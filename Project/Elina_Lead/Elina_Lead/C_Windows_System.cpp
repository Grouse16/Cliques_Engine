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

#include "C_Windows_System.h"
#include "C_Wnd_Proc_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


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
C_Windows_System::C_Windows_System(void)
{
	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�𐶐����鏈��
// ����   �Fvoid
// �߂�l �F�����������ǂ��� �������Ă���true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Windows_System::M_Creat_Window(void)
{
	// �� �ϐ��錾 �� //
	WNDCLASSEX w_wc;	// WNDCLASSEX�\���̂̒��g�̏���

	std::wstring device_name_in_wstr;	// ���C�h������ł̃E�B���h�E��


	// �E�B���h�E�����C�h������ɕϊ�
	{
		// �� �ϐ��錾 �� //
		int text_size = (int)con_DEVICE_NAME.size();	// ������


		device_name_in_wstr.resize(text_size + 1);
		device_name_in_wstr[text_size] = '\0';

		for (int l_now_text = 0; l_now_text < text_size; l_now_text++)
		{
			device_name_in_wstr[l_now_text] = con_DEVICE_NAME[l_now_text];
		}
	}


	// ���̍\���̂̃T�C�Y
	w_wc.cbSize = sizeof(WNDCLASSEX);

	// �E�B���h�E�̃X�^�C��
	w_wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	// �E�B���h�E�v���V�[�W���̃A�h���X
	w_wc.lpfnWndProc = OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Get_Engine_APK_Wnd_Proc();

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
	w_wc.lpszClassName = device_name_in_wstr.data();

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
		device_name_in_wstr.data(),

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


//==��  �p�u���b�N  ��==//

//-��-  �������ƏI����  -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�Y�̃V�X�e��������������
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Creat_Windows_System(void)
{
	m_this_instance.reset(new C_Windows_System());

	// �f�o�b�O�V�X�e��������
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Init_Debug();
#endif // _DEBUG

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�Y�@�\�̏������p����
// ����   �FHINSTANCE& �C���X�^���X�n���h��, int& �R�}���h�ԍ�
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Windows_System::M_Set_Up(void)
{
	// �� �f�o�b�O���̂݃Z�b�g�A�b�v�J�n��ʒm �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�E�B���h�E�Y�̃Z�b�g�A�b�v�J�n-��-��-��-��-��-��-��-");
#endif // _DEBUG


	// �E�B���h�E�𐶐�����
	M_Creat_Window();


	// �� �f�o�b�O���̂݃Z�b�g�A�b�v������ʒm �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�E�B���h�E�Y�̃Z�b�g�A�b�v�ɐ����AGUI���N������-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


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
C_Windows_System::~C_Windows_System()
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉���ȂǏI�����̏������s��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Release(void)
{
	mpr_variable.m_cmd_show = 0;
	mpr_variable.s_wnd.h_my_wind = NULL;
	mpr_variable.s_wnd.msg_of_wnd = MSG();

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̍X�V�������Ȃ�
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Update(void)
{
	// �� �E�B���h�E�̏��� �� //

	// ���[�U�[�ɂ����͂̍X�V
	while (PeekMessage(&mpr_variable.s_wnd.msg_of_wnd, NULL, 0, 0, PM_REMOVE) > 0)
	{
		// �������b�Z�[�W�𐶐�
		TranslateMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// �E�B���h�E�v���V�[�W�����Ăяo���ă��b�Z�[�W�X�V
		DispatchMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// �E�B���h�E��������t���O�𗧂Ă����ʒm����
		if (mpr_variable.s_wnd.msg_of_wnd.message == WM_QUIT)
		{
			m_flg_os_active = false;

			break;
		}
	}

	// �E�B���h�E�T�C�Y�̍X�V
	M_Window_Size_Update();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃T�C�Y�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Window_Size_Update(void)
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
// �ڍ�   �F�E�B���h�E�̏����R�}���h�ԍ����Z�b�g
// ����   �Fint �R�}���h�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Set_Cmd_Show(int in_cmdshow)
{
	// �� �ϐ��錾 �� //
	C_Windows_System * wind_os_system = static_cast<C_Windows_System*>(m_this_instance.get());	// �E�B���h�E�YOS�p�̃V�X�e��


	wind_os_system->mpr_variable.m_cmd_show = in_cmdshow;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���E�B���h�E�̃n���h����Ԃ�
// ����   �Fvoid
// �߂�l �FHWND ���E�B���h�E�̃n���h��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
HWND C_Windows_System::M_Get_Window_Handle(void)
{
	return static_cast<C_Windows_System*>(m_this_instance.get())->mpr_variable.s_wnd.h_my_wind;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̎��Ԃ������̎Q�Ɛ�ɓn��
// ����   �FS_Time_Inform & ���Ԃ̐ݒ��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Get_Now_Time(OS::S_Time_Inform & in_set_time_inform)
{
	// �� �ϐ��錾 �� //
	time_t get_time = time(nullptr);	// ���ԏ��

	tm time_data;	// ���ԏ�����͂����f�[�^


	// ���ԏ����f�[�^�ɕϊ�
	localtime_s(&time_data, &get_time);


	// ���t��ݒ�
	in_set_time_inform.year = time_data.tm_year + 1900;	// �N�A���肵������1900�N���ȗ�����Ă��邽�ߒ���
	in_set_time_inform.month = time_data.tm_mon + 1;	// ���A���肵����񂪂O�n�܂�Ō����v�Z���Ă���̂Œ���(0�`11 + 1 = 1�`12)
	in_set_time_inform.day = time_data.tm_mday;			// ��

	// ������ݒ�
	in_set_time_inform.hour = time_data.tm_hour;
	in_set_time_inform.minute = time_data.tm_min;
	in_set_time_inform.second = time_data.tm_sec;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�o�ߎ��Ԃ��~���b�P�ʂŎ擾����
// ����   �Funsigned __int64 & �擾��̎��ԕϐ��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Get_Now_Mili_Second(unsigned __int64 & in_plz_set_this_timer)
{// * GetTickCount64��1.26�i�m�b�ōő��Ȃ̂Ŏg�p���Ă���
	in_plz_set_this_timer = GetTickCount64();

	return;
}


//-��- �E�B���h�E�@�\ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃^�C�g����ҏW����
// ����   �Fconst wstring & �Z�b�g����^�C�g����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_System::M_Set_Window_Title(const std::wstring & in_set_title_name)
{
	// �E�B���h�E�^�C�g�����Z�b�g
	SetWindowText(mpr_variable.s_wnd.h_my_wind, in_set_title_name.c_str());

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�Z�[�W�{�b�N�X��\������(�E�B���h�E�n���h����K�v�Ƃ��邽��)
// ����   �Fconst wstring & �^�C�g��, const wstring & �\�����e, const unsigned int ���b�Z�[�W�{�b�N�X�̎��
// �߂�l �Fint �E�B���h�E���͂̌���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Windows_System::M_Creat_Massage_Box(const std::wstring & in_title, const std::wstring & in_text, const unsigned int in_type)
{
	return MessageBox(mpr_variable.s_wnd.h_my_wind, in_text.c_str(), in_title.c_str(), in_type);
}


#endif // OS_IS_WINDOWS
