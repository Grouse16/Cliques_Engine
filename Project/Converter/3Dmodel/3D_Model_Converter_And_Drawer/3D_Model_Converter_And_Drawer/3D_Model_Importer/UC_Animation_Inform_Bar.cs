using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer
{
    // ☆ クラス ☆ //

    // アニメーション名表示用ボックス
    public partial class UC_Animation_Inform_Bar : UserControl
    {
        // ☆ 変数 ☆ //
        private string m_animation_name = ""; // アニメーション名
        private string m_animation_path = ""; // アニメーションパス


        // ☆ プロパティ ☆ //

        // アニメーション名
        public string mp_animation_name
        {
            // ゲッタ
            get
            {
                return m_animation_name;
            }
        }


        // アニメーションパス
        public string mp_animation_path
        {
            // ゲッタ
            get
            {
                return m_animation_path;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public UC_Animation_Inform_Bar()
        {
            InitializeComponent();

            return;
        }


        //-☆- セッタ -☆-//

        // アニメーション情報をセット　引数：アニメーション名、アニメーションパス
        public void Set_Animation_Inform(string in_animation_name, string in_animation_path)
        {
            // アニメーション名をセット
            m_animation_name = in_animation_name;
            tb_animation_name.Text = m_animation_name;

            // アニメーションパスをセット
            m_animation_path = in_animation_path;

            return;
        }
    }
}
