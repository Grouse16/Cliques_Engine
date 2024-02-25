using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ELMaterial_Generator.Blend_Setting_UI
{
    // ☆ 列挙 ☆ //

    // 書き込み設定を指定する列挙
    public enum E_WRITE_SETTING
    {
        e_ADD,    // 加法混色
        e_SUB,    // 減法混色
    }


    // ☆ クラス ☆ //

    // ブレンド設定用のユーザーコントロール
    public partial class UC_Blend_Setting : UserControl
    {
        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Blend_Setting()
        {
            InitializeComponent();

            CB_write_setting.SelectedIndex = 0;

            // サイズを固定
            MaximumSize = Size;
            MinimumSize = Size;

            return;
        }


        //-☆- ゲッタ -☆-//

        // 書き込み設定を取得　戻り値：書き込み設定
        public string M_Get_Write_Setting_In_Text()
        {
            switch (CB_write_setting.SelectedIndex)
            {
                // 加法混色
                case (int)E_WRITE_SETTING.e_ADD:
                    return "ADD";

                // 減法混色
                case (int)E_WRITE_SETTING.e_SUB:
                    return "SUB";

                // その他
                default:
                    return "ADD";
            }
        }


        //-☆- セッタ -☆-//

        // ブレンド設定の番号を編集　引数：ブレンド設定の番号
        public void M_Set_Blend_Setting_Number(int in_set_number)
        {
            TB_Blend_Setting_Text.Text = "ブレンド設定 <" + in_set_number.ToString() + ">";

            return;
        }

        // 書き込み設定をセット　引数：書き込み設定
        public void M_Set_Write_Setting(E_WRITE_SETTING in_set_write_setting)
        {
            CB_write_setting.SelectedIndex = (int)in_set_write_setting;

            return;
        }
    }
}
