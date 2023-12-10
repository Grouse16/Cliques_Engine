namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    partial class UC_Name_Setting
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
            this.TB_material_number.Location = new System.Drawing.Point(3, 3);
            this.TB_material_number.Name = "TB_material_number";
            this.TB_material_number.ReadOnly = true;
            this.TB_material_number.Size = new System.Drawing.Size(69, 19);
            this.TB_material_number.TabIndex = 0;
            // 
            // TB_material_name
            // 
            this.TB_material_name.Location = new System.Drawing.Point(78, 3);
            this.TB_material_name.Name = "TB_material_name";
            this.TB_material_name.Size = new System.Drawing.Size(368, 19);
            this.TB_material_name.TabIndex = 1;
            // 
            // UC_Name_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.TB_material_name);
            this.Controls.Add(this.TB_material_number);
            this.Name = "UC_Name_Setting";
            this.Size = new System.Drawing.Size(449, 23);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TB_material_number;
        private System.Windows.Forms.TextBox TB_material_name;
    }
}
