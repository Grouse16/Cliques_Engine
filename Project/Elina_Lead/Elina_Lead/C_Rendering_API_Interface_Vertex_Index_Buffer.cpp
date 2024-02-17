//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒��_�C���f�b�N�X�o�b�t�@�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F���_�C���f�b�N�X�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Vertex_Index_Buffer.h"
#include "C_Rendering_API_Base.h"


// ���@�l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�p�̏��𐶐�����
// ����   �Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & �ݒ��̒��_�C���f�b�N�X�o�b�t�@�̎Q��, const S_Create_Index_Buffer_Inform & ���_�C���f�b�N�X�o�b�t�@�����p�̏��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Create_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & out_result_vertex_buffer, const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & in_create_vertex_index_buffer_inform)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Index_Inform(out_result_vertex_buffer, in_create_vertex_index_buffer_inform);

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@�����Ɏw�肳�ꂽ���_�C���f�b�N�X�Ԃ̕`����s��
// ����   �Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & �ݒ��̒��_�C���f�b�N�X�o�b�t�@�̎Q��, int �`��J�n�ʒu�̒��_�C���f�b�N�X�ԍ�, int �`��I���ʒu�̒��_�C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer_By_Range(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_draw_index_buffer, int in_start_index_slot, int in_end_index_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer_By_Range(in_draw_index_buffer, in_start_index_slot, in_end_index_slot);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@�����ɕ`����s��
// ����   �Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & �ݒ��̒��_�C���f�b�N�X�o�b�t�@�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_draw_index_buffer)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer(in_draw_index_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@���Z�b�g����
// ����   �Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & ���_�C���f�b�N�X�f�[�^�ݒ�p���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Set_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_set_index_inform)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Index_Buffer(in_set_index_inform);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Z�b�g���ꂽ���_�C���f�b�N�X�o�b�t�@�����ɕ`����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_Command_By_Set_Index_Buffer(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Set_Index_Buffer();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Z�b�g���ꂽ���_�C���f�b�N�X�o�b�t�@�����Ɏw�肳�ꂽ�C���f�b�N�X�Ԃ̕`����s��
// ����   �Fint �`����J�n����C���f�b�N�X�ԍ�, int �`��I���̃C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_Command_By_Set_Index_Buffer_By_Range(int in_start_index_number, int in_end_index_number)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Set_Index_Buffer_By_Range(in_start_index_number, in_end_index_number);

	return;
}
