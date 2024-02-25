namespace Shader_Setting_Generator.sampler_setting
{
    partial class UC_Sampler_Setting
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
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.TB_Sampler_Setting_Number = new System.Windows.Forms.TextBox();
            this.CB_Sampler_Setting = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(0, 22);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(128, 23);
            this.textBox3.TabIndex = 8;
            this.textBox3.Text = "UV設定";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox5.Location = new System.Drawing.Point(127, 0);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(240, 23);
            this.textBox5.TabIndex = 9;
            this.textBox5.Text = "サンプラー設定";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TB_Sampler_Setting_Number
            // 
            this.TB_Sampler_Setting_Number.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Sampler_Setting_Number.Location = new System.Drawing.Point(0, 0);
            this.TB_Sampler_Setting_Number.Name = "TB_Sampler_Setting_Number";
            this.TB_Sampler_Setting_Number.ReadOnly = true;
            this.TB_Sampler_Setting_Number.Size = new System.Drawing.Size(128, 23);
            this.TB_Sampler_Setting_Number.TabIndex = 10;
            this.TB_Sampler_Setting_Number.Text = "1";
            this.TB_Sampler_Setting_Number.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CB_Sampler_Setting
            // 
            this.CB_Sampler_Setting.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Sampler_Setting.DropDownWidth = 620;
            this.CB_Sampler_Setting.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.CB_Sampler_Setting.FormattingEnabled = true;
            this.CB_Sampler_Setting.Items.AddRange(new object[] {
            "WARP：UVが０～１を超えるとテクスチャをループする",
            "MIRROR：UVが０～１を超えるとテクスチャをループするが、繰り返すたびに反転する",
            "CLAMP：UVが０～１を超えるとテクスチャを強制的に０か１に戻す",
            "BORDER：UVが０～１を超えると黒色を返す",
            "MIRROR_ONCE：UVが０～１を超えると一度だけ反転したテクスチャを出す（ー１～０,１～２の時）"});
            this.CB_Sampler_Setting.Location = new System.Drawing.Point(127, 24);
            this.CB_Sampler_Setting.Name = "CB_Sampler_Setting";
            this.CB_Sampler_Setting.Size = new System.Drawing.Size(240, 24);
            this.CB_Sampler_Setting.TabIndex = 11;
            this.CB_Sampler_Setting.SelectedIndexChanged += new System.EventHandler(this.CB_Sampler_Setting_SelectedIndexChanged);
            // 
            // UC_Sampler_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.CB_Sampler_Setting);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.TB_Sampler_Setting_Number);
            this.Name = "UC_Sampler_Setting";
            this.Size = new System.Drawing.Size(366, 46);
            this.Load += new System.EventHandler(this.UC_Sampler_Setting_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox TB_Sampler_Setting_Number;
        private System.Windows.Forms.ComboBox CB_Sampler_Setting;
    }
}
