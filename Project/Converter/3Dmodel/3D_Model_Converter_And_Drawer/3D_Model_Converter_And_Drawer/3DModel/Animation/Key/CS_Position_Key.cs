using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.System
{
    // ☆ クラス ☆ //

    // 位置座標のキー情報のクラス
    public class CS_Position_Key
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Vector3 m_position = new SharpDX.Vector3();  // 位置座標

        private float m_time = 0.0f;    // 時間


        // ☆ プロパティ ☆ //

        // 位置座標
        public SharpDX.Vector3 mp_position
        {
            // ゲッタ
            get
            {
                return m_position;
            }

            // セッタ
            set
            {
                m_position = value;
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
