using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11.Transform
{
    // ☆ クラス ☆ //

    // トランスフォームのクラス
    public class CS_Transform
    {
        // ☆ 変数宣言 ☆ //
        private CS_Position m_position = new CS_Position();  // 位置座標

        private CS_Rotation m_rotation = new CS_Rotation();  // 回転角度

        private CS_Scale m_scale = new CS_Scale();           // スケール


        // ☆ プロパティ ☆ //

        // 位置座標
        public CS_Position mp_position
        {
            // ゲッタ
            get
            {
                return m_position;
            }

            // セッタ
            set
            {
                m_position = value;
            }
        }

        // 回転角度
        public CS_Rotation mp_rotation
        {
            // ゲッタ
            get
            {
                return m_rotation;
            }

            // セッタ
            set
            {
                m_rotation = value;
            }
        }

        // スケール
        public CS_Scale mp_scale
        {
            // ゲッタ
            get
            {
                return m_scale;
            }

            // セッタ
            set
            {
                m_scale = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Transform()
        {
            return;
        }


        //-☆- マトリクス -☆-//

        // 今の位置座標を元にワールドマトリクスを生成する　引数：ワールドマトリクスの設定先
        public void M_Convert_To_Matrix(ref SharpDX.Matrix out_matrix)
        {
            // ☆ 変数宣言 ☆ //
            SharpDX.Matrix position_matrix = new SharpDX.Matrix();  // 位置座標のマトリクス
            SharpDX.Matrix rotation_matrix = new SharpDX.Matrix();  // 回転のマトリクス
            SharpDX.Matrix scale_matrix = new SharpDX.Matrix();     // スケールのマトリクス
            

            // マトリクスを生成
            m_position.M_Convert_Matrix(out position_matrix);
            m_rotation.M_Convert_Matrix(out rotation_matrix);
            m_scale.M_Convert_Matrix(out scale_matrix);


            // ワールドマトリクスを計算
            out_matrix = scale_matrix * rotation_matrix * position_matrix;

            return;
        }
    }
}
