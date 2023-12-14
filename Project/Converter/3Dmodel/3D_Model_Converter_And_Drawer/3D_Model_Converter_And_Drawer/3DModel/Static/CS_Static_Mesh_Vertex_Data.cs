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
    public class CS_Static_Mesh_Vertex_Data
    {
        // ☆ 変数宣言 ☆ //
        private List<CS_Static_Vertex_Data> m_vertex_data_list = new List<CS_Static_Vertex_Data>(); // 頂点データのリスト

        private List<uint> m_index_list = new List<uint>();   // 頂点インデックス番号のリスト


        // ☆ プロパティ ☆ //

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
        public CS_Static_Mesh_Vertex_Data()
        {
            return;
        }
    }
}
