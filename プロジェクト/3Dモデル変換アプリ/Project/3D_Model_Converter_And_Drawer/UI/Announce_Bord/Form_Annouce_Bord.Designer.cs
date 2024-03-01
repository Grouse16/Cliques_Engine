namespace _3D_Model_Converter_And_Drawer.UI.Announce_Bord
{
    partial class Form_Announce_Bord
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
            this.TB_announce_text = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // TB_announce_text
            // 
            this.TB_announce_text.Enabled = false;
            this.TB_announce_text.Font = new System.Drawing.Font("MS UI Gothic", 20F);
            this.TB_announce_text.Location = new System.Drawing.Point(-10, -8);
            this.TB_announce_text.Name = "TB_announce_text";
            this.TB_announce_text.Size = new System.Drawing.Size(429, 41);
            this.TB_announce_text.TabIndex = 0;
            this.TB_announce_text.Text = "デフォルト";
            this.TB_announce_text.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form_Announce_Bord
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(410, 29);
            this.ControlBox = false;
            this.Controls.Add(this.TB_announce_text);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form_Announce_Bord";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TB_announce_text;
    }
}