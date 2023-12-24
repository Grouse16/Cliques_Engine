namespace _3D_Model_Converter_And_Drawer
{
    partial class Form_3D_Model_Convert_Setting
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
            this.b_exit_button = new System.Windows.Forms.Button();
            this.b_animative_model_generate_button = new System.Windows.Forms.Button();
            this.b_material_inform_generate_button = new System.Windows.Forms.Button();
            this.b_static_model_convert_button = new System.Windows.Forms.Button();
            this.b_animation_data_convert_button = new System.Windows.Forms.Button();
            this.uc_born_name_list = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.UC_Scroll_Name_Setting();
            this.uc_animation_data_list = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.UC_Scroll_Name_Setting();
            this.uc_mesh_name_list = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.UC_Scroll_Name_Setting();
            this.uc_material_name_list = new _3D_Model_Converter_And_Drawer._3Dmodel_Convert.UC_Scroll_Name_Setting();
            this.SuspendLayout();
            // 
            // b_exit_button
            // 
            this.b_exit_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_exit_button.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.b_exit_button.Location = new System.Drawing.Point(12, 519);
            this.b_exit_button.Name = "b_exit_button";
            this.b_exit_button.Size = new System.Drawing.Size(232, 45);
            this.b_exit_button.TabIndex = 1;
            this.b_exit_button.Text = "閉じる";
            this.b_exit_button.UseVisualStyleBackColor = true;
            this.b_exit_button.Click += new System.EventHandler(this.Exit_button_Click);
            // 
            // b_animative_model_generate_button
            // 
            this.b_animative_model_generate_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_animative_model_generate_button.Location = new System.Drawing.Point(804, 444);
            this.b_animative_model_generate_button.Name = "b_animative_model_generate_button";
            this.b_animative_model_generate_button.Size = new System.Drawing.Size(232, 101);
            this.b_animative_model_generate_button.TabIndex = 1;
            this.b_animative_model_generate_button.Text = "3Dアニメーション可能モデル変換ボタン\r\nELANMモデルを生成\r\nボーンのデータありの\r\nアニメーション可能なモデルを生成";
            this.b_animative_model_generate_button.UseVisualStyleBackColor = true;
            this.b_animative_model_generate_button.Click += new System.EventHandler(this.b_animative_model_generate_button_Click);
            // 
            // b_material_inform_generate_button
            // 
            this.b_material_inform_generate_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_material_inform_generate_button.Location = new System.Drawing.Point(256, 205);
            this.b_material_inform_generate_button.Name = "b_material_inform_generate_button";
            this.b_material_inform_generate_button.Size = new System.Drawing.Size(229, 53);
            this.b_material_inform_generate_button.TabIndex = 1;
            this.b_material_inform_generate_button.Text = "マテリアル（質感）情報生成ボタン\r\n（ELMATではないので注意）";
            this.b_material_inform_generate_button.UseVisualStyleBackColor = true;
            this.b_material_inform_generate_button.Click += new System.EventHandler(this.B_material_inform_generate_button_Click);
            // 
            // b_static_model_convert_button
            // 
            this.b_static_model_convert_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_static_model_convert_button.Location = new System.Drawing.Point(558, 444);
            this.b_static_model_convert_button.Name = "b_static_model_convert_button";
            this.b_static_model_convert_button.Size = new System.Drawing.Size(232, 101);
            this.b_static_model_convert_button.TabIndex = 1;
            this.b_static_model_convert_button.Text = "スタティックモデル変換ボタン\r\nELSSTモデルを生成\r\nボーンのデータなしの静的なモデルを生成";
            this.b_static_model_convert_button.UseVisualStyleBackColor = true;
            this.b_static_model_convert_button.Click += new System.EventHandler(this.B_static_model_convert_button_Click);
            // 
            // b_animation_data_convert_button
            // 
            this.b_animation_data_convert_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_animation_data_convert_button.Location = new System.Drawing.Point(256, 444);
            this.b_animation_data_convert_button.Name = "b_animation_data_convert_button";
            this.b_animation_data_convert_button.Size = new System.Drawing.Size(229, 45);
            this.b_animation_data_convert_button.TabIndex = 1;
            this.b_animation_data_convert_button.Text = "アニメーションデータ生成ボタン";
            this.b_animation_data_convert_button.UseVisualStyleBackColor = true;
            this.b_animation_data_convert_button.Click += new System.EventHandler(this.b_animation_data_convert_button_Click);
            // 
            // uc_born_name_list
            // 
            this.uc_born_name_list.Location = new System.Drawing.Point(560, 205);
            this.uc_born_name_list.Name = "uc_born_name_list";
            this.uc_born_name_list.Size = new System.Drawing.Size(478, 173);
            this.uc_born_name_list.TabIndex = 3;
            // 
            // uc_animation_data_list
            // 
            this.uc_animation_data_list.Location = new System.Drawing.Point(12, 264);
            this.uc_animation_data_list.Name = "uc_animation_data_list";
            this.uc_animation_data_list.Size = new System.Drawing.Size(478, 173);
            this.uc_animation_data_list.TabIndex = 3;
            // 
            // uc_mesh_name_list
            // 
            this.uc_mesh_name_list.Location = new System.Drawing.Point(558, 14);
            this.uc_mesh_name_list.Name = "uc_mesh_name_list";
            this.uc_mesh_name_list.Size = new System.Drawing.Size(478, 173);
            this.uc_mesh_name_list.TabIndex = 3;
            // 
            // uc_material_name_list
            // 
            this.uc_material_name_list.Location = new System.Drawing.Point(12, 12);
            this.uc_material_name_list.Name = "uc_material_name_list";
            this.uc_material_name_list.Size = new System.Drawing.Size(478, 173);
            this.uc_material_name_list.TabIndex = 2;
            // 
            // Form_3D_Model_Convert_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1050, 571);
            this.Controls.Add(this.uc_born_name_list);
            this.Controls.Add(this.uc_animation_data_list);
            this.Controls.Add(this.uc_mesh_name_list);
            this.Controls.Add(this.uc_material_name_list);
            this.Controls.Add(this.b_animation_data_convert_button);
            this.Controls.Add(this.b_material_inform_generate_button);
            this.Controls.Add(this.b_static_model_convert_button);
            this.Controls.Add(this.b_animative_model_generate_button);
            this.Controls.Add(this.b_exit_button);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form_3D_Model_Convert_Setting";
            this.Text = "３Dモデル変換システム";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form_3D_Model_Convert_Setting_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button b_exit_button;
        private System.Windows.Forms.Button b_animative_model_generate_button;
        private System.Windows.Forms.Button b_material_inform_generate_button;
        private System.Windows.Forms.Button b_static_model_convert_button;
        private System.Windows.Forms.Button b_animation_data_convert_button;
        private _3Dmodel_Convert.UC_Scroll_Name_Setting uc_animation_data_list;
        private _3Dmodel_Convert.UC_Scroll_Name_Setting uc_born_name_list;
        private _3Dmodel_Convert.UC_Scroll_Name_Setting uc_mesh_name_list;
        private _3Dmodel_Convert.UC_Scroll_Name_Setting uc_material_name_list;
    }
}