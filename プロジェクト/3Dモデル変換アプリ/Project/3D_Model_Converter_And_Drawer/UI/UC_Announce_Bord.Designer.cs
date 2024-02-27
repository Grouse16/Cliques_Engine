namespace _3D_Model_Converter_And_Drawer.UI
{
    partial class UC_Announce_Bord
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
            this.TB_announce = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // TB_announce
            // 
            this.TB_announce.Font = new System.Drawing.Font("MS UI Gothic", 16F);
            this.TB_announce.Location = new System.Drawing.Point(3, 3);
            this.TB_announce.Name = "TB_announce";
            this.TB_announce.ReadOnly = true;
            this.TB_announce.Size = new System.Drawing.Size(377, 34);
            this.TB_announce.TabIndex = 0;
            this.TB_announce.Text = "ベーステキスト";
            // 
            // UC_Announce_Bord
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.TB_announce);
            this.Name = "UC_Announce_Bord";
            this.Size = new System.Drawing.Size(385, 40);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TB_announce;
    }
}
