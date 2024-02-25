using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3DModel.Material
{
    // ☆ クラス ☆ //

    // 質感データのクラス
    public class CS_Material_Data
    {
        // ☆ 変数宣言 ☆ //
        private string m_name = ""; // 質感名

        private Vector4 m_ambient = new Vector4(); // アンビエントカラー
        private Vector4 m_diffuse = new Vector4(); // ディフューズカラー
        private Vector4 m_emissive = new Vector4();    // エミッシブカラー
        private Vector4 m_refraction = new Vector4();  // リフレクションカラー
        private Vector4 m_specular = new Vector4();    // スペキュラカラー
        private Vector4 m_transparent = new Vector4(); // トランスペアレントカラー


        // ☆ プロパティ ☆ //

        // 質感名
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

        // アンビエントカラー
        public Vector4 mp_ambient
        {
            // ゲッタ
            get
            {
                return m_ambient;
            }

            // セッタ
            set
            {
                m_ambient = value;
            }
        }

        // ディフューズカラー
        public Vector4 mp_diffuse
        {
            // ゲッタ
            get
            {
                return m_diffuse;
            }

            // セッタ
            set
            {
                m_diffuse = value;
            }
        }

        // エミッシブカラー
        public Vector4   mp_emissive
        {
            // ゲッタ
            get
            {
                return m_emissive;
            }

            // セッタ
            set
            {
                m_emissive = value;
            }
        }

        // リフレクションカラー
        public Vector4 mp_refraction
        {
            // ゲッタ
            get
            {
                return m_refraction;
            }

            // セッタ
            set
            {
                m_refraction = value;
            }
        }

        // スペキュラカラー
        public Vector4 mp_specular
        {
            // ゲッタ
            get
            {
                return m_specular;
            }

            // セッタ
            set
            {
                m_specular = value;
            }
        }

        // トランスペアレントカラー
        public Vector4 mp_transparent
        {
            // ゲッタ
            get
            {
                return m_transparent;
            }

            // セッタ
            set
            {
                m_transparent = value;
            }
        }
    }
}
