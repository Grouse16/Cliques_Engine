namespace _3D_Model_Converter_And_Drawer
{
    partial class Main_Form
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

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.tb_print_model_viewer = new System.Windows.Forms.TextBox();
            this.tb_print_camera_setting = new System.Windows.Forms.TextBox();
            this.tb_print_camera_distance = new System.Windows.Forms.TextBox();
            this.tb_print_camera_position = new System.Windows.Forms.TextBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.tb_print_animation_blend = new System.Windows.Forms.TextBox();
            this.tb_print_animation_01_times = new System.Windows.Forms.TextBox();
            this.tb_print_animation_02_time = new System.Windows.Forms.TextBox();
            this.tb_print_animation_01_name = new System.Windows.Forms.TextBox();
            this.tb_print_animation_02_name = new System.Windows.Forms.TextBox();
            this.trackBar3 = new System.Windows.Forms.TrackBar();
            this.trackBar4 = new System.Windows.Forms.TrackBar();
            this.tb_print_animation_blend_percent = new System.Windows.Forms.TextBox();
            this.trackBar5 = new System.Windows.Forms.TrackBar();
            this.b_model_converter = new System.Windows.Forms.Button();
            this.b_model_importer = new System.Windows.Forms.Button();
            this.tb_print_model_importer = new System.Windows.Forms.TextBox();
            this.tb_print_model_converter = new System.Windows.Forms.TextBox();
            this.uc_load_inform_box = new _3D_Model_Converter_And_Drawer.FormTool.UC_Load_Inform_Box();
            this.uc_dx_11_panel = new _3D_Model_Converter_And_Drawer.d3d11.UC_DX_11_Panel();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar5)).BeginInit();
            this.SuspendLayout();
            // 
            // tb_print_model_viewer
            // 
            this.tb_print_model_viewer.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_model_viewer.Location = new System.Drawing.Point(282, 0);
            this.tb_print_model_viewer.Name = "tb_print_model_viewer";
            this.tb_print_model_viewer.Size = new System.Drawing.Size(527, 19);
            this.tb_print_model_viewer.TabIndex = 1;
            this.tb_print_model_viewer.Text = "モデルビュワー";
            // 
            // tb_print_camera_setting
            // 
            this.tb_print_camera_setting.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_camera_setting.Location = new System.Drawing.Point(-1, 407);
            this.tb_print_camera_setting.Name = "tb_print_camera_setting";
            this.tb_print_camera_setting.Size = new System.Drawing.Size(527, 19);
            this.tb_print_camera_setting.TabIndex = 1;
            this.tb_print_camera_setting.Text = "カメラ設定";
            // 
            // tb_print_camera_distance
            // 
            this.tb_print_camera_distance.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_camera_distance.Location = new System.Drawing.Point(-1, 426);
            this.tb_print_camera_distance.Name = "tb_print_camera_distance";
            this.tb_print_camera_distance.Size = new System.Drawing.Size(258, 19);
            this.tb_print_camera_distance.TabIndex = 1;
            this.tb_print_camera_distance.Text = "カメラ距離";
            // 
            // tb_print_camera_position
            // 
            this.tb_print_camera_position.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_camera_position.Location = new System.Drawing.Point(253, 426);
            this.tb_print_camera_position.Name = "tb_print_camera_position";
            this.tb_print_camera_position.Size = new System.Drawing.Size(272, 19);
            this.tb_print_camera_position.TabIndex = 1;
            this.tb_print_camera_position.Text = "カメラ位置（roll）";
            // 
            // trackBar1
            // 
            this.trackBar1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.trackBar1.Location = new System.Drawing.Point(0, 443);
            this.trackBar1.Maximum = 100;
            this.trackBar1.Minimum = 10;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(258, 45);
            this.trackBar1.TabIndex = 4;
            this.trackBar1.Value = 10;
            // 
            // trackBar2
            // 
            this.trackBar2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.trackBar2.Location = new System.Drawing.Point(254, 443);
            this.trackBar2.Maximum = 360;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(272, 45);
            this.trackBar2.TabIndex = 4;
            // 
            // tb_print_animation_blend
            // 
            this.tb_print_animation_blend.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_blend.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_blend.Location = new System.Drawing.Point(0, 487);
            this.tb_print_animation_blend.Name = "tb_print_animation_blend";
            this.tb_print_animation_blend.Size = new System.Drawing.Size(876, 19);
            this.tb_print_animation_blend.TabIndex = 1;
            this.tb_print_animation_blend.Text = "アニメーションブレンド";
            // 
            // tb_print_animation_01_times
            // 
            this.tb_print_animation_01_times.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_01_times.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_01_times.Location = new System.Drawing.Point(1, 506);
            this.tb_print_animation_01_times.Name = "tb_print_animation_01_times";
            this.tb_print_animation_01_times.Size = new System.Drawing.Size(125, 19);
            this.tb_print_animation_01_times.TabIndex = 1;
            this.tb_print_animation_01_times.Text = "アニメーション１経過時間";
            // 
            // tb_print_animation_02_time
            // 
            this.tb_print_animation_02_time.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_02_time.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_02_time.Location = new System.Drawing.Point(300, 506);
            this.tb_print_animation_02_time.Name = "tb_print_animation_02_time";
            this.tb_print_animation_02_time.Size = new System.Drawing.Size(127, 19);
            this.tb_print_animation_02_time.TabIndex = 1;
            this.tb_print_animation_02_time.Text = "アニメーション２経過時間";
            // 
            // tb_print_animation_01_name
            // 
            this.tb_print_animation_01_name.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_01_name.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_01_name.Location = new System.Drawing.Point(124, 506);
            this.tb_print_animation_01_name.Name = "tb_print_animation_01_name";
            this.tb_print_animation_01_name.Size = new System.Drawing.Size(178, 19);
            this.tb_print_animation_01_name.TabIndex = 1;
            this.tb_print_animation_01_name.Text = "アニメーション名";
            // 
            // tb_print_animation_02_name
            // 
            this.tb_print_animation_02_name.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_02_name.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_02_name.Location = new System.Drawing.Point(424, 505);
            this.tb_print_animation_02_name.Name = "tb_print_animation_02_name";
            this.tb_print_animation_02_name.Size = new System.Drawing.Size(177, 19);
            this.tb_print_animation_02_name.TabIndex = 1;
            this.tb_print_animation_02_name.Text = "アニメーション名";
            // 
            // trackBar3
            // 
            this.trackBar3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.trackBar3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.trackBar3.Location = new System.Drawing.Point(0, 522);
            this.trackBar3.Maximum = 120;
            this.trackBar3.Name = "trackBar3";
            this.trackBar3.Size = new System.Drawing.Size(300, 45);
            this.trackBar3.TabIndex = 4;
            // 
            // trackBar4
            // 
            this.trackBar4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.trackBar4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.trackBar4.Location = new System.Drawing.Point(300, 522);
            this.trackBar4.Maximum = 120;
            this.trackBar4.Name = "trackBar4";
            this.trackBar4.Size = new System.Drawing.Size(301, 45);
            this.trackBar4.TabIndex = 4;
            // 
            // tb_print_animation_blend_percent
            // 
            this.tb_print_animation_blend_percent.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tb_print_animation_blend_percent.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_animation_blend_percent.Location = new System.Drawing.Point(602, 505);
            this.tb_print_animation_blend_percent.Name = "tb_print_animation_blend_percent";
            this.tb_print_animation_blend_percent.Size = new System.Drawing.Size(274, 19);
            this.tb_print_animation_blend_percent.TabIndex = 1;
            this.tb_print_animation_blend_percent.Text = "アニメーションブレンド率";
            // 
            // trackBar5
            // 
            this.trackBar5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.trackBar5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.trackBar5.Location = new System.Drawing.Point(601, 522);
            this.trackBar5.Maximum = 100;
            this.trackBar5.Name = "trackBar5";
            this.trackBar5.Size = new System.Drawing.Size(274, 45);
            this.trackBar5.TabIndex = 4;
            // 
            // b_model_converter
            // 
            this.b_model_converter.AllowDrop = true;
            this.b_model_converter.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.b_model_converter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.b_model_converter.Cursor = System.Windows.Forms.Cursors.No;
            this.b_model_converter.Font = new System.Drawing.Font("MS UI Gothic", 11F);
            this.b_model_converter.Location = new System.Drawing.Point(900, 310);
            this.b_model_converter.Name = "b_model_converter";
            this.b_model_converter.Size = new System.Drawing.Size(180, 123);
            this.b_model_converter.TabIndex = 0;
            this.b_model_converter.Text = "変換するモデルファイルを\r\nドラッグアンドドロップ\r\n\r\nfbx, obj, dxfなど";
            this.b_model_converter.UseVisualStyleBackColor = false;
            this.b_model_converter.DragDrop += new System.Windows.Forms.DragEventHandler(this.B_Model_Converter_DragDrop);
            this.b_model_converter.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // b_model_importer
            // 
            this.b_model_importer.AllowDrop = true;
            this.b_model_importer.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.b_model_importer.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.b_model_importer.Cursor = System.Windows.Forms.Cursors.No;
            this.b_model_importer.Font = new System.Drawing.Font("MS UI Gothic", 11F);
            this.b_model_importer.Location = new System.Drawing.Point(902, 448);
            this.b_model_importer.Name = "b_model_importer";
            this.b_model_importer.Size = new System.Drawing.Size(178, 123);
            this.b_model_importer.TabIndex = 0;
            this.b_model_importer.Text = "読み込むモデルファイルを\r\nドラッグアンドドロップ\r\n\r\nelsttmdl\r\nelanmmdl\r\nelanmdt";
            this.b_model_importer.UseVisualStyleBackColor = false;
            this.b_model_importer.DragDrop += new System.Windows.Forms.DragEventHandler(this.B_Model_Importer_DragDrop);
            this.b_model_importer.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // tb_print_model_importer
            // 
            this.tb_print_model_importer.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_model_importer.Location = new System.Drawing.Point(902, 432);
            this.tb_print_model_importer.Name = "tb_print_model_importer";
            this.tb_print_model_importer.Size = new System.Drawing.Size(178, 19);
            this.tb_print_model_importer.TabIndex = 1;
            this.tb_print_model_importer.Text = "モデルインポーター";
            // 
            // tb_print_model_converter
            // 
            this.tb_print_model_converter.BackColor = System.Drawing.SystemColors.Menu;
            this.tb_print_model_converter.Location = new System.Drawing.Point(900, 294);
            this.tb_print_model_converter.Name = "tb_print_model_converter";
            this.tb_print_model_converter.Size = new System.Drawing.Size(180, 19);
            this.tb_print_model_converter.TabIndex = 1;
            this.tb_print_model_converter.Text = "モデルコンバーター";
            // 
            // uc_load_inform_box
            // 
            this.uc_load_inform_box.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.uc_load_inform_box.Location = new System.Drawing.Point(0, 572);
            this.uc_load_inform_box.Margin = new System.Windows.Forms.Padding(4);
            this.uc_load_inform_box.MaximumSize = new System.Drawing.Size(1081, 54);
            this.uc_load_inform_box.MinimumSize = new System.Drawing.Size(1081, 54);
            this.uc_load_inform_box.Name = "uc_load_inform_box";
            this.uc_load_inform_box.Size = new System.Drawing.Size(1081, 54);
            this.uc_load_inform_box.TabIndex = 12;
            // 
            // uc_dx_11_panel
            // 
            this.uc_dx_11_panel.Location = new System.Drawing.Point(283, 17);
            this.uc_dx_11_panel.Name = "uc_dx_11_panel";
            this.uc_dx_11_panel.Size = new System.Drawing.Size(524, 392);
            this.uc_dx_11_panel.TabIndex = 13;
            // 
            // Main_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1082, 626);
            this.Controls.Add(this.uc_dx_11_panel);
            this.Controls.Add(this.tb_print_camera_setting);
            this.Controls.Add(this.tb_print_camera_position);
            this.Controls.Add(this.tb_print_camera_distance);
            this.Controls.Add(this.uc_load_inform_box);
            this.Controls.Add(this.tb_print_model_viewer);
            this.Controls.Add(this.tb_print_animation_02_time);
            this.Controls.Add(this.tb_print_animation_blend_percent);
            this.Controls.Add(this.tb_print_animation_02_name);
            this.Controls.Add(this.tb_print_animation_01_name);
            this.Controls.Add(this.tb_print_animation_01_times);
            this.Controls.Add(this.tb_print_animation_blend);
            this.Controls.Add(this.trackBar5);
            this.Controls.Add(this.trackBar4);
            this.Controls.Add(this.trackBar3);
            this.Controls.Add(this.tb_print_model_converter);
            this.Controls.Add(this.tb_print_model_importer);
            this.Controls.Add(this.b_model_importer);
            this.Controls.Add(this.b_model_converter);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.trackBar1);
            this.MaximizeBox = false;
            this.Name = "Main_Form";
            this.Text = "３Dモデル編集システム";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar5)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox tb_print_model_viewer;
        private System.Windows.Forms.TextBox tb_print_camera_setting;
        private System.Windows.Forms.TextBox tb_print_camera_distance;
        private System.Windows.Forms.TextBox tb_print_camera_position;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.TextBox tb_print_animation_blend;
        private System.Windows.Forms.TextBox tb_print_animation_01_times;
        private System.Windows.Forms.TextBox tb_print_animation_02_time;
        private System.Windows.Forms.TextBox tb_print_animation_01_name;
        private System.Windows.Forms.TextBox tb_print_animation_02_name;
        private System.Windows.Forms.TrackBar trackBar3;
        private System.Windows.Forms.TrackBar trackBar4;
        private System.Windows.Forms.TextBox tb_print_animation_blend_percent;
        private System.Windows.Forms.TrackBar trackBar5;
        private FormTool.UC_Load_Inform_Box uc_load_inform_box;
        private System.Windows.Forms.Button b_model_converter;
        private System.Windows.Forms.Button b_model_importer;
        private System.Windows.Forms.TextBox tb_print_model_importer;
        private System.Windows.Forms.TextBox tb_print_model_converter;
        private d3d11.UC_DX_11_Panel uc_dx_11_panel;
    }
}

