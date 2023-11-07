using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer
{
    internal class My_Math_System
    {
        // 渡された絶対パスを、自ファイルからの相対パスに変換する
        static public string M_Get_Relative_Path(string in_path)
        {
            // ☆ 変数宣言 ☆ //
            Uri uri_base_path = new Uri(System.Reflection.Assembly.GetExecutingAssembly().Location);    // 基本となる相対元のパス
            Uri uri_relative_check_path = new Uri(in_path);                                             // 相対パスに変換したいシステムのパス
            Uri uri_relative_path = uri_base_path.MakeRelativeUri(uri_relative_check_path);             // 絶対Uriから相対Uriを取得する

            return uri_relative_path.ToString();   // 相対パス
        }
    }
}
