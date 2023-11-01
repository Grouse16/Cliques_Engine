//����������������������������������������������//
// �ڍ�   �F�����_�����O�p�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�����_�����O�p���̐ݒ���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Setting_System_For_Engine.h"
#include "C_Rendering_Graphics_API_Base.h"

#include "C_Creat_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Setting_System_For_Engine::C_Rendering_Setting_System_For_Engine(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Setting_System_For_Engine::~C_Rendering_Setting_System_For_Engine(void)
{
	M_Delete();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Setting_System_For_Engine::M_Delete(void)
{
	mpr_variable.rendering_setting_inform.reset();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����p�̏������ɐ�������
// ����   �Fint �g�p����V�F�[�_�[�Z�b�g�̔ԍ�
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_Setting_System_For_Engine::M_Creat_Pipeline_Setting(int in_shader_set)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREAT::C_Creat_Rendering_Graphics_Setting_Inform creat_inform;	// �����p���


	// �����p�̏���ݒ肵�Đ�������
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Creat_Rendering_Graphics_Inform(mpr_variable.rendering_setting_inform, creat_inform) == false)
	{
		return false;	// ���s������G���[�Ŕ�����
	}

	return true;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�ɂ��̃����_�����O�ݒ��K�p����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Setting_System_For_Engine::M_Set_Rendering_Setting_For_API(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(mpr_variable.rendering_setting_inform);

	return;
}


