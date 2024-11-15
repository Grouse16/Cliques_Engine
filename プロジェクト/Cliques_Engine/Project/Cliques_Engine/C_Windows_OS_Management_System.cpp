//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�Y�̋@�\���g�����߂̃N���X
// ����   �F�E�B���h�E�ݒ�⃁�b�Z�[�W�������s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include <time.h>

#include "C_Windows_OS_Management_System.h"
#include "C_Wnd_Proc_Manager.h"

#include "C_Console_Log_Interface.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace OS::WINDOWS;


// �� �}�N�� �� //
#define D_ICON_ADDRESS L"data/asset/image/window/star.ico"	// �A�C�R���n���h��

#define D_WND_WIDTH 1000	// �E�B���h�E�̉��̃T�C�Y
#define D_WND_HEIGHT 500	// �E�B���h�E�̏c�̃T�C�Y


// �� �֐� �� //

//==��  �v���C�x�[�g  ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Windows_OS_Management_System::C_Windows_OS_Management_System(void)
{
	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�𐶐����鏈��
// ����   �Fvoid
// �߂�l �F�����������ǂ��� �������Ă���true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Windows_OS_Management_System::M_Create_Window(void)
{
	// �� �ϐ��錾 �� //
	WNDCLASSEX w_wc = WNDCLASSEX();	// WNDCLASSEX�\���̂̒��g�̏���

	std::wstring device_name = M_Get_Window_Title_Name();	// ���C�h������ł̃E�B���h�E��


	// ���̍\���̂̃T�C�Y
	w_wc.cbSize = sizeof(WNDCLASSEX);

	// �E�B���h�E�̃X�^�C��
	w_wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	// �E�B���h�E�v���V�[�W���̃A�h���X
	w_wc.lpfnWndProc = OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Get_Game_APK_Wnd_Proc();

	// �\���̗̂\���̃�����
	w_wc.cbClsExtra = 0;

	// �E�B���h�E���̗\���̃�����
	w_wc.cbWndExtra = 0;

	// �C���X�^���X�n���h��
	w_wc.hInstance = GetModuleHandle(0);

	// �A�v���̃V���[�g�J�b�g�̃A�C�R���̌�����
	w_wc.hIcon = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// �E�B���h�E��̃}�E�X�J�[�\���̌�����
	w_wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// �E�B���h�E���̔w�i�F�i�N���C�A���g�̈�̔w�i�F�j
	w_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	// �E�B���h�E�̃��j���[�̖��O
	w_wc.lpszMenuName = NULL;

	// �E�B���h�E�̃N���X�̖��O
	w_wc.lpszClassName = device_name.data();

	// �^�C�g���o�[�̃A�C�R���̌�����
	w_wc.hIconSm = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// ���W�X�^�ɃZ�b�g���ăE�B���h�E����o�^
	RegisterClassEx(&w_wc);


	// �E�B���h�E�̑傫����ݒ�
	M_Set_Window_Size_Variable(D_WND_WIDTH, D_WND_HEIGHT);
	

	// �E�B���h�E�̕\���ݒ�̏�����
	mpr_variable.s_wnd.h_my_wind = CreateWindowEx(

		// �g���E�B���h�E�X�^�C��
		0,

		// �E�B���h�E�N���X�̖��O
		w_wc.lpszClassName,

		// �E�B���h�E�̖��O
		device_name.data(),

		// �E�B���h�E�X�^�C��
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_CAPTION,

		// �\���ʒu
		CW_USEDEFAULT,	// ����w���W
		CW_USEDEFAULT,	// ����x���W 

		//�E�B���h�E�̃T�C�Y
		(int)D_WND_WIDTH,	// �E�B���h�E�̕�
		(int)D_WND_HEIGHT,	// �E�B���h�E�̍���

		// �e�E�B���h�E�̃n���h��
		NULL,

		// ���j���[�n���h���܂��͎q�E�B���h�EID
		NULL,

		// �C���X�^���X�n���h��
		GetModuleHandle(0),

		// �E�B���h�E�쐬�f�[�^
		NULL);


	// �E�B���h�E��\��
	ShowWindow(mpr_variable.s_wnd.h_my_wind, mpr_variable.m_cmd_show);

	// �E�B���h�E�̏�Ԃ𒼂��ɔ��f(�E�B���h�E�̃N���C�A���g�̈���X�V)
	UpdateWindow(mpr_variable.s_wnd.h_my_wind);

	// ����
	return true;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�E�X���͂̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Mouse_Input_Update(void)
{
	// �� �ϐ��錾 �� //
	POINT mouse_point;	// �}�E�X���W


	// �}�E�X���W���擾����
	GetCursorPos(&mouse_point);
	M_Set_Mouse_Position_Variable(mouse_point.x, mouse_point.y);

	return;
}


//==��  �p�u���b�N  ��==//

//-��-  �������ƏI����  -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�Y�p�̃V�X�e��������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Create_Windows_System(void)
{
	// �E�B���h�E�Y�p�̃V�X�e���𐶐�
	m_this_instance.reset(new C_Windows_OS_Management_System());

	// ���O�V�X�e����������
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Create_And_Initialize_Console_Log_System();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�Y�@�\�̏������p����
// ����   �FHINSTANCE& �C���X�^���X�n���h��, int& �R�}���h�ԍ�
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Windows_OS_Management_System::M_Set_Up(void)
{
	// �E�B���h�E�Y�p�A�v���P�[�V�����̃Z�b�g�A�b�v�J�n�����m
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�E�B���h�E�Y�A�v���P�[�V�����̃Z�b�g�A�b�v�J�n-��-��-��-��-��-��-��-");


	// �E�B���h�E�𐶐�����
	M_Create_Window();


	// �E�B���h�E�Y�p�A�v���P�[�V�����̃Z�b�g�A�b�v�������
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�E�B���h�E�Y�̃Z�b�g�A�b�v�ɐ����AGUI���N������-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();


	// �E�B���h�E�T�C�Y�̍X�V
	M_Window_Size_Update();

	// ����
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Windows_OS_Management_System::~C_Windows_OS_Management_System()
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉���ȂǏI�����̏������s��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Release(void)
{
	mpr_variable.m_cmd_show = 0;
	mpr_variable.s_wnd.h_my_wind = NULL;

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̍X�V�������Ȃ�
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Update(void)
{
	// ���@�ϐ��錾 �� //
	MSG msg_of_wnd = MSG();	// �E�B���h�E�̏����p�̕ϐ�


	// �� �E�B���h�E�̏��� �� //

	// ���[�U�[�ɂ����͂̍X�V
	while (PeekMessage(&msg_of_wnd, NULL, 0, 0, PM_REMOVE) > 0)
	{
		// �������b�Z�[�W�𐶐�
		TranslateMessage(&msg_of_wnd);

		// �E�B���h�E�v���V�[�W�����Ăяo���ă��b�Z�[�W�X�V
		DispatchMessage(&msg_of_wnd);

		// �E�B���h�E��������t���O�𗧂Ă����ʒm����
		if (msg_of_wnd.message == WM_QUIT)
		{
			m_flg_os_active = false;

			break;
		}
	}

	// �E�B���h�E�T�C�Y�̍X�V
	M_Window_Size_Update();

	// �}�E�X���W�̍X�V
	M_Mouse_Input_Update();

	// ���Ԃ̍X�V
	M_Update_Time();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃T�C�Y�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Window_Size_Update(void)
{
	// �� �ϐ��錾 �� //
	RECT client_rect;	// �N���C�A���g�̈�̃s�N�Z�����W

	S_Window_Position set_window_pos;	// �ݒ肷��E�B���h�E���W


	// �E�B���h�E�̃T�C�Y���擾
	GetClientRect(mpr_variable.s_wnd.h_my_wind, &client_rect);
	M_Set_Window_Size_Variable(client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);


	// �E�B���h�E�̈ʒu���擾
	set_window_pos.position_left_x = client_rect.left;
	set_window_pos.position_right_x = client_rect.right;
	set_window_pos.position_top_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.top;
	set_window_pos.position_bottom_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.bottom;
	M_Set_Window_Position_Variable(set_window_pos);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Update_Time(void)
{
	// �� �ϐ��錾 �� //
	time_t get_time = time(nullptr);	// ���ԏ��

	tm time_data;	// ���ԏ�����͂����f�[�^

	S_Day_And_Time_Inform now_time;	// ���݂̎���


	// ���ԏ����f�[�^�ɕϊ�
	localtime_s(&time_data, &get_time);

	// ���t��ݒ�
	now_time.year = time_data.tm_year + 1900;	// �N�A���肵������1900�N���ȗ�����Ă��邽�ߒ���
	now_time.month = time_data.tm_mon + 1;		// ���A���肵����񂪂O�n�܂�Ō����v�Z���Ă���̂Œ���(0�`11 + 1 = 1�`12)
	now_time.day = time_data.tm_mday;			// ��

	// ������ݒ�
	now_time.hour = time_data.tm_hour;	// ��
	now_time.minute = time_data.tm_min;	// ��
	now_time.second = time_data.tm_sec;	// �b

	// ���݂̓������Z�b�g
	M_Set_Now_Day_And_Time(now_time);


	// ���݂̌o�ߎ��Ԃ��Z�b�g
	M_Set_Now_Time_By_Start_In_Milli_Second(GetTickCount64());

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̏����R�}���h�ԍ����Z�b�g
// ����   �Fint �R�}���h�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Set_Cmd_Show(int in_command_show)
{
	// �� �ϐ��錾 �� //
	C_Windows_OS_Management_System * wind_os_system = static_cast<C_Windows_OS_Management_System*>(m_this_instance.get());	// �E�B���h�E�YOS�p�̃V�X�e��


	wind_os_system->mpr_variable.m_cmd_show = in_command_show;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���E�B���h�E�̃n���h����Ԃ�
// ����   �Fvoid
// �߂�l �FHWND ���E�B���h�E�̃n���h��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
HWND C_Windows_OS_Management_System::M_Get_Window_Handle(void)
{
	return static_cast<C_Windows_OS_Management_System*>(m_this_instance.get())->mpr_variable.s_wnd.h_my_wind;
}


//-��- �E�B���h�E�@�\ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃^�C�g����ҏW����
// ����   �Fconst wstring & �Z�b�g����^�C�g����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_OS_Management_System::M_Change_Window_Title(const std::wstring & in_set_title_name)
{
	// �E�B���h�E�^�C�g�����Z�b�g
	SetWindowText(mpr_variable.s_wnd.h_my_wind, in_set_title_name.c_str());
	M_Set_Window_Title_Name(in_set_title_name);

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�Z�[�W�{�b�N�X��\������(�E�B���h�E�n���h����K�v�Ƃ��邽��)
// ����   �Fconst wstring & �^�C�g��, const wstring & �\�����e, unsigned int ���b�Z�[�W�{�b�N�X�̎��
// �߂�l �Fint �E�B���h�E���͂̌���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Windows_OS_Management_System::M_Create_Massage_Box(const std::wstring & in_title, const std::wstring & in_text, unsigned int in_type)
{
	return MessageBox(mpr_variable.s_wnd.h_my_wind, in_text.c_str(), in_title.c_str(), in_type);
}


#endif // OS_IS_WINDOWS

