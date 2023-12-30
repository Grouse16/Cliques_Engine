using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.d3d11
{
    // ☆ 列挙 ☆ //

    // シェーダーの種類を指定する列挙
    public enum E_DX11_SHADER_TYPE
    {
        e_VERTEX_SHADER,    // 頂点シェーダー
        e_HULL_SHADER,      // ハルシェーダー
        e_DOMAIN_SHADER,    // ドメインシェーダー
        e_GEOMETRY_SHADER,  // ジオメトリシェーダー
        e_PIXEL_SHADER,     // ピクセルシェーダー
    }
}
