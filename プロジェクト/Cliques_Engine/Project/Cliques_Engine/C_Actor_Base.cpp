//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Actor_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::ACTOR::BASE;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �R���|�[�l���g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃R���|�[�l���g���폜����
// ����   �Fstring �폜����R���|�[�l���g��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// �w�肳�ꂽ�����ʂ�̃C���X�^���X���폜����
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// �R���|�[�l���g�̖��O����v������̂��폜
			[in_delete_ui_component_name](S_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_component_list.end()
	);

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Actor_Base::C_Actor_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Actor_Base::~C_Actor_Base(void)
{
	m_component_list.clear();
	m_component_list.shrink_to_fit();

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���|�[�l���g�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Base::M_Component_Update(void)
{
	for (S_Component_Inform & now_component : m_component_list)
	{
		now_component.component->M_Update();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�폜�̃t���O�������Ă���R���|�[�l���g���폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Base::M_Delete_Component_Update(void)
{
	// �w�肳�ꂽ�����ʂ�̃C���X�^���X���폜����
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// �폜�̃t���O�������Ă���R���|�[�l���g���폜
			[](S_Component_Inform& in_component_inform)
			{
				if (in_component_inform.component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.component.reset();

					return true;
				}

				return false;
			}
		),

		m_component_list.end()
	);

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�N�^�[��`�悷�邩�ǂ����̃t���O���Z�b�g����
// ����   �Fbool �A�N�^�[���Z�b�g���邩�ǂ����̃t���O
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Base::M_Set_Draw_Flg(bool in_set_draw_flg)
{
	m_draw_flg = in_set_draw_flg;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O���Z�b�g����
// ����   �Fbool �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O�Atrue�̎��̂ݕ`�悷��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Actor_Base::M_Set_After_Draw_Flg(bool in_after_draw_flg)
{
	m_after_draw_flg = in_after_draw_flg;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ�
// ����   �Fvoid
// �߂�l �Fbool �A�N�^�[��`�悷�邩�ǂ����̃t���O�Atrue�͕`�悷��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Actor_Base::M_Get_Draw_Flg(void)
{
	return m_draw_flg;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ�
// ����   �Fvoid
// �߂�l �Fbool �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O�Atrue�͕`�悷��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Actor_Base::M_Get_After_Draw_Flg(void)
{
	return m_after_draw_flg;
}

