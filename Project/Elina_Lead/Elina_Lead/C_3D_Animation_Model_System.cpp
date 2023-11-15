//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_3D_Animation_Model_System.h"

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
C_3D_Animation_Model_System::C_3D_Animation_Model_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_3D_Animation_Model_System::~C_3D_Animation_Model_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_System::M_Release(void)
{
	for (S_Animative_Mesh_Data_Inform & mesh_data : mpr_variable.mesh_inform_list)
	{
		mesh_data.mesh_data.reset();
	}
	mpr_variable.mesh_inform_list.clear();
	mpr_variable.mesh_inform_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスの3Dアニメーションモデルをロードする
// 引数   ：string 3Dアニメーションモデルまでのパス
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_3D_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// ファイルのデータを読み取るシステム


	// 指定されたファイルをロード　ロードに失敗時はエラーを出して抜ける
	if (file_data.M_Load_Select_File(in_3d_animation_model_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "ファイルの取得に失敗しました：" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}

	// 認証名を探索する
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "このファイルは.elanmmdl形式ではありません：" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}


	// 現在持っているアニメーションモデルデータは削除する
	M_Release();


	// メッシュデータ数を取得
	file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:");
	mpr_variable.mesh_inform_list.resize(file_data.M_Get_Number());


	// ボーン数を取得しその数分ボーンを生成
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_list.resize(file_data.M_Get_Number());


	// ボーンデータ分読み取る
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & bone_inform : mpr_variable.bone_list)
	{
		// 現在のボーンのデータまで移動
		file_data.M_Move_Next_Raw();

		// ボーン名を取得
		bone_inform.bone_name = file_data.M_Get_Data_By_Text("/");

		// オフセットマトリクスA１をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._11 = file_data.M_Get_Number();

		// オフセットマトリクスA２をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._12 = file_data.M_Get_Number();

		// オフセットマトリクスA３をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._13 = file_data.M_Get_Number();
		
		// オフセットマトリクスA４をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._14 = file_data.M_Get_Number();

		// オフセットマトリクスB１をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._21 = file_data.M_Get_Number();

		// オフセットマトリクスB２をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._22 = file_data.M_Get_Number();

		// オフセットマトリクスB３をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._23 = file_data.M_Get_Number();

		// オフセットマトリクスB４をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._24 = file_data.M_Get_Number();

		// オフセットマトリクスC１をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._31 = file_data.M_Get_Number();

		// オフセットマトリクスC２をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._32 = file_data.M_Get_Number();

		// オフセットマトリクスC３をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._33 = file_data.M_Get_Number();

		// オフセットマトリクスC４をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._34 = file_data.M_Get_Number();

		// オフセットマトリクスD１をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._41 = file_data.M_Get_Number();

		// オフセットマトリクスD２をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._42 = file_data.M_Get_Number();

		// オフセットマトリクスD３をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._43 = file_data.M_Get_Number();

		// オフセットマトリクスD４をロード
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._44 = file_data.M_Get_Number();
	}


	// メッシュデータ分読み取る
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// メッシュの位置へ移動
		file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");

		// メッシュ名を取得
		file_data.M_Move_Next_Raw();
		now_mesh_inform.name = file_data.M_Get_Data_Now_Row();

		// メッシュデータを生成
		now_mesh_inform.mesh_data.reset(new ASSET::ANIMATION::MESH::C_Animative_Mesh());

		// メッシュのマテリアルをロード　ロード失敗でエラーを出して抜ける
		file_data.M_Move_Raw_By_Number(2);
		file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.mesh_data->M_Load_Material_By_Name(file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "マテリアルのロードに失敗しました。アニメーション用モデル：" + in_3d_animation_model_path);
