using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.Constant_Data
{
    // ☆ 構造体 ☆ //

    // WVP行列の構造体
    public struct S_WVP
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Matrix m_world_matrix; // ワールド行列

        private SharpDX.Matrix m_view_matrix; // ビュー行列

        private SharpDX.Matrix m_projection_matrix; // 射影行列


        // ☆ プロパティ ☆ //

        // ワールド行列
        public SharpDX.Matrix mp_world_matrix
        {
            // ゲッタ
            get
            {
                return m_world_matrix;
            }

            // セッタ
            set
            {
                m_world_matrix = value;
            }
        }

        // ビュー行列
        public SharpDX.Matrix mp_view_matrix
        {
            // ゲッタ
            get
            {
                return m_view_matrix;
            }

            // セッタ
            set
            {
                m_view_matrix = value;
            }
        }

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
    }
}
