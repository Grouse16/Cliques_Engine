using _3D_Model_Converter_And_Drawer._3DModel.Animation.Bone;
using _3D_Model_Converter_And_Drawer._3DModel.Animation.Key;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.System
{
    // ☆ クラス ☆ //

    // アニメーションのシステムのクラス
    public class CS_Animation_System
    {
        // ☆ 変数宣言 ☆ //
        private List<CS_Animation_Bone_Data> m_bone_list = new List<CS_Animation_Bone_Data>(); // ボーンのアニメーション情報のリスト

        float m_end_time = 0.0f;    // アニメーションの終了時間


        // ☆ プロテクト ☆ //

        // ボーンのアニメーション情報のリスト
        protected List<CS_Animation_Bone_Data> Bone_List
        {
            // ゲッタ
            get
            {
                return m_bone_list;
            }

            // セッタ
            set
            {
                m_bone_list = value;
            }
        }

        // アニメーションの終了時間
        protected float End_Time
        {
            // ゲッタ
            get
            {
                return m_end_time;
            }

            // セッタ
            set
            {
                m_end_time = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_Animation_System()
        {
            return;
        }
    }
}
