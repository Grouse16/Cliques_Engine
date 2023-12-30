using _3D_Model_Converter_And_Drawer._3DModel.Animation.Key;
using _3D_Model_Converter_And_Drawer.d3d11.Transform;
using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.Bone
{
    // ☆ クラス ☆ //

    // ボーンのアニメーションデータのクラス
    public class CS_Animation_Bone_Data
    {
        // ☆ 変数宣言 ☆ //
        private CS_Key_Frame m_key_frame = new CS_Key_Frame(); // キーフレーム情報

        private int m_index = 0; // ボーンインデックス番号

        private string m_name = ""; // ボーン名


        // ☆ プロパティ ☆ //

        // キーフレーム情報
        public CS_Key_Frame mp_key_frame
        {
            // ゲッタ
            get
            {
                return m_key_frame;
            }

            // セッタ
            set
            {
                m_key_frame = value;
            }
        }

        // ボーンインデックス番号
        public int mp_index
        {
            // ゲッタ
            get
            {
                return m_index;
            }

            // セッタ
            set
            {
                m_index = value;
            }
        }

        // ボーン名
        public string mp_name
        {
            // ゲッタ
            get
            {
                return m_name;
            }

            // セッタ
            set
            {
                m_name = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Animation_Bone_Data()
        {
            return;
        }


        //-☆- マトリクス -☆-//

        // 指定された時間のキーフレーム情報をトランスフォームに変換して返す　引数：変換後のトランスフォームの設定先, 時間
        public void M_Convert_To_Matrix_By_Time(out CS_Transform out_matrix, float in_time)
        {
            // トランスフォームを初期化
            out_matrix = new CS_Transform();


            // キーフレーム情報をトランスフォームで取得
            m_key_frame.M_Convert_To_Transform(out out_matrix, in_time);

            return;
        }


        // 指定された時間のキーフレーム情報を渡されたトランスフォームとブレンドして返す　引数：変換後のトランスフォームの設定先, ブレンド先のトランスフォーム, 時間, ブレンド率
        public void M_Convert_To_Matrix_By_Time_And_Blend(out CS_Transform out_transform, CS_Transform in_blend_to_transform, float in_time, float in_blend_percent)
        {
            // トランスフォームを初期化
            out_transform = new CS_Transform();


            // キーフレーム情報をトランスフォームで取得
            m_key_frame.M_Convert_To_Transform_And_Blend(out out_transform, in_blend_to_transform, in_time, in_blend_percent);

            return;
        }
    }
}
