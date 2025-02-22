////
// Ú×   FEBhEYÌ@\ðg¤½ßÌNX
// à¾   FEBhEÝèâbZ[Wðs¤
// ì¬Ò Fûüâ´½
////


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include <time.h>

#include "C_Windows_OS_Management_System.h"
#include "C_Wnd_Proc_Manager.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace OS::WINDOWS;


//  è  //

// ±Ìt@CpÌèðÄÑo·½ßÌ¼O
namespace WND_OS_SYSTEM_CONSTANT_DATA
{
	constexpr wchar_t con_ICON_ADDRESS[] = L"data/asset/image/window/star.ico";	// ACRnh

	constexpr int con_WND_INITIAL_WIDTH = 1000;	// EBhEÌ¡ÌTCY
	constexpr int con_WND_INITIAL_HEIGHT = 500;	// EBhEÌcÌTCY
}


//  Ö  //

//==  vCx[g  ==//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
C_Windows_OS_Management_System::C_Windows_OS_Management_System(void)
{
	return;
}

//===============//
// Ú×   FEBhEð¶¬·é
// ø   Fvoid
// ßèl F¬÷µ½©Ç¤© ¬÷µÄ½çtrue
//===============//
bool C_Windows_OS_Management_System::M_Create_Window(void)
{
	//  Ïé¾  //
	WNDCLASSEX windows_class_ex = WNDCLASSEX();	// WNDCLASSEX\¢ÌÌgÌõ

	std::wstring device_name = M_Get_Window_Title_Name();	// Ch¶ñÅÌEBhE¼


	// ±Ì\¢ÌÌTCY
	windows_class_ex.cbSize = sizeof(WNDCLASSEX);

	// EBhEÌX^C
	windows_class_ex.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	// EBhEvV[WÌAhX
	windows_class_ex.lpfnWndProc = OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Get_Game_APK_Wnd_Proc();

	// \¢ÌÌ\õÌ
	windows_class_ex.cbClsExtra = 0;

	// EBhE¤Ì\õÌ
	windows_class_ex.cbWndExtra = 0;

	// CX^Xnh
	windows_class_ex.hInstance = GetModuleHandle(NULL);

	// AvÌV[gJbgÌACRÌ©½ß
	windows_class_ex.hIcon = LoadIcon(windows_class_ex.hInstance, WND_OS_SYSTEM_CONSTANT_DATA::con_ICON_ADDRESS);

	// EBhEãÌ}EXJ[\Ì©½ß
	windows_class_ex.hCursor = LoadCursor(NULL, IDC_ARROW);

	// EBhEàÌwiFiNCAgÌæÌwiFj
	windows_class_ex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	// EBhEÌj[Ì¼O
	windows_class_ex.lpszMenuName = NULL;

	// EBhEÌNXÌ¼O
	windows_class_ex.lpszClassName = device_name.data();

	// ^Cgo[ÌACRÌ©½ß
	windows_class_ex.hIconSm = LoadIcon(windows_class_ex.hInstance, WND_OS_SYSTEM_CONSTANT_DATA::con_ICON_ADDRESS);

	// WX^ÉZbgµÄEBhEîñðo^
	RegisterClassEx(&windows_class_ex);


	// EBhEÌå«³ðÝè
	M_Set_Window_Size_Variable(WND_OS_SYSTEM_CONSTANT_DATA::con_WND_INITIAL_WIDTH, WND_OS_SYSTEM_CONSTANT_DATA::con_WND_INITIAL_HEIGHT);
	

	// EBhEÌ\¦ÝèÌú»
	mpr_variable.s_wnd.h_my_wind = CreateWindowEx(

		// g£EBhEX^C
		0,

		// EBhENXÌ¼O
		windows_class_ex.lpszClassName,

		// EBhEÌ¼O
		device_name.data(),

		// EBhEX^C
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_CAPTION,

		// \¦Êu
		CW_USEDEFAULT,	// ¶ãwÀW
		CW_USEDEFAULT,	// ¶ãxÀW 

		//EBhEÌTCY
		(int)WND_OS_SYSTEM_CONSTANT_DATA::con_WND_INITIAL_WIDTH,	// EBhEÌ
		(int)WND_OS_SYSTEM_CONSTANT_DATA::con_WND_INITIAL_HEIGHT,	// EBhEÌ³

		// eEBhEÌnh
		NULL,

		// j[nhÜ½ÍqEBhEID
		NULL,

		// CX^Xnh
		GetModuleHandle(0),

		// EBhEì¬f[^
		NULL);


	// EBhEð\¦
	ShowWindow(mpr_variable.s_wnd.h_my_wind, SW_SHOW);

	// EBhEÌóÔð¼¿É½f(EBhEÌNCAgÌæðXV)
	UpdateWindow(mpr_variable.s_wnd.h_my_wind);

	// ¬÷
	return true;
}


//-- üÍ --//

//===============//
// Ú×   F}EXüÍÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Mouse_Input_Update(void)
{
	//  Ïé¾  //
	POINT mouse_point;	// }EXÀW


	// }EXÀWðæ¾·é
	GetCursorPos(&mouse_point);
	M_Set_Mouse_Position_Variable(mouse_point.x, mouse_point.y);

	return;
}


//==  pubN  ==//

//--  ú»ÆI¹  --//

//===============//
// Ú×   FEBhEYpÌVXeðú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Create_Windows_System(void)
{
	// EBhEYpÌVXeð¶¬
	m_this_instance.reset(new C_Windows_OS_Management_System());

	// OVXeðú»
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Create_And_Initialize_Console_Log_System();

	return;
}


