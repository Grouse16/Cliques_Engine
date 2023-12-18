using _3D_Model_Converter_And_Drawer._3DModel.Animation.System;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.Key
{
    // ☆ クラス ☆ //

    // キーフレームのクラス
    public class CS_Key_Frame
    {
        // ☆ 変数宣言 ☆ //
        private List<CS_Position_Key> m_position = new List<CS_Position_Key>(); // 位置座標のリスト

        private List<CS_Rotation_Key> m_rotation = new List<CS_Rotation_Key>(); // 回転角度のリスト

        private List<CS_Scale_Key> m_scale = new List<CS_Scale_Key>(); // スケールのリスト


        // ☆ プロパティ ☆ //

        // 位置座標のリスト
        public List<CS_Position_Key> Position
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

        // 回転角度のリスト
        public List<CS_Rotation_Key> Rotation
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

        // スケールのリスト
        public List<CS_Scale_Key> Scale
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
    }
}
