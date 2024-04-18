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
using _3D_Model_Converter_And_Drawer._3DModel;
using _3D_Model_Converter_And_Drawer.d3d11.Transform;
using _3D_Model_Converter_And_Drawer.Rendering_Systems.Camera;
using _3D_Model_Converter_And_Drawer.d3d11;
using _3D_Model_Converter_And_Drawer.Support_System;
using SharpDX.Direct3D11;
using SharpDX.D3DCompiler;

namespace _3D_Model_Converter_And_Drawer
{
	// ☆ クラス ☆ //

	// メインフォーム
	public partial class Main_Form : Form
	{
		// ☆ 定数 ☆ //
		const int con_WVP_CONSTANT_BUFFER_SLOT_NUMBER = 0;			// WVP行列の定数バッファのスロット番号
		const int con_BONE_MATRIX_CONSTANT_BUFFER_SLOT_NUMBER = 1;	// ボーンマトリクスの定数バッファのスロット番号
		const int con_MAIN_TEXTURE_SLOT_NUMBER = 0;					// メインテクスチャのスロット番号


		// ☆ 変数宣言 ☆ //
		private CS_Static_Model_Data m_static_model = null; // 静的モデルデータ

		private CS_Animation_Model_Data m_animation_model = null; // アニメーションモデルデータ

		private Stopwatch m_stop_watch = new Stopwatch();   // タイマーシステム

		private Process m_now_process = Process.GetCurrentProcess();   // 現在のプロセスの状況を取得

		private CS_Transform m_model_transform = new CS_Transform();	// モデルのトランスフォーム

		private CS_DX_11_Constant_Buffer<Constant_Data.S_WVP> m_wvp_constant_buffer = new CS_DX_11_Constant_Buffer<Constant_Data.S_WVP>();	// WVP行列の定数バッファ

		private CS_DX_11_Constant_Buffer<Matrix> m_bone_matrix_constant_buffer = new CS_DX_11_Constant_Buffer<Matrix>();	// ボーンマトリクスの定数バッファ

		private C_Shader_Source m_triangle_shader = new C_Shader_Source();			// 三角形用のシェーダー設定用のシステム
		private C_Shader_Source m_static_model_shader = new C_Shader_Source();		// 静的モデル用のシェーダー設定用のシステム
		private C_Shader_Source m_animation_model_shader = new C_Shader_Source();	// アニメーションモデル用のシェーダー設定用のシステム

		private List<CS_Animation_System> m_animation_system_list = new List<CS_Animation_System>();	// アニメーションシステムのリスト

		private CS_DX_11_Draw_Call_System m_draw_setting = new CS_DX_11_Draw_Call_System();	// 描画設定用のシステム

		private long m_before_working_memory = 0;   // ロード前の物理メモリ
		private long m_before_virtual_memory = 0;   // ロード前の仮想メモリ

		private int m_animation_by_index = 0; // ブレンド元のアニメーションのインデックス番号
		private int m_animation_to_index = 0; // ブレンド先のアニメーションのインデックス番号

