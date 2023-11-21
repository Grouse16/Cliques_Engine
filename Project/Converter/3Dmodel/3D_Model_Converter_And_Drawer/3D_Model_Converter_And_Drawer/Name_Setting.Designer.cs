namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    partial class Name_Setting
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
            this.TB_material_number = new System.Windows.Forms.TextBox();
            this.TB_material_name = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // TB_material_number
            // 
            this.TB_material_number.Location = new System.Drawing.Point(4, 4);
            this.TB_material_number.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TB_material_number.Name = "TB_material_number";
            this.TB_material_number.ReadOnly = true;
            this.TB_material_number.Size = new System.Drawing.Size(132, 22);
            this.TB_material_number.TabIndex = 0;
            this.TB_material_number.TextChanged += new System.EventHandler(this.TB_material_number_TextChanged);
            // 
            // TB_material_name
            // 
            this.TB_material_name.Location = new System.Drawing.Point(145, 4);
            this.TB_material_name.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TB_material_name.Name = "TB_material_name";
            this.TB_material_name.Size = new System.Drawing.Size(448, 22);
            this.TB_material_name.TabIndex = 1;
            this.TB_material_name.TextChanged += new System.EventHandler(this.TB_material_name_TextChanged);
            // 
            // Name_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.TB_material_name);
            this.Controls.Add(this.TB_material_number);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Name_Setting";
            this.Size = new System.Drawing.Size(599, 29);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TB_material_number;
        private System.Windows.Forms.TextBox TB_material_name;
    }
}
