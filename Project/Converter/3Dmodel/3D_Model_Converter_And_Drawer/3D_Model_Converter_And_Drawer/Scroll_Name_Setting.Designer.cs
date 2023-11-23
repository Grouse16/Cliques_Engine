using Assimp;
using System.Collections.Generic;
using System.Drawing;

namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    partial class Scroll_Name_Setting
    {
        // ☆ 定数 ☆ //
        const int con_X_LOCATION = 3;   // X座標での座標
        const int con_ONE_SPAN_Y = 23;  // Y座標でのUI一つ分の間隔


        // ☆ 変数宣言 ☆ //
        public List<Name_Setting> name_list = new List<Name_Setting>();

        string scroll_name = "default";


        /// <summary> 
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }
        

        // 名前の設定数をセット　引数：マテリアル設定数
        public void M_Set_Name_Sum(int in_mat_sum)
        {
            for(int now_mat_num = 0; now_mat_num < in_mat_sum; now_mat_num++)
            {
                Name_Setting new_mat_name_setting = new Name_Setting();   // あたらしいマテリアルネーム設定

                new_mat_name_setting.Location = new Point(con_X_LOCATION, con_ONE_SPAN_Y + con_ONE_SPAN_Y * now_mat_num);
                new_mat_name_setting.Size = new Size(449, 23);
                new_mat_name_setting.M_Set_Number_Prate(scroll_name + (now_mat_num + 1).ToString());


                new_mat_name_setting.M_Set_Name("default" + (now_mat_num + 1).ToString());

                name_list.Add(new_mat_name_setting);

                this.Controls.Add(new_mat_name_setting);
            }

            if (in_mat_sum > 3)
            {
                scroll_bar.Maximum = (in_mat_sum - 3) * con_ONE_SPAN_Y;
            }

            else
            {
                scroll_bar.Maximum = 1;
            }

            return;
        }

        // マテリアル名で名前を初期化する
        public void M_Set_Mat_Name()
        {
            for (int now_mat = 0; now_mat < name_list.Count; now_mat++)
            {
                name_list[now_mat].M_Set_Name(CS_3D_Model_Convert_System.m_now_scene.Materials[now_mat].Name);
            }

            return;
        }

        // メッシュ名で名前を初期化する
        public void M_Set_Mesh_Name()
        {
            for (int now_mesh = 0; now_mesh < name_list.Count; now_mesh++)
            {
                name_list[now_mesh].M_Set_Name(CS_3D_Model_Convert_System.m_now_scene.Meshes[now_mesh].Name);
            }

            return;
        }

        // スクロール値を受け取ってスクロールさせる　引数：スクロール値
        public void M_Set_Var_Scroll(int in_scroll_value)
        {
            for (int now_mat_num = 0; now_mat_num < name_list.Count; now_mat_num++)
            {
                name_list[now_mat_num].Location = new Point(con_X_LOCATION, con_ONE_SPAN_Y + con_ONE_SPAN_Y * now_mat_num - in_scroll_value);
            }

            return;
        }

        // スクロール枠名とテキストの基準名を設定
        public void M_Set_Frame_Name(string scroll_frame_name, string in_scroll_text_name)
        {
            textBox1.Text = scroll_frame_name;
            scroll_name = in_scroll_text_name;
        }

        #region コンポーネント デザイナーで生成されたコード

        /// <summary> 
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を 
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.scroll_bar = new System.Windows.Forms.VScrollBar();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(636, 22);
            this.textBox1.TabIndex = 0;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // scroll_bar
            // 
            this.scroll_bar.Location = new System.Drawing.Point(608, 22);
            this.scroll_bar.Maximum = 10;
            this.scroll_bar.Name = "scroll_bar";
            this.scroll_bar.Size = new System.Drawing.Size(23, 108);
            this.scroll_bar.TabIndex = 1;
            this.scroll_bar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar1_Scroll);
            // 
            // Scroll_Name_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.scroll_bar);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Scroll_Name_Setting";
            this.Size = new System.Drawing.Size(637, 130);
            this.Load += new System.EventHandler(this.Scroll_Name_Setting_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.VScrollBar scroll_bar;
    }
}
