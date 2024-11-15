//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�̕`�搧�������N���X
// ����   �F�A�N�^�[��`�悷�邩�ǂ����̃t���O��A������J�����Ƃ̈ʒu�֌W����̃J�����O�Ȃǂ��s���ĕ`�悷��I�u�W�F�N�g���܂Ƃ߂Ď���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Actor_Draw_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::ACTOR::DRAW_MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Actor_Draw_Manager C_Actor_Draw_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Actor_Draw_Manager::C_Actor_Draw_Manager(void)
{
	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����O�̏��������s����
// ����   �FC_Actor_Base * �J�����O�̔�����s���A�N�^�[�̃A�h���X
// �߂�l �Fbool �`�悷�鎞�̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Actor_Draw_Manager::M_Culling_Calculation(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_draw_actor)
{
	// �`�悷��
	return true;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Actor_Draw_Manager::~C_Actor_Draw_Manager(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`�惊�X�g�ɃA�N�^�[��ǉ�����
// ����   �FC_Actor_Base * �ǉ�����A�N�^�[�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Draw_Manager::M_Set_Actor_To_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_set_actor)
{
	// �A�N�^�[���`�悵�Ȃ���ԂɂȂ��Ă�����`�悵�Ȃ�
	if (in_set_actor->M_Get_Draw_Flg() == false)
	{
		return;
	}


	// �A�N�^�[���J�����O�ɂ���ĕ`�悳��Ȃ��ꍇ�͕`�惊�X�g�ɒǉ����Ȃ�
	if (M_Culling_Calculation(in_set_actor) == false)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	int actor_slot = (int)m_this.mpr_variable.draw_actor_list.size();	// �A�N�^�[�̒ǉ���X���b�g�ԍ�


	// �A�N�^�[��`��V�X�e�����ɒǉ�����
	m_this.mpr_variable.draw_actor_list.resize(actor_slot + 1);
	m_this.mpr_variable.draw_actor_list[actor_slot] = in_set_actor;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`�惊�X�g�ɃA�N�^�[��ǉ�����
// ����   �FC_Actor_Base * �ǉ�����A�N�^�[�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Draw_Manager::M_Set_Actor_To_After_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_set_actor)
{
	// �A�N�^�[���`�悵�Ȃ���ԂɂȂ��Ă�����`�悵�Ȃ�
	if (in_set_actor->M_Get_After_Draw_Flg() == false)
	{
		return;
	}


	// �A�N�^�[���J�����O�ɂ���ĕ`�悳��Ȃ��ꍇ�͕`�惊�X�g�ɒǉ����Ȃ�
	if (M_Culling_Calculation(in_set_actor) == false)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	int actor_slot = (int)m_this.mpr_variable.after_draw_actor_list.size();	// �A�N�^�[�̒ǉ���X���b�g�ԍ�


	// �A�N�^�[��`��V�X�e�����ɒǉ�����
	m_this.mpr_variable.after_draw_actor_list.resize(actor_slot + 1);
	m_this.mpr_variable.after_draw_actor_list[actor_slot] = in_set_actor;

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`�惊�X�g���̃A�N�^�[��`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Draw_Manager::M_Draw_Actor_In_Draw_List(void)
{
	for (GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * draw_actor : m_this.mpr_variable.draw_actor_list)
	{
		draw_actor->M_Actor_Draw();
	}


	// �`�悷��A�N�^�[�̃��X�g������������
	m_this.mpr_variable.draw_actor_list.clear();
	m_this.mpr_variable.draw_actor_list.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�`���̕`�惊�X�g���̃A�N�^�[��`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Draw_Manager::M_Draw_Actor_In_After_Draw_List(void)
{
	for (GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * after_draw_actor : m_this.mpr_variable.after_draw_actor_list)
	{
		after_draw_actor->M_Actor_After_Draw();
	}


	// �ʏ�`���ɕ`�悷��A�N�^�[�̃��X�g������������
	m_this.mpr_variable.after_draw_actor_list.clear();
	m_this.mpr_variable.after_draw_actor_list.shrink_to_fit();

	return;
}

