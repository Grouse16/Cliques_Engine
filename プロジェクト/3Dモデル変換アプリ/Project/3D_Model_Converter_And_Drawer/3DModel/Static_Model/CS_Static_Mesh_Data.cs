using System.Collections.Generic;

namespace _3D_Model_Converter_And_Drawer._3DModel
{
    // ☆ クラス ☆ //

    // メッシュデータのクラス
    public class CS_Static_Mesh_Data
    {
        // ☆ 変数宣言 ☆ //
        private List<uint> m_index_list = new List<uint>();   // 頂点インデックス番号のリスト

        string m_name = "";  // メッシュ名

        private string m_material_name = ""; // マテリアルデータ


        // ☆ プロパティ ☆ //

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

        // マテリアルデータ
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

        //-☆- コンストラクタ -☆-//

        // コンストラクタ
        public CS_Static_Mesh_Data()
        {
            return;
        }
    }
}
