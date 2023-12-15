namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer
{
    partial class Form_Animation_Model_Importer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.b_import_button = new System.Windows.Forms.Button();
            this.b_cancel_button = new System.Windows.Forms.Button();
            this.uC_Animation_List1 = new _3D_Model_Converter_And_Drawer._3D_Model_Importer.UC_Animation_List();
            this.SuspendLayout();
            // 
            // b_import_button
            // 
            this.b_import_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_import_button.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.b_import_button.Location = new System.Drawing.Point(464, 265);
            this.b_import_button.Name = "b_import_button";
            this.b_import_button.Size = new System.Drawing.Size(167, 99);
            this.b_import_button.TabIndex = 0;
            this.b_import_button.Text = "インポート";
            this.b_import_button.UseVisualStyleBackColor = true;
            this.b_import_button.Click += new System.EventHandler(this.b_model_import_button_Click);
            // 
            // b_cancel_button
            // 
            this.b_cancel_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b_cancel_button.Font = new System.Drawing.Font("MS UI Gothic", 9F, System.Drawing.FontStyle.Bold);
            this.b_cancel_button.Location = new System.Drawing.Point(29, 318);
            this.b_cancel_button.Name = "b_cancel_button";
            this.b_cancel_button.Size = new System.Drawing.Size(77, 34);
            this.b_cancel_button.TabIndex = 0;
            this.b_cancel_button.Text = "キャンセル";
            this.b_cancel_button.UseVisualStyleBackColor = true;
            this.b_cancel_button.Click += new System.EventHandler(this.b_cancel_button_Click);
            // 
            // uC_Animation_List1
            // 
            this.uC_Animation_List1.Location = new System.Drawing.Point(12, 12);
            this.uC_Animation_List1.MaximumSize = new System.Drawing.Size(619, 247);
            this.uC_Animation_List1.MinimumSize = new System.Drawing.Size(619, 247);
            this.uC_Animation_List1.Name = "uC_Animation_List1";
            this.uC_Animation_List1.Size = new System.Drawing.Size(619, 247);
            this.uC_Animation_List1.TabIndex = 1;
            // 
            // Form_3D_Model_Importer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(639, 375);
            this.Controls.Add(this.uC_Animation_List1);
            this.Controls.Add(this.b_cancel_button);
            this.Controls.Add(this.b_import_button);
            this.Name = "Form_3D_Model_Importer";
            this.Text = "アニメーションモデルインポートシステム";
            this.Load += new System.EventHandler(this.Form_3D_Model_Importer_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button b_import_button;
        private System.Windows.Forms.Button b_cancel_button;
        private UC_Animation_List uC_Animation_List1;
    }
}