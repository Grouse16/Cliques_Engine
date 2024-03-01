using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer.UI.Announce_Bord
{
    // ☆ クラス ☆ //

    // 告知用ボード表示用のフォーム
    public partial class Form_Announce_Bord : Form
    {
        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public Form_Announce_Bord()
        {
            InitializeComponent();

            return;
        }


        //-☆- セッタ -☆-//

        // 告知する文字列を設定する　引数：設定する文字列
        public void M_Set_Announce_Text(string in_set_text)
        {
            TB_announce_text.Text = in_set_text;

            this.Refresh();

            return;
        }
    }
}