		private float m_animation_by_time = 0.0f;		// ブレンド元のアニメーションの時間
		private float m_animation_to_time = 0.0f;		// ブレンド先のアニメーションの時間
		private float m_animation_blend_percent = 0.0f; // アニメーションブレンドの割合
		private float m_camera_distance = 10.0f;		// カメラの距離
		private float m_camera_angle = 0.0f;			// カメラの角度


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public Main_Form()
		{
			// コンポーネントの初期化
			InitializeComponent();


			// 使用するシェーダーのロード
			M_Load_Shader_By_Path(out m_triangle_shader, "Asset\\Triangle_Shader.fx");
			M_Load_Shader_By_Path(out m_static_model_shader, "Asset\\Static_3D_Model_Shader.fx");
			M_Load_Shader_By_Path(out m_animation_model_shader, "Asset\\Animation_Model_Shader.fx");


			// レンダラの初期化
			uc_dx_11_panel.mp_renderer.M_Create_Renderer(Handle);


			// 三角形を描画
			M_Draw_Triangle();


            // プロジェクションを設定
            CS_Camera_Manager.mp_camera_system.mp_projection.mp_aspect_ratio = (float)uc_dx_11_panel.Width / (float)uc_dx_11_panel.Height;
			CS_Camera_Manager.mp_camera_system.mp_projection.mp_field_of_view = 60.0f;
			CS_Camera_Manager.mp_camera_system.mp_projection.mp_near_distance = 0.1f;
			CS_Camera_Manager.mp_camera_system.mp_projection.mp_far_distance = 1000.0f;


			// WVPマトリクス用の定数バッファを生成
			m_wvp_constant_buffer.M_Create_Constant_Buffer(uc_dx_11_panel.mp_renderer.mp_device, 1);

			return;
		}


		// 三角形用のシェーダーのセット
		private void M_Set_Triangle_Shader()
		{
			// 三角形のシェーダーのパスをセット
			uc_dx_11_panel.mp_shader.mp_shader_path = m_triangle_shader.mp_shader_path;


			// 頂点レイアウトを初期化
			if (uc_dx_11_panel.mp_shader.mp_layout != null)
			{
                uc_dx_11_panel.mp_shader.mp_layout.Dispose();
                uc_dx_11_panel.mp_shader.mp_layout = null;
            }


			// 三角形の頂点レイアウトの生成
            uc_dx_11_panel.mp_shader.mp_layout = new InputLayout
			(
				uc_dx_11_panel.mp_renderer.mp_device,
				ShaderSignature.GetInputSignature(uc_dx_11_panel.mp_shader.mp_compiled_vertex_shader_code),
				new[]
				{
					new InputElement("POSITION", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 0, 0),
					new InputElement("COLOR", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 16, 0)
				}
			);
			
			return;
		}


		// 静的モデル用のシェーダーのセット
		private void M_Set_Static_Model_Shader()
		{
			// 静的モデルのシェーダーのパスをセット
			uc_dx_11_panel.mp_shader.mp_shader_path = m_static_model_shader.mp_shader_path;


            // 頂点レイアウトを初期化
            if (uc_dx_11_panel.mp_shader.mp_layout != null)
            {
                uc_dx_11_panel.mp_shader.mp_layout.Dispose();
                uc_dx_11_panel.mp_shader.mp_layout = null;
            }


            // 静的モデルの頂点レイアウトの生成
            uc_dx_11_panel.mp_shader.mp_layout = new InputLayout
			(
				uc_dx_11_panel.mp_renderer.mp_device,
				ShaderSignature.GetInputSignature(uc_dx_11_panel.mp_shader.mp_compiled_vertex_shader_code),
				new[]
				{
				   new InputElement("POSITION", 0, SharpDX.DXGI.Format.R32G32B32_Float, 0, 0),
				   new InputElement("TEXCOORD", 0, SharpDX.DXGI.Format.R32G32_Float, 12, 0),
				   new InputElement("COLOR", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 20, 0),
				   new InputElement("NORMAL", 0, SharpDX.DXGI.Format.R32G32B32_Float, 36, 0),
				   new InputElement("TANGENT", 0, SharpDX.DXGI.Format.R32G32B32_Float, 48, 0),
				   new InputElement("BINORMAL", 0, SharpDX.DXGI.Format.R32G32B32_Float, 60, 0)
				}
			);

			return;
		}


