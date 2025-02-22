////
// Ú×   FEBhEYpÌOðoÍ·éNXÌè`
// à¾   FfobOpÉOðL^·éVXeðEBhEYpÉ`¬·é
// ì¬Ò Fûüâ´½
////


//  fobOÌÝLø  //
#ifdef _DEBUG

//  EBhEYÂ«ÅÌÀsÌÝLø  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <conio.h>

#include "C_Windows_Console_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_User_System.h"
#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"
#include "Console_Debug_Log_Names.h"
#include "GCC_Or_MSVC_Macro.h"
#include "Challenge_Mode_Macro.h"


// fobOÍ[No
#define _CRTDBG_MAP_ALLOC


//  l[Xy[XÌÈª  //
using namespace DEBUGGER::LOG::CONSOLE::WINDOWS;


//  l[Xy[X  //

// WindowspÌR\[VXeÉgp·éèQðÄÑo·½ßÌ¼O
namespace LOCALSPACE::CONSTANT_DATAS
{
	//  è  //
	const char * con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// fobOf[^Û¶æÌpX

	constexpr int con_BLACK = 0;	// F
	constexpr int con_GRAY = FOREGROUND_INTENSITY;	// DF
	constexpr int con_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;	// F
	constexpr int con_LIGHT_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;	// ¾é¢F
	constexpr int con_RED = FOREGROUND_RED;		// ÔF
	constexpr int con_PINK = FOREGROUND_RED | FOREGROUND_INTENSITY;		// sN
	constexpr int con_GREEN = FOREGROUND_GREEN;	// ÎF
	constexpr int con_LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// ©ÎF
	constexpr int con_BLUE = FOREGROUND_BLUE;	// ÂF
	constexpr int con_LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// F
	constexpr int con_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE;	// F
	constexpr int con_LIGHT_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// ¾é¢F
	constexpr int con_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;	// ©F
	constexpr int con_LIGHT_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// ¾é¢©F
	constexpr int con_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;	// VAiÂj
	constexpr int con_LIGHT_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// ¾é¢VAiÂj
}


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^ACX^X»h~Ì½ßÉBÁ
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Windows_Console_Log_System::C_Windows_Console_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//===============//
// Ú×   FfobOVXeÌú»
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Init_Debug(void)
{
	// AZu`W
#ifdef  D_ASM_CHALLENGE

	// GCCÅÌRpC
#ifdef D_GCC_COMPILE & D_ASM_CHALLENGE

	// ·ÅÉú»³êÄ¢êÎ²¯é
	asm volatile
		(
			"cmpb $1, %0\n"			// initialized ª true (1) ©Ç¤©ðär
			"ret\n"					// initialized ª true ÌêÍ^[
			:						// oÍIyh
	: "m" (mpr_variable.initialized) // üÍIyh
		);

	// MSVCÅÌRpC
#elif D_MSVC_COMPILE

	// ·ÅÉú»³êÄ¢êÎ²¯é
	__asm
	{
		mov al, mpr_variable.initialized // initialized ð AL WX^É[h
		cmp al, 1                       // true (1) Æär
		ret                             // true ÌêÍ^[
	}

#endif

	// AZu`WÅÍÈ¢
#else

	// ·ÅÉú»³êÄ¢êÎ²¯é
	if (mpr_variable.initialized == true)
	{
		return;
	}

#endif //  D_ASM_CHALLENGE


	// ú»³ê½±ÆðL^
	mpr_variable.initialized = true;

	// R\[æÊðú»·é
	FreeConsole();


	// R\[æÊð¢«·é
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);


	// R\[Ìf[^t@Cðüè
	_wfreopen_s(&mpr_variable.console_file, L"CONOUT$", L"w+", stdout);

	// oÍÌ¶R[hwèAhttps://learn.microsoft.com/en-us/cpp/c-runtime-library/translation-mode-constants?view=msvc-170
	if (_setmode(_fileno(stdout), _O_TEXT) == -1)
	{
		return;
	}


	// ÈñÆÈ­JbR¢¢FðÝè·é
	DEBUGGER::LOG::CONSOLE::WINDOWS::C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);

	// OÌ¶¬É¬÷µ½±ÆðOÆµÄc·
	M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "fobOpR\[yÑVXeÌ¶¬É¬÷");

	return;
}


