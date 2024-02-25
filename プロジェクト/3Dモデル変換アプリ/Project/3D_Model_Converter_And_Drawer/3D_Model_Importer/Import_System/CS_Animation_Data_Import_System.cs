using _3D_Model_Converter_And_Drawer._3DModel.Animation;
using _3D_Model_Converter_And_Drawer._3DModel.Animation.Key;
using _3D_Model_Converter_And_Drawer._3DModel.Animation.System;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer.Import_System
{
	// ☆ クラス ☆ //

	// アニメーションデータのインポートシステムのクラス
	public class CS_Animation_Data_Import_System
	{
		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// アニメーションデータをロードする　引数：ロードするファイルのパス, 設定先のアニメーション情報, 対応したアニメーションモデルのデータ
		static public void M_Load_Animation_Data(string in_load_file_path, out CS_Animation_System out_animation_system, in CS_Animation_Model_Data in_animation_model_data)
		{
			// ☆ 変数宣言 ☆ //
			List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

			S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0); // 現在のファイル操作中の場所
			
			int bone_sum = 0;   // ボーンの数


			// 設定先アニメーションデータを初期化
			out_animation_system = new CS_Animation_System();


			// ファイルのデータを読み取る
			{
				// ☆　変数宣言 ☆ //
				StreamReader file_data = new StreamReader(in_load_file_path); // 指定されたファイルのデータ

				bool is_file_end = false;   // ファイルの終わりに来たかどうか


				// ファイルの終わりに来るまで読み取る
				while (is_file_end == false)
				{
					// ☆ 変数宣言 ☆ //
					string new_line = file_data.ReadLine();  // 新しい行のデータ


					// もうデータがないなら終了
					if (new_line == null)
					{
						is_file_end = true;
					}

					// データがあるなら読み取ったデータのリストに追加
					else
					{
						read_data_list.Add(new_line);
					}
				}

				// ファイルを閉じる
				file_data.Close();


				// ファイル名をセット
				out_animation_system.mp_name = Path.GetFileNameWithoutExtension(in_load_file_path);
			}


			// アニメーションデータの開始位置に移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "ANIMATION:", now_position);

			// フレームレートを取得
			now_position.M_Goto_Next_Line(read_data_list);
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "FRAMERATE:", now_position);
			out_animation_system.mp_frame_rate = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// アニメーションの終了時間を取得
			now_position.M_Goto_Next_Line(read_data_list);
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "ENDTIME:", now_position);
			out_animation_system.mp_end_time = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// ボーンの数を取得
			now_position.M_Goto_Next_Line(read_data_list);
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "BONESUM:", now_position);
			bone_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


			// ボーンの数だけボーンのアニメーション情報を追加
			for (int l_now_bone_number = 0; l_now_bone_number < bone_sum; l_now_bone_number++)
			{
				out_animation_system.mp_bone_list.Add(new _3DModel.Animation.Bone.CS_Animation_Bone_Data());
			}


			// ボーンのアニメーション情報をロード
			foreach (var l_now_bone in out_animation_system.mp_bone_list)
			{
				// ☆ 変数宣言 ☆ //
				int position_key_frame_sum = 0; // 位置座標のキーフレームの数
				int rotation_key_frame_sum = 0; // 回転のキーフレームの数
				int scale_key_frame_sum = 0;    // スケールのキーフレームの数


				// ボーンの開始位置へ移動
				now_position.M_Goto_Next_Line(read_data_list);
				now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "BONE:", now_position);

				// ボーン名を取得
				l_now_bone.mp_name = read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column);


				// ボーンのインデックス番号を取得
				l_now_bone.mp_index = -1;
				for (int l_now_bone_number = 0; l_now_bone_number < in_animation_model_data.mp_bone_data_list.Count; l_now_bone_number++)
				{
					if (l_now_bone.mp_name == in_animation_model_data.mp_bone_data_list[l_now_bone_number].mp_name)
					{
						l_now_bone.mp_index = l_now_bone_number;

						break;
					}
				}

				// ボーンのインデックス番号が取得できなかったらこのボーンはないのでスルー
				if (l_now_bone.mp_index < 0)
				{
					continue;
				}


				// 位置座標のキーフレームの数を取得
				now_position.M_Goto_Next_Line(read_data_list);
				now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "POS:", now_position);

				// 位置座標のキーフレーム分の配列を生成
				for (int l_now_key_frame_number = 0; l_now_key_frame_number < position_key_frame_sum; l_now_key_frame_number++)
				{
                    l_now_bone.mp_key_frame.mp_position.Add(new CS_Position_Key());
                }

				// 位置座標のキーフレームをロード
				foreach (var l_now_position_key_frame in l_now_bone.mp_key_frame.mp_position)
				{
					// ☆ 変数宣言 ☆ //
					float x_position = 0.0f;    // X座標
					float y_position = 0.0f;    // Y座標
					float z_position = 0.0f;    // Z座標


					// 現在の位置座標のキーフレームの開始位置へ移動
					now_position.M_Goto_Next_Line(read_data_list);


					// 時間を取得
                    l_now_position_key_frame.mp_time = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

                    // 位置座標を取得
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    x_position = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
					y_position = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    z_position = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


					// 位置座標をセット
					l_now_position_key_frame.mp_data = new d3d11.CS_Position(x_position, y_position, z_position);
                }


				// 回転のキーフレームの数を取得
				now_position.M_Goto_Next_Line(read_data_list);
				now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "ROT:", now_position);

				// 回転のキーフレーム分の配列を生成
				for (int l_now_key_frame_number = 0; l_now_key_frame_number < rotation_key_frame_sum; l_now_key_frame_number++)
				{
                    l_now_bone.mp_key_frame.mp_rotation.Add(new CS_Rotation_Key());
                }

				// 回転のキーフレームをロード
				foreach (var l_now_rotation_key_frame in l_now_bone.mp_key_frame.mp_rotation)
				{
                    // ☆ 変数宣言 ☆ //
                    float x_rotation = 0.0f;    // X軸回転角度
                    float y_rotation = 0.0f;    // Y軸回転角度
                    float z_rotation = 0.0f;    // Z軸回転角度
					float w_rotation = 0.0f;    // W軸回転角度


					// 現在の回転のキーフレームの開始位置へ移動
					now_position.M_Goto_Next_Line(read_data_list);


					// 時間を取得
                    l_now_rotation_key_frame.mp_time = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

                    // 回転角度を取得
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    x_rotation = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    y_rotation = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    z_rotation = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
					now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
					w_rotation = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


					// 回転角度をセット
					l_now_rotation_key_frame.mp_data = new d3d11.CS_Rotation(x_rotation, y_rotation, z_rotation, w_rotation);
				}


				// スケールのキーフレームの数を取得
				now_position.M_Goto_Next_Line(read_data_list);
				now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "SCL:", now_position);

				// スケールのキーフレーム分の配列を生成
				for (int l_now_key_frame_number = 0; l_now_key_frame_number < scale_key_frame_sum; l_now_key_frame_number++)
				{
                    l_now_bone.mp_key_frame.mp_scale.Add(new CS_Scale_Key());
                }

				// スケールのキーフレームをロード
				foreach (var l_now_scale_key_frame in l_now_bone.mp_key_frame.mp_scale)
				{
                    // ☆ 変数宣言 ☆ //
                    float x_scale = 0.0f;    // X軸スケール
                    float y_scale = 0.0f;    // Y軸スケール
                    float z_scale = 0.0f;    // Z軸スケール


					// 現在のスケールのキーフレームの開始位置へ移動
					now_position.M_Goto_Next_Line(read_data_list);

					// 時間を取得
                    l_now_scale_key_frame.mp_time = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

                    // スケールを取得
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    x_scale = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    y_scale = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                    z_scale = float.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


					// スケールをセット
					l_now_scale_key_frame.mp_data = new d3d11.CS_Scale(x_scale, y_scale, z_scale);
				}
			}

			return;
		}
	}
}
