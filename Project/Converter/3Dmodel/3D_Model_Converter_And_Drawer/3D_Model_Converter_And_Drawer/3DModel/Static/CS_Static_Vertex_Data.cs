using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel
{
    // ☆ クラス ☆ //

    // 静的な頂点データのクラス
    public class CS_Static_Vertex_Data
    {
        // ☆ 変数宣言 ☆ //
        private Vector3 m_position = new Vector3(); // 位置座標

        private Vector2 m_uv = new Vector2();       // uv座標

        private Vector4 m_color = new Vector4();    // 頂点カラー

        private Vector3 m_normal = new Vector3();   // 法線ベクトル
        private Vector3 m_tangent = new Vector3();  // タンジェントベクトル
        private Vector3 m_bi_normal_tangent = new Vector3();    // 従法線ベクトル


        // ☆ プロパティ ☆ //

        // 位置座標
        public Vector3 mp_position
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

        // uv座標
        public Vector2 mp_uv
        {
            // ゲッタ
            get
            {
                return m_uv;
            }

            // セッタ
            set
            {
                m_uv = value;
            }
        }

        // 頂点カラー
        public Vector4 mp_color
        {
            // ゲッタ
            get
            {
                return m_color;
            }

            // セッタ
            set
            {
                m_color = value;
            }
        }

        // 法線ベクトル
        public Vector3 mp_normal
        {
            // ゲッタ
            get
            {
                return m_normal;
            }

            // セッタ
            set
            {
                m_normal = value;
            }
        }

        // タンジェントベクトル
        public Vector3 mp_tangent
        {
            // ゲッタ
            get
            {
                return m_tangent;
            }

            // セッタ
            set
            {
                m_tangent = value;
            }
        }

        // 従法線ベクトル
        public Vector3 mp_bi_normal_tangent
        {
            // ゲッタ
            get
            {
                return m_bi_normal_tangent;
            }

            // セッタ
            set
            {
                m_bi_normal_tangent = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- コンストラクタ -☆-//

        // コンストラクタ
        public CS_Static_Vertex_Data()
        {
            return;
        }
    }
}
