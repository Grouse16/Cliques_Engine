//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃����_�����O��ʗp�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�����_�����O��ʂɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Rendering_Screen.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʃV�X�e���̉��
// ����   �Funique_ptr<C_Rendering_Screen_Data_Base> & �ݒ��̃����_�����O��ʂ̎Q��, const S_Create_Render_Screen_Inform & �����_�����O��ʂ𐶐����邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Rendering_Screen::M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & out_result_rendering_screen_system, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & in_create_rendering_screen_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Rendering_Screen(out_result_rendering_screen_system, in_create_rendering_screen_inform);
}


//-��- ��� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ̍폜��ʒm����
// ����   �Fconst C_Rendering_Screen_Data_Base * �폜���ꂽ�����_�����O��ʂ̃A�h���X�iconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * in_delete_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Notice_Rendering_Screen_Deleted(in_delete_rendering_screen);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ��N���A����
// ����   �Funique_ptr<C_Rendering_Screen_Data_Base> & �N���A���郌���_�����O��ʔԍ�, S_Create_Render_Screen_Inform & �N���A���郌���_�����O��ʃV�X�e���̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Clear_Rendering_Screen(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(in_rendering_screen_number, in_rendering_screen);

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����_�����O��ʂ�`���ɃZ�b�g
// ����   �Funique_ptr<C_Rendering_Screen_Data_Base> & �ݒ��̃����_�����O��ʂ̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_To_Draw_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_set_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Render_Target(in_set_rendering_screen);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���C���̃����_�����O��ʂ�`���ɂ���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Rendering_Screen_To_Draw(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Rendering_Screen_To_Rendering();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����_�����O��ʂ��e�N�X�`�����\�[�X�X���b�g�ɃZ�b�g
// ����   �Fint �ݒ��̃X���b�g�ԍ�, int �ݒ肷���ʂ̔ԍ�, unique_ptr<C_Rendering_Screen_Data_Base> & �ݒ��̃����_�����O��ʂ̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_To_Texture_Resource_Slot(int in_set_slot_number, int in_set_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_set_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Texture_Slot(in_set_slot_number, in_set_screen_number, in_set_rendering_screen);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���C���̕\�����̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����
// ����   �Fint �ݒ��̃e�N�X�`���̃X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(in_texture_slot);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���C���̕`�揑�����ݒ��̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����
// ����   �Fint �ݒ��̃e�N�X�`���̃X���b�g�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(in_texture_slot);

	return;
}


//-��- �e�N�X�`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ�
// ����   �Fint �ݒ肷�郌���_�����O��ʔԍ�, unique_ptr<C_Rendering_Screen_Data_Base> & �����_�����O��ʃV�X�e���̎Q��, C_Texture_Map & �ݒ��̃e�N�X�`���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Save_Rendering_Screen_To_Texture(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen_data, ASSET::TEXTURE::C_Texture_Map & out_result_texture_map)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Save_Rendering_Screen_To_Texture(in_rendering_screen_number, in_rendering_screen_data, out_result_texture_map);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���C���̃����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ�
// ����   �FC_Texture_Map & �ݒ��̃e�N�X�`���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Save_Main_Rendering_Screen_To_Texture(in_texture_map);
}


//-��- ���\�[�X�ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʂ̃f�[�^��ǂݎ��\�ɂ���
// ����   �Fint �ݒ肷�郌���_�����O��ʔԍ�, unique_ptr<C_Rendering_Screen_Data_Base> & �����_�����O��ʃV�X�e���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_Can_Readable(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_Can_Readable(in_rendering_screen_number, in_rendering_screen);

	return;
}
