//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：変形しないモデルのコンポーネントのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Static_Model_Component.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::COMPONENT::MODEL_COMPONENT;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_Component::C_Static_Model_Component(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_Component::~C_Static_Model_Component(void)
{
	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のモデルをロードする
// 引数   ：string ロードするモデル名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_Component::M_Load_Model_By_Name(std::string in_load_model_name)
{
	return mpr_variable.model_system.M_Load_3D_Model(in_load_model_name);
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ローカル座標の参照を返す
// 引数   ：void
// 戻り値 ：C_Transform & ローカル座標の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
MATH::C_Transform & C_Static_Model_Component::M_Get_Transform(void)
{
	return mpr_variable.transform;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画設定リストに描画設定を追加する
// 引数   ：int 描画設定の設定先番号, string 使用するマテリアル名, vector<string> 描画するメッシュ名のリスト
// 戻り値 ：C_Material_User * 追加したマテリアル使用システムのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MATERIAL::C_Material_User * C_Static_Model_Component::M_Set_Model_Draw_List(int in_draw_command_number, std::string in_material_name, std::vector<std::string> in_mesh_name_list)
{
	// 指定された番号分の配列が用意されていなければ配列を用意する
	if (in_draw_command_number >= mpr_variable.draw_command_list.size())
	{
		mpr_variable.draw_command_list.resize(in_draw_command_number + 1);
	}


	// 使用するマテリアル名がNATURAL、または空文字なら元からメッシュに登録されているマテリアルを使用する
	if (in_material_name == "NATURAL" || in_material_name == "")
	{
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW;
	}

	// マテリアル名を指定されている時はそのマテリアルをロードする
	else
	{
		// マテリアルを指定するフラグを立てる
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL;
		
		// マテリアルのロード、失敗したらエラーで抜ける
		if (mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Load_Material(in_material_name) == false)
		{
			return nullptr;
		}
	}

	// 描画するメッシュに指定があるなら登録する
	if (in_mesh_name_list.size() > 0)
	{
		mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list = in_mesh_name_list;

		// マテリアルを指定したうえでメッシュの指定を行う
		if (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option == ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL)
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL;
		}

		// メッシュの指定のみ行う
		else
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH;
		}
	}

	// 使用するマテリアル使用システムのアドレスを返す
	return &mpr_variable.draw_command_list[in_draw_command_number].material_data;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：モデルシステムのアドレスを返す
// 引数   ：void
// 戻り値 ：C_3D_Model_User & モデルシステムのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MODEL::C_3D_Model_User & C_Static_Model_Component::M_Get_Model_Address(void)
{
	return mpr_variable.model_system;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_Component::M_Update(void)
{
	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画位置となるワールドマトリクスを設定する、描画の開始時に実行する
// 引数   ：const XMMATRIX & 設定するワールドマトリクス変換行列の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_Component::M_Draw_Start_World_Matrix_Set(const DirectX::XMMATRIX & in_world_matrix)
{
	// ワールドマトリクス変換行列を生成
	mpr_variable.transform.M_Generate_Matrix(mpr_variable.world_matrix);
	mpr_variable.world_matrix *= in_world_matrix;

	// モデルのマテリアルにWVP行列をセット
	mpr_variable.model_system.M_Get_3D_Model_Address()->M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(mpr_variable.world_matrix);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：モデルの描画を行う
// 引数   ：int 描画する時の描画設定の番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_Component::M_Model_Draw(int in_draw_command_number)
{
	//--☆ 描画オプションで分岐して描画を行なう -☆-//
	switch (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option)
	{
		// 通常描画
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW:
		
		mpr_variable.model_system.M_Draw_3D_Model();
		break;

		// マテリアルを指定して描画する
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL:
		{
			// ☆ 変数宣言 ☆ //
			ASSET::MATERIAL::C_Material * use_material = nullptr;	// 使用するマテリアルのアドレス


			// 使用するマテリアルを取得し、WVPをセット
			use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
			use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
			use_material->M_Set_View_Projection_By_Main_Camera();
			mpr_variable.model_system.M_Draw_3D_Model_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data);
		}
		break;

		// メッシュを指定して描画する
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH:

		for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
		{
			mpr_variable.model_system.M_Draw_3D_Model_Meshes_By_Mesh_Name(now_mesh_name);
		}
		break;

		// メッシュとマテリアルを指定して描画する
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL:
		{
			// ☆ 変数宣言 ☆ //
			ASSET::MATERIAL::C_Material * use_material = nullptr;	// 使用するマテリアルのアドレス


			// 使用するマテリアルを取得し、WVPをセット
			use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
			use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
			use_material->M_Set_View_Projection_By_Main_Camera();

			// メッシュを指定して描画する
			for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
			{
				mpr_variable.model_system.M_Draw_3D_Model_Meshes_By_Name_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data, now_mesh_name);
			}
		}
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンポーネント用の描画処理だが使用しない（モデル描画前にマテリアルの設定などを行なったり、）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_Component::M_Draw(void)
{
	return;
}
