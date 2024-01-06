using SharpDXSample;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ 構造体 ☆ //

    // 定数バッファの描画設定用の情報の構造体
    public struct S_DX_11_Constant_Buffer_Draw_Setting
    {
        // ☆ 変数宣言 ☆ //
        private CS_DX_11_Constant_Buffer_Handle constant_buffer_handle;  // 設定する定数バッファのハンドル

        private E_DX_11_SHADER_TYPE attach_shader_type;  // 設定先のシェーダーの種類

        private int shader_slot;  // バッファのスロット番号


        // ☆ プロパティ ☆ //

        // 設定する定数バッファのハンドル
        public CS_DX_11_Constant_Buffer_Handle mp_constant_buffer_handle
        {
            // ゲッタ
            get
            {
                return constant_buffer_handle;
            }

            // セッタ
            set
            {
                constant_buffer_handle = value;
            }
        }

        // 設定先のシェーダーの種類
        public E_DX_11_SHADER_TYPE mp_attach_shader_type
        {
            // ゲッタ
            get
            {
                return attach_shader_type;
            }

            // セッタ
            set
            {
                attach_shader_type = value;
            }
        }

        // バッファのスロット番号
        public int mp_set_slot
        {
            // ゲッタ
            get
            {
                return shader_slot;
            }

            // セッタ
            set
            {
                shader_slot = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ　引数：設定する定数バッファ, 設定先のシェーダーの種類, 設定先のスロット番号
        public S_DX_11_Constant_Buffer_Draw_Setting(CS_DX_11_Constant_Buffer_Handle in_set_constant_buffer, E_DX_11_SHADER_TYPE in_set_shader_type, int in_set_shader_slot)
        {
            constant_buffer_handle = in_set_constant_buffer;

            attach_shader_type = in_set_shader_type;

            shader_slot = in_set_shader_slot;

            return;
        }
    }



    // テクスチャリソースの描画設定用の情報の構造体
    public struct S_DX11_Texture_Draw_Setting
    {
        // ☆ 変数宣言 ☆ //
        private CS_DX_11_Texture use_texture;  // 設定するテクスチャ

        private E_DX_11_SHADER_TYPE attach_shader_type;  // 設定先のシェーダーの種類

        private int shader_slot;  // バッファのスロット番号


        // ☆ プロパティ ☆ //

        // 設定するテクスチャ
        public CS_DX_11_Texture mp_texture
        {
            // ゲッタ
            get
            {
                return use_texture;
            }

            // セッタ
            set
            {
                use_texture = value;
            }
        }

        // 設定先のシェーダーの種類
        public E_DX_11_SHADER_TYPE mp_attach_shader_type
        {
            // ゲッタ
            get
            {
                return attach_shader_type;
            }

            // セッタ
            set
            {
                attach_shader_type = value;
            }
        }

        // バッファのスロット番号
        public int mp_set_slot
        {
            // ゲッタ
            get
            {
                return shader_slot;
            }

            // セッタ
            set
            {
                shader_slot = value;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ　引数：設定するテクスチャ, 設定先のシェーダーの種類, 設定先のスロット番号
        public S_DX11_Texture_Draw_Setting(CS_DX_11_Texture in_set_texture, E_DX_11_SHADER_TYPE in_set_shader_type, int in_set_shader_slot)
        {
            use_texture = in_set_texture;

            attach_shader_type = in_set_shader_type;

            shader_slot = in_set_shader_slot;

            return;
        }
    }


    // ☆ クラス ☆ //

    // 描画実行用のシステムのクラス
    public class CS_DX_11_Draw_Call_System
    {
        // ☆ 変数宣言 ☆ //
        private CS_DX_11_Vertex_Buffer_Handler m_vertex_buffer = null;  // 頂点バッファ

        private List<CS_DX11_Mesh_Data> m_mesh_data = new List<CS_DX11_Mesh_Data>();    // メッシュデータのリスト


        // ☆ プロパティ ☆ //

        // 頂点バッファ
        public CS_DX_11_Vertex_Buffer_Handler mp_vertex_buffer
        {
            // ゲッタ
            get
            {
                return m_vertex_buffer;
            }

            // セッタ
            set
            {
                m_vertex_buffer = value;
            }
        }

        // メッシュデータのリスト
        public List<CS_DX11_Mesh_Data> mp_mesh_data_list
        {
            // ゲッタ
            get
            {
                return m_mesh_data;
            }

            // セッタ
            set
            {
                m_mesh_data = value;
            }
        }
    }


    // メッシュの描画処理を指定するクラス
    public class CS_DX11_Mesh_Data
    {
        // ☆ 変数宣言 ☆ //
        private CS_DX_11_Index_Buffer_Class m_index_data = new CS_DX_11_Index_Buffer_Class();  // 頂点インデックスバッファ

        private List<S_DX_11_Constant_Buffer_Draw_Setting> m_constant_buffer_set_list = new List<S_DX_11_Constant_Buffer_Draw_Setting>();   // 定数バッファの描画設定のリスト

        private List<S_DX11_Texture_Draw_Setting> m_texture_set_list = new List<S_DX11_Texture_Draw_Setting>(); // テクスチャの描画設定のリスト


        // ☆ プロパティ ☆ //

        // 頂点インデックスバッファ
        public CS_DX_11_Index_Buffer_Class mp_vertex_index
        {
            // ゲッタ
            get
            {
                return m_index_data;
            }

            // セッタ
            set
            {
                m_index_data = value;
            }
        }

        // 定数バッファの描画設定のリスト
        public List<S_DX_11_Constant_Buffer_Draw_Setting> mp_constant_buffer_set_list
        {
            // ゲッタ
            get
            {
                return m_constant_buffer_set_list;
            }

            // セッタ
            set
            {
                m_constant_buffer_set_list = value;
            }
        }

        // テクスチャの描画設定のリスト
        public List<S_DX11_Texture_Draw_Setting> mp_texture_set_list
        {
            // ゲッタ
            get
            {
                return m_texture_set_list;
            }

            // セッタ
            set
            {
                m_texture_set_list = value;
            }
        }
    }
}
