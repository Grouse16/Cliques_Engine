using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
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


        // スケール設定用コンストラクタ　引数：スケールｘ, スケールｙ, スケールｚ
        public CS_Scale(float in_scale_x, float in_scale_y, float in_scale_z)
        {
            m_scale.X = in_scale_x;
            m_scale.Y = in_scale_y;
            m_scale.Z = in_scale_z;

            return;
        }


        //-☆- ブレンド -☆-//

        // スケールのブレンド　引数：ブレンド後のスケールの設定先, ブレンド元のスケール, ブレンド先のスケール, ブレンド率
        static public void M_Blend(ref CS_Scale out_scale, CS_Scale in_start_scale, CS_Scale in_end_scale, float in_blend_percent)
        {
            out_scale.mp_scale = SharpDX.Vector3.Lerp(in_start_scale.mp_scale, in_end_scale.mp_scale, in_blend_percent);

            return;
        }


        //-☆- マトリクス -☆-//

        // スケールのキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(out SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.Scaling(m_scale);

            return;
        }
    }
}
