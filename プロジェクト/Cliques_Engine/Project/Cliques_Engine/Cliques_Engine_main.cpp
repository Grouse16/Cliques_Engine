//����������������������������������������������//
// �ڍ�   �FCliques Engine�̃��C���֐���
// ����   �F�����Ń��C�����[�v��Z�b�g�A�b�v���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �}�N�� �� //

// �f�o�b�O���s�����߂̃��O�V�X�e���̃}�N��
#define _CRTDBG_MAP_ALLOC


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Manager.h"
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"

#include "C_Console_Log_Interface.h"


// �� �֐� �� //

//-��- �������ƏI���� -��-//

// OS�V�X�e���̐������s��
void M_OS_Create_System(void);

// �����_�����OAPI�̏��������s��
void M_Rendering_API_Init(void);

// �Q�[���V�X�e���̏��������s��
void M_Game_Set_Up(void);

// �Q�[���̏I������
void M_Game_End(void);


//-��- �f�o�b�O���O -��-//

// �������̐�����\������
void M_Print_Log_Of_Succeeded_Init(void);


// �� ���C���֐� �� //

// ���C���֐��i�G���g���[�|�C���g�j
int main(void)
{
	// �� ������ �� //
	
	// OS�p�V�X�e���̐���
	M_OS_Create_System();

	// �����_�����OAPI�̐���
	M_Rendering_API_Init();

	// �Q�[���p�V�X�e���̏�����
	M_Game_Set_Up();

	// �f�o�b�O���͏������������̂ݐ����̃��O���c��
	M_Print_Log_Of_Succeeded_Init();


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
void M_OS_Create_System(void)
{
	// OS�𐶐�����@���s�ŏI��
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
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
	// OS����V�X�e�������������ă����_�����OAPI�𐶐�����@���s�ŏI��
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API())
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
	// �I�������s���ꂽ�̂ŃA�v���P�[�V�������~�����m
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "-��-��-��-��-��-��-��-�I�������s���ꂽ�̂ŃA�v���P�[�V�������~-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	// �Q�[���̃��������
	GAME::C_Game_Manager::M_Release();

	// �����_�����O�p�̃A�v���P�[�V�������I������
	PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API();

	return;
}


//-��- �f�o�b�O���O -��-//

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

	// �������̐����̃��O���c��
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�������I��-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-�A�v���P�[�V�����J�n-��-��-��-��-��-��-��-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUI�̉�ʕ`����J�n���܂�");

	return;
}




//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

