using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shader_Setting_Generator
{
    // ☆ クラス ☆ //

    // サンプラー情報のクラス
    internal class C_Sampler_Inform
    {
        // ☆ 変数宣言 ☆ //
        public string m_uv_setting = "default";    // UVの扱い方を指定する文字列


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public C_Sampler_Inform(string in_setting)
        {
            m_uv_setting = in_setting;

            return;
        }
    }
}
