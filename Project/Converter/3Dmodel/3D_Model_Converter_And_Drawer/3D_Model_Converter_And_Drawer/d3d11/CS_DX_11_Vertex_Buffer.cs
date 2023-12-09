using SharpDX.Direct3D11;
using System.Runtime.InteropServices;
using SharpDX;
using System;
using SharpDX.Direct3D;

namespace SharpDXSample
{
    // ☆ 構造体 ☆ //

    // 頂点の情報の構造体
    public struct S_Vertex
    {
        // ☆ 変数宣言 ☆ //
        public Vector4 m_position;  // 位置

        public Vector4 m_color; // 色

        public Vector4 m_normal;    // 法線


        // ☆ プロパティ ☆ //

        // 位置ｘ
        public float mp_position_x
        {
            // ゲッタ
            get { return m_position.X; } 
        }

        // 位置ｙ
        public float mp_position_y 
        {
            // ゲッタ
            get { return m_position.Y; }
        }

        // 位置ｚ
        public float mp_position_z 
        { 
            // ゲッタ
            get { return m_position.Z; }
        }


        // 色R
        public float mp_color_r 
        {
            // ゲッタ
            get { return m_color.X; }
        }

        // 色G
        public float mp_color_g 
        {
            // ゲッタ
            get { return m_color.Y; }
        }

        // 色B
        public float mp_color_b
        {
            // ゲッタ
            get { return m_color.Z; }
        }

        // 色A
        public float mp_color_a
        {
            // ゲッタ
            get { return m_color.W; }
        }


        // 法線ｘ
        public float mp_normal_x
        {
            // ゲッタ
            get { return m_normal.X; }
        }

        // 法線ｙ
        public float mp_normal_y
        {
            // ゲッタ
            get { return m_normal.Y; }
        }

        // 法線ｚ
        public float mp_normal_z
        {
            // ゲッタ
            get { return m_normal.Z; }
        }

        // 法線ｗ
        public float mp_normal_w
        {
            // ゲッタ
            get { return m_normal.W; }
        }


        // ☆ 関数 ☆ //

        // コンストラクタ　引数：位置、色、法線
        public S_Vertex(Vector4 in_set_position, Vector4 in_set_color, Vector4 in_set_normal)
        {
            m_position = in_set_position;
            m_color = in_set_color;
            m_normal = in_set_normal;

            return;
        }


        // 文字列に変換
        public override string ToString()
        {
            return $"({m_position.X}, {m_position.Y}, {m_position.Z})({m_color.X}, {m_color.Y}, {m_color.Z}, {m_color.W})({m_normal.X}, {m_normal.Y}, {m_normal.Z}, {m_normal.W})";
        }
    }


    // ☆ クラス ☆ //

    // 頂点バッファを管理するクラス
    public class CS_DX_11_Vertex_Buffer : System.IDisposable
    {
        // ☆ スタティック変数 ☆ //
        static int s_stride = Marshal.SizeOf<S_Vertex>();


        // ☆ 変数宣言 ☆ //
        S_Vertex[] m_vertex_data;   // 頂点データ

        SharpDX.Direct3D11.Buffer m_vertex_buffer;  // 頂点バッファ


        // ☆ プロパティ ☆ //

        // 頂点データ
        public S_Vertex[] mp_vertex_data
        {
            // ゲッタ
            get { return m_vertex_data; }

            // セッタ
            set { M_Set_Vertex(value); }
        }

        // 頂点バッファ
        public SharpDX.Direct3D11.Buffer mp_vertex_buffer
        {
            // ゲッタ
            get { return m_vertex_buffer; }
        }


        // ☆ 関数 ☆ //

        //-☆- 削除 -☆-//

        // メモリの解放を行う
        public void Dispose()
        {
            if(m_vertex_buffer != null)
            {
                m_vertex_buffer.Dispose();
                m_vertex_buffer = null;
            }

            if (m_vertex_buffer != null)
            {
                m_vertex_buffer.Dispose();
                m_vertex_buffer = null;
            }

            return;
        }


        //-☆- セッタ -☆-//

        // 頂点データを設定する　引数：頂点データ
        public void M_Set_Vertex(S_Vertex[] vertices)
        {
            Dispose();
            m_vertex_data = vertices;

            return;
        }


        //-☆- 生成 -☆-//

        // リソースの生成を行う　引数：デバイス
        void M_Create_Vertex_Buffer(Device in_device)
        {
            // 頂点データが存在しない場合は生成しない
            if (m_vertex_data != null)
            {
                Console.WriteLine("create bufer");
                m_vertex_buffer = SharpDX.Direct3D11.Buffer.Create(in_device, BindFlags.VertexBuffer, m_vertex_data);
            }
        
            return;
        }

        
        //-☆- 描画 -☆-//

        // 描画を行う　引数：デバイス、コンテキスト
        public void M_Set_Vertex_Buffer(Device in_device, DeviceContext in_context)
        {
            // 頂点バッファ未生成の場合は生成する
            if (m_vertex_buffer == null)
            {
                M_Create_Vertex_Buffer(in_device);
            }

            // 頂点バッファの設定
            if (m_vertex_buffer != null)
            {
                in_context.InputAssembler.PrimitiveTopology = PrimitiveTopology.TriangleList;
                in_context.InputAssembler.SetVertexBuffers(0, new VertexBufferBinding(m_vertex_buffer, s_stride, 0));
            }

            return;
        }
    }
}
