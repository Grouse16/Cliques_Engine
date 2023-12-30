namespace _3D_Model_Converter_And_Drawer.d3d11
{
    partial class UC_DX_11_Panel
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
            this.b_draw_position_viewer = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // b_draw_position_viewer
            // 
            this.b_draw_position_viewer.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.b_draw_position_viewer.Font = new System.Drawing.Font("MS UI Gothic", 20F);
            this.b_draw_position_viewer.Location = new System.Drawing.Point(0, 0);
            this.b_draw_position_viewer.Name = "b_draw_position_viewer";
            this.b_draw_position_viewer.Size = new System.Drawing.Size(524, 392);
            this.b_draw_position_viewer.TabIndex = 0;
            this.b_draw_position_viewer.Text = "DX11描画範囲";
            this.b_draw_position_viewer.UseVisualStyleBackColor = false;
            // 
            // UC_New_DX_11_Panel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.b_draw_position_viewer);
            this.Name = "UC_New_DX_11_Panel";
            this.Size = new System.Drawing.Size(524, 392);
            this.Load += new System.EventHandler(this.UC_New_DX_11_Panel_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button b_draw_position_viewer;
    }
}