#endif // _DEBUG

			return false;
		}

		// 頂点数を取得し、頂点データを生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("VERT:");
		now_mesh_inform.mesh_data->M_Creat_Vertex_List(file_data.M_Get_Number());

		// 頂点データをロード
		for (DATA::VERTEX::S_3D_Animation_Model_Vertex & now_vertex_data : now_mesh_inform.mesh_data->M_Get_Vertex_Data_List())
		{
			// 現在の頂点データまで移動
			file_data.M_Move_Next_Raw();

			// 頂点座標のロード
			now_vertex_data.vertex.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.z = file_data.M_Get_Float_Double_Number();

			// UV座標のロード
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.uv.u = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.uv.v = file_data.M_Get_Float_Double_Number();

			// 色のロード
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.color.r = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.g = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.b = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.a = file_data.M_Get_Float_Double_Number();

			// 法線ベクトルのロード
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.normal.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.z = file_data.M_Get_Float_Double_Number();

			// タンジェントベクトルのロード
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.z = file_data.M_Get_Float_Double_Number();

			// バイノーマルタンジェントベクトル（従法線ベクトル）のロード
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.binormal_tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.z = file_data.M_Get_Float_Double_Number();

			// ボーンウェイト（ボーン影響値）情報の位置へ移動
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");

			// ボーンウェイト情報の終了の記号がくるか、４回繰り返すまで、ボーンウェイト情報をロードし続ける
			for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
			{
				now_vertex_data.bone_weight[loop_cnt].bone_index = file_data.M_Get_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column("/");
				now_vertex_data.bone_weight[loop_cnt].weight = file_data.M_Get_Float_Double_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			}
		}

		// 頂点インデックス数を取得して、頂点インデックスデータを生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.mesh_data->M_Creat_Index_List(file_data.M_Get_Number());

		// 頂点インデックスデータをロード
		for (unsigned __int32 & now_index_data : now_mesh_inform.mesh_data->M_Get_Index_Data_List())
		{
			file_data.M_Move_Next_Raw();
			now_index_data = file_data.M_Get_Number();
		}

		// 頂点と頂点インデックス情報分のバッファを生成し、データをバッファにセット、その後データは使用しないので削除（バッファは残る）
		now_mesh_inform.mesh_data->M_Creat_Vertex_Buffer_And_Index_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Vertex_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Delete_Vertex_Data();
		now_mesh_inform.mesh_data->M_Delete_Index_Data();
	}


	// マテリアルの定数バッファを探索し、特殊な名前のスロットを取得する
	for (S_Animative_Mesh_Data_Inform & now_mesh : mpr_variable.mesh_inform_list)
	{
		// ☆ 変数宣言 ☆ //
		ASSET::MATERIAL::C_Material * now_material = now_mesh.mesh_data->M_Get_Material_User().M_Get_Material_Address();	// マテリアルのアドレス


		// トランスフォーム　あれば定数バッファを確保する
		now_mesh.unique_buffer_number.transform = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_TRANSFORM");

		// アンビエントライト
		now_mesh.unique_buffer_number.ambient_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_AMBIENT_LIGHT");

		// ディレクショナルライト
		now_mesh.unique_buffer_number.directional_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_DIRECTIONAL_LIGHT");

		// ポイントライト
		now_mesh.unique_buffer_number.point_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// スポットライト
		now_mesh.unique_buffer_number.spot_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// エリアライト
		now_mesh.unique_buffer_number.area_light = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_POINT_LIGHT");

		// ボーン
		now_mesh.unique_buffer_number.bone = now_material->M_Get_Constant_Buffer_Number_By_Name("CB_BONE");

		// メインとなるテクスチャ
		now_mesh.unique_buffer_number.main_texture = now_material->M_Get_Texture_Number_By_Name("CT_MAIN_TEXTURE");
	}


	// ロードに成功、デバッグ時は成功ログを表示
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "アニメーション用モデルのロードに成功しました：" + in_3d_animation_model_path);
#endif // _DEBUG

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータをロードする
// 引数   ：string ロードするアニメーションデータ名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_3D_Animation_Model_System::M_Load_Animation_Data_By_Path(std::string in_animation_data_name)
{
	// すでにロードされているなら何もしない
	for (S_Animation_Data_Inform & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.name == in_animation_data_name)
		{
			return;
		}
	}


	// ☆ 変数宣言 ☆ //
	std::string load_path = "project/asset/animation/" + in_animation_data_name + ".elanmdt";	// アニメーションデータまでのパス

	int new_animation_data = mpr_variable.animation_data_list.size();	// 新しいアニメーションデータの配列番号


	// アニメーションデータをロードする　失敗でfalseを返して抜ける
	mpr_variable.animation_data_list.resize(new_animation_data + 1);
	mpr_variable.animation_data_list[new_animation_data].animation_data.reset(new ASSET::ANIMATION_SYSTEM::C_Animation_Data_System());
	if (mpr_variable.animation_data_list[new_animation_data].animation_data->M_Load_Anmation_Data_By_Path(load_path, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// アニメーションデータ名を設定
	mpr_variable.animation_data_list[new_animation_data].name = in_animation_data_name;

	// ロードに成功
	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のメッシュを返す
// 引数   ：string 探すメッシュの名前
// 戻り値 ：C_Animative_Mesh * 名前が一致したメッシュのアドレス、一致しなかったらnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION::MESH::C_Animative_Mesh * C_3D_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// 一致するメッシュ名を探し、あればそのアドレスを返す
	for (S_Animative_Mesh_Data_Inform & now_mesh_data : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_data.name == in_mesh_name)
		{
			return now_mesh_data.mesh_data.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッシュ情報のリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> & メッシュ情報のリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> &  C_3D_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_inform_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータを返す
// 引数   ：string 探すアニメーションデータの名前
// 戻り値 ：const C_Animation_Data_System * 名前が一致したアニメーションデータのアドレス、一致しなかったらnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_3D_Animation_Model_System::M_Get_Animation_Data_By_Name(std::string in_animation_data)
{
	// 一致するアニメーションデータ名を探し、あればそのアドレスを返す
	for (S_Animation_Data_Inform & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.name == in_animation_data)
		{
			return now_animation_data.animation_data.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションデータの情報のリストの参照を返す
// 引数   ：void
// 戻り値 ：const vector<C_3D_Animation_Model_System::S_Animation_Data_Inform> & アニメーションデータの情報のリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<C_3D_Animation_Model_System::S_Animation_Data_Inform> & C_3D_Animation_Model_System::M_Get_Animation_Inform_List(void)
{
	return mpr_variable.animation_data_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ボーン情報のリストを返す
// 引数   ：void
// 戻り値 ：const vector<S_Bone_Inform> ボーン情報のリストを返す(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & C_3D_Animation_Model_System::M_Get_Bone_Inform_List(void)
{
	return mpr_variable.bone_list;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ボーンのマトリクスをマテリアルにセットする
// 引数   ：const std::vector<DirectX::XMFLOAT4X4> & セットするボーンマトリクス配列の参照(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_System::M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	// ☆ 変数宣言 ☆ //
	int bone_sum = mpr_variable.bone_list.size();	// ボーン数


	// セットするボーンマトリクス配列が現在のボーン情報と一致しないなら処理をしない
	if (bone_sum != in_bone_matrix_list.size())
	{
		return;
	}

	// 全てのメッシュにボーンをセットする
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// ☆ 変数宣言 ☆ //
		ASSET::MATERIAL::S_Constant_Buffer_Data * now_bone_constant_buffer =	// 現在のボーンの定数バッファ
			now_mesh_inform.mesh_data->M_Get_Material_User().M_Get_Material_Address()->M_Get_Constant_Buffer_Data_By_Index(now_mesh_inform.unique_buffer_number.bone);

		// 定数バッファの中身があるときのみ、ボーンの情報をセットする
		if (now_bone_constant_buffer)
		{
			now_bone_constant_buffer->data->M_Set_Constant_Buffer_Data<DirectX::XMFLOAT4X4>(bone_sum, 0, &in_bone_matrix_list[0]);
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_System::M_Draw_3D_Model(void)
{
	// 全てのメッシュを描画
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		now_mesh_inform.mesh_data->M_Draw_Mesh();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルから指定されたメッシュ名のみ描画する
// 引数   ：string 描画するメッシュ名（複数判定する）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// 全てのメッシュから描画するメッシュ名と同じメッシュのみ描画
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->M_Draw_Mesh();
		}
	}

	return;
}

