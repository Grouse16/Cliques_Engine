namespace Shader_Setting_Generator
{
    partial class UC_Vertex_Setting
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
            this.TB_Number = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.CB_Byte_Format = new System.Windows.Forms.ComboBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.CB_Type_Format = new System.Windows.Forms.ComboBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.CB_Element = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(66, 0);
            this.textBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(338, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "変数レイアウト";
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // TB_Number
            // 
            this.TB_Number.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Number.Location = new System.Drawing.Point(0, 0);
            this.TB_Number.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.TB_Number.Name = "TB_Number";
            this.TB_Number.ReadOnly = true;
            this.TB_Number.Size = new System.Drawing.Size(68, 23);
            this.TB_Number.TabIndex = 0;
            this.TB_Number.Text = "1";
            this.TB_Number.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(0, 21);
            this.textBox3.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(68, 23);
            this.textBox3.TabIndex = 0;
            this.textBox3.Text = "バイト数";
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // CB_Byte_Format
            // 
            this.CB_Byte_Format.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Byte_Format.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Byte_Format.FormattingEnabled = true;
            this.CB_Byte_Format.Items.AddRange(new object[] {
            "1",
            "2",
            "4"});
            this.CB_Byte_Format.Location = new System.Drawing.Point(66, 21);
            this.CB_Byte_Format.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.CB_Byte_Format.Name = "CB_Byte_Format";
            this.CB_Byte_Format.Size = new System.Drawing.Size(338, 24);
            this.CB_Byte_Format.TabIndex = 1;
            this.CB_Byte_Format.SelectedIndexChanged += new System.EventHandler(this.CB_Byte_Format_SelectedIndexChanged);
            // 
            // textBox4
            // 
            this.textBox4.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox4.Location = new System.Drawing.Point(0, 43);
            this.textBox4.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(68, 23);
            this.textBox4.TabIndex = 0;
            this.textBox4.Text = "型";
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // CB_Type_Format
            // 
            this.CB_Type_Format.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Type_Format.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Type_Format.FormattingEnabled = true;
            this.CB_Type_Format.Items.AddRange(new object[] {
            "INT",
            "UINT",
            "FLOAT"});
            this.CB_Type_Format.Location = new System.Drawing.Point(66, 42);
            this.CB_Type_Format.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.CB_Type_Format.Name = "CB_Type_Format";
            this.CB_Type_Format.Size = new System.Drawing.Size(338, 24);
            this.CB_Type_Format.TabIndex = 1;
            this.CB_Type_Format.SelectedIndexChanged += new System.EventHandler(this.CB_Type_Format_SelectedIndexChanged);
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox5.Location = new System.Drawing.Point(-1, 64);
            this.textBox5.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(68, 23);
            this.textBox5.TabIndex = 0;
            this.textBox5.Text = "要素数";
            this.textBox5.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // CB_Element
            // 
            this.CB_Element.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Element.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Element.FormattingEnabled = true;
            this.CB_Element.Items.AddRange(new object[] {
            "x",
            "xy",
            "xyz",
            "xyzw"});
            this.CB_Element.Location = new System.Drawing.Point(66, 63);
            this.CB_Element.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.CB_Element.Name = "CB_Element";
            this.CB_Element.Size = new System.Drawing.Size(338, 24);
            this.CB_Element.TabIndex = 1;
            // 
            // UC_Vertex_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.CB_Element);
            this.Controls.Add(this.CB_Type_Format);
            this.Controls.Add(this.CB_Byte_Format);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.TB_Number);
            this.Controls.Add(this.textBox1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "UC_Vertex_Setting";
            this.Size = new System.Drawing.Size(403, 86);
            this.Load += new System.EventHandler(this.UC_Vertex_Setting_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox TB_Number;
        private System.Windows.Forms.TextBox textBox3;
        public System.Windows.Forms.ComboBox CB_Byte_Format;
        private System.Windows.Forms.TextBox textBox4;
        public System.Windows.Forms.ComboBox CB_Type_Format;
        private System.Windows.Forms.TextBox textBox5;
        public System.Windows.Forms.ComboBox CB_Element;
    }
}
