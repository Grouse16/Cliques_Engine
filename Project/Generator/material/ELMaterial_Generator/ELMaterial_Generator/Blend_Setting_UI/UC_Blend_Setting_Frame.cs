using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator.Blend_Setting_UI
{
	public partial class UC_Blend_Setting_Frame : UserControl
	{
		// ☆ 定数 ☆ //
		const int con_BLEND_SETTING_IN_WINDOW_SUM = 2;    // ブレンド設定を表示できる数

		const int con_BLEND_SETTING_LIST_INITIAL_HOROZONTAL = 12;   // ブレンド設定リストの初期横位置
        const int con_BLEND_SETTING_LIST_INITIAL_VERTICAL = 29;     // ブレンド設定リストの初期縦位置

		const int con_BLEND_SETTING_LIST_VERTICAL_DISTANCE = 63;    // ブレンド設定リストの縦間隔


        // ☆ 変数 ☆ //
        private List<UC_Blend_Setting> m_blend_setting_list = new List<UC_Blend_Setting>();    // ブレンド設定リスト

		private int m_now_blend_setting_sum = 0;    // 現在のブレンド設定数


		// ☆ プロパティ ☆ //

		// ブレンド設定リスト
		public List<UC_Blend_Setting> mp_blend_setting_list
		{
            get
			{
                return m_blend_setting_list;
            }
        }


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public UC_Blend_Setting_Frame()
		{
			InitializeComponent();

			// サイズを固定
			MaximumSize = Size;
			MinimumSize = Size;

			// ブレンド設定数を初期化
			M_Change_Blend_Setting_Sum(1);

			return;
		}

		// リセットする
		public void M_Reset()
		{
            // ブレンド設定数を初期化
            M_Change_Blend_Setting_Sum(1);

			// 要素を初期化
			foreach (var now_vertex_list in m_blend_setting_list)
			{
				now_vertex_list.M_Set_Write_Setting(E_WRITE_SETTING.e_ADD);
			}

            return;
        }


		//-☆- ブレンド設定数変更 -☆-//

		// リストの数をブレンド設定数に合わせる
		public void M_Change_Blend_Setting_Sum(int in_set_sum)
        {
            // ☆ 変数宣言 ☆ //
            List<UC_Blend_Setting> new_blend_setting_list = new List<UC_Blend_Setting>();   // 新しく確保したブレンド設定情報のリスト


            // 指定されたブレンド設定数分要素を確保
            for (int l_num = 0; l_num < in_set_sum; l_num++)
            {
                // 設定中のブレンド設定が現在持っている情報数未満なら、情報を引き継ぐ
                if (l_num < m_now_blend_setting_sum)
                {
                    new_blend_setting_list.Add(m_blend_setting_list[l_num]);
                    this.Controls.Add(new_blend_setting_list[l_num]);
                }

                // 新しいブレンド設定であれば、生成して追加する
                else
                {
                    new_blend_setting_list.Add(new UC_Blend_Setting());
                    new_blend_setting_list[l_num].M_Set_Blend_Setting_Number(l_num + 1);
                    this.Controls.Add(new_blend_setting_list[l_num]);
                }
            }


			// 余分なブレンド設定情報を削除
			for (int l_num = in_set_sum; l_num < m_now_blend_setting_sum; l_num++)
			{
				this.Controls.Remove(m_blend_setting_list[l_num]);
			}


            // 新しく生成したリストに入れ替える
            m_blend_setting_list = new_blend_setting_list;


            // スクロールの位置調整を行う
            M_Refresh_Scroll_Bar_Position();

            // 現在のブレンド設定数を更新
            NUM_blend_sum_setting.Value = (decimal)in_set_sum;

            return;
        }


		//-☆- スクロール -☆-//

		// スクロールバーの位置を再設定する
		private void M_Refresh_Scroll_Bar_Position()
		{
			// ブレンド設定数が表示できる数を超えたら必要な分だけスクロールを可能にする
			if (con_BLEND_SETTING_IN_WINDOW_SUM < (int)NUM_blend_sum_setting.Value)
			{
				SB_scroll.Maximum
					= con_BLEND_SETTING_LIST_VERTICAL_DISTANCE * ((int)NUM_blend_sum_setting.Value - con_BLEND_SETTING_IN_WINDOW_SUM) +
					con_BLEND_SETTING_LIST_VERTICAL_DISTANCE / 2;
			}
			// ブレンド設定数が表示できる数を超えなかったらスクロールを不可能にする
			else
			{
                // スクロールバーの位置を再設定する
                SB_scroll.Maximum = 0;
			}

			// スクロールバーの値を再設定する
			M_Set_Scroll_Bar_Position();

			return;
		}


		// スクロールバーによってスクロールする時の設置処理
		private void M_Set_Scroll_Bar_Position()
		{
			// ブレンド設定情報の位置を再設定
			for (int l_now_blend_setting_number = 0; l_now_blend_setting_number < m_blend_setting_list.Count; l_now_blend_setting_number++)
			{
				m_blend_setting_list[l_now_blend_setting_number].Location = new Point
					(
					con_BLEND_SETTING_LIST_INITIAL_HOROZONTAL,

					con_BLEND_SETTING_LIST_INITIAL_VERTICAL +
					con_BLEND_SETTING_LIST_VERTICAL_DISTANCE * l_now_blend_setting_number - SB_scroll.Value
					);
			}

			return;
		}


		//-☆- イベント -☆-//

		// ブレンド設定数が変更された
		private void NUM_blend_sum_ValueChanged(object sender, EventArgs e)
		{
			M_Change_Blend_Setting_Sum((int)NUM_blend_sum_setting.Value);

            return;
        }


		// スクロールバーがスクロールされた
        private void SB_scroll_Scroll(object sender, ScrollEventArgs e)
        {
			// スクロールバーの値を再設定する
            M_Set_Scroll_Bar_Position();

            return;
        }
    }
}
