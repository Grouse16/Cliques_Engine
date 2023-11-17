//����������������������������������������������//
// �ڍ�   �F����Q�[���A�G���i�E���[�h�̃��C���֐���
// ����   �F�����Ń��C�����[�v��Z�b�g�A�b�v���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �}�N�� �� //

// �f�o�b�O���s�����߂̃��O�V�X�e���̃}�N��
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include "C_Log_System.h"
#endif // _DEBUG


// �� OS���m �� //
#include "Platform_Detector_Macro.h"


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Manager.h"
#include "C_API_Initialize_And_Release_Manager.h"


// �� �֐� �� //

//-��- �������ƏI���� -��-//

// OS�V�X�e���̐������s��
void M_OS_Creat_System(void);

// �����_�����OAPI�̏��������s��
void M_Rendering_API_Init(void);

// �Q�[���V�X�e���̏��������s��
void M_Game_Set_Up(void);

// �Q�[���̏I������
void M_Game_End(void);


//-��- �f�o�b�O -��-//
#if _DEBUG

// �������̐�����\������
void M_Print_Log_Of_Succeeded_Init(void);

#endif // _DEBUG


// �� ���C���֐� �� //

// �E�B���h�E�Y����Winmain�֐����g�������̃}�N���̗L���͈͊O�ł͒l���g�p���Ȃ�����(���v���b�g�t�H�[���̂��߂�)	// �E�B���h�E�Y�̃T�u�V�X�e�����w�肷�邱��
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_System.h"
int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE /* �����g�p����鎖�͂Ȃ��A��ɂO */, _In_ LPSTR, _In_ int in_cmd_show)
{
// ���̑��̎� OpenGL�n��int main(void)�֐�����n�߂�
#else
int main(void)
{
#endif

	//===�� �����J�n ��===//
	
	// OS�p�V�X�e���̐���
	M_OS_Creat_System();


// �E�B���h�E�Y���̓R�}���h�ԍ����Z�b�g�iDirectX���g�p���̓X���[�����j
#ifdef D_OS_IS_WINDOWS
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Set_CMD_Number(in_cmd_show);
#endif


	// �����_�����OAPI�̐���
	M_Rendering_API_Init();

	// �Q�[���p�V�X�e���̏�����
	M_Game_Set_Up();


	// �f�o�b�O���Ȃ珉�����̐�����\���i���s���̓X���[�����j
#if _DEBUG
	M_Print_Log_Of_Succeeded_Init();
#endif // _DEBUG
	

	// �� ���C�����[�v �� //
	while (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		// �Q�[���̃v���Z�X�����s
		GAME::C_Game_Manager::M_Executes_Process();
	}


	// �� �I������ �� //
	M_Game_End();


	// �� �A�v������� �� //
	return 0;
}


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS�V�X�e���̐������s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void M_OS_Creat_System(void)
{
	// OS�𐶐�����@���s�ŏI��
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Creat_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�V�X�e���̐������s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void M_Rendering_API_Init(void)
{
	// OS�̏��������s���@���s�ŏI��
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_OS())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}


	// �����_�����OAPI�𐶐�����@���s�ŏI��
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_API())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���V�X�e���̏��������s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void M_Game_Set_Up(void)
{
	// ����܂ł̏��������������Ă��鎞�̂ݏ��������s��
	if (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		GAME::C_Game_Manager::M_Init();
	}

	return;
}



//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���̏I������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void M_Game_End(void)
{
	// �� �f�o�b�O���Ȃ�I����\�� �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "-��-��-��-��-��-��-��-�I�������s���ꂽ�̂ŃA�v���P�[�V�������~-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


	// �Q�[���̃��������
	GAME::C_Game_Manager::M_Release();

	// �����_�����O�p�̃A�v���P�[�V�������I������
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Relese_Graphics_API();

	return;
}


//-��- �f�o�b�O -��-//
#if _DEBUG

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̐�����\������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void M_Print_Log_Of_Succeeded_Init(void)
{
	// �������ɐ������Ă��Ȃ������甲����
	if (!GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		return;
	}

	// �� �f�o�b�O���Ȃ珉�����̐�����\�� �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�������I��-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();

	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�A�v���P�[�V�����J�n-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUI�̉�ʕ`����J�n���܂�");
#endif

	return;
}

#endif // _DEBUG


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