		// アニメーションモデル用のシェーダーのセット
		private void M_Set_Animation_Model_Shader()
		{
			// アニメーションモデルのシェーダーのパスをセット
			uc_dx_11_panel.mp_shader.mp_shader_path = m_animation_model_shader.mp_shader_path;


            // 頂点レイアウトを初期化
            if (uc_dx_11_panel.mp_shader.mp_layout != null)
            {
                uc_dx_11_panel.mp_shader.mp_layout.Dispose();
                uc_dx_11_panel.mp_shader.mp_layout = null;
            }


            // アニメーションモデルの頂点レイアウトの生成
            uc_dx_11_panel.mp_shader.mp_layout = new InputLayout
			(
				uc_dx_11_panel.mp_renderer.mp_device,
				ShaderSignature.GetInputSignature(uc_dx_11_panel.mp_shader.mp_compiled_vertex_shader_code),
				new[]
				{
				   new InputElement("POSITION", 0, SharpDX.DXGI.Format.R32G32B32_Float, 0, 0),
				   new InputElement("TEXCOORD", 0, SharpDX.DXGI.Format.R32G32_Float, 12, 0),
				   new InputElement("COLOR", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 20, 0),
				   new InputElement("NORMAL", 0, SharpDX.DXGI.Format.R32G32B32_Float, 36, 0),
				   new InputElement("TANGENT", 0, SharpDX.DXGI.Format.R32G32B32_Float, 48, 0),
				   new InputElement("BINORMAL", 0, SharpDX.DXGI.Format.R32G32B32_Float, 60, 0),
				   new InputElement("WEIGHT", 0, SharpDX.DXGI.Format.R32_Float, 72, 0),
				   new InputElement("INDEX", 0, SharpDX.DXGI.Format.R32_UInt, 76, 0),
				   new InputElement("WEIGHT", 1, SharpDX.DXGI.Format.R32_Float, 80, 0),
				   new InputElement("INDEX", 1, SharpDX.DXGI.Format.R32_UInt, 84, 0),
				   new InputElement("WEIGHT", 2, SharpDX.DXGI.Format.R32_Float, 88, 0),
				   new InputElement("INDEX", 2, SharpDX.DXGI.Format.R32_UInt, 92, 0),
				   new InputElement("WEIGHT", 3, SharpDX.DXGI.Format.R32_Float, 96, 0),
				   new InputElement("INDEX", 3, SharpDX.DXGI.Format.R32_UInt, 100, 0)
				}
			);

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


		//-☆- シェーダー -☆-//

		// 指定されたパスのシェーダーをロードしセットする　引数：読み込んだシェーダー設定先のシェーダー設定用システム, シェーダーパス
		private void M_Load_Shader_By_Path(out C_Shader_Source out_shader_source, string in_shader_path)
		{
			out_shader_source = new C_Shader_Source();
			out_shader_source.PropertyChanged += M_source_PropertyChanged;
			out_shader_source.mp_shader_path = File.ReadAllText(Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), in_shader_path), Encoding.UTF8);

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
				case (int)E_BYTE_KIND.e_BYTE:
					result_string += con_BYTE;
					break;

				// キロバイト表記
				case (int)E_BYTE_KIND.e_KILO_BYTE:
					result_string += con_KILO_BYTE;
					break;

				// メガバイト表記
				case (int)E_BYTE_KIND.e_MEGA_BYTE:
					result_string += con_MEGA_BYTE;
					break;

				// ギガバイト表記
				case (int)E_BYTE_KIND.e_GIGA_BYTE:
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
			// 三角形の描画に戻す
			M_Draw_Triangle();


			// 静的モデルを削除
			if (m_static_model != null)
			{
				m_static_model.mp_mesh_data_list.Clear();
				m_static_model = null;
			}

			// アニメーションモデルを削除
			if (m_animation_model != null)
			{
				m_animation_model.mp_mesh_list.Clear();
				m_animation_model = null;
			}

			// すでに持っているアニメーションデータを削除
			m_animation_system_list.Clear();

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

			uc_dx_11_panel.Invalidate();

			return;
		}


