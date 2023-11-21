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
    public partial class Name_Setting : UserControl
    {
        public Name_Setting()
        {
            InitializeComponent();
            TB_material_number.ReadOnly = true;
        }

        public void M_Set_Number_Prate(string in_number)
        {
            TB_material_number.Text = in_number;
        }

        public void M_Set_Name(string in_name)
        {
            TB_material_name.Text = in_name;
        }

        public string M_Get_Name()
        {
            return TB_material_name.Text;
        }

        private void TB_material_number_TextChanged(object sender, EventArgs e)
        {

        }

        private void TB_material_name_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
