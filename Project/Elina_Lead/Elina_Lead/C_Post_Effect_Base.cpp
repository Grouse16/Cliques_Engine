//����������������������������������������������//
// �ڍ�   �F�|�X�g�G�t�F�N�g�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// ���@�t�@�C���Ђ炫 �� //
#include "C_Post_Effect_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::POST_EFFECT::BASE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Post_Effect_Base::C_Post_Effect_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Post_Effect_Base::~C_Post_Effect_Base(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�`��O�Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O���Z�b�g����
// ����   �Fbool true�ŕ`�悷��Afalse�͕`�悵�Ȃ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_Before_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_before_ui = in_set_draw_flg;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�`���Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O���Z�b�g����
// ����   �Fbool true�ŕ`�悷��Afalse�͕`�悵�Ȃ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_After_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_after_ui = in_set_draw_flg;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�`��O�Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O��Ԃ�
// ����   �Fvoid
// �߂�l �Fbool true�ŕ`�悷��Afalse�͕`�悵�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_Before_UI_Draw(void)
{
	return m_flg_draw_before_ui;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�`���Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O��Ԃ�
// ����   �Fvoid
// �߂�l �Fbool true�ŕ`�悷��Afalse�͕`�悵�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_After_UI_Draw(void)
{
	return m_flg_draw_after_ui;
}
