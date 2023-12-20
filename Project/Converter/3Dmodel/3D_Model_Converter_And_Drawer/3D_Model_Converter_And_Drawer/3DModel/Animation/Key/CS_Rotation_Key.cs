using _3D_Model_Converter_And_Drawer.d3d11.Transform;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.Key
{
    // ☆ クラス ☆ //

    // 回転のキー情報のクラス
    public class CS_Rotation_Key
    {
        // ☆ 変数宣言 ☆ //
        private CS_Rotation m_data = new CS_Rotation();  // 回転

        private float m_time = 0.0f;    // 時間


        // ☆ プロパティ ☆ //

        // 回転
        public CS_Rotation mp_data
        {
            // ゲッタ
            get
            {
                return m_data;
            }

            // セッタ
            set
            {
                m_data = value;
            }
        }

        // 時間
        public float mp_time
        {
            // ゲッタ
            get
            {
                return m_time;
            }

            // セッタ
            set
            {
                m_time = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Rotation_Key()
        {
            return;
        }
    }
}