		// WVPマトリクスの定数バッファを更新する　引数：セットする定数バッファのインデックス番号
		private void M_Update_WVP_Constant_Buffer(int in_set_index)
		{
			// ☆ 変数宣言 ☆ //
			Constant_Data.S_WVP new_wvp = new Constant_Data.S_WVP();    // 新しいWVPマトリクスのデータ

			Matrix new_world_matrix = new Matrix();         // 新しいワールドマトリクスのデータ


			// ワールドマトリクスを生成
			m_model_transform.M_Convert_To_Matrix(ref new_world_matrix);

			// ワールドマトリクスをセット
			new_wvp.mp_world_matrix = new_world_matrix;


			// ビューマトリクスを生成
			CS_Camera_Manager.mp_camera_system.M_Calculate_Camera_Matrix();

			// ビューマトリクスをセット
			new_wvp.mp_view_matrix = CS_Camera_Manager.mp_camera_system.mp_camera_matrix;


			// プロジェクションマトリクスを生成
			CS_Camera_Manager.mp_camera_system.mp_projection.M_Create_Projection_Matrix();

			// プロジェクションマトリクスをセット
			new_wvp.mp_projection_matrix = CS_Camera_Manager.mp_camera_system.mp_projection.mp_projection_matrix;


			// 定数データをセット
			m_wvp_constant_buffer.mp_constant_data_list[0] = new_wvp;

			// 定数バッファを更新
			m_wvp_constant_buffer.M_Write_Data_To_Constant_Buffer(uc_dx_11_panel.mp_renderer.mp_context);


			// 定数バッファをセット
			foreach (var l_now_mesh in m_draw_setting.mp_mesh_data_list)
			{
				l_now_mesh.mp_constant_buffer_set_list.Add(new S_DX_11_Constant_Buffer_Draw_Setting(m_wvp_constant_buffer, E_DX_11_SHADER_TYPE.e_VERTEX_SHADER, in_set_index));
			}

			return;
		}


