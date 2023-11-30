namespace Shader_Setting_Generator.shader_set
{
    partial class UC_Shader_Inform
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

        #region コンポーネント デザイナーで生成されたコード

        /// <summary> 
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を 
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.TB_Shader_Name = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.NM_Constant_Buffer_Sum = new System.Windows.Forms.NumericUpDown();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.NM_Texture_Buffer_Sum = new System.Windows.Forms.NumericUpDown();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.NM_Sampler_Sum = new System.Windows.Forms.NumericUpDown();
            this.uC_Texture_Inform_List1 = new Shader_Setting_Generator.texture_buffer.UC_Texture_Inform_List();
            this.uC_Constant_Buffer_Setting_List1 = new Shader_Setting_Generator.constant_buffer.UC_Constant_Buffer_Setting_List();
            this.uC_Sampler_Setting_List1 = new Shader_Setting_Generator.sampler_setting.UC_Sampler_Setting_List();
            this.B_Reset = new System.Windows.Forms.Button();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.CHB_Pixel_Shader = new System.Windows.Forms.CheckBox();
            this.CHB_Vertex_Shader = new System.Windows.Forms.CheckBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.CHB_Geometry_Shader = new System.Windows.Forms.CheckBox();
            this.CHB_Domain_Shader = new System.Windows.Forms.CheckBox();
            this.CHB_Hul_Shader = new System.Windows.Forms.CheckBox();
            this.CB_Setting_Shader_Kind = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Constant_Buffer_Sum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Texture_Buffer_Sum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Sampler_Sum)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(2, 123);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(153, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "使用するシェーダー名";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TB_Shader_Name
            // 
            this.TB_Shader_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Shader_Name.Location = new System.Drawing.Point(155, 123);
            this.TB_Shader_Name.Name = "TB_Shader_Name";
            this.TB_Shader_Name.Size = new System.Drawing.Size(674, 23);
            this.TB_Shader_Name.TabIndex = 0;
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox2.Location = new System.Drawing.Point(2, 147);
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(415, 23);
            this.textBox2.TabIndex = 0;
            this.textBox2.Text = "定数バッファ設定";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(3, 170);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(152, 23);
            this.textBox3.TabIndex = 0;
            this.textBox3.Text = "定数バッファ数";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NM_Constant_Buffer_Sum
            // 
            this.NM_Constant_Buffer_Sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NM_Constant_Buffer_Sum.Location = new System.Drawing.Point(155, 170);
            this.NM_Constant_Buffer_Sum.Maximum = new decimal(new int[] {
            14,
            0,
            0,
            0});
            this.NM_Constant_Buffer_Sum.Name = "NM_Constant_Buffer_Sum";
            this.NM_Constant_Buffer_Sum.Size = new System.Drawing.Size(119, 23);
            this.NM_Constant_Buffer_Sum.TabIndex = 1;
            this.NM_Constant_Buffer_Sum.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NM_Constant_Buffer_Sum.ValueChanged += new System.EventHandler(this.NM_Constant_Buffer_Sum_ValueChanged);
            // 
            // textBox4
            // 
            this.textBox4.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox4.Location = new System.Drawing.Point(414, 147);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(415, 23);
            this.textBox4.TabIndex = 0;
            this.textBox4.Text = "テクスチャバッファ設定";
            this.textBox4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox5.Location = new System.Drawing.Point(414, 170);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(152, 23);
            this.textBox5.TabIndex = 0;
            this.textBox5.Text = "テクスチャバッファ数";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NM_Texture_Buffer_Sum
            // 
            this.NM_Texture_Buffer_Sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NM_Texture_Buffer_Sum.Location = new System.Drawing.Point(566, 170);
            this.NM_Texture_Buffer_Sum.Maximum = new decimal(new int[] {
            16,
            0,
            0,
            0});
            this.NM_Texture_Buffer_Sum.Name = "NM_Texture_Buffer_Sum";
            this.NM_Texture_Buffer_Sum.Size = new System.Drawing.Size(119, 23);
            this.NM_Texture_Buffer_Sum.TabIndex = 1;
            this.NM_Texture_Buffer_Sum.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NM_Texture_Buffer_Sum.ValueChanged += new System.EventHandler(this.NM_Texture_Buffer_Sum_ValueChanged);
            // 
            // textBox6
            // 
            this.textBox6.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox6.Location = new System.Drawing.Point(3, 414);
            this.textBox6.Name = "textBox6";
            this.textBox6.ReadOnly = true;
            this.textBox6.Size = new System.Drawing.Size(412, 23);
            this.textBox6.TabIndex = 0;
            this.textBox6.Text = "サンプラー設定";
            this.textBox6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox7
            // 
            this.textBox7.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox7.Location = new System.Drawing.Point(4, 437);
            this.textBox7.Name = "textBox7";
            this.textBox7.ReadOnly = true;
            this.textBox7.Size = new System.Drawing.Size(152, 23);
            this.textBox7.TabIndex = 0;
            this.textBox7.Text = "サンプラー設定数";
            this.textBox7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NM_Sampler_Sum
            // 
            this.NM_Sampler_Sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NM_Sampler_Sum.Location = new System.Drawing.Point(156, 437);
            this.NM_Sampler_Sum.Maximum = new decimal(new int[] {
            16,
            0,
            0,
            0});
            this.NM_Sampler_Sum.Name = "NM_Sampler_Sum";
            this.NM_Sampler_Sum.Size = new System.Drawing.Size(119, 23);
            this.NM_Sampler_Sum.TabIndex = 1;
            this.NM_Sampler_Sum.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NM_Sampler_Sum.ValueChanged += new System.EventHandler(this.NM_Sampler_Sum_ValueChanged);
            // 
            // uC_Texture_Inform_List1
            // 
            this.uC_Texture_Inform_List1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.uC_Texture_Inform_List1.Location = new System.Drawing.Point(416, 192);
            this.uC_Texture_Inform_List1.Name = "uC_Texture_Inform_List1";
            this.uC_Texture_Inform_List1.Size = new System.Drawing.Size(415, 195);
            this.uC_Texture_Inform_List1.TabIndex = 3;
            // 
            // uC_Constant_Buffer_Setting_List1
            // 
            this.uC_Constant_Buffer_Setting_List1.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.uC_Constant_Buffer_Setting_List1.Location = new System.Drawing.Point(2, 192);
            this.uC_Constant_Buffer_Setting_List1.Name = "uC_Constant_Buffer_Setting_List1";
            this.uC_Constant_Buffer_Setting_List1.Size = new System.Drawing.Size(415, 222);
            this.uC_Constant_Buffer_Setting_List1.TabIndex = 2;
            // 
            // uC_Sampler_Setting_List1
            // 
            this.uC_Sampler_Setting_List1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.uC_Sampler_Setting_List1.Location = new System.Drawing.Point(4, 460);
            this.uC_Sampler_Setting_List1.Name = "uC_Sampler_Setting_List1";
            this.uC_Sampler_Setting_List1.Size = new System.Drawing.Size(411, 139);
            this.uC_Sampler_Setting_List1.TabIndex = 4;
            // 
            // B_Reset
            // 
            this.B_Reset.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.B_Reset.Location = new System.Drawing.Point(735, 565);
            this.B_Reset.Name = "B_Reset";
            this.B_Reset.Size = new System.Drawing.Size(75, 23);
            this.B_Reset.TabIndex = 5;
            this.B_Reset.Text = "Reset";
            this.B_Reset.UseVisualStyleBackColor = true;
            this.B_Reset.MouseUp += new System.Windows.Forms.MouseEventHandler(this.B_Reset_MouseUp);
            // 
            // textBox8
            // 
            this.textBox8.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox8.Location = new System.Drawing.Point(413, 23);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(415, 23);
            this.textBox8.TabIndex = 9;
            this.textBox8.Text = "有効なシェーダーの種類";
            this.textBox8.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox9
            // 
            this.textBox9.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox9.Location = new System.Drawing.Point(-1, 23);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(415, 23);
            this.textBox9.TabIndex = 10;
            this.textBox9.Text = "設定するシェーダーの種類";
            this.textBox9.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox10
            // 
            this.textBox10.Dock = System.Windows.Forms.DockStyle.Top;
            this.textBox10.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox10.Location = new System.Drawing.Point(0, 0);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(829, 23);
            this.textBox10.TabIndex = 8;
            this.textBox10.Text = "シェーダーリソース設定";
            this.textBox10.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CHB_Pixel_Shader
            // 
            this.CHB_Pixel_Shader.AutoSize = true;
            this.CHB_Pixel_Shader.Checked = true;
            this.CHB_Pixel_Shader.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CHB_Pixel_Shader.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CHB_Pixel_Shader.Location = new System.Drawing.Point(22, 29);
            this.CHB_Pixel_Shader.Name = "CHB_Pixel_Shader";
            this.CHB_Pixel_Shader.Size = new System.Drawing.Size(110, 20);
            this.CHB_Pixel_Shader.TabIndex = 6;
            this.CHB_Pixel_Shader.Text = "Pixel Shader";
            this.CHB_Pixel_Shader.UseVisualStyleBackColor = true;
            // 
            // CHB_Vertex_Shader
            // 
            this.CHB_Vertex_Shader.AutoSize = true;
            this.CHB_Vertex_Shader.Checked = true;
            this.CHB_Vertex_Shader.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CHB_Vertex_Shader.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CHB_Vertex_Shader.Location = new System.Drawing.Point(22, 3);
            this.CHB_Vertex_Shader.Name = "CHB_Vertex_Shader";
            this.CHB_Vertex_Shader.Size = new System.Drawing.Size(124, 20);
            this.CHB_Vertex_Shader.TabIndex = 6;
            this.CHB_Vertex_Shader.Text = "Vertex Shader";
            this.CHB_Vertex_Shader.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.panel1.Controls.Add(this.CHB_Geometry_Shader);
            this.panel1.Controls.Add(this.CHB_Domain_Shader);
            this.panel1.Controls.Add(this.CHB_Hul_Shader);
            this.panel1.Controls.Add(this.CHB_Pixel_Shader);
            this.panel1.Controls.Add(this.CHB_Vertex_Shader);
            this.panel1.Location = new System.Drawing.Point(413, 46);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(415, 78);
            this.panel1.TabIndex = 12;
            // 
            // CHB_Geometry_Shader
            // 
            this.CHB_Geometry_Shader.AutoSize = true;
            this.CHB_Geometry_Shader.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CHB_Geometry_Shader.Location = new System.Drawing.Point(204, 55);
            this.CHB_Geometry_Shader.Name = "CHB_Geometry_Shader";
            this.CHB_Geometry_Shader.Size = new System.Drawing.Size(146, 20);
            this.CHB_Geometry_Shader.TabIndex = 6;
            this.CHB_Geometry_Shader.Text = "Geometry Shader";
            this.CHB_Geometry_Shader.UseVisualStyleBackColor = true;
            // 
            // CHB_Domain_Shader
            // 
            this.CHB_Domain_Shader.AutoSize = true;
            this.CHB_Domain_Shader.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CHB_Domain_Shader.Location = new System.Drawing.Point(204, 29);
            this.CHB_Domain_Shader.Name = "CHB_Domain_Shader";
            this.CHB_Domain_Shader.Size = new System.Drawing.Size(128, 20);
            this.CHB_Domain_Shader.TabIndex = 6;
            this.CHB_Domain_Shader.Text = "Domain Shader";
            this.CHB_Domain_Shader.UseVisualStyleBackColor = true;
            // 
            // CHB_Hul_Shader
            // 
            this.CHB_Hul_Shader.AutoSize = true;
            this.CHB_Hul_Shader.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CHB_Hul_Shader.Location = new System.Drawing.Point(204, 3);
            this.CHB_Hul_Shader.Name = "CHB_Hul_Shader";
            this.CHB_Hul_Shader.Size = new System.Drawing.Size(100, 20);
            this.CHB_Hul_Shader.TabIndex = 6;
            this.CHB_Hul_Shader.Text = "Hul Shader";
            this.CHB_Hul_Shader.UseVisualStyleBackColor = true;
            // 
            // CB_Setting_Shader_Kind
            // 
            this.CB_Setting_Shader_Kind.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Setting_Shader_Kind.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Setting_Shader_Kind.FormattingEnabled = true;
            this.CB_Setting_Shader_Kind.Items.AddRange(new object[] {
            "All Shader Resource：全シェーダー共通リソース",
            "Vertex Shader：頂点シェーダー用リソース",
            "Hul Shader：ハルシェーダー用リソース",
            "Domain Shader：ドメインシェーダー用リソース",
            "Geometry Shader：ジオメトリシェーダー用リソース",
            "Pixel Shader：ピクセルシェーダー用リソース"});
            this.CB_Setting_Shader_Kind.Location = new System.Drawing.Point(0, 46);
            this.CB_Setting_Shader_Kind.Name = "CB_Setting_Shader_Kind";
            this.CB_Setting_Shader_Kind.Size = new System.Drawing.Size(414, 24);
            this.CB_Setting_Shader_Kind.TabIndex = 13;
            this.CB_Setting_Shader_Kind.SelectedIndexChanged += new System.EventHandler(this.CB_Setting_Shader_Kind_SelectedIndexChanged);
            // 
            // UC_Shader_Inform
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.Controls.Add(this.CB_Setting_Shader_Kind);
            this.Controls.Add(this.textBox8);
            this.Controls.Add(this.textBox9);
            this.Controls.Add(this.textBox10);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.B_Reset);
            this.Controls.Add(this.uC_Sampler_Setting_List1);
            this.Controls.Add(this.uC_Texture_Inform_List1);
            this.Controls.Add(this.uC_Constant_Buffer_Setting_List1);
            this.Controls.Add(this.NM_Texture_Buffer_Sum);
            this.Controls.Add(this.NM_Sampler_Sum);
            this.Controls.Add(this.NM_Constant_Buffer_Sum);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.TB_Shader_Name);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Name = "UC_Shader_Inform";
            this.Size = new System.Drawing.Size(829, 600);
            this.Load += new System.EventHandler(this.UC_Shader_Inform_Load);
            ((System.ComponentModel.ISupportInitialize)(this.NM_Constant_Buffer_Sum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Texture_Buffer_Sum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Sampler_Sum)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox TB_Shader_Name;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.NumericUpDown NM_Constant_Buffer_Sum;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.NumericUpDown NM_Texture_Buffer_Sum;
        private constant_buffer.UC_Constant_Buffer_Setting_List uC_Constant_Buffer_Setting_List1;
        private texture_buffer.UC_Texture_Inform_List uC_Texture_Inform_List1;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.NumericUpDown NM_Sampler_Sum;
        private sampler_setting.UC_Sampler_Setting_List uC_Sampler_Setting_List1;
        private System.Windows.Forms.Button B_Reset;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.CheckBox CHB_Pixel_Shader;
        private System.Windows.Forms.CheckBox CHB_Vertex_Shader;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.CheckBox CHB_Geometry_Shader;
        private System.Windows.Forms.CheckBox CHB_Domain_Shader;
        private System.Windows.Forms.CheckBox CHB_Hul_Shader;
        private System.Windows.Forms.ComboBox CB_Setting_Shader_Kind;
    }
}
