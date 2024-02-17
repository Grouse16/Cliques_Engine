//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃e�X�N�`�����\�[�X�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�e�X�N�`���o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Texture_Resource.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace  RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�X�N�`�����\�[�X�p�̏��𐶐�����
// ����   �Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & �ݒ��̃e�X�N�`�����\�[�X�̎Q��, const S_Create_Texture_Setting_Inform & �e�X�N�`�����\�[�X�𐶐����邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Texture_Resource::M_Create_Texture_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & out_result_texture_resource, const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & in_create_texture_resource_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Texture_Inform(out_result_texture_resource, in_create_texture_resource_inform);
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�X�N�`�����\�[�X��`��p�ɃZ�b�g����
// ����   �FS_Texture_Buffer_Drawing_Setting & �e�X�N�`�����\�[�X�p�`��ݒ�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Texture_Resource::M_Set_Texture_Resource_To_Draw(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & in_draw_texture_resource)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Texture(in_draw_texture_resource);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ԍ��̃��\�[�X�X���b�g�Ƀe�X�N�`���f�[�^���Z�b�g����
// ����   �Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & �Z�b�g����e�X�N�`�����\�[�X�̎Q��, int �Z�b�g��̃��\�[�X�X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Texture_Resource::M_Set_Texture_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_draw_texture_resource, int in_slot_number)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Texture_By_Index(in_draw_texture_resource, in_slot_number);

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�X�N�`�������[�h����
// ����   �Fstring ���[�h����e�N�X�`���܂ł̃p�X, C_Texture_Map & ���[�h��̃e�N�X�`���}�b�v�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Texture_Resource::M_Load_Texture(std::string in_load_texture_path, ASSET::TEXTURE::C_Texture_Map & out_result_texture)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Load_Texture(in_load_texture_path, out_result_texture);
}
