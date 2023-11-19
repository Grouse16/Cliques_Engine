using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {

        }

        private void TRACK_Depth_Value_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Value.Text = TRACK_Depth_Value.Value.ToString();
        }

        private void TRACK_Depth_Max_Value_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Max_Value.Text = (TRACK_Depth_Max_Value.Value / 100.0f).ToString();
        }

        private void TRACK_Depth_Slope_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Slope.Text = (TRACK_Depth_Slope.Value / 100.0f).ToString();
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void Track_Sampling_Count_Scroll(object sender, EventArgs e)
        {
            TB_Sampling_Count.Text = Track_Sampling_Count.Value.ToString();
        }

        private void Track_Sampling_Quality_Scroll(object sender, EventArgs e)
        {
            TB_Sampling_Quality.Text = Track_Sampling_Quality.Value.ToString();
        }

        private void Track_Ambient_Red_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Red.Text = (Track_Ambient_Red.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Green_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Green.Text = (Track_Ambient_Green.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Blue.Text = (Track_Ambient_Blue.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Alpha.Text = (Track_Ambient_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Red_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Red.Text = (Track_Diffuse_Red.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Green_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Green.Text = (Track_Diffuse_Green.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Blue.Text = (Track_Diffuse_Blue.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Alpha.Text = (Track_Diffuse_Alpha.Value / 100.0f).ToString();
        }
    }
}
