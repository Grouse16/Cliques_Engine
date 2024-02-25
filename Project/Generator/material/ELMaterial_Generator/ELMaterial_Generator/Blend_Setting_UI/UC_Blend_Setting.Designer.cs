namespace ELMaterial_Generator.Blend_Setting_UI
{
    partial class UC_Blend_Setting
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
            this.CB_write_setting = new System.Windows.Forms.ComboBox();
            this.TB_Write_Setting_Text = new System.Windows.Forms.TextBox();
            this.TB_Blend_Setting_Text = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // CB_write_setting
            // 
            this.CB_write_setting.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_write_setting.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_write_setting.FormattingEnabled = true;
            this.CB_write_setting.IntegralHeight = false;
            this.CB_write_setting.Items.AddRange(new object[] {
            "加法混色",
            "減法混色"});
            this.CB_write_setting.Location = new System.Drawing.Point(97, 22);
            this.CB_write_setting.Name = "CB_write_setting";
            this.CB_write_setting.Size = new System.Drawing.Size(254, 24);
            this.CB_write_setting.TabIndex = 2;
            // 
            // TB_Write_Setting_Text
            // 
            this.TB_Write_Setting_Text.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Write_Setting_Text.Location = new System.Drawing.Point(0, 23);
            this.TB_Write_Setting_Text.Name = "TB_Write_Setting_Text";
            this.TB_Write_Setting_Text.ReadOnly = true;
            this.TB_Write_Setting_Text.Size = new System.Drawing.Size(100, 23);
            this.TB_Write_Setting_Text.TabIndex = 3;
            this.TB_Write_Setting_Text.Text = "書き込み設定";
            // 
            // TB_Blend_Setting_Text
            // 
            this.TB_Blend_Setting_Text.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Blend_Setting_Text.Location = new System.Drawing.Point(0, 0);
            this.TB_Blend_Setting_Text.Name = "TB_Blend_Setting_Text";
            this.TB_Blend_Setting_Text.ReadOnly = true;
            this.TB_Blend_Setting_Text.Size = new System.Drawing.Size(351, 23);
            this.TB_Blend_Setting_Text.TabIndex = 3;
            this.TB_Blend_Setting_Text.Text = "ブレンド設定 <１>";
            // 
            // UC_Blend_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.CB_write_setting);
            this.Controls.Add(this.TB_Blend_Setting_Text);
            this.Controls.Add(this.TB_Write_Setting_Text);
            this.Name = "UC_Blend_Setting";
            this.Size = new System.Drawing.Size(352, 47);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ComboBox CB_write_setting;
        private System.Windows.Forms.TextBox TB_Write_Setting_Text;
        private System.Windows.Forms.TextBox TB_Blend_Setting_Text;
    }
}
