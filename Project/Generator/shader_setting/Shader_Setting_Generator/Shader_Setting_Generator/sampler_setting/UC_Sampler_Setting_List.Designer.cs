namespace Shader_Setting_Generator.sampler_setting
{
    partial class UC_Sampler_Setting_List
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
            this.SB_Sampler_Scroll_Bar = new System.Windows.Forms.VScrollBar();
            this.SuspendLayout();
            // 
            // SB_Sampler_Scroll_Bar
            // 
            this.SB_Sampler_Scroll_Bar.Dock = System.Windows.Forms.DockStyle.Right;
            this.SB_Sampler_Scroll_Bar.LargeChange = 2;
            this.SB_Sampler_Scroll_Bar.Location = new System.Drawing.Point(394, 0);
            this.SB_Sampler_Scroll_Bar.Maximum = 1;
            this.SB_Sampler_Scroll_Bar.Name = "SB_Sampler_Scroll_Bar";
            this.SB_Sampler_Scroll_Bar.Size = new System.Drawing.Size(17, 139);
            this.SB_Sampler_Scroll_Bar.TabIndex = 0;
            this.SB_Sampler_Scroll_Bar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.SB_Sampler_Scroll_Bar_Scroll);
            // 
            // UC_Sampler_Setting_List
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.Controls.Add(this.SB_Sampler_Scroll_Bar);
            this.Name = "UC_Sampler_Setting_List";
            this.Size = new System.Drawing.Size(411, 139);
            this.Load += new System.EventHandler(this.UC_Sampler_Setting_List_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.VScrollBar SB_Sampler_Scroll_Bar;
    }
}
