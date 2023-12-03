//����������������������������������������������//
// �ڍ�   �F�����_�����O�p�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�����_�����O�p���̐ݒ���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Setting_System.h"
#include "C_Rendering_Graphics_API_Base.h"

#include "C_Create_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Setting_System::C_Rendering_Setting_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Setting_System::~C_Rendering_Setting_System(void)
{
	M_Delete();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Setting_System::M_Delete(void)
{
	mpr_variable.rendering_setting_inform.reset();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����p�̏������ɐ�������
// ����   �Fconst RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform �����_�����O�ݒ萶���p���(const)
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_Setting_System::M_Create_Pipeline_Setting(const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform& in_create_inform)
{
	// �����p�̏���ݒ肵�Đ�������
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Rendering_Graphics_Inform(mpr_variable.rendering_setting_inform, in_create_inform);
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�ɂ��̃����_�����O�ݒ��K�p����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Setting_System::M_Set_Rendering_Setting_For_API(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(mpr_variable.rendering_setting_inform);

	return;
}


