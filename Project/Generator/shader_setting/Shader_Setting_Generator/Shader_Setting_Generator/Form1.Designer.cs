namespace Shader_Setting_Generator
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
            this.B_Generate = new System.Windows.Forms.Button();
            this.uC_Vertex_Layout1 = new Shader_Setting_Generator.UC_Vertex_Layout();
            this.uC_Shader_Inform1 = new Shader_Setting_Generator.shader_set.UC_Shader_Inform();
            this.TB_Save_Name = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // B_Generate
            // 
            this.B_Generate.Font = new System.Drawing.Font("MS UI Gothic", 20F);
            this.B_Generate.Location = new System.Drawing.Point(12, 556);
            this.B_Generate.Name = "B_Generate";
            this.B_Generate.Size = new System.Drawing.Size(183, 56);
            this.B_Generate.TabIndex = 2;
            this.B_Generate.Text = "Generate";
            this.B_Generate.UseVisualStyleBackColor = true;
            this.B_Generate.MouseUp += new System.Windows.Forms.MouseEventHandler(this.B_Generate_MouseUp);
            // 
            // uC_Vertex_Layout1
            // 
            this.uC_Vertex_Layout1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.uC_Vertex_Layout1.Location = new System.Drawing.Point(4, 5);
            this.uC_Vertex_Layout1.Name = "uC_Vertex_Layout1";
            this.uC_Vertex_Layout1.Size = new System.Drawing.Size(461, 359);
            this.uC_Vertex_Layout1.TabIndex = 0;
            // 
            // uC_Shader_Inform1
            // 
            this.uC_Shader_Inform1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.uC_Shader_Inform1.Location = new System.Drawing.Point(507, 12);
            this.uC_Shader_Inform1.Name = "uC_Shader_Inform1";
            this.uC_Shader_Inform1.Size = new System.Drawing.Size(829, 600);
            this.uC_Shader_Inform1.TabIndex = 3;
            // 
            // TB_Save_Name
            // 
            this.TB_Save_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Save_Name.Location = new System.Drawing.Point(12, 508);
            this.TB_Save_Name.Name = "TB_Save_Name";
            this.TB_Save_Name.Size = new System.Drawing.Size(453, 23);
            this.TB_Save_Name.TabIndex = 4;
            this.TB_Save_Name.Text = "default";
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox2.Location = new System.Drawing.Point(12, 488);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(453, 23);
            this.textBox2.TabIndex = 4;
            this.textBox2.Text = "シェーダー設定名（ファイル保存時の名前）";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1348, 639);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.TB_Save_Name);
            this.Controls.Add(this.uC_Shader_Inform1);
            this.Controls.Add(this.B_Generate);
            this.Controls.Add(this.uC_Vertex_Layout1);
            this.Name = "Form1";
            this.Text = "シェーダー設定生成用システム";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private UC_Vertex_Layout uC_Vertex_Layout1;
        private System.Windows.Forms.Button B_Generate;
        private shader_set.UC_Shader_Inform uC_Shader_Inform1;
        private System.Windows.Forms.TextBox TB_Save_Name;
        private System.Windows.Forms.TextBox textBox2;
    }
}

