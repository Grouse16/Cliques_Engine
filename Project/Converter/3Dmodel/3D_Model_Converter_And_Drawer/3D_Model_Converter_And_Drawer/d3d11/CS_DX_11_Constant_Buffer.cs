using SharpDX;
using SharpDX.Direct3D11;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ クラス ☆ //

    // DirectX11の定数バッファを使用するための抽象レイヤーのクラス
    public abstract class CS_DX_11_Constant_Buffer_Handle : System.IDisposable
    {
        // ☆ 関数 ☆ //

        //-☆- 削除 -☆-//

        // メモリの解放を行う
        abstract public void Dispose();


        //-☆- ゲッタ -☆-//

        // 定数バッファを返す　戻り値：定数バッファ
        abstract public SharpDX.Direct3D11.Buffer M_Get_Constant_Buffer();


        //-☆- 生成 -☆-//

        // 定数バッファの生成を行う　引数：デバイス, 定数バッファの配列数
        abstract public void M_Create_Constant_Buffer(Device in_device, int in_constant_buffer_array_sum);


        //-☆- 描画 -☆-//

        // 頂点シェーダー用リソースにセットする　引数：デバイス、コンテキスト, セットする定数バッファのインデックス番号
        abstract public void M_Set_Constant_Buffer_To_Vertex_Shader(int in_index, Device in_device, DeviceContext in_device_context);

        // ピクセルシェーダー用リソースにセットする　引数：デバイス、コンテキスト, セットする定数バッファのインデックス番号
        abstract public void M_Set_Constant_Buffer_To_Pixel_Shader(int in_index, Device in_device, DeviceContext in_device_context);
    }


    // DirectX11の定数バッファのクラス
    public class CS_DX_11_Constant_Buffer<S_Constant_Data_Format> : CS_DX_11_Constant_Buffer_Handle where S_Constant_Data_Format : struct
    {
        // ☆ 定数 ☆ //
        public const int con_CONSTANT_BUFFER_BYTE_SUM = 256;  // 定数バッファのバイト数


        // ☆ 変数宣言 ☆ //
        private SharpDX.Direct3D11.Buffer m_buffer = null; // 定数バッファ

        List<S_Constant_Data_Format> m_constant_data_list = new List<S_Constant_Data_Format>(); // 定数バッファに書き込むデータのリスト


        // ☆ プロパティ ☆ //

        // 定数バッファ
        public SharpDX.Direct3D11.Buffer mp_buffer
        {
            // ゲッタ
            get
            {
                return m_buffer;
            }

            // セッタ
            set
            {
                m_buffer = value;
            }
        }

        // 定数バッファに書き込むデータのリスト
        public List<S_Constant_Data_Format> mp_constant_data_list
        {
            // ゲッタ
            get
            {
                return m_constant_data_list;
            }

            // セッタ
            set
            {
                m_constant_data_list = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化と解放 -☆-//

        // コンストラクタ
        public CS_DX_11_Constant_Buffer()
        {
            return;
        }


        // デストラクタ
        ~CS_DX_11_Constant_Buffer()
        {
            Dispose();

            return;
        }


        // メモリの解消の実行
        public override void Dispose()
        {
            if (m_buffer != null)
            {
                m_buffer.Dispose();
                m_buffer = null;
            }

            return;
        }


        //-☆- 描画 -☆-//

        // 頂点シェーダー用リソースにセットする　引数：セット先の定数バッファのインデックス番号, デバイス、コンテキスト
        public override void M_Set_Constant_Buffer_To_Vertex_Shader(int in_index, Device in_device, DeviceContext in_device_context)
        {
            // 定数バッファにデータを書き込む
            M_Write_Data_To_Constant_Buffer(in_device_context);

            // 定数バッファをセット
            in_device_context.VertexShader.SetConstantBuffer(in_index, m_buffer);

            return;
        }


        // ピクセルシェーダー用リソースにセットする　引数：セットする定数バッファのインデックス番号, デバイス、コンテキスト
        public override void M_Set_Constant_Buffer_To_Pixel_Shader(int in_index, Device in_device, DeviceContext in_device_context)
        {
            // 定数バッファにデータを書き込む
            M_Write_Data_To_Constant_Buffer(in_device_context);

            // 定数バッファをセット
            in_device_context.PixelShader.SetConstantBuffer(in_index, m_buffer);

            return;
        }


        //-☆- 生成 -☆-//

        // 定数バッファを生成する　引数：デバイスの参照, 定数バッファの配列数
        public unsafe override void M_Create_Constant_Buffer(Device in_device, int in_buffer_array_sum)
        {
            m_buffer = new SharpDX.Direct3D11.Buffer(in_device, new BufferDescription()
            {
                Usage = ResourceUsage.Dynamic,
                SizeInBytes = in_buffer_array_sum * con_CONSTANT_BUFFER_BYTE_SUM,
                BindFlags = BindFlags.ConstantBuffer,
                CpuAccessFlags = CpuAccessFlags.Write,
                OptionFlags = ResourceOptionFlags.None,
                StructureByteStride = sizeof(S_Constant_Data_Format)
            });


            // データの数が定数バッファの配列数と一致していないときは、不足分の配列を生成する
            while (m_constant_data_list.Count < in_buffer_array_sum)
            {
                m_constant_data_list.Add(new S_Constant_Data_Format());
            }

            return;
        }


        //-☆- 書き込み -☆-//

        // 定数バッファにデータをセット　引数：デバイスコンテキストの参照, 書き込むデータの配列, 書き込むデータのサイズ数
        public void M_Write_Data_To_Constant_Buffer(DeviceContext in_device_context)
        {
            // 定数バッファが生成されていない場合は生成する
            if (m_buffer == null)
            {
                M_Create_Constant_Buffer(in_device_context.Device, m_constant_data_list.Count);
            }


            // ☆ 変数宣言 ☆ //
            DataStream data_stream = null;  // 定数バッファのデータストリーム


            // 定数バッファのデータを取得
            in_device_context.MapSubresource(m_buffer, MapMode.WriteDiscard, SharpDX.Direct3D11.MapFlags.None, out data_stream);
            
            // 定数バッファにデータを書き込む
            data_stream.WriteRange(m_constant_data_list.ToArray());

            // 定数バッファのデータを解放
            in_device_context.UnmapSubresource(m_buffer, 0);
            data_stream = null;

            return;
        }


        //-☆- ゲッタ -☆-//

        // 定数バッファを返す　戻り値：定数バッファ
        public override SharpDX.Direct3D11.Buffer M_Get_Constant_Buffer()
        {
            return m_buffer;
        }
    }
}


