using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // カラー変換用のクラス
    static class CS_Color_Extensions
    {
        // SharpDXのカラーをfloat4のカラーに変換　
        public static System.Drawing.Color M_SharpDX_Color_To_Float4_Color(this Color4 src)
        {
            return System.Drawing.Color.FromArgb
                (
                    (byte)(src.Alpha * 255),
                    (byte)(src.Red * 255),
                    (byte)(src.Green * 255),
                    (byte)(src.Blue * 255)
                );
        }


        // float4のカラーをSharpDXのカラーに変換
        public static Color4 M_Float4_Color_To_SharpDX_Color(this System.Drawing.Color value)
        {
            return new Color4
                (
                    value.R / 255.0f,
                    value.G / 255.0f,
                    value.B / 255.0f,
                    value.A / 255.0f
                );
        }
    }
}
