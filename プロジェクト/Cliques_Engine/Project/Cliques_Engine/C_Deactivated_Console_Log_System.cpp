////
// Ú×   FR\[OpÌVXeð³ø»·éNX
// à¾   F[XÈÇR\[OªsvÈêÉgp·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Deactivated_Console_Log_System.h"


//  l[Xy[XÌÈª  //
using namespace DEBUGGER::LOG::CONSOLE::DEACTIVATED;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Deactivated_Console_Log_System::C_Deactivated_Console_Log_System(void)
{
	return;
}


//===============//
// Ú×   FfobOVXeÌú»Æ¶¬
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Init_Debug(void)
{
	return;
}


//===============//
// Ú×   FfobOOVXe³ø»pNXð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System(void)
{
	//  Ïé¾  //
	C_Deactivated_Console_Log_System * deactivated_console_log_system = new C_Deactivated_Console_Log_System();	// ³ø»³ê½R\[OVXe


	// fobOVXeÌú»
	deactivated_console_log_system->M_Init_Debug();

	// VOgÌCX^Xð¶¬
	m_this.reset(deactivated_console_log_system);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Deactivated_Console_Log_System::~C_Deactivated_Console_Log_System(void)
{
	return;
}



//===============//
// Ú×   FfobOOVXeðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
{
	return;
}


//-- OoÍ --//

//===============//
// Ú×   Fwè³ê½¶ñðÝè³ê½t@C¼ÅoÍ·é
// ø   FE_CONSOLE_LOG_TAGS OÌíÞ, string L^·ét@C¼, string L^àe
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_log_tags, std::string in_log_file_name, std::string in_print_text)
{
	return;
}


//===============//
// Ú×   Fð~ßÄOðo·
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	return;
}


//===============//
// Ú×   FR\[ÌOðú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Console_Log_Flush(void)
{
	return;
}


//===============//
// Ú×   FR\[Ì¶J[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//===============//
// Ú×   FR\[Ì¶J[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//===============//
// Ú×   FR\[Ì¶J[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR ¶ÌF, E_CONSOLE_LOG_COLOR wiÌF
// ßèl Fvoid
//===============//
void C_Deactivated_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_text_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	return;
}



