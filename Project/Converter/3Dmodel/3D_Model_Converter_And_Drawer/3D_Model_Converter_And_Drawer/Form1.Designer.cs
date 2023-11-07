namespace _3D_Model_Converter_And_Drawer
{
    partial class Form1
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
            this.B_Model_Converter = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.TB_before_convert_path = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.TB_after_convert_path = new System.Windows.Forms.TextBox();
            this.B_Animation_Converter = new System.Windows.Forms.Button();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.B_Model_Importer = new System.Windows.Forms.Button();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.B_Animation_Importer_1 = new System.Windows.Forms.Button();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.d3D11Panel1 = new SharpDXSample.D3D11Panel();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.textBox11 = new System.Windows.Forms.TextBox();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.textBox13 = new System.Windows.Forms.TextBox();
            this.textBox14 = new System.Windows.Forms.TextBox();
            this.textBox15 = new System.Windows.Forms.TextBox();
            this.trackBar3 = new System.Windows.Forms.TrackBar();
            this.trackBar4 = new System.Windows.Forms.TrackBar();
            this.textBox16 = new System.Windows.Forms.TextBox();
            this.trackBar5 = new System.Windows.Forms.TrackBar();
            this.B_Animation_Importer_2 = new System.Windows.Forms.Button();
            this.textBox17 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar5)).BeginInit();
            this.SuspendLayout();
            // 
            // B_Model_Converter
            // 
            this.B_Model_Converter.AllowDrop = true;
            this.B_Model_Converter.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.B_Model_Converter.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Model_Converter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Model_Converter.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Model_Converter.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Model_Converter.Location = new System.Drawing.Point(0, 442);
            this.B_Model_Converter.Name = "B_Model_Converter";
            this.B_Model_Converter.Size = new System.Drawing.Size(283, 120);
            this.B_Model_Converter.TabIndex = 0;
            this.B_Model_Converter.Text = "ここに3Dモデルのファイルをドラッグアンドドロップ\r\n（独自形式へ変換）";
            this.B_Model_Converter.UseVisualStyleBackColor = false;
            this.B_Model_Converter.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox1
            // 
            this.textBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox1.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1.Location = new System.Drawing.Point(0, 427);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(286, 19);
            this.textBox1.TabIndex = 1;
            this.textBox1.Text = "モデルコンバーター";
            // 
            // textBox2
            // 
            this.textBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox2.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.textBox2.Location = new System.Drawing.Point(282, 517);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(134, 23);
            this.textBox2.TabIndex = 2;
            this.textBox2.Text = "変換前モデルのパス";
            // 
            // TB_before_convert_path
            // 
            this.TB_before_convert_path.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.TB_before_convert_path.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_before_convert_path.Location = new System.Drawing.Point(412, 517);
            this.TB_before_convert_path.Name = "TB_before_convert_path";
            this.TB_before_convert_path.Size = new System.Drawing.Size(670, 23);
            this.TB_before_convert_path.TabIndex = 2;
            // 
            // textBox4
            // 
            this.textBox4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox4.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox4.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.textBox4.Location = new System.Drawing.Point(282, 537);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(134, 23);
            this.textBox4.TabIndex = 2;
            this.textBox4.Text = "変換後モデルのパス";
            // 
            // TB_after_convert_path
            // 
            this.TB_after_convert_path.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.TB_after_convert_path.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_after_convert_path.Location = new System.Drawing.Point(412, 537);
            this.TB_after_convert_path.Name = "TB_after_convert_path";
            this.TB_after_convert_path.Size = new System.Drawing.Size(670, 23);
            this.TB_after_convert_path.TabIndex = 2;
            // 
            // B_Animation_Converter
            // 
            this.B_Animation_Converter.AllowDrop = true;
            this.B_Animation_Converter.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.B_Animation_Converter.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Converter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Converter.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Converter.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Converter.Location = new System.Drawing.Point(0, 311);
            this.B_Animation_Converter.Name = "B_Animation_Converter";
            this.B_Animation_Converter.Size = new System.Drawing.Size(283, 120);
            this.B_Animation_Converter.TabIndex = 0;
            this.B_Animation_Converter.Text = "ここにアニメーションのファイルをドラッグアンドドロップ\r\n（独自形式へ変換）";
            this.B_Animation_Converter.UseVisualStyleBackColor = false;
            this.B_Animation_Converter.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox3
            // 
            this.textBox3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox3.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox3.Location = new System.Drawing.Point(0, 295);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(286, 19);
            this.textBox3.TabIndex = 1;
            this.textBox3.Text = "アニメーションコンバーター";
            // 
            // B_Model_Importer
            // 
            this.B_Model_Importer.AllowDrop = true;
            this.B_Model_Importer.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.B_Model_Importer.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Model_Importer.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Model_Importer.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Model_Importer.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Model_Importer.Location = new System.Drawing.Point(0, 12);
            this.B_Model_Importer.Name = "B_Model_Importer";
            this.B_Model_Importer.Size = new System.Drawing.Size(283, 287);
            this.B_Model_Importer.TabIndex = 0;
            this.B_Model_Importer.Text = "ここに独自形式モデルのファイルをドラッグアンドドロップして読み込み";
            this.B_Model_Importer.UseVisualStyleBackColor = false;
            this.B_Model_Importer.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox5
            // 
            this.textBox5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox5.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox5.Location = new System.Drawing.Point(0, 0);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(286, 19);
            this.textBox5.TabIndex = 1;
            this.textBox5.Text = "モデルインポーター";
            // 
            // B_Animation_Importer_1
            // 
            this.B_Animation_Importer_1.AllowDrop = true;
            this.B_Animation_Importer_1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.B_Animation_Importer_1.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Importer_1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Importer_1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Importer_1.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Importer_1.Location = new System.Drawing.Point(808, 16);
            this.B_Animation_Importer_1.Name = "B_Animation_Importer_1";
            this.B_Animation_Importer_1.Size = new System.Drawing.Size(274, 179);
            this.B_Animation_Importer_1.TabIndex = 0;
            this.B_Animation_Importer_1.Text = "ここに独自形式アニメーションのファイルをドラッグアンドドロップして読み込み";
            this.B_Animation_Importer_1.UseVisualStyleBackColor = false;
            this.B_Animation_Importer_1.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox6
            // 
            this.textBox6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox6.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox6.Location = new System.Drawing.Point(808, 0);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(274, 19);
            this.textBox6.TabIndex = 1;
            this.textBox6.Text = "アニメーションインポーター　１に設定";
            // 
            // textBox7
            // 
            this.textBox7.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox7.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox7.Location = new System.Drawing.Point(282, 0);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(527, 19);
            this.textBox7.TabIndex = 1;
            this.textBox7.Text = "モデルビュワー";
            // 
            // d3D11Panel1
            // 
            this.d3D11Panel1.Location = new System.Drawing.Point(282, 18);
            this.d3D11Panel1.Name = "d3D11Panel1";
            this.d3D11Panel1.Size = new System.Drawing.Size(526, 336);
            this.d3D11Panel1.TabIndex = 3;
            // 
            // textBox8
            // 
            this.textBox8.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox8.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox8.Location = new System.Drawing.Point(282, 352);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(527, 19);
            this.textBox8.TabIndex = 1;
            this.textBox8.Text = "カメラ設定";
            // 
            // textBox9
            // 
            this.textBox9.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox9.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox9.Location = new System.Drawing.Point(282, 371);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(258, 19);
            this.textBox9.TabIndex = 1;
            this.textBox9.Text = "カメラ距離";
            // 
            // textBox10
            // 
            this.textBox10.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox10.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox10.Location = new System.Drawing.Point(536, 371);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(272, 19);
            this.textBox10.TabIndex = 1;
            this.textBox10.Text = "カメラ位置（角度ｙ）";
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(282, 389);
            this.trackBar1.Maximum = 100;
            this.trackBar1.Minimum = 10;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(258, 45);
            this.trackBar1.TabIndex = 4;
            this.trackBar1.Value = 10;
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(536, 389);
            this.trackBar2.Maximum = 360;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(272, 45);
            this.trackBar2.TabIndex = 4;
            // 
            // textBox11
            // 
            this.textBox11.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox11.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox11.Location = new System.Drawing.Point(280, 432);
            this.textBox11.Name = "textBox11";
            this.textBox11.Size = new System.Drawing.Size(801, 19);
            this.textBox11.TabIndex = 1;
            this.textBox11.Text = "アニメーションブレンド";
            // 
            // textBox12
            // 
            this.textBox12.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox12.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox12.Location = new System.Drawing.Point(281, 451);
            this.textBox12.Name = "textBox12";
            this.textBox12.Size = new System.Drawing.Size(82, 19);
            this.textBox12.TabIndex = 1;
            this.textBox12.Text = "アニメーション１";
            // 
            // textBox13
            // 
            this.textBox13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox13.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox13.Location = new System.Drawing.Point(676, 451);
            this.textBox13.Name = "textBox13";
            this.textBox13.Size = new System.Drawing.Size(82, 19);
            this.textBox13.TabIndex = 1;
            this.textBox13.Text = "アニメーション２";
            // 
            // textBox14
            // 
            this.textBox14.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox14.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox14.Location = new System.Drawing.Point(360, 451);
            this.textBox14.Name = "textBox14";
            this.textBox14.Size = new System.Drawing.Size(320, 19);
            this.textBox14.TabIndex = 1;
            this.textBox14.Text = "アニメーション名";
            // 
            // textBox15
            // 
            this.textBox15.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox15.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox15.Location = new System.Drawing.Point(755, 451);
            this.textBox15.Name = "textBox15";
            this.textBox15.Size = new System.Drawing.Size(326, 19);
            this.textBox15.TabIndex = 1;
            this.textBox15.Text = "アニメーション名";
            // 
            // trackBar3
            // 
            this.trackBar3.Location = new System.Drawing.Point(281, 471);
            this.trackBar3.Maximum = 120;
            this.trackBar3.Name = "trackBar3";
            this.trackBar3.Size = new System.Drawing.Size(399, 45);
            this.trackBar3.TabIndex = 4;
            this.trackBar3.Value = 10;
            // 
            // trackBar4
            // 
            this.trackBar4.Location = new System.Drawing.Point(676, 471);
            this.trackBar4.Maximum = 120;
            this.trackBar4.Name = "trackBar4";
            this.trackBar4.Size = new System.Drawing.Size(405, 45);
            this.trackBar4.TabIndex = 4;
            this.trackBar4.Value = 10;
            // 
            // textBox16
            // 
            this.textBox16.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox16.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox16.Location = new System.Drawing.Point(808, 371);
            this.textBox16.Name = "textBox16";
            this.textBox16.Size = new System.Drawing.Size(273, 19);
            this.textBox16.TabIndex = 1;
            this.textBox16.Text = "アニメーションブレンド率";
            // 
            // trackBar5
            // 
            this.trackBar5.Location = new System.Drawing.Point(808, 389);
            this.trackBar5.Maximum = 100;
            this.trackBar5.Name = "trackBar5";
            this.trackBar5.Size = new System.Drawing.Size(273, 45);
            this.trackBar5.TabIndex = 4;
            this.trackBar5.Value = 10;
            // 
            // B_Animation_Importer_2
            // 
            this.B_Animation_Importer_2.AllowDrop = true;
            this.B_Animation_Importer_2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.B_Animation_Importer_2.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Importer_2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Importer_2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Importer_2.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Importer_2.Location = new System.Drawing.Point(807, 210);
            this.B_Animation_Importer_2.Name = "B_Animation_Importer_2";
            this.B_Animation_Importer_2.Size = new System.Drawing.Size(274, 161);
            this.B_Animation_Importer_2.TabIndex = 0;
            this.B_Animation_Importer_2.Text = "ここに独自形式アニメーションのファイルをドラッグアンドドロップして読み込み";
            this.B_Animation_Importer_2.UseVisualStyleBackColor = false;
            this.B_Animation_Importer_2.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox17
            // 
            this.textBox17.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox17.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox17.Location = new System.Drawing.Point(807, 194);
            this.textBox17.Name = "textBox17";
            this.textBox17.Size = new System.Drawing.Size(274, 19);
            this.textBox17.TabIndex = 1;
            this.textBox17.Text = "アニメーションインポーター　２に設定";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1082, 561);
            this.Controls.Add(this.textBox13);
            this.Controls.Add(this.textBox16);
            this.Controls.Add(this.textBox15);
            this.Controls.Add(this.textBox14);
            this.Controls.Add(this.textBox12);
            this.Controls.Add(this.textBox11);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.trackBar5);
            this.Controls.Add(this.trackBar4);
            this.Controls.Add(this.trackBar3);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.textBox10);
            this.Controls.Add(this.textBox9);
            this.Controls.Add(this.textBox8);
            this.Controls.Add(this.d3D11Panel1);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.TB_after_convert_path);
            this.Controls.Add(this.TB_before_convert_path);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox17);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.B_Animation_Importer_2);
            this.Controls.Add(this.B_Animation_Importer_1);
            this.Controls.Add(this.B_Model_Importer);
            this.Controls.Add(this.B_Animation_Converter);
            this.Controls.Add(this.B_Model_Converter);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Model Convert And Importer";
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

        private System.Windows.Forms.Button B_Model_Converter;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox TB_before_convert_path;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox TB_after_convert_path;
        private System.Windows.Forms.Button B_Animation_Converter;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Button B_Model_Importer;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Button B_Animation_Importer_1;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox7;
        private SharpDXSample.D3D11Panel d3D11Panel1;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.TextBox textBox11;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox textBox13;
        private System.Windows.Forms.TextBox textBox14;
        private System.Windows.Forms.TextBox textBox15;
        private System.Windows.Forms.TrackBar trackBar3;
        private System.Windows.Forms.TrackBar trackBar4;
        private System.Windows.Forms.TextBox textBox16;
        private System.Windows.Forms.TrackBar trackBar5;
        private System.Windows.Forms.Button B_Animation_Importer_2;
        private System.Windows.Forms.TextBox textBox17;
    }
}

