//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのロードをするシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Model_Loader.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION_MODEL::LOADER;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスのファイルをロードし、アニメーションモデルのデータであるかどうかを判定する
// 引数   ：string ファイルのパス, C_Text_And_File_Manager & ロードした文字データの取得先の参照
// 戻り値 ：bool ロードに成功、かつアニメーションモデルのデータである場合のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_Loader::M_Load_Animation_Model_File(std::string in_file_path, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	// ファイルをセット
	in_file_text.M_Set_File_Path(in_file_path);


	// 指定されたファイルをロード　ロードに失敗時はエラーを出して抜ける
	if (in_file_text.M_Load_Now_File() == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "ファイルの取得に失敗しました：" + in_file_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// 認証名を探索する
	if (in_file_text.M_Check_Text_Is_Eqaul_Now_Position("This-Is-ELANMMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "このファイルは.elanmmdl形式ではありません：" + in_file_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// ファイルのロードに成功したのでtrue
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデルの頂点データを読み込まれたデータを元にロードする
// 引数   ：C_Text_And_File_Manager & ロードしたモデルのファイルデータの参照, C_Object_Vertex_System<S_3D_Animation_Model_Vertex> & 設定先の頂点データの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex>& in_vertex_system)
{
	// ☆ 変数宣言 ☆ //
	std::vector<DATA::VERTEX::S_3D_Animation_Model_Vertex> & vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// 頂点データのリストの参照


	// 頂点数の位置へ移動、なければエラーを返して終了
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"頂点数を検出できませんでした：" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// 頂点数を取得し、頂点数分メモリを確保し頂点バッファを生成
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_model_file_data.M_Get_Number());

	// 頂点データをロード
	for (DATA::VERTEX::S_3D_Animation_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// 現在の頂点データまで移動
		in_model_file_data.M_Move_Next_Raw();

		// 頂点座標のロード
		l_now_vertex_data.vertex.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// UV座標のロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_model_file_data.M_Get_Float_Double_Number();

		// 色のロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_model_file_data.M_Get_Float_Double_Number();

		// 法線ベクトルのロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// タンジェントベクトルのロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// バイノーマルタンジェントベクトル（従法線ベクトル）のロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ボーンウェイト（ボーン影響値）情報の位置へ移動
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");

		// ボーンウェイト情報の終了の記号がくるか、４回繰り返すまで、ボーンウェイト情報をロードし続ける
		for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || in_model_file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
		{
			l_now_vertex_data.bone_weight[loop_cnt].bone_index = (int)in_model_file_data.M_Get_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column("/");
			l_now_vertex_data.bone_weight[loop_cnt].weight = (float)in_model_file_data.M_Get_Float_Double_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		}
	}

	// 頂点バッファにデータを設定し頂点データのみ削除、頂点バッファは残る
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// 成功したのでtrue
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデルのボーンデータを読み込まれたデータを元にロードする
// 引数   ：C_Text_And_File_Manager & ロードしたモデルのファイルデータの参照, vector<S_Bone_Inform> &  設定先のボーンデータの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_system)
{
	// ボーン数の位置へ移動、なければエラーを返して終了
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"ボーン数を検出できませんでした：" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	
	// ボーン数を取得し、ボーン数分メモリを確保
	in_bone_system.resize((int)in_model_file_data.M_Get_Number());

	// ボーンデータをロード
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & l_now_bone_inform : in_bone_system)
	{
		// 現在のボーンのデータまで移動
		in_model_file_data.M_Move_Next_Raw();


		// ボーン名を取得
		l_now_bone_inform.bone_name = in_model_file_data.M_Get_Data_By_Text("/");


		// 親ボーンのインデックスを取得
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.parent_bone_index = (int)in_model_file_data.M_Get_Number();


		// 子ボーンのインデックスを取得
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		while (in_model_file_data.M_Get_Data_By_Number(1) != "/")
		{
			l_now_bone_inform.children_bone_index_list.reserve(l_now_bone_inform.children_bone_index_list.size());
			l_now_bone_inform.children_bone_index_list.emplace_back((int)in_model_file_data.M_Get_Number());
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(",");
		}


		// オフセットマトリクスA１をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.offset_matrix._11 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスA２をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._12 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスA３をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._13 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスA４をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._14 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスB１をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._21 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスB２をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._22 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスB３をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._23 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスB４をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._24 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスC１をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._31 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスC２をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._32 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスC３をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._33 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスC４をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._34 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスD１をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._41 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスD２をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._42 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスD３をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._43 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// オフセットマトリクスD４をロード
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._44 = (float)in_model_file_data.M_Get_Float_Double_Number();
	}

	// 成功したのでtrue
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデルのメッシュを読み込まれたデータを元にロードする
// 引数   ：C_Text_And_File_Manager & ロードしたモデルのファイルデータの参照, vector<C_Animative_Mesh> &  設定先のボーンデータの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::ANIMATION::MESH::C_Animative_Mesh> & in_mesh_system)
{
	// メッシュ数の位置へ移動、なければエラーを返して終了
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"メッシュ数を検出できませんでした：" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}


	// メッシュ数を取得し、メッシュ数分メモリを確保
	in_mesh_system.resize((int)in_model_file_data.M_Get_Number());


	// メッシュデータをロード
	for (ASSET::ANIMATION::MESH::C_Animative_Mesh & l_now_mesh : in_mesh_system)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<unsigned int> & index_list = l_now_mesh.M_Get_Index_Data_List();	// メッシュが使用する頂点インデックスのリストの参照


		// 今のメッシュ情報の開始位置へ移動
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// メッシュ名を取得
		in_model_file_data.M_Move_Next_Raw();
		l_now_mesh.M_Set_Name(in_model_file_data.M_Get_Data_Now_Row());


		// メッシュのマテリアルをロード　ロード失敗でエラーを出して抜ける
		in_model_file_data.M_Move_Raw_By_Number(2);
		in_model_file_data.M_Goto_Column_By_Set_Number(0);
		if (l_now_mesh.M_Load_Material_By_Name(in_model_file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"マテリアルのロードに失敗しました。アニメーション用モデル：" + in_model_file_data.M_Get_File_Path_Refer() + "　マテリアル：" + in_model_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}


		// 頂点インデックス数を取得して、頂点インデックスデータを生成
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		l_now_mesh.M_Create_Index_List((int)in_model_file_data.M_Get_Number());

		// 頂点インデックスデータをロード
		for (unsigned __int32 & now_index_data : index_list)
		{
			in_model_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_model_file_data.M_Get_Number();
		}

		// 頂点インデックス情報分のバッファを生成し、データをバッファにセット、その後データは使用しないので削除（バッファは残る）
		l_now_mesh.M_Attach_Index_Data_To_Buffer();
		l_now_mesh.M_Delete_Index_Data();
	}

	// 成功したのでtrue
	return true;
}

