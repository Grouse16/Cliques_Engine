using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel
{
    // ☆ クラス ☆ //

    // ボーンウェイト行列のクラス
    public class CS_Bone_Weight_Data
    {
        // ☆ 変数宣言 ☆ //
        float m_weight = 0.0f;  // ウェイト値

        int m_index = 0;        // ボーンインデックス番号


        // ☆ プロパティ ☆ //

        // ウェイト値
        public float mp_weight
        {
            // ゲッタ
            get
            {
                return m_weight;
            }

            // セッタ
            set
            {
                m_weight = value;
            }
        }

        // ボーンインデックス番号
        public int mp_index
        {
            // ゲッタ
            get
            {
                return m_index;
            }

            // セッタ
            set
            {
                m_index = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ　引数：ボーン番号, ボーンウェイト値
        public CS_Bone_Weight_Data(int in_set_index, float in_set_weight)
        {
            m_index = in_set_index;
            m_weight = in_set_weight;

            return;
        }
    }
}
