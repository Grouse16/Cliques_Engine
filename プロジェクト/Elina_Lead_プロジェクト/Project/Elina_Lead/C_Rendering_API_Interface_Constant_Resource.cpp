//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒萔���\�[�X�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�萔�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Constant_Resource.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �N���X �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔���\�[�X�p�̏��𐶐�����
// ����   �Funique_ptr<C_Rendering_Constant_Buffer_Setting_Inform_Base> & �ݒ��̒萔���\�[�X�̎Q��, const S_Create_Constant_Buffer_Inform & �萔���\�[�X�𐶐����邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & out_result_constant_buffer, const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & in_create_constant_resource_inform)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Constant_Inform(out_result_constant_buffer, in_create_constant_resource_inform);

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔���\�[�X��`��p�ɃZ�b�g����
// ����   �FS_Constant_Buffer_Drawing_Setting & �萔���\�[�X�p�`��ݒ�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & in_draw_constant_buffer)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Constant_Buffer(in_draw_constant_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ԍ��̃��\�[�X�X���b�g�ɒ萔�f�[�^���Z�b�g����
// ����   �Funique_ptr<C_Rendering_Constant_Buffer_Setting_Inform_Base> & �Z�b�g����萔���\�[�X�̎Q��, int �Z�b�g��̃��\�[�X�X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & in_draw_constant_resource, int in_set_slot_number)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Constant_Buffer_By_Index(in_draw_constant_resource, in_set_slot_number);

	return;
}
