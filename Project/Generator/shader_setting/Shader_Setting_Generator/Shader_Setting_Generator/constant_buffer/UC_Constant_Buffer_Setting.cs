using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator
{
    public partial class UC_Constant_Buffer_Setting : UserControl
    {
        // ☆ 変数宣言 ☆ //
        public C_Constant_Buffer_Inform constant_buffer_inform = new C_Constant_Buffer_Inform("default", 1, false);    // 定数バッファ情報


        // ☆ 関数 ☆ //

        public UC_Constant_Buffer_Setting()
        {
            InitializeComponent();
        }

        private void UC_Constant_Buffer_Setting_Load(object sender, EventArgs e)
        {

        }
    }
}
