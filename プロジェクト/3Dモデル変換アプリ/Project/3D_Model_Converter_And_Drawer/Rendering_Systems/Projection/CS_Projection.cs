using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.Rendering_Systems.Projection
{
	// ☆ クラス ☆ //

	// 射影システムのクラス
	public class CS_Projection
	{
		// ☆ 変数宣言 ☆ //
		private SharpDX.Matrix m_projection_matrix = new SharpDX.Matrix(); // 射影行列

		private float m_field_of_view = 0.0f;	// 視野角
		private float m_aspect_ratio = 0.0f;	// アスペクト比
		private float m_near_distance = 0.0f;	// 描画開始距離
		private float m_far_distance = 0.0f;	// 描画終了距離


		// ☆ プロパティ ☆ //

		// 射影行列
		public SharpDX.Matrix mp_projection_matrix
		{
            // ゲッタ
            get
			{
                return m_projection_matrix;
            }

            // セッタ
            set
			{
                m_projection_matrix = value;
            }
        }

		// 視野角
		public float mp_field_of_view
		{
			// ゲッタ
			get
			{
				return m_field_of_view;
			}

			// セッタ
			set
			{
				m_field_of_view = value;
			}
		}

		// アスペクト比
		public float mp_aspect_ratio
		{
			// ゲッタ
			get
			{
				return m_aspect_ratio;
			}

			// セッタ
			set
			{
				m_aspect_ratio = value;
			}
		}

		// 描画開始距離
		public float mp_near_distance
		{
            // ゲッタ
            get
			{
                return m_near_distance;
            }

            // セッタ
            set
			{
                m_near_distance = value;
            }
        }

		// 描画終了距離
		public float mp_far_distance
		{
            // ゲッタ
            get
			{
                return m_far_distance;
            }

            // セッタ
            set
			{
                m_far_distance = value;
            }
        }


		// ☆ 関数 ☆ //

		//-☆- マトリクス -☆-//

		// プロジェクション変換行列の作成
		public void M_Create_Projection_Matrix()
		{
            m_projection_matrix = SharpDX.Matrix.PerspectiveFovLH(m_field_of_view, m_aspect_ratio, m_near_distance, m_far_distance);

			return;
        }
	}
}
