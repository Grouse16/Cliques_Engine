using _3D_Model_Converter_And_Drawer._3DModel.Material;
using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel
{
    // ☆ クラス ☆ //

    // メッシュデータのクラス
    public class CS_Static_Mesh_Data
    {
        // ☆ 変数宣言 ☆ //
        string m_name = "";  // メッシュ名

        private List<CS_Static_Vertex_Data> m_vertex_data_list = new List<CS_Static_Vertex_Data>(); // 頂点データのリスト

        private CS_Material_Data m_material_data = new CS_Material_Data(); // マテリアルデータ

        private List<uint> m_index_list = new List<uint>();   // 頂点インデックス番号のリスト


        // ☆ プロパティ ☆ //

        // メッシュ名
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

        // 頂点データのリスト
        public List<CS_Static_Vertex_Data> mp_vertex_data_list
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

        // マテリアルデータ
        public CS_Material_Data mp_material_data
        {
            // ゲッタ
            get
            {
                return m_material_data;
            }

            // セッタ
            set
            {
                m_material_data = value;
            }
        }

        // 頂点インデックスのリスト
        public List<uint> mp_index_list
        {
            // ゲッタ
            get
            {
                return m_index_list;
            }

            // セッタ
            set
            {
                m_index_list = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- コンストラクタ -☆-//

        // コンストラクタ
        public CS_Static_Mesh_Data()
        {
            return;
        }
    }
}
