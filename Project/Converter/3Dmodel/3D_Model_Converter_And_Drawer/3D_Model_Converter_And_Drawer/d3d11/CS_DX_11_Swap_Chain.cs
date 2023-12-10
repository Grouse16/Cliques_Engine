using SharpDX.Direct3D11;
using SharpDX.DXGI;
using System;


namespace SharpDXSample
{
    // ☆ クラス ☆ //

    // スワップチェインを管理するクラス
    class CS_DX_11_Swap_Chain : IDisposable
    {
        // ☆ 変数宣言 ☆ //
        private SwapChain m_swap_chain; // スワップチェイン

        private RenderTargetView m_render_target_view;  // レンダーターゲットビュー


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_DX_11_Swap_Chain(SwapChain in_set_swap_chain)
        {
            m_swap_chain = in_set_swap_chain;
        }


        //-☆- 削除 -☆-//

        // メモリの解放を行う
        public void Dispose()
        {
            // レンダーターゲットビューの解放
            M_Release_Render_Target_View();

            // スワップチェインの解放
            if (m_swap_chain != null)
            {
                m_swap_chain.Dispose();
                m_swap_chain = null;
            }
        }


        // レンダーターゲットビューの解放
        public void M_Release_Render_Target_View()
        {
            // レンダーターゲットビューの解放
            if (m_render_target_view != null)
            {
                m_render_target_view.Dispose();
                m_render_target_view = null;
            }
        }


        //-☆- 描画 -☆-//

        // バックバッファをフロントバッファに転送する
        public void M_Present_And_Swap()
        {
            m_swap_chain.Present(0, PresentFlags.None);

            return;
        }


        //-☆- セッタ -☆-//

        // 画面のサイズの変更
        public void M_Resize(int in_width, int in_height)
        {
            // ☆ 変数宣言 ☆ //
            SwapChainDescription swap_chain_desc = m_swap_chain.Description;    // スワップチェインの設定

            // レンダーターゲットビューの解放
            M_Release_Render_Target_View();

            // スワップチェインのサイズ変更
            m_swap_chain.ResizeBuffers(swap_chain_desc.BufferCount, in_width, in_height, swap_chain_desc.ModeDescription.Format, swap_chain_desc.Flags);
        }


        //-☆- ゲッタ -☆-//

        // レンダーターゲットビューの取得
        public RenderTargetView M_Get_Render_Target_View(SharpDX.Direct3D11.Device in_device)
        {
            // レンダーターゲットビューがない場合は生成する
            if (m_render_target_view == null)
            {
                m_render_target_view = new RenderTargetView(in_device, Texture2D.FromSwapChain<Texture2D>(m_swap_chain, 0));
            }

            return m_render_target_view;
        }
    }
}
