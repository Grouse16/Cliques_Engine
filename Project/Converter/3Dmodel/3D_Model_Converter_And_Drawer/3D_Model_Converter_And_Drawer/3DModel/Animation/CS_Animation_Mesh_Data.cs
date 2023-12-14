using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation
{
    // ☆ クラス ☆ //

    // アニメーション用メッシュデータのクラス
    public class CS_Animation_Mesh_Data
    {
        // ☆ 変数宣言 ☆ //
        private List<CS_Animation_Vertex_Data> m_vertex_data_list = new List<CS_Animation_Vertex_Data>(); // 頂点データのリスト

        private List<uint> m_index_data_list = new List<uint>();    // 頂点インデックス番号のリスト
            

        // ☆ プロパティ ☆ //

        // 頂点データのリスト
        public List<CS_Animation_Vertex_Data> mp_vertex_data_list
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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Animation_Mesh_Data()
        {
            return;
        }
    }
}
