////
// Ú×   FCliques EngineÌCÖ
// à¾   F±±ÅC[vâZbgAbvðs¤
// ì¬Ò Fûüâ´½
////


//  }N  //

// fobOðs¤½ßÌOVXeÌ}N
#define _CRTDBG_MAP_ALLOC


//  t@CÐç«  //
#include "Cliques_Engine_main.h"
#include "C_Game_Manager.h"
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"

#include "C_Console_Log_Interface.h"


//  CÖ  //

// CÖiGg[|Cgj
int main(void)
{
	//  ú»  //
	
	// OSpVXeÌ¶¬
	M_OS_Create_System();

	// _OAPIÌ¶¬
	M_Rendering_API_Init();

	// Q[pVXeÌú»
	M_Game_Set_Up();

	// fobOÍú»¬÷ÌÝ¬÷ÌOðc·
	M_Print_Log_Of_Succeeded_Init();


	//  C[v  //
	while (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		// Q[ÌvZXðÀs
		GAME::C_Game_Manager::M_Executes_Process();
	}


	//  I¹  //
	M_Game_End();


	//  Av¨íè  //
	return 0;
}


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FOSVXeÌ¶¬ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_OS_Create_System(void)
{
	// OSð¶¬·é@¸sÅI¹
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//===============//
// Ú×   F_OAPIVXeÌ¶¬ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Rendering_API_Init(void)
{
	// OS§äVXeðú»µÄ_OAPIð¶¬·é@¸sÅI¹
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//===============//
// Ú×   FQ[VXeÌú»ðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Game_Set_Up(void)
{
	// ±êÜÅÌú»ª¬÷µÄ¢éÌÝú»ðs¤
	if (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		GAME::C_Game_Manager::M_Init();
	}

	return;
}



//===============//
// Ú×   FQ[ÌI¹
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Game_End(void)
{
	// I¹ªÀs³ê½ÌÅAvP[Vðâ~ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "--------I¹ªÀs³ê½ÌÅAvP[Vðâ~--------");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();
	
	// Q[Ìðú
	GAME::C_Game_Manager::M_Release();

	// _OpÌAvP[VðI¹·é
	PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API();

	return;
}


//-- fobOO --//

//===============//
// Ú×   Fú»Ì¬÷ð\¦·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void M_Print_Log_Of_Succeeded_Init(void)
{
	// ú»É¬÷µÄ¢È©Á½ç²¯é
	if (!GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		return;
	}

	// ú»Ì¬÷ÌOðc·
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "--------ú»I¹--------");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "--------AvP[VJn--------");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUIÌæÊ`æðJnµÜ·");

	return;
}




//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

