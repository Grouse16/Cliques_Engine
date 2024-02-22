using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ELMaterial_Generator.Blend_Setting_UI;
using CS_MY_MATH;

namespace ELMaterial_Generator.Load_System
{
	// ☆ 構造体 ☆ //

	// マテリアル設定のデータの構造体
	public struct S_Load_Material_Inform
	{
		// ☆ 変数宣言 ☆ //
		private string material_name;   // マテリアル名
		private string shader_name;     // シェーダー名

		private int blend_sum;	// ブレンド設定数

		private List<E_WRITE_SETTING> write_setting_list;   // 書き込み設定リスト

		private E_DEPTH_MODE depth_mode;   // 深度モード

		private E_DRAW_MODE draw_mode;     // 表示モード

		private E_CULL_MODE cull_mode;     // カリングモード

		private E_ANTI_ALIASING_MODE anti_aliasing_mode;   // アンチエイリアシングモード

		private int sampling_level;   // サンプリングレベル

		private S_RGBA_Data ambient_data;		// アンビエントデータ
		private S_RGBA_Data diffuse_data;		// ディフューズデータ
		private S_RGBA_Data emission_data;		// エミッションデータ
		private S_RGBA_Data reflection_data;    // リフレクションデータ
		private S_RGBA_Data specular_data;		// スペキュラデータ
		private S_RGBA_Data transparent_data;	// トランスペアレントデータ


		// ☆ プロパティ ☆ //

		// マテリアル名
		public string mp_material_name
		{
			// ゲッタ
			get
			{
				return material_name;
			}

			// セッタ
			set
			{
				material_name = value;
			}
		}

		// シェーダー名
		public string mp_shader_name
		{
			// ゲッタ
			get
			{
				return shader_name;
			}

			// セッタ
			set
			{
				shader_name = value;
			}
		}

		// ブレンド設定数
		public int mp_blend_sum
		{
			// ゲッタ
			get
			{
				return blend_sum;
			}

			// セッタ
			set
			{
				blend_sum = value;
			}
		}

		// 書き込み設定リスト
		public List<E_WRITE_SETTING> mp_write_setting_list
		{
			// ゲッタ
			get
			{
				return write_setting_list;
			}

			// セッタ
			set
			{
				write_setting_list = value;
			}
		}

		// 深度モード
		public E_DEPTH_MODE mp_depth_mode
		{
			// ゲッタ
			get
			{
				return depth_mode;
			}

			// セッタ
			set
			{
				depth_mode = value;
			}
		}

		// 描画モード
		public E_DRAW_MODE mp_draw_mode
		{
			// ゲッタ
			get
			{
				return draw_mode;
			}
			
			// セッタ
			set
			{
				draw_mode = value;
			}
		}

		// カリングモード
		public E_CULL_MODE mp_cull_mode
		{
			// ゲッタ
			get
			{
				return cull_mode;
			}

			// セッタ
			set
			{
				cull_mode = value;
			}
		}

		// アンチエイリアシングモード
		public E_ANTI_ALIASING_MODE mp_anti_aliasing_mode
		{
			// ゲッタ
			get
			{
				return anti_aliasing_mode;
			}

			// セッタ
			set
			{
				anti_aliasing_mode = value;
			}
		}

		// サンプリングレベル
		public int mp_sampling_level
		{
			// ゲッタ
			get
			{
				return sampling_level;
			}

			// セッタ
			set
			{
				sampling_level = value;
			}
		}

		// アンビエントデータ
		public S_RGBA_Data mp_ambient_data
		{
			// ゲッタ
			get
			{
				return ambient_data;
			}

			// セッタ
			set
			{
				ambient_data = value;
			}
		}

		// ディフューズデータ
		public S_RGBA_Data mp_diffuse_data
		{
			// ゲッタ
			get
			{
				return diffuse_data;
			}

			// セッタ
			set
			{
				diffuse_data = value;
			}
		}

		// エミッションデータ
		public S_RGBA_Data mp_emission_data
		{
			// ゲッタ
			get
			{
				return emission_data;
			}

			// セッタ
			set
			{
				emission_data = value;
			}
		}

		// リフレクションデータ
		public S_RGBA_Data mp_reflection_data
		{
			// ゲッタ
			get
			{
				return reflection_data;
			}

			// セッタ
			set
			{
				reflection_data = value;
			}
		}

		// スペキュラデータ
		public S_RGBA_Data mp_specular_data
		{
			// ゲッタ
			get
			{
				return specular_data;
			}

			// セッタ
			set
			{
				specular_data = value;
			}
		}

