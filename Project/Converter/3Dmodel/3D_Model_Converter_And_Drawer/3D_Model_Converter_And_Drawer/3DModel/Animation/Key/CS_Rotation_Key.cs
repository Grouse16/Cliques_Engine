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
        private SharpDX.Quaternion m_rotation = new SharpDX.Quaternion();  // 回転

        private float m_time = 0.0f;    // 時間


        // ☆ プロパティ ☆ //

        // 回転
        public SharpDX.Quaternion mp_rotation
        {
            // ゲッタ
            get
            {
                return m_rotation;
            }

            // セッタ
            set
            {
                m_rotation = value;
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
    }
}
