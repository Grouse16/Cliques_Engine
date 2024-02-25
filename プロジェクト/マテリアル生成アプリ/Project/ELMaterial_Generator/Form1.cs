using ELMaterial_Generator.Load_System;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator
{
	// ☆ 列挙 ☆ //

	// 深度モードの列挙
	public enum E_DEPTH_MODE
	{
		e_TRUE,     // 奥行きあり
		e_FALSE,    // 奥行きなし
	}


	// 表示モードの列挙
	public enum E_DRAW_MODE
	{
		e_NORMAL,		// 通常
		e_WIREFRAME,	// ワイヤーフレーム
	}


	// 面の表示設定の列挙
	public enum E_CULL_MODE
	{
		e_CULL_FRONT,	// 表面表示
		e_CULL_BACK,	// 裏面表示
		e_CULL_ALWAYS,	// 両面表示
	}


	// アンチエイリアシング設定の列挙
	public enum E_ANTI_ALIASING_MODE
	{
		e_ALPHA,	// アルファ
		e_COLOR,	// カラー
		e_LINE,		// ライン
	}


	// ☆ クラス ☆ //

	public partial class Form1 : Form
	{
		// ☆ 定数 ☆ //
		const string con_MAT_DEFAULT_NAME = "Default";       // マテリアルの初期名
		const string con_SHADER_DEFAULT_NAME = "Default";    // シェーダーの初期名


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public Form1()
		{
			InitializeComponent();
		}


		// ロード時の初期化処理
		private void Form1_Load(object sender, EventArgs e)
		{
			// マテリアルの各枠名をセット
			UC_ambient_data.M_Set_Tag_Name("アンビエント（基本の明るさ）");
			UC_diffuse_data.M_Set_Tag_Name("ディフューズ（色の減衰）");
			UC_emission_data.M_Set_Tag_Name("エミッション（輝き）");
			UC_reflection_data.M_Set_Tag_Name("リフレクション（反射）");
			UC_specular_data.M_Set_Tag_Name("スペキュラー（鏡面反射）");
			UC_transparent_data.M_Set_Tag_Name("トランスペアレント（透明度）");

			// 輝きの最大値をセット
			UC_emission_data.M_Change_Maximum_Track_Value(10.0f);

			// 情報の初期化
			M_Reset();

			return;
		}


		// 情報を全てリセットする
		public void M_Reset()
		{
			// サイズの初期化
			MaximumSize = Size;
			MinimumSize = Size;

			// マテリアルとシェーダーの名前を初期化
			TB_material_name.Text = con_MAT_DEFAULT_NAME;
			TB_Shader_Setting_Name.Text = con_SHADER_DEFAULT_NAME;

			// ブレンド設定の初期化
			UC_blend_setting_frame.M_Reset();

			// 深度ステンシル設定の初期化
			CB_depth_mode.SelectedIndex = (int)E_DEPTH_MODE.e_TRUE;

			// ラスタライザ設定の初期化
			CB_rasterize_draw_mode.SelectedIndex = (int)E_DRAW_MODE.e_NORMAL;
			CB_rasterizer_mesh_setting.SelectedIndex = (int)E_CULL_MODE.e_CULL_FRONT;
			CB_rasterizer_anti_aliasing.SelectedIndex = (int)E_ANTI_ALIASING_MODE.e_ALPHA;

			// サンプリング設定の初期化
			NB_sampling_level.Value = 1;

			// 質感設定の初期化
			UC_ambient_data.M_Set_RGBA_Data(new S_RGBA_Data(0.0f, 0.0f, 0.0f, 1.0f));
			UC_diffuse_data.M_Reset();
			UC_emission_data.M_Reset();
			UC_reflection_data.M_Reset();
			UC_specular_data.M_Reset();
			UC_transparent_data.M_Set_RGBA_Data(new S_RGBA_Data(1.0f, 1.0f, 1.0f, 1.0f));

			return;
		}


		//-☆- 変換 -☆-//

		// 深度モードへの設定を文字列に変換　引数：奥行きフラグ　戻り値：深度モードの文字列
		private string M_Convert_Depth_Mode_To_String(E_DEPTH_MODE in_depth_mode)
		{
			switch (in_depth_mode)
			{
				// 奥行きあり
				case E_DEPTH_MODE.e_TRUE:
					return "ONE";

				// 奥行きなし
				case E_DEPTH_MODE.e_FALSE:
					return "NO";

				// その他
				default:
					return "ONE";
			}
		}


		// 深度オプションへの設定を文字列に変換　引数：奥行きフラグ　戻り値：深度オプションの文字列
		private string M_Convert_Depth_Option_To_String(E_DEPTH_MODE in_depth_mode)
		{
			switch (in_depth_mode)
			{
				// 奥行きあり
				case E_DEPTH_MODE.e_TRUE:
					return "LESS";

				// 奥行きなし
				case E_DEPTH_MODE.e_FALSE:
					return "DONT";

				// その他
				default:
					return "ONE";
			}
		}


		// ステンシルへの設定を文字列に変換　引数：ステンシルフラグ　戻り値：ステンシルの文字列
		private string M_Convert_Stencil_To_String(E_DEPTH_MODE in_depth_mode)
		{
			switch (in_depth_mode)
			{
				// 奥行きあり
				case E_DEPTH_MODE.e_TRUE:
					return "ACTIVE";

				// 奥行きなし
				case E_DEPTH_MODE.e_FALSE:
					return "NO_ACTIVE";

				// その他
				default:
					return "ACTIVE";
			}
		}


		// 表示モードへの設定を文字列に変換　引数：表示モード　戻り値：表示モードの文字列
		private string M_Convert_Draw_Mode_To_String(E_DRAW_MODE in_draw_mode)
		{
			switch (in_draw_mode)
			{
				// 通常
				case E_DRAW_MODE.e_NORMAL:
					return "NORMAL";

				// ワイヤーフレーム
				case E_DRAW_MODE.e_WIREFRAME:
					return "WIRE_FRAME";

				// その他
				default:
					return "NORMAL";
			}
		}


		// 面の表示設定への設定を文字列に変換　引数：面の表示設定　戻り値：面の表示設定の文字列
		private string M_Convert_Cull_Mode_To_String(E_CULL_MODE in_cull_mode)
		{
			switch (in_cull_mode)
			{
				// 表面表示
				case E_CULL_MODE.e_CULL_FRONT:
					return "FRONT";

				// 裏面表示
				case E_CULL_MODE.e_CULL_BACK:
					return "BACK";

				// 両面表示
				case E_CULL_MODE.e_CULL_ALWAYS:
					return "ALWAYS";

				// その他
				default:
					return "ALWAYS";
			}
		}


		// アンチエイリアシングへの設定を文字列に変換　引数：アンチエイリアシング設定　戻り値：アンチエイリアシング設定の文字列
		private string M_Convert_Anti_Aliasing_To_String(E_ANTI_ALIASING_MODE in_anti_aliasing_mode)
		{
			switch (in_anti_aliasing_mode)
			{
				// アルファ
				case E_ANTI_ALIASING_MODE.e_ALPHA:
					return "ALPHA";

				// カラー
				case E_ANTI_ALIASING_MODE.e_COLOR:
					return "PIXEL";

				// ライン
				case E_ANTI_ALIASING_MODE.e_LINE:
					return "LINE";

				// その他
				default:
					return "ALPHA";
			}
		}


		//-☆- イベント -☆-//

		// リセットボタンが押されたらリセット
		private void B_Reset_MouseUp(object sender, MouseEventArgs e)
		{
			M_Reset();

			return;
		}


		// 生成ボタンを押されたら生成する
		private void B_Generate_MouseUp(object sender, MouseEventArgs e)
		{
			// ☆ 変数宣言 ☆ //
			List<string> write_text = new List<string>();   // 書き込むデータ

			S_RGBA_Data color_data = new S_RGBA_Data();    // 色のデータ


			// マテリアルファイルであることを示す
			write_text.Add("This-Is-ELMAT");

			// シェーダー設定名を書き込む
			write_text.Add("SHADERSETTINGNAME:");
			write_text.Add(TB_Shader_Setting_Name.Text);


			//  ブレンドモード  //

			// ブレンドモードの設定数を書き込む
			write_text.Add("BLENDSUM:" + UC_blend_setting_frame.mp_blend_setting_list.Count);

			// ブレンドの情報の設定を書き込む
			for (int l_blend_num = 0; l_blend_num < UC_blend_setting_frame.mp_blend_setting_list.Count; l_blend_num++)
			{
				// ブレンドの情報の開始位置を書き込む
				write_text.Add("BLEND" + (l_blend_num + 1).ToString() + ":");

				// ブレンドモードを書き込む
				write_text.Add("NORMAL");

				// 混ぜ方を書き込む
				write_text.Add(UC_blend_setting_frame.mp_blend_setting_list[l_blend_num].M_Get_Write_Setting_In_Text());

				// フォーマット
				write_text.Add("FLOAT4");

				// カラー
				write_text.Add("RGBA");
			}


			//  深度モード  //

			// 深度の開始位置を書き込む
			write_text.Add("DEPTH:");

			// 深度モードを書き込む
			write_text.Add(M_Convert_Depth_Mode_To_String((E_DEPTH_MODE)CB_depth_mode.SelectedIndex));

			// 深度オプションを書き込む
			write_text.Add(M_Convert_Depth_Option_To_String((E_DEPTH_MODE)CB_depth_mode.SelectedIndex));

			// ステンシルを書き込む
			write_text.Add(M_Convert_Stencil_To_String((E_DEPTH_MODE)CB_depth_mode.SelectedIndex));


			//  ラスタライザ  //

			// ラスタライザの開始位置を書き込む
			write_text.Add("RASTERIZER:");

			// 表示モードを書き込む
			write_text.Add(M_Convert_Draw_Mode_To_String((E_DRAW_MODE)CB_rasterize_draw_mode.SelectedIndex));

			// 面のカリング設定
			write_text.Add(M_Convert_Cull_Mode_To_String((E_CULL_MODE)CB_rasterizer_mesh_setting.SelectedIndex));

			// 表面の設定
			write_text.Add("CLOCK_WISE");

			// 奥行き値を書き込む
			write_text.Add("0");

			// 奥行きの最大値を書き込む
			write_text.Add("0");

			// 奥行きの傾き値を書き込む
			write_text.Add("0");

			// アンチエイリアシング設定を書き込む
			write_text.Add(M_Convert_Anti_Aliasing_To_String((E_ANTI_ALIASING_MODE)CB_rasterizer_anti_aliasing.SelectedIndex));

			// 保守的なラスタライズの設定を書き込む
			write_text.Add("true");


			//  サンプリング  //

			// サンプリングの開始位置を書き込む
			write_text.Add("SAMPLING:");

			// サンプリング回数を書き込む
			write_text.Add(((int)NB_sampling_level.Value).ToString());

			// サンプリング品質を書き込む
			write_text.Add(((int)NB_sampling_level.Value).ToString());


			//  質感  //

			// 質感の開始位置を書き込む
			write_text.Add("MATERIAL:");

			// アンビエント値を書き込む
			color_data = UC_ambient_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");

			// ディフューズ値を書き込む
			color_data = UC_diffuse_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");

			// エミッション値を書き込む
			color_data = UC_emission_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");
			
			// リフレクション値を書き込む
			color_data = UC_reflection_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");
			
			// スペキュラー値を書き込む
			color_data = UC_specular_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");

			// トランスペアレント値を書き込む
			color_data = UC_transparent_data.M_Get_RGBA_Data();
			write_text.Add(color_data.mp_red.ToString() + "," + color_data.mp_green.ToString() + "," + color_data.mp_blue.ToString() + "," + color_data.mp_alpha.ToString() + ",");


			// ☆ 変数宣言 ☆ //
			SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

			string extension = "elmat";   // 拡張子


			sfd.FileName = TB_material_name.Text + "." + extension;
			sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
			sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")|*." + ";*." + extension + "|すべてのファイル(*.*)|*.*";
			sfd.FilterIndex = 1;
			sfd.Title = "マテリアルの質感情報の保存先とファイル名を決めてください";
			// ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
			sfd.RestoreDirectory = true;
			// 既に存在するファイル名を指定したとき警告する
			sfd.OverwritePrompt = true;
			// 存在しないパスが指定されたとき警告を表示する
			sfd.CheckPathExists = true;

			// ダイアログを表示する
			if (sfd.ShowDialog() == DialogResult.OK)
			{
				System.IO.File.WriteAllText(sfd.FileName, write_text[0] + Environment.NewLine);

				for (int now_write_raw = 1; now_write_raw < write_text.Count; now_write_raw++)
				{
					System.IO.File.AppendAllText(sfd.FileName, write_text[now_write_raw] + Environment.NewLine);
				}
			}
		}


		// 指定された文字列から終了マーク（：）を探してその番号を返す
		private int M_Search_End_Mark(string in_string)
		{
			int end_mark_is_this = 0;   // 終了マークの番号

			for (end_mark_is_this = 0; end_mark_is_this < in_string.Length; end_mark_is_this++)
			{
				if (in_string[end_mark_is_this] == '：')
				{
					return end_mark_is_this;
				}
			}

			return 0;
		}


		//-☆- ロード -☆-//

		// 渡された絶対パスを、自ファイルからの相対パスに変換する
		static public string M_Get_Relative_Path(string in_path)
		{
			// ☆ 変数宣言 ☆ //
			Uri uri_base_path = new Uri(System.Reflection.Assembly.GetExecutingAssembly().Location);    // 基本となる相対元のパス
			Uri uri_relative_check_path = new Uri(in_path);                                             // 相対パスに変換したいシステムのパス
			Uri uri_relative_path = uri_base_path.MakeRelativeUri(uri_relative_check_path);             // 絶対Uriから相対Uriを取得する

			return uri_relative_path.ToString();   // 相対パス
		}

		
		// 独自形式マテリアルの情報をロードしデータをセットする　引数：相対パス
		private void M_Load_Data_By_ELMaterial(string in_relative_file_path)
		{
			// ☆ 変数宣言 ☆ //
			S_Load_Material_Inform material_inform = new S_Load_Material_Inform();  // ロードしたマテリアル情報


			// マテリアル情報のロード
			material_inform = CS_Load_Material_Inform_System.M_Load_Material_Inform(in_relative_file_path);


			// マテリアル名をセット
			TB_material_name.Text = material_inform.mp_material_name;

			// シェーダー名をセット
			TB_Shader_Setting_Name.Text = material_inform.mp_shader_name;

			// ブレンド設定数をセット
			UC_blend_setting_frame.M_Change_Blend_Setting_Sum(material_inform.mp_blend_sum);

			// ブレンド設定の情報をセット
			for (int now_blend_setting = 0; now_blend_setting < material_inform.mp_blend_sum; now_blend_setting++)
			{
				UC_blend_setting_frame.mp_blend_setting_list[now_blend_setting].M_Set_Write_Setting(material_inform.mp_write_setting_list[now_blend_setting]);
			}

			// 深度モードをセット
			CB_depth_mode.SelectedIndex = (int)material_inform.mp_depth_mode;

			// ラスタライザの表示モードをセット
			CB_rasterize_draw_mode.SelectedIndex = (int)material_inform.mp_draw_mode;

			// ラスタライザの面の表示設定をセット
			CB_rasterizer_mesh_setting.SelectedIndex = (int)material_inform.mp_cull_mode;

			// ラスタライザのアンチエイリアシング設定をセット
			CB_rasterizer_anti_aliasing.SelectedIndex = (int)material_inform.mp_anti_aliasing_mode;

			// サンプリングの設定をセット
			NB_sampling_level.Value = material_inform.mp_sampling_level;

			// 質感の設定をセット
			UC_ambient_data.M_Set_RGBA_Data(material_inform.mp_ambient_data);
			UC_diffuse_data.M_Set_RGBA_Data(material_inform.mp_diffuse_data);
			UC_emission_data.M_Set_RGBA_Data(material_inform.mp_emission_data);
			UC_reflection_data.M_Set_RGBA_Data(material_inform.mp_reflection_data);
			UC_specular_data.M_Set_RGBA_Data(material_inform.mp_specular_data);
			UC_transparent_data.M_Set_RGBA_Data(material_inform.mp_transparent_data);

			return;
		}


		// マテリアル質感情報ファイルの情報をロードしデータをセットする　引数：相対パス
		private void M_Load_Data_By_ELMaterialInform(string in_relative_file_path)
		{
			// ☆ 変数宣言 ☆ //
			S_Mesh_Material_Data mesh_material = new S_Mesh_Material_Data();	// マテリアル質感情報


			// マテリアル質感情報のロード
			mesh_material = CS_Load_Material_Inform_System.M_Load_Mesh_Material_Inform(in_relative_file_path);


            // マテリアル名をセット
            TB_material_name.Text = Path.GetFileName(in_relative_file_path);
            TB_material_name.Text = Path.ChangeExtension(TB_material_name.Text, null);


            // マテリアル質感情報をセット
            UC_ambient_data.M_Set_RGBA_Data(mesh_material.mp_ambient_data);
			UC_diffuse_data.M_Set_RGBA_Data(mesh_material.mp_diffuse_data);
			UC_emission_data.M_Set_RGBA_Data(mesh_material.mp_emission_data);
			UC_reflection_data.M_Set_RGBA_Data(mesh_material.mp_reflection_data);
			UC_specular_data.M_Set_RGBA_Data(mesh_material.mp_specular_data);
			UC_transparent_data.M_Set_RGBA_Data(mesh_material.mp_transparent_data);

            return;
		}


		//-☆- イベント -☆-//

		// ドラッグ中のカーソルがボタンの上にあるとき
		private void B_export_block_DragOver(object sender, DragEventArgs e)
		{
			// ファイルドロップ時はカーソルをコピーに変更
			if (e.Data.GetDataPresent(DataFormats.FileDrop))
			{
				e.Effect = DragDropEffects.Copy;
			}

			// それ以外の時はなにもしない
			else
			{
				e.Effect = DragDropEffects.None;
			}

			return;
		}


		// ドラッグ＆ドロップされたとき
		private void B_export_block_DragDrop(object sender, DragEventArgs e)
		{
			// ファイルドロップ時はファイルのプロパティを取得（なければスルー）
			if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
			{
				return;
			}


			// ☆ 変数宣言 ☆ //
			string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイル名（絶対パス）

			string relative_file_path = M_Get_Relative_Path(file_path[0]);   // 相対パス

			StreamReader file_data = new StreamReader(relative_file_path); // ファイルデータ

			string file_data_a_line = file_data.ReadLine(); // ファイルの一行分のデータ


			// マテリアルのファイルの場合のロード
			if (file_data_a_line == "This-Is-ELMAT")
			{
				M_Load_Data_By_ELMaterial(relative_file_path);

				return;
			}


			// マテリアル質感情報ファイルの場合のロード
			if (file_data_a_line == "This-Is-ELMATINFORM")
			{
				M_Load_Data_By_ELMaterialInform(relative_file_path);

				return;
			}

			return;
		}
	}
}
