namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer
{
    partial class UC_Animation_Inform_Bar
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
            this.tb_animation_name = new System.Windows.Forms.TextBox();
            this.b_delete_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(3, 3);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(113, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "アニメーション名";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tb_animation_name
            // 
            this.tb_animation_name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.tb_animation_name.Location = new System.Drawing.Point(113, 3);
            this.tb_animation_name.Name = "tb_animation_name";
            this.tb_animation_name.ReadOnly = true;
            this.tb_animation_name.Size = new System.Drawing.Size(419, 23);
            this.tb_animation_name.TabIndex = 0;
            this.tb_animation_name.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // b_delete_button
            // 
            this.b_delete_button.BackColor = System.Drawing.SystemColors.ControlLight;
            this.b_delete_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_delete_button.Font = new System.Drawing.Font("MS UI Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.b_delete_button.Location = new System.Drawing.Point(529, 3);
            this.b_delete_button.Name = "b_delete_button";
            this.b_delete_button.Size = new System.Drawing.Size(57, 23);
            this.b_delete_button.TabIndex = 1;
            this.b_delete_button.Text = "削除";
            this.b_delete_button.UseVisualStyleBackColor = false;
            // 
            // UC_Animation_Inform_Bar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.b_delete_button);
            this.Controls.Add(this.tb_animation_name);
            this.Controls.Add(this.textBox1);
            this.Name = "UC_Animation_Inform_Bar";
            this.Size = new System.Drawing.Size(589, 29);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox tb_animation_name;
        private System.Windows.Forms.Button b_delete_button;
    }
}
