using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator
{
	// ☆ 構造体 ☆ //

	// ＲＧＢＡのデータ
	public struct S_RGBA_Data
	{
		// ☆ 変数宣言 ☆ //
		public float m_red;     // 赤
		public float m_green;   // 緑
		public float m_blue;    // 青
		public float m_alpha;   // α


		// ☆ プロパティ ☆ //

		// 赤
		public float mp_red
		{
			get
			{
				return m_red;
			}
			set
			{
				m_red = value;
			}
		}

		// 緑
		public float mp_green
		{
			get
			{
				return m_green;
			}
			set
			{
				m_green = value;
			}
		}

		// 青
		public float mp_blue
		{
            get
			{
                return m_blue;
            }
            set
			{
                m_blue = value;
            }
        }

		// α
		public float mp_alpha
		{
            get
			{
                return m_alpha;
            }
            set
			{
                m_alpha = value;
            }
        }


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public S_RGBA_Data(float in_red, float in_green, float in_blue, float in_alpha)
		{
            // ＲＧＢＡ値を設定
            m_red = in_red;
            m_green = in_green;
            m_blue = in_blue;
            m_alpha = in_alpha;

            return;
        }
	}


	// ☆ クラス ☆ //

	// マテリアル設定用のユーザーコントロール
	public partial class UC_Material_Setting_Frame : UserControl
	{
		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public UC_Material_Setting_Frame()
		{
			// コンポーネントの初期化
			InitializeComponent();

			return;
		}


		// ロード時の処理
		private void UC_Material_Setting_Frame_Load(object sender, EventArgs e)
		{
            // トラックバーの値をリセット
            M_Reset();

			// サイズを固定
			MaximumSize = Size;
			MinimumSize = Size;

            return;
        }

		
		// リセットする
		public void M_Reset()
		{
            // トラックバーの値をリセット
            Track_red.Value = 0;
            Track_green.Value = 0;
            Track_blue.Value = 0;
            Track_alpha.Value = 100;

            return;
        }

		
		//-☆- ゲッタ -☆-//

		// ＲＧＢＡのデータを返す　戻り値：ＲＧＢＡ値
		public S_RGBA_Data M_Get_RGBA_Data()
		{
			// ☆ 変数宣言 ☆ //
            S_RGBA_Data result_rgba = new S_RGBA_Data();	// 結果のRGBA値


			// ＲＧＢＡ値を取得
			result_rgba.mp_red = (float)Track_red.Value / 100.0f;
			result_rgba.mp_green = (float)Track_green.Value / 100.0f;
			result_rgba.mp_blue = (float)Track_blue.Value / 100.0f;
			result_rgba.mp_alpha = (float)Track_alpha.Value / 100.0f;

			return result_rgba;
        }


		//-☆- セッタ -☆-//

		// タグ名を設定　引数：タグ名
		public void M_Set_Tag_Name(string in_tag_name)
		{
			TB_data_tag.Text = in_tag_name;

            return;
        }


		// ＲＧＢＡ血の最大値を変更　引数：最大値
		public void M_Change_Maximum_Track_Value(float in_max_value)
		{
            // トラックバーの最大値を変更
            Track_red.Maximum = (int)(in_max_value * 100);
            Track_green.Maximum = (int)(in_max_value * 100);
            Track_blue.Maximum = (int)(in_max_value * 100);
            Track_alpha.Maximum = (int)(in_max_value * 100);

			// 表記に最大値を設定
			TB_red_max.Text = in_max_value.ToString();
			TB_green_max.Text = in_max_value.ToString();
			TB_blue_max.Text = in_max_value.ToString();
			TB_alpha_max.Text = in_max_value.ToString();

            return;
        }


		// ＲＧＢＡのデータを設定　引数：ＲＧＢＡ値
		public void M_Set_RGBA_Data(S_RGBA_Data in_rgba_data)
		{
            // トラックバーの値を設定
            Track_red.Value = (int)(in_rgba_data.m_red * 100);
            Track_green.Value = (int)(in_rgba_data.m_green * 100);
            Track_blue.Value = (int)(in_rgba_data.m_blue * 100);
            Track_alpha.Value = (int)(in_rgba_data.m_alpha * 100);

            return;
		}


		//-☆- イベント -☆-//

		// 赤のトラックバーの値が変更されたとき
        private void Track_red_ValueChanged(object sender, EventArgs e)
        {
			// ラベルの値を変更
            TB_red_value.Text = ((float)Track_red.Value / 100.0f).ToString();

            return;
        }


		// 緑のトラックバーの値が変更されたとき
        private void Track_green_ValueChanged(object sender, EventArgs e)
        {
			// ラベルの値を変更
            TB_green_value.Text = ((float)Track_green.Value / 100.0f).ToString();

            return;
        }


		// 青のトラックバーの値が変更されたとき
        private void Track_blue_ValueChanged(object sender, EventArgs e)
        {
			// ラベルの値を変更
            TB_blue_value.Text = ((float)Track_blue.Value / 100.0f).ToString();

            return;
        }


		// αのトラックバーの値が変更されたとき
        private void Track_alpha_ValueChanged(object sender, EventArgs e)
        {
			// ラベルの値を変更
            TB_alpha_value.Text = ((float)Track_alpha.Value / 100.0f).ToString();

            return;
        }
    }
}
