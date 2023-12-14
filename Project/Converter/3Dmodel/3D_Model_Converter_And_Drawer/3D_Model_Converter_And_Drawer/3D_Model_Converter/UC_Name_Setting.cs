using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    // ☆ クラス ☆ //

    // 名前を設定するユーザーコントロール
    public partial class UC_Name_Setting : UserControl
    {
        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Name_Setting()
        {
            InitializeComponent();
            tb_print_material_number.ReadOnly = true;
        }


        //-☆- セッタ -☆-//

        // 番号をセットする
        public void M_Set_Number_Prate(string in_number)
        {
            tb_print_material_number.Text = in_number;
        }


        // 名前をセットする
        public void M_Set_Name(string in_name)
        {
            tb_material_name.Text = in_name;
        }

        
        //-☆- ゲッタ -☆-//

        // 番号を取得する
        public string M_Get_Name()
        {
            return tb_material_name.Text;
        }
    }
}
