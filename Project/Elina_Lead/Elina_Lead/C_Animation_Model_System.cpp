//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Model_System.h"
#include "C_Main_Camera.h"
#include "C_Animation_Model_Loader.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION_MODEL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Model_System::C_Animation_Model_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Model_System::~C_Animation_Model_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Release(void)
{
	mpr_variable.mesh_list.clear();
	mpr_variable.mesh_list.shrink_to_fit();

	mpr_variable.bone_list.clear();
	mpr_variable.bone_list.shrink_to_fit();

	mpr_variable.vertex_system.M_Release();

	mpr_variable.animation_data_list.clear();
	mpr_variable.animation_data_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスの3Dアニメーションモデルをロードする
// 引数   ：string 3Dアニメーションモデルまでのパス
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager load_file;	// ファイルをロードするためのクラス


	// 現在持っているアニメーションモデルデータは削除する
	M_Release();


	// アニメーションモデルをロードする、失敗したらエラーで抜ける
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_File(in_3d_animation_model_path, load_file) == false)
	{
		return false;
	}

	// 頂点データをロードする、失敗したらエラーで抜ける
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(load_file, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// ボーンデータをロードする、失敗したらエラーで抜ける
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Bone(load_file, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// メッシュデータをロードする、失敗したらエラーで抜ける
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(load_file, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// ロードに成功、デバッグ時は成功ログを表示
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log
	(
		DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"アニメーション用モデルのロードに成功しました：" + in_3d_animation_model_path
	);
#endif // _DEBUG

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータをロードする
// 引数   ：string ロードするアニメーションデータ名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_System::M_Load_Animation_Data_By_Name(std::string in_animation_data_name)
{
	// すでにロードされているなら何もしない
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data_name)
		{
			return true;
		}
	}


	// ☆ 変数宣言 ☆ //
	std::string load_path = "project/asset/animation/" + in_animation_data_name + ".elanmdt";	// アニメーションデータまでのパス

	int new_animation_data_number = (int)mpr_variable.animation_data_list.size();	// 新しいアニメーションデータの配列番号


	// アニメーションデータをロードする　失敗でfalseを返して抜ける
	mpr_variable.animation_data_list.resize(new_animation_data_number + 1);
	if (mpr_variable.animation_data_list[new_animation_data_number].M_Load_Animation_Data_By_Path(load_path, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// アニメーションデータ名を設定
	mpr_variable.animation_data_list[new_animation_data_number].M_Set_Name(in_animation_data_name);

	// ロードに成功
	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のメッシュを返す
// 引数   ：string 探すメッシュの名前
// 戻り値 ：C_Mesh_Data * 名前が一致したメッシュのアドレス、一致しなかったらnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MESH::C_Mesh_Data * C_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// 一致するメッシュ名を探し、あればそのアドレスを返す
	for (ASSET::MESH::C_Mesh_Data & l_now_mesh_data : mpr_variable.mesh_list)
	{
		if (l_now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
		{
			return &l_now_mesh_data;
		}
	}

	// 見つからなかった
	return nullptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッシュ情報のリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<C_Mesh_Data> & メッシュ情報のリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<ASSET::MESH::C_Mesh_Data> &  C_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータを返す
// 引数   ：string 探すアニメーションデータの名前
// 戻り値 ：const C_Animation_Data_System * 名前が一致したアニメーションデータのアドレス、一致しなかったらnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Model_System::M_Get_Animation_Data_By_Name(std::string in_animation_data)
{
	// 一致するアニメーションデータ名を探し、あればそのアドレスを返す
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data)
		{
			return &now_animation_data;
		}
	}

	// 見つからなかった
	return nullptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションシステムのリストの参照を返す
// 引数   ：void
// 戻り値 ：const vector<C_Animation_Data_System> & アニメーションシステムのリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & C_Animation_Model_System::M_Get_Animation_Inform_List(void)
{
	return mpr_variable.animation_data_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のボーンを返す
// 引数   ：void
// 戻り値 ：string ボーン名
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const ASSET::ANIMATION::BONE::S_Bone_Inform * C_Animation_Model_System::M_Get_Bone_Inform_By_Name(std::string in_bone_name)
{
	// 一致するボーン名を探し、あればそのアドレスを返す
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & now_bone_inform : mpr_variable.bone_list)
	{
		if (now_bone_inform.bone_name == in_bone_name)
		{
			return &now_bone_inform;
		}
	}

	// 見つからなかった
	return nullptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ボーン情報のリストを返す
// 引数   ：void
// 戻り値 ：const vector<S_Bone_Inform> ボーン情報のリストを返す(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & C_Animation_Model_System::M_Get_Bone_Inform_List(void)
{
	return mpr_variable.bone_list;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Draw_3D_Model(void)
{
	// 頂点をセット
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// 全てのメッシュを描画
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルから指定されたメッシュ名のみ描画する
// 引数   ：string 描画するメッシュ名（複数判定する）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// 頂点をセット
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// 全てのメッシュから描画するメッシュ名と同じメッシュのみ描画
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh();
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルを設定せずに、3Dモデルを描画する（描画前にマテリアルをセットするとき用）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Draw_3D_Model_Do_Not_Use_Material(void)
{
	// 頂点をセット
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// 全てのメッシュを描画
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルを設定せずに、3Dモデルから指定されたメッシュ名のみ描画する（描画前にマテリアルをセットするとき用）
// 引数   ：string 描画するメッシュ名（複数判定する）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// 頂点をセット
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// 全てのメッシュから描画するメッシュ名と同じメッシュのみ描画
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
		}
	}

	return;
}


//-☆- 定数バッファ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ボーンのマトリクスをマテリアルにセットする
// 引数   ：const vector<XMFLOAT4X4> & セットするボーンマトリクス配列の参照(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	// ☆ 変数宣言 ☆ //
	int bone_sum = (int)mpr_variable.bone_list.size();	// ボーン数


	// セットするボーンマトリクス配列が現在のボーン情報と一致しないなら処理をしない
	if (bone_sum != in_bone_matrix_list.size())
	{
		return;
	}

	// 全てのメッシュにボーンをセットする
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Get_Material_User().M_Get_Material_Address()->M_Set_Bone_Matrix(in_bone_matrix_list);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする
// 引数   ：const C_Transform & トランスフォームの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
{
	// ☆ 変数宣言 ☆ //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// ワールド ビュー プロジェクションのマトリクス上方


	// ワールドマトリクスを生成
	in_transform.M_Generate_Matrix(in_set_wvp.world);

	// ビューマトリクスをセット
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// プロジェクションマトリクスをセット
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// 全てのメッシュのマテリアルにトランスフォームをセット
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする、ワールドマトリクスを受け取る
// 引数   ：const XMMATRIX & ワールドマトリクスの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
{
	// ☆ 変数宣言 ☆ //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// ワールド ビュー プロジェクションのマトリクス上方


	// ワールドマトリクスを生成
	in_set_wvp.world = in_world_matrix;

	// ビューマトリクスをセット
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// プロジェクションマトリクスをセット
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// 全てのメッシュのマテリアルにトランスフォームをセット
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


















































//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
