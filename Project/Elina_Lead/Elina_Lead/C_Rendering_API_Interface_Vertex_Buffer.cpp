//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒��_�o�b�t�@�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F���_�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Vertex_Buffer.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^�p�̏��𐶐�����
// ����   �Funique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & �ݒ��̒��_�o�b�t�@�̎Q��,�@const S_Create_Vertex_Buffer_Inform & �������邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Buffer::M_Create_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & out_result_vertex_buffer, const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & in_create_vertex_buffer_inform)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(out_result_vertex_buffer, in_create_vertex_buffer_inform);

    return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^��`��p�ɃZ�b�g����
// ����   �Funique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & �Z�b�g���钸�_�o�b�t�@
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Buffer::M_Set_Vertex_Buffer_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & in_set_vertex_buffer)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Vertex_Buffer(in_set_vertex_buffer);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�o�b�t�@�����ɕ`������s����
// ����   �Funique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & �`�悷�钸�_�o�b�t�@
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Vertex_Buffer::M_Draw_By_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & in_draw_vertex_buffer)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Vertex_Buffer(in_draw_vertex_buffer);

    return;
}
