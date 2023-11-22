namespace Shader_Setting_Generator
{
    partial class UC_Shader_Setting
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
            this.CB_Setting_Shader_Kind = new System.Windows.Forms.ComboBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.CL_Active_Shader_List = new System.Windows.Forms.CheckedListBox();
            this.TB_Setting_Shader_Name = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(876, 23);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "シェーダーリソース設定";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox2.Location = new System.Drawing.Point(0, 23);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(415, 23);
            this.textBox2.TabIndex = 1;
            this.textBox2.Text = "設定するシェーダーの種類";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CB_Setting_Shader_Kind
            // 
            this.CB_Setting_Shader_Kind.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawVariable;
            this.CB_Setting_Shader_Kind.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CB_Setting_Shader_Kind.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CB_Setting_Shader_Kind.FormattingEnabled = true;
            this.CB_Setting_Shader_Kind.Items.AddRange(new object[] {
            "頂点シェーダー　Vertex Shader",
            "ハルシェーダー　Hul Shader",
            "ドメインシェーダー　Domain Shader",
            "ジオメトリシェーダー　Geometry Shader",
            "ピクセルシェーダー　Pixel Shader"});
            this.CB_Setting_Shader_Kind.Location = new System.Drawing.Point(1, 46);
            this.CB_Setting_Shader_Kind.Name = "CB_Setting_Shader_Kind";
            this.CB_Setting_Shader_Kind.Size = new System.Drawing.Size(414, 24);
            this.CB_Setting_Shader_Kind.TabIndex = 2;
            this.CB_Setting_Shader_Kind.SelectedIndexChanged += new System.EventHandler(this.CB_Setting_Shader_Kind_SelectedIndexChanged);
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.textBox3.Location = new System.Drawing.Point(414, 23);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(462, 23);
            this.textBox3.TabIndex = 1;
            this.textBox3.Text = "有効なシェーダーの種類";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CL_Active_Shader_List
            // 
            this.CL_Active_Shader_List.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.CL_Active_Shader_List.FormattingEnabled = true;
            this.CL_Active_Shader_List.Items.AddRange(new object[] {
            "頂点シェーダー　Vertex Shader",
            "ハルシェーダー　Hul Shader",
            "ドメインシェーダー　Domain Shader",
            "ジオメトリシェーダー　Geometry Shader",
            "ピクセルシェーダー　Pixel Shader"});
            this.CL_Active_Shader_List.Location = new System.Drawing.Point(414, 46);
            this.CL_Active_Shader_List.Name = "CL_Active_Shader_List";
            this.CL_Active_Shader_List.Size = new System.Drawing.Size(462, 94);
            this.CL_Active_Shader_List.TabIndex = 3;
            // 
            // TB_Setting_Shader_Name
            // 
            this.TB_Setting_Shader_Name.Font = new System.Drawing.Font("MS UI Gothic", 12F);
            this.TB_Setting_Shader_Name.Location = new System.Drawing.Point(1, 140);
            this.TB_Setting_Shader_Name.Name = "TB_Setting_Shader_Name";
            this.TB_Setting_Shader_Name.ReadOnly = true;
            this.TB_Setting_Shader_Name.Size = new System.Drawing.Size(876, 23);
            this.TB_Setting_Shader_Name.TabIndex = 4;
            this.TB_Setting_Shader_Name.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // UC_Shader_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.Controls.Add(this.TB_Setting_Shader_Name);
            this.Controls.Add(this.CL_Active_Shader_List);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.CB_Setting_Shader_Kind);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Name = "UC_Shader_Setting";
            this.Size = new System.Drawing.Size(876, 627);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.ComboBox CB_Setting_Shader_Kind;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.CheckedListBox CL_Active_Shader_List;
        private System.Windows.Forms.TextBox TB_Setting_Shader_Name;
    }
}
