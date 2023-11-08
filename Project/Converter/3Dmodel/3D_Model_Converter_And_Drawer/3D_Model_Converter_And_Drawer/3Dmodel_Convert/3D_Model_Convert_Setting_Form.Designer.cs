namespace _3D_Model_Converter_And_Drawer
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.scroll_material_name_setting = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.Scroll_Name_Setting();
            this.scroll_mesh_groop_name = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.Scroll_Name_Setting();
            this.exit_button = new System.Windows.Forms.Button();
            this.generate_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // scroll_material_name_setting
            // 
            this.scroll_material_name_setting.Location = new System.Drawing.Point(27, 12);
            this.scroll_material_name_setting.Name = "scroll_material_name_setting";
            this.scroll_material_name_setting.Size = new System.Drawing.Size(478, 104);
            this.scroll_material_name_setting.TabIndex = 0;
            this.scroll_material_name_setting.Load += new System.EventHandler(this.scroll_Material1_Load);
            // 
            // scroll_mesh_groop_name
            // 
            this.scroll_mesh_groop_name.Location = new System.Drawing.Point(27, 122);
            this.scroll_mesh_groop_name.Name = "scroll_mesh_groop_name";
            this.scroll_mesh_groop_name.Size = new System.Drawing.Size(478, 104);
            this.scroll_mesh_groop_name.TabIndex = 0;
            this.scroll_mesh_groop_name.Load += new System.EventHandler(this.scroll_Material1_Load);
            // 
            // exit_button
            // 
            this.exit_button.Location = new System.Drawing.Point(12, 390);
            this.exit_button.Name = "exit_button";
            this.exit_button.Size = new System.Drawing.Size(75, 23);
            this.exit_button.TabIndex = 1;
            this.exit_button.Text = "exit";
            this.exit_button.UseVisualStyleBackColor = true;
            this.exit_button.Click += new System.EventHandler(this.exit_button_Click);
            // 
            // generate_button
            // 
            this.generate_button.Location = new System.Drawing.Point(430, 390);
            this.generate_button.Name = "generate_button";
            this.generate_button.Size = new System.Drawing.Size(75, 23);
            this.generate_button.TabIndex = 1;
            this.generate_button.Text = "generate";
            this.generate_button.UseVisualStyleBackColor = true;
            this.generate_button.Click += new System.EventHandler(this.generate_button_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(517, 425);
            this.Controls.Add(this.generate_button);
            this.Controls.Add(this.exit_button);
            this.Controls.Add(this.scroll_mesh_groop_name);
            this.Controls.Add(this.scroll_material_name_setting);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "３Dモデル変換設定";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private _3Dmodel_Convert.Scroll_Name_Setting scroll_material_name_setting;
        private _3Dmodel_Convert.Scroll_Name_Setting scroll_mesh_groop_name;
        private System.Windows.Forms.Button exit_button;
        private System.Windows.Forms.Button generate_button;
    }
}