using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shader_Setting_Generator
{
    // ☆ クラス ☆ //

    // シェーダーのデータのクラス
    internal class C_Shader_Data
    {
        // ☆ 変数宣言 ☆ //
        public List<C_Constant_Buffer_Inform> m_constant_inform_list;   // 定数バッファ情報リスト

        public List<C_Texture_Inform> m_texture_inform_list; // テクスチャ情報リスト

        public List<C_Sampler_Inform> m_sampler_inform;    // サンプラー情報リスト

        public int m_constant_buffer_sum = 0;   // 定数バッファ数
        public int m_texture_buffer_sum = 0;    // テクスチャバッファ数
        public int m_sampler_sum = 0;           // サンプラー数


        // ☆ 関数 ☆ //

        //-☆- 生成 -☆-//

        // 定数バッファを指定された数にする　引数：生成する定数バッファ数
        public void M_Create_Constant_Buffer(int in_new_constant_sum)
        {
            // ☆ 変数宣言 ☆ //
            List<C_Constant_Buffer_Inform> new_constant_inform_list = new List<C_Constant_Buffer_Inform>(); // 新しい定数バッファリスト


            // 新しい定数バッファの配列を生成
            for (int loop_num = 0; loop_num < in_new_constant_sum; loop_num++)
            {
                // 今まで持っていた定数バッファ数未満なら今ある情報を移す
                if (loop_num < m_constant_buffer_sum)
                {
                    new_constant_inform_list[loop_num] = m_constant_inform_list[loop_num];
                }

                // 今まで持っていた定数バッファ数以上なら新しい配列を追加する
                else
                {
                    new_constant_inform_list.Add(new C_Constant_Buffer_Inform("default", 0, true));
                }
            }

            // 新しい定数バッファに更新
            m_constant_inform_list = new_constant_inform_list;
            m_constant_buffer_sum = in_new_constant_sum;
        }

        // テクスチャ情報を指定された数にする　引数：生成するテクスチャ情報数
        public void M_Create_Texture_Buffer(int in_new_texture_sum)
        {
            // ☆ 変数宣言 ☆ //
            List<C_Texture_Inform> new_texture_inform_list = new List<C_Texture_Inform>(); // 新しいテクスチャ情報リスト


            // 新しいテクスチャ情報の配列を生成
            for (int loop_num = 0; loop_num < in_new_texture_sum; loop_num++)
            {
                // 今まで持っていたテクスチャ情報数未満なら今ある情報を移す
                if (loop_num < m_texture_buffer_sum)
                {
                    new_texture_inform_list[loop_num] = m_texture_inform_list[loop_num];
                }

                // 今まで持っていたテクスチャ情報数以上なら新しい配列を追加する
                else
                {
                    new_texture_inform_list.Add(new C_Texture_Inform("default", "default"));
                }
            }

            // 新しいテクスチャ情報に更新
            m_texture_inform_list = new_texture_inform_list;
            m_texture_buffer_sum = in_new_texture_sum;
        }

        // サンプラー情報を指定された数にする　引数：生成するサンプラー情報数
        public void M_Create_Sampler_Buffer(int in_new_sampler_sum)
        {
            // ☆ 変数宣言 ☆ //
            List<C_Sampler_Inform> new_sampler_inform_list = new List<C_Sampler_Inform>(); // 新しいサンプラー情報リスト


            // 新しいサンプラー情報の配列を生成
            for (int loop_num = 0; loop_num < in_new_sampler_sum; loop_num++)
            {
                // 今まで持っていたテクスチャ情報数未満なら今ある情報を移す
                if (loop_num < m_sampler_sum)
                {
                    new_sampler_inform_list[loop_num] = m_sampler_inform[loop_num];
                }

                // 今まで持っていたテクスチャ情報数以上なら新しい配列を追加する
                else
                {
                    new_sampler_inform_list.Add(new C_Sampler_Inform("default"));
                }
            }

            // 新しいテクスチャ情報に更新
            m_sampler_inform = new_sampler_inform_list;
            m_sampler_sum = in_new_sampler_sum;
        }
    }
}
