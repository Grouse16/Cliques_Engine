using _3D_Model_Converter_And_Drawer.d3d11.Transform;
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
        private CS_Scale m_scale = new CS_Scale();  // スケール

        private float m_time = 0.0f;    // 時間


        // ☆ プロパティ ☆ //

        // スケール
        public CS_Scale mp_scale
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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Scale_Key()
        {
            return;
        }
    }
}
