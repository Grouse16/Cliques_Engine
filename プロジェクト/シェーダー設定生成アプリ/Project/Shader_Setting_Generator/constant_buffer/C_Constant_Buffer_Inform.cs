using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shader_Setting_Generator
{
    // ☆ クラス ☆ //

    // 定数バッファの情報用のクラス
    public class C_Constant_Buffer_Inform
    {
        // ☆ 変数宣言 ☆ //
        public string m_name = "default"; // 定数バッファ名

        public int m_element_sum = 1; // 要素数

        public bool m_flg_data_create = false;   // 定数データを生成するかどうかのフラグ


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public C_Constant_Buffer_Inform(string in_name, int in_element_sum, bool in_flg_data_create)
        {
            m_name = in_name;
            m_element_sum = in_element_sum;
            m_flg_data_create = in_flg_data_create;

            return;
        }
    }
}
