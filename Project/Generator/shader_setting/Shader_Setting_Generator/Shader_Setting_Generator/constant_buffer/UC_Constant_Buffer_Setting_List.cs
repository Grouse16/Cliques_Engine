using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.constant_buffer
{
    public partial class UC_Constant_Buffer_Setting_List : UserControl
    {
        // ☆ 定数 ☆ //
        private const int con_VERTICAL_SET_SPAN = 95;   // 頂点レイアウト情報の縦での設置間隔
        private const int con_VERTICAL_INITIAL_SPAN = 13;   // 頂点レイアウト情報の縦での初期設置間隔
        private const int con_HORIZONTAL_SET_POS = 21;  // 頂点レイアウト情報の横での設置位置


        // ☆ 変数宣言 ☆ //
        List<UC_Constant_Buffer_Setting> m_constant_buffer_setting_list = new List<UC_Constant_Buffer_Setting> ();    // 定数バッファ情報のリスト

        public int m_constant_buffer_sum = 0;   // 定数バッファ数


        // ☆ 関数 ☆ //

        public UC_Constant_Buffer_Setting_List()
        {
            InitializeComponent();
        }

        // ロード時の初期化
        private void UC_Constant_Buffer_Setting_List_Load(object sender, EventArgs e)
        {
            M_Reset();

            return;
        }

        // 定数バッファ情報をリセットする
        public void M_Reset()
        {
            // ☆ 変数宣言 ☆ //
            List<UC_Constant_Buffer_Setting> new_constant_buffer_setting_list = new List<UC_Constant_Buffer_Setting>();   // 新しく確保した定数バッファ情報のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_constant_buffer_list in m_constant_buffer_setting_list)
            {
                this.Controls.Remove(now_constant_buffer_list);
            }
            m_constant_buffer_setting_list.Clear();

            // スクロールバーを初期化する
            SB_Constant_Buffer_Scroll.Value = 0;
            SB_Constant_Buffer_Scroll.Maximum = con_VERTICAL_SET_SPAN * (m_constant_buffer_setting_list.Count - 2);
            if (SB_Constant_Buffer_Scroll.Maximum < 1)
            {
                SB_Constant_Buffer_Scroll.Maximum = 1;
            }
            SB_Constant_Buffer_Scroll.Minimum = 0;

            return;
        }


        // 定数バッファ情報数を設定する　引数：定数バッファ情報数
        public void M_Set_Constant_Buffer_Sum(int in_constant_buffer_sum)
        {
            // 定数バッファ情報がなくなるなら初期化する
            if (in_constant_buffer_sum <= 0)
            {
                M_Reset();

                return;
            }


            // ☆ 変数宣言 ☆ //
            List<UC_Constant_Buffer_Setting> new_constant_buffer_list = new List<UC_Constant_Buffer_Setting>();   // 新しく確保した定数バッファ情報のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_vertex_list in m_constant_buffer_setting_list)
            {
                this.Controls.Remove(now_vertex_list);
            }

            // 指定された定数バッファ情報数分要素を確保
            for (int l_num = 0; l_num < in_constant_buffer_sum; l_num++)
            {
                // 設定中の定数バッファ情報が現在持っている情報数未満なら、情報を引き継ぐ
                if (l_num < m_constant_buffer_setting_list.Count)
                {
                    new_constant_buffer_list.Add(m_constant_buffer_setting_list[l_num]);
                    this.Controls.Add(new_constant_buffer_list[l_num]);
                }

                // 新しい定数バッファ情報であれば、生成して追加する
                else
                {
                    new_constant_buffer_list.Add(new UC_Constant_Buffer_Setting());
                    new_constant_buffer_list[l_num].M_Set_Constant_Buffer_Num(l_num + 1);
                    this.Controls.Add(new_constant_buffer_list[l_num]);
                }
            }

            // 新しく生成したリストに入れ替える
            m_constant_buffer_setting_list = new_constant_buffer_list;

            // リストを整列する
            m_constant_buffer_setting_list[0].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN);
            for (int l_num = 0; l_num < m_constant_buffer_setting_list.Count; l_num++)
            {
                m_constant_buffer_setting_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num);
            }

            // スクロールバーを初期化する
            SB_Constant_Buffer_Scroll.Value = 0;
            SB_Constant_Buffer_Scroll.Maximum = 1;
            SB_Constant_Buffer_Scroll.Minimum = 0;

            return;
        }


        // 定数バッファ情報の配列を返す　戻り値：定数バッファ情報リスト
        public List<UC_Constant_Buffer_Setting> M_Get_Constant_Buffer_List()
        {
            return m_constant_buffer_setting_list;
        }


        // バーをスクロールされたらUIの位置をスライドする
        private void SB_Constant_Buffer_Scroll_Scroll(object sender, ScrollEventArgs e)
        {
            // リストを整列する
            for (int l_num = 0; l_num < m_constant_buffer_setting_list.Count; l_num++)
            {
                m_constant_buffer_setting_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num - SB_Constant_Buffer_Scroll.Value);
            }

            return;
        }
    }
}
