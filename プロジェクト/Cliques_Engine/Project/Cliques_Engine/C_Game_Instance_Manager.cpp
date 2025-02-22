////
// Ú×   FQ[ãÌCX^Xð§ä·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Instance_Manager.h"
#include "C_Actor_Draw_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE;


//  Ö  //

//== pubN ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============// 
C_Game_Instance_Manager::C_Game_Instance_Manager(void)
{
	return;
}


//-- í --//

//===============//
// Ú×   FQ[ãÌSÄÌCX^XÌÈ©©çAíÌtOª§ÁÄ¢éàÌðÁ·
// ø   Fvoid
// ßèl FÈµ
//===============// 
void C_Game_Instance_Manager::M_All_Instance_Destroy_Update(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// AN^[ÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UIÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// |XgGtFNgÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & sound_list_system_list =	// TEhÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();


	// ítOÌ§ÁÄ¢éAN^[Ìí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// ítOÌ§ÁÄ¢éUIÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// ítOÌ§ÁÄ¢é|XgGtFNgÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	// ítOÌ§ÁÄ¢éTEhÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	return;
}


//===============//
// Ú×   FCX^XÌV[JÚÌíðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Instance_Destroy_On_Scene_Change(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// AN^[ÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UIÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// |XgGtFNgÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & sound_list_system_list =	// TEhÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();


	// V[JÚÉæéAN^[í
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Most_OF_Instance_Execute();
	}

	// V[JÚÉæéUIí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Most_OF_Instance_Execute();
	}

	// V[JÚÉæé|XgGtFNgí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Most_OF_Instance_Execute();
	}

	// V[JÚÉæéTEhí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Most_OF_Instance_Execute();
	}

	return;
}


//===============//
// Ú×   FSÄÌCX^Xðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Delete_All_Instance(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// AN^[ÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UIÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// |XgGtFNgÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* >& sound_list_system_list =	// TEhÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();
	

	// AN^[Ìí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// UIÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// |XgGtFNgÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	// TEhÌí
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	return;
}


//-- XV --//

//===============//
// Ú×   FSÄÌAN^[ðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Update_Actor(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// AN^[ÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();


	// AN^[ÌXV
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Instance_Update();
	}

	return;
}


//===============//
// Ú×   FSÄÌUIðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Update_UI(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* >& ui_list_system_list =	// UIÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	
	// UIÌXV
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* ui_list : ui_list_system_list)
	{
		ui_list->M_Instance_Update();
	}

	return;
}


//===============//
// Ú×   FSÄÌ|XgGtFNgðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Update_Post_Effect(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* >& post_effect_list_system_list =	// |XgGtFNgÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// |XgGtFNgÌXV
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Instance_Draw();
	}

	return;
}


//===============//
// Ú×   FSÄÌTEhðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Update_Sound(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & sound_list_system_list =	// TEhÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();


	// TEhÌXV
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * sound_list : sound_list_system_list)
	{
		sound_list->M_Instance_Update();
	}

	return;
}


//===============//
// Ú×   FSÄÌQ[VXeÌXVð·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Update_Game_System(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & system_list_system_list =	// VXeÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::GAME_SYSTEM::LIST::C_Game_System_List>::M_Get_List_Of_All_Instance_List();


	// VXeÌXV
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * system_list : system_list_system_list)
	{
		system_list->M_Instance_Update();
	}

	return;
}


//-- `æ --//

//===============//
// Ú×   FSÄÌAN^[ð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Draw_Actor(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// AN^[ÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();


	// AN^[Ì`æXgÖÌo^
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Instance_Draw();
	}


	// Êí`æðÀs
	GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Draw_Actor_In_Draw_List();

	// Êí`æãÌ`æðÀs
	GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Draw_Actor_In_After_Draw_List();

	return;
}


//===============//
// Ú×   F|XgGtFNgð`æpXgÉÇÁ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Set_Post_Effect_To_Draw_List(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// |XgGtFNgÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// |XgGtFNgÌ`æXgÖÌo^
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Instance_Draw();
	}

	return;
}


//===============//
// Ú×   FUIÌOÉ|XgGtFNgð©¯é`æð·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Draw_Post_Effect_Before_UI(void)
{
	GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_Before_UI();

	return;
}


//===============//
// Ú×   FSÄÌUIð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Draw_UI(void)
{
	//  Ïé¾  //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UIÇpXgÌXg
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();


	// UIÌ`æ
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Instance_Draw();
	}

	return;
}


//===============//
// Ú×   FUIÌãÉ|XgGtFNgð©¯é`æð·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Manager::M_Draw_Post_Effect_After_UI(void)
{
	GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_After_UI();

	return;
}