		// ボーンマトリクスの定数バッファを更新する　引数：セットする定数バッファのインデックス番号, ブレンドの割合
		private void M_Update_Bone_Matrix_Constant_Buffer(int in_set_index)
		{
			// ☆ 変数宣言 ☆ //
			List<SharpDX.Matrix> animation_matrix_list = new List<Matrix>(); // ボーンマトリクス計算用のリスト


			// ボーンマトリクスの定数バッファを生成
			m_bone_matrix_constant_buffer.M_Create_Constant_Buffer(uc_dx_11_panel.mp_renderer.mp_device, m_animation_model.mp_bone_data_list.Count);


			// アニメーションがある時はアニメーションの計算を行う
			if (m_animation_system_list.Count > 0)
			{
				// ボーンマトリクスのリストを生成
				for (int l_now_bone_matrix_num = 0; l_now_bone_matrix_num < m_animation_model.mp_bone_data_list.Count; l_now_bone_matrix_num++)
				{
					animation_matrix_list.Add(new Matrix());
				}


				// ブレンド先とブレンド元のアニメーションがない時は何もしない
				if (m_animation_to_index < 0 && m_animation_by_index < 0)
				{

				}

				// ブレンド先がない時はブレンド元のアニメーション結果をボーンオフセットマトリクスとブレンドする
				else if (m_animation_to_index < 0)
				{
					m_animation_system_list[m_animation_by_index].M_Update_Animation_By_Time(ref animation_matrix_list, m_animation_by_time);


					// ボーンオフセットマトリクスとブレンド
					for (int l_now_bone_matrix_num = 0; l_now_bone_matrix_num < m_bone_matrix_constant_buffer.mp_constant_data_list.Count; l_now_bone_matrix_num++)
					{
						animation_matrix_list[l_now_bone_matrix_num] =
							m_animation_model.mp_bone_data_list[l_now_bone_matrix_num].mp_offset_matrix * m_animation_blend_percent + animation_matrix_list[l_now_bone_matrix_num] * (1.0f - m_animation_blend_percent);
					}
				}

				// ブレンド元がない時はブレンド先のアニメーション結果をボーンオフセットマトリクスとブレンドする
				else if (m_animation_by_index < 0)
				{
					m_animation_system_list[m_animation_to_index].M_Update_Animation_By_Time(ref animation_matrix_list, m_animation_to_time);


					// ボーンオフセットマトリクスとブレンド
					for (int l_now_bone_matrix_num = 0; l_now_bone_matrix_num < m_bone_matrix_constant_buffer.mp_constant_data_list.Count; l_now_bone_matrix_num++)
					{
						animation_matrix_list[l_now_bone_matrix_num] =
							m_animation_model.mp_bone_data_list[l_now_bone_matrix_num].mp_offset_matrix * (1.0f - m_animation_blend_percent) + animation_matrix_list[l_now_bone_matrix_num] * m_animation_blend_percent;
					}
				}

				// ブレンド先とブレンド元のアニメーションがある時はブレンドする
				else
				{
					m_animation_system_list[m_animation_by_index].M_Update_Animation_By_Time_And_Blend_Rate
						(
							ref animation_matrix_list,
							m_animation_system_list[m_animation_to_index],
							m_animation_by_time,
							m_animation_to_time,
							m_animation_blend_percent
						);
				}
			}


			// アニメーションの結果にボーンの親子関係による更新を掛ける
			M_Update_Bone_Animation_By_Parent_Child_Relation(ref animation_matrix_list, 0);

			// アニメーションの結果とボーンオフセットマトリクスを掛ける
			for (int l_now_bone_matrix_num = 0; l_now_bone_matrix_num < m_bone_matrix_constant_buffer.mp_constant_data_list.Count; l_now_bone_matrix_num++)
			{
				animation_matrix_list[l_now_bone_matrix_num] *= m_animation_model.mp_bone_data_list[l_now_bone_matrix_num].mp_offset_matrix;
			}


			// ボーンマトリクスの定数バッファにデータを書き込む
			m_bone_matrix_constant_buffer.M_Write_Data_To_Constant_Buffer(uc_dx_11_panel.mp_renderer.mp_context);

			// 定数バッファをセット
			foreach (var l_now_mesh in m_draw_setting.mp_mesh_data_list)
			{
				l_now_mesh.mp_constant_buffer_set_list.Add(new S_DX_11_Constant_Buffer_Draw_Setting(m_bone_matrix_constant_buffer, E_DX_11_SHADER_TYPE.e_VERTEX_SHADER, in_set_index));
			}

			return;
		}


		// ボーンのアニメーション結果にボーンの親子関係による更新を掛ける　引数：ボーンのアニメーション結果のリスト, 現在のボーン番号
		private void M_Update_Bone_Animation_By_Parent_Child_Relation(ref List<SharpDX.Matrix> in_animation_matrix_list, int in_now_bone_number)
		{
			// ボーンの親がいないときは、子の更新のみかける
			if (m_animation_model.mp_bone_data_list[in_now_bone_number].mp_parent_index < 0)
			{
				M_Update_Bone_Animation_By_Parent_Child_Relation(ref in_animation_matrix_list, in_now_bone_number);
			}

			// ボーンの親がいるときは、親の更新を掛けてから子の更新を掛ける
			else
			{
				// アニメーションのデータと親のボーンオフセットマトリクスを掛ける
				in_animation_matrix_list[in_now_bone_number] *= in_animation_matrix_list[m_animation_model.mp_bone_data_list[in_now_bone_number].mp_parent_index];

				// 子の更新をかける
				M_Update_Bone_Animation_By_Parent_Child_Relation(ref in_animation_matrix_list, in_now_bone_number);
			}

			return;
		}


		//-☆- 描画 -☆-//

		// 三角形を描画
		private void M_Draw_Triangle()
		{
            // 三角形用のシェーダーをセット
            M_Set_Triangle_Shader();

			// 描画を実行
			uc_dx_11_panel.M_Reset_To_Triangle();
			uc_dx_11_panel.M_Re_Paint();

			return;
		}

