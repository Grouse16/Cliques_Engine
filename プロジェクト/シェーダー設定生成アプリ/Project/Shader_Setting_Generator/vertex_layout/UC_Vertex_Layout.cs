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

        // 頂点レイアウトの変数情報の数を返す　戻り値：頂点レイアウトの変数の数
        public int M_Get_Vertex_Instance_Sum()
        {
            return (int)NB_Vertex_Layout_Sum.Value;
        }

        // 頂点の変数のリストを返す　戻り値：頂点の変数のリスト
        public List<UC_Vertex_Setting> M_Get_Vertex_Layout_List()
        {
            return uC_Vertex_Setting_List1.M_Get_Vertex_Layout_List();
        }
    }
}
