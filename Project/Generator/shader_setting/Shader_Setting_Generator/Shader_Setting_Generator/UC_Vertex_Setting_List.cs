using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator
{
    public partial class UC_Vertex_Setting_List : UserControl
    {
        // ☆ 定数 ☆ //
        private const int con_VERTICAL_SET_SPAN = 108;   // 頂点レイアウト情報の縦での設置間隔
        private const int con_VERTICAL_INITIAL_SPAN = 14;   // 頂点レイアウト情報の縦での初期設置間隔
        private const int con_HORIZONTAL_SET_POS = 12;  // 頂点レイアウト情報の横での設置位置


        // ☆ 変数宣言 ☆ //
        private List<UC_Vertex_Setting> m_vertex_setting_list = new List<UC_Vertex_Setting>();    // 頂点設定のリスト


        // ☆ 関数 ☆ //

        public UC_Vertex_Setting_List()
        {
            InitializeComponent();
        }

        // 初期化
        private void UC_Vertex_Setting_List_Load(object sender, EventArgs e)
        {
            M_Reset();
        }

        // 初期化
        public void M_Reset()
        {
            // ☆ 変数宣言 ☆ //
            List<UC_Vertex_Setting> new_vertex_setting_list = new List<UC_Vertex_Setting>();   // 新しく確保した頂点設定のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_vertex_list in m_vertex_setting_list)
            {
                this.Controls.Remove(now_vertex_list);
            }

            // 指定されたレイアウト数分要素を確保
            for (int loop_num = 0; loop_num < 1; loop_num++)
            {
                new_vertex_setting_list.Add(new UC_Vertex_Setting());
                this.Controls.Add(new_vertex_setting_list[loop_num]);
                new_vertex_setting_list[loop_num].M_Set_Vertex_Layout_Number(loop_num + 1);
            }

            // 新しく生成したリストに入れ替える
            m_vertex_setting_list = new_vertex_setting_list;

            // リストを整列する
            m_vertex_setting_list[0].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN);
            for (int loop_num = 1; loop_num < m_vertex_setting_list.Count; loop_num++)
            {
                m_vertex_setting_list[loop_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * loop_num);
            }

            // スクロールバーを初期化する
            ScrollBar_Vertex_Setting.Value = 0;
            ScrollBar_Vertex_Setting.Maximum = con_VERTICAL_SET_SPAN * (m_vertex_setting_list.Count - 2);
            if (ScrollBar_Vertex_Setting.Maximum < 1)
            {
                ScrollBar_Vertex_Setting.Maximum = 1;
            }
            ScrollBar_Vertex_Setting.Minimum = 0;

            return;
        }


        // 頂点レイアウト数を設定する　引数：頂点レイアウト数
        public void M_Set_Vertex_Layout_Sum(int in_vertex_sum)
        {
            // ☆ 変数宣言 ☆ //
            List<UC_Vertex_Setting> new_vertex_setting_list = new List<UC_Vertex_Setting>();   // 新しく確保した頂点設定のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_vertex_list in m_vertex_setting_list)
            {
                this.Controls.Remove(now_vertex_list);
            }

            // 指定されたレイアウト数分要素を確保
            for (int loop_num = 0; loop_num < in_vertex_sum; loop_num++)
            {
                // 設定中の頂点レイアウト情報が現在持っている情報数未満なら、情報を引き継ぐ
                if (loop_num < m_vertex_setting_list.Count)
                {
                    new_vertex_setting_list.Add(m_vertex_setting_list[loop_num]);
                    this.Controls.Add(new_vertex_setting_list[loop_num]);
                }

                // 新しい頂点レイアウトであれば、生成して追加する
                else
                {
                    new_vertex_setting_list.Add(new UC_Vertex_Setting());
                    new_vertex_setting_list[loop_num].M_Set_Vertex_Layout_Number(loop_num + 1);
                    this.Controls.Add(new_vertex_setting_list[loop_num]);
                }
            }

            // 新しく生成したリストに入れ替える
            m_vertex_setting_list = new_vertex_setting_list;

            // リストを整列する
            m_vertex_setting_list[0].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN);
            for (int loop_num = 0; loop_num < m_vertex_setting_list.Count; loop_num++)
            {
                m_vertex_setting_list[loop_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * loop_num);
            }

            // スクロールバーを初期化する
            ScrollBar_Vertex_Setting.Value = 0;
            ScrollBar_Vertex_Setting.Maximum = con_VERTICAL_SET_SPAN * (m_vertex_setting_list.Count - 2);
            if (ScrollBar_Vertex_Setting.Maximum < 1)
            {
                ScrollBar_Vertex_Setting.Maximum = 1;
            }
            ScrollBar_Vertex_Setting.Minimum = 0;

            return;
        }


        // 頂点レイアウト情報の配列を返す　戻り値：頂点レイアウト数
        public List<UC_Vertex_Setting> M_Get_Vertex_Layout_List()
        {
            return m_vertex_setting_list;
        }

        // スクロールバーがスクロールされた
        private void ScrollBar_Vertex_Setting_Scroll(object sender, ScrollEventArgs e)
        {
            // リストを整列する
            for (int loop_num = 0; loop_num < m_vertex_setting_list.Count; loop_num++)
            {
                m_vertex_setting_list[loop_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * loop_num - ScrollBar_Vertex_Setting.Value);
            }
        }
    }
}
