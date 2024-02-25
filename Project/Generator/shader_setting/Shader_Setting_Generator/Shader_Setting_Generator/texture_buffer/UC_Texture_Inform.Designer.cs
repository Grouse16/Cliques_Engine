namespace Shader_Setting_Generator.texture_buffer
{
    partial class UC_Texture_Inform
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
            this.CB_Use_Texture = new System.Windows.Forms.ComboBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.TB_Texture_Buffer_Number = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.CB_Texture_Name = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // CB_Use_Texture
            // 
            this.CB_Use_Texture.DropDownWidth = 500;
            this.CB_Use_Texture.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Use_Texture.FormattingEnabled = true;
            this.CB_Use_Texture.Items.AddRange(new object[] {
            "NOTHING：テクスチャを使用するが初期ロードはしない",
            "ORIGINAL：ゲーム内で生成したテクスチャを使用する。　RSC時は無効",
            "＊＊：＊＊に直接入力して初期ロードするテクスチャの名前を設定　RSC時は無効"});
            this.CB_Use_Texture.Location = new System.Drawing.Point(126, 44);
            this.CB_Use_Texture.Name = "CB_Use_Texture";
            this.CB_Use_Texture.Size = new System.Drawing.Size(239, 24);
            this.CB_Use_Texture.TabIndex = 5;
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(-1, 22);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(128, 23);
            this.textBox3.TabIndex = 2;
            this.textBox3.Text = "テクスチャバッファ名";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox5.Location = new System.Drawing.Point(126, 0);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(240, 23);
            this.textBox5.TabIndex = 3;
            this.textBox5.Text = "テクスチャバッファ設定";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TB_Texture_Buffer_Number
            // 
            this.TB_Texture_Buffer_Number.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Texture_Buffer_Number.Location = new System.Drawing.Point(-1, 0);
            this.TB_Texture_Buffer_Number.Name = "TB_Texture_Buffer_Number";
            this.TB_Texture_Buffer_Number.ReadOnly = true;
            this.TB_Texture_Buffer_Number.Size = new System.Drawing.Size(128, 23);
            this.TB_Texture_Buffer_Number.TabIndex = 4;
            this.TB_Texture_Buffer_Number.Text = "1";
            this.TB_Texture_Buffer_Number.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(-1, 45);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(128, 23);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "初期テクスチャ名";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CB_Texture_Name
            // 
            this.CB_Texture_Name.DropDownWidth = 560;
            this.CB_Texture_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Texture_Name.FormattingEnabled = true;
            this.CB_Texture_Name.Items.AddRange(new object[] {
            "＊＊：テクスチャスロットの名前を設定（＊＊に名前を設定可能）",
            "RSC_＊＊：レンダリングした画像をセットするスロット（＊＊に名前を設定可能）",
            "DSB_＊＊：深度ステンシルのテクスチャをセットするスロット（＊＊に名前を設定可能）"});
            this.CB_Texture_Name.Location = new System.Drawing.Point(126, 20);
            this.CB_Texture_Name.Margin = new System.Windows.Forms.Padding(2);
            this.CB_Texture_Name.Name = "CB_Texture_Name";
            this.CB_Texture_Name.Size = new System.Drawing.Size(241, 24);
            this.CB_Texture_Name.TabIndex = 6;
            // 
            // UC_Texture_Inform
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.CB_Texture_Name);
            this.Controls.Add(this.CB_Use_Texture);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.TB_Texture_Buffer_Number);
            this.Name = "UC_Texture_Inform";
            this.Size = new System.Drawing.Size(366, 69);
            this.Load += new System.EventHandler(this.UC_Texture_Inform_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox CB_Use_Texture;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox TB_Texture_Buffer_Number;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ComboBox CB_Texture_Name;
    }
}
