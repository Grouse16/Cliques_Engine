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
    public partial class UC_Vertex_Setting : UserControl
    {
        public UC_Vertex_Setting()
        {
            InitializeComponent();
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        // 現在の頂点レイアウト番号を設定　引数：頂点レイアウト番号
        public void M_Set_Vertex_Layout_Number(int in_vertex_layout_num)
        {
            TB_Number.Text = in_vertex_layout_num.ToString();
        }

        private void CB_Byte_Format_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void UC_Vertex_Setting_Load(object sender, EventArgs e)
        {
            CB_Byte_Format.SelectedIndex = 2;
            CB_Type_Format.SelectedIndex = 2;
            CB_Element.SelectedIndex = 3;
        }

        private void CB_Type_Format_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
