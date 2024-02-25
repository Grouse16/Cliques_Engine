using Shader_Setting_Generator.constant_buffer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.texture_buffer
{
    public partial class UC_Texture_Inform_List : UserControl
    {
        // ☆ 定数 ☆ //
        private const int con_VERTICAL_SET_SPAN = 75;   // 頂点レイアウト情報の縦での設置間隔
        private const int con_VERTICAL_INITIAL_SPAN = 13;   // 頂点レイアウト情報の縦での初期設置間隔
        private const int con_HORIZONTAL_SET_POS = 21;  // 頂点レイアウト情報の横での設置位置


        // ☆ 変数宣言 ☆ //
        private List<UC_Texture_Inform> m_texture_inform_list = new List<UC_Texture_Inform>();  // テクスチャバッファのリスト


        // ☆ 関数 ☆ //

        public UC_Texture_Inform_List()
        {
            InitializeComponent();
        }

        // ロード時の初期化
        private void UC_Texture_Inform_List_Load(object sender, EventArgs e)
        {
            M_Reset();
        }

        // テクスチャバッファ情報をリセットする
        public void M_Reset()
        {
            // 今まで持っていた情報を画面から排除
            for (int l_num = 0; l_num < m_texture_inform_list.Count; l_num++)
            {
                this.Controls.Remove(m_texture_inform_list[l_num]);
            }
            m_texture_inform_list.Clear();

            // スクロールバーを初期化する
            SB_Texture_Inform_Scroll.Value = 0;
            SB_Texture_Inform_Scroll.Maximum = 1;
            SB_Texture_Inform_Scroll.Minimum = 0;

            return;
        }


        // テクスチャバッファ情報数を設定する　引数：テクスチャバッファ情報数
        public void M_Set_Texture_Buffer_Sum(int in_texture_buffer_sum)
        {
            // テクスチャ情報がなくなるなら初期化する
            if (in_texture_buffer_sum <= 0)
            {
                M_Reset();

                return;
            }


            // ☆ 変数宣言 ☆ //
            List<UC_Texture_Inform> new_texture_buffer_list = new List<UC_Texture_Inform>();   // 新しく確保したテクスチャバッファ情報のリスト


            // 今まで持っていた情報を画面から排除
            foreach (var now_vertex_list in m_texture_inform_list)
            {
                this.Controls.Remove(now_vertex_list);
            }

            // 指定されたテクスチャバッファ情報数分要素を確保
            for (int l_num = 0; l_num < in_texture_buffer_sum; l_num++)
            {
                // 設定中のテクスチャバッファ情報が現在持っている情報数未満なら、情報を引き継ぐ
                if (l_num < m_texture_inform_list.Count)
                {
                    new_texture_buffer_list.Add(m_texture_inform_list[l_num]);
                    this.Controls.Add(new_texture_buffer_list[l_num]);
                }

                // 新しいテクスチャバッファ情報であれば、生成して追加する
                else
                {
                    new_texture_buffer_list.Add(new UC_Texture_Inform());
                    new_texture_buffer_list[l_num].M_Set_Texture_Inform_Number(l_num + 1);
                    this.Controls.Add(new_texture_buffer_list[l_num]);
                }
            }

            // 新しく生成したリストに入れ替える
            m_texture_inform_list = new_texture_buffer_list;

            // リストを整列する
            m_texture_inform_list[0].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN);
            for (int l_num = 0; l_num < m_texture_inform_list.Count; l_num++)
            {
                m_texture_inform_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num);
            }

            // スクロールバーを初期化する
            SB_Texture_Inform_Scroll.Value = 0;
            SB_Texture_Inform_Scroll.Maximum = con_VERTICAL_SET_SPAN * (m_texture_inform_list.Count - 2);
            if (SB_Texture_Inform_Scroll.Maximum < 1)
            {
                SB_Texture_Inform_Scroll.Maximum = 1;
            }
            SB_Texture_Inform_Scroll.Minimum = 0;

            return;
        }


        // テクスチャバッファ情報の配列を返す　戻り値：テクスチャバッファ情報リスト
        public List<UC_Texture_Inform> M_Get_Texture_Buffer_List()
        {
            return m_texture_inform_list;
        }

        // テクスチャバッファ情報をスクロールする
        private void SB_Texture_Inform_Scroll_Scroll(object sender, ScrollEventArgs e)
        {
            // リストを整列する
            for (int l_num = 0; l_num < m_texture_inform_list.Count; l_num++)
            {
                m_texture_inform_list[l_num].Location = new Point(con_HORIZONTAL_SET_POS, con_VERTICAL_INITIAL_SPAN + con_VERTICAL_SET_SPAN * l_num - SB_Texture_Inform_Scroll.Value);
            }

            return;
        }
    }
}
