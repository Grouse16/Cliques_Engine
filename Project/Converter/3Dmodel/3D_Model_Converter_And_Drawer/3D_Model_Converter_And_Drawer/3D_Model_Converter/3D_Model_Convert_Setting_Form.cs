using _3D_Model_Converter_And_Drawer._3D_model_Convert;
using _3D_Model_Converter_And_Drawer._3Dmodel_Convert;
using _3D_Model_Converter_And_Drawer.Animation_Convert;
using Assimp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // 3Dモデルの変換の設定をするフォーム
    public partial class Form_3D_Model_Convert_Setting : Form
    {
        // ☆ 変数宣言 ☆ //
        Scene now_scene = new Scene();  // シーン情報

        static private List<string> m_material_name_list = new List<string>();   // マテリアル名のリスト
        static private List<string> m_mesh_name_list = new List<string>();       // メッシュ名のリスト
        static private List<string> m_born_name_list = new List<string>();       // ボーン名のリスト
        static private List<string> m_animation_data_name_list = new List<string>(); // アニメーションデータ名のリスト


        // ☆ プロパティ ☆ //

        // マテリアル名のリスト
        static public List<string> mp_material_name_list
        {
            // ゲッタ
            get
            {
                return m_material_name_list;
            }
        }

        // メッシュ名のリスト
        static public List<string> mp_mesh_name_list
        {
            // ゲッタ
            get
            {
                return m_mesh_name_list;
            }
        }

        // ボーン名のリスト
        static public List<string> mp_born_name_list
        {
            // ゲッタ
            get
            {
                return m_born_name_list;
            }
        }

        // アニメーションデータ名のリスト
        static public List<string> mp_animation_data_name_list
        {
            // ゲッタ
            get
            {
                return m_animation_data_name_list;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public Form_3D_Model_Convert_Setting()
        {
            // コンポーネントの初期化
            InitializeComponent();

            return;
        }


        // ロード
        private void Form1_Load(object sender, EventArgs e)
        {
            // 設定項目の枠名のセット
            uc_material_name_list.M_Set_Frame_Name("マテリアル名の設定", "Material");
            uc_mesh_name_list.M_Set_Frame_Name("メッシュ名の設定", "Mesh");
            uc_born_name_list.M_Set_Frame_Name("ボーン名の設定", "Bone");
            uc_animation_data_list.M_Set_Frame_Name("アニメーションデータ名の設定", "Animation Data");

            // サイズの設定
            MaximumSize = Size;
            MinimumSize = Size;

            return;
        }


        // 初期化を行う
        public void M_Initialize(Scene in_set_scene)
        {
            // シーンをセット
            now_scene = in_set_scene;

            // リストを初期化
            m_material_name_list.Clear();
            m_mesh_name_list.Clear();
            m_born_name_list.Clear();
            m_animation_data_name_list.Clear();


            // マテリアル名の設定
            foreach (var now_material in in_set_scene.Materials)
            {
                m_material_name_list.Add(now_material.Name);
            }

            // メッシュ名の設定
            foreach (var now_mesh in in_set_scene.Meshes)
            {
                m_mesh_name_list.Add(now_mesh.Name);
            }

            // ボーン名の設定
            foreach (var now_born in in_set_scene.RootNode.Children)
            {
                m_born_name_list.Add(now_born.Name);
            }

            // アニメーションデータ名の設定
            foreach (var now_animation_data in in_set_scene.Animations)
            {
                m_animation_data_name_list.Add(now_animation_data.Name);
            }


            // リストの生成
            uc_material_name_list.M_Create_Name_List(m_material_name_list);
            uc_mesh_name_list.M_Create_Name_List(m_mesh_name_list);
            uc_born_name_list.M_Create_Name_List(m_born_name_list);
            uc_animation_data_list.M_Create_Name_List(m_animation_data_name_list);

            return;
        }


        //-☆- イベント -☆-//

        // 終了ボタンが押されたときはフォームを閉じる
        private void Exit_button_Click(object sender, EventArgs e)
        {
            this.Close();

            return;
        }


        // マテリアル情報生成ボタンが押されたとき
        private void B_material_inform_generate_button_Click(object sender, EventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            string now_doubling_material = uc_material_name_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


            // マテリアル名に被りがあるなら実行しない
            if (now_doubling_material != "NOTHING")
            {
                MessageBox.Show("マテリアル名に被りがあります。被ったマテリアル名：" + now_doubling_material);
                return;
            }


            // マテリアル情報を生成
            CS_Material_Inform_Convert_System.M_Convert_Material_Inform(now_scene);

            return;
        }


        // アニメーションデータ生成ボタンが押されたとき
        private void b_animation_data_convert_button_Click(object sender, EventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            string now_doubling_animation = uc_animation_data_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


            // アニメーション名に被りがあるなら実行しない
            if (now_doubling_animation != "NOTHING")
            {
                MessageBox.Show("アニメーションデータ名に被りがあります。被ったアニメーションデータ名：" + now_doubling_animation);
                return;
            }

            // アニメーションデータを生成
            CS_Animation_Convert_System.M_Convert_Animation_Data(now_scene);

            return;
        }


        // 静的なモデルに変換するボタンが押されたとき
        private void B_static_model_convert_button_Click(object sender, EventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            string now_doubling_material = uc_material_name_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


            // マテリアル名に被りがあるなら実行しない
            if (now_doubling_material != "NOTHING")
            {
                MessageBox.Show("マテリアル名に被りがあります。被ったマテリアル名：" + now_doubling_material);
                return;
            }

            // 静的なモデルを生成
            CS_3D_Model_Convert_System.M_Convert_Static_Model(now_scene);

            return;
        }

        // 動的なモデルに変換するボタンが押されたとき
        private void b_animative_model_generate_button_Click(object sender, EventArgs e)
        {
            // ☆ 変数宣言 ☆ //
            string now_doubling_material = uc_material_name_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前

            string now_doubling_born = uc_born_name_list.M_Check_Name_Doubling();  // 被りがあるボーンの名前


            // マテリアル名に被りがあるなら実行しない
            if (now_doubling_material != "NOTHING")
            {
                MessageBox.Show("マテリアル名に被りがあります。被ったマテリアル名：" + now_doubling_material);
                return;
            }

            // ボーン名に被りがあるなら実行しない
            if (now_doubling_born != "NOTHING")
            {
                MessageBox.Show("ボーン名に被りがあります。被ったボーン名：" + now_doubling_born);
                return;
            }

            // アニメーション可能なモデルを生成
            CS_3D_Model_Convert_System.M_Convert_Animation_Model(now_scene);

            return;
        }

    }
}
