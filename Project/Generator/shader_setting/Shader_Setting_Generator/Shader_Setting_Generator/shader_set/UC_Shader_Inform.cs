using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shader_Setting_Generator.shader_set
{
    public partial class UC_Shader_Inform : UserControl
    {
        // ☆ 変数宣言 ☆ //
        private List<C_Shader_Data> m_shader_data = new List<C_Shader_Data>();    // シェーダーのデータのリスト

        private int m_now_shader_kind = 0;    // 現在のシェーダーの種類の番号


        // ☆ 関数 ☆ //

        public UC_Shader_Inform()
        {
            InitializeComponent();
        }

        // ロード時の初期化
        private void UC_Shader_Inform_Load(object sender, EventArgs e)
        {
            for (int l_now_shader = 0; l_now_shader < (int)E_SHADER_NUMBER.e_SUM; l_now_shader++)
            {
                m_shader_data.Add(new C_Shader_Data());
            }

            CB_Setting_Shader_Kind.SelectedIndex = 1;
            m_now_shader_kind = 1;
        }


        // 定数バッファ数の変更
        private void NM_Constant_Buffer_Sum_ValueChanged(object sender, EventArgs e)
        {
            uC_Constant_Buffer_Setting_List1.M_Set_Constant_Buffer_Sum((int)NM_Constant_Buffer_Sum.Value);
        }

        // テクスチャバッファ数の変更
        private void NM_Texture_Buffer_Sum_ValueChanged(object sender, EventArgs e)
        {
            uC_Texture_Inform_List1.M_Set_Texture_Buffer_Sum((int)NM_Texture_Buffer_Sum.Value);
        }

        // サンプラー情報数の変更
        private void NM_Sampler_Sum_ValueChanged(object sender, EventArgs e)
        {
            uC_Sampler_Setting_List1.M_Set_Sampler_Sum((int)NM_Sampler_Sum.Value);
        }

        // リセットボタンが押されたらリセットを実行する
        private void B_Reset_MouseUp(object sender, MouseEventArgs e)
        {
            NM_Constant_Buffer_Sum.Value = 0;
            uC_Constant_Buffer_Setting_List1.M_Reset();

            NM_Texture_Buffer_Sum.Value = 0;
            uC_Texture_Inform_List1.M_Reset();

            NM_Sampler_Sum.Value = 0;
            uC_Sampler_Setting_List1.M_Reset();

            return;
        }

        // シェーダー情報のリストを返す　戻り値：シェーダー情報リスト
        public List<C_Shader_Data> M_Get_Shader_Inform_List()
        {
            // シェーダー情報を更新
            M_Attach_Shader_Inform();

            // シェーダー情報リストを返す
            return m_shader_data;
        }

        // 現在画面に出ているデータをシェーダーの情報として登録する
        private void M_Attach_Shader_Inform()
        {
            // シェーダー名を設定
            m_shader_data[m_now_shader_kind].m_use_shader_name = TB_Shader_Name.Text;

            // リソース数を設定
            m_shader_data[m_now_shader_kind].m_constant_buffer_sum = (int)NM_Constant_Buffer_Sum.Value;
            m_shader_data[m_now_shader_kind].m_texture_buffer_sum = (int)NM_Texture_Buffer_Sum.Value;
            m_shader_data[m_now_shader_kind].m_sampler_sum = (int)NM_Sampler_Sum.Value;

            // リソース情報を初期化
            m_shader_data[m_now_shader_kind].m_constant_inform_list.Clear();
            m_shader_data[m_now_shader_kind].m_texture_inform_list.Clear();
            m_shader_data[m_now_shader_kind].m_sampler_inform.Clear();

            // 定数バッファ情報を記録
            foreach (var constant_buffer_inform in uC_Constant_Buffer_Setting_List1.M_Get_Constant_Buffer_List())
            {
                // ☆ 変数宣言 ☆ //
                C_Constant_Buffer_Inform now_constant_buffer = constant_buffer_inform.M_Get_Constant_Inform();  // 今の定数バッファ情報


                m_shader_data[m_now_shader_kind].m_constant_inform_list.Add(new C_Constant_Buffer_Inform(M_Cut_To_End_Mark(now_constant_buffer.m_name), now_constant_buffer.m_element_sum, now_constant_buffer.m_flg_data_create));
            }

            // テクスチャバッファ情報を記録
            foreach (var texture_buffer_inform in uC_Texture_Inform_List1.M_Get_Texture_Buffer_List())
            {
                // ☆ 変数宣言 ☆ //
                C_Texture_Inform now_texture_buffer = texture_buffer_inform.M_Get_Texture_Inform();  // 今のテクスチャバッファ情報


                m_shader_data[m_now_shader_kind].m_texture_inform_list.Add(new C_Texture_Inform(now_texture_buffer.m_name, M_Cut_To_End_Mark(now_texture_buffer.m_initialize_texture_setting)));
            }

            // サンプラー情報を記録
            foreach (var sampler_inform in uC_Sampler_Setting_List1.M_Get_Sampler_List())
            {
                // ☆ 変数宣言 ☆ //
                C_Sampler_Inform now_sampler = sampler_inform.M_Get_Sampler_Inform();  // 今のサンプラー情報


                m_shader_data[m_now_shader_kind].m_sampler_inform.Add(new C_Sampler_Inform(now_sampler.m_uv_setting));
            }

            return;
        }

        // シェーダーを有効にするかどうかのリストを返す　戻り値：シェーダー有効化リスト
        public List<bool> M_Get_Shader_Activate_List()
        {
            // ☆ 変数宣言 ☆ //
            List<bool> shader_activate_list = new List<bool>(); // シェーダーを有効にするかどうかのリスト


            // リストを生成する
            for (int l_num_shader = 0; l_num_shader < (int)E_SHADER_NUMBER.e_SUM; l_num_shader++)
            {
                shader_activate_list.Add(true);
            }


            // シェーダーを有効にするかどうかのリストを設定する
            shader_activate_list[(int)E_SHADER_NUMBER.e_ALL_SHADER] = true;
            shader_activate_list[(int)E_SHADER_NUMBER.e_VERTEX_SHADER] = CHB_Vertex_Shader.Checked;
            shader_activate_list[(int)E_SHADER_NUMBER.e_HUL_SHADER] = CHB_Hul_Shader.Checked;
            shader_activate_list[(int)E_SHADER_NUMBER.e_DOMAIN_SHADER] = CHB_Domain_Shader.Checked;
            shader_activate_list[(int)E_SHADER_NUMBER.e_GEOMETRY_SHADER] = CHB_Geometry_Shader.Checked;
            shader_activate_list[(int)E_SHADER_NUMBER.e_PIXEL_SHADER] = CHB_Pixel_Shader.Checked;

            // シェーダーを有効にするかどうかのリスト
            return shader_activate_list;
        }
        
        // シェーダーの種類を変更したときの更新
        private void CB_Setting_Shader_Kind_SelectedIndexChanged(object sender, EventArgs e)
        {
            // 現在の情報を記録
            M_Attach_Shader_Inform();


            // シェーダーの種類を変更
            m_now_shader_kind = CB_Setting_Shader_Kind.SelectedIndex;

            // シェーダー変更先のシェーダー名を表示
            TB_Shader_Name.Text = m_shader_data[m_now_shader_kind].m_use_shader_name;

            // シェーダー変更先の設定数を設定
            NM_Constant_Buffer_Sum.Value = m_shader_data[m_now_shader_kind].m_constant_buffer_sum;
            uC_Constant_Buffer_Setting_List1.M_Set_Constant_Buffer_Sum((int)NM_Constant_Buffer_Sum.Value);
            NM_Texture_Buffer_Sum.Value = m_shader_data[m_now_shader_kind].m_texture_buffer_sum;
            uC_Texture_Inform_List1.M_Set_Texture_Buffer_Sum((int)NM_Texture_Buffer_Sum.Value);
            NM_Sampler_Sum.Value = m_shader_data[m_now_shader_kind].m_sampler_sum;
            uC_Sampler_Setting_List1.M_Set_Sampler_Sum((int)NM_Sampler_Sum.Value);


            //  変更先のシェーダーの情報を画面描画用に設定する  //

            // 定数バッファ情報を初期化
            for (int l_now_constant_inform = 0; l_now_constant_inform < (int)NM_Constant_Buffer_Sum.Value; l_now_constant_inform++)
            {
                uC_Constant_Buffer_Setting_List1.M_Get_Constant_Buffer_List()[l_now_constant_inform].M_Set_Constant_Inform(m_shader_data[m_now_shader_kind].m_constant_inform_list[l_now_constant_inform]);
            }

            // テクスチャバッファ情報を初期化
            for (int l_now_texture_inform = 0; l_now_texture_inform < (int)NM_Texture_Buffer_Sum.Value; l_now_texture_inform++)
            {
                uC_Texture_Inform_List1.M_Get_Texture_Buffer_List()[l_now_texture_inform].M_Set_Texture_Inform(m_shader_data[m_now_shader_kind].m_texture_inform_list[l_now_texture_inform]);
            }

            // サンプラー情報を初期化
            for (int l_now_sampler_inform = 0; l_now_sampler_inform < (int)NM_Sampler_Sum.Value; l_now_sampler_inform++)
            {
                uC_Sampler_Setting_List1.M_Get_Sampler_List()[l_now_sampler_inform].M_Set_Sampler_Inform(m_shader_data[m_now_shader_kind].m_sampler_inform[l_now_sampler_inform]);
            }

            // 全シェーダー共通情報ならシェーダー名はない
            if (CB_Setting_Shader_Kind.SelectedIndex == 0)
            {
                TB_Shader_Name.ReadOnly = true;
                TB_Shader_Name.Text = "";
            }

            // 通常のシェーダーならシェーダー名あり
            else
            {
                TB_Shader_Name.ReadOnly = false;
            }

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
