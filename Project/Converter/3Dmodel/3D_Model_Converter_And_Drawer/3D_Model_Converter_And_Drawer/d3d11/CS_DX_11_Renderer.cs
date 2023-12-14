using SharpDX;
using SharpDX.Direct3D;
using SharpDX.Direct3D11;
using SharpDX.DXGI;
using System;


namespace SharpDXSample
{
    // ☆ クラス ☆ //

    // レンダリングを管理するクラス
    public class CS_DX_11_Renderer : IDisposable
    {
        // ☆ 変数宣言 ☆ //
        SharpDX.Direct3D11.Device m_device; // デバイス

        DeviceContext m_context;    // デバイスコンテキスト

        CS_DX_11_Swap_Chain m_swap_chain;    // スワップチェイン


        // ☆ プロパティ ☆ //

        // 画面の横幅
        public int mp_width
        {
            // ゲッタ
            get;

            // セッタ
            private set;
        }

        // 画面の縦幅
        public int mp_height
        {
            // ゲッタ
            get;

            // セッタ
            private set;
        }

        // ビューポート
        Viewport mp_view_port
        {
            // ゲッタ
            get
            {
                return new Viewport(0, 0, mp_width, mp_height, 0.0f, 1.0f);
            }
        }

        // クリアカラー
        public Color4 mp_clear_color
        {
            // ゲッタ
            get;

            // セッタ
            set;
        }

        // デバイス
        public SharpDX.Direct3D11.Device mp_device
        {
            // ゲッタ
            get 
            {
                return m_device;
            }
        }

        // デバイスコンテキスト
        public DeviceContext mp_context
        {
            get 
            { 
                return m_context;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 削除 -☆-//

        // メモリの解放を行う
        public void Dispose()
        {
            // スワップチェインの解放
            if (m_swap_chain != null)
            {
                m_swap_chain.Dispose();
                m_swap_chain = null;
            }

            // デバイスコンテキストの解放
            if (m_context != null)
            {
                m_context.Dispose();
                m_context = null;
            }

            // デバイスの解放
            if (m_device != null)
            {
                m_device.Dispose();
                m_device = null;
            }

            return;
        }


        //-☆- 生成 -☆-//

        // レンダリングシステムの生成を行う　引数：ウィンドウハンドル
        public void M_Create_Renderer(IntPtr in_handle_window)
        {
            // 既に生成済みならば処理を行わない
            if (m_device != null && m_swap_chain != null)
            {
                return;
            }


            // メモリを解放する
            Dispose();


            // オブジェクト追跡の有効化
            SharpDX.Configuration.EnableObjectTracking = true;


            // ☆ 変数宣言 ☆ //
            SwapChainDescription swap_chain_desc = new SwapChainDescription()   // スワップチェインの設定
            {
                BufferCount = 1,
                ModeDescription = new ModeDescription(mp_width, mp_height,
                    new Rational(60, 1), Format.R8G8B8A8_UNorm),
                IsWindowed = true,
                OutputHandle = in_handle_window,
                SampleDescription = new SampleDescription(1, 0),
                SwapEffect = SwapEffect.Discard,
                Usage = Usage.RenderTargetOutput
            };

            SwapChain new_swap_chain;    // 新しいスワップチェイン


            // デバイスとスワップチェインの生成
            SharpDX.Direct3D11.Device.CreateWithSwapChain(DriverType.Hardware,
                DeviceCreationFlags.Debug,
                swap_chain_desc,
                out m_device, out new_swap_chain);

            // デバイスコンテキストの取得
            m_context = m_device.ImmediateContext;

            // ウィンドウメッセージを無視するように設定
            new_swap_chain.GetParent<Factory>().MakeWindowAssociation(in_handle_window, WindowAssociationFlags.IgnoreAll);
            
            // 新しいスワップチェインをセット
            m_swap_chain = new CS_DX_11_Swap_Chain(new_swap_chain);

            return;
        }


        //-☆- セッタ -☆-//

        // 画面のサイズの変更　引数：横幅、縦幅
        public void M_Resize(int in_width, int in_height)
        {
            // 変更後の画面サイズが変更前と同じなら設定する必要はない
            if (in_width == mp_width && in_height == mp_height)
            {
                return;
            }

            // 画面サイズのセット
            mp_width = in_width;
            mp_height = in_height;

            // スワップチェインのサイズ変更
            if (m_swap_chain != null)
            {
                m_swap_chain.M_Resize(in_width, in_height);
            }

            return;
        }


        //-☆- 描画 -☆-//

        // レンダリングの開始を行う　引数：ウィンドウハンドル
        public void M_Begin_Rendering(IntPtr in_handle_window)
        {
            // レンダリングシステムの生成
            M_Create_Renderer(in_handle_window);

            // ☆ 変数宣言 ☆ //
            var rtv = m_swap_chain.M_Get_Render_Target_View(m_device);   // レンダーターゲットビュー


            // レンダーターゲットのクリア
            m_context.ClearRenderTargetView(rtv, mp_clear_color);

            // レンダーターゲットの設定
            m_context.OutputMerger.SetTargets(rtv);
            m_context.Rasterizer.SetViewport(mp_view_port);

            return;
        }


        // レンダリングの終了
        public void M_End_Rendering()
        { 
            m_swap_chain.M_Present_And_Swap();

            return;
        }
    }
}
