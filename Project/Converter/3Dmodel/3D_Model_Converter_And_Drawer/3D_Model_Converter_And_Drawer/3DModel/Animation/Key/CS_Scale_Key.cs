using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.Key
{
    // ☆ クラス ☆ //

    // スケールのキー情報のクラス
    public class CS_Scale_Key
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Vector3 m_scale = new SharpDX.Vector3();  // スケール

        private float m_time = 0.0f;    // 時間


        // ☆ プロパティ ☆ //

        // スケール
        public SharpDX.Vector3 mp_scale
        {
            // ゲッタ
            get
            {
                return m_scale;
            }

            // セッタ
            set
            {
                m_scale = value;
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
