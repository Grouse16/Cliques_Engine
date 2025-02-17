namespace Shader_Setting_Generator
{
    partial class UC_Vertex_Layout
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
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.NB_Vertex_Layout_Sum = new System.Windows.Forms.NumericUpDown();
            this.uC_Vertex_Setting_List1 = new Shader_Setting_Generator.UC_Vertex_Setting_List();
            this.B_Reset = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.NB_Vertex_Layout_Sum)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(461, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "頂点レイアウト";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox2.Location = new System.Drawing.Point(0, 23);
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(128, 23);
            this.textBox2.TabIndex = 0;
            this.textBox2.Text = "頂点インスタンス数";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NB_Vertex_Layout_Sum
            // 
            this.NB_Vertex_Layout_Sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NB_Vertex_Layout_Sum.Location = new System.Drawing.Point(125, 23);
            this.NB_Vertex_Layout_Sum.Maximum = new decimal(new int[] {
            99,
            0,
            0,
            0});
            this.NB_Vertex_Layout_Sum.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.NB_Vertex_Layout_Sum.Name = "NB_Vertex_Layout_Sum";
            this.NB_Vertex_Layout_Sum.Size = new System.Drawing.Size(91, 23);
            this.NB_Vertex_Layout_Sum.TabIndex = 2;
            this.NB_Vertex_Layout_Sum.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NB_Vertex_Layout_Sum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.NB_Vertex_Layout_Sum.ValueChanged += new System.EventHandler(this.NB_Vertex_Layout_Sum_ValueChanged);
            // 
            // uC_Vertex_Setting_List1
            // 
            this.uC_Vertex_Setting_List1.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.uC_Vertex_Setting_List1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.uC_Vertex_Setting_List1.Location = new System.Drawing.Point(0, 57);
            this.uC_Vertex_Setting_List1.Margin = new System.Windows.Forms.Padding(2);
            this.uC_Vertex_Setting_List1.Name = "uC_Vertex_Setting_List1";
            this.uC_Vertex_Setting_List1.Size = new System.Drawing.Size(461, 279);
            this.uC_Vertex_Setting_List1.TabIndex = 3;
            // 
            // B_Reset
            // 
            this.B_Reset.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.B_Reset.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.B_Reset.Location = new System.Drawing.Point(0, 336);
            this.B_Reset.Name = "B_Reset";
            this.B_Reset.Size = new System.Drawing.Size(461, 23);
            this.B_Reset.TabIndex = 4;
            this.B_Reset.Text = "Reset";
            this.B_Reset.UseVisualStyleBackColor = true;
            this.B_Reset.MouseUp += new System.Windows.Forms.MouseEventHandler(this.B_Reset_MouseUp);
            // 
            // UC_Vertex_Layout
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.Controls.Add(this.uC_Vertex_Setting_List1);
            this.Controls.Add(this.B_Reset);
            this.Controls.Add(this.NB_Vertex_Layout_Sum);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Name = "UC_Vertex_Layout";
            this.Size = new System.Drawing.Size(461, 359);
            ((System.ComponentModel.ISupportInitialize)(this.NB_Vertex_Layout_Sum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.NumericUpDown NB_Vertex_Layout_Sum;
        private UC_Vertex_Setting_List uC_Vertex_Setting_List1;
        private System.Windows.Forms.Button B_Reset;
    }
}
