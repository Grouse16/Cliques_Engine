using _3D_Model_Converter_And_Drawer.d3d11;
using System;
using System.ComponentModel;
using System.Windows.Forms;


namespace SharpDXSample
{
    // ☆ クラス ☆ //

    // DirectX11を管理するクラス
    public partial class UC_DX_11_Panel : UserControl
    {
        // ☆ 変数宣言 ☆ //
        CS_DX_11_Renderer m_renderer = new CS_DX_11_Renderer(); // レンダリングシステム

        CS_DX_11_Shader m_shader = new CS_DX_11_Shader();   // シェーダー

        CS_DX_11_Vertex_Buffer m_vertex_buffer = new CS_DX_11_Vertex_Buffer();  // 頂点バッファ

        CS_DX_11_Index_Buffer_Class m_index_buffer = new CS_DX_11_Index_Buffer_Class(); // インデックスバッファ
        

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
        public CS_DX_11_Vertex_Buffer mp_buffer
        {
            // ゲッタ
            get
            {
                return m_vertex_buffer;
            }
        }

        // インデックスバッファ
        public CS_DX_11_Index_Buffer_Class Index_Buffer
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

            // リソースが生成されているときのみ描画を実行する
            if (m_vertex_buffer.mp_vertex_buffer != null && m_index_buffer.mp_index_buffer != null)
            {
                m_renderer.mp_context.DrawIndexed(m_index_buffer.mp_index_data.Count, 0, 0);
            }

            // レンダリングの終了
            m_renderer.M_End_Rendering();

            return;
        }


        //-☆- サイズ変更 -☆-//

        // サイズが変更されたら調整する
        protected override void OnSizeChanged(EventArgs e)
        {
            m_renderer.M_Create_Renderer(Handle); // レンダリングシステムの生成
            m_renderer.M_Resize(ClientSize.Width, ClientSize.Height);
            Invalidate(); // 再描画

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
