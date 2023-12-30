using _3D_Model_Converter_And_Drawer;
using _3D_Model_Converter_And_Drawer.d3d11;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Windows.Forms;


namespace SharpDXSample
{
	// ☆ クラス ☆ //

	// DirectX11を管理するクラス
	public partial class UC_DX_11_Panel : UserControl
	{
		// ☆ 変数宣言 ☆ //
		private CS_DX_11_Renderer m_renderer = new CS_DX_11_Renderer(); // レンダリングシステム

		private CS_DX_11_Shader m_shader = new CS_DX_11_Shader();   // シェーダー

		private CS_DX11_Draw_Call_System m_triangle_draw_call_system = new CS_DX11_Draw_Call_System();   // 四角形描画実行用のシステム
		

		// ☆ プロパティ ☆ //

		// レンダリングシステム
		public CS_DX_11_Renderer mp_renderer
		{
			// ゲッタ
			get
			{
				return m_renderer;
			}
		}

		// シェーダー
		public CS_DX_11_Shader mp_shader
		{
			// ゲッタ
			get
			{
				return m_shader;
			}
		}


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		public UC_DX_11_Panel()
		{
			// コンポーネントの初期化
			InitializeComponent();

			// レンダリングシステムの初期化
			m_renderer.mp_clear_color = new SharpDX.Mathematics.Interop.RawColor4(0, 0, 0.5f, 1.0f);

			return;
		}


		//-☆- 削除 -☆-//

		// メモリの解放を行う
		public void Close()
		{
			// シェーダーの解放
			if (m_shader != null)
			{
				m_shader.Dispose();
				m_shader = null;
			}

			// レンダリングシステムの解放
			if (m_renderer != null)
			{
				m_renderer.Dispose();
				m_renderer = null;
			}

			return;
		}


		//-☆- 描画 -☆-//

		// 描画の処理
		public void M_Draw(CS_DX11_Draw_Call_System in_draw_call)
		{
			// レンダリングの開始
			m_renderer.M_Begin_Rendering(Handle);

			// シェーダーの設定
			m_shader.M_Set_Shader(m_renderer.mp_device, m_renderer.mp_context);

			// 頂点バッファの設定
			in_draw_call.mp_vertex_buffer.M_Set_Vertex_Buffer(m_renderer.mp_device, m_renderer.mp_context);


			// 頂点バッファがあるときのみ描画を実行
			if (in_draw_call.mp_vertex_buffer.M_Get_Vertex_Buffer() != null)
			{
				// メッシュごとの描画を実行
				foreach (var l_now_mesh_data in in_draw_call.mp_mesh_data_list)
                {
					// インデックスのデータがなければ次のメッシュの描画へ
					if (l_now_mesh_data.mp_vertex_index == null)
					{
						continue;
                    }


                    // 頂点インデックスバッファの設定
                    l_now_mesh_data.mp_vertex_index.M_Set_Index_Buffer(m_renderer.mp_device, m_renderer.mp_context);


					// インデックスバッファがなければ次のメッシュの描画へ
					if (l_now_mesh_data.mp_vertex_index.mp_index_buffer == null)
					{
						continue;
					}


					// 定数バッファの設定
					foreach (var l_now_constant_buffer_setting in l_now_mesh_data.mp_constant_buffer_set_list)
					{
						M_Set_Constant_Buffer(l_now_constant_buffer_setting);
					}

					// テクスチャの設定
					foreach (var l_now_texture_setting in l_now_mesh_data.mp_texture_set_list)
					{
						M_Set_Texture(l_now_texture_setting);
					}

					// 描画を実行
					m_renderer.mp_context.DrawIndexed(l_now_mesh_data.mp_vertex_index.mp_index_data.Count, 0, 0);
				}
			}

			// レンダリングの終了
			m_renderer.M_End_Rendering();

			return;
		}


		// 描画の実行
		protected override void OnPaint(PaintEventArgs e)
		{
			M_Draw(m_triangle_draw_call_system);

			return;
		}


