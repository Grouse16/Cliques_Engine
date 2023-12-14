using SharpDXSample;
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

    // 3Dモデルインポート用bのフォーム
    public partial class Form_Animation_Model_Importer : Form
    {
        // ☆ 変数 ☆ //
        private SharpDXSample.UC_DX_11_Panel m_dx11_panel;  // レンダラーの参照

        private string m_animation_model_path = ""; // アニメーションモデルのパス


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public Form_Animation_Model_Importer()
        {
            InitializeComponent();
        }


        // ロード
        private void Form_3D_Model_Importer_Load(object sender, EventArgs e)
        {
            // サイズを固定
            MaximumSize = Size;
            MinimumSize = Size;

            return;
        }


        // 初期化の実行　引数：アニメーションモデルのパス, レンダラーの参照
        public void M_Initialize(string in_animation_model_path, SharpDXSample.UC_DX_11_Panel in_set_dx11_panel)
        {
            m_animation_model_path = in_animation_model_path;
            m_dx11_panel = in_set_dx11_panel;

            return;
        }


        //-☆- イベント -☆-//

        // キャンセルボタンが押されたとき
        private void b_cancel_button_Click(object sender, EventArgs e)
        {
            // フォームを閉じる
            Close();

            return;
        }


        // インポートボタンが押されたとき
        private void b_model_import_button_Click(object sender, EventArgs e)
        {
            // フォームを閉じる
            Close();
            
            return;
        }
    }
}
