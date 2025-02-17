using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.texture_buffer
{
    public partial class UC_Texture_Inform : UserControl
    {
        // ☆ 変数宣言 ☆ //
        private C_Texture_Inform m_texture_inform = new C_Texture_Inform("default", "default"); // テクスチャ情報


        // ☆ 関数 ☆ //

        public UC_Texture_Inform()
        {
            InitializeComponent();
        }

        private void UC_Texture_Inform_Load(object sender, EventArgs e)
        {
            CB_Use_Texture.SelectedIndex = 0;
        }

        // テクスチャ情報の番号を設定する　引数：テクスチャ情報の番号
        public void M_Set_Texture_Inform_Number(int in_texture_inform_number)
        {
            TB_Texture_Buffer_Number.Text = in_texture_inform_number.ToString();

            return;
        }

        // テクスチャ情報を返す　戻り値：テクスチャ情報
        public C_Texture_Inform M_Get_Texture_Inform()
        {
            m_texture_inform = new C_Texture_Inform(m_texture_inform.m_name, M_Cut_To_End_Mark(CB_Use_Texture.Text));

            return m_texture_inform;
        }

        // テクスチャバッファ情報をセットする　引数：テクスチャバッファ情報
        public void M_Set_Texture_Inform(C_Texture_Inform in_set_texture_inform)
        {
            m_texture_inform = new C_Texture_Inform(in_set_texture_inform.m_name, M_Cut_To_End_Mark(in_set_texture_inform.m_initialize_texture_setting));

            return;
        }

        // テクスチャバッファ識別名が変更されたら更新
        private void TB_Texture_Name_TextChanged(object sender, EventArgs e)
        {
            m_texture_inform = new C_Texture_Inform(CB_Texture_Name.Text, m_texture_inform.m_initialize_texture_setting);

            return;
        }


        // 指定された文字列から終了マーク（：）を探してそれまでの文字列を返す　引数：切り取る文字列　戻り値：切り取った結果の文字列
        private string M_Cut_To_End_Mark(string in_string)
        {
            int end_mark_is_this = 0;   // 終了マークの番号

            for (end_mark_is_this = 0; end_mark_is_this < in_string.Length; end_mark_is_this++)
            {
                if (in_string[end_mark_is_this] == '：')
                {
                    return in_string.Substring(0, end_mark_is_this);
                }
            }

            return in_string;
        }
    }
}
