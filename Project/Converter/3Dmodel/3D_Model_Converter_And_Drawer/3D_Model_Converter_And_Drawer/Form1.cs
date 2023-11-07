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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        // フォーム読み込み時
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.ReadOnly = true;
            textBox2.ReadOnly = true;
            textBox3.ReadOnly = true;
            textBox4.ReadOnly = true;
            textBox5.ReadOnly = true;
            textBox6.ReadOnly = true;
            textBox7.ReadOnly = true;
            textBox8.ReadOnly = true;
            textBox9.ReadOnly = true;
            textBox10.ReadOnly = true;
            textBox11.ReadOnly = true;
            textBox12.ReadOnly = true;
            textBox13.ReadOnly = true;
            textBox14.ReadOnly = true;
            textBox15.ReadOnly = true;
            textBox16.ReadOnly = true;
            textBox17.ReadOnly = true;
            TB_after_convert_path.ReadOnly = true;
            TB_before_convert_path.ReadOnly = true;

            this.MaximumSize = this.Size;
            this.MinimumSize = this.Size;
        }


        // ドラッグがカーソル上にあるとき
        private void B_Drag_Over_File_Checker(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はカーソルをコピーに変更
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }

            // それ以外の時はなにもしない
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }


    }
}
