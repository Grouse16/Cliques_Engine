namespace ELMaterial_Generator.Blend_Setting_UI
{
    partial class UC_Blend_Setting_Frame
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
            this.TB_blend_setting = new System.Windows.Forms.TextBox();
            this.SB_scroll = new System.Windows.Forms.VScrollBar();
            this.TB_blend_sum = new System.Windows.Forms.TextBox();
            this.NUM_blend_sum_setting = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.NUM_blend_sum_setting)).BeginInit();
            this.SuspendLayout();
            // 
            // TB_blend_setting
            // 
            this.TB_blend_setting.Dock = System.Windows.Forms.DockStyle.Top;
            this.TB_blend_setting.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_blend_setting.Location = new System.Drawing.Point(0, 0);
            this.TB_blend_setting.Name = "TB_blend_setting";
            this.TB_blend_setting.ReadOnly = true;
            this.TB_blend_setting.Size = new System.Drawing.Size(394, 23);
            this.TB_blend_setting.TabIndex = 1;
            this.TB_blend_setting.Text = "ブレンド設定";
            // 
            // SB_scroll
            // 
            this.SB_scroll.Dock = System.Windows.Forms.DockStyle.Right;
            this.SB_scroll.LargeChange = 2;
            this.SB_scroll.Location = new System.Drawing.Point(377, 23);
            this.SB_scroll.Maximum = 1;
            this.SB_scroll.Name = "SB_scroll";
            this.SB_scroll.Size = new System.Drawing.Size(17, 127);
            this.SB_scroll.TabIndex = 2;
            this.SB_scroll.Scroll += new System.Windows.Forms.ScrollEventHandler(this.SB_scroll_Scroll);
            // 
            // TB_blend_sum
            // 
            this.TB_blend_sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_blend_sum.Location = new System.Drawing.Point(221, 0);
            this.TB_blend_sum.Name = "TB_blend_sum";
            this.TB_blend_sum.ReadOnly = true;
            this.TB_blend_sum.Size = new System.Drawing.Size(102, 23);
            this.TB_blend_sum.TabIndex = 6;
            this.TB_blend_sum.Text = "ブレンド設定数";
            // 
            // NUM_blend_sum_setting
            // 
            this.NUM_blend_sum_setting.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NUM_blend_sum_setting.Location = new System.Drawing.Point(322, 0);
            this.NUM_blend_sum_setting.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.NUM_blend_sum_setting.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.NUM_blend_sum_setting.Name = "NUM_blend_sum_setting";
            this.NUM_blend_sum_setting.Size = new System.Drawing.Size(72, 23);
            this.NUM_blend_sum_setting.TabIndex = 7;
            this.NUM_blend_sum_setting.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // UC_Blend_Setting_Frame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.Controls.Add(this.NUM_blend_sum_setting);
            this.Controls.Add(this.TB_blend_sum);
            this.Controls.Add(this.SB_scroll);
            this.Controls.Add(this.TB_blend_setting);
            this.Name = "UC_Blend_Setting_Frame";
            this.Size = new System.Drawing.Size(394, 150);
            ((System.ComponentModel.ISupportInitialize)(this.NUM_blend_sum_setting)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox TB_blend_setting;
        private System.Windows.Forms.VScrollBar SB_scroll;
        private System.Windows.Forms.TextBox TB_blend_sum;
        private System.Windows.Forms.NumericUpDown NUM_blend_sum_setting;
    }
}
