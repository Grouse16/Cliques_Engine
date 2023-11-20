using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator
{
    struct S_Blend_Setting
    {
        public int Blend_Mode;
        public int How_To_Blend;
        public int Blend_Byte_Format;
        public int Blend_Color_Format;


        public S_Blend_Setting(int in_mode, int in_how, int in_byte, int in_color)
        {
            Blend_Mode = in_mode;
            How_To_Blend = in_how;
            Blend_Byte_Format = in_byte;
            Blend_Color_Format = in_color;
        }
    }

    public partial class Form1 : Form
    {
        // ☆ 変数宣言 ☆ //
        string m_mat_default_name = string.Empty;       // マテリアルの初期名
        string m_shader_default_name = string.Empty;    // シェーダーの初期名

        List<S_Blend_Setting> m_blend_list = new List<S_Blend_Setting>();   // ブレンドのリスト

        int m_blend_count = 0;  // 現在のブレンド番号


        // ☆ 関数 ☆ //

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for (int loop_num = 0; loop_num < 8; loop_num++)
            {
                m_blend_list.Add(new S_Blend_Setting(0, 0, 4, 2));
            }

            m_blend_count = 0;
            CB_Blend_Number.Items.Clear();
            for (int blend_num = 1; blend_num <= CB_Blend_Sum.SelectedIndex + 1; blend_num++)
            {
                CB_Blend_Number.Items.Add(blend_num.ToString());
            }
            CB_Blend_Sum.SelectedIndex = 0;
            CB_Blend_Number.SelectedIndex = 0;

            MaximumSize = Size;
            MinimumSize = Size;

            m_mat_default_name = TB_material_name.Text;
            m_shader_default_name = TB_Shader_Setting_Name.Text;

            CB_Blend_Mode.SelectedIndex = m_blend_list[m_blend_count].Blend_Mode;
            CB_How_To_Blend.SelectedIndex = m_blend_list[m_blend_count].How_To_Blend;
            CB_Blend_Byte_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Byte_Format;
            CB_Blend_Color_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Color_Format;

            CB_Depth_Mode.SelectedIndex = 0;
            CB_Depth_Option.SelectedIndex = 0;
            CB_Stencil.SelectedIndex = 0;

            CB_Rasterize_Draw_Mode.SelectedIndex = 0;
            CB_Rasterizer_Mesh_Setting.SelectedIndex = 1;
            CB_Rasterizer_Front.SelectedIndex = 1;

            Track_Sampling_Count.Value = 0;
            TB_Sampling_Count.Text = Track_Sampling_Count.Value.ToString();
            Track_Sampling_Quality.Value = 0;
            TB_Sampling_Quality.Text = Track_Sampling_Quality.Value.ToString();

            Track_Depth_Value.Value = 0;
            TB_Depth_Value.Text = Track_Depth_Value.Value.ToString();
            Track_Depth_Max_Value.Value = 0;
            TB_Depth_Max_Value.Text = Track_Depth_Max_Value.Value.ToString();
            Track_Depth_Slope.Value = 0;
            TB_Depth_Slope.Text = Track_Depth_Slope.Value.ToString();

            Track_Ambient_Red.Value = 0;
            TB_Ambient_Red.Text = Track_Ambient_Red.Value.ToString();
            Track_Ambient_Green.Value = 0;
            TB_Ambient_Green.Text = Track_Ambient_Green.Value.ToString();
            Track_Ambient_Blue.Value = 0;
            TB_Ambient_Blue.Text = Track_Ambient_Blue.Value.ToString();
            Track_Ambient_Alpha.Value = 0;
            TB_Ambient_Alpha.Text = Track_Ambient_Alpha.Value.ToString();

            Track_Diffuse_Red.Value = 0;
            TB_Diffuse_Red.Text = Track_Diffuse_Red.Value.ToString();
            Track_Diffuse_Green.Value = 0;
            TB_Diffuse_Green.Text = Track_Diffuse_Green.Value.ToString();
            Track_Diffuse_Blue.Value = 0;
            TB_Diffuse_Blue.Text = Track_Diffuse_Blue.Value.ToString();
            Track_Diffuse_Alpha.Value = 0;
            TB_Diffuse_Alpha.Text = Track_Diffuse_Alpha.Value.ToString();

            Track_Emission_Red.Value = 0;
            TB_Emission_Red.Text = Track_Emission_Red.Value.ToString();
            Track_Emission_Green.Value = 0;
            TB_Emission_Green.Text = Track_Emission_Green.Value.ToString();
            Track_Emission_Blue.Value = 0;
            TB_Emission_Blue.Text = Track_Emission_Blue.Value.ToString();
            Track_Emission_Alpha.Value = 0;
            TB_Emission_Alpha.Text = Track_Emission_Alpha.Value.ToString();

            Track_Reflection_Red.Value = 0;
            TB_Reflection_Red.Text = Track_Reflection_Red.Value.ToString();
            Track_Reflection_Green.Value = 0;
            TB_Reflection_Green.Text = Track_Reflection_Green.Value.ToString();
            Track_Reflection_Blue.Value = 0;
            TB_Reflection_Blue.Text = Track_Reflection_Blue.Value.ToString();
            Track_Reflection_Alpha.Value = 0;
            TB_Reflection_Alpha.Text = Track_Reflection_Alpha.Value.ToString();

            Track_Specular_Red.Value = 0;
            TB_Specular_Red.Text = Track_Specular_Red.Value.ToString();
            Track_Specular_Green.Value = 0;
            TB_Specular_Green.Text = Track_Specular_Green.Value.ToString();
            Track_Specular_Blue.Value = 0;
            TB_Specular_Blue.Text = Track_Specular_Blue.Value.ToString();
            Track_Specular_Alpha.Value = 0;
            TB_Specular_Alpha.Text = Track_Specular_Alpha.Value.ToString();

            Track_Transparent_Red.Value = 100;
            TB_Transparent_Red.Text = (Track_Transparent_Red.Value / 100.0f).ToString();
            Track_Transparent_Green.Value = 100;
            TB_Transparent_Green.Text = (Track_Transparent_Green.Value / 100.0f).ToString();
            Track_Transparent_Blue.Value = 100;
            TB_Transparent_Blue.Text = (Track_Transparent_Blue.Value / 100.0f).ToString();
            Track_Transparent_Alpha.Value = 100;
            TB_Transparent_Alpha.Text = (Track_Transparent_Alpha.Value / 100.0f).ToString();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {

        }

        private void TRACK_Depth_Value_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Value.Text = Track_Depth_Value.Value.ToString();
        }

        private void TRACK_Depth_Max_Value_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Max_Value.Text = (Track_Depth_Max_Value.Value / 100.0f).ToString();
        }

        private void TRACK_Depth_Slope_Scroll(object sender, EventArgs e)
        {
            TB_Depth_Slope.Text = (Track_Depth_Slope.Value / 100.0f).ToString();
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void Track_Sampling_Count_Scroll(object sender, EventArgs e)
        {
            TB_Sampling_Count.Text = Track_Sampling_Count.Value.ToString();
        }

        private void Track_Sampling_Quality_Scroll(object sender, EventArgs e)
        {
            TB_Sampling_Quality.Text = Track_Sampling_Quality.Value.ToString();
        }

        private void Track_Ambient_Red_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Red.Text = (Track_Ambient_Red.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Green_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Green.Text = (Track_Ambient_Green.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Blue.Text = (Track_Ambient_Blue.Value / 100.0f).ToString();
        }

        private void Track_Ambient_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Ambient_Alpha.Text = (Track_Ambient_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Red_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Red.Text = (Track_Diffuse_Red.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Green_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Green.Text = (Track_Diffuse_Green.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Blue.Text = (Track_Diffuse_Blue.Value / 100.0f).ToString();
        }

        private void Track_Diffuse_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Diffuse_Alpha.Text = (Track_Diffuse_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Emission_Red_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Red.Text = (Track_Emission_Red.Value / 100.0f).ToString();
        }

        private void Track_Emission_Green_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Green.Text = (Track_Emission_Green.Value / 100.0f).ToString();
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Blue.Text = (Track_Emission_Blue.Value / 100.0f).ToString();
        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Alpha.Text = (Track_Emission_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Emission_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Blue.Text = (Track_Emission_Blue.Value / 100.0f).ToString();
        }

        private void Track_Emission_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Emission_Alpha.Text = (Track_Emission_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Reflection_Red_Scroll(object sender, EventArgs e)
        {
            TB_Reflection_Red.Text = (Track_Reflection_Red.Value / 100.0f).ToString();
        }

        private void Track_Reflection_Green_Scroll(object sender, EventArgs e)
        {
            TB_Reflection_Green.Text = (Track_Reflection_Green.Value / 100.0f).ToString();
        }

        private void Track_Reflection_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Reflection_Blue.Text = (Track_Reflection_Blue.Value / 100.0f).ToString();
        }

        private void Track_Reflection_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Reflection_Alpha.Text = (Track_Reflection_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Specular_Red_Scroll(object sender, EventArgs e)
        {
            TB_Specular_Red.Text = (Track_Specular_Red.Value / 100.0f).ToString();
        }

        private void Track_Specular_Green_Scroll(object sender, EventArgs e)
        {
            TB_Specular_Green.Text = (Track_Specular_Green.Value / 100.0f).ToString();
        }

        private void Track_Specular_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Specular_Blue.Text = (Track_Specular_Blue.Value / 100.0f).ToString();
        }

        private void Track_Specular_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Specular_Alpha.Text = (Track_Specular_Alpha.Value / 100.0f).ToString();
        }

        private void Track_Transparent_Red_Scroll(object sender, EventArgs e)
        {
            TB_Transparent_Red.Text = (Track_Transparent_Red.Value / 100.0f).ToString();
        }

        private void Track_Transparent_Green_Scroll(object sender, EventArgs e)
        {
            TB_Transparent_Green.Text = (Track_Transparent_Green.Value / 100.0f).ToString();
        }

        private void Track_Transparent_Blue_Scroll(object sender, EventArgs e)
        {
            TB_Transparent_Blue.Text = (Track_Transparent_Blue.Value / 100.0f).ToString();
        }

        private void Track_Transparent_Alpha_Scroll(object sender, EventArgs e)
        {
            TB_Transparent_Alpha.Text = (Track_Transparent_Alpha.Value / 100.0f).ToString();
        }

        private void TB_material_name_TextChanged(object sender, EventArgs e)
        {

        }

        private void B_Reset_MouseUp(object sender, MouseEventArgs e)
        {
            for (int loop_num = 0; loop_num < 8; loop_num++)
            {
                m_blend_list[loop_num] = new S_Blend_Setting(0, 0, 4, 2);
            }

            m_blend_count = 0;
            CB_Blend_Number.Items.Clear();
            for (int blend_num = 1; blend_num <= CB_Blend_Sum.SelectedIndex + 1; blend_num++)
            {
                CB_Blend_Number.Items.Add(blend_num.ToString());
            }

            CB_Blend_Sum.SelectedIndex = 0;
            CB_Blend_Number.SelectedIndex = 0;

            TB_material_name.Text = m_mat_default_name;
            TB_Shader_Setting_Name.Text = m_shader_default_name;

            CB_Blend_Mode.SelectedIndex = m_blend_list[m_blend_count].Blend_Mode;
            CB_How_To_Blend.SelectedIndex = m_blend_list[m_blend_count].How_To_Blend;
            CB_Blend_Byte_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Byte_Format;
            CB_Blend_Color_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Color_Format;

            CB_Depth_Mode.SelectedIndex = 0;
            CB_Depth_Option.SelectedIndex = 0;
            CB_Stencil.SelectedIndex = 0;

            CB_Rasterize_Draw_Mode.SelectedIndex = 0;
            CB_Rasterizer_Mesh_Setting.SelectedIndex = 1;
            CB_Rasterizer_Front.SelectedIndex = 1;

            Track_Depth_Value.Value = 0;
            TB_Depth_Value.Text = Track_Depth_Value.Value.ToString();
            Track_Depth_Max_Value.Value = 0;
            TB_Depth_Max_Value.Text = Track_Depth_Max_Value.Value.ToString();
            Track_Depth_Slope.Value = 0;
            TB_Depth_Slope.Text = Track_Depth_Slope.Value.ToString();

            Track_Sampling_Count.Value = 0;
            TB_Sampling_Count.Text = Track_Sampling_Count.Value.ToString();
            Track_Sampling_Quality.Value = 0;
            TB_Sampling_Quality.Text = Track_Sampling_Quality.Value.ToString();

            Track_Ambient_Red.Value = 0;
            TB_Ambient_Red.Text = Track_Ambient_Red.Value.ToString();
            Track_Ambient_Green.Value = 0;
            TB_Ambient_Green.Text = Track_Ambient_Green.Value.ToString();
            Track_Ambient_Blue.Value = 0;
            TB_Ambient_Blue.Text = Track_Ambient_Blue.Value.ToString();
            Track_Ambient_Alpha.Value = 0;
            TB_Ambient_Alpha.Text = Track_Ambient_Alpha.Value.ToString();

            Track_Diffuse_Red.Value = 0;
            TB_Diffuse_Red.Text = Track_Diffuse_Red.Value.ToString();
            Track_Diffuse_Green.Value = 0;
            TB_Diffuse_Green.Text = Track_Diffuse_Green.Value.ToString();
            Track_Diffuse_Blue.Value = 0;
            TB_Diffuse_Blue.Text = Track_Diffuse_Blue.Value.ToString();
            Track_Diffuse_Alpha.Value = 0;
            TB_Diffuse_Alpha.Text = Track_Diffuse_Alpha.Value.ToString();

            Track_Emission_Red.Value = 0;
            TB_Emission_Red.Text = Track_Emission_Red.Value.ToString();
            Track_Emission_Green.Value = 0;
            TB_Emission_Green.Text = Track_Emission_Green.Value.ToString();
            Track_Emission_Blue.Value = 0;
            TB_Emission_Blue.Text = Track_Emission_Blue.Value.ToString();
            Track_Emission_Alpha.Value = 0;
            TB_Emission_Alpha.Text = Track_Emission_Alpha.Value.ToString();

            Track_Reflection_Red.Value = 0;
            TB_Reflection_Red.Text = Track_Reflection_Red.Value.ToString();
            Track_Reflection_Green.Value = 0;
            TB_Reflection_Green.Text = Track_Reflection_Green.Value.ToString();
            Track_Reflection_Blue.Value = 0;
            TB_Reflection_Blue.Text = Track_Reflection_Blue.Value.ToString();
            Track_Reflection_Alpha.Value = 0;
            TB_Reflection_Alpha.Text = Track_Reflection_Alpha.Value.ToString();

            Track_Specular_Red.Value = 0;
            TB_Specular_Red.Text = Track_Specular_Red.Value.ToString();
            Track_Specular_Green.Value = 0;
            TB_Specular_Green.Text = Track_Specular_Green.Value.ToString();
            Track_Specular_Blue.Value = 0;
            TB_Specular_Blue.Text = Track_Specular_Blue.Value.ToString();
            Track_Specular_Alpha.Value = 0;
            TB_Specular_Alpha.Text = Track_Specular_Alpha.Value.ToString();

            Track_Transparent_Red.Value = 100;
            TB_Transparent_Red.Text = (Track_Transparent_Red.Value / 100.0f).ToString();
            Track_Transparent_Green.Value = 100;
            TB_Transparent_Green.Text = (Track_Transparent_Green.Value / 100.0f).ToString();
            Track_Transparent_Blue.Value = 100;
            TB_Transparent_Blue.Text = (Track_Transparent_Blue.Value / 100.0f).ToString();
            Track_Transparent_Alpha.Value = 100;
            TB_Transparent_Alpha.Text = (Track_Transparent_Alpha.Value / 100.0f).ToString();
        }


        // 生成開始
        private void B_Generate_MouseUp(object sender, MouseEventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            List<string> write_text = new List<string>();   // 書き込むデータ


            // マテリアルファイルであることを示す
            write_text.Add("This-Is-ELMAT");

            // シェーダー設定名を書き込む
            write_text.Add("SHADERSETTINGNAME:");
            write_text.Add(TB_Shader_Setting_Name.Text);


            //  ブレンドモード  //

            // ブレンドモードの設定数を書き込む
            write_text.Add("BLENDSUM:" + CB_Blend_Number.Items.Count);

            // ブレンドの情報の設定を書き込む
            for (int l_blend_num = 0; l_blend_num < CB_Blend_Number.Items.Count; l_blend_num++)
            {
                // ブレンドの情報の開始位置を書き込む
                write_text.Add("BLEND" + (l_blend_num + 1).ToString() + ":");

                // ブレンドモードを書き込む
                write_text.Add(CB_Blend_Mode.Items[m_blend_list[l_blend_num].Blend_Mode].ToString().Substring(0, M_Search_End_Mark(CB_Blend_Mode.Items[m_blend_list[l_blend_num].Blend_Mode].ToString())));

                // 混ぜ方を書き込む
                write_text.Add(CB_How_To_Blend.Items[m_blend_list[l_blend_num].How_To_Blend].ToString().Substring(0, M_Search_End_Mark(CB_How_To_Blend.Items[m_blend_list[l_blend_num].How_To_Blend].ToString())));

                // フォーマット
                write_text.Add(CB_Blend_Byte_Format.Items[m_blend_list[l_blend_num].Blend_Byte_Format].ToString().Substring(0, M_Search_End_Mark(CB_Blend_Byte_Format.Items[m_blend_list[l_blend_num].Blend_Byte_Format].ToString())));

                // カラー
                write_text.Add(CB_Blend_Color_Format.Items[m_blend_list[l_blend_num].Blend_Color_Format].ToString().Substring(0, M_Search_End_Mark(CB_Blend_Color_Format.Items[m_blend_list[l_blend_num].Blend_Color_Format].ToString())));
            }


            //  深度モード  //

            // 深度の開始位置を書き込む
            write_text.Add("DEPTH:");

            // 深度モードを書き込む
            write_text.Add(CB_Depth_Mode.Text.Substring(0, M_Search_End_Mark(CB_Depth_Mode.Text)));

            // 深度オプションを書き込む
            write_text.Add(CB_Depth_Option.Text.Substring(0, M_Search_End_Mark(CB_Depth_Option.Text)));

            // ステンシルを書き込む
            write_text.Add(CB_Stencil.Text.Substring(0, M_Search_End_Mark(CB_Stencil.Text)));


            //  ラスタライザ  //

            // ラスタライザの開始位置を書き込む
            write_text.Add("RASTERIZER:");

            // 表示モードを書き込む
            write_text.Add(CB_Rasterize_Draw_Mode.Text.Substring(0, M_Search_End_Mark(CB_Rasterize_Draw_Mode.Text)));

            // 面の表示基準を書き込む
            write_text.Add(CB_Rasterizer_Mesh_Setting.Text.Substring(0, M_Search_End_Mark(CB_Rasterizer_Mesh_Setting.Text)));

            // 面の表面の指定を書き込む
            write_text.Add(CB_Rasterizer_Front.Text.Substring(0, M_Search_End_Mark(CB_Rasterizer_Front.Text)));

            // 奥行き値を書き込む
            write_text.Add(Track_Depth_Value.Value.ToString());

            // 奥行きの最大値を書き込む
            write_text.Add((Track_Depth_Max_Value.Value / 100.0f).ToString());

            // 奥行きの傾き値を書き込む
            write_text.Add((Track_Depth_Slope.Value / 100.0f).ToString());


            //  サンプリング  //

            // サンプリングの開始位置を書き込む
            write_text.Add("SAMPLING:");

            // サンプリング回数を書き込む
            write_text.Add(Track_Sampling_Count.Value.ToString());

            // サンプリング品質を書き込む
            write_text.Add(Track_Sampling_Quality.Value.ToString());


            //  質感  //

            // 質感の開始位置を書き込む
            write_text.Add("MATERIAL:");

            // アンビエント値を書き込む
            write_text.Add((Track_Ambient_Red.Value / 100.0f).ToString() + "," + (Track_Ambient_Green.Value / 100.0f).ToString() + "," + (Track_Ambient_Blue.Value / 100.0f).ToString() + "," + (Track_Ambient_Alpha.Value / 100.0f).ToString());

            // ディフューズ値を書き込む
            write_text.Add((Track_Diffuse_Red.Value / 100.0f).ToString() + "," + (Track_Diffuse_Green.Value / 100.0f).ToString() + "," + (Track_Diffuse_Blue.Value / 100.0f).ToString() + "," + (Track_Diffuse_Alpha.Value / 100.0f).ToString());

            // エミッション値を書き込む
            write_text.Add((Track_Emission_Red.Value / 100.0f).ToString() + "," + (Track_Emission_Green.Value / 100.0f).ToString() + "," + (Track_Emission_Blue.Value / 100.0f).ToString() + "," + (Track_Emission_Alpha.Value / 100.0f).ToString());

            // リフレクション値を書き込む
            write_text.Add((Track_Reflection_Red.Value / 100.0f).ToString() + "," + (Track_Reflection_Green.Value / 100.0f).ToString() + "," + (Track_Reflection_Blue.Value / 100.0f).ToString() + "," + (Track_Reflection_Alpha.Value / 100.0f).ToString());

            // スペキュラー値を書き込む
            write_text.Add((Track_Specular_Red.Value / 100.0f).ToString() + "," + (Track_Specular_Green.Value / 100.0f).ToString() + "," + (Track_Specular_Blue.Value / 100.0f).ToString() + "," + (Track_Specular_Alpha.Value / 100.0f).ToString());
            
            // スペキュラー値を書き込む
            write_text.Add((Track_Transparent_Red.Value / 100.0f).ToString() + "," + (Track_Transparent_Green.Value / 100.0f).ToString() + "," + (Track_Transparent_Blue.Value / 100.0f).ToString() + "," + (Track_Transparent_Alpha.Value / 100.0f).ToString());


            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elmat";   // 拡張子


            sfd.FileName = TB_material_name.Text + "." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")|*." + ";*." + extension + "|すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "マテリアルの質感情報の保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, write_text[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < write_text.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, write_text[now_write_raw] + Environment.NewLine);
                }
            }
        }

        private void CB_Blend_Number_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_blend_count = CB_Blend_Number.SelectedIndex;

            CB_Blend_Mode.SelectedIndex = m_blend_list[m_blend_count].Blend_Mode;
            CB_How_To_Blend.SelectedIndex = m_blend_list[m_blend_count].How_To_Blend;
            CB_Blend_Byte_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Byte_Format;
            CB_Blend_Color_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Color_Format;
        }

        private void CB_Blend_Sum_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (CB_Blend_Sum.SelectedIndex + 1 < CB_Blend_Number.Items.Count)
            {
                m_blend_count = CB_Blend_Sum.SelectedIndex;
            }
            CB_Blend_Number.Items.Clear();
            for (int blend_num = 1; blend_num <= CB_Blend_Sum.SelectedIndex + 1; blend_num++)
            {
                CB_Blend_Number.Items.Add(blend_num.ToString());
            }
            CB_Blend_Number.SelectedIndex = m_blend_count;

            CB_Blend_Mode.SelectedIndex = m_blend_list[m_blend_count].Blend_Mode;
            CB_How_To_Blend.SelectedIndex = m_blend_list[m_blend_count].How_To_Blend;
            CB_Blend_Byte_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Byte_Format;
            CB_Blend_Color_Format.SelectedIndex = m_blend_list[m_blend_count].Blend_Color_Format;
        }

        // 指定された文字列から終了マーク（：）を探してその番号を返す
        private int M_Search_End_Mark(string in_string)
        {
            int end_mark_is_this = 0;   // 終了マークの番号

            for (end_mark_is_this = 0; end_mark_is_this < in_string.Length; end_mark_is_this++)
            {
                if (in_string[end_mark_is_this] == '：')
                {
                    return end_mark_is_this;
                }
            }

            return 0;
        }

        private void B_Reset_Click(object sender, EventArgs e)
        {

        }

        private void B_Generate_Click(object sender, EventArgs e)
        {

        }

        private void CB_Rasterize_Draw_Mode_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void CB_Rasterizer_Mesh_Setting_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void CB_Rasterizer_Front_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void CB_Blend_Mode_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_blend_list[m_blend_count] = new S_Blend_Setting(CB_Blend_Mode.SelectedIndex, m_blend_list[m_blend_count].How_To_Blend, m_blend_list[m_blend_count].Blend_Byte_Format, m_blend_list[m_blend_count].Blend_Color_Format);
        }

        private void CB_How_To_Blend_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_blend_list[m_blend_count] = new S_Blend_Setting(m_blend_list[m_blend_count].Blend_Mode, CB_How_To_Blend.SelectedIndex, m_blend_list[m_blend_count].Blend_Byte_Format, m_blend_list[m_blend_count].Blend_Color_Format);
        }

        private void CB_Blend_Byte_Format_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_blend_list[m_blend_count] = new S_Blend_Setting(m_blend_list[m_blend_count].Blend_Mode, m_blend_list[m_blend_count].How_To_Blend, CB_Blend_Byte_Format.SelectedIndex, m_blend_list[m_blend_count].Blend_Color_Format);
        }

        private void CB_Blend_Color_Format_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_blend_list[m_blend_count] = new S_Blend_Setting(m_blend_list[m_blend_count].Blend_Mode, m_blend_list[m_blend_count].How_To_Blend, m_blend_list[m_blend_count].Blend_Byte_Format, CB_Blend_Color_Format.SelectedIndex);
        }
    }
}
