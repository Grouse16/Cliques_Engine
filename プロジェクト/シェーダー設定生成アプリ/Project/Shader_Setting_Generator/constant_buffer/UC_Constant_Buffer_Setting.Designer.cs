namespace Shader_Setting_Generator
{
    partial class UC_Constant_Buffer_Setting
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
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.CB_Constant_Data_Enough_Flg = new System.Windows.Forms.ComboBox();
            this.NM_Element_Sum = new System.Windows.Forms.NumericUpDown();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.TB_Constant_Buffer_Number = new System.Windows.Forms.TextBox();
            this.CB_Constant_Buffer_Name = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.NM_Element_Sum)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(0, 29);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(137, 27);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "定数バッファ名";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox2.Location = new System.Drawing.Point(1, 54);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(136, 27);
            this.textBox2.TabIndex = 0;
            this.textBox2.Text = "配列数";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(0, 81);
            this.textBox3.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(137, 27);
            this.textBox3.TabIndex = 0;
            this.textBox3.Text = "データが必要か";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CB_Constant_Data_Enough_Flg
            // 
            this.CB_Constant_Data_Enough_Flg.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Constant_Data_Enough_Flg.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Constant_Data_Enough_Flg.FormattingEnabled = true;
            this.CB_Constant_Data_Enough_Flg.Items.AddRange(new object[] {
            "true：定数データを生成する",
            "false：定数バッファのみ生成する"});
            this.CB_Constant_Data_Enough_Flg.Location = new System.Drawing.Point(136, 80);
            this.CB_Constant_Data_Enough_Flg.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.CB_Constant_Data_Enough_Flg.Name = "CB_Constant_Data_Enough_Flg";
            this.CB_Constant_Data_Enough_Flg.Size = new System.Drawing.Size(351, 28);
            this.CB_Constant_Data_Enough_Flg.TabIndex = 1;
            this.CB_Constant_Data_Enough_Flg.SelectedIndexChanged += new System.EventHandler(this.CB_Constant_Data_Enough_Flg_SelectedIndexChanged);
            // 
            // NM_Element_Sum
            // 
            this.NM_Element_Sum.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.NM_Element_Sum.Location = new System.Drawing.Point(136, 54);
            this.NM_Element_Sum.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.NM_Element_Sum.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.NM_Element_Sum.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.NM_Element_Sum.Name = "NM_Element_Sum";
            this.NM_Element_Sum.Size = new System.Drawing.Size(352, 27);
            this.NM_Element_Sum.TabIndex = 2;
            this.NM_Element_Sum.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NM_Element_Sum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.NM_Element_Sum.ValueChanged += new System.EventHandler(this.NM_Element_Sum_ValueChanged);
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox5.Location = new System.Drawing.Point(135, 0);
            this.textBox5.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(352, 27);
            this.textBox5.TabIndex = 0;
            this.textBox5.Text = "定数バッファ設定";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TB_Constant_Buffer_Number
            // 
            this.TB_Constant_Buffer_Number.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Constant_Buffer_Number.Location = new System.Drawing.Point(0, 0);
            this.TB_Constant_Buffer_Number.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TB_Constant_Buffer_Number.Name = "TB_Constant_Buffer_Number";
            this.TB_Constant_Buffer_Number.ReadOnly = true;
            this.TB_Constant_Buffer_Number.Size = new System.Drawing.Size(137, 27);
            this.TB_Constant_Buffer_Number.TabIndex = 0;
            this.TB_Constant_Buffer_Number.Text = "1";
            this.TB_Constant_Buffer_Number.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CB_Constant_Buffer_Name
            // 
            this.CB_Constant_Buffer_Name.DropDownWidth = 400;
            this.CB_Constant_Buffer_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Constant_Buffer_Name.FormattingEnabled = true;
            this.CB_Constant_Buffer_Name.Items.AddRange(new object[] {
            "CB_WBP：ワールド ビュー プロジェクション行列",
            "CB_BONE：ボーンマトリクス行列",
            "CB_AMBIENT_LIGHT：アンビエントライト",
            "CB_DIRECTIONAL_LIGHT：ディレクショナルライト",
            "CB_POINT_LIGHT：ポイントライト",
            "CB_SPOT_LIGHT：スポットライト",
            "CB_AREA_LIGHT：エリアライト"});
            this.CB_Constant_Buffer_Name.Location = new System.Drawing.Point(136, 28);
            this.CB_Constant_Buffer_Name.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.CB_Constant_Buffer_Name.Name = "CB_Constant_Buffer_Name";
            this.CB_Constant_Buffer_Name.Size = new System.Drawing.Size(351, 28);
            this.CB_Constant_Buffer_Name.TabIndex = 3;
            this.CB_Constant_Buffer_Name.Text = "Default";
            // 
            // UC_Constant_Buffer_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.CB_Constant_Buffer_Name);
            this.Controls.Add(this.NM_Element_Sum);
            this.Controls.Add(this.CB_Constant_Data_Enough_Flg);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.TB_Constant_Buffer_Number);
            this.Controls.Add(this.textBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "UC_Constant_Buffer_Setting";
            this.Size = new System.Drawing.Size(488, 110);
            this.Load += new System.EventHandler(this.UC_Constant_Buffer_Setting_Load);
            ((System.ComponentModel.ISupportInitialize)(this.NM_Element_Sum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.ComboBox CB_Constant_Data_Enough_Flg;
        private System.Windows.Forms.NumericUpDown NM_Element_Sum;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox TB_Constant_Buffer_Number;
        private System.Windows.Forms.ComboBox CB_Constant_Buffer_Name;
    }
}
