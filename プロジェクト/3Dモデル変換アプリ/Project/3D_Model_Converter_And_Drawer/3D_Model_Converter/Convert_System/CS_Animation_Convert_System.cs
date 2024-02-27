using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Assimp;
using Assimp.Unmanaged;


namespace _3D_Model_Converter_And_Drawer.Animation_Convert
{
	// ☆ クラス ☆ //

	// アニメーション変換システム
	internal class CS_Animation_Convert_System
	{
		// ☆ 関数 ☆ //

		//-☆- 変換 -☆-//

		// アニメーションデータの変換をする
		static public void M_Convert_Animation_Data(Scene in_scene)
		{
			// ☆ 定数 ☆ //
			const string con_EXTENSION = ".elanmdt";   // 拡張子


			// ☆ 変数宣言 ☆ //
			string selected_folder_path = "";   // 選択されたフォルダのパス

			int now_animation_data_num = 0;   // 現在のアニメーションデータ番号


			// フォルダ選択ダイアログを表示して、選択されたフォルダのパスを取得、取得できなかったら終了
			if (CS_File_Write_Load_System.M_Get_Folder_Path(out selected_folder_path) == false)
			{
				return;
			}


			// アニメーション数分変換を行う
			foreach (var now_animation in in_scene.Animations)
			{
				// ☆ 変数宣言 ☆ //
				List<string> write_data_to_file = new List<string>();  // ファイルに書き込むデータ

				string write_file_path = selected_folder_path + Form_3D_Model_Convert_Setting.mp_animation_data_name_list[now_animation_data_num] + con_EXTENSION;  // 書き込むファイルのパス

				double one_frame_time = 1.0 / now_animation.TicksPerSecond;    // １フレームの時間


				// 今までに書き込まれたデータを初期化
				write_data_to_file.Clear();

				// アニメーションのファイルであることを示す文字列を記録
				write_data_to_file.Add("This-Is-ELANMDT");


				// アニメーションの開始位置を書き込む
				write_data_to_file.Add("ANIMATION:");

				// アニメーションの１秒間でのフレームレートを書き込む
				write_data_to_file.Add("FRAMERATE:" + now_animation.TicksPerSecond.ToString());

				// アニメーションの終了までの時間を書き込む
				write_data_to_file.Add("ENDTIME:" + now_animation.DurationInTicks);


				// 位置座標のキーフレームを書き込む
				M_Write_Position_Animation_Data(now_animation, ref write_data_to_file);
				
				// 回転のキーフレームを書き込む
				M_Write_Rotation_Animation_Data(now_animation, ref write_data_to_file);

				// 拡大縮小のキーフレームを書き込む
				M_Write_Scale_Animation_Data(now_animation, ref write_data_to_file);


				// ボーンの情報を書き込む
				M_Write_Bone_Data(now_animation, ref write_data_to_file);

				
				// 新しいファイルの書き込みを行う
				File.WriteAllText(write_file_path, write_data_to_file[0]);
				for (int now_write_raw = 1; now_write_raw < write_data_to_file.Count; now_write_raw++)
				{
					File.AppendAllText(write_file_path, Environment.NewLine + write_data_to_file[now_write_raw]);
				}

				// 次のアニメーションデータを指定
				now_animation_data_num += 1;
			}

			return;
		}


		// 位置座標のアニメーションデータを書き込む　引数：アニメーションデータ、書き込むデータの参照
		static private void M_Write_Position_Animation_Data(Animation in_animation, ref List<string> in_write_data)
		{
			// ☆ 変数宣言 ☆ //
			int position_animation_key_sum = 0;   // 位置座標のキーの合計数


			// 位置座標のキーの合計数を計算
			for (int l_now_bone_number = 0; l_now_bone_number < in_animation.NodeAnimationChannels.Count; l_now_bone_number++)
			{
				position_animation_key_sum += in_animation.NodeAnimationChannels[l_now_bone_number].PositionKeyCount;
			}
			
			// 座標のキー情報の開始位置と座標キー数を書き込む
			in_write_data.Add("POS:" + position_animation_key_sum.ToString());


			// 位置座標のアニメーションデータを書き込む
			foreach (NodeAnimationChannel l_now_animation_data in in_animation.NodeAnimationChannels)
			{
				// 座標のキーを全て書き込む
				foreach (VectorKey l_now_position_key in l_now_animation_data.PositionKeys)
				{
					// このキーになる時間と座標情報を書き込む
					in_write_data.Add
					(
						l_now_position_key.Time.ToString() + ","
						+ l_now_position_key.Value.X.ToString() + ","
						+ l_now_position_key.Value.Y.ToString() + ","
						+ l_now_position_key.Value.Z.ToString() + ","
					);
				}
			}

			return;
		}


