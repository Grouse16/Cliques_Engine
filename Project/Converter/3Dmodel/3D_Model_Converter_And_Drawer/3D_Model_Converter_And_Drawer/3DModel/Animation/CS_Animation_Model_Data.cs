using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation
{
    // ☆ クラス ☆ //

    // アニメーションモデルデータのクラス
    public class CS_Animation_Model_Data
    {
        // ☆ 変数宣言 ☆ //
        string m_name = "";  // モデル名

        private List<CS_Animation_Mesh_Data> m_mesh_vertex_data_list = new List<CS_Animation_Mesh_Data>(); // メッシュデータのリスト

        private List<CS_Bone_Data> m_bone_data_list = new List<CS_Bone_Data>(); // ボーンデータのリスト


        // ☆ プロパティ ☆ //

        // モデル名
        public string mp_name
        {
            // ゲッタ
            get
            {
                return m_name;
            }

            // セッタ
            set
            {
                m_name = value;
            }
        }

        // メッシュデータのリスト
        public List<CS_Animation_Mesh_Data> mp_mesh_list
        {
            // ゲッタ
            get
            {
                return m_mesh_vertex_data_list;
            }

            // セッタ
            set
            {
                m_mesh_vertex_data_list = value;
            }
        }

        // ボーンデータのリスト
        public List<CS_Bone_Data> mp_bone_data_list
        {
            // ゲッタ
            get
            {
                return m_bone_data_list;
            }

            // セッタ
            set
            {
                m_bone_data_list = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Animation_Model_Data()
        {
            return;
        }
    }
}
