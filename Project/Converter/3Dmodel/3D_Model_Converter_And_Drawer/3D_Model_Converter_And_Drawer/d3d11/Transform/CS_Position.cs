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
        public SharpDX.Vector3 mp_pos
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

        // 位置座標セット用コンストラクタ　引数：位置座標ｘ, 位置座標ｙ, 位置座標ｚ
        public CS_Position(float in_pos_x, float in_pos_y, float in_pos_z)
        {
            m_position.X = in_pos_x;
            m_position.Y = in_pos_y;
            m_position.Z = in_pos_z;

            return;
        }


        //-☆- ブレンド -☆-//

        // 位置座標のブレンド　引数：ブレンド後の位置座標の設定先, ブレンド元の位置座標, ブレンド先の位置座標, ブレンド率
        static public void M_Blend(ref CS_Position out_pos, CS_Position in_start_pos, CS_Position in_end_pos, float in_blend_percent)
        {
            out_pos.mp_pos = in_start_pos.mp_pos * (1.0f - in_blend_percent) + in_end_pos.mp_pos * in_blend_percent;

            return;
        }


        //-☆- マトリクス -☆-//

        // 位置座標のキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(out SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.Translation(m_position);

            return;
        }
    }
}
