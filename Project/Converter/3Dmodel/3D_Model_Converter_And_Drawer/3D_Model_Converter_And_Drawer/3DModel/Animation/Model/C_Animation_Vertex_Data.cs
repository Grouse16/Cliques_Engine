using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel
{
    // ☆ 構造体 ☆ //

    // アニメーションする頂点データの構造体
    public struct S_Animation_Vertex_Data
    {
        // ☆ 変数宣言 ☆ //
        private Vector3 m_position; // 位置座標

        private Vector2 m_uv;       // uv座標

        private Vector4 m_color;    // 頂点カラー

        private Vector3 m_normal;   // 法線ベクトル
        private Vector3 m_tangent;  // タンジェントベクトル
        private Vector3 m_bi_normal_tangent;    // 従法線ベクトル

        private List<CS_Bone_Weight_Data> m_bone_weight; // ボーンウェイト行列のリスト


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

        // ボーンウェイト情報
        public List<CS_Bone_Weight_Data> mp_bone_weight
        {
            // ゲッタ
            get
            {
                return m_bone_weight;
            }

            // セッタ
            set
            {
                m_bone_weight = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ　引数：位置座標, uv座標, 頂点カラー, 法線ベクトル, タンジェントベクトル, 従法線ベクトル
        public S_Animation_Vertex_Data(Vector3 in_position, Vector2 in_uv, Vector4 in_color, Vector3 in_normal, Vector3 in_tangent, Vector3 in_bi_normal_tangent)
        {
            m_position = in_position;
            m_uv = in_uv;
            m_color = in_color;
            m_normal = in_normal;
            m_tangent = in_tangent;
            m_bi_normal_tangent = in_bi_normal_tangent;
            m_bone_weight = new List<CS_Bone_Weight_Data>();
            m_bone_weight.Add(new CS_Bone_Weight_Data(0, 0.0f));
            m_bone_weight.Add(new CS_Bone_Weight_Data(0, 0.0f));
            m_bone_weight.Add(new CS_Bone_Weight_Data(0, 0.0f));
            m_bone_weight.Add(new CS_Bone_Weight_Data(0, 0.0f));

            return;
        }
    }
}
