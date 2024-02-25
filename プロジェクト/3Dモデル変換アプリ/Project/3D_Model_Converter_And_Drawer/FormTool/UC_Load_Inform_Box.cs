using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer.FormTool
{
    // ☆ クラス ☆ //

    // ロードの情報を表示するユーザーコントロール
    public partial class UC_Load_Inform_Box : UserControl
    {
        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Load_Inform_Box()
        {
            InitializeComponent();
        }

        // ロード
        private void UC_Load_Inform_Box_Load(object sender, EventArgs e)
        {
            MaximumSize = new Size(Width, Height);
            MinimumSize = new Size(Width, Height);

            return;
        }


        //-☆- セッタ -☆-//
        
        // assimpによるモデルのロードの情報をセットする　引数：ロード時間, 物理メモリサイズ, 仮想メモリサイズ
        public void M_Set_Assimp_Load_Inform(float in_load_time, string in_physic_memory_size, string in_virtual_memory_size)
        {
            TB_assimp_sstmdl_load_time.Text = in_load_time.ToString() + "second";
            TB_assimp_sstmdl_load_physics_data_size.Text = in_physic_memory_size;
            TB_assimp_sstmdl_load_virtual_data_size.Text = in_virtual_memory_size;

            return;
        }


        // 変換後モデルのロードの情報をセットする　引数：ロード時間, 物理メモリサイズ, 仮想メモリサイズ
        public void M_Set_My_Model_Load_Inform(float in_load_time, string in_physic_memory_size, string in_virtual_memory_size)
        {
            TB_my_format_mdl_load_time.Text = in_load_time.ToString() + "second";
            TB_my_format_mdl_load_physics_data_size.Text = in_physic_memory_size;
            TB_my_format_mdl_load_virtual_data_size.Text = in_virtual_memory_size;

            return;
        }
    }
}
