using _3D_Model_Converter_And_Drawer._3D_model_Convert;
using _3D_Model_Converter_And_Drawer._3Dmodel_Convert;
using _3D_Model_Converter_And_Drawer.Animation_Convert;
using _3D_Model_Converter_And_Drawer.UI;
using _3D_Model_Converter_And_Drawer.UI.Announce_Bord;
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
		private Scene now_scene = new Scene();  // シーン情報

		static private List<S_Write_Bone_Data_Inform> m_bone_data_list = new List<S_Write_Bone_Data_Inform>();  // ボーン情報のリスト

		static private List<string> m_material_name_list = new List<string>();   // マテリアル名のリスト
		static private List<string> m_born_name_list = new List<string>();       // ボーン名のリスト
		static private List<string> m_mesh_name_list = new List<string>();       // メッシュ名のリスト
		static private List<string> m_animation_data_name_list = new List<string>(); // アニメーションデータ名のリスト

		static private bool m_is_active = false; // フォームがアクティブであればtrue


		// ☆ プロパティ ☆ //

		// ボーン情報のリスト
		static public List<S_Write_Bone_Data_Inform> mp_bone_data_list
		{
			// ゲッタ
			get
			{
				return m_bone_data_list;
			}
		}

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

		// フォームがアクティブであればtrue
		static public bool mp_is_active
		{
			// ゲッタ
			get
			{
				return m_is_active;
			}
		}


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		public Form_3D_Model_Convert_Setting()
		{
			// コンポーネントの初期化
			InitializeComponent();

			m_is_active = true;

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


		// 初期化を行う　引数：モデルの情報
		public void M_Initialize(Scene in_set_scene)
		{
			// シーンをセット
			now_scene = in_set_scene;

			// リストを初期化
			m_material_name_list.Clear();
			m_mesh_name_list.Clear();
			m_born_name_list.Clear();
			m_animation_data_name_list.Clear();
			m_bone_data_list.Clear();


			// 最初のボーンの情報を設定（再帰処理でできない）
			m_bone_data_list.Add
			(
				new S_Write_Bone_Data_Inform
				(
					now_scene.RootNode.Name,
					m_bone_data_list.Count,
					-1,
					new List<int>(),
					now_scene.RootNode.Transform
				)
			);

			// メッシュ数分ボーン名とインデックスの関連付けを行う
			CS_My_Math_System.M_Get_Bone_Information(ref m_bone_data_list, now_scene.RootNode.Children);

			// ルートボーンの子ボーンの情報を設定
			{
				// ☆ 変数宣言 ☆ //
				List<int> children_list = new List<int>();   // 子ボーンの番号リスト


				// 子ボーンの番号リストを生成する
				foreach (var l_now_child_bone in now_scene.RootNode.Children)
				{
					children_list.Add(CS_My_Math_System.M_Get_Bone_Index_From_Name(l_now_child_bone.Name, m_bone_data_list));
				}

				// 子ボーンの番号リストを設定する
				m_bone_data_list[0] = new S_Write_Bone_Data_Inform
				(
					m_bone_data_list[0].name,
					m_bone_data_list[0].index,
					m_bone_data_list[0].parent_index,
					children_list,
					m_bone_data_list[0].offset_matrix
				);
			}


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
			foreach (var now_born in m_bone_data_list)
			{
				m_born_name_list.Add(now_born.name);
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
			Form_Announce_Bord form_announce = new Form_Announce_Bord();	// 告知するボード用のフォーム

			string now_doubling_material = uc_material_name_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


			// マテリアル名に被りがあるなら実行しない
			if (now_doubling_material != "NOTHING")
			{
				MessageBox.Show("マテリアル名に被りがあります。被ったマテリアル名：" + now_doubling_material);
				return;
			}


            // 書き込み中を示すボードを表示
            form_announce.M_Set_Announce_Text("マテリアルデータ生成中");

            // ボードを画面の真ん中に表示する
			form_announce.StartPosition = FormStartPosition.CenterScreen;
            form_announce.Show();


            // マテリアル情報を生成
            CS_Material_Inform_Convert_System.M_Convert_Material_Inform(now_scene, ref form_announce);


			// 書き込み中を示すボードを削除
			form_announce.Dispose();

            return;
		}


		// アニメーションデータ生成ボタンが押されたとき
		private void b_animation_data_convert_button_Click(object sender, EventArgs e)
		{
            // ☆ 変数宣言 ☆ //
            Form_Announce_Bord form_announce = new Form_Announce_Bord();    // 告知するボード用のフォーム

            string now_doubling_animation = uc_animation_data_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


			// アニメーション名に被りがあるなら実行しない
			if (now_doubling_animation != "NOTHING")
			{
				MessageBox.Show("アニメーションデータ名に被りがあります。被ったアニメーションデータ名：" + now_doubling_animation);
				return;
            }


            // 書き込み中を示すボードを表示
            form_announce.M_Set_Announce_Text("アニメーションデータ生成中");

            // ボードを画面の真ん中に表示する
            form_announce.StartPosition = FormStartPosition.CenterScreen;
            form_announce.Show();


            // アニメーションデータを生成
            CS_Animation_Convert_System.M_Convert_Animation_Data(now_scene, ref form_announce);


            // 書き込み中を示すボードを削除
            form_announce.Dispose();

            return;
		}


		// 静的なモデルに変換するボタンが押されたとき
		private void B_static_model_convert_button_Click(object sender, EventArgs e)
		{
            // ☆ 変数宣言 ☆ //
            Form_Announce_Bord form_announce = new Form_Announce_Bord();    // 告知するボード用のフォーム

            string now_doubling_material = uc_material_name_list.M_Check_Name_Doubling();  // 被りがあるマテリアルの名前


			// マテリアル名に被りがあるなら実行しない
			if (now_doubling_material != "NOTHING")
			{
				MessageBox.Show("マテリアル名に被りがあります。被ったマテリアル名：" + now_doubling_material);
				return;
            }


            // 書き込み中を示すボードを表示
            form_announce.M_Set_Announce_Text("静的モデルデータ生成中");


            // ボードを画面の真ん中に表示する
            form_announce.StartPosition = FormStartPosition.CenterScreen;
            form_announce.Show();


            // 静的なモデルを生成
            CS_3D_Model_Convert_System.M_Convert_Static_Model(now_scene, ref form_announce);


            // 書き込み中を示すボードを削除
            form_announce.Dispose();

            return;
		}


		// 動的なモデルに変換するボタンが押されたとき
		private void b_animative_model_generate_button_Click(object sender, EventArgs e)
		{
            // ☆ 変数宣言 ☆ //
            Form_Announce_Bord form_announce = new Form_Announce_Bord();    // 告知するボード用のフォーム

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


            // 書き込み中を示すボードを表示
            form_announce.M_Set_Announce_Text("アニメーションモデルデータ生成中");

            // ボードを画面の真ん中に表示する
            form_announce.StartPosition = FormStartPosition.CenterScreen;
            form_announce.Show();


            // アニメーション可能なモデルを生成
            CS_3D_Model_Convert_System.M_Convert_Animation_Model(now_scene, ref form_announce);


            // 書き込み中を示すボードを削除
            form_announce.Dispose();

            return;
		}


		// フォームが閉じられたとき
		private void Form_3D_Model_Convert_Setting_FormClosed(object sender, FormClosedEventArgs e)
		{
			m_is_active = false;

			m_mesh_name_list.Clear();
			m_mesh_name_list = new List<string>();
			m_born_name_list.Clear();
			m_born_name_list = new List<string>();
			m_animation_data_name_list.Clear();
			m_animation_data_name_list = new List<string>();
			m_bone_data_list.Clear();
			m_bone_data_list = new List<S_Write_Bone_Data_Inform>();
			m_material_name_list.Clear();
			m_material_name_list = new List<string>();

			now_scene.Clear();
			now_scene = null;

			// ガーベージコレクションを実行し、ファイナライザの実行を待つ
			GC.Collect();
			GC.WaitForPendingFinalizers();

			return;
		}
	}
}