		// トランスペアレントデータ
		public S_RGBA_Data mp_transparent_data
		{
			// ゲッタ
			get
			{
				return transparent_data;
			}

			// セッタ
			set
			{
				transparent_data = value;
			}
		}
	}


	// ☆ クラス ☆ //

	// マテリアル情報の読み込み
	public class CS_Load_Material_Inform_System
	{
		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// マテリアル設定をロードする　引数：ファイルパス（相対）　戻り値：マテリアル情報
		static public S_Load_Material_Inform M_Load_Material_Inform(string in_file_path)
		{
			// ☆ 変数宣言 ☆ //
			List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

			S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0); // 現在のファイル操作中の場所

			S_Load_Material_Inform result_material = new S_Load_Material_Inform();   // 結果のマテリアル情報


			// ファイルのデータを読み取る
			{
				// ☆　変数宣言 ☆ //
				StreamReader file_data = new StreamReader(in_file_path); // 指定されたファイルのデータ

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
				result_material.mp_material_name = Path.GetFileName(in_file_path);
			}


			// シェーダー名へ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "SHADERSETTINGNAME:", new S_Now_File_Data_Position(0, 0));
			now_position.M_Goto_Next_Data(read_data_list);

			// シェーダー名をセット
			result_material.mp_shader_name = read_data_list[now_position.mp_now_line];


			// ブレンド設定数へ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "BLENDSUM:", now_position);

			// ブレンド設定数をセット
			result_material.mp_blend_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


			// 書き込み設定リストをセット
			{
				// ☆ 変数宣言 ☆ //
				List<E_WRITE_SETTING> new_write_setting_list = new List<E_WRITE_SETTING>();   // 新しい書き込み設定リスト
				

				// 書き込み設定リストへ移動
				for (int l_now_blend_number = 0; l_now_blend_number < result_material.mp_blend_sum; l_now_blend_number++)
				{
					// ☆ 変数宣言 ☆ //
					string write_setting = "";   // 書き込み設定


					// 現在のブレンド番号へ移動
					now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "BLEND" + (l_now_blend_number + 1).ToString(), now_position);


					// 書き込み設定へ移動
					now_position.M_Goto_Next_Data(read_data_list);
					now_position.M_Goto_Next_Data(read_data_list);

					// 書き込み設定をセット
					write_setting = read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column);


					// 書き込み設定を判定して設定
					switch (write_setting)
					{
						// 加法混色
						case "ADD":
							new_write_setting_list.Add(E_WRITE_SETTING.e_ADD);
							break;

						// 減法混色
						case "SUB":
							new_write_setting_list.Add(E_WRITE_SETTING.e_SUB);
							break;

						// その他
						default:
							new_write_setting_list.Add(E_WRITE_SETTING.e_ADD);
							break;
					}
				}

