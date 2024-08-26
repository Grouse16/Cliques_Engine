//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルのクラス
// 説明   ：3Dモデルの取得から描画、アニメーションの実行までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Static_Model_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Main_Camera.h"
#include "C_Static_Model_Loader.h"

#include "C_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MODEL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_System::C_Static_Model_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_System::~C_Static_Model_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_System::M_Release(void)
{
	for (ASSET::MESH::C_Mesh_Data & mesh_data : mpr_variable.mesh_list)
	{
		mesh_data.M_Release();
	}
	mpr_variable.mesh_list.clear();
	mpr_variable.mesh_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスの3Dモデルをロードする
// 引数   ：string 3Dモデルまでのパス
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_System::M_Load_3D_Model_By_Path(std::string in_3d_model_path)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// ファイルのデータを読み取るシステム


	// 現在持っているモデルデータは削除する
	M_Release();


	// モデルのデータをロードする、失敗したらエラーで抜ける
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_File_Data(in_3d_model_path, file_data) == false)
	{
		return false;
	}

	// 頂点のデータをロードする、失敗したらエラーで抜ける
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Vertex(file_data, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// メッシュのデータをロードする、失敗したらエラーで抜ける
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Mesh(file_data, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// モデルのロードの成功を告知
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log
	(
		DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"モデルのロードに成功しました：" + in_3d_model_path
	);

	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のメッシュを返す
// 引数   ：string 探すメッシュの名前
// 戻り値 ：C_Mesh_Data * 名前が一致したメッシュのアドレス、一致しなかったらnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MESH::C_Mesh_Data * C_Static_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// 一致するメッシュ名を探し、あればそのアドレスを返す
	for (ASSET::MESH::C_Mesh_Data & now_mesh_data : mpr_variable.mesh_list)
	{
		if (now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
		{
			return &now_mesh_data;
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
std::vector<ASSET::MESH::C_Mesh_Data> & C_Static_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_System::M_Draw_Model(void)
{
	// 頂点シェーダーをセット
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
void C_Static_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// 頂点シェーダーをセット
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
void C_Static_Model_System::M_Draw_Model_Do_Not_Use_Material(void)
{
	// 頂点シェーダーをセット
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
void C_Static_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// 頂点シェーダーをセット
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
// 詳細   ：ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする、トランスフォームを受け取る
// 引数   ：const C_Transform & トランスフォームの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
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
// 引数   ：const C_Transform & ワールドマトリクスの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
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
