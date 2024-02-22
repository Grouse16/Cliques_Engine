using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ELMaterial_Generator
{
    // ☆ 構造体 ☆ //

    // 質感情報のデータの構造体
    public struct S_Mesh_Material_Data
    {
        // ☆ 変数宣言 ☆ //
        private S_RGBA_Data ambient_data;       // アンビエントデータ
        private S_RGBA_Data diffuse_data;       // ディフューズデータ
        private S_RGBA_Data emission_data;      // エミッションデータ
        private S_RGBA_Data reflection_data;    // リフレクションデータ
        private S_RGBA_Data specular_data;      // スペキュラデータ
        private S_RGBA_Data transparent_data;   // トランスペアレントデータ


        // ☆ プロパティ ☆ //

        // アンビエントデータ
        public S_RGBA_Data mp_ambient_data
        {
            // ゲッタ
            get
            {
                return ambient_data;
            }

            // セッタ
            set
            {
                ambient_data = value;
            }
        }


        // ディフューズデータ
        public S_RGBA_Data mp_diffuse_data
        {
            // ゲッタ
            get
            {
                return diffuse_data;
            }

            // セッタ
            set
            {
                diffuse_data = value;
            }
        }


        // エミッションデータ
        public S_RGBA_Data mp_emission_data
        {
            // ゲッタ
            get
            {
                return emission_data;
            }

            // セッタ
            set
            {
                emission_data = value;
            }
        }


        // リフレクションデータ
        public S_RGBA_Data mp_reflection_data
        {
            // ゲッタ
            get
            {
                return reflection_data;
            }

            // セッタ
            set
            {
                reflection_data = value;
            }
        }


        // スペキュラデータ
        public S_RGBA_Data mp_specular_data
        {
            // ゲッタ
            get
            {
                return specular_data;
            }

            // セッタ
            set
            {
                specular_data = value;
            }
        }


        // トランスペアレントデータ
        public S_RGBA_Data mp_transparent_data
        {
            // ゲッタ
            get
            {
                return transparent_data;
            }

            // セッタ
            set
            {
                transparent_data = value;
            }
        }
    }
}
