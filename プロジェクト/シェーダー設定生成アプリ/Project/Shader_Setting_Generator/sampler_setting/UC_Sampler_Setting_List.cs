using Shader_Setting_Generator.constant_buffer;
using Shader_Setting_Generator.texture_buffer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.sampler_setting
{
    public partial class UC_Sampler_Setting_List : UserControl
    {
        // ☆ 定数 ☆ //
        private const int con_VERTICAL_SET_SPAN = 52;   // 頂点レイアウト情報の縦での設置間隔
        private const int con_VERTICAL_INITIAL_SPAN = 13;   // 頂点レイアウト情報の縦での初期設置間隔
        private const int con_HORIZONTAL_SET_POS = 13;  // 頂点レイアウト情報の横での設置位置


        // ☆ 変数宣言 ☆ //
        List<UC_Sampler_Setting> m_sampler_inform_list = new List<UC_Sampler_Setting>(); // サンプラー設定リスト


        // ☆ 関数 ☆ //

        public UC_Sampler_Setting_List()
        {
            InitializeComponent();
        }

        // ロード時の初期化
        private void UC_Sampler_Setting_List_Load(object sender, EventArgs e)
        {
            M_Reset();
        }

        // サンプラー設定情報をリセットする
        public void M_Reset()
        {
            // ☆ 変数宣言 ☆ //
            List<UC_Sampler_Setting> new_sampler_setting_list = new List<UC_Sampler_Setting>();   // 新しく確保したサンプラー設定情報のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_constant_buffer_list in m_sampler_inform_list)
            {
                this.Controls.Remove(now_constant_buffer_list);
            }
            m_sampler_inform_list.Clear();

            // スクロールバーを初期化する
            SB_Sampler_Scroll_Bar.Value = 0;
            SB_Sampler_Scroll_Bar.Maximum = 1;
            SB_Sampler_Scroll_Bar.Minimum = 0;

            return;
        }


        // サンプラー設定情報数を設定する　引数：サンプラー設定情報数
        public void M_Set_Sampler_Sum(int in_constant_buffer_sum)
        {
            // サンプラー設定情報がなくなるなら初期化する
            if (in_constant_buffer_sum <= 0)
            {
                M_Reset();

                return;
            }


            // ☆ 変数宣言 ☆ //
            List<UC_Sampler_Setting> new_constant_buffer_list = new List<UC_Sampler_Setting>();   // 新しく確保したサンプラー設定情報のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_vertex_list in m_sampler_inform_list)
            {
                this.Controls.Remove(now_vertex_list);
            }

            // 指定されたサンプラー設定情報数分要素を確保
            for (int l_num = 0; l_num < in_constant_buffer_sum; l_num++)
            {
                // 設定中のサンプラー設定情報が現在持っている情報数未満なら、情報を引き継ぐ
                if (l_num < m_sampler_inform_list.Count)
                {
                    new_constant_buffer_list.Add(m_sampler_inform_list[l_num]);
                    this.Controls.Add(new_constant_buffer_list[l_num]);
                }

                // 新しいサンプラー設定情報であれば、生成して追加する
                else
                {
                    new_constant_buffer_list.Add(new UC_Sampler_Setting());
                    new_constant_buffer_list[l_num].M_Set_Sampler_Number(l_num + 1);
                    this.Controls.Add(new_constant_buffer_list[l_num]);
                }
            }

            // 新しく生成したリストに入れ替える
            m_sampler_inform_list = new_constant_buffer_list;

            // リストを整列する
            m_sampler_inform_list[0].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN);
            for (int l_num = 0; l_num < m_sampler_inform_list.Count; l_num++)
            {
                m_sampler_inform_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num);
            }

            // スクロールバーを初期化する
            SB_Sampler_Scroll_Bar.Value = 0;
            SB_Sampler_Scroll_Bar.Maximum = con_VERTICAL_SET_SPAN * (m_sampler_inform_list.Count - 2);
            if (SB_Sampler_Scroll_Bar.Maximum < 1)
            {
                SB_Sampler_Scroll_Bar.Maximum = 1;
            }
            SB_Sampler_Scroll_Bar.Minimum = 0;

            return;
        }


        // サンプラー設定情報の配列を返す　戻り値：サンプラー設定情報リスト
        public List<UC_Sampler_Setting> M_Get_Sampler_List()
        {
            return m_sampler_inform_list;
        }

        // サンプラー情報がスクロールされた
        private void SB_Sampler_Scroll_Bar_Scroll(object sender, ScrollEventArgs e)
        {
            // リストを整列する
            for (int l_num = 0; l_num < m_sampler_inform_list.Count; l_num++)
            {
                m_sampler_inform_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num - SB_Sampler_Scroll_Bar.Value);
            }

            return;
        }
    }
}
