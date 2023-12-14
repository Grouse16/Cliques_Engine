using _3D_Model_Converter_And_Drawer._3Dmodel_Convert;
using Assimp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer
{
    // ☆ クラス ☆ //

    // アニメーションリスト
    public partial class UC_Animation_List : UserControl
    {
        // ☆ 定数 ☆ //
        const int con_ANIMATION_LIST_INITIAL_VERTICAL = 29;     // アニメーションリストの初期高さ
        const int con_ANIMATION_LIST_INITIAL_HOROZONTAL = 3;    // アニメーションリストの初期幅
        const int con_ANIMATION_LIST_VERTICAL_DISTANCE = 35;    // アニメーションリストのごとの設置幅の高さ
        const int con_ANIMATION_LIST_IN_WINDOW_SUM = 3;         // アニメーションリストがウィンドウ内に表示される数


        // ☆ 変数 ☆ //
        private List<UC_Animation_Inform_Bar> m_animation_list = new List<UC_Animation_Inform_Bar>(); // アニメーション情報のリスト

        private int m_now_animation_list_sum = 0;   // 現在のアニメーションリストの数
        

        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Animation_List()
        {
            InitializeComponent();

            return;
        }


        // ロード
        private void UC_Animation_List_Load(object sender, EventArgs e)
        {
            MaximumSize = Size;
            MinimumSize = Size;

            return;
        }


        //-☆- スクロール -☆-//

        // スクロールバーの位置を再設定する
        private void M_Refresh_Scroll_Bar_Position()
        {
            // アニメーション数が表示できる数を超えたら必要な分だけスクロールを可能にする
            if (con_ANIMATION_LIST_IN_WINDOW_SUM < m_now_animation_list_sum)
            {
                // スクロールバーの位置を再設定する
                sb_animation_scroll_bar.Maximum 
                    = con_ANIMATION_LIST_VERTICAL_DISTANCE * (m_now_animation_list_sum - (1 + con_ANIMATION_LIST_IN_WINDOW_SUM)) +
                    con_ANIMATION_LIST_VERTICAL_DISTANCE / 2;
            }
            // アニメーション数が表示できる数を超えなかったらスクロールを不可能にする
            else
            {
                // スクロールバーの位置を再設定する
                sb_animation_scroll_bar.Maximum = 0;
            }

            // スクロールバーの値を再設定する
            M_Set_Scroll_Bar_Position();

            return;
        }

        
        // スクロールバーによってスクロールする時の設置処理
        private void M_Set_Scroll_Bar_Position()
        {
            // アニメーション情報の位置を再設定
            for (int now_animation_inform = 0; now_animation_inform < m_animation_list.Count; now_animation_inform++)
            {
                m_animation_list[now_animation_inform].Location = new Point
                    (
                    con_ANIMATION_LIST_INITIAL_HOROZONTAL,

                    con_ANIMATION_LIST_INITIAL_VERTICAL + 
                    con_ANIMATION_LIST_VERTICAL_DISTANCE * now_animation_inform - sb_animation_scroll_bar.Value
                    );
            }

            return;
        }


        //-☆- リスト -☆-//

        // アニメーション情報を追加する　引数：アニメーション名、アニメーションパス
        private void M_Add_Animation_Inform_Bar(string in_animation_name, string in_animation_path)
        {
            // ☆ 変数宣言 ☆ //
            UC_Animation_Inform_Bar new_animation_inform = new UC_Animation_Inform_Bar();   // あたらしいアニメーション情報


            // アニメーション情報の追加
            m_animation_list.Add(new_animation_inform);

            // 生成したネームUIを画面に表示
            this.Controls.Add(new_animation_inform);

            // 設置位置とサイズをセット
            new_animation_inform.Set_Animation_Inform(in_animation_name, in_animation_path);

            // スクロールの位置を再設定
            M_Refresh_Scroll_Bar_Position();

            return;
        }


        //-☆- イベント -☆-//

        // ファイルをドロップされたとき
        private void b_import_box_DragDrop(object sender, DragEventArgs e)
        {
            // ☆ 定数 ☆ //
            const string con_IS_ELANMDT_TEXT = "This-Is-ELANMDT";   // elanmdtであることを確認するための文字列


            // ファイルドロップ時はファイルのプロパティを取得（なければスルー）
            if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
            {
                return;
            }


            // ☆ 変数宣言 ☆ //
            string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイルまでの絶対パス

            string relative_file_path = CS_My_Math_System.M_Get_Relative_Path(file_path[0]);   // ファイルまでの相対パス
            string file_name = System.IO.Path.GetFileNameWithoutExtension(file_path[0]);   // ファイル名
            
            StreamReader file_data = new StreamReader(file_path[0]); // ファイルデータ


            // elanmdtであることを確認
            foreach (var l_now_text in con_IS_ELANMDT_TEXT)
            {
                // elanmdtでなければ終了
                if (l_now_text != file_data.Read())
                {
                    return;
                }
            }

            // アニメーション情報を追加
            M_Add_Animation_Inform_Bar(file_name, relative_file_path);

            return;
        }


        // ファイルを上にドラッグされている時
        private void b_import_box_DragOver(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はカーソルをコピーに変更
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }

            // それ以外の時はなにもしない
            else
            {
                e.Effect = DragDropEffects.None;
            }

            return;
        }


        // スクロールバーの値が変更されたとき
        private void sb_animation_scroll_bar_ValueChanged(object sender, EventArgs e)
        {
            M_Set_Scroll_Bar_Position();

            return;
        }
    }
}
