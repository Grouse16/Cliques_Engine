using Assimp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation
{
    // ☆ クラス ☆ //

    // ボーンのデータのクラス
    public class CS_Model_Bone_Data
    {
        // ☆ 変数宣言 ☆ //
        SharpDX.Matrix m_offset_matrix = new SharpDX.Matrix(); // オフセットマトリクス行列

        private int m_parent_bone_index = -1; // 親ボーンのインデックス

        private string m_name = ""; // ボーン名


        // ☆ プロパティ ☆ //

        // オフセットマトリクス行列
        public SharpDX.Matrix mp_offset_matrix
        {
            // ゲッタ
            get
            {
                return m_offset_matrix;
            }

            // セッタ
            set
            {
                m_offset_matrix = value;
            }
        }

        // 親ボーンのインデックス
        public int mp_parent_bone_index
        {
            // ゲッタ
            get
            {
                return m_parent_bone_index;
            }

            // セッタ
            set
            {
                m_parent_bone_index = value;
            }
        }

        // ボーン名
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
        public CS_Model_Bone_Data()
        {
            return;
        }
    }
}
