//����������������������������������������������//
// �ڍ�   �F�G���W���p�̃����_�����O�ݒ���Ǘ�����}�l�[�W���[
// ����   �F�G���W���Ɏg�p���郌���_�����O�p�C�v���C���ݒ�̏������Ǝg�p�𐧌䂷��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Engine_Rendering_Setting_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::DRAW;


// �� �ϐ��錾 �� //
C_Engine_Rendering_Setting_Manager::SPr_Variable C_Engine_Rendering_Setting_Manager::mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

C_Engine_Rendering_Setting_Manager C_Engine_Rendering_Setting_Manager::m_this;	// ���̃N���X���C���X�^���X�����邽�߂̕ϐ�


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�V���O���g�����̂��߂ɉB��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Rendering_Setting_Manager::C_Engine_Rendering_Setting_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������s��
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Engine_Rendering_Setting_Manager::M_Init(void)
{
	// �S�Ă̕`��p�ݒ������������@// ���s������G���[���o���Ĕ�����
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_OBJECT; loop_x++)
	{
		if (mpr_variable.rendering_setting_system_list[loop_x].M_Creat_Pipeline_Setting(loop_x) == false)
		{
			return false;
		}
	}

	// ����
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Rendering_Setting_Manager::~C_Engine_Rendering_Setting_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Rendering_Setting_Manager::M_Release(void)
{
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_SUM; loop_x++)
	{
		mpr_variable.rendering_setting_system_list[loop_x].M_Delete();
	}

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����_�����O�ݒ��`��ɓK�p����
// ����   �FE_RENDERING_SETTING_NUM �����_�����O�ݒ�̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Rendering_Setting_Manager::M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM in_rendering_setting_num)
{
	mpr_variable.rendering_setting_system_list[(int)in_rendering_setting_num].M_Set_Rendering_Setting_For_API();

	return;
}