//===============//
// Ú×   FWindowspÌR\[OVXeð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Create_Windows_Console_Debug_Log_System(void)
{
	//  Ïé¾  //
	C_Windows_Console_Log_System * new_windows_console_log_system = new C_Windows_Console_Log_System();	// EBhEYpÌR\[OVXe


	// fobOVXeÌú»
	new_windows_console_log_system->M_Init_Debug();

	// VOgÌCX^Xð¶¬
	m_this.reset(new_windows_console_log_system);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Windows_Console_Log_System::~C_Windows_Console_Log_System(void)
{
	M_Delete_Console_Debug_Log_System();

	return;
}


//===============//
// Ú×   FfobOOVXeðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
{
	// R\[ðI¹·é
	FreeConsole();
	mpr_variable.console_file = nullptr;

	return;
}


//-- OoÍ --//

//===============//
// Ú×   FOðoÍ·é
// ø   FC_Console_Debug_Log_System_Base::E_CONSOLE_LOG_TAGS OÌíÞ, string L^·ét@C¼, string L^àe
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// t@CìpVXe

	OS::S_Day_And_Time_Inform now_time_and_day;	// ÔÆút

	std::string log_file_path;	// oÍ·éO^Cg
	std::string print_log;	// oÍ·éO


	// »ÝÌÔîñðæ¾
	OS::C_OS_User_System::M_Update_Time();
	now_time_and_day = OS::C_OS_User_System::M_Get_Now_Day_And_Time();


	// oÍ·éOÌútðÝè
	log_file_path += std::to_string(now_time_and_day.year)		// NÌ\¦
		+ "-" + std::to_string(now_time_and_day.month)		// Ì\¦
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// úÌ\¦


	//  OÌ¯ÊÔÉæÁÄÊXÌîñðtÁ  //
	switch (in_tag)
	{
		//-- VXe --//

		//  ZbgAbv  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP:
		log_file_path += "SYSTEM_00-SET_UP-";
		break;

		//  Vbg_E  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN:
		log_file_path += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-- AvP[V --//

		//  IuWFNg  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT:
		log_file_path += "APPLICATION_00-OBJECT-";
		break;

		//  Q[Ì`æpVXe  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING:
		log_file_path += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_UI:
		log_file_path += "APPLICATION_02-UI-";
		break;


		//-- G[ --//

		// áO
	default:
		break;
	}


	// oÍ·éOðÝè
	print_log =
		std::to_string(now_time_and_day.hour) + "-hour."	// Ô
		+ std::to_string(now_time_and_day.minute) + "-min."	// ª
		+ std::to_string(now_time_and_day.second) + "-sec\n"	// b
		+ (std::string)(in_print_log)+"\n";				// Oàe


	// R\[Éîñð\¦·é
	std::wcout << std::endl << log_file_path.c_str() << std::endl << print_log.c_str();


	// f[^ðLü·é
	file_user_system.M_Set_File_Path
	(
		((std::string)LOCALSPACE::CONSTANT_DATAS::con_DEBUG_FOLDER_PATH
		+ "/" + log_file_path
		+ "/" + (std::string)(in_file_name) + ".txt").c_str()
	);
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();

	return;
}


//===============//
// Ú×   FR\[ðÝé½ßÉð~ßÄüÍobt@ðSÄNAµ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	//  è  //
	constexpr int con_ENTER = 13;	// EnterÌAXL[R[h


	//  Ïé¾  //
	bool inputted_enter = false;	// Enterª³ê½©Ç¤©


	// obt@ÌàeðæÊÉoÍ
	std::wcout << std::flush;

	// ¶ðFÉ·é
	M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE, COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE);

	// EnterðÒÂ±Æð\¦·é
	std::cout << std::endl;
	std::cout << "Press Enter to continue...";
	
	// Enterª³êéÜÅÒ@·é
	while (inputted_enter == false)
	{
		// L[{[hÌüÍð`FbN
		if (_kbhit())
		{
			// EnterL[ÌAXL[R[hªüÍ³ê½çiEnterÌüÍª Á½çj[vð²¯é
			if (_getch() == con_ENTER)
			{
				inputted_enter = true;
			}
		}
	}

	return;
}


//===============//
// Ú×   FR\[ÌOðú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Console_Log_Flush(void)
{
	//  è  //
	constexpr int con_LINE_SUM = 50;	// æÊðNA·é½ßÌósÌ


	// Fð³Éß·
	M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR::e_WHITE);
	M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	
	// ósðoÍµÄæÊðNAµ½æ¤É©¹é
	for (int l_write_line = 0; l_write_line < con_LINE_SUM; ++l_write_line)
	{
		std::cout << std::endl;
	}

	return;
}


//===============//
// Ú×   FR\[Ì¶J[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	//  Ïé¾  //
	int & color_data = mpr_variable.text_color;	// Ff[^ÌÝèæÌQÆ


	// {Æz[y[W https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	//  ¶J[ÏXðÝè  //
	switch (in_set_color)
	{
		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  O[  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  ¾é¢  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  Ô  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  sN  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  Î  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  ¾é¢Î  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  Â  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  ¾é¢Â  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  ¾é¢  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  ©  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  ¾é¢©  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  VA  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  ¾é¢VA  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// FÌXV
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (mpr_variable.color_back << 4) | mpr_variable.text_color);

	return;
}


//===============//
// Ú×   FR\[ÌwiJ[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR Ýè·éFÔ
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	//  Ïé¾  //
	int & color_data = mpr_variable.color_back;	// Ff[^ÌÝèæÌQÆ


	//  ¶J[ÏXðÝè  //
	switch (in_set_color)
	{
		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  O[  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  ¾é¢  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  Ô  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  sN  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  Î  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  ¾é¢Î  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  Â  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  ¾é¢Â  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//    //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  ¾é¢  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  ©  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  ¾é¢©  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  VA  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  ¾é¢VA  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// FÌXV
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (mpr_variable.color_back << 4) | mpr_variable.text_color);

	return;
}


//===============//
// Ú×   FR\[ÌwiJ[ðÏX·é
// ø   FE_CONSOLE_LOG_COLOR eLXgÌFÔ, E_CONSOLE_LOG_COLOR wiÌFÔ
// ßèl Fvoid
//===============//
void C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_txt_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // D_OS_IS_WINDOWS

#endif // _DEBUG