		// 静的モデルを描画
		private void M_Draw_Static_Model()
        {
			// デバッグ時は描画開始のログを出力
			CS_Draw_Log_System.M_Draw_Log(" ☆ 静的モデルの描画を開始します ☆ ");

            // 静的モデルがないなら終了
            if (m_static_model == null)
            {
                CS_Draw_Log_System.M_Draw_Log(" ☆ 静的モデルがロードされてないので描画を中止 ☆ ");

                return;
			}

            // 描画用の設定を初期化する
            m_draw_setting = new CS_DX_11_Draw_Call_System();


			// ☆ 変数宣言 ☆ //
			CS_DX_11_Vertex_Buffer<S_Static_Vertex_Data> new_vertex_buffer = new CS_DX_11_Vertex_Buffer<S_Static_Vertex_Data>(); // 頂点バッファ


			// 静的モデル用のシェーダーをセット
			M_Set_Static_Model_Shader();


			// 頂点バッファのデータを設定
			new_vertex_buffer.mp_vertex_data = m_static_model.mp_vertex_data_list;
			

			// 頂点バッファを生成
			new_vertex_buffer.M_Create_Vertex_Buffer(uc_dx_11_panel.mp_renderer.mp_device);

			// 新しい頂点バッファを設定
			m_draw_setting.mp_vertex_buffer = new_vertex_buffer;


			// メッシュデータをリセット
			m_draw_setting.mp_mesh_data_list.Clear();


			// 頂点インデックスデータを設定
			for (int l_now_mesh_data_number = 0; l_now_mesh_data_number < m_static_model.mp_mesh_data_list.Count; l_now_mesh_data_number++)
			{
				// メッシュデータを追加
				m_draw_setting.mp_mesh_data_list.Add(new CS_DX11_Mesh_Data());

				// インデックスデータを追加
				foreach (var l_now_index in m_static_model.mp_mesh_data_list[l_now_mesh_data_number].mp_index_list)
				{
					m_draw_setting.mp_mesh_data_list[l_now_mesh_data_number].mp_vertex_index.mp_index_data.Add(l_now_index);
				}
			}

			// 頂点インデックスバッファを生成
			foreach (var l_now_mesh_data in m_draw_setting.mp_mesh_data_list)
			{
				l_now_mesh_data.mp_vertex_index.M_Create_Index_Buffer(uc_dx_11_panel.mp_renderer.mp_device, uc_dx_11_panel.mp_renderer.mp_context);
			}


			// カメラを設定
			CS_Camera_Manager.M_Set_Camera_Target_Position(m_model_transform.mp_position.mp_pos);
			CS_Camera_Manager.M_Set_Target_To_Camera_Angle(m_camera_angle);
			CS_Camera_Manager.M_Set_Target_To_Camera_Distance(m_camera_distance);
			CS_Camera_Manager.M_Update_Camera_Position_And_Angle_By_Target();


			// WVPマトリクスを定数バッファにセット
			M_Update_WVP_Constant_Buffer(con_WVP_CONSTANT_BUFFER_SLOT_NUMBER);


			// 描画を実行
			uc_dx_11_panel.mp_now_draw_setting = m_draw_setting;
            uc_dx_11_panel.M_Re_Paint();


			// デバッグ時は描画終了のログを出力
            CS_Draw_Log_System.M_Draw_Log(" ☆ 静的モデルの描画を完了 ☆ ");

            return;
		}


