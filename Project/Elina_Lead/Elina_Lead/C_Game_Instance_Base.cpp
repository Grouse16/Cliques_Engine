//����������������������������������������������//
// �ڍ�   �F�Q�[���C���X�^���X�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::BASE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Instance_Base::C_Game_Instance_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Instance_Base::~C_Game_Instance_Base(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�C���X�^���X����ݒ肷��
// ����   �Fstring �ݒ肷��C���X�^���X�̖��O
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Instance_Base::M_Set_Instance_Name(std::string in_set_name)
{
	m_name = in_set_name;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�폜�̎��s��\������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Instance_Base::M_Get_Destroy_Instance_Flg(void)
{
	return m_flg_destroy_instance;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�C���X�^���X���̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst std::string & �C���X�^���X��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::string & C_Game_Instance_Base::M_Get_Instance_Name(void)
{
	return m_name;
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�폜�̎��s��\������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Instance_Base::M_Destroy(void)
{
	m_flg_destroy_instance = true;

	return;
}


