using System;
using System.Collections.Generic;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpDX;
using SharpDX.Direct3D11;


namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ クラス ☆ //

    // DirectX11のテクスチャのクラス
    public class CS_DX_11_Texture : System.IDisposable
    {
        // ☆ 変数宣言 ☆ //
        private ShaderResourceView m_texture_view = null; // テクスチャビュー

        private string m_name = ""; // テクスチャ名


        // ☆ プロパティ ☆ //

        // テクスチャビュー
        public ShaderResourceView mp_texture_view
        {
            // ゲッタ
            get
            {
                return m_texture_view;
            }

            // セッタ
            set
            {
                m_texture_view = value;
            }
        }

        // テクスチャ名
        public string mp_name
        {
            // ゲッタ
            get
            {
                return m_name;
            }

            // セッタ
            set
            {
                m_name = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化と終了時 -☆-//

        // コンストラクタ
        public CS_DX_11_Texture()
        {
            return;
        }


        // メモリの解放
        public void Dispose()
        {
            Release();

            return;
        }


        // テクスチャの解放
        public void Release()
        {
            // テクスチャビューの解放
            if (m_texture_view != null)
            {
                m_texture_view.Dispose();
                m_texture_view = null;
            }

            // テクスチャ名の初期化
            m_name = "";

            return;
        }


        //-☆- ロード -☆-//

        // テクスチャの読み込み　引数：デバイス, テクスチャまでのパス
        public bool Load(Device in_device, string in_texture_file_path)
        {
            // テクスチャ名の保存
            m_name = in_texture_file_path;

            // テクスチャの読み込み
            m_texture_view = new ShaderResourceView(in_device, M_Load_Texture(in_device, in_texture_file_path));

            // テクスチャの読み込みに失敗した場合
            if (m_texture_view == null)
            {
                // テクスチャの解放
                Release();

                // 読み込み失敗
                return false;
            }

            // 読み込み成功
            return true;
        }


        // テクスチャの読み込み　引数：デバイス, テクスチャまでのパス
        private Texture2D M_Load_Texture(Device in_device, string in_texture_file_path)
        {
            // テクスチャの読み込み
            using (System.Drawing.Bitmap bitmap_data = (System.Drawing.Bitmap)System.Drawing.Image.FromFile(in_texture_file_path))
            {
                // ☆ 変数宣言 ☆ //
                System.Drawing.Rectangle source_area = new System.Drawing.Rectangle(0, 0, bitmap_data.Width, bitmap_data.Height);   // 読み込み元の領域

                BitmapData lock_bitmap_data = bitmap_data.LockBits(source_area, System.Drawing.Imaging.ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format32bppArgb);    // 読み込み元のビットマップデータのロック

                DataBox[] texture_data_box = new[] { new DataBox(lock_bitmap_data.Scan0, bitmap_data.Width * 4, bitmap_data.Height) };    // テクスチャデータ用のボックス

                Texture2DDescription texture_data_desc = new Texture2DDescription()    // テクスチャデータの設定
                {
                    Format = SharpDX.DXGI.Format.B8G8R8A8_UNorm,    // フォーマット
                    ArraySize = 1,  // 配列数
                    MipLevels = 1,  // ミップマップ数
                    Width = bitmap_data.Width,      // 幅
                    Height = bitmap_data.Height,    // 高さ
                    SampleDescription = new SharpDX.DXGI.SampleDescription(1, 0),   // サンプルの設定
                    Usage = ResourceUsage.Default,  // リソースの使用方法
                    BindFlags = BindFlags.ShaderResource,   // バインドフラグ
                    CpuAccessFlags = CpuAccessFlags.None,   // CPUアクセスフラグ
                    OptionFlags = ResourceOptionFlags.None, // オプションフラグ
                };

                Texture2D texture_data = new Texture2D(in_device, texture_data_desc, texture_data_box);    // 読み込み結果のテクスチャデータ


                // ロックしたビットマップデータの解放
                bitmap_data.UnlockBits(lock_bitmap_data);

                // テクスチャリソースを返す
                return texture_data;
            }
        }


        //-☆- セット -☆-//

        // ピクセルシェーダー用リソースにセットする　引数：セットするテクスチャのインデックス番号, デバイス、コンテキスト
        public void M_Set_Texture_To_Pixel_Shader(int in_index, Device in_device, DeviceContext in_device_context)
        {
            // テクスチャが生成されていない場合は生成する
            if (m_texture_view == null)
            {
                Load(in_device, m_name);
            }

            // テクスチャをセット
            in_device_context.PixelShader.SetShaderResource(in_index, m_texture_view);

            return;
        }
    }
}
