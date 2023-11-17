//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͂̓����蔻��𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#include "C_Game_Input_Collision_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INPUT::COLLISION;


// �� �X�^�e�B�b�N�ϐ� �� //
std::unique_ptr<C_Game_Input_Collision_Manager> C_Game_Input_Collision_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Input_Collision_Manager::C_Game_Input_Collision_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���̓��̓{�b�N�X����p�V�X�e���̐���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Input_Collision_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Input_Collision_Manager);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Input_Collision_Manager::~C_Game_Input_Collision_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Input_Collision_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͔���̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<C_Game_Input_Collision * > & ���͔���̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<C_Game_Input_Collision * > & C_Game_Input_Collision_Manager::M_Get_Input_Collision_List(void)
{
	return m_this->mpr_variable.collision_list;
}


//-��- ���X�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���͔���̃A�h���X���Ǘ��p���X�g�ɒǉ�����
// ����   �FC_Game_Input_Collision * ���X�g�ɒǉ�������͔���̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * in_add_input_box)
{
	m_this->mpr_variable.collision_list.reserve(m_this->mpr_variable.collision_list.size() + 1);
	m_this->mpr_variable.collision_list.emplace_back(in_add_input_box);

	// �D��x�����ɍ~���Ƀ\�[�g����
	std::sort
	(
		m_this->mpr_variable.collision_list.begin(),	// �\�[�g�̊J�n
		m_this->mpr_variable.collision_list.end(),		// �\�[�g�̂����

		// �����_���A�E�̗v�f�����̗v�f�����l���傫����΁A���Ԃ����ւ���
		[](C_Game_Input_Collision * & left_function, C_Game_Input_Collision * & right_function)
		{
			return left_function->M_Get_Priority() >= right_function->M_Get_Priority();
		}
	);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���͔���̃A�h���X���Ǘ��p���X�g����폜����
// ����   �FC_Game_Input_Collision * ���X�g����폜������͔���̃A�h���X
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * in_delete_input_box)
{
	m_this->mpr_variable.collision_list.erase(std::remove(m_this->mpr_variable.collision_list.begin(), m_this->mpr_variable.collision_list.end(), in_delete_input_box), m_this->mpr_variable.collision_list.end());
	m_this->mpr_variable.collision_list.shrink_to_fit();

	return;
}
