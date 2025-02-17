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
    public partial class UC_Constant_Buffer_Setting : UserControl
    {
        // ☆ 変数宣言 ☆ //
        private C_Constant_Buffer_Inform m_constant_buffer_inform = new C_Constant_Buffer_Inform("default", 1, false);    // 定数バッファ情報


        // ☆ 関数 ☆ //

        public UC_Constant_Buffer_Setting()
        {
            InitializeComponent();
        }

        // ロード時の初期化
        private void UC_Constant_Buffer_Setting_Load(object sender, EventArgs e)
        {
            CB_Constant_Data_Enough_Flg.SelectedIndex = 1;
        }

        // 定数バッファ情報を返す　戻り値：定数バッファ情報
        public C_Constant_Buffer_Inform M_Get_Constant_Inform()
        {
            m_constant_buffer_inform = new C_Constant_Buffer_Inform(M_Cut_To_End_Mark(CB_Constant_Buffer_Name.Text), m_constant_buffer_inform.m_element_sum, m_constant_buffer_inform.m_flg_data_create);

            return m_constant_buffer_inform;
        }

        // 定数バッファ情報をセットする　引数：定数バッファ情報
        public void M_Set_Constant_Inform(C_Constant_Buffer_Inform in_set_constant_inform)
        {
            m_constant_buffer_inform = new C_Constant_Buffer_Inform(in_set_constant_inform.m_name, in_set_constant_inform.m_element_sum, in_set_constant_inform.m_flg_data_create);

            return;
        }

        // 定数バッファの番号を登録　引数：設定する番号
        public void M_Set_Constant_Buffer_Num(int in_set_number)
        {
            TB_Constant_Buffer_Number.Text = in_set_number.ToString();

            return;
        }


        // 配列数が変更されたら更新
        private void NM_Element_Sum_ValueChanged(object sender, EventArgs e)
        {
            m_constant_buffer_inform = new C_Constant_Buffer_Inform(m_constant_buffer_inform.m_name, (int)NM_Element_Sum.Value, m_constant_buffer_inform.m_flg_data_create);

            return;
        }

        // 定数データを使用するかどうかのフラグを変更されたら更新
        private void CB_Constant_Data_Enough_Flg_SelectedIndexChanged(object sender, EventArgs e)
        {
            // falseの場合はデータを生成しない
            if (M_Cut_To_End_Mark(CB_Constant_Data_Enough_Flg.Text) == "false")
            {
                m_constant_buffer_inform = new C_Constant_Buffer_Inform(m_constant_buffer_inform.m_name, m_constant_buffer_inform.m_element_sum, false);
            }

            // trueの場合はデータを生成する
            else
            {
                m_constant_buffer_inform = new C_Constant_Buffer_Inform(m_constant_buffer_inform.m_name, m_constant_buffer_inform.m_element_sum, true);
            }
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
