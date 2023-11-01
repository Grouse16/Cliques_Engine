//����������������������������������������������//
// �ڍ�   �F�}�e���A���̃N���X�A�`�掞�̕`����@�̐ݒ���s��
// ����   �F�o�b�t�@�̊Ǘ��⃌���_�����O�ݒ�̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Log_System.h"
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Text_And_File_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MATERIAL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material::C_Material(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material::~C_Material(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material::M_Release(void)
{
	// �`��p�ݒ�
	mpr_variable.rendering_setting.M_Delete();

	// �萔�o�b�t�@
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		now_constant_buffer.data.M_Release();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// �e�N�X�`��
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Delete();
	}
	mpr_variable.texture_data_list.clear();
	mpr_variable.texture_data_list.shrink_to_fit();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A���f�[�^�ւ̃p�X����}�e���A���������[�h
// ����   �Fstring �}�e���A���f�[�^�ւ̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Material::M_Load_Material_By_Path(std::string in_material_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager material_inform_file_data;	// �}�e���A�����̃t�@�C���̃f�[�^

	mpr_variable.constant_data_list.size();	// 


	// �w�肳�ꂽ�t�@�C���̃��[�h���s���@�G���[�ŏI������
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�w�肳�ꂽ�}�e���A���̃t�@�C���͂���܂���");

		return false;
	}

	// �}�e���A���Ɏg�p����V�F�[�_�[�ݒ薼���擾����
	material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("Shader�F");
	mpr_variable.shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row());


	// �萔�o�b�t�@��ݒ肷��


	return true;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�p�̏���GPU�ɐݒ肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material::M_Attach_To_GPU(void)
{
	// �����_�����O�ݒ��K�p
	mpr_variable.rendering_setting.M_Set_Rendering_Setting_For_API();

	// �萔�o�b�t�@����ÂK�p����
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		now_constant_buffer.data.M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// �e�N�X�`���o�b�t�@����ÂK�p����
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Attach_To_Shader_By_Index(now_texture_buffer.index);
	}

	return;
}



