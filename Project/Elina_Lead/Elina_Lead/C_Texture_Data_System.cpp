//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���f�[�^�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�e�N�X�`���f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Data_System.h"
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
C_Texture_Data_System::C_Texture_Data_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Data_System::~C_Texture_Data_System(void)
{
	M_Delete();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Delete(void)
{
	mpr_variable.texture_setting_inform.reset();
	mpr_variable.texture_map.M_Delete_Map();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�̂݉������i�o�b�t�@�͎c��j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Delete_Map(void)
{
	mpr_variable.texture_map.M_Delete_Map();

	return;
}


//-��- ���Z�b�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�̂݉������i�o�b�t�@�͎c��j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Reset_Texture(void)
{
	// �� �ϐ��錾 �� //
	DATA::COLOR::C_Color reset_color(255, 0, 255, 255);	// ���Z�b�g�p�̐F


	// �e�N�X�`���𐶐����������F��ݒ�
	M_Create_Texture_Data(10, 10);
	mpr_variable.texture_map.M_Flush_All_Color(reset_color);

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�𐶐�����
// ����   �Fint �e�N�X�`���̉��T�C�Y, int �e�N�X�`���̏c�T�C�Y
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Create_Texture_Data(int in_tex_width, int in_tex_height)
{
	// �}�C�i�X���͐����ł��Ȃ��̂ŃG���[�Ŕ�����
	if (in_tex_width <= 0 || in_tex_height <= 0)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// �����p���


	// �����p�̏���ݒ肵�āA��������
	create_inform.pixel_width = in_tex_width;
	create_inform.pixel_height = in_tex_height;
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);


	// �}�b�v���w�肳�ꂽ�s�N�Z��������������
	mpr_variable.texture_map.M_Create_Texture_Map(in_tex_width, in_tex_height);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�ɍ��킹�āA�e�N�X�`���̃��\�[�X�𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Create_Texture_Resource_By_Texture_Map(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// �����p���


	// �����p�̏���ݒ肵�āA��������
	create_inform.pixel_width = mpr_variable.texture_map.M_Get_Width_Size();
	create_inform.pixel_height = mpr_variable.texture_map.M_Get_Height_Size();
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);
	M_Texture_Map_To_Texture_Resource_Data();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`�������[�h�����f�[�^�����ɐ�������
// ����   �Fstring �e�N�X�`���̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Texture_Data_System::M_Create_Texture_By_Load_Texture_File(std::string in_tex_file_path)
{
	// �e�N�X�`�������[�h���ăe�N�X�`���}�b�v�����@�G���[�Ŕ�����
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Load_Texture(in_tex_file_path, mpr_variable.texture_map) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// �����p���


	// �����p�̏���ݒ肵�āA��������
	create_inform.pixel_width = mpr_variable.texture_map.M_Get_Width_Size();
	create_inform.pixel_height = mpr_variable.texture_map.M_Get_Height_Size();
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);


	// ���������e�N�X�`���p�̃o�b�t�@�Ƀe�N�X�`���}�b�v��K�p����
	M_Texture_Map_To_Texture_Resource_Data();

	return true;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^�̎��ʖ����Z�b�g����
// ����   �Fstring �Z�b�g���镶����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Set_Data_Signature_Name(std::string in_set_name)
{
	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name = in_set_name;
	mpr_variable.data_signature_name.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�ύX����
// ����   �FE_SHADER_KIND �ݒ��̃V�F�[�_�[�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.attach_shader = in_set_shader_kind;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^�̎��ʖ���Ԃ�
// ����   �Fvoid
// �߂�l �Fconst string & ���݂̃f�[�^���ʖ��̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::string & C_Texture_Data_System::M_Get_Data_Signature_Name(void)
{
	return mpr_variable.data_signature_name;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�Ԃ�
// ����   �Fvoid
// �߂�l �FE_SHADER_KIND �ݒ��̃V�F�[�_�[�̎��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::E_SHADER_KIND C_Texture_Data_System::M_Get_Attach_Shader_Kind(void)
{
	return mpr_variable.attach_shader;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FDATA::TEXTURE::C_Texture_Map & �e�N�X�`���}�b�v�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::TEXTURE::C_Texture_Map & C_Texture_Data_System::M_Get_Texture_Map(void)
{
	return mpr_variable.texture_map;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�̃f�[�^���e�N�X�`���Ƃ��ăZ�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Texture_Map_To_Texture_Resource_Data(void)
{
	mpr_variable.texture_setting_inform->M_Set_Texture_Data(mpr_variable.texture_map.M_Get_Texture_Map(), mpr_variable.texture_map.M_Get_Width_Size(), mpr_variable.texture_map.M_Get_Height_Size());

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`������GPU�ɓn��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Attach_To_Shader(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::INSTANCE::S_Texture_Buffer_Drawing_Setting drawing_setting;	// �`��p�ݒ�


	// �`��p����ݒ肵�ĕ`�悷��
	drawing_setting.add_texture_data = mpr_variable.texture_setting_inform.get();
	drawing_setting.attach_shader_kind = mpr_variable.attach_shader;
	drawing_setting.add_signature_name = &mpr_variable.data_signature_name;
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Texture(drawing_setting);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`�������w�肳�ꂽ�C���f�b�N�X�ɐݒ肵�AGPU�ɓn��
// ����   �Fint �C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_System::M_Attach_To_Shader_By_Index(int in_index)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Texture_By_Index(mpr_variable.texture_setting_inform, in_index);

	return;
}


