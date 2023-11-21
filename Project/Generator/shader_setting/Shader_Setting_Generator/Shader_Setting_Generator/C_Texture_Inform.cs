using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shader_Setting_Generator
{
    // ☆ クラス ☆ //

    // テクスチャ用の情報
    internal class C_Texture_Inform
    {
        // ☆ 変数宣言 ☆ //
        public string m_name = "default";   // テクスチャ識別名

        public string m_initialize_texture_setting = "default"; // 初期のテクスチャ設定


        // ☆ 関数 ☆ //

        //-☆- 初期化と終了時 -☆-//

        // コンストラクタ
        public C_Texture_Inform(string in_name, string in_initialize_texture_setting)
        {
            m_name = in_name;
            m_initialize_texture_setting = in_initialize_texture_setting;

            return;
        }
    }
}
