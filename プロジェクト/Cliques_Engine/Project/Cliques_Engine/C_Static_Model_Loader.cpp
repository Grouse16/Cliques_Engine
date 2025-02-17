//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：静的モデルをロードするクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Static_Model_Loader.h"

#include "C_Console_Log_Interface.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MODEL::STATIC_MODEL::LOADER;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルをロードし、静的モデルであるかどうかを判定する
// 引数   ：string ファイル名, C_Text_And_File_Manager & ロードしたファイルデータの記録先
// 戻り値 ：bool ロードに成功、かつ静的モデルであればtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_Loader::M_Load_Static_Model_File_Data(std::string in_load_file_name, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data_system)
{
	// ファイルをセット
	in_file_data_system.M_Set_File_Path(in_load_file_name);


	// 指定されたファイルをロード　ロードに失敗時はエラーを出して抜ける
	if (in_file_data_system.M_Load_Now_File() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"ファイルの取得に失敗しました：" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ファイルが静的モデルであるかどうかを判定、静的モデルでなければエラーを出して抜ける
	if (in_file_data_system.M_Check_Text_Is_Equal_Now_Position("This-Is-ELSTTMDL") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"このファイルは.elsttmdl形式ではありません：" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ロードに成功したらtrueを返す
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：静的モデルの頂点データをロードする
// 引数   ：C_Text_And_File_Manager & モデルファイルのデータ, C_Object_Vertex_System<S_3D_Model_Vertex> & ロード先の頂点データの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_Loader::M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & in_vertex_system)
{
	// ☆ 変数宣言 ☆ //
	std::vector<DATA::VERTEX::S_3D_Model_Vertex> vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// 現在の頂点データ


	// 頂点数へ移動、なければエラーを出して抜ける
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"ファイルの取得に失敗しました：" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// 頂点数を取得し、頂点データを作成
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_file_data.M_Get_Number());


	// 頂点データをロード
	for (DATA::VERTEX::S_3D_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// 現在の頂点データまで移動
		in_file_data.M_Move_Next_Raw();

		// 頂点座標のロード
		l_now_vertex_data.vertex.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_file_data.M_Get_Float_Double_Number();

		// UV座標のロード
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_file_data.M_Get_Float_Double_Number();

		// 色のロード
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_file_data.M_Get_Float_Double_Number();

		// 法線ベクトルのロード
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_file_data.M_Get_Float_Double_Number();

		// タンジェントベクトルのロード
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_file_data.M_Get_Float_Double_Number();

		// バイノーマルタンジェントベクトル（従法線ベクトル）のロード
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_file_data.M_Get_Float_Double_Number();
	}


	// 頂点データをバッファにセットして頂点データを削除、頂点バッファのみ残す
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// ロードに成功したらtrueを返す
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：静的モデルのメッシュデータをロードする
// 引数   ：C_Text_And_File_Manager & モデルファイルのデータ, C_Object_Vertex_System<S_3D_Model_Vertex> & ロード先の頂点データの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_Loader::M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, std::vector<ASSET::MESH::C_Mesh_Data> & in_mesh_list)
{
	// メッシュデータ数へ移動、なければエラーを出して抜ける
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"ファイルの取得に失敗しました：" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// メッシュデータ数を取得し、メッシュデータを作成
	in_mesh_list.resize(in_file_data.M_Get_Number());


	// メッシュデータ分読み取る
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : in_mesh_list)
	{
		// メッシュの位置へ移動
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// メッシュ名を取得
		in_file_data.M_Move_Next_Raw();
		now_mesh_inform.M_Set_Mesh_Name(in_file_data.M_Get_Data_Now_Row());


		// メッシュのマテリアルをロード　ロード失敗でエラーを出して抜ける
		in_file_data.M_Move_Raw_By_Number(2);
		in_file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.M_Load_Material_By_Name(in_file_data.M_Get_Data_Now_Row()) == false)
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
			(
				DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"マテリアルのロードに失敗しました。モデル：" + in_file_data.M_Get_File_Path_Refer() + "　マテリアル：" + in_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}


		// 頂点インデックス数を取得して、頂点インデックスデータを生成
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.M_Create_Index_List((int)in_file_data.M_Get_Number());

		// 頂点インデックスデータをロード
		for (unsigned __int32 & now_index_data : now_mesh_inform.M_Get_Index_Data_List())
		{
			in_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_file_data.M_Get_Number();
		}

		// 頂点と頂点インデックス情報分のバッファを生成し、データをバッファにセット、その後データは使用しないので削除（バッファは残る）
		now_mesh_inform.M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.M_Delete_Index_Data();
	}

	// ロードに成功したらtrueを返す
	return true;
}


