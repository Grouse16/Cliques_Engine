//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̐[�x�X�e���V���p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�[�x�X�e���V���ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Depth_Stencil.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�𐶐�����
// ����   �Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & �ݒ��̐[�x�X�e���V���o�b�t�@�̎Q��, const S_Create_Depth_Stencil_Buffer_Inform & �[�x�X�e���V���o�b�t�@�𐶐����邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Depth_Stencil::M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & out_result_stencil_buffer, const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & in_create_stencil_buffer)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Depth_Stencil_Buffer(out_result_stencil_buffer, in_create_stencil_buffer);
}


//-��- ��� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�̍폜��ʒm����
// ����   �Fconst C_Rendering_Depth_Stencil_Buffer_Base * �폜���ꂽ�[�x�X�e���V���o�b�t�@�̃A�h���X�iconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Depth_Stencil::M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * in_delete_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Notice_Depth_Stencil_Buffer_Deleted(in_delete_depth_stencil_view);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�����Z�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Depth_Stencil::M_Reset_Draw_Depth_Stencil_Buffer(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Reset_Depth_Stencil_Buffer();

	return;
}


//-��- �N���A -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@���N���A����
// ����   �Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & �N���A����[�x�X�e���V���o�b�t�@�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Depth_Stencil::M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_clear_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Clear_Depth_Stencil_Buffer(in_clear_depth_stencil_view);

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@��`��p�ɃZ�b�g����
// ����   �Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & �ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Depth_Stencil::M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_set_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(in_set_depth_stencil_view);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@��GPU�p���\�[�X�̃e�N�X�`���X���b�g�ɃZ�b�g
// ����   �Fint �ݒ��̃X���b�g�ԍ�, unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & �ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Depth_Stencil::M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int in_slot, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_set_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Texture_Slot(in_slot, in_set_depth_stencil_view);

	return;
}

