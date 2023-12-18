using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ クラス ☆ //

    // 頂点のクラス
    public class CS_Position
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Vector3 m_position = new SharpDX.Vector3();  // 位置座標


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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Position()
        {
            return;
        }


        //-☆- マトリクス -☆-//

        // 位置座標のキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(ref SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.Translation(m_position);

            return;
        }
    }
}
