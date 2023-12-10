using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    // ☆ クラス ☆ //

    // スクロールバーの名前を設定するユーザーコントロール
    public partial class UC_Scroll_Name_Setting : UserControl
    {
        // ☆ 定数 ☆ //
        const int con_X_LOCATION = 3;   // X座標での座標
        const int con_ONE_SPAN_Y = 23;  // Y座標でのUI一つ分の間隔


        // ☆ 変数宣言 ☆ //
        public List<UC_Name_Setting> m_name_list = new List<UC_Name_Setting>();   // ネームUIのリスト

        string m_scroll_name = "default"; // スクロール枠の名前


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Scroll_Name_Setting()
        {
            InitializeComponent();

            return;
        }


        // ロードを行う
        private void UC_Scroll_Name_Setting_Load(object sender, System.EventArgs e)
        {

            return;
        }


        //-☆- 生成 -☆-//

        // 名前のリストを生成する　引数：セットする名前のリスト
        public void M_Create_Name_List(List<string> in_set_name_list)
        {
            // すでにあるネームUIを削除
            M_Delete_Name_UI();

            // ネームUIの生成
            for (int now_inform_num = 0; now_inform_num < in_set_name_list.Count; now_inform_num++)
            {
                // ☆ 変数宣言 ☆ //
                UC_Name_Setting new_name_setting = new UC_Name_Setting();   // あたらしいマテリアルネーム設定


                // 設置位置とサイズをセット
                new_name_setting.Location = new Point(con_X_LOCATION, con_ONE_SPAN_Y + con_ONE_SPAN_Y * now_inform_num);
                new_name_setting.Size = new Size(449, 23);
                new_name_setting.M_Set_Number_Prate(m_scroll_name + (now_inform_num + 1).ToString());

                // 初期名セット
                new_name_setting.M_Set_Name(in_set_name_list[now_inform_num]);

                // 生成したネームUIを画面に表示
                m_name_list.Add(new_name_setting);
                this.Controls.Add(new_name_setting);
            }


            // 枠内をはみ出すならスクロールできるようにする
            if (in_set_name_list.Count > 3)
            {
                scroll_bar.Maximum = (in_set_name_list.Count - 3) * con_ONE_SPAN_Y;
            }

            // 枠内に収まるならスクロールできないようにする
            else
            {
                scroll_bar.Maximum = 1;
            }

            return;
        }


        //-☆- セッタ -☆-//

        // スクロール値を受け取ってスクロールさせる　引数：スクロール値
        public void M_Set_Var_Scroll(int in_scroll_value)
        {
            for (int now_mat_num = 0; now_mat_num < m_name_list.Count; now_mat_num++)
            {
                m_name_list[now_mat_num].Location = new Point(con_X_LOCATION, con_ONE_SPAN_Y + con_ONE_SPAN_Y * now_mat_num - in_scroll_value);
            }

            return;
        }

        // スクロール枠名とテキストの基準名を設定
        public void M_Set_Frame_Name(string scroll_frame_name, string in_scroll_text_name)
        {
            textBox1.Text = scroll_frame_name;
            m_scroll_name = in_scroll_text_name;

            return;
        }


        //-☆- 検査 -☆-//

        // リスト内のデータ名に被りがあるかどうかを調べる　戻り値：被っている文字列、なければNOTHINGが返る
        public string M_Check_Name_Doubling()
        {
            for (int l_now_name_num = 0; l_now_name_num + 1 < m_name_list.Count; l_now_name_num++)
            {
                for (int l_check_name_num = l_now_name_num + 1; l_check_name_num < m_name_list.Count; l_check_name_num++)
                {
                    // 被りがあった
                    if (m_name_list[l_now_name_num].M_Get_Name() == m_name_list[l_check_name_num].M_Get_Name())
                    {
                        return m_name_list[l_now_name_num].M_Get_Name();
                    }
                }
            }

            // 被りはなかった
            return "NOTHING";
        }


        //-☆- イベント -☆-//

        // バーがスクロールしたとき
        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            M_Set_Var_Scroll(e.NewValue);

            return;
        }
    }
}
