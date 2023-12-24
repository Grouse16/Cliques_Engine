using SharpDX;
using SharpDXSample;
using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Assimp;
using System.Runtime.InteropServices;
using Assimp.Unmanaged;
using _3D_Model_Converter_And_Drawer.Animation_Convert;
using _3D_Model_Converter_And_Drawer._3D_Model_Importer;
using _3D_Model_Converter_And_Drawer._3D_Model_Importer.Import_System;
using _3D_Model_Converter_And_Drawer._3DModel.Static;
using _3D_Model_Converter_And_Drawer._3DModel.Animation;
using _3D_Model_Converter_And_Drawer._3DModel.Animation.System;
using System.Diagnostics;
using System.Runtime.Caching;

namespace _3D_Model_Converter_And_Drawer
{
	// ☆ クラス ☆ //

	// メインフォーム
	public partial class Main_Form : Form
	{
		// ☆ 変数宣言 ☆ //
		private BindingList<S_Vertex> m_vertex_list = new BindingList<S_Vertex>(); // 頂点データ

		private C_Shader_Source m_shader;  // シェーダー

		private CS_Static_Model_Data m_static_model = null; // 静的モデルデータ

		private CS_Animation_Model_Data m_animation_model = null; // アニメーションモデルデータ

		private CS_Animation_System m_animation_system = null; // アニメーションシステム

		private Stopwatch m_stop_watch = new Stopwatch();   // タイマーシステム

		private Process m_now_process = Process.GetCurrentProcess();   // 現在のプロセスの状況を取得

		private string m_shader_path = "";   // シェーダーファイルのパス

		private long m_before_working_memory = 0;   // ロード前の物理メモリ
		private long m_before_virtual_memory = 0;   // ロード前の仮想メモリ


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public Main_Form()
		{
			// コンポーネントの初期化
			InitializeComponent();

			// シェーダーロード
			m_shader_path = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "Asset\\shader.fx");
			m_shader = new C_Shader_Source();
			m_shader.PropertyChanged += M_source_PropertyChanged;
			m_shader.mp_shader = File.ReadAllText(m_shader_path, Encoding.UTF8);

			// シェーダーのパスをセット
			uc_dx_11_panel.mp_shader.mp_shader_path = m_shader.mp_shader;
			uc_dx_11_panel.mp_renderer.M_Create_Renderer(Handle);


			// 頂点リストのファイルウォッチャーの設定
			m_vertex_list.ListChanged += (o, e) =>
			  {
				  uc_dx_11_panel.mp_buffer.M_Set_Vertex(m_vertex_list.ToArray());
				  uc_dx_11_panel.Invalidate();
			  };

