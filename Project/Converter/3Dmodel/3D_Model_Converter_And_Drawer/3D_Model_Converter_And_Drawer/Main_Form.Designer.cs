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
            this.textBox18 = new System.Windows.Forms.TextBox();
            this.textBox19 = new System.Windows.Forms.TextBox();
            this.textBox20 = new System.Windows.Forms.TextBox();
            this.textBox21 = new System.Windows.Forms.TextBox();
            this.textBox22 = new System.Windows.Forms.TextBox();
            this.TB_assimp_load_time = new System.Windows.Forms.TextBox();
            this.TB_assimp_load_physics_data_size = new System.Windows.Forms.TextBox();
            this.TB_my_format_load_time = new System.Windows.Forms.TextBox();
            this.textBox24 = new System.Windows.Forms.TextBox();
            this.TB_assimp_load_virtual_data_size = new System.Windows.Forms.TextBox();
            this.textBox23 = new System.Windows.Forms.TextBox();
            this.TB_my_format_load_physics_data_size = new System.Windows.Forms.TextBox();
            this.textBox27 = new System.Windows.Forms.TextBox();
            this.TB_my_format_load_virtual_data_size = new System.Windows.Forms.TextBox();
            this.d3D11Panel1 = new SharpDXSample.D3D11Panel();
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
            this.B_Model_Converter.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Model_Converter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Model_Converter.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Model_Converter.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Model_Converter.Location = new System.Drawing.Point(0, 552);
            this.B_Model_Converter.Margin = new System.Windows.Forms.Padding(4);
            this.B_Model_Converter.Name = "B_Model_Converter";
            this.B_Model_Converter.Size = new System.Drawing.Size(377, 146);
            this.B_Model_Converter.TabIndex = 0;
            this.B_Model_Converter.Text = "ここに3Dモデルのファイルをドラッグアンドドロップ\r\n（独自形式へ変換）";
            this.B_Model_Converter.UseVisualStyleBackColor = false;
            this.B_Model_Converter.Click += new System.EventHandler(this.B_Model_Converter_Click);
            this.B_Model_Converter.DragDrop += new System.Windows.Forms.DragEventHandler(this.B_Model_Converter_DragDrop);
            this.B_Model_Converter.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1.Location = new System.Drawing.Point(0, 534);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(380, 22);
            this.textBox1.TabIndex = 1;
            this.textBox1.Text = "モデルコンバーター";
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox2.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.textBox2.Location = new System.Drawing.Point(376, 646);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(177, 27);
            this.textBox2.TabIndex = 2;
            this.textBox2.Text = "変換前モデルのパス";
            // 
            // TB_before_convert_path
            // 
            this.TB_before_convert_path.Font = new System.Drawing.Font("MS UI Gothic", 9F);
            this.TB_before_convert_path.Location = new System.Drawing.Point(549, 646);
            this.TB_before_convert_path.Margin = new System.Windows.Forms.Padding(4);
            this.TB_before_convert_path.Name = "TB_before_convert_path";
            this.TB_before_convert_path.Size = new System.Drawing.Size(892, 22);
            this.TB_before_convert_path.TabIndex = 2;
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox4.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.textBox4.Location = new System.Drawing.Point(376, 671);
            this.textBox4.Margin = new System.Windows.Forms.Padding(4);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(177, 27);
            this.textBox4.TabIndex = 2;
            this.textBox4.Text = "変換後モデルのパス";
            // 
            // TB_after_convert_path
            // 
            this.TB_after_convert_path.Font = new System.Drawing.Font("MS UI Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.TB_after_convert_path.Location = new System.Drawing.Point(549, 671);
            this.TB_after_convert_path.Margin = new System.Windows.Forms.Padding(4);
            this.TB_after_convert_path.Name = "TB_after_convert_path";
            this.TB_after_convert_path.Size = new System.Drawing.Size(892, 27);
            this.TB_after_convert_path.TabIndex = 2;
            // 
            // B_Animation_Converter
            // 
            this.B_Animation_Converter.AllowDrop = true;
            this.B_Animation_Converter.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Converter.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Converter.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Converter.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Converter.Location = new System.Drawing.Point(0, 389);
            this.B_Animation_Converter.Margin = new System.Windows.Forms.Padding(4);
            this.B_Animation_Converter.Name = "B_Animation_Converter";
            this.B_Animation_Converter.Size = new System.Drawing.Size(377, 150);
            this.B_Animation_Converter.TabIndex = 0;
            this.B_Animation_Converter.Text = "ここにアニメーションのファイルをドラッグアンドドロップ\r\n（独自形式へ変換）";
            this.B_Animation_Converter.UseVisualStyleBackColor = false;
            this.B_Animation_Converter.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox3
            // 
            this.textBox3.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox3.Location = new System.Drawing.Point(0, 369);
            this.textBox3.Margin = new System.Windows.Forms.Padding(4);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(380, 22);
            this.textBox3.TabIndex = 1;
            this.textBox3.Text = "アニメーションコンバーター";
            // 
            // B_Model_Importer
            // 
            this.B_Model_Importer.AllowDrop = true;
            this.B_Model_Importer.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Model_Importer.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Model_Importer.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Model_Importer.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Model_Importer.Location = new System.Drawing.Point(0, 15);
            this.B_Model_Importer.Margin = new System.Windows.Forms.Padding(4);
            this.B_Model_Importer.Name = "B_Model_Importer";
            this.B_Model_Importer.Size = new System.Drawing.Size(377, 359);
            this.B_Model_Importer.TabIndex = 0;
            this.B_Model_Importer.Text = "ここに独自形式モデルのファイルをドラッグアンドドロップして読み込み";
            this.B_Model_Importer.UseVisualStyleBackColor = false;
            this.B_Model_Importer.Click += new System.EventHandler(this.B_Model_Importer_Click);
            this.B_Model_Importer.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox5
            // 
            this.textBox5.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox5.Location = new System.Drawing.Point(0, 0);
            this.textBox5.Margin = new System.Windows.Forms.Padding(4);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(380, 22);
            this.textBox5.TabIndex = 1;
            this.textBox5.Text = "モデルインポーター";
            // 
            // B_Animation_Importer_1
            // 
            this.B_Animation_Importer_1.AllowDrop = true;
            this.B_Animation_Importer_1.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Importer_1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Importer_1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Importer_1.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Importer_1.Location = new System.Drawing.Point(1077, 20);
            this.B_Animation_Importer_1.Margin = new System.Windows.Forms.Padding(4);
            this.B_Animation_Importer_1.Name = "B_Animation_Importer_1";
            this.B_Animation_Importer_1.Size = new System.Drawing.Size(365, 224);
            this.B_Animation_Importer_1.TabIndex = 0;
            this.B_Animation_Importer_1.Text = "ここに独自形式アニメーションのファイルをドラッグアンドドロップして読み込み";
            this.B_Animation_Importer_1.UseVisualStyleBackColor = false;
            this.B_Animation_Importer_1.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox6.Location = new System.Drawing.Point(1077, 0);
            this.textBox6.Margin = new System.Windows.Forms.Padding(4);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(364, 22);
            this.textBox6.TabIndex = 1;
            this.textBox6.Text = "アニメーションインポーター　１に設定";
            // 
            // textBox7
            // 
            this.textBox7.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox7.Location = new System.Drawing.Point(376, 0);
            this.textBox7.Margin = new System.Windows.Forms.Padding(4);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(701, 22);
            this.textBox7.TabIndex = 1;
            this.textBox7.Text = "モデルビュワー";
            // 
            // textBox8
            // 
            this.textBox8.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox8.Location = new System.Drawing.Point(376, 440);
            this.textBox8.Margin = new System.Windows.Forms.Padding(4);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(701, 22);
            this.textBox8.TabIndex = 1;
            this.textBox8.Text = "カメラ設定";
            // 
            // textBox9
            // 
            this.textBox9.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox9.Location = new System.Drawing.Point(376, 464);
            this.textBox9.Margin = new System.Windows.Forms.Padding(4);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(343, 22);
            this.textBox9.TabIndex = 1;
            this.textBox9.Text = "カメラ距離";
            // 
            // textBox10
            // 
            this.textBox10.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox10.Location = new System.Drawing.Point(715, 464);
            this.textBox10.Margin = new System.Windows.Forms.Padding(4);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(361, 22);
            this.textBox10.TabIndex = 1;
            this.textBox10.Text = "カメラ位置（角度ｙ）";
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(376, 486);
            this.trackBar1.Margin = new System.Windows.Forms.Padding(4);
            this.trackBar1.Maximum = 100;
            this.trackBar1.Minimum = 10;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(344, 56);
            this.trackBar1.TabIndex = 4;
            this.trackBar1.Value = 10;
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(715, 486);
            this.trackBar2.Margin = new System.Windows.Forms.Padding(4);
            this.trackBar2.Maximum = 360;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(363, 56);
            this.trackBar2.TabIndex = 4;
            // 
            // textBox11
            // 
            this.textBox11.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox11.Location = new System.Drawing.Point(373, 540);
            this.textBox11.Margin = new System.Windows.Forms.Padding(4);
            this.textBox11.Name = "textBox11";
            this.textBox11.Size = new System.Drawing.Size(1067, 22);
            this.textBox11.TabIndex = 1;
            this.textBox11.Text = "アニメーションブレンド";
            // 
            // textBox12
            // 
            this.textBox12.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox12.Location = new System.Drawing.Point(375, 564);
            this.textBox12.Margin = new System.Windows.Forms.Padding(4);
            this.textBox12.Name = "textBox12";
            this.textBox12.Size = new System.Drawing.Size(108, 22);
            this.textBox12.TabIndex = 1;
            this.textBox12.Text = "アニメーション１";
            // 
            // textBox13
            // 
            this.textBox13.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox13.Location = new System.Drawing.Point(901, 564);
            this.textBox13.Margin = new System.Windows.Forms.Padding(4);
            this.textBox13.Name = "textBox13";
            this.textBox13.Size = new System.Drawing.Size(108, 22);
            this.textBox13.TabIndex = 1;
            this.textBox13.Text = "アニメーション２";
            // 
            // textBox14
            // 
            this.textBox14.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox14.Location = new System.Drawing.Point(480, 564);
            this.textBox14.Margin = new System.Windows.Forms.Padding(4);
            this.textBox14.Name = "textBox14";
            this.textBox14.Size = new System.Drawing.Size(425, 22);
            this.textBox14.TabIndex = 1;
            this.textBox14.Text = "アニメーション名";
            // 
            // textBox15
            // 
            this.textBox15.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox15.Location = new System.Drawing.Point(1007, 564);
            this.textBox15.Margin = new System.Windows.Forms.Padding(4);
            this.textBox15.Name = "textBox15";
            this.textBox15.Size = new System.Drawing.Size(433, 22);
            this.textBox15.TabIndex = 1;
            this.textBox15.Text = "アニメーション名";
            // 
            // trackBar3
            // 
            this.trackBar3.Location = new System.Drawing.Point(375, 589);
            this.trackBar3.Margin = new System.Windows.Forms.Padding(4);
            this.trackBar3.Maximum = 120;
            this.trackBar3.Name = "trackBar3";
            this.trackBar3.Size = new System.Drawing.Size(532, 56);
            this.trackBar3.TabIndex = 4;
            // 
            // trackBar4
            // 
            this.trackBar4.Location = new System.Drawing.Point(901, 589);
            this.trackBar4.Margin = new System.Windows.Forms.Padding(4);
            this.trackBar4.Maximum = 120;
            this.trackBar4.Name = "trackBar4";
            this.trackBar4.Size = new System.Drawing.Size(540, 56);
            this.trackBar4.TabIndex = 4;
            // 
            // textBox16
            // 
            this.textBox16.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox16.Location = new System.Drawing.Point(1077, 464);
            this.textBox16.Margin = new System.Windows.Forms.Padding(4);
            this.textBox16.Name = "textBox16";
            this.textBox16.Size = new System.Drawing.Size(363, 22);
            this.textBox16.TabIndex = 1;
            this.textBox16.Text = "アニメーションブレンド率";
            // 
            // trackBar5
            // 
            this.trackBar5.Location = new System.Drawing.Point(1077, 486);
            this.trackBar5.Margin = new System.Windows.Forms.Padding(4);
            this.trackBar5.Maximum = 100;
            this.trackBar5.Name = "trackBar5";
            this.trackBar5.Size = new System.Drawing.Size(364, 56);
            this.trackBar5.TabIndex = 4;
            // 
            // B_Animation_Importer_2
            // 
            this.B_Animation_Importer_2.AllowDrop = true;
            this.B_Animation_Importer_2.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.B_Animation_Importer_2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.B_Animation_Importer_2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.B_Animation_Importer_2.Font = new System.Drawing.Font("MS UI Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.B_Animation_Importer_2.Location = new System.Drawing.Point(1076, 262);
            this.B_Animation_Importer_2.Margin = new System.Windows.Forms.Padding(4);
            this.B_Animation_Importer_2.Name = "B_Animation_Importer_2";
            this.B_Animation_Importer_2.Size = new System.Drawing.Size(365, 201);
            this.B_Animation_Importer_2.TabIndex = 0;
            this.B_Animation_Importer_2.Text = "ここに独自形式アニメーションのファイルをドラッグアンドドロップして読み込み";
            this.B_Animation_Importer_2.UseVisualStyleBackColor = false;
            this.B_Animation_Importer_2.DragOver += new System.Windows.Forms.DragEventHandler(this.B_Drag_Over_File_Checker);
            // 
            // textBox17
            // 
            this.textBox17.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox17.Location = new System.Drawing.Point(1076, 242);
            this.textBox17.Margin = new System.Windows.Forms.Padding(4);
            this.textBox17.Name = "textBox17";
            this.textBox17.Size = new System.Drawing.Size(364, 22);
            this.textBox17.TabIndex = 1;
            this.textBox17.Text = "アニメーションインポーター　２に設定";
            // 
            // textBox18
            // 
            this.textBox18.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox18.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox18.Location = new System.Drawing.Point(0, 696);
            this.textBox18.Name = "textBox18";
            this.textBox18.ReadOnly = true;
            this.textBox18.Size = new System.Drawing.Size(719, 22);
            this.textBox18.TabIndex = 5;
            this.textBox18.Text = "assimpによる\"非\"独自形式のロード情報";
            // 
            // textBox19
            // 
            this.textBox19.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox19.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox19.ForeColor = System.Drawing.SystemColors.InfoText;
            this.textBox19.Location = new System.Drawing.Point(715, 696);
            this.textBox19.Name = "textBox19";
            this.textBox19.ReadOnly = true;
            this.textBox19.Size = new System.Drawing.Size(725, 22);
            this.textBox19.TabIndex = 5;
            this.textBox19.Text = "独自形式のモデルのロード情報";
            this.textBox19.TextChanged += new System.EventHandler(this.textBox19_TextChanged);
            // 
            // textBox20
            // 
            this.textBox20.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox20.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox20.Location = new System.Drawing.Point(1, 718);
            this.textBox20.Name = "textBox20";
            this.textBox20.ReadOnly = true;
            this.textBox20.Size = new System.Drawing.Size(78, 22);
            this.textBox20.TabIndex = 6;
            this.textBox20.Text = "ロード時間";
            // 
            // textBox21
            // 
            this.textBox21.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox21.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox21.Location = new System.Drawing.Point(0, 739);
            this.textBox21.Name = "textBox21";
            this.textBox21.ReadOnly = true;
            this.textBox21.Size = new System.Drawing.Size(106, 22);
            this.textBox21.TabIndex = 6;
            this.textBox21.Text = "物理メモリサイズ";
            // 
            // textBox22
            // 
            this.textBox22.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox22.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox22.ForeColor = System.Drawing.SystemColors.InfoText;
            this.textBox22.Location = new System.Drawing.Point(715, 718);
            this.textBox22.Name = "textBox22";
            this.textBox22.ReadOnly = true;
            this.textBox22.Size = new System.Drawing.Size(74, 22);
            this.textBox22.TabIndex = 6;
            this.textBox22.Text = "ロード時間";
            this.textBox22.TextChanged += new System.EventHandler(this.textBox22_TextChanged);
            // 
            // TB_assimp_load_time
            // 
            this.TB_assimp_load_time.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_assimp_load_time.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_assimp_load_time.Location = new System.Drawing.Point(78, 718);
            this.TB_assimp_load_time.Name = "TB_assimp_load_time";
            this.TB_assimp_load_time.ReadOnly = true;
            this.TB_assimp_load_time.Size = new System.Drawing.Size(641, 22);
            this.TB_assimp_load_time.TabIndex = 6;
            this.TB_assimp_load_time.TextChanged += new System.EventHandler(this.textBox24_TextChanged);
            // 
            // TB_assimp_load_physics_data_size
            // 
            this.TB_assimp_load_physics_data_size.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_assimp_load_physics_data_size.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_assimp_load_physics_data_size.Location = new System.Drawing.Point(104, 739);
            this.TB_assimp_load_physics_data_size.Name = "TB_assimp_load_physics_data_size";
            this.TB_assimp_load_physics_data_size.ReadOnly = true;
            this.TB_assimp_load_physics_data_size.Size = new System.Drawing.Size(258, 22);
            this.TB_assimp_load_physics_data_size.TabIndex = 6;
            this.TB_assimp_load_physics_data_size.TextChanged += new System.EventHandler(this.textBox25_TextChanged);
            // 
            // TB_my_format_load_time
            // 
            this.TB_my_format_load_time.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_my_format_load_time.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_my_format_load_time.Location = new System.Drawing.Point(787, 718);
            this.TB_my_format_load_time.Name = "TB_my_format_load_time";
            this.TB_my_format_load_time.ReadOnly = true;
            this.TB_my_format_load_time.Size = new System.Drawing.Size(655, 22);
            this.TB_my_format_load_time.TabIndex = 6;
            this.TB_my_format_load_time.TextChanged += new System.EventHandler(this.textBox24_TextChanged);
            // 
            // textBox24
            // 
            this.textBox24.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox24.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox24.Location = new System.Drawing.Point(362, 739);
            this.textBox24.Name = "textBox24";
            this.textBox24.ReadOnly = true;
            this.textBox24.Size = new System.Drawing.Size(106, 22);
            this.textBox24.TabIndex = 6;
            this.textBox24.Text = "仮想メモリサイズ";
            // 
            // TB_assimp_load_virtual_data_size
            // 
            this.TB_assimp_load_virtual_data_size.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_assimp_load_virtual_data_size.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_assimp_load_virtual_data_size.Location = new System.Drawing.Point(466, 739);
            this.TB_assimp_load_virtual_data_size.Name = "TB_assimp_load_virtual_data_size";
            this.TB_assimp_load_virtual_data_size.ReadOnly = true;
            this.TB_assimp_load_virtual_data_size.Size = new System.Drawing.Size(253, 22);
            this.TB_assimp_load_virtual_data_size.TabIndex = 6;
            this.TB_assimp_load_virtual_data_size.TextChanged += new System.EventHandler(this.textBox25_TextChanged);
            // 
            // textBox23
            // 
            this.textBox23.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox23.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox23.Location = new System.Drawing.Point(715, 739);
            this.textBox23.Name = "textBox23";
            this.textBox23.ReadOnly = true;
            this.textBox23.Size = new System.Drawing.Size(107, 22);
            this.textBox23.TabIndex = 6;
            this.textBox23.Text = "物理メモリサイズ";
            // 
            // TB_my_format_load_physics_data_size
            // 
            this.TB_my_format_load_physics_data_size.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_my_format_load_physics_data_size.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_my_format_load_physics_data_size.Location = new System.Drawing.Point(819, 739);
            this.TB_my_format_load_physics_data_size.Name = "TB_my_format_load_physics_data_size";
            this.TB_my_format_load_physics_data_size.ReadOnly = true;
            this.TB_my_format_load_physics_data_size.Size = new System.Drawing.Size(258, 22);
            this.TB_my_format_load_physics_data_size.TabIndex = 6;
            this.TB_my_format_load_physics_data_size.TextChanged += new System.EventHandler(this.textBox25_TextChanged);
            // 
            // textBox27
            // 
            this.textBox27.BackColor = System.Drawing.SystemColors.ControlLight;
            this.textBox27.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox27.Location = new System.Drawing.Point(1077, 739);
            this.textBox27.Name = "textBox27";
            this.textBox27.ReadOnly = true;
            this.textBox27.Size = new System.Drawing.Size(107, 22);
            this.textBox27.TabIndex = 6;
            this.textBox27.Text = "仮想メモリサイズ";
            // 
            // TB_my_format_load_virtual_data_size
            // 
            this.TB_my_format_load_virtual_data_size.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.TB_my_format_load_virtual_data_size.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.TB_my_format_load_virtual_data_size.Location = new System.Drawing.Point(1183, 739);
            this.TB_my_format_load_virtual_data_size.Name = "TB_my_format_load_virtual_data_size";
            this.TB_my_format_load_virtual_data_size.ReadOnly = true;
            this.TB_my_format_load_virtual_data_size.Size = new System.Drawing.Size(258, 22);
            this.TB_my_format_load_virtual_data_size.TabIndex = 6;
            this.TB_my_format_load_virtual_data_size.TextChanged += new System.EventHandler(this.textBox25_TextChanged);
            // 
            // d3D11Panel1
            // 
            this.d3D11Panel1.Location = new System.Drawing.Point(375, 20);
            this.d3D11Panel1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.d3D11Panel1.Name = "d3D11Panel1";
            this.d3D11Panel1.Size = new System.Drawing.Size(701, 420);
            this.d3D11Panel1.TabIndex = 7;
            // 
            // Main_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1443, 760);
            this.Controls.Add(this.d3D11Panel1);
            this.Controls.Add(this.textBox22);
            this.Controls.Add(this.textBox20);
            this.Controls.Add(this.textBox21);
            this.Controls.Add(this.textBox24);
            this.Controls.Add(this.textBox27);
            this.Controls.Add(this.textBox23);
            this.Controls.Add(this.TB_my_format_load_virtual_data_size);
            this.Controls.Add(this.TB_assimp_load_virtual_data_size);
            this.Controls.Add(this.TB_my_format_load_physics_data_size);
            this.Controls.Add(this.TB_assimp_load_physics_data_size);
            this.Controls.Add(this.TB_my_format_load_time);
            this.Controls.Add(this.TB_assimp_load_time);
            this.Controls.Add(this.textBox19);
            this.Controls.Add(this.textBox18);
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
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "Main_Form";
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
        private System.Windows.Forms.TextBox textBox18;
        private System.Windows.Forms.TextBox textBox19;
        private System.Windows.Forms.TextBox textBox20;
        private System.Windows.Forms.TextBox textBox21;
        private System.Windows.Forms.TextBox textBox22;
        private System.Windows.Forms.TextBox TB_assimp_load_time;
        private System.Windows.Forms.TextBox TB_assimp_load_physics_data_size;
        private System.Windows.Forms.TextBox TB_my_format_load_time;
        private System.Windows.Forms.TextBox textBox24;
        private System.Windows.Forms.TextBox TB_assimp_load_virtual_data_size;
        private System.Windows.Forms.TextBox textBox23;
        private System.Windows.Forms.TextBox TB_my_format_load_physics_data_size;
        private System.Windows.Forms.TextBox textBox27;
        private System.Windows.Forms.TextBox TB_my_format_load_virtual_data_size;
        private SharpDXSample.D3D11Panel d3D11Panel1;
    }
}

