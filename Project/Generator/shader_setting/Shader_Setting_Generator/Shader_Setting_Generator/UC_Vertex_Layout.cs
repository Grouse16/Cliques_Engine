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
    public partial class UC_Vertex_Layout : UserControl
    {
        public UC_Vertex_Layout()
        {
            InitializeComponent();
        }

        // 頂点レイアウト数の変更
        private void NB_Vertex_Layout_Sum_ValueChanged(object sender, EventArgs e)
        {
            uC_Vertex_Setting_List1.M_Set_Vertex_Layout_Sum(((int)NB_Vertex_Layout_Sum.Value));
        }

        private void uC_Vertex_Setting_List1_Load(object sender, EventArgs e)
        {

        }

        private void B_Reset_MouseUp(object sender, MouseEventArgs e)
        {
            NB_Vertex_Layout_Sum.Value = 1;

            uC_Vertex_Setting_List1.M_Reset();
        }
    }
}