		// アニメーションモデルを描画
		private void M_Draw_Animation_Model()
		{
			// アニメーションモデルがないなら終了
			if (m_animation_model == null)
			{
				return;
            }


            // ☆ 変数宣言 ☆ //
            CS_DX_11_Vertex_Buffer<S_Animation_Vertex_Data> new_vertex_buffer = new CS_DX_11_Vertex_Buffer<S_Animation_Vertex_Data>(); // 頂点バッファ


            // 描画用の設定を初期化する
            m_draw_setting = new CS_DX_11_Draw_Call_System();


			// アニメーションモデル用のシェーダーをセット
			M_Set_Animation_Model_Shader();


			// 頂点バッファのデータを設定
			new_vertex_buffer.mp_vertex_data = m_animation_model.mp_vertex_list;

			// 頂点バッファを生成
			new_vertex_buffer.M_Create_Vertex_Buffer(uc_dx_11_panel.mp_renderer.mp_device);

			// 新しい頂点バッファを設定
			m_draw_setting.mp_vertex_buffer = new_vertex_buffer;


			// メッシュデータをクリア
			m_draw_setting.mp_mesh_data_list.Clear();


			// 頂点インデックスデータを設定
			for (int l_now_mesh_data_number = 0; l_now_mesh_data_number < m_animation_model.mp_mesh_list.Count; l_now_mesh_data_number++)
			{
				foreach (var l_now_index in m_animation_model.mp_mesh_list[l_now_mesh_data_number].mp_index_data_list)
				{
					m_draw_setting.mp_mesh_data_list[l_now_mesh_data_number].mp_vertex_index.mp_index_data.Add(l_now_index);
				}
			}

			// 頂点インデックスバッファを生成
			foreach (var l_now_mesh_data in m_draw_setting.mp_mesh_data_list)
			{
				l_now_mesh_data.mp_vertex_index.M_Create_Index_Buffer(uc_dx_11_panel.mp_renderer.mp_device, uc_dx_11_panel.mp_renderer.mp_context);
			}


			// WVPマトリクスを定数バッファにセット
			M_Update_WVP_Constant_Buffer(con_WVP_CONSTANT_BUFFER_SLOT_NUMBER);

			// ボーンマトリクスを定数バッファにセット
			M_Update_Bone_Matrix_Constant_Buffer(con_BONE_MATRIX_CONSTANT_BUFFER_SLOT_NUMBER);


			// 描画を実行
			uc_dx_11_panel.mp_now_draw_setting = m_draw_setting;
			uc_dx_11_panel.M_Re_Paint();

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
			// ☆ 変数宣言 ☆ //
			CS_Animation_System new_animation_system = new CS_Animation_System(); // 新しいアニメーションシステム


			// ロード開始時点での時間と使用メモリを記録
			M_Start_Save_Time_And_Memory_Click();


			// アニメーションデータのロード
			CS_Animation_Data_Import_System.M_Load_Animation_Data(in_file_path, out new_animation_system, m_animation_model);


			// ロード終了、ロードにかかった時間と必要なメモリサイズを表示
			M_Stop_Save_Time_And_Memory_Click_Set_To_Original_Format();


			// 新しいアニメーションシステムをリストに追加
			m_animation_system_list.Add(new_animation_system);

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


			// 静的モデルのロード
			if (data_name == con_IS_ELSSTMDL_TEXT)
			{
				// モデルとアニメーションのデータをリセット
				M_Model_And_Animation_Data_Reset();

				// 静的モデルのロード
				M_Static_Model_Load(relative_file_path);

				// 静的モデルを描画
				M_Draw_Static_Model();

				return;
			}


			// アニメーションモデルのロード
			if (data_name == con_IS_ELANMMDL_TEXT)
			{
				// モデルとアニメーションのデータをリセット
				M_Model_And_Animation_Data_Reset();

				// アニメーションモデルのロード
				M_Animation_Model_Load(relative_file_path);

				// アニメーションモデルを描画
				M_Draw_Animation_Model();

				return;
			}


			// アニメーションデータのロード
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


		// モデルのリセットボタンが押されたら、三角形を描画し、モデルデータリセット
        private void B_model_reset_Click(object sender, EventArgs e)
        {
			// モデルとアニメーションのデータをリセット
			M_Model_And_Animation_Data_Reset();

			return;
        }
    }
}
