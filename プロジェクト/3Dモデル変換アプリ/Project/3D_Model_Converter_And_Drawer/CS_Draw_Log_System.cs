using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // ログ出力用のクラス
    public class CS_Draw_Log_System
    {
        // ログを出力する　引数：ログの内容
        public static void M_Draw_Log(string in_log)
        {
#if DEBUG
            Console.WriteLine(in_log);
#endif

            return;
        }
    }
}
