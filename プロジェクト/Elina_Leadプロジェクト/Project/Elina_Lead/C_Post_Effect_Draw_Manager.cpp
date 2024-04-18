//����������������������������������������������//
// �ڍ�   �F�|�X�g�G�t�F�N�g�̕`�搧��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Post_Effect_Draw_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Post_Effect_Draw_Manager C_Post_Effect_Draw_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Post_Effect_Draw_Manager::C_Post_Effect_Draw_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Post_Effect_Draw_Manager::~C_Post_Effect_Draw_Manager(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�̑O�ɕ`�悷��|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�����
// ����   �FC_Post_Effect_Base * �ǉ�����|�X�g�G�t�F�N�g
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * in_add_post_effect)
{
	// UI�`��O�ɕ`�悵�Ȃ��|�X�g�G�t�F�N�g�͕`�惊�X�g�ɒǉ����Ȃ�
	if (in_add_post_effect->M_Get_Flg_Post_Effect_Before_UI_Draw() == false)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	int set_post_effect_slot = (int)m_this.mpr_variable.post_effect_before_ui_list.size();	// �|�X�g�G�t�F�N�g�̒ǉ���X���b�g


	// �|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�
	m_this.mpr_variable.post_effect_before_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_before_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�̑O�ɕ`�悷��|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�����
// ����   �FC_Post_Effect_Base * �ǉ�����|�X�g�G�t�F�N�g
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base* in_add_post_effect)
{
	// UI�`���ɕ`�悵�Ȃ��|�X�g�G�t�F�N�g�͕`�惊�X�g�ɒǉ����Ȃ�
	if (in_add_post_effect->M_Get_Flg_Post_Effect_After_UI_Draw() == false)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	int set_post_effect_slot = (int)m_this.mpr_variable.post_effect_after_ui_list.size();	// �|�X�g�G�t�F�N�g�̒ǉ���X���b�g


	// �|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�
	m_this.mpr_variable.post_effect_after_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_after_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�̑O�̃|�X�g�G�t�F�N�g��`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_Before_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_before_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}

	
	// UI�`��O�ɕ`�悷��|�X�g�G�t�F�N�g�̃��X�g
	m_this.mpr_variable.post_effect_before_ui_list.clear();
	m_this.mpr_variable.post_effect_before_ui_list.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�̌�̃|�X�g�G�t�F�N�g��`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_After_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_after_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}


	// UI�`���ɕ`�悷��|�X�g�G�t�F�N�g�̃��X�g
	m_this.mpr_variable.post_effect_after_ui_list.clear();
	m_this.mpr_variable.post_effect_after_ui_list.shrink_to_fit();

	return;
}


