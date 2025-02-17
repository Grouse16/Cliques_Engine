//����������������������������������������������//
// �ڍ�   �FUI�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_User_Interface_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE::UI::BASE;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �R���|�[�l���g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O��UI�̃R���|�[�l���g���폜����
// ����   �Fstring �폜����R���|�[�l���g��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_User_Interface_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// �w�肳�ꂽ�����ʂ�̃C���X�^���X���폜����
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// �R���|�[�l���g�̖��O����v������̂��폜
			[in_delete_ui_component_name](S_UI_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_ui_component_list.end()
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
C_User_Interface_Base::C_User_Interface_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_User_Interface_Base::~C_User_Interface_Base(void)
{
	m_ui_component_list.clear();
	m_ui_component_list.shrink_to_fit();

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���|�[�l���g�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_User_Interface_Base::M_Update_Component(void)
{
	for (S_UI_Component_Inform & m_component_list : m_ui_component_list)
	{
		m_component_list.ui_component->M_Update();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�폜�̃t���O�������Ă���R���|�[�l���g���폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_User_Interface_Base::M_Delete_Component_Update(void)
{
	// �w�肳�ꂽ�����ʂ�̃C���X�^���X���폜����
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// �폜�̃t���O�������Ă���R���|�[�l���g���폜
			[](S_UI_Component_Inform& in_component_inform)
			{
				if (in_component_inform.ui_component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.ui_component.reset();

					return true;
				}

				return false;
			}
		),

		m_ui_component_list.end()
	);

	return;
}

