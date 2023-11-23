using Shader_Setting_Generator.shader_set;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MaximumSize = Size;
            MinimumSize = Size;
        }

        // 生成ボタンを押されたらシェーダー情報を生成する
        private void B_Generate_MouseUp(object sender, MouseEventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            List<string> write_data = new List<string>();   // 書き込むデータ


            // シェーダー設定データであるとこを示す記述を書き込む
            write_data.Add("This-Is-ELSST");

            // 頂点レイアウトの情報開始位置を書き込む
            write_data.Add("VERTEXLAYOUT:");

            // 頂点の変数情報の数を書き込む
            write_data.Add(uC_Vertex_Layout1.M_Get_Vertex_Instance_Sum().ToString());

            // 頂点情報書き込み
            {
                // ☆　変数宣言 ☆ //
                List<UC_Vertex_Setting> vertex_setting_list = uC_Vertex_Layout1.M_Get_Vertex_Layout_List(); // 頂点の変数の情報のリスト


                // 頂点情報を全て書き込む
                foreach (var now_vertex_setting in vertex_setting_list)
                {
                    write_data.Add
                        (
                        // バイト数を書き込む
                        now_vertex_setting.M_Get_Byte_Sum().ToString() + ","
                        +

                        // フォーマットを書き込む
                        now_vertex_setting.M_Get_Format_String() + ","
                        +

                        // 変数の要素数を書き込む
                        now_vertex_setting.M_Get_Vertex_Element_Sum().ToString() + ","
                        );
                }
            }

            // 全てのシェーダーの情報をそれぞれ書き込む
            {
                // ☆ 変数宣言 ☆ //
                List<C_Shader_Data> shader_inform_list = uC_Shader_Inform1.M_Get_Shader_Inform_List();  // シェーダー設定用のデータのリスト

                List<bool> shader_active_list = uC_Shader_Inform1.M_Get_Shader_Activate_List(); // シェーダーを有効にするかどうかのリスト


                // シェーダーの種類数分書き込む
                for (int l_now_shader_kind = 0; l_now_shader_kind < (int)E_SHADER_NUMBER.e_SUM; l_now_shader_kind++)
                {
                    // シェーダーが有効じゃないなら今の種類のシェーダーは書き込まない
                    if (shader_active_list[l_now_shader_kind] == false)
                    {
                        continue;
                    }


                    // ☆ 変数宣言 ☆ //
                    string shader_kind = M_Get_Shader_Kind_String((E_SHADER_NUMBER)l_now_shader_kind);  // シェーダーの種類を示す文字列


                    // シェーダーの開始と使用するシェーダー名を書き込む
                    write_data.Add(shader_kind + "START:" + shader_inform_list[l_now_shader_kind].m_use_shader_name);

                    // 定数バッファ数を書き込む
                    write_data.Add(shader_inform_list[l_now_shader_kind].m_constant_buffer_sum.ToString());

                    // テクスチャ数を書き込む
                    write_data.Add(shader_inform_list[l_now_shader_kind].m_texture_buffer_sum.ToString());

                    // サンプラー数を書き込む
                    write_data.Add(shader_inform_list[l_now_shader_kind].m_sampler_sum.ToString());

                    // 定数バッファの開始位置を書き込む
                    write_data.Add(shader_kind + "CON:");

                    // 定数バッファの情報を書き込む
                    foreach (var now_constant_inform in shader_inform_list[l_now_shader_kind].m_constant_inform_list)
                    {
                        write_data.Add
                            (
                            // 定数バッファ名
                            now_constant_inform.m_name + ","
                            +

                            // 配列数
                            now_constant_inform.m_element_sum.ToString() + ","
                            +

                            // 定数データを生成するかどうか
                            M_Get_Flg_String(now_constant_inform.m_flg_data_create) + ","
                            );
                    }

                    // テクスチャの開始位置を書き込む
                    write_data.Add(shader_kind + "TEX:");

                    // テクスチャの情報を書き込む
                    foreach (var now_texture_inform in shader_inform_list[l_now_shader_kind].m_texture_inform_list)
                    {
                        write_data.Add
                            (
                            // テクスチャ識別名
                            now_texture_inform.m_name + ","
                            +

                            // 初期のテクスチャ設定を行う
                            now_texture_inform.m_initialize_texture_setting + ","
                            );
                    }

                    // サンプラーの開始位置を書き込む
                    write_data.Add(shader_kind + "SAM:");

                    // サンプラーの情報を書き込む
                    foreach (var now_sampler_inform in shader_inform_list[l_now_shader_kind].m_sampler_inform)
                    {
                        write_data.Add
                            (
                            // UVの使用方法を書き込む
                            now_sampler_inform.m_uv_setting + ","
                            );
                    }
                }
            }

            
            //  ファイルの生成  //
            
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elsst";   // 拡張子


            sfd.FileName = TB_Save_Name.Text + "." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")|*." + ";*." + extension + "|すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "シェーダーの情報の保存先とファイル名を決めてください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, write_data[now_write_raw] + Environment.NewLine);
                }
            }
        }

        // シェーダーの種類を文字列に変換して返す　引数：シェーダーの種類を指定する番号　戻り値：シェーダーの種類を示す文字列
        private string M_Get_Shader_Kind_String(E_SHADER_NUMBER in_shader_number)
        {
            if (in_shader_number == E_SHADER_NUMBER.e_VERTEX_SHADER)
            {
                return "VS";
            }
            else if (in_shader_number == E_SHADER_NUMBER.e_HUL_SHADER)
            {
                return "HS";
            }
            else if (in_shader_number == E_SHADER_NUMBER.e_DOMAIN_SHADER)
            {
                return "DS";
            }
            else if (in_shader_number == E_SHADER_NUMBER.e_GEOMETRY_SHADER)
            {
                return "GS";
            }
            else if (in_shader_number == E_SHADER_NUMBER.e_PIXEL_SHADER)
            {
                return "PS";
            }
            else
            {
                return "AS";
            }
        }

        // フラグを文字列に変換して返す　引数：フラグ（bool）　戻り値：変換後の文字列、TRUE、FALSE
        private string M_Get_Flg_String(bool in_flg)
        {
            if (in_flg)
            {
                return "TRUE";
            }
            else
            {
                return "FALSE";
            }
        }
    }
}
