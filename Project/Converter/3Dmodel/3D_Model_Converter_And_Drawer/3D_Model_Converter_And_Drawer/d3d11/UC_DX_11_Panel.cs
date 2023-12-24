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

		private CS_DX_11_Vertex_Buffer_Handler m_vertex_buffer = new CS_DX_11_Vertex_Buffer<S_Triangle_Vertex>();  // 頂点バッファ

		private CS_DX_11_Index_Buffer_Class m_index_buffer = new CS_DX_11_Index_Buffer_Class(); // インデックスバッファ
		

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

		// 頂点バッファ
		public CS_DX_11_Vertex_Buffer_Handler mp_vertex_buffer
		{
			// ゲッタ
			get
			{
				return m_vertex_buffer;
			}
		}

		// インデックスバッファ
		public CS_DX_11_Index_Buffer_Class mp_index_buffer
		{
			// ゲッタ
			get
			{
				return m_index_buffer;
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
			// 頂点バッファの解放
			if (m_vertex_buffer != null)
			{
				m_vertex_buffer.Dispose();
				m_vertex_buffer = null;
			}

			// インデックスバッファの解放
			if (m_index_buffer != null)
			{
				m_index_buffer.Dispose();
				m_index_buffer = null;
			}

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

		// 描画の実行
		protected override void OnPaint(PaintEventArgs e)
		{
			// レンダリングの開始
			m_renderer.M_Begin_Rendering(Handle);

			// シェーダーの設定
			m_shader.M_Set_Shader(m_renderer.mp_device, m_renderer.mp_context);

            // 頂点バッファの設定
            m_vertex_buffer.M_Set_Vertex_Buffer(m_renderer.mp_device, m_renderer.mp_context);

            // インデックスバッファの設定
            m_index_buffer.M_Set_Index_Buffer(m_renderer.mp_device, m_renderer.mp_context);

            // リソースが生成されていないなら三角形を描画する
            if (m_vertex_buffer.M_Get_Vertex_Buffer() == null || m_index_buffer.mp_index_buffer == null)
			{
				M_Reset_To_Triangle();


                // 頂点バッファの設定
                m_vertex_buffer.M_Set_Vertex_Buffer(m_renderer.mp_device, m_renderer.mp_context);

                // インデックスバッファの設定
                m_index_buffer.M_Set_Index_Buffer(m_renderer.mp_device, m_renderer.mp_context);
            }

			// 描画の実行
            m_renderer.mp_context.DrawIndexed(m_index_buffer.mp_index_data.Count, 0, 0);

            // レンダリングの終了
            m_renderer.M_End_Rendering();

			return;
		}


		// リソースを初期設定に戻し、三角形の描画に戻す
		public void M_Reset_To_Triangle()
		{
			// ☆ 変数宣言 ☆ //
			CS_DX_11_Vertex_Buffer<S_Triangle_Vertex> new_vertex_buffer = new CS_DX_11_Vertex_Buffer<S_Triangle_Vertex>();  // 頂点バッファ

			List<S_Triangle_Vertex> triangle_vertex_list = new List<S_Triangle_Vertex>();   // 三角形の頂点データ


            // 三角形の頂点データを設定
            triangle_vertex_list.Add(new S_Triangle_Vertex(new SharpDX.Vector4(0.0f, 0.5f, 0.5f, 1.0f), new SharpDX.Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
			triangle_vertex_list.Add(new S_Triangle_Vertex(new SharpDX.Vector4(0.5f, -0.5f, 0.5f, 1.0f), new SharpDX.Vector4(0.0f, 1.0f, 0.0f, 1.0f)));
            triangle_vertex_list.Add(new S_Triangle_Vertex(new SharpDX.Vector4(-0.5f, -0.5f, 0.5f, 1.0f), new SharpDX.Vector4(0.0f, 0.0f, 1.0f, 1.0f)));

			// 頂点データを設定
			new_vertex_buffer.M_Set_Vertex(triangle_vertex_list);


			// 頂点バッファを設定
			m_vertex_buffer = new_vertex_buffer;


			// インデックスデータを設定
			m_index_buffer.Dispose();
            m_index_buffer = new CS_DX_11_Index_Buffer_Class();

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