			// 頂点リストの初期化
			m_vertex_list.Add(new S_Vertex(new Vector4(0.0f, 0.5f, 0.5f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
			m_vertex_list.Add(new S_Vertex(new Vector4(0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 1.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
			m_vertex_list.Add(new S_Vertex(new Vector4(-0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 0.0f, 1.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));

			return;
		}


		// フォーム読み込み時
		private void Form1_Load(object sender, EventArgs e)
		{
			tb_print_model_converter.ReadOnly = true;
			tb_print_model_importer.ReadOnly = true;
			tb_print_model_viewer.ReadOnly = true;
			tb_print_camera_setting.ReadOnly = true;
			tb_print_camera_distance.ReadOnly = true;
			tb_print_camera_position.ReadOnly = true;
			tb_print_animation_blend.ReadOnly = true;
			tb_print_animation_01_times.ReadOnly = true;
			tb_print_animation_02_time.ReadOnly = true;
			tb_print_animation_01_name.ReadOnly = true;
			tb_print_animation_02_name.ReadOnly = true;
			tb_print_animation_blend_percent.ReadOnly = true;

			this.MaximumSize = this.Size;
			this.MinimumSize = this.Size;

			return;
		}


		//-☆- メモリ最適化 -☆-//

		// ガーベージコレクションを実行し、全てのファイナライザの実行を待つ
		private void M_Garbage_Collection_Refresh()
		{
			GC.Collect();
			GC.WaitForPendingFinalizers();

			return;
		}


		//-☆- 計測 -☆-//

		// 時間と使用メモリの計測開始
		private void M_Start_Save_Time_And_Memory_Click()
		{
			// ストップウォッチを初期化
			m_stop_watch = new Stopwatch();


			// ガーベージコレクションを実行
			M_Garbage_Collection_Refresh();


			// 使用しているメモリ容量を物理と仮想の両方取得する
			m_now_process = Process.GetCurrentProcess();
			m_now_process.Refresh();
			m_before_working_memory = m_now_process.WorkingSet64;
			m_before_virtual_memory = m_now_process.VirtualMemorySize64;

			// 時間の計測開始
			m_stop_watch.Start();

			return;
		}


		// 指定された数値を最適なバイト表記に変換して返す
		private string M_Shrink_To_Fit_String(float in_number)
		{
			// ☆ 定数 ☆ //
			const string con_BYTE = "B";		// バイト
			const string con_KILO_BYTE = "KB";	// キロバイト
			const string con_MEGA_BYTE = "MB";	// メガバイト
			const string con_GIGA_BYTE = "GB";  // ギガバイト


			// ☆ 変数宣言 ☆ //
			int byte_shrink_times = 0;	// 表記を縮小した回数

			string result_string = "";  // 変換結果の文字列


			// バイトの表記とバイトサイズを割り出す
			while (in_number >= 1024.0f && byte_shrink_times < 3)
			{
				in_number /= 1024.0f;
				byte_shrink_times += 1;
			}


			// バイト数を結果としてセット
			result_string = in_number.ToString();

			// 表記を縮小した回数によって表記を変える
			switch (byte_shrink_times)
			{
					// バイト表記
				case 0:
					result_string += con_BYTE;
					break;

					// キロバイト表記
				case 1:
					result_string += con_KILO_BYTE;
					break;

					// メガバイト表記
				case 2:
					result_string += con_MEGA_BYTE;
					break;

					// ギガバイト表記
				case 3:
					result_string += con_GIGA_BYTE;
					break;
			}

			// 結果を返す
			return result_string;
		}


		// 時間と使用メモリの計測終了し、assimpのロードにかかった時間と必要なメモリサイズに表示
		private void M_Stop_Save_Time_And_Memory_Click_And_Set_To_Assimp()
		{
			// 時間の計測終了
			m_stop_watch.Stop();


			// 使用しているメモリ容量を物理と仮想の両方取得する
			m_now_process.Refresh();

			// ロード時間と必要なメモリサイズを表示
			uc_load_inform_box.M_Set_Assimp_Load_Inform
				(
					((float)m_stop_watch.ElapsedMilliseconds / 1000.0f),
					M_Shrink_To_Fit_String(m_now_process.WorkingSet64 - m_before_working_memory),
					M_Shrink_To_Fit_String(m_now_process.VirtualMemorySize64 - m_before_virtual_memory)
				);


			// ガーベージコレクションを実行
			M_Garbage_Collection_Refresh();

			return;
		}


		// 時間と使用メモリの計測終了し、独自形式のロードにかかった時間と必要なメモリサイズに表示
		private void M_Stop_Save_Time_And_Memory_Click_Set_To_Original_Format()
		{
			// 時間の計測終了
			m_stop_watch.Stop();


			// 使用しているメモリ容量を物理と仮想の両方取得する
			m_now_process.Refresh();

			// ロード時間と必要なメモリサイズを表示
			uc_load_inform_box.M_Set_My_Model_Load_Inform
				(
					((float)m_stop_watch.ElapsedMilliseconds / 1000.0f),
					M_Shrink_To_Fit_String(m_now_process.WorkingSet64 - m_before_working_memory),
					M_Shrink_To_Fit_String(m_now_process.VirtualMemorySize64 - m_before_virtual_memory)
				);



			// ガーベージコレクションを実行
			M_Garbage_Collection_Refresh();

			return;
		}


		//-☆- リセット -☆-//

		// モデルとアニメーションのデータをリセット
		private void M_Model_And_Animation_Data_Reset()
		{
			// 静的モデルを削除
			if (m_static_model != null)
			{
				m_static_model.mp_mesh_data_list.Clear();
				m_static_model = null; ;
			}

			// アニメーションモデルを削除
			if (m_animation_model != null)
			{
				m_animation_model.mp_mesh_list.Clear();
				m_animation_model = null;
			}

			// すでに持っているアニメーションデータを削除
			if (m_animation_system != null)
			{
				m_animation_system.mp_bone_list.Clear();
				m_animation_system = null;
			}

			return;
		}


		//-☆- 更新 -☆-//

		// ウォッチャー変更時
		private async void Watcher_Changed(object sender, FileSystemEventArgs e)
		{
			// 少し待つ
			await Task.Delay(100);

			// UIスレッドでの実行でないなら、UIスレッドで実行
			if (InvokeRequired)
			{
				// ☆ 変数宣言 ☆ //
				Action call_back = () =>    // コールバック関数
				{
					Watcher_Changed(sender, e);
				};


				// 別スレッドに投げることでUIスレッドで実行
				Invoke(call_back);

				return;
			}

			// シェーダーの再読み込み
			m_shader.mp_shader = File.ReadAllText(m_shader_path, Encoding.UTF8);

			return;
		}


		// シェーダーのプロパティ変更時
		private void M_source_PropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			// UIスレッドでの実行でないなら、UIスレッドで実行
			if (InvokeRequired)
			{
				// ☆ 変数宣言 ☆ //
				Action call_back = () =>    // コールバック関数
				{
					M_source_PropertyChanged(sender, e);
				};


				// 別スレッドに投げることでUIスレッドで実行
				Invoke(call_back);
				return;
			}

			// シェーダーのパスをセット
			uc_dx_11_panel.mp_shader.mp_shader_path = m_shader.mp_shader;
			uc_dx_11_panel.Invalidate();

			return;
		}


		//-☆- ロード -☆-//

		// 静的モデルのロード　引数：ファイルパス
		private void M_Static_Model_Load(string in_file_path)
		{
			// ロード開始時点での時間と使用メモリを記録
			M_Start_Save_Time_And_Memory_Click();


			// 静的モデルのロード
			CS_Static_Model_Import_System.M_Static_Model_Load(in_file_path, out m_static_model);


			// ロード終了、ロードにかかった時間と必要なメモリサイズを表示
			M_Stop_Save_Time_And_Memory_Click_Set_To_Original_Format();
			
			return;
		}


		// アニメーションモデルのロード　引数：ファイルパス
		private void M_Animation_Model_Load(string in_file_path)
		{
			// ロード開始時点での時間と使用メモリを記録
			M_Start_Save_Time_And_Memory_Click();


			// アニメーションモデルのロード
			CS_Animation_Model_Import_System.M_Import_Animation_Model(in_file_path, out m_animation_model);


			// ロード終了、ロードにかかった時間と必要なメモリサイズを表示
			M_Stop_Save_Time_And_Memory_Click_Set_To_Original_Format();

			return;
		}


		// アニメーションデータのロード　引数：ファイルパス
		private void M_Animation_Data_Load(string in_file_path)
		{
			// ロード開始時点での時間と使用メモリを記録
			M_Start_Save_Time_And_Memory_Click();


			// アニメーションデータのロード
			CS_Animation_Data_Import_System.M_Load_Animation_Data(in_file_path, out m_animation_system, m_animation_model);


			// ロード終了、ロードにかかった時間と必要なメモリサイズを表示
			M_Stop_Save_Time_And_Memory_Click_Set_To_Original_Format();

			return;
		}


		//-☆- イベント -☆-//

		// ドラッグがカーソル上にあるとき
		private void B_Drag_Over_File_Checker(object sender, DragEventArgs e)
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


		// 変換する3Dモデルのファイルのドロップを受け取る
		private void B_Model_Converter_DragDrop(object sender, DragEventArgs e)
		{
			// ファイルドロップ時はファイルのプロパティを取得（なければスルー）、まだ変換するフォームが破棄されていないならスルー
			if (e.Data.GetDataPresent(DataFormats.FileDrop) == false || Form_3D_Model_Convert_Setting.mp_is_active)
			{
				return;
			}


			// ロード開始時点での時間と使用メモリを記録
			M_Start_Save_Time_And_Memory_Click();


			// ☆ 変数宣言 ☆ //
			string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイル名（絶対パス）

			string relative_file_path = CS_My_Math_System.M_Get_Relative_Path(file_path[0]);   // 相対パス

			AssimpContext importer = new AssimpContext(); // インポートシステム

			Scene scene =     // 取得結果のデータ
				importer.ImportFile
				(
					relative_file_path,
					PostProcessSteps.CalculateTangentSpace |	// 接空間を計算
					PostProcessSteps.GenerateSmoothNormals |	// スムーズな法線を生成
					PostProcessSteps.JoinIdenticalVertices |	// 同一頂点を結合
					PostProcessSteps.LimitBoneWeights |			// ボーンウェイトを制限
					PostProcessSteps.RemoveRedundantMaterials |	// 冗長なマテリアルを削除
					PostProcessSteps.SplitLargeMeshes |			// 大きいメッシュを分割
					PostProcessSteps.GenerateUVCoords |			// UV座標を生成
					PostProcessSteps.SortByPrimitiveType |		// プリミティブタイプでソート
					PostProcessSteps.FindDegenerates |			// 縮退面を見つける
					PostProcessSteps.FindInvalidData |			// 無効なデータを見つける
					PostProcessSteps.Triangulate |				// 全ての面を三角形に変換
					PostProcessSteps.FlipWindingOrder |			// 時計回り
					PostProcessSteps.MakeLeftHanded				// 左手系
				);


            // ロード終了、ロードにかかった時間と必要なメモリサイズを表示
            M_Stop_Save_Time_And_Memory_Click_And_Set_To_Assimp();


			// コンバートするデータをセットし、各種設定用のフォームを生成
			CS_3D_Model_Convert_System.M_Create_Form_Of_Convert_Model(scene);

            return;
		}


		// 独自形式モデルの変換にファイルのドロップがあった時
		private void B_Model_Importer_DragDrop(object sender, DragEventArgs e)
		{
			// ☆ 定数 ☆ //
			const string con_IS_ELSSTMDL_TEXT = "This-Is-ELSTTMDL";     // 静的モデル、elsttmdlであることを確認するための文字列
			const string con_IS_ELANMMDL_TEXT = "This-Is-ELANMMDL";     // 動的モデル、elanmmdlであることを確認するための文字列
			const string con_IS_ELANMDT_TEXT = "This-Is-ELANMDT";       // アニメーションデータ、elanmdtであることを確認するための文字列


			// ファイルドロップ時はファイルのプロパティを取得（なければスルー）
			if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
			{
				return;
			}


			// ☆ 変数宣言 ☆ //
			string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイルまでの絶対パス

			string relative_file_path = CS_My_Math_System.M_Get_Relative_Path(file_path[0]);   // ファイルまでの相対パス
			
			StreamReader file_data = new StreamReader(relative_file_path); // ファイルデータ

			string data_name = file_data.ReadLine(); // ファイルの一行分のデータ


			// ファイルを閉じる
			file_data.Close();


			// 静的モデルである時のロード
			if (data_name == con_IS_ELSSTMDL_TEXT)
			{
				// モデルとアニメーションのデータをリセット
				M_Model_And_Animation_Data_Reset();

				// 静的モデルのロード
				M_Static_Model_Load(relative_file_path);

				return;
			}


			// アニメーションモデルである時のロード
			if (data_name == con_IS_ELANMMDL_TEXT)
			{
				// モデルとアニメーションのデータをリセット
				M_Model_And_Animation_Data_Reset();

				// アニメーションモデルのロード
				M_Animation_Model_Load(relative_file_path);

				return;
			}


			// アニメーションデータである時のロード
			if (data_name == con_IS_ELANMDT_TEXT)
			{
				// アニメーションモデルがないならボーン情報がなく、ロードできないので終了
				if (m_animation_model == null)
				{
					return;
				}

				// アニメーションデータのロード
				M_Animation_Data_Load(relative_file_path);

				return;
			}

			return;
		}

		private void tb_print_animation_blend_percent_TextChanged(object sender, EventArgs e)
		{

		}

		private void trackBar5_Scroll(object sender, EventArgs e)
		{

		}

		private void trackBar4_Scroll(object sender, EventArgs e)
		{

		}

		private void tb_print_animation_02_name_TextChanged(object sender, EventArgs e)
		{

		}

		private void tb_print_animation_02_time_TextChanged(object sender, EventArgs e)
		{

		}

		private void tb_print_animation_01_name_TextChanged(object sender, EventArgs e)
		{

		}

		private void trackBar3_Scroll(object sender, EventArgs e)
		{

		}

		private void b_model_importer_Click(object sender, EventArgs e)
		{

		}
	}


	// シェーダー設定用のクラス
	class C_Shader_Source : INotifyPropertyChanged
	{
		// ☆ 変数宣言 ☆ //
		string m_shader_path;   // シェーダーファイルのパス


		// ☆ プロパティ ☆ //

		// シェーダーファイルのパス
		public string mp_shader
		{
			// ゲッタ
			get
			{
				return m_shader_path;
			}

			// セッタ
			set
			{
				if (m_shader_path == value)
				{
					return;
				}

				m_shader_path = value;
				RaisePropertyChanged(nameof(mp_shader));

				return;
			}
		}


		// ☆ イベント ☆ //
		public event PropertyChangedEventHandler PropertyChanged;   // プロパティ変更時


		// プロパティ変更時
		void RaisePropertyChanged(string prop)
		{
			// ☆ 変数宣言 ☆ //
			var handler = PropertyChanged;  // プロパティ変更イベントのハンドル


			// プロパティ変更イベントが取得できたならプロパティ変更イベントを実行
			if (handler != null)
			{
				handler(this, new PropertyChangedEventArgs(prop));
			}
		}
	}


	// ロード情報表示用のクラス
	static class CS_Color_Extensions
	{
		// SharpDXのカラーをfloat4のカラーに変換
		public static System.Drawing.Color M_SharpDX_Color_To_Float4_Color(this Color4 src)
		{
			return System.Drawing.Color.FromArgb(
				(byte)(src.Alpha * 255),
				(byte)(src.Red * 255),
				(byte)(src.Green * 255),
				(byte)(src.Blue * 255)
				);
		}

		// float4のカラーをSharpDXのカラーに変換
		public static Color4 M_Float4_Color_To_SharpDX_Color(this System.Drawing.Color value)
		{
			return new Color4(
				value.R / 255.0f,
				value.G / 255.0f,
				value.B / 255.0f,
				value.A / 255.0f
				);
		}
	}
}
