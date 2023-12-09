using SharpDX.D3DCompiler;
using SharpDX.Direct3D11;
using System;

namespace SharpDXSample
{
    // ☆ クラス ☆ //

    // シェーダーを管理するクラス
    public class CS_DX_11_Shader : IDisposable
    {
        // ☆ 変数宣言 ☆ //
        private InputLayout m_layout;   // 入力レイアウト

        private CompilationResult m_compiled_vertex_shader_code;    // 頂点シェーダーのコンパイル済みコード
        private CompilationResult m_compiled_pixel_shader_code;     // ピクセルシェーダーのコンパイル済みコード

        private VertexShader m_vertex_shader;   // 頂点シェーダー
        private PixelShader m_pixel_shader;     // ピクセルシェーダー

        private string m_shader_path;   // シェーダーのパス


        // ☆ プロパティ ☆ //

        // シェーダーのパス
        public string mp_shader_path
        {
            // ゲッタ
            get
            {
                return m_shader_path;
            }

            // セッタ
            set
            {
                // すでに同じ値が入っている場合は何もしない
                if (m_shader_path == value)
                {
                    return;
                }

                // 値の設定
                m_shader_path = value;

                // メモリの解放
                Dispose();

                // シェーダーをコンパイルする
                m_compiled_vertex_shader_code = ShaderBytecode.Compile(m_shader_path, "VS", "vs_4_0", ShaderFlags.None, EffectFlags.None);
                m_compiled_pixel_shader_code = ShaderBytecode.Compile(m_shader_path, "PS", "ps_4_0", ShaderFlags.None, EffectFlags.None);

                // コンパイル実行を表示
                Console.WriteLine("compiled");

                return;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 削除 -☆-//

        // メモリの解放を行う
        public void Dispose()
        {
            // 入力レイアウトの解放
            if (m_layout != null)
            {
                m_layout.Dispose();
                m_layout = null;
            }

            // 頂点シェーダーの解放
            if (m_vertex_shader != null)
            {
                m_vertex_shader.Dispose();
                m_vertex_shader = null;
            }

            // ピクセルシェーダーの解放
            if (m_pixel_shader != null)
            {
                m_pixel_shader.Dispose();
                m_pixel_shader = null;
            }

            // コンパイル済み頂点シェーダーコードの解放
            if (m_compiled_vertex_shader_code != null)
            {
                m_compiled_vertex_shader_code.Dispose();
                m_compiled_vertex_shader_code = null;
            }

            // コンパイル済みピクセルシェーダーコードの解放
            if (m_compiled_pixel_shader_code != null)
            {
                m_compiled_pixel_shader_code.Dispose();
                m_compiled_pixel_shader_code = null;
            }

            return;
        }


        //-☆- 生成 -☆-//

        // シェーダーの生成を行う　引数：デバイス
        void M_Create_Shader(Device in_device)
        {
            // 頂点シェーダーの生成
            if (m_vertex_shader == null)
            {
                if (m_compiled_vertex_shader_code != null)
                {
                    m_vertex_shader = new VertexShader(in_device, m_compiled_vertex_shader_code);
                }
            }

            // 入力レイアウトの生成
            if (m_layout == null)
            {
                if (m_compiled_vertex_shader_code != null)
                {
                    m_layout = new InputLayout
                    (
                        in_device,
                        ShaderSignature.GetInputSignature(m_compiled_vertex_shader_code),
                        new[]
                        {
                            new InputElement("POSITION", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 0, 0),
                            new InputElement("COLOR", 0, SharpDX.DXGI.Format.R32G32B32A32_Float, 16, 0)
                        }
                    );
                }
            }

            // ピクセルシェーダーの生成
            if (m_pixel_shader == null)
            {
                if (m_compiled_pixel_shader_code != null)
                {
                    m_pixel_shader = new PixelShader(in_device, m_compiled_pixel_shader_code);
                }
            }

            return;
        }


        //-☆- セッタ -☆-//

        // シェーダーをコンテキストに設定する　引数：デバイス、コンテキスト
        public void M_Set_Shader(Device device, DeviceContext context)
        {
            // シェーダー未生成の場合は生成する
            M_Create_Shader(device);

            // シェーダーの設定
            if (m_vertex_shader != null)
            {
                context.VertexShader.Set(m_vertex_shader);
                context.PixelShader.Set(m_pixel_shader);
                context.InputAssembler.InputLayout = m_layout;
            }

            return;
        }
    }
}
