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
    public class CS_Bone_Data
    {
        // ☆ 変数宣言 ☆ //
        private string m_name = ""; // ボーン名

        Matrix4x4 m_offset_matrix; // オフセットマトリクス行列


        // ☆ プロパティ ☆ //

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

        // オフセットマトリクス行列
        public Matrix4x4 mp_offset_matrix
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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Bone_Data()
        {
            return;
        }
    }
}
