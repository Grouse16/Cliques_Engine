using _3D_Model_Converter_And_Drawer._3Dmodel_Convert;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    public partial class Scroll_Name_Setting : UserControl
    {
        public Scroll_Name_Setting()
        {
            InitializeComponent();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }


        // バーがスクロールしたとき
        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            M_Set_Var_Scroll(e.NewValue);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Scroll_Name_Setting_Load(object sender, EventArgs e)
        {

        }
    }
}
