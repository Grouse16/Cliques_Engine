//����������������������������������������������//
// �ڍ�   �F�����[�X���̂��߂̃��O�V�X�e���̒�`���s��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �f�o�b�O���͖��� �� //
#ifndef _DEBUG


// �� �t�@�C���Ђ炫 �� //
#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG;


// �� �ϐ��錾 �� //
C_Log_System C_Log_System::m_this;	// ���N���X�ւ̃A�N�Z�X�p�̕ϐ�
C_Log_System::Pr_Variable C_Log_System::mpr_variable;	// �v���C�x�[�g�ϐ��ւ̃A�N�Z�X�p�̕ϐ�


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Log_System::C_Log_System(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O�V�X�e���̏�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Init_Debug(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Log_System::~C_Log_System(void)
{
	return;
}


//-��- ���O�o�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���O���o�͂���
// ����   �FC_Log_System::E_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Print_Log(E_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[�����݂邽�߂ɏ������~�߂ē��̓o�b�t�@��S�ăN���A��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Stop_Update_And_Log_Present(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̃��O������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Console_LOG_Flush(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR in_set_color)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR in_set_color)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_LOG_COLOR �e�L�X�g�̐F�ԍ�, E_LOG_COLOR �w�i�̐F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Color_Text_And_Back(E_LOG_COLOR in_txt_color, E_LOG_COLOR in_back_color)
{
	return;
}


#endif // !_DEBUG

