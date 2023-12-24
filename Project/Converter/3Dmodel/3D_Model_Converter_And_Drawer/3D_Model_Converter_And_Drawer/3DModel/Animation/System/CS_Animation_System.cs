﻿using _3D_Model_Converter_And_Drawer._3DModel.Animation.Bone;
using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;

namespace _3D_Model_Converter_And_Drawer._3DModel.Animation.System
{
	// ☆ クラス ☆ //

	// アニメーションのシステムのクラス
	public class CS_Animation_System
	{
		// ☆ 変数宣言 ☆ //
		private List<CS_Animation_Bone_Data> m_bone_list = new List<CS_Animation_Bone_Data>(); // ボーンのアニメーション情報のリスト

		private float m_start_time = 0;    // アニメーションの開始の時間（リアルタイム）
		private float m_now_animation_time = 0.0f;  // 現在のアニメーション時間
		private float m_end_animation_time = 0.0f;  // アニメーションの終了時間

		private int m_frame_rate = 0;	// アニメーションのフレームレート

		private string m_name = "";	// アニメーションデータ名


		// ☆ プロテクト ☆ //

		// ボーンのアニメーション情報のリスト
		public List<CS_Animation_Bone_Data> mp_bone_list
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

        // アニメーションの開始の時間（リアルタイム）
        public float mp_start_time
		{
			// ゲッタ
			get
			{
				return m_start_time;
			}

			// セッタ
			set
			{
				m_start_time = value;
			}
		}

        // 現在のアニメーション時間
        public float mp_now_animation_time
		{
			// ゲッタ
			get
			{
				return m_now_animation_time;
			}

			// セッタ
			set
			{
				m_now_animation_time = value;
			}
		}

        // アニメーションの終了時間
        public float mp_end_time
		{
			// ゲッタ
			get
			{
				return m_end_animation_time;
			}

			// セッタ
			set
			{
				m_end_animation_time = value;
			}
		}

		// アニメーションのフレームレート
		public int mp_frame_rate
		{
            // ゲッタ
            get
			{
                return m_frame_rate;
            }

            // セッタ
            set
			{
                m_frame_rate = value;
            }
        }

		// アニメーションデータ名
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
		public CS_Animation_System()
		{
			return;
		}


		//-☆- アニメーション -☆-//

		// アニメーションの開始
		private void M_Start_Animation()
		{
			// 現在の時間を更新する
			m_start_time =
				DateTime.Now.Hour * 3600.0f +
				DateTime.Now.Minute * 60.0f +
				DateTime.Now.Second + 
				DateTime.Now.Millisecond / 1000.0f;

			// 現在のアニメーション時間を初期化する
			m_now_animation_time = 0.0f;

			return;
		}


		// アニメーションの更新　引数：ボーンのマトリクスの設定先
		public void M_Update_Animation(ref List<SharpDX.Matrix> out_bone_matrix)
		{
			// 時間を更新する
			m_now_animation_time = m_start_time -
			DateTime.Now.Hour * 3600.0f +
			DateTime.Now.Minute * 60.0f +
			DateTime.Now.Second +
			DateTime.Now.Millisecond / 1000.0f;


			// アニメーションの終了時刻を超えないようにする
			if (m_end_animation_time < m_now_animation_time)
			{
				m_now_animation_time = m_end_animation_time;
			}

			// 全てのボーンのアニメーションを更新する
			foreach (var l_now_bone in m_bone_list)
			{
				// ☆ 変数宣言 ☆ //
				SharpDX.Matrix new_matrix = new SharpDX.Matrix(); // 新しいマトリクス情報


				// アニメーション結果をセットする
				l_now_bone.M_Convert_To_Matrix_By_Time(ref new_matrix, m_now_animation_time);


				// 設定先があるならばセットする
				if(l_now_bone.mp_index < out_bone_matrix.Count)
				{
					out_bone_matrix[l_now_bone.mp_index] = new_matrix;
				}
			}

			return;
		}

		
		// 指定された時間のアニメーションのボーンのマトリクスを取得する　引数：時間, ボーンのマトリクスの設定先
		public void M_Update_Animation_By_Time(ref List<SharpDX.Matrix> out_bone_matrix, float in_time)
        {
            // アニメーションの終了時刻を超えないようにする
            if (m_end_animation_time < in_time)
            {
                in_time = m_end_animation_time;
            }

            // 全てのボーンのアニメーションを更新する
            foreach (var l_now_bone in m_bone_list)
            {
                // ☆ 変数宣言 ☆ //
                SharpDX.Matrix new_matrix = new SharpDX.Matrix(); // 新しいマトリクス情報


                // アニメーション結果をセットする
                l_now_bone.M_Convert_To_Matrix_By_Time(ref new_matrix, in_time);

                // 設定先があるならばセットする
                if (l_now_bone.mp_index < out_bone_matrix.Count)
                {
                    out_bone_matrix[l_now_bone.mp_index] = new_matrix;
                }
            }

			return;
        }
	}
}