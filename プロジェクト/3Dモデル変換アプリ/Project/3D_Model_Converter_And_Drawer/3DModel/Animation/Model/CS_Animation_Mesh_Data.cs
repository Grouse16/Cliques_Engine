using _3D_Model_Converter_And_Drawer._3DModel.Material;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation
{
    // ☆ クラス ☆ //

    // アニメーション用メッシュデータのクラス
    public class CS_Animation_Mesh_Data
    {
        // ☆ 変数宣言 ☆ //
        private List<uint> m_index_data_list = new List<uint>();    // 頂点インデックス番号のリスト

        private string m_name = "";  // メッシュ名

        private string m_material_name = ""; // マテリアル名


        // ☆ プロパティ ☆ //

        // 頂点インデックス番号のリスト
        public List<uint> mp_index_data_list
        {
            // ゲッタ
            get
            {
                return m_index_data_list;
            }

            // セッタ
            set
            {
                m_index_data_list = value;
            }
        }

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

        // マテリアル
        public string mp_material_name
        {
            // ゲッタ
            get
            {
                return m_material_name;
            }

            // セッタ
            set
            {
                m_material_name = value;
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
