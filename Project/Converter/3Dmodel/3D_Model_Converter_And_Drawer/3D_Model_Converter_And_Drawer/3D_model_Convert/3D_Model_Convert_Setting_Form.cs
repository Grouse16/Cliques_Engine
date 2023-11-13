using _3D_Model_Converter_And_Drawer._3Dmodel_Convert;
using Assimp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer
{
    public partial class Form_3D_Model_Convert_Setting : Form
    {
        public static int material_num = 0;
        public static int mesh_num = 0;

        public static List<string> material_name_list = new List<string>();
        public static List<string> mesh_group_name_list = new List<string>();

        public Form_3D_Model_Convert_Setting()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            scroll_material_name_setting.M_Set_Frame_Name("マテリアル名の設定", "Material ");
            scroll_material_name_setting.M_Set_Name_Sum(material_num);
            scroll_material_name_setting.M_Set_Mat_Name();

            scroll_mesh_groop_name.M_Set_Frame_Name("メッシュグループ名の設定", "Mesh Group ");
            scroll_mesh_groop_name.M_Set_Name_Sum(mesh_num);
            scroll_mesh_groop_name.M_Set_Mesh_Name();

            this.MaximumSize = this.Size;
            this.MinimumSize = this.Size;
        }

        private void scroll_Material1_Load(object sender, EventArgs e)
        {

        }

        private void generate_button_Click(object sender, EventArgs e)
        {
            material_name_list.Clear();
            for (int now_mat_num = 0; now_mat_num < material_num; now_mat_num++)
            {
                material_name_list.Add(scroll_material_name_setting.name_list[now_mat_num].M_Get_Name());
            }

            mesh_group_name_list.Clear();
            for (int now_mat_num = 0; now_mat_num < material_num; now_mat_num++)
            {
                mesh_group_name_list.Add(scroll_mesh_groop_name.name_list[now_mat_num].M_Get_Name());
            }

            CS_3D_Model_Convert_System.M_Model_Covert_Execute();

            this.Close();
        }

        private void exit_button_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
