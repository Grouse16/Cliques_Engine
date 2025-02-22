////
// Ú×   FEBhEYpÌR\[OVXeÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE


//  t@CÐç«  //
#include "C_Console_Debug_Log_System_Base.h"


//  l[Xy[X  //

// EBhEYpÌR\[OpVXeðÄÑo·½ßÌ¼O
namespace DEBUGGER::LOG::CONSOLE::WINDOWS
{
	//  NX  //

	// EBhEYpR\[fobOOoÍVXe
	class C_Windows_Console_Log_System : public DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base
	{
		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//
		
		// RXgN^
		C_Windows_Console_Log_System(void);

		// fobOVXeÌú»Æ¶¬
		void M_Init_Debug(void) override;

		// WindowspÌR\[OVXeð¶¬·é
		static void M_Create_Windows_Console_Debug_Log_System(void);

		// fXgN^
		~C_Windows_Console_Log_System(void) override;

		// fobOOVXeðí·é
		void M_Delete_Console_Debug_Log_System(void) override;


		//-- OoÍ --//

		// wè³ê½¶ñðÝè³ê½t@C¼ÅoÍ·é@øFOÌíÞ, L^·ét@C¼, L^àe
		void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) override;

		// ð~ßÄOðo·
		void M_Stop_Update_And_Log_Present(void) override;

		// R\[ÌOðú»·é
		void M_Console_Log_Flush(void) override;

		// R\[Ì¶J[ðÏX·é@øFÝè·éFÔ
		void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// R\[ÌwiJ[ðÏX·é@øFÝè·éFÔ
		void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// R\[Ì¶ÆwiJ[ðÏX·é@øF¶ÌF, wiÌF
		void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) override;
	};
}


#endif //!D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE

