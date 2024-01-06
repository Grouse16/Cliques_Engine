using _3D_Model_Converter_And_Drawer._3DModel.Animation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Static
{
    // ☆ クラス ☆ //

    // 静的なモデルデータのクラス
    public class CS_Static_Model_Data
    {
        // ☆ 変数宣言 ☆ //
        private List<S_Static_Vertex_Data> m_vertex_data_list = new List<S_Static_Vertex_Data>(); // 頂点データのリスト

        private List<CS_Static_Mesh_Data> m_mesh_data_list = new List<CS_Static_Mesh_Data>(); // メッシュデータのリスト

        string m_name = "";  // モデル名


        //-☆- プロパティ -☆-//

        // 頂点データのリスト
        public List<S_Static_Vertex_Data> mp_vertex_data_list
        {
            // ゲッタ
            get
            {
                return m_vertex_data_list;
            }

            // セッタ
            set
            {
                m_vertex_data_list = value;
            }
        }

        // メッシュデータのリスト
        public List<CS_Static_Mesh_Data> mp_mesh_data_list
        {
            // ゲッタ
            get
            {
                return m_mesh_data_list;
            }

            // セッタ
            set
            {
                m_mesh_data_list = value;
            }
        }

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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Static_Model_Data()
        {
            return;
        }
    }
}
