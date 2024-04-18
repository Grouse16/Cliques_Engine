using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // メイン関数実行用のクラス
    internal static class CS_Main_Program
    {
        // メイン関数
        [STAThread] static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Main_Form());
            Console.WriteLine(SharpDX.Diagnostics.ObjectTracker.ReportActiveObjects());
        }
    }
}