		// リソースを初期設定に戻し、三角形の描画に戻す
		public void M_Draw_Triangle()
		{
			// 三角形用の描画システムがまだ生成されていなければ生成
			if (m_triangle_draw_call_system.mp_vertex_buffer == null)
			{
				// ☆ 変数宣言 ☆ //
				CS_DX_11_Vertex_Buffer<S_Triangle_Vertex> new_vertex_buffer = new CS_DX_11_Vertex_Buffer<S_Triangle_Vertex>();    // 新しい頂点バッファ


				// 三角形用の描画システムを生成
                m_triangle_draw_call_system = new CS_DX11_Draw_Call_System();


				// 三角形データを設定
				new_vertex_buffer.mp_vertex_data.Add(new S_Triangle_Vertex(new SharpDX.Vector4(0.0f, 0.5f, 0.5f, 1.0f), new SharpDX.Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
				new_vertex_buffer.mp_vertex_data.Add(new S_Triangle_Vertex(new SharpDX.Vector4(0.5f, -0.5f, 0.5f, 1.0f), new SharpDX.Vector4(0.0f, 1.0f, 0.0f, 1.0f)));
				new_vertex_buffer.mp_vertex_data.Add(new S_Triangle_Vertex(new SharpDX.Vector4(-0.5f, -0.5f, 0.5f, 1.0f), new SharpDX.Vector4(0.0f, 0.0f, 1.0f, 1.0f)));

				// 頂点バッファを設定
				m_triangle_draw_call_system.mp_vertex_buffer = new_vertex_buffer;


				// インデックスバッファを設定
				m_triangle_draw_call_system.mp_mesh_data_list.Add(new CS_DX11_Mesh_Data());
				m_triangle_draw_call_system.mp_mesh_data_list[0].mp_vertex_index = new CS_DX_11_Index_Buffer_Class();
				m_triangle_draw_call_system.mp_mesh_data_list[0].mp_vertex_index.mp_index_data.Add(0);
				m_triangle_draw_call_system.mp_mesh_data_list[0].mp_vertex_index.mp_index_data.Add(1);
				m_triangle_draw_call_system.mp_mesh_data_list[0].mp_vertex_index.mp_index_data.Add(2);
            }


			// 描画を実行
			M_Draw(m_triangle_draw_call_system);

			return;
		}


		// 定数バッファをセットする　引数：定数バッファの設定
		public void M_Set_Constant_Buffer(S_DX11_Constant_Buffer_Draw_Setting in_constant_buffer_setting)
		{
			// シェーダーの種類で設定先を分岐
			switch (in_constant_buffer_setting.mp_attach_shader_type)
			{
				// 頂点シェーダー
				case E_DX11_SHADER_TYPE.e_VERTEX_SHADER:
					m_renderer.mp_context.VertexShader.SetConstantBuffer(in_constant_buffer_setting.mp_set_slot, in_constant_buffer_setting.mp_constant_buffer_handle.M_Get_Constant_Buffer());
					break;

                // ハルシェーダー
                case E_DX11_SHADER_TYPE.e_HULL_SHADER:
                    m_renderer.mp_context.HullShader.SetConstantBuffer(in_constant_buffer_setting.mp_set_slot, in_constant_buffer_setting.mp_constant_buffer_handle.M_Get_Constant_Buffer());
                    break;

                // ドメインシェーダー
                case E_DX11_SHADER_TYPE.e_DOMAIN_SHADER:
                    m_renderer.mp_context.DomainShader.SetConstantBuffer(in_constant_buffer_setting.mp_set_slot, in_constant_buffer_setting.mp_constant_buffer_handle.M_Get_Constant_Buffer());
                    break;

                // ジオメトリシェーダー
                case E_DX11_SHADER_TYPE.e_GEOMETRY_SHADER:
                    m_renderer.mp_context.GeometryShader.SetConstantBuffer(in_constant_buffer_setting.mp_set_slot, in_constant_buffer_setting.mp_constant_buffer_handle.M_Get_Constant_Buffer());
                    break;

                // ピクセルシェーダー
                case E_DX11_SHADER_TYPE.e_PIXEL_SHADER:
					m_renderer.mp_context.PixelShader.SetConstantBuffer(in_constant_buffer_setting.mp_set_slot, in_constant_buffer_setting.mp_constant_buffer_handle.M_Get_Constant_Buffer());
					break;
			}

			return;
		}


		// テクスチャをセットする　引数：テクスチャの設定
		public void M_Set_Texture(S_DX11_Texture_Draw_Setting in_texture_setting)
		{
            // シェーダーの種類で設定先を分岐
            switch (in_texture_setting.mp_attach_shader_type)
			{
                // 頂点シェーダー
                case E_DX11_SHADER_TYPE.e_VERTEX_SHADER:
                    m_renderer.mp_context.VertexShader.SetShaderResource(in_texture_setting.mp_set_slot, in_texture_setting.mp_texture.mp_texture_view);
                    break;

                // ハルシェーダー
                case E_DX11_SHADER_TYPE.e_HULL_SHADER:
                    m_renderer.mp_context.HullShader.SetShaderResource(in_texture_setting.mp_set_slot, in_texture_setting.mp_texture.mp_texture_view);
                    break;

                // ドメインシェーダー
                case E_DX11_SHADER_TYPE.e_DOMAIN_SHADER:
                    m_renderer.mp_context.DomainShader.SetShaderResource(in_texture_setting.mp_set_slot, in_texture_setting.mp_texture.mp_texture_view);
                    break;

                // ジオメトリシェーダー
                case E_DX11_SHADER_TYPE.e_GEOMETRY_SHADER:
                    m_renderer.mp_context.GeometryShader.SetShaderResource(in_texture_setting.mp_set_slot, in_texture_setting.mp_texture.mp_texture_view);
                    break;

                // ピクセルシェーダー
                case E_DX11_SHADER_TYPE.e_PIXEL_SHADER:
                    m_renderer.mp_context.PixelShader.SetShaderResource(in_texture_setting.mp_set_slot, in_texture_setting.mp_texture.mp_texture_view);
                    break;
            }

            return;
        }


		//-☆- サイズ変更 -☆-//

		// サイズが変更されたら調整する
		protected override void OnSizeChanged(EventArgs e)
		{
			m_renderer.M_Create_Renderer(Handle);
			m_renderer.M_Resize(ClientSize.Width, ClientSize.Height);
			Invalidate();

			return;
		}


		//-☆- ロード -☆-//

		// ロードを行う（ワープポイント）
		private void D3D11Panel_Load(object sender, EventArgs e)
		{
			return;
		}
	}
}
