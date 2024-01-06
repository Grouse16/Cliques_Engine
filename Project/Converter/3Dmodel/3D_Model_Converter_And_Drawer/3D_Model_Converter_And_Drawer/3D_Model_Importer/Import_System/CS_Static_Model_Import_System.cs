using _3D_Model_Converter_And_Drawer._3DModel.Animation;
using _3D_Model_Converter_And_Drawer._3DModel.Static;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer.Import_System
{
	// ☆ クラス ☆ //

	// 静的モデルをインポートするシステムのクラス
	public class CS_Static_Model_Import_System
	{
		// ☆ 関数 ☆ //

		//-☆- インポート -☆-//

		// 静的モデルのロード　引数：ロードするデータのパス, 設定先モデルデータ
		static public void M_Static_Model_Load(string in_load_file_path, out CS_Static_Model_Data in_static_model)
		{
			// ☆ 変数宣言 ☆ //
			List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

			S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0); // 現在のファイル操作中の場所


			// 設定先モデルデータを初期化
			in_static_model = new CS_Static_Model_Data();


			// ファイルのデータを読み取る
			CS_File_Write_Load_System.M_Read_Data_From_File(in_load_file_path, out read_data_list);

			// ファイル名をセット
			in_static_model.mp_name = Path.GetFileNameWithoutExtension(in_load_file_path);


			// 頂点データをロード
			M_Load_Vertex_Data(read_data_list, ref now_position, ref in_static_model);

			// メッシュデータをロード
			M_Load_Mesh_Data(read_data_list, ref now_position, ref in_static_model);

			return;
		}


		//-☆- ロード -☆-//

		// 頂点データをロード　引数：読み取るデータのリスト, 読み取る場所, 設定先モデルデータ
		static private void M_Load_Vertex_Data(List<string> in_read_data_list, ref S_Now_File_Data_Position in_now_position, ref CS_Static_Model_Data in_static_model)
		{
			// ☆ 変数宣言 ☆ //
			int vertex_sum = 0; // 頂点数


			// 頂点数を取得
			in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_read_data_list, "VERTSUM:", in_now_position);
			vertex_sum = int.Parse(in_read_data_list[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


			// 頂点数分メモリを確保
			for (int l_now_vertex = 0; l_now_vertex < vertex_sum; l_now_vertex++)
			{
				in_static_model.mp_vertex_data_list.Add(new _3DModel.S_Static_Vertex_Data());
			}

			// 頂点分だけデータをロード
			for (int l_now_vertex_number = 0; l_now_vertex_number < in_static_model.mp_vertex_data_list.Count; l_now_vertex_number++)
			{
				// ☆ 変数宣言 ☆ //
				_3DModel.S_Static_Vertex_Data new_vertex_data = new _3DModel.S_Static_Vertex_Data();    // 新しい頂点データ


				// 現在の頂点へ移動
				in_now_position.M_Goto_Next_Line(in_read_data_list);


				// 位置座標をロード
				{
					// ☆ 変数宣言 ☆ //
					float position_x = 0.0f;    // X座標
					float position_y = 0.0f;    // Y座標
					float position_z = 0.0f;    // Z座標


					// データをロード
					position_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					position_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					position_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// 位置座標をセット
					new_vertex_data.mp_position = new SharpDX.Vector3(position_x, position_y, position_z);
				}

				// UVへ移動
				{
					// ☆ 変数宣言 ☆ //
					float set_u = 0.0f; // U座標
					float set_v = 0.0f; // V座標


					// データをロード
					set_u = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					set_v = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// UV座標をセット
					new_vertex_data.mp_uv = new SharpDX.Vector2(set_u, set_v);
				}

				// 色へ移動
				{
					// ☆ 変数宣言 ☆ //
					float set_r = 0.0f; // R
					float set_g = 0.0f; // G
					float set_b = 0.0f; // B
					float set_a = 0.0f; // A


					// データをロード
					set_r = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					set_g = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					set_b = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					set_a = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// 色をセット
					new_vertex_data.mp_color = new SharpDX.Vector4(set_a, set_g, set_b, set_a);
				}

				// 法線ベクトルへ移動
				{
					// ☆ 変数宣言 ☆ //
					float normal_x = 0.0f;  // 法線ベクトルX
					float normal_y = 0.0f;  // 法線ベクトルY
					float normal_z = 0.0f;  // 法線ベクトルZ


					// データをロード
					normal_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					normal_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					normal_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// 法線ベクトルをセット
					new_vertex_data.mp_normal = new SharpDX.Vector3(normal_x, normal_y, normal_z);
				}


				// タンジェントベクトルへ移動
				{
					// ☆ 変数宣言 ☆ //
					float tangent_x = 0.0f; // タンジェントX
					float tangent_y = 0.0f; // タンジェントY
					float tangent_z = 0.0f; // タンジェントZ


					// データをロード
					tangent_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					tangent_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					tangent_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// タンジェントベクトルをセット
					new_vertex_data.mp_tangent = new SharpDX.Vector3(tangent_x, tangent_y, tangent_z);
				}

				// 従法線ベクトルへ移動
				{
					// ☆ 変数宣言 ☆ //
					float bi_normal_tangent_x = 0.0f;   // 従法線X
					float bi_normal_tangent_y = 0.0f;   // 従法線Y
					float bi_normal_tangent_z = 0.0f;   // 従法線Z


					// データをロード
					bi_normal_tangent_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					bi_normal_tangent_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ',');
					bi_normal_tangent_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_read_data_list, ref in_now_position, ':');

					// 従法線ベクトルをセット
					new_vertex_data.mp_bi_normal_tangent = new SharpDX.Vector3(bi_normal_tangent_x, bi_normal_tangent_y, bi_normal_tangent_z);
				}

				// 新しい頂点データをセット
				in_static_model.mp_vertex_data_list[l_now_vertex_number] = new_vertex_data;
			}

			return;
		}


		// メッシュデータをロード　引数：読み取るデータのリスト, 読み取る場所, 設定先モデルデータ
		static private void M_Load_Mesh_Data(List<string> in_read_data_list, ref S_Now_File_Data_Position in_now_position, ref CS_Static_Model_Data in_static_model)
		{
			// ☆ 変数宣言 ☆ //
			int mesh_sum = 0;   // メッシュ数


			// メッシュ数を取得
			in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_read_data_list, "MESHSUM:", in_now_position);
			mesh_sum = int.Parse(in_read_data_list[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


			// メッシュ数分メモリを確保
			for (int l_now_mesh = 0; l_now_mesh < mesh_sum; l_now_mesh++)
			{
				in_static_model.mp_mesh_data_list.Add(new _3DModel.CS_Static_Mesh_Data());
			}


			// メッシュ分だけデータをロード
			in_now_position.M_Goto_Next_Line(in_read_data_list);
			foreach (var l_now_mesh_data in in_static_model.mp_mesh_data_list)
			{
				// ☆ 変数宣言 ☆ //
				int index_sum = 0;  // インデックス数


				// メッシュの開始位置へ移動
				in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_read_data_list, "MESH:", in_now_position);


				// メッシュ名がある場所に移動し、メッシュ名を取得
				in_now_position.M_Goto_Next_Line(in_read_data_list);
				l_now_mesh_data.mp_name = in_read_data_list[in_now_position.mp_now_line];


				// マテリアル名がある場所に移動し、マテリアル名を取得
				in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_read_data_list, "MATERIAL:", in_now_position);
				in_now_position.M_Goto_Next_Line(in_read_data_list);
				l_now_mesh_data.mp_name = in_read_data_list[in_now_position.mp_now_line];


				// インデックス数を取得
				in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_read_data_list, "INDEX:", in_now_position);
				index_sum = int.Parse(in_read_data_list[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


				// インデックス数分だけロード
				in_now_position.M_Goto_Next_Line(in_read_data_list);
				for (int l_now_index = 0; l_now_index < index_sum; l_now_index++)
				{
					l_now_mesh_data.mp_index_list.Add(uint.Parse(in_read_data_list[in_now_position.mp_now_line]));
					in_now_position.M_Goto_Next_Line(in_read_data_list);
				}
			}

			return;
		}
	}
}