//===============//
// Ú×   FEBhEY@\Ìú»p
// ø   FHINSTANCE& CX^Xnh, int& R}hÔ
// ßèl F¬÷ÌÝtrue
//===============//
bool C_Windows_OS_Management_System::M_Set_Up(void)
{
	// EBhEYpAvP[VÌZbgAbvJnðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "--------EBhEYAvP[VÌZbgAbvJn--------");


	// EBhEð¶¬·é
	M_Create_Window();


	// EBhEYpAvP[VÌZbgAbv®¹ðñ
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "--------EBhEYÌZbgAbvÉ¬÷AGUIðN®®¹--------");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();


	// EBhETCYÌXV
	M_Window_Size_Update();

	// ¬÷
	return true;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Windows_OS_Management_System::~C_Windows_OS_Management_System()
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúÈÇI¹Ìðs¤
// ø   Fvoid
// ßèl FÈµ
//===============//
void C_Windows_OS_Management_System::M_Release(void)
{
	mpr_variable.s_wnd.h_my_wind = NULL;

	return;
}


//-- XV --//

//===============//
// Ú×   FEBhEÌXVð¨±È¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Update(void)
{
	// @Ïé¾  //
	MSG msg_of_wnd = MSG();	// EBhEÌpÌÏ


	//  EBhEÌ  //

	// [U[ÉæéüÍÌXV
	while (PeekMessage(&msg_of_wnd, NULL, 0, 0, PM_REMOVE) > 0)
	{
		// ¶bZ[Wð¶¬
		TranslateMessage(&msg_of_wnd);

		// EBhEvV[WðÄÑoµÄbZ[WXV
		DispatchMessage(&msg_of_wnd);

		// EBhEªÂ¶½çtOð§Ä»êðÊm·é
		if (msg_of_wnd.message == WM_QUIT)
		{
			m_flg_os_active = false;

			break;
		}
	}

	// EBhETCYÌXV
	M_Window_Size_Update();

	// }EXÀWÌXV
	M_Mouse_Input_Update();

	// ÔÌXV
	M_Update_Time();

	return;
}


//===============//
// Ú×   FEBhEÌTCYÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Window_Size_Update(void)
{
	//  Ïé¾  //
	RECT client_rect;	// NCAgÌæÌsNZÀW

	S_Window_Position set_window_pos;	// Ýè·éEBhEÀW


	// EBhEÌTCYðæ¾
	GetClientRect(mpr_variable.s_wnd.h_my_wind, &client_rect);
	M_Set_Window_Size_Variable(client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);


	// EBhEÌÊuðæ¾
	set_window_pos.position_left_x = client_rect.left;
	set_window_pos.position_right_x = client_rect.right;
	set_window_pos.position_top_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.top;
	set_window_pos.position_bottom_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.bottom;
	M_Set_Window_Position_Variable(set_window_pos);

	return;
}


//===============//
// Ú×   FÔÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Update_Time(void)
{
	//  Ïé¾  //
	time_t get_time = time(nullptr);	// Ôîñ

	tm time_data;	// ÔîñððÍµ½f[^

	S_Day_And_Time_Inform now_time;	// »ÝÌÔ


	// Ôîñðf[^ÉÏ·
	localtime_s(&time_data, &get_time);

	// útðÝè
	now_time.year = time_data.tm_year + 1900;	// NAüèµ½îñÍ1900NªÈª³êÄ¢é½ßù³
	now_time.month = time_data.tm_mon + 1;		// Aüèµ½îñªOnÜèÅðvZµÄ¢éÌÅù³(0`11 + 1 = 1`12)
	now_time.day = time_data.tm_mday;			// ú

	// ðÝè
	now_time.hour = time_data.tm_hour;	// 
	now_time.minute = time_data.tm_min;	// ª
	now_time.second = time_data.tm_sec;	// b

	// »ÝÌúðZbg
	M_Set_Now_Day_And_Time(now_time);


	// »ÝÌoßÔðZbg
	M_Set_Now_Time_By_Start_In_Milli_Second(GetTickCount64());

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FEBhEÌnhÔâA¯ÊÔðÔ·
// ø   Fvoid
// ßèl Fvoid * EBhEÌnhÔâA¯ÊÔ
//===============//
void * C_Windows_OS_Management_System::M_Get_Window_Handle_Or_Identify(void) const
{
	return reinterpret_cast<void * >(mpr_variable.s_wnd.h_my_wind);
}


//-- EBhE@\ --//

//===============//
// Ú×   FEBhEÌ^CgðÒW·é
// ø   Fconst wstring & Zbg·é^Cg¼
// ßèl Fvoid
//===============//
void C_Windows_OS_Management_System::M_Change_Window_Title(const std::wstring & in_set_title_name)
{
	// EBhE^CgðZbg
	SetWindowText(mpr_variable.s_wnd.h_my_wind, in_set_title_name.c_str());
	M_Set_Window_Title_Name(in_set_title_name);

	return;
}


//===============//
// Ú×   FbZ[W{bNXð\¦·é(EBhEnhðKvÆ·é½ß)
// ø   Fconst wstring & ^Cg, const wstring & \¦àe, unsigned int bZ[W{bNXÌíÞ
// ßèl Fint EBhEüÍÌÊ
//===============//
int C_Windows_OS_Management_System::M_Create_Massage_Box(const std::wstring & in_title, const std::wstring & in_text, unsigned int in_type)
{
	return MessageBox(mpr_variable.s_wnd.h_my_wind, in_text.c_str(), in_title.c_str(), in_type);
}


#endif // OS_IS_WINDOWS