				// 書き込み設定リストをセット
				result_material.mp_write_setting_list = new_write_setting_list;
			}


			// 深度モードへ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "DEPTH:", now_position);
			now_position.M_Goto_Next_Data(read_data_list);

			// 深度モードを判定してセット
			switch (read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column))
			{
				// 奥行きあり
				case "ONE":
					result_material.mp_depth_mode = E_DEPTH_MODE.e_TRUE;
					break;

				// 奥行きなし
				case "NO":
					result_material.mp_depth_mode = E_DEPTH_MODE.e_FALSE;
					break;

				// その他
				default:
					result_material.mp_depth_mode = E_DEPTH_MODE.e_TRUE;
					break;
			}


			// 描画モードへ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "RASTERIZER:", now_position);
			now_position.M_Goto_Next_Data(read_data_list);

			// 描画モードを判定してセット
			switch (read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column))
			{
				// 通常
				case "NORMAL":
					result_material.mp_draw_mode = E_DRAW_MODE.e_NORMAL;
					break;

				// ワイヤーフレーム
				case "WIRE_FRAME":
					result_material.mp_draw_mode = E_DRAW_MODE.e_WIREFRAME;
					break;

				// その他
				default:
					result_material.mp_draw_mode = E_DRAW_MODE.e_NORMAL;
					break;
			}


			// カリングモードへ移動
			now_position.M_Goto_Next_Data(read_data_list);

			// カリングモードを判定してセット
			switch (read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column))
			{
				// 全面
				case "ALWAYS":
					result_material.mp_cull_mode = E_CULL_MODE.e_CULL_ALWAYS;
					break;

				// 前面
				case "FRONT":
					result_material.mp_cull_mode = E_CULL_MODE.e_CULL_FRONT;
					break;

				// 裏面
				case "BACK":
					result_material.mp_cull_mode = E_CULL_MODE.e_CULL_BACK;
					break;

				// その他
				default:
					result_material.mp_cull_mode = E_CULL_MODE.e_CULL_ALWAYS;
					break;
			}


			// アンチエイリアシングモードへ移動
			now_position.M_Goto_Next_Data(read_data_list);
			now_position.M_Goto_Next_Data(read_data_list);
			now_position.M_Goto_Next_Data(read_data_list);
			now_position.M_Goto_Next_Data(read_data_list);
			now_position.M_Goto_Next_Data(read_data_list);

			// アンチエイリアシングモードを判定してセット
			switch (read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column))
			{
				// α補間
				case "ALPHA":
					result_material.mp_anti_aliasing_mode = E_ANTI_ALIASING_MODE.e_ALPHA;
					break;

				// 色補間
				case "PIXEL":
					result_material.mp_anti_aliasing_mode = E_ANTI_ALIASING_MODE.e_COLOR;
					break;

				// 線形補間
				case "LINE":
					result_material.mp_anti_aliasing_mode = E_ANTI_ALIASING_MODE.e_LINE;
					break;

				// その他
				default:
					result_material.mp_anti_aliasing_mode = E_ANTI_ALIASING_MODE.e_ALPHA;
					break;
			}


			// サンプリングレベルへ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "SAMPLING:", now_position);
			now_position.M_Goto_Next_Data(read_data_list);

			// サンプリングレベルをセット
			result_material.mp_sampling_level = int.Parse(read_data_list[now_position.mp_now_line]);


			// 質感情報へ移動
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "MATERIAL:", now_position);
			now_position.M_Goto_Next_Data(read_data_list);

			// 質感情報をセット
			result_material.mp_ambient_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);
			now_position.M_Goto_Next_Data(read_data_list);

			result_material.mp_diffuse_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);
			now_position.M_Goto_Next_Data(read_data_list);

			result_material.mp_emission_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);
			now_position.M_Goto_Next_Data(read_data_list);

			result_material.mp_reflection_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);
			now_position.M_Goto_Next_Data(read_data_list);

			result_material.mp_specular_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);
			now_position.M_Goto_Next_Data(read_data_list);

			result_material.mp_transparent_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line]);

			return result_material;
		}


		// 質感情報をロードしてセットする　引数：ファイルパス（相対）　戻り値：マテリアル情報
		static public S_Mesh_Material_Data M_Load_Material_Inform_And_Set(string in_file_path, ref S_Load_Material_Inform out_material)
		{
			// ☆ 変数宣言 ☆ //
			List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

			S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0);	// 現在のファイル操作中の場所

			S_Mesh_Material_Data result_mesh_material = new S_Mesh_Material_Data();	// 結果のマテリアル情報


			// ファイルのデータを読み取る
			{
				// ☆　変数宣言 ☆ //
				StreamReader file_data = new StreamReader(in_file_path); // 指定されたファイルのデータ

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
			}


            // アンビエントをロード
            now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "AMBIENT:", now_position);
			result_mesh_material.mp_ambient_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// ディフューズをロード
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "DIFFUSE:", now_position);
			result_mesh_material.mp_diffuse_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// エミッションをロード
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "EMISSION:", now_position);
			result_mesh_material.mp_emission_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// リフレクションをロード
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "REFLECTION:", now_position);
			result_mesh_material.mp_reflection_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// スペキュラをロード
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "SPECULAR:", now_position);
			result_mesh_material.mp_specular_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

			// トランスペアレントをロード
			now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "TRANSPARENT:", now_position);
			result_mesh_material.mp_transparent_data = M_Convert_String_To_RGBA(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));

            return result_mesh_material;
		}



		// 文字列をRGBAデータに変換する　引数：RGBAを示す文字列　戻り値：RGBAデータ
		static public S_RGBA_Data M_Convert_String_To_RGBA(string in_rgba_string)
		{
			// ☆ 変数宣言 ☆ //
			S_RGBA_Data result_rgba = new S_RGBA_Data();   // 結果のRGBAデータ

			int now_word_position = 0;   // 現在の文字位置


			// RGBAデータをセット
			result_rgba.mp_red = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_word_position, in_rgba_string, ','));
			now_word_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_rgba_string, ",", now_word_position);

			result_rgba.mp_green = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_word_position, in_rgba_string, ','));
			now_word_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_rgba_string, ",", now_word_position);

			result_rgba.mp_blue = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_word_position, in_rgba_string, ','));
			now_word_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_rgba_string, ",", now_word_position);

			result_rgba.mp_alpha = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_word_position, in_rgba_string, ','));
			now_word_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_rgba_string, ",", now_word_position);


			return result_rgba;
		}

	}
}
