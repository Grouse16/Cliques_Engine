using _3D_Model_Converter_And_Drawer._3DModel.Animation.System;
using _3D_Model_Converter_And_Drawer.d3d11;
using _3D_Model_Converter_And_Drawer.d3d11.Transform;
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
        public List<CS_Position_Key> mp_position
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
        public List<CS_Rotation_Key> mp_rotation
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
        public List<CS_Scale_Key> mp_scale
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
        public CS_Key_Frame()
        {
            return;
        }


        //-☆- ゲッタ -☆-//

        // 指定された時間の位置座標の番号を取得する　引数：時間　戻り値：キー番号
        private int M_Get_Position_Key_By_Time(float in_time)
        {
            // ☆ 変数宣言 ☆ //
            int search_end_number = m_position.Count - 1; // 探索終了位置のキー番号


            // 指定された時間のキー番号を取得する
            for (int l_now_position_number = 0; l_now_position_number < search_end_number; l_now_position_number++)
            {
                if (m_position[l_now_position_number].mp_time <= in_time && in_time < m_position[l_now_position_number + 1].mp_time)
                {
                    return l_now_position_number;
                }
            }

            // 無ければ最後まで再生され切ったということなので最後のキーを返す
            return m_position.Count - 1;
        }


        // 指定された時間の回転角度の番号を取得する　引数：時間　戻り値：キー番号
        private int M_Get_Rotation_Key_By_Time(float in_time)
        {
            // ☆ 変数宣言 ☆ //
            int search_end_number = m_rotation.Count - 1; // 探索終了位置のキー番号


            // 指定された時間のキー番号を取得する
            for (int l_now_rotation_number = 0; l_now_rotation_number < search_end_number; l_now_rotation_number++)
            {
                if (m_rotation[l_now_rotation_number].mp_time <= in_time && in_time < m_rotation[l_now_rotation_number + 1].mp_time)
                {
                    return l_now_rotation_number;
                }
            }

            // 無ければ最後まで再生され切ったということなので最後のキーを返す
            return m_rotation.Count - 1;
        }


        // 指定された時間のスケールの番号を取得する　引数：時間　戻り値：キー番号
        private int M_Get_Scale_Key_By_Time(float in_time)
        {
            // ☆ 変数宣言 ☆ //
            int search_end_number = m_scale.Count - 1; // 探索終了位置のキー番号


            // 指定された時間のキー番号を取得する
            for (int l_now_scale_number = 0; l_now_scale_number < search_end_number; l_now_scale_number++)
            {
                if (m_scale[l_now_scale_number].mp_time <= in_time && in_time < m_scale[l_now_scale_number + 1].mp_time)
                {
                    return l_now_scale_number;
                }
            }

            // 無ければ最後まで再生され切ったということなので最後のキーを返す
            return m_scale.Count - 1;
        }


        //-☆- キーフレーム番号 -☆-//

        // 指定された時間から位置座標の前後のキーとの補間を行う　引数：キーフレーム番号, 時間, 補間後の位置座標
        public void M_Lerp_Position_Key(float in_time, ref CS_Position out_position)
        {
            // ☆ 変数宣言 ☆ //
            int now_key_number = M_Get_Position_Key_By_Time(in_time); // 現在のキーフレーム番号


            // 現在のキーフレーム番号が最後のキーフレーム番号なら最後のキーの位置座標を返す
            if (m_position.Count == now_key_number)
            {
                out_position = m_position[now_key_number].mp_data;
                return;
            }

            // 現在のキーフレーム番号が最後のキーフレーム番号でないなら補間を行う
            else
            {
                // ☆ 変数宣言 ☆ //
                float now_key_time = m_position[now_key_number].mp_time; // 現在のキーの時間
                float next_key_time = m_position[now_key_number + 1].mp_time; // 次のキーの時間
                float blend_percent = (in_time - now_key_time) / (next_key_time - now_key_time); // ブレンド率


                // 現在のキーと次のキーの補間を行う
                CS_Position.M_Blend(ref out_position, m_position[now_key_number].mp_data, m_position[now_key_number + 1].mp_data, blend_percent);
            }

            return;
        }


        // 指定された時間から回転角度の前後のキーとの補間を行う　引数：時間, 補間後の回転角度
        public void M_SLerp_Rotation_Key(float in_time, ref CS_Rotation out_rotation)
        {
            // ☆ 変数宣言 ☆ //
            int now_key_number = M_Get_Rotation_Key_By_Time(in_time); // 現在のキーフレーム番号


            // 現在のキーフレーム番号が最後のキーフレーム番号なら最後のキーの回転角度を返す
            if (m_rotation.Count == now_key_number)
            {
                out_rotation = m_rotation[now_key_number].mp_data;
                return;
            }

            // 現在のキーフレーム番号が最後のキーフレーム番号でないなら補間を行う
            else
            {
                // ☆ 変数宣言 ☆ //
                float now_key_time = m_rotation[now_key_number].mp_time; // 現在のキーの時間
                float next_key_time = m_rotation[now_key_number + 1].mp_time; // 次のキーの時間
                float blend_percent = (in_time - now_key_time) / (next_key_time - now_key_time); // ブレンド率


                // 現在のキーと次のキーの補間を行う
                CS_Rotation.M_Blend(ref out_rotation, m_rotation[now_key_number].mp_data, m_rotation[now_key_number + 1].mp_data, blend_percent);
            }

            return;
        }


        // 回転角度のキーの補間をブレンドして返す　引数：時間, ブレンド率, ブレンドするの回転角度, 補間後の回転角度
        public void M_SLerp_Rotation_Key_And_Blend(float in_time, float in_blend_percent, CS_Rotation in_blend_rotation, ref CS_Rotation out_rotation)
        {
            // ☆ 変数宣言 ☆ //
            CS_Rotation key_frame_rotation = new CS_Rotation(); // キーフレームの回転角度

            int now_key_number = M_Get_Rotation_Key_By_Time(in_time); // 現在のキーフレーム番号


            // 現在のキーフレーム番号が最後のキーフレーム番号なら最後のキーの回転角度を返す
            if (m_rotation.Count == now_key_number)
            {
                key_frame_rotation = m_rotation[now_key_number].mp_data;
                return;
            }

            // 現在のキーフレーム番号が最後のキーフレーム番号でないなら補間を行う
            else
            {
                // ☆ 変数宣言 ☆ //
                float now_key_time = m_rotation[now_key_number].mp_time; // 現在のキーの時間
                float next_key_time = m_rotation[now_key_number + 1].mp_time; // 次のキーの時間
                float blend_percent = (in_time - now_key_time) / (next_key_time - now_key_time); // ブレンド率


                // 現在のキーと次のキーの補間を行う
                CS_Rotation.M_Blend(ref key_frame_rotation, m_rotation[now_key_number].mp_data, m_rotation[now_key_number + 1].mp_data, blend_percent);
            }

            // ブレンドする回転角度と補間後の回転角度をブレンドする
            CS_Rotation.M_Blend(ref out_rotation, key_frame_rotation, in_blend_rotation, in_blend_percent);

            return;
        }


        // 指定された時間からスケールの前後のキーとの補間を行う　引数：時間, 補間後のスケール
        public void M_Lerp_Scale_Key(float in_time, ref CS_Scale out_scale)
        {
            // ☆ 変数宣言 ☆ //
            int now_key_number = M_Get_Scale_Key_By_Time(in_time); // 現在のキーフレーム番号


            // 現在のキーフレーム番号が最後のキーフレーム番号なら最後のキーのスケールを返す
            if (m_scale.Count == now_key_number)
            {
                out_scale = m_scale[now_key_number].mp_data;
                return;
            }

            // 現在のキーフレーム番号が最後のキーフレーム番号でないなら補間を行う
            else
            {
                // ☆ 変数宣言 ☆ //
                float now_key_time = m_scale[now_key_number].mp_time; // 現在のキーの時間
                float next_key_time = m_scale[now_key_number + 1].mp_time; // 次のキーの時間
                float blend_percent = (in_time - now_key_time) / (next_key_time - now_key_time); // ブレンド率


                // 現在のキーと次のキーの補間を行う
                CS_Scale.M_Blend(ref out_scale, m_scale[now_key_number].mp_data, m_scale[now_key_number + 1].mp_data, blend_percent);
            }

            return;
        }



        //-☆- 生成 -☆-//

        // トランスフォームを生成して返す　引数：トランスフォームの設定先, 時間
        public void M_Convert_To_Transform(out CS_Transform out_transform, float in_time)
        {
            // ☆ 変数宣言 ☆ //
            CS_Position new_position = new CS_Position(); // 位置座標

            CS_Rotation new_rotation = new CS_Rotation(); // 回転角度

            CS_Scale new_scale = new CS_Scale(); // スケール


            // 新しいトランスフォームを生成する
            out_transform = new CS_Transform();


            // 位置座標の補間を行う
            M_Lerp_Position_Key(in_time, ref new_position);

            // 回転角度の補間を行う
            M_SLerp_Rotation_Key(in_time, ref new_rotation);

            // スケールの補間を行う
            M_Lerp_Scale_Key(in_time, ref new_scale);


            // トランスフォームに設定する
            out_transform.mp_position = new_position;
            out_transform.mp_rotation = new_rotation;
            out_transform.mp_scale = new_scale;

            return;
        }


        // 渡されたトランスフォームとキーフレーム情報をブレンドして返す　引数：トランスフォームの設定先, ブレンド先のトランスフォーム, 時間, ブレンド率
        public void M_Convert_To_Transform_And_Blend(out CS_Transform out_transform, CS_Transform in_blend_to_transform, float in_time, float in_blend_percent)
        {
            // ☆ 変数宣言 ☆ //
            CS_Position new_position = new CS_Position(); // 位置座標

            CS_Rotation new_rotation = new CS_Rotation(); // 回転角度

            CS_Scale new_scale = new CS_Scale(); // スケール


            // 新しいトランスフォームを生成する
            out_transform = new CS_Transform();


            // 位置座標の補間を行う
            M_Lerp_Position_Key(in_time, ref new_position);

            // 回転角度の補間を行う
            M_SLerp_Rotation_Key_And_Blend(in_time, in_blend_percent, in_blend_to_transform.mp_rotation, ref new_rotation);

            // スケールの補間を行う
            M_Lerp_Scale_Key(in_time, ref new_scale);


            // ブレンドしてトランスフォームに設定する
            out_transform.mp_position.mp_pos = new_position.mp_pos * (1.0f - in_blend_percent) + in_blend_to_transform.mp_position.mp_pos * in_blend_percent;
            out_transform.mp_rotation = new_rotation;
            out_transform.mp_scale.mp_scale = new_scale.mp_scale * (1.0f - in_blend_percent) + in_blend_to_transform.mp_scale.mp_scale * in_blend_percent;

            return;
        }
    }
}
