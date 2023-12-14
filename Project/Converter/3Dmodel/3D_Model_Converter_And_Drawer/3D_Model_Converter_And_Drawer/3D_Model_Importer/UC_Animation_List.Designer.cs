namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer
{
    partial class UC_Animation_List
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
            this.tb_print_animation_list = new System.Windows.Forms.TextBox();
            this.sb_animation_scroll_bar = new System.Windows.Forms.VScrollBar();
            this.b_import_box = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tb_print_animation_list
            // 
            this.tb_print_animation_list.Dock = System.Windows.Forms.DockStyle.Top;
            this.tb_print_animation_list.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.tb_print_animation_list.Location = new System.Drawing.Point(0, 0);
            this.tb_print_animation_list.Name = "tb_print_animation_list";
            this.tb_print_animation_list.ReadOnly = true;
            this.tb_print_animation_list.Size = new System.Drawing.Size(619, 23);
            this.tb_print_animation_list.TabIndex = 1;
            this.tb_print_animation_list.Text = "インポートアニメーションリスト";
            this.tb_print_animation_list.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // sb_animation_scroll_bar
            // 
            this.sb_animation_scroll_bar.Location = new System.Drawing.Point(599, 23);
            this.sb_animation_scroll_bar.Name = "sb_animation_scroll_bar";
            this.sb_animation_scroll_bar.Size = new System.Drawing.Size(20, 127);
            this.sb_animation_scroll_bar.TabIndex = 3;
            this.sb_animation_scroll_bar.ValueChanged += new System.EventHandler(this.sb_animation_scroll_bar_ValueChanged);
            // 
            // b_import_box
            // 
            this.b_import_box.BackColor = System.Drawing.SystemColors.ControlDark;
            this.b_import_box.Cursor = System.Windows.Forms.Cursors.No;
            this.b_import_box.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.b_import_box.Location = new System.Drawing.Point(0, 147);
            this.b_import_box.Name = "b_import_box";
            this.b_import_box.Size = new System.Drawing.Size(619, 100);
            this.b_import_box.TabIndex = 4;
            this.b_import_box.Text = "アニメーションをここにドラッグアンドドロップしてインポート";
            this.b_import_box.UseVisualStyleBackColor = false;
            this.b_import_box.DragDrop += new System.Windows.Forms.DragEventHandler(this.b_import_box_DragDrop);
            this.b_import_box.DragOver += new System.Windows.Forms.DragEventHandler(this.b_import_box_DragOver);
            // 
            // UC_Animation_List
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.b_import_box);
            this.Controls.Add(this.sb_animation_scroll_bar);
            this.Controls.Add(this.tb_print_animation_list);
            this.Name = "UC_Animation_List";
            this.Size = new System.Drawing.Size(619, 247);
            this.Load += new System.EventHandler(this.UC_Animation_List_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox tb_print_animation_list;
        private System.Windows.Forms.VScrollBar sb_animation_scroll_bar;
        private System.Windows.Forms.Button b_import_box;
    }
}
