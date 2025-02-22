////
// Ú×   FOðR\[Æt@CÉoÍ·éNX
// à¾   FfobOpÉOðL^·é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM
#define D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


//  t@CÐç«  //
#include <memory>
#include <string>

#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"


//  l[Xy[X  //

// fobOOÌR\[ÌîêNXðÄÑo·½ßÌ¼O
namespace DEBUGGER::LOG::CONSOLE::BASE
{
	//  NX  //

	// fobOOoÍpVXeÌîêNX
	class C_Console_Debug_Log_System_Base
	{
		//== veNg ==//
	protected:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct Pr_Variable
		{
			FILE * console_file = nullptr;	// R\[ÌoÍæ

			int text_color = 0;	// R\[ÌeLXgÌF
			int color_back = 0;	// R\[ÌwiF

			bool initialized = false;	// ú»³ê½©Ç¤©ÌtO

		} static mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static std::unique_ptr<C_Console_Debug_Log_System_Base> m_this;	// OVXepNXÌÀÌiVOgj


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^ACX^X»h~Ì½ßÉBÁ
		C_Console_Debug_Log_System_Base(void);

		// fXgN^
		virtual ~C_Console_Debug_Log_System_Base(void);

		// fobOVXeÌú»Æ¶¬
		virtual void M_Init_Debug(void) = 0;

		// fobOOVXeðí·é
		virtual void M_Delete_Console_Debug_Log_System(void) = 0;

		// fobOOVXeððú·é
		static void M_Release(void);


		//-- Qb^ --//

		// R\[OVXeÌCX^XÌAhXðÔ·@ßèlFR\[OVXeÌQÆ
		static C_Console_Debug_Log_System_Base * M_Get_Console_Debug_Log_System(void);


		//-- OoÍ --//

		// wè³ê½¶ñðÝè³ê½t@C¼ÅoÍ·é@øFOÌíÞ, L^·ét@C¼, L^àe
		virtual void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) = 0;

		// ð~ßÄOðo·
		virtual void M_Stop_Update_And_Log_Present(void) = 0;

		// R\[ÌOðú»·é
		virtual void M_Console_Log_Flush(void) = 0;

		// R\[Ì¶J[ðÏX·é@øFÝè·éFÔ
		virtual void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// R\[ÌwiJ[ðÏX·é@øFÝè·éFÔ
		virtual void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// R\[Ì¶ÆwiJ[ðÏX·é@øF¶ÌF, wiÌF
		virtual void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

