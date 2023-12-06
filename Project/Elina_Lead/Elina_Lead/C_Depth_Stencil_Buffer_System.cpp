//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�[�x�X�e���V���o�b�t�@�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Depth_Stencil_Buffer_System.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Depth_Stencil_Buffer_System::C_Depth_Stencil_Buffer_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Depth_Stencil_Buffer_System::~C_Depth_Stencil_Buffer_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Release(void)
{
	if (mpr_variable.depth_stencil_buffer == nullptr)
	{
		return;
	}


	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Notice_Depth_Stencil_Buffer_Deleted(mpr_variable.depth_stencil_buffer.get());
	mpr_variable.depth_stencil_buffer.reset();
	
	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�����[�h����
// ����   �FE_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT �[�x�X�e���V���o�b�t�@�̃o�C�g�t�H�[�}�b�g
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Depth_Stencil_Buffer_System::M_Load_Depth_Stencil_Buffer(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT in_byte_format)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Depth_Stencil_Buffer_Inform create_depth_stencil_inform;	// �[�x�X�e���V���o�b�t�@�̐����p���



	// �� �[�x�X�e���V���o�b�t�@�̐����p����ݒ� �� //
	create_depth_stencil_inform.m_byte_format = in_byte_format;

	// �������Č��ʂ�Ԃ�
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Depth_Stencil_Buffer(mpr_variable.depth_stencil_buffer, create_depth_stencil_inform);
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@���N���A����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Clear_Depth_Stencil_Buffer(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(mpr_variable.depth_stencil_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@���w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����
// ����   �Fint �e�N�X�`���X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Texture_Slot(in_texture_slot, mpr_variable.depth_stencil_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�������_�����O��Ƃ��Đݒ肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Set_Depth_Stencil_Buffer_To_Render_Target(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(mpr_variable.depth_stencil_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@���e�N�X�`���ɕϊ�����
// ����   �FC_Texture_Map & �ݒ��̃e�N�X�`���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Save_Depth_Stencil_Buffer_To_Texture(ASSET::TEXTURE::C_Texture_Map & out_texture)
{
	mpr_variable.depth_stencil_buffer->M_Save_Screen_For_Texture(out_texture);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�����C���̐[�x�X�e���V���o�b�t�@�ɖ߂�
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Depth_Stencil_Buffer_System::M_Set_Main_Depth_Stencil_Buffer(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Main_Depth_Stencil_Buffer_To_Rendering();

	return;
}
