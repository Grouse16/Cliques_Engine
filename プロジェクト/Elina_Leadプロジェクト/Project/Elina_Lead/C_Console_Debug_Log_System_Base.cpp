//����������������������������������������������//
// �ڍ�   �F�f�o�b�O���O�V�X�e���̊��N���X�p�̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Console_Debug_Log_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG::CONSOLE::BASE;


// �� �ÓI�ϐ��錾 �� //
std::unique_ptr<C_Console_Debug_Log_System_Base> C_Console_Debug_Log_System_Base::m_this;	// ���N���X�ւ̃A�N�Z�X�p�̕ϐ�

C_Console_Debug_Log_System_Base::Pr_Variable C_Console_Debug_Log_System_Base::mpr_variable;	// �v���C�x�[�g�ϐ��ւ̃A�N�Z�X�p�̕ϐ�


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Console_Debug_Log_System_Base::C_Console_Debug_Log_System_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Console_Debug_Log_System_Base::~C_Console_Debug_Log_System_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�V�X�e�����������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Console_Debug_Log_System_Base::M_Release(void)
{
	// ���łɂȂ��ꍇ�͍폜����K�v�͂Ȃ�
	if (m_this == nullptr)
	{
		return;
	}

	// �������
	m_this.release();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[�����O�V�X�e���̃C���X�^���X�̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Console_Debug_Log_System_Base * �R���\�[�����O�V�X�e���̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Console_Debug_Log_System_Base * C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System(void)
{
	return m_this.get();
}
