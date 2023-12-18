using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11.Transform
{
    // ☆ クラス ☆ //

    // スケールのクラス
    public class CS_Scale
    {
        // ☆ 変数宣言 ☆ //
        private SharpDX.Vector3 m_scale = new SharpDX.Vector3();  // スケール


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


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Scale()
        {
            return;
        }


        //-☆- マトリクス -☆-//

        // スケールのキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(ref SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.Scaling(m_scale);

            return;
        }
    }
}
