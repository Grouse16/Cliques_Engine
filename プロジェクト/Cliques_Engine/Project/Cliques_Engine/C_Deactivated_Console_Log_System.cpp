//����������������������������������������������//
// �ڍ�   �F�R���\�[�����O�p�̃V�X�e���𖳌�������N���X
// ����   �F�����[�X���ȂǃR���\�[�����O���s�v�ȏꍇ�Ɏg�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Deactivated_Console_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG::CONSOLE::DEACTIVATED;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Deactivated_Console_Log_System::C_Deactivated_Console_Log_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O�V�X�e���̏������Ɛ���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Init_Debug(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�V�X�e���������p�N���X�𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System(void)
{
	// �� �ϐ��錾 �� //
	C_Deactivated_Console_Log_System * deactivated_console_log_system = new C_Deactivated_Console_Log_System();	// ���������ꂽ�R���\�[�����O�V�X�e��


	// �f�o�b�O�V�X�e���̏�����
	deactivated_console_log_system->M_Init_Debug();

	// �V���O���g���̃C���X�^���X�𐶐�
	m_this.reset(deactivated_console_log_system);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Deactivated_Console_Log_System::~C_Deactivated_Console_Log_System(void)
{
	return;
}



//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�V�X�e�����폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
{
	return;
}


//-��- ���O�o�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���
// ����   �FE_CONSOLE_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_log_tags, std::string in_log_file_name, std::string in_print_text)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������~�߂ă��O���o��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̃��O������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Console_Log_Flush(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �����̐F, E_CONSOLE_LOG_COLOR �w�i�̐F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Deactivated_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_text_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	return;
}



