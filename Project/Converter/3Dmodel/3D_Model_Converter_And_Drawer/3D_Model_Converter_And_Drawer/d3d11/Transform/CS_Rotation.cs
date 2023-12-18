using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11.Transform
{
    // ☆ クラス ☆ //

    // 回転角度のクラス
    public class CS_Rotation
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Quaternion m_rotation = new SharpDX.Quaternion();  // 回転角度


        // ☆ プロパティ ☆ //

        // 回転角度
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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Rotation()
        {
            return;
        }


        //-☆- マトリクス -☆-//

        // 回転角度のキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(ref SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.RotationQuaternion(m_rotation);

            return;
        }
    }
}
