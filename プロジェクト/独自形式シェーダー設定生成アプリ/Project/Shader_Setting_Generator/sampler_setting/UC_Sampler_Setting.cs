using Shader_Setting_Generator.texture_buffer;
using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.sampler_setting
{
    public partial class UC_Sampler_Setting : UserControl
    {
        // ☆ 変数宣言 ☆ //
        private C_Sampler_Inform m_sampler_setting = new C_Sampler_Inform("default"); // サンプラー設定


        // ☆ 関数 ☆ //

        public UC_Sampler_Setting()
        {
            InitializeComponent();
        }

        
        private void UC_Sampler_Setting_Load(object sender, EventArgs e)
        {
            CB_Sampler_Setting.SelectedIndex = 3;
        }

        // サンプラー設定情報の番号をセットする　引数：サンプラー設定の番号
        public void M_Set_Sampler_Number(int in_sampler_number)
        {
            TB_Sampler_Setting_Number.Text = in_sampler_number.ToString();

            return;
        }

        // サンプラー設定情報を返す　引数：サンプラー設定情報
        public C_Sampler_Inform M_Get_Sampler_Inform()
        {
            return m_sampler_setting;
        }

        // サンプラー情報をセットする　引数：サンプラー情報
        public void M_Set_Sampler_Inform(C_Sampler_Inform in_set_sampler_inform)
        {
            m_sampler_setting = new C_Sampler_Inform(in_set_sampler_inform.m_uv_setting);

            return;
        }

        // UV設定に変更があったら更新する
        private void CB_Sampler_Setting_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_sampler_setting = new C_Sampler_Inform(M_Cut_To_End_Mark(CB_Sampler_Setting.Text));

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
