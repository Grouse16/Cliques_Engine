namespace _3D_Model_Converter_And_Drawer.d3d11
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

        
        // 回転座標セット用コンストラクタ　引数：回転角度ｘ, 回転角度ｙ, 回転角度ｚ, 回転角度ｗ
        public CS_Rotation(float in_rotation_x, float in_rotation_y, float in_rotation_z, float in_rotation_w)
        {
            m_rotation.X = in_rotation_x;
            m_rotation.Y = in_rotation_y;
            m_rotation.Z = in_rotation_z;
            m_rotation.W = in_rotation_w;

            return;
        }


        //-☆- ブレンド -☆-//

        // 回転角度のブレンド　引数：ブレンド後の回転角度の設定先, ブレンド元の回転角度, ブレンド後の回転角度, ブレンド率
        static public void M_Blend(ref CS_Rotation out_rotation, CS_Rotation in_start_rotation, CS_Rotation in_end_rotation, float in_blend_percent)
        {
            out_rotation.mp_rotation = SharpDX.Quaternion.Slerp(in_start_rotation.mp_rotation, in_end_rotation.mp_rotation, in_blend_percent);

            return;
        }


        //-☆- マトリクス -☆-//

        // 回転角度のキー情報をマトリクスに変換する　引数：変換後のマトリクスの設定先
        public void M_Convert_Matrix(out SharpDX.Matrix out_matrix)
        {
            out_matrix = SharpDX.Matrix.RotationQuaternion(m_rotation);

            return;
        }
    }
}
