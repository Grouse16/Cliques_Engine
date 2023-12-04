//����������������������������������������������//
// �ڍ�   �F�����_�����O�摜���~���ɐݒ肵�A�g�p���邽�߂̃V�X�e��
// ����   �F�����_�����OAPI�Ƃ̘A�g��A���G�Ȓ��ۉ����C���[�̃V�X�e���̃J�v�Z�������s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Screen_System.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Screen_System::C_Rendering_Screen_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_Screen_System::~C_Rendering_Screen_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ��폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Release(void)
{
	mpr_variable.rendering_screen.reset();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ𐶐�����
// ����   �Fint ��ʐ�, E_RENDERING_SCREEN_FORMAT ��ʂ̃o�C�g��, E_SCREEN_TEXTURE_SETTING ��ʂ̃e�N�X�`���ݒ�
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_Screen_System::M_Create_Rendering_Screen(int in_screen_sum, RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT in_screen_format, RENDERING::GRAPHICS::CREATE::E_SCREEN_TEXTURE_SETTING in_texture_setting)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Render_Screen_Inform create_screen_inform;	// �����_�����O��ʐ������
	

	// ��ʐ�
	create_screen_inform.m_screen_buffer_sum = in_screen_sum;

	// ��ʂ̃o�C�g��
	create_screen_inform.m_rendering_screen_format = in_screen_format;

	// ��ʂ̃e�N�X�`���ݒ�
	create_screen_inform.m_screen_texture_setting = in_texture_setting;

	// �������Č��ʂ�Ԃ�
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Rendering_Screen(mpr_variable.rendering_screen, create_screen_inform);
}


//-��- �e�N�X�`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����
// ����   �Fint �����_�����O��ʔԍ�, C_Texture_Map & �ۑ���̃e�N�X�`����ʂ̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_rendering_screen_num, ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Save_Rendering_Screen_To_Texture(in_rendering_screen_num, mpr_variable.rendering_screen, in_texture_map);

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�摜��`���Ƃ��Đݒ肷��
// ����   �Fint �ݒ肷�郌���_�����O�摜�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Set_Render_Target(int in_screen_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Render_Target(in_screen_number, mpr_variable.rendering_screen);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʂ��N���A����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Clear_Screen(void)
{
	// �� �ϐ��錾 �� //
	int rendering_screen_sum = mpr_variable.rendering_screen->M_Get_Rendering_Screen_Sum();	// �����_�����O�摜��


	for (int l_screen_number = 0; l_screen_number < rendering_screen_sum; l_screen_number++)
	{
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(l_screen_number, mpr_variable.rendering_screen);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʂ��N���A����
// ����   �Fint �N���A�����ʔԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Clear_Screen_By_Number(int in_screen_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(in_screen_number, mpr_variable.rendering_screen);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�e�N�X�`���̃X���b�g�ԍ��Ƀ����_�����O��ʂ̉摜���Z�b�g����
// ����   �Fint �Z�b�g�����ʔԍ�, int �Z�b�g����X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_Screen_System::M_Set_Rendering_Screen_To_Texture_Slot(int in_screen_number, int in_slot_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Texture_Slot(in_screen_number, in_slot_number, mpr_variable.rendering_screen);

	return;
}

