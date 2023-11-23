namespace Shader_Setting_Generator.constant_buffer
{
    partial class UC_Constant_Buffer_Setting_List
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
            this.SB_Constant_Buffer_Scroll = new System.Windows.Forms.VScrollBar();
            this.SuspendLayout();
            // 
            // SB_Constant_Buffer_Scroll
            // 
            this.SB_Constant_Buffer_Scroll.Dock = System.Windows.Forms.DockStyle.Right;
            this.SB_Constant_Buffer_Scroll.LargeChange = 2;
            this.SB_Constant_Buffer_Scroll.Location = new System.Drawing.Point(398, 0);
            this.SB_Constant_Buffer_Scroll.Maximum = 1;
            this.SB_Constant_Buffer_Scroll.Name = "SB_Constant_Buffer_Scroll";
            this.SB_Constant_Buffer_Scroll.Size = new System.Drawing.Size(17, 222);
            this.SB_Constant_Buffer_Scroll.TabIndex = 0;
            this.SB_Constant_Buffer_Scroll.Scroll += new System.Windows.Forms.ScrollEventHandler(this.SB_Constant_Buffer_Scroll_Scroll);
            // 
            // UC_Constant_Buffer_Setting_List
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.Controls.Add(this.SB_Constant_Buffer_Scroll);
            this.Name = "UC_Constant_Buffer_Setting_List";
            this.Size = new System.Drawing.Size(415, 222);
            this.Load += new System.EventHandler(this.UC_Constant_Buffer_Setting_List_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.VScrollBar SB_Constant_Buffer_Scroll;
    }
}
