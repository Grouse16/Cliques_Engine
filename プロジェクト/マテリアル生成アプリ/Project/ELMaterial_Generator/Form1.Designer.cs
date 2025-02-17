namespace ELMaterial_Generator
{
    partial class Form1
    {
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

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.TB_material_name = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.CB_rasterize_draw_mode = new System.Windows.Forms.ComboBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.CB_rasterizer_mesh_setting = new System.Windows.Forms.ComboBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.CB_rasterizer_anti_aliasing = new System.Windows.Forms.ComboBox();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.TB_Shader_Setting_Name = new System.Windows.Forms.TextBox();
            this.textBox20 = new System.Windows.Forms.TextBox();
            this.textBox23 = new System.Windows.Forms.TextBox();
            this.textBox13 = new System.Windows.Forms.TextBox();
            this.B_Generate = new System.Windows.Forms.Button();
            this.B_Reset = new System.Windows.Forms.Button();
            this.TB_depth_setting = new System.Windows.Forms.TextBox();
            this.CB_depth_mode = new System.Windows.Forms.ComboBox();
            this.NB_sampling_level = new System.Windows.Forms.NumericUpDown();
            this.TB_preview = new System.Windows.Forms.TextBox();
            this.UC_transparent_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_specular_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_reflection_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_emission_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_diffuse_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_ambient_data = new ELMaterial_Generator.UC_Material_Setting_Frame();
            this.UC_blend_setting_frame = new ELMaterial_Generator.Blend_Setting_UI.UC_Blend_Setting_Frame();
            this.B_export_block = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.NB_sampling_level)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(11, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(394, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "マテリアル名";
            // 
            // TB_material_name
            // 
            this.TB_material_name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_material_name.Location = new System.Drawing.Point(11, 32);
            this.TB_material_name.Name = "TB_material_name";
            this.TB_material_name.Size = new System.Drawing.Size(394, 23);
            this.TB_material_name.TabIndex = 0;
            this.TB_material_name.Text = "Default_Name";
            // 
            // textBox7
            // 
            this.textBox7.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox7.Location = new System.Drawing.Point(11, 322);
            this.textBox7.Name = "textBox7";
            this.textBox7.ReadOnly = true;
            this.textBox7.Size = new System.Drawing.Size(394, 23);
            this.textBox7.TabIndex = 0;
            this.textBox7.Text = "ラスタライザ設定";
            // 
            // textBox8
            // 
            this.textBox8.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox8.Location = new System.Drawing.Point(11, 345);
            this.textBox8.Name = "textBox8";
            this.textBox8.ReadOnly = true;
            this.textBox8.Size = new System.Drawing.Size(125, 23);
            this.textBox8.TabIndex = 0;
            this.textBox8.Text = "表示モード";
            // 
            // CB_rasterize_draw_mode
            // 
            this.CB_rasterize_draw_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_rasterize_draw_mode.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_rasterize_draw_mode.FormattingEnabled = true;
            this.CB_rasterize_draw_mode.IntegralHeight = false;
            this.CB_rasterize_draw_mode.Items.AddRange(new object[] {
            "通常表示",
            "ワイヤーフレーム表示"});
            this.CB_rasterize_draw_mode.Location = new System.Drawing.Point(135, 345);
            this.CB_rasterize_draw_mode.Name = "CB_rasterize_draw_mode";
            this.CB_rasterize_draw_mode.Size = new System.Drawing.Size(269, 24);
            this.CB_rasterize_draw_mode.TabIndex = 1;
            // 
            // textBox9
            // 
            this.textBox9.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox9.Location = new System.Drawing.Point(12, 368);
            this.textBox9.Name = "textBox9";
            this.textBox9.ReadOnly = true;
            this.textBox9.Size = new System.Drawing.Size(125, 23);
            this.textBox9.TabIndex = 0;
            this.textBox9.Text = "面の表示基準";
            // 
            // CB_rasterizer_mesh_setting
            // 
            this.CB_rasterizer_mesh_setting.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_rasterizer_mesh_setting.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_rasterizer_mesh_setting.FormattingEnabled = true;
            this.CB_rasterizer_mesh_setting.IntegralHeight = false;
            this.CB_rasterizer_mesh_setting.Items.AddRange(new object[] {
            "表面のみ描画",
            "裏面のみ描画",
            "全て描画"});
            this.CB_rasterizer_mesh_setting.Location = new System.Drawing.Point(135, 367);
            this.CB_rasterizer_mesh_setting.Name = "CB_rasterizer_mesh_setting";
            this.CB_rasterizer_mesh_setting.Size = new System.Drawing.Size(269, 24);
            this.CB_rasterizer_mesh_setting.TabIndex = 1;
            // 
            // textBox10
            // 
            this.textBox10.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox10.Location = new System.Drawing.Point(12, 390);
            this.textBox10.Name = "textBox10";
            this.textBox10.ReadOnly = true;
            this.textBox10.Size = new System.Drawing.Size(125, 23);
            this.textBox10.TabIndex = 0;
            this.textBox10.Text = "アンチエイリアシング";
            // 
            // CB_rasterizer_anti_aliasing
            // 
            this.CB_rasterizer_anti_aliasing.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_rasterizer_anti_aliasing.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_rasterizer_anti_aliasing.FormattingEnabled = true;
            this.CB_rasterizer_anti_aliasing.IntegralHeight = false;
            this.CB_rasterizer_anti_aliasing.Items.AddRange(new object[] {
            "α補間",
            "色補間",
            "線形補間"});
            this.CB_rasterizer_anti_aliasing.Location = new System.Drawing.Point(135, 390);
            this.CB_rasterizer_anti_aliasing.Name = "CB_rasterizer_anti_aliasing";
            this.CB_rasterizer_anti_aliasing.Size = new System.Drawing.Size(269, 24);
            this.CB_rasterizer_anti_aliasing.TabIndex = 1;
            // 
            // textBox12
            // 
            this.textBox12.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox12.Location = new System.Drawing.Point(10, 61);
            this.textBox12.Name = "textBox12";
            this.textBox12.ReadOnly = true;
            this.textBox12.Size = new System.Drawing.Size(394, 23);
            this.textBox12.TabIndex = 0;
            this.textBox12.Text = "シェーダー設定名";
            // 
            // TB_Shader_Setting_Name
            // 
            this.TB_Shader_Setting_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Shader_Setting_Name.Location = new System.Drawing.Point(10, 81);
            this.TB_Shader_Setting_Name.Name = "TB_Shader_Setting_Name";
            this.TB_Shader_Setting_Name.Size = new System.Drawing.Size(394, 23);
            this.TB_Shader_Setting_Name.TabIndex = 0;
            this.TB_Shader_Setting_Name.Text = "Default_Name";
            // 
            // textBox20
            // 
            this.textBox20.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox20.Location = new System.Drawing.Point(12, 430);
            this.textBox20.Name = "textBox20";
            this.textBox20.ReadOnly = true;
            this.textBox20.Size = new System.Drawing.Size(393, 23);
            this.textBox20.TabIndex = 0;
            this.textBox20.Text = "サンプリング設定";
            // 
            // textBox23
            // 
            this.textBox23.BackColor = System.Drawing.SystemColors.Control;
            this.textBox23.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox23.Location = new System.Drawing.Point(12, 450);
            this.textBox23.Name = "textBox23";
            this.textBox23.ReadOnly = true;
            this.textBox23.Size = new System.Drawing.Size(119, 23);
            this.textBox23.TabIndex = 0;
            this.textBox23.Text = "サンプリングレベル";
            // 
            // textBox13
            // 
            this.textBox13.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox13.Location = new System.Drawing.Point(420, 12);
            this.textBox13.Name = "textBox13";
            this.textBox13.ReadOnly = true;
            this.textBox13.Size = new System.Drawing.Size(439, 23);
            this.textBox13.TabIndex = 0;
            this.textBox13.Text = "質感（マテリアル）";
            // 
            // B_Generate
            // 
            this.B_Generate.Font = new System.Drawing.Font("MS UI Gothic", 14F);
            this.B_Generate.Location = new System.Drawing.Point(16, 686);
            this.B_Generate.Margin = new System.Windows.Forms.Padding(2);
            this.B_Generate.Name = "B_Generate";
            this.B_Generate.Size = new System.Drawing.Size(181, 42);
            this.B_Generate.TabIndex = 3;
            this.B_Generate.Text = "Generate";
            this.B_Generate.UseVisualStyleBackColor = true;
            this.B_Generate.MouseUp += new System.Windows.Forms.MouseEventHandler(this.B_Generate_MouseUp);
            // 
            // B_Reset
            // 
            this.B_Reset.Font = new System.Drawing.Font("MS UI Gothic", 14F);
            this.B_Reset.Location = new System.Drawing.Point(216, 686);
            this.B_Reset.Margin = new System.Windows.Forms.Padding(2);
            this.B_Reset.Name = "B_Reset";
            this.B_Reset.Size = new System.Drawing.Size(181, 42);
            this.B_Reset.TabIndex = 3;
            this.B_Reset.Text = "Reset";
            this.B_Reset.UseVisualStyleBackColor = true;
            this.B_Reset.MouseUp += new System.Windows.Forms.MouseEventHandler(this.B_Reset_MouseUp);
            // 
            // TB_depth_setting
            // 
            this.TB_depth_setting.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_depth_setting.Location = new System.Drawing.Point(11, 269);
            this.TB_depth_setting.Name = "TB_depth_setting";
            this.TB_depth_setting.ReadOnly = true;
            this.TB_depth_setting.Size = new System.Drawing.Size(393, 23);
            this.TB_depth_setting.TabIndex = 0;
            this.TB_depth_setting.Text = "奥行き設定";
            // 
            // CB_depth_mode
            // 
            this.CB_depth_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_depth_mode.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_depth_mode.FormattingEnabled = true;
            this.CB_depth_mode.IntegralHeight = false;
            this.CB_depth_mode.Items.AddRange(new object[] {
            "奥行きあり",
            "奥行きなし"});
            this.CB_depth_mode.Location = new System.Drawing.Point(11, 292);
            this.CB_depth_mode.Name = "CB_depth_mode";
            this.CB_depth_mode.Size = new System.Drawing.Size(394, 24);
            this.CB_depth_mode.TabIndex = 1;
            // 
            // NB_sampling_level
            // 
            this.NB_sampling_level.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NB_sampling_level.Location = new System.Drawing.Point(130, 450);
            this.NB_sampling_level.Name = "NB_sampling_level";
            this.NB_sampling_level.Size = new System.Drawing.Size(275, 23);
            this.NB_sampling_level.TabIndex = 7;
            // 
            // TB_preview
            // 
            this.TB_preview.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_preview.Location = new System.Drawing.Point(865, 12);
            this.TB_preview.Name = "TB_preview";
            this.TB_preview.ReadOnly = true;
            this.TB_preview.Size = new System.Drawing.Size(315, 23);
            this.TB_preview.TabIndex = 0;
            this.TB_preview.Text = "プレビュー（実装予定）";
            // 
            // UC_transparent_data
            // 
            this.UC_transparent_data.Location = new System.Drawing.Point(419, 578);
            this.UC_transparent_data.Name = "UC_transparent_data";
            this.UC_transparent_data.Size = new System.Drawing.Size(439, 109);
            this.UC_transparent_data.TabIndex = 8;
            // 
            // UC_specular_data
            // 
            this.UC_specular_data.Location = new System.Drawing.Point(419, 471);
            this.UC_specular_data.Name = "UC_specular_data";
            this.UC_specular_data.Size = new System.Drawing.Size(439, 109);
            this.UC_specular_data.TabIndex = 8;
            // 
            // UC_reflection_data
            // 
            this.UC_reflection_data.Location = new System.Drawing.Point(419, 361);
            this.UC_reflection_data.Name = "UC_reflection_data";
            this.UC_reflection_data.Size = new System.Drawing.Size(439, 109);
            this.UC_reflection_data.TabIndex = 8;
            // 
            // UC_emission_data
            // 
            this.UC_emission_data.Location = new System.Drawing.Point(419, 252);
            this.UC_emission_data.Name = "UC_emission_data";
            this.UC_emission_data.Size = new System.Drawing.Size(439, 109);
            this.UC_emission_data.TabIndex = 8;
            // 
            // UC_diffuse_data
            // 
            this.UC_diffuse_data.Location = new System.Drawing.Point(420, 143);
            this.UC_diffuse_data.Name = "UC_diffuse_data";
            this.UC_diffuse_data.Size = new System.Drawing.Size(439, 109);
            this.UC_diffuse_data.TabIndex = 8;
            // 
            // UC_ambient_data
            // 
            this.UC_ambient_data.Location = new System.Drawing.Point(420, 33);
            this.UC_ambient_data.Name = "UC_ambient_data";
            this.UC_ambient_data.Size = new System.Drawing.Size(439, 109);
            this.UC_ambient_data.TabIndex = 8;
            // 
            // UC_blend_setting_frame
            // 
            this.UC_blend_setting_frame.BackColor = System.Drawing.SystemColors.ControlDark;
            this.UC_blend_setting_frame.Location = new System.Drawing.Point(10, 110);
            this.UC_blend_setting_frame.MaximumSize = new System.Drawing.Size(394, 150);
            this.UC_blend_setting_frame.MinimumSize = new System.Drawing.Size(394, 150);
            this.UC_blend_setting_frame.Name = "UC_blend_setting_frame";
            this.UC_blend_setting_frame.Size = new System.Drawing.Size(394, 150);
            this.UC_blend_setting_frame.TabIndex = 6;
            // 
            // B_export_block
            // 
            this.B_export_block.AllowDrop = true;
            this.B_export_block.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_export_block.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_export_block.ForeColor = System.Drawing.SystemColors.ControlText;
            this.B_export_block.Location = new System.Drawing.Point(12, 489);
            this.B_export_block.Name = "B_export_block";
            this.B_export_block.Size = new System.Drawing.Size(393, 183);
            this.B_export_block.TabIndex = 9;
            this.B_export_block.Text = "データロードブロック\r\n.elmat　.elmatinform\r\nをここにドラッグアンドドロップすることで、\r\nデータをロードして設定";
            this.B_export_block.UseVisualStyleBackColor = false;
            this.B_export_block.DragDrop += new System.Windows.Forms.DragEventHandler(this.B_export_block_DragDrop);
            this.B_export_block.DragOver += new System.Windows.Forms.DragEventHandler(this.B_export_block_DragOver);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1192, 737);
            this.Controls.Add(this.B_export_block);
            this.Controls.Add(this.UC_transparent_data);
            this.Controls.Add(this.UC_specular_data);
            this.Controls.Add(this.UC_reflection_data);
            this.Controls.Add(this.UC_emission_data);
            this.Controls.Add(this.UC_diffuse_data);
            this.Controls.Add(this.UC_ambient_data);
            this.Controls.Add(this.NB_sampling_level);
            this.Controls.Add(this.UC_blend_setting_frame);
            this.Controls.Add(this.B_Reset);
            this.Controls.Add(this.B_Generate);
            this.Controls.Add(this.CB_rasterizer_anti_aliasing);
            this.Controls.Add(this.CB_depth_mode);
            this.Controls.Add(this.CB_rasterizer_mesh_setting);
            this.Controls.Add(this.CB_rasterize_draw_mode);
            this.Controls.Add(this.textBox23);
            this.Controls.Add(this.textBox10);
            this.Controls.Add(this.textBox9);
            this.Controls.Add(this.textBox8);
            this.Controls.Add(this.textBox13);
            this.Controls.Add(this.TB_depth_setting);
            this.Controls.Add(this.textBox20);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.TB_Shader_Setting_Name);
            this.Controls.Add(this.TB_material_name);
            this.Controls.Add(this.textBox12);
            this.Controls.Add(this.TB_preview);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "Elina Lead用マテリアル生成システム";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.NB_sampling_level)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox TB_material_name;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.ComboBox CB_rasterize_draw_mode;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.ComboBox CB_rasterizer_mesh_setting;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.ComboBox CB_rasterizer_anti_aliasing;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox TB_Shader_Setting_Name;
        private System.Windows.Forms.TextBox textBox20;
        private System.Windows.Forms.TextBox textBox23;
        private System.Windows.Forms.TextBox textBox13;
        private System.Windows.Forms.Button B_Generate;
        private System.Windows.Forms.Button B_Reset;
        private System.Windows.Forms.TextBox TB_depth_setting;
        private System.Windows.Forms.ComboBox CB_depth_mode;
        private Blend_Setting_UI.UC_Blend_Setting_Frame UC_blend_setting_frame;
        private System.Windows.Forms.NumericUpDown NB_sampling_level;
        private UC_Material_Setting_Frame UC_ambient_data;
        private UC_Material_Setting_Frame UC_diffuse_data;
        private UC_Material_Setting_Frame UC_emission_data;
        private UC_Material_Setting_Frame UC_reflection_data;
        private UC_Material_Setting_Frame UC_specular_data;
        private UC_Material_Setting_Frame UC_transparent_data;
        private System.Windows.Forms.TextBox TB_preview;
        private System.Windows.Forms.Button B_export_block;
    }
}

