////
// Ú×   FV[ð§ä·é½ßÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Scene_Manager.h"
#include "C_Scene_Title.h"
#include "C_Scene_Game.h"
#include "C_Game_State_Manager.h"
#include "C_Game_Instance_Manager.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace GAME::SCENE::MANAGER;


//  X^eBbNÏ  //
C_Scene_Manager C_Scene_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- I¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Scene_Manager::C_Scene_Manager(void)
{
	return;
}


//-- V[JÚ --//

//===============//
// Ú×   FV[JÚÉKvÈVXe
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Scene_Manager::M_Scene_Change_Option(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		GAME::INSTANCE::C_Game_Instance_Manager::M_Instance_Destroy_On_Scene_Change();
	}

	return;
}


//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Scene_Manager::~C_Scene_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Scene_Manager::M_Release(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		m_this.mpr_variable.game_scene.reset();
	}

	return;
}


//-- [h --//

//===============//
// Ú×   F¼O©çV[ð[h·é
// ø   Fstring [h·éV[¼
// ßèl Fvoid
//===============//
bool C_Scene_Manager::M_Scene_Load(std::string in_load_scene)
{
	// ^CgV[
	if (in_load_scene == "TITLE")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"TITLE");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Title());

		return true;
	}

	// Q[V[
	if (in_load_scene == "GAME")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"GAME");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Game());

		return true;
	}

	
	// V[ªÈ¢Èç»Ì±ÆðÔ·
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "±ÌV[Í èÜ¹ñF" + in_load_scene);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

	// V[ª©Â©çÈ©Á½
	return false;
}


//-- Qb^ --//

//===============//
// Ú×   F»ÝÌV[ÌAhXðÔ·
// ø   Fvoid
// ßèl FC_Scene_Base * »ÝÌV[ÌAhX
//===============//
GAME::SCENE::BASE::C_Scene_Base * C_Scene_Manager::M_Get_Scene(void)
{
	return m_this.mpr_variable.game_scene.get();
}
