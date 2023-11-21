namespace Shader_Setting_Generator
{
    partial class UC_Vertex_Setting_List
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
            this.ScrollBar_Vertex_Setting = new System.Windows.Forms.VScrollBar();
            this.SuspendLayout();
            // 
            // ScrollBar_Vertex_Setting
            // 
            this.ScrollBar_Vertex_Setting.Dock = System.Windows.Forms.DockStyle.Right;
            this.ScrollBar_Vertex_Setting.LargeChange = 1;
            this.ScrollBar_Vertex_Setting.Location = new System.Drawing.Point(440, 0);
            this.ScrollBar_Vertex_Setting.Maximum = 0;
            this.ScrollBar_Vertex_Setting.Name = "ScrollBar_Vertex_Setting";
            this.ScrollBar_Vertex_Setting.Size = new System.Drawing.Size(21, 279);
            this.ScrollBar_Vertex_Setting.TabIndex = 0;
            this.ScrollBar_Vertex_Setting.Scroll += new System.Windows.Forms.ScrollEventHandler(this.ScrollBar_Vertex_Setting_Scroll);
            // 
            // UC_Vertex_Setting_List
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.Controls.Add(this.ScrollBar_Vertex_Setting);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "UC_Vertex_Setting_List";
            this.Size = new System.Drawing.Size(461, 279);
            this.Load += new System.EventHandler(this.UC_Vertex_Setting_List_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.VScrollBar ScrollBar_Vertex_Setting;
    }
}
