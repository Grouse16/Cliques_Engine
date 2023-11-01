//����������������������������������������������//
// �ڍ�   �F�G���W���̏�Ԃ����L���邽�߂̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_State_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::STATE;


// �� �ϐ��錾 �� //
std::unique_ptr<C_Game_State_Manager> C_Game_State_Manager::m_this;	// ���g���Ăяo�����߂̖��O


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_State_Manager::C_Game_State_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�X�e���𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_State_Manager::M_Init(void)
{
	m_this.reset(new C_Game_State_Manager);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_State_Manager::~C_Game_State_Manager(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_State_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃V�[�������Z�b�g����
// ����   �Fwstring �ݒ肷�錻�݂̃V�[����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_State_Manager::M_Set_Now_Engine_Scene_Name(std::wstring in_set_name)
{
	m_this->mpr_variable.now_engine_scene_name = in_set_name;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���ύX�v���̕ύX��V�[�������Z�b�g����
// ����   �Fwstring �V�[���ύX�v���̕ύX��V�[����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_State_Manager::M_Set_Execute_Change_Engine_Scene_Name(std::wstring in_set_name)
{
	m_this->mpr_variable.excute_change_engine_scene_name = in_set_name;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃V�[�����̎Q�Ƃ��擾����
// ����   �Fvoid
// �߂�l �Fconst wstring & ���݂̃V�[�����̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::wstring & C_Game_State_Manager::M_Get_Now_Engine_Scene_Name(void)
{
	return m_this->mpr_variable.now_engine_scene_name;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���ύX�v���̕ύX��V�[�����̎Q�Ƃ��擾����
// ����   �Fvoid
// �߂�l �Fconst wstring & �V�[���ύX�v���̕ύX��V�[�����̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::wstring & C_Game_State_Manager::M_Get_Execute_Change_Engine_Scene_Name(void)
{
	return m_this->mpr_variable.excute_change_engine_scene_name;
}


