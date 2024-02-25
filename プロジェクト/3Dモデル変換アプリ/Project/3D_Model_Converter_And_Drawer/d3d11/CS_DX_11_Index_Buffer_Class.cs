using SharpDX.Direct3D11;
using SharpDX.DXGI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ クラス ☆ //

    // インデックスバッファを管理するクラス
    public class CS_DX_11_Index_Buffer_Class
    {
        // ☆ 変数宣言 ☆ //
        private List<uint> m_index_data = new List<uint>();    // インデックスデータ

        SharpDX.Direct3D11.Buffer m_index_buffer;  // インデックスバッファ


        // ☆ プロパティ ☆ //

        // インデックスデータ
        public List<uint> mp_index_data
        {
            get { return m_index_data; }
        }

        // インデックスバッファ
        public SharpDX.Direct3D11.Buffer mp_index_buffer
        {
            get { return m_index_buffer; }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public CS_DX_11_Index_Buffer_Class()
        {
            m_index_data.Add(0);
            m_index_data.Add(1);
            m_index_data.Add(2);

            return;
        }


        //-☆- 削除 -☆-//

        // 削除の実行
        internal void Dispose()
        {
            if (m_index_data != null)
            {
                m_index_data = null;
            }

            if (m_index_buffer != null)
            {
                m_index_buffer.Dispose();
                m_index_buffer = null;
            }

            return;
        }


        //-☆- 生成 -☆-//

        // インデックスバッファを生成する　引数：デバイス, デバイスコンテキスト
        public void M_Create_Index_Buffer(SharpDX.Direct3D11.Device in_device, DeviceContext in_device_context)
        {
            // ☆ 変数宣言 ☆ //
            BufferDescription index_buffer_desc = new BufferDescription    // インデックスバッファ
            {
                Usage = ResourceUsage.Default,
                BindFlags = BindFlags.IndexBuffer,
                CpuAccessFlags = CpuAccessFlags.None,
                OptionFlags = ResourceOptionFlags.None,
                SizeInBytes = sizeof(uint) * m_index_data.Count,
                StructureByteStride = sizeof(uint)
            };


            // バッファを初期化
            if (m_index_buffer != null)
            {
                m_index_buffer.Dispose();
                m_index_buffer = null;
            }

            // インデックスバッファ生成
            this.m_index_buffer = new SharpDX.Direct3D11.Buffer(in_device, index_buffer_desc);

            // バッファに値をセット
            in_device_context.UpdateSubresource(m_index_data.ToArray(), m_index_buffer);

            return;
        }


        //-☆- 描画 -☆-//

        // デバイスコンテキストにインデックスバッファをセットする　引数：デバイス, デバイスコンテキスト
        public void M_Set_Index_Buffer(SharpDX.Direct3D11.Device in_device, DeviceContext in_device_context)
        {
            // インデックスデータが消えていたら初期化
            if (m_index_data == null)
            {
                m_index_data.Add(0);
                m_index_data.Add(1);
                m_index_data.Add(2);
            }


            // インデックスバッファが生成されていなければ生成する
            if (m_index_buffer == null)
            {
                M_Create_Index_Buffer(in_device, in_device_context);
            }

            in_device_context.InputAssembler.SetIndexBuffer(this.m_index_buffer, Format.R32_UInt, 0);

            return;
        }
    }
}
