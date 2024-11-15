//����������������������������������������������//
// �ڍ�   �F�R���\�[�����O���o�͂��邽�߂̃C���^�[�t�F�[�X
// ����   �F�R���\�[�����O�̐����⏉�����A�o�́A������ȗ������A�ˑ��֌W��؂藣�����߂̃C���^�[�t�F�[�X
// �쐬�� �F���◴��
//����������������������������������������������//


//-��- �t�@�C���Ђ炫 -��-//
#include "C_Console_Log_Interface.h"
#include "Platform_Detector_Macro.h"

#include "C_Deactivated_Console_Log_System.h"


// �E�B���h�E�Y�p�̃R���\�[�����O�V�X�e�����Ђ炭�i�f�o�b�O���̂݁j
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_Console_Log_System.h"

// OpenGL���p�̃R���\�[�����O�V�X�e�����Ђ炭�i�f�o�b�O���̂݁j
#elif D_OS_IS_MAC | D_OS_IS_LINUX | D_OS_IS_UNIX

#endif


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG::CONSOLE;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Console_Log_Interface::C_Console_Log_Interface(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�N���X�𐶐�����A�n�r��r���h���̐ݒ�ŕ��򂷂�
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Create_And_Initialize_Console_Log_System(void)
{
	// �f�o�b�O���̓R���\�[�����O�V�X�e���𐶐�����
#ifdef _DEBUG

	// �E�B���h�E�Y�p�̃R���\�[�����O�V�X�e���𐶐�����
#ifdef D_OS_IS_WINDOWS
	DEBUGGER::LOG::CONSOLE::WINDOWS::C_Windows_Console_Log_System::M_Create_Windows_Console_Debug_Log_System();

	// OpenGL���p�̃R���\�[�����O�V�X�e���𐶐�����
#elif D_OS_IS_MAC | D_OS_IS_LINUX | D_OS_IS_UNIX


	// �s���ȏꍇ�͖���������
#else 
	DEBUGGER::LOG::CONSOLE::DEACTIVATED::C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System();

#endif // D_OS_IS_WINDOWS


// �����[�X���͖���������
#else
	DEBUGGER::LOG::CONSOLE::DEACTIVATED::C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System();

#endif // _DEBUG

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�V�X�e�����폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Delete_Console_Log_System(void)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������Ȃ�폜����K�v�͂Ȃ�
	if (debug_console_log_system_address == nullptr)
	{
		return;
	}


	// �f�o�b�O���O�V�X�e�����폜����
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Release();

	return;
}


//-��- �o�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���
// ����   �FE_CONSOLE_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_tag, std::string in_file_name, std::string in_text)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŃ��O�o�͂�v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// �f�o�b�O���O���o�͂���
	debug_console_log_system_address->M_Print_Log(in_tag, in_file_name, in_text);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������~�߂ă��O���o��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Stop_Update_And_Log_Present(void)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŃ��O�o�͂�v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// ���O��\������
	debug_console_log_system_address->M_Stop_Update_And_Log_Present();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[����ʂɏo�͒��̃��O���t���b�V���i�������j����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Console_LOG_Flush(void)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŃ��O�t���b�V����v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// ���O���t���b�V������
	debug_console_log_system_address->M_Console_Log_Flush();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_text_color)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base* debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŐF�ύX��v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}


	// �e�L�X�g�J���[��ύX����
	debug_console_log_system_address->M_Set_Console_Text_Color(in_text_color);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base* debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŐF�ύX��v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	
	// �w�i�J���[��ύX����
	debug_console_log_system_address->M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����Ɣw�i�J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �����̐F, E_CONSOLE_LOG_COLOR �w�i�̐F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_text_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	// �� �ϐ��錾 �� //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// �R���\�[�����O�V�X�e���̃A�h���X


	// �������������̏�ԂŐF�ύX��v�����ꂽ�琶������
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}


	// �e�L�X�g�J���[��ύX����
	debug_console_log_system_address->M_Set_Console_Color_Text_And_Back(in_text_color, in_back_color);

	return;
}


