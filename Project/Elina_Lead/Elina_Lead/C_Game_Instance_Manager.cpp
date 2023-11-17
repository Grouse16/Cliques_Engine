//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲーム上のインスタンスを制御するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Game_Instance_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆// 
C_Game_Instance_Manager::C_Game_Instance_Manager(void)
{
	return;
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲーム上の全てのインスタンスのなかから、削除のフラグが立っているものを消す
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆// 
void C_Game_Instance_Manager::M_All_Instance_Destroy_Update(void)
{
	// ☆ 変数宣言 ☆ //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// アクター管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UI管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & sound_list_system_list =	// サウンド管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// ポストエフェクト管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// 削除フラグの立っているアクターの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// 削除フラグの立っているUIの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// 削除フラグの立っているサウンドの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	// 削除フラグの立っているポストエフェクトの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：全てのインスタンスを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Instance_Manager::M_Delete_All_Instance(void)
{
	// ☆ 変数宣言 ☆ //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & actor_list_system_list =	// アクター管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & ui_list_system_list =	// UI管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & sound_list_system_list =	// サウンド管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & post_effect_list_system_list =	// ポストエフェクト管理用リストのリスト
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// アクターの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// UIの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// サウンドの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	// ポストエフェクトの削除
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	return;
}



