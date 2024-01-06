using _3D_Model_Converter_And_Drawer.Rendering_Systems.Projection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.Rendering_Systems.Camera
{
    // ☆ クラス ☆ //

    // カメラシステムのクラス
    public class CS_Camera_System
    {
        // ☆ 変数宣言 ☆ //
        private d3d11.CS_Position m_position = new d3d11.CS_Position(); // カメラの位置座標

        private d3d11.CS_Rotation m_rotation = new d3d11.CS_Rotation(); // カメラの回転角度

        private SharpDX.Matrix m_camera_matrix = new SharpDX.Matrix(); // カメラのビュー行列

        private CS_Projection m_projection = new CS_Projection(); // カメラの射影行列


        // ☆ プロパティ ☆ //

        // カメラの位置座標
        public d3d11.CS_Position mp_position
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

        // カメラの回転角度
        public d3d11.CS_Rotation mp_rotation
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

        // カメラのビュー行列
        public SharpDX.Matrix mp_camera_matrix
        {
            // ゲッタ
            get
            {
                return m_camera_matrix;
            }

            // セッタ
            set
            {
                m_camera_matrix = value;
            }
        }

        // カメラの射影行列
        public CS_Projection mp_projection
        {
            // ゲッタ
            get
            {
                return m_projection;
            }

            // セッタ
            set
            {
                m_projection = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Camera_System()
        {
            m_projection.mp_field_of_view = 90.0f;
            m_projection.mp_aspect_ratio = 0.0f;
            m_projection.mp_near_distance = 0.1f;
            m_projection.mp_far_distance = 100.0f;

            return;
        }


        //-☆- マトリクス -☆-//

        // カメラのビュー行列を計算する関数
        public void M_Calculate_Camera_Matrix()
        {
            // ☆ 変数宣言 ☆ //
            SharpDX.Matrix rotation_matrix = new SharpDX.Matrix(); // 回転のマトリクス

            SharpDX.Vector3 up_vector = new SharpDX.Vector3();  // 上方向のベクトル
            SharpDX.Vector3 target = new SharpDX.Vector3();     // カメラの注視点


            // 回転のマトリクスを計算する
            mp_rotation.M_Convert_Matrix(out rotation_matrix);

            // 上方向のベクトルをセットする
            up_vector = rotation_matrix.Up;

            // カメラの注視点をセットする
            target = mp_position.mp_pos + rotation_matrix.Forward * 100.0f;


            // カメラのビューマトリクスを計算する
            mp_camera_matrix = SharpDX.Matrix.LookAtLH(mp_position.mp_pos, target, up_vector);

            return;
        }
    }
}