		// 回転のアニメーションデータを書き込む　引数：アニメーションデータ、書き込むデータの参照
		static private void M_Write_Rotation_Animation_Data(Animation in_animation, ref List<string> in_write_data)
		{
            // ☆ 変数宣言 ☆ //
            int rotation_animation_key_sum = 0;   // 回転のキーの合計数


			// 回転のキーの合計数を計算
			for (int l_now_bone_number = 0; l_now_bone_number < in_animation.NodeAnimationChannels.Count; l_now_bone_number++)
			{
                rotation_animation_key_sum += in_animation.NodeAnimationChannels[l_now_bone_number].RotationKeyCount;
            }

			// 回転のキー情報の開始位置とキー数を書き込む
			in_write_data.Add("ROT:" + rotation_animation_key_sum.ToString());


			// 回転のアニメーションデータを書き込む
			foreach (NodeAnimationChannel l_now_animation_data in in_animation.NodeAnimationChannels)
			{
                // 回転のキーを全て書き込む
                foreach (QuaternionKey l_now_rotation_key in l_now_animation_data.RotationKeys)
				{
                    // このキーになる時間と回転情報を書き込む
                    in_write_data.Add
                    (
						l_now_rotation_key.Time.ToString() + ","
						+ l_now_rotation_key.Value.X.ToString() + ","
						+ l_now_rotation_key.Value.Y.ToString() + ","
						+ l_now_rotation_key.Value.Z.ToString() + ","
						+ l_now_rotation_key.Value.W.ToString() + ","
					);
                }
            }

			return;
		}


		// 拡大縮小のアニメーションデータを書き込む　引数：アニメーションデータ、書き込むデータの参照
		static private void M_Write_Scale_Animation_Data(Animation in_animation, ref List<string> in_write_data)
		{
            // ☆ 変数宣言 ☆ //
            int scale_animation_key_sum = 0;   // 拡大縮小のキーの合計数


			// 拡大縮小のキーの合計数を計算
			for (int l_now_bone_number = 0; l_now_bone_number < in_animation.NodeAnimationChannels.Count; l_now_bone_number++)
			{
                scale_animation_key_sum += in_animation.NodeAnimationChannels[l_now_bone_number].ScalingKeyCount;
            }

			// 拡大縮小のキー情報の開始位置とキー数を書き込む
			in_write_data.Add("SCL:" + scale_animation_key_sum.ToString());


			// 拡大縮小のアニメーションデータを書き込む
			foreach (NodeAnimationChannel l_now_animation_data in in_animation.NodeAnimationChannels)
			{
                // 拡大縮小のキーを全て書き込む
                foreach (VectorKey l_now_scale_key in l_now_animation_data.ScalingKeys)
				{
                    // このキーになる時間と拡大縮小情報を書き込む
                    in_write_data.Add
                    (
						l_now_scale_key.Time.ToString() + ","
						+ l_now_scale_key.Value.X.ToString() + ","
						+ l_now_scale_key.Value.Y.ToString() + ","
						+ l_now_scale_key.Value.Z.ToString() + ","
					);
                }
            }

			return;
		}


        // アニメーションのボーンのデータを書き込む　引数：アニメーションデータ、書き込むデータの参照
        static private void M_Write_Bone_Data(Animation in_animation, ref List<string> in_write_data)
		{
			// ☆ 変数宣言 ☆ //
			int now_position_key_start = 0;	// 位置座標のキーの現在の開始番号
			int now_rotation_key_start = 0;	// 回転情報のキーの現在の開始番号
			int now_scale_key_start = 0;	// 拡大縮小のキーの現在の開始番号


			// ボーン数を書き込む
			in_write_data.Add("BONESUM:" + in_animation.NodeAnimationChannels.Count.ToString());


			// ボーンの情報を書き込む
			foreach (NodeAnimationChannel l_now_bone in in_animation.NodeAnimationChannels)
			{
				// ボーン名を書き込む
                in_write_data.Add("BONE:" + l_now_bone.NodeName);


				// 位置座標のキーの開始番号と終了番号を書き込む
				in_write_data.Add(now_position_key_start.ToString() + "," + (l_now_bone.PositionKeys.Count + now_position_key_start - 1).ToString());

				// 回転のキーの開始番号と終了番号を書き込む
				in_write_data.Add(now_rotation_key_start.ToString() + "," + (l_now_bone.RotationKeys.Count + now_rotation_key_start - 1).ToString());

				// 拡大縮小のキーの開始番号と終了番号を書き込む
				in_write_data.Add(now_scale_key_start.ToString() + "," + (l_now_bone.ScalingKeys.Count + now_scale_key_start - 1).ToString());


				// 位置座標のキーの開始番号を更新
				now_position_key_start += l_now_bone.PositionKeys.Count;

				// 回転のキーの開始番号を更新
				now_rotation_key_start += l_now_bone.RotationKeys.Count;

				// 拡大縮小のキーの開始番号を更新
				now_scale_key_start += l_now_bone.ScalingKeys.Count;
			}

			return;
		}

    }
}

















































//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

