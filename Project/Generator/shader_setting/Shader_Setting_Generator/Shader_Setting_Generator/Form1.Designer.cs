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
            this.uC_Vertex_Layout1 = new Shader_Setting_Generator.UC_Vertex_Layout();
            this.uC_Shader_Setting1 = new Shader_Setting_Generator.UC_Shader_Setting();
            this.SuspendLayout();
            // 
            // uC_Vertex_Layout1
            // 
            this.uC_Vertex_Layout1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.uC_Vertex_Layout1.Location = new System.Drawing.Point(4, 5);
            this.uC_Vertex_Layout1.Name = "uC_Vertex_Layout1";
            this.uC_Vertex_Layout1.Size = new System.Drawing.Size(461, 359);
            this.uC_Vertex_Layout1.TabIndex = 0;
            // 
            // uC_Shader_Setting1
            // 
            this.uC_Shader_Setting1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.uC_Shader_Setting1.Location = new System.Drawing.Point(471, 5);
            this.uC_Shader_Setting1.Name = "uC_Shader_Setting1";
            this.uC_Shader_Setting1.Size = new System.Drawing.Size(876, 627);
            this.uC_Shader_Setting1.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1348, 639);
            this.Controls.Add(this.uC_Shader_Setting1);
            this.Controls.Add(this.uC_Vertex_Layout1);
            this.Name = "Form1";
            this.Text = "シェーダー設定生成用システム";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private UC_Vertex_Layout uC_Vertex_Layout1;
        private UC_Shader_Setting uC_Shader_Setting1;
    }
}

