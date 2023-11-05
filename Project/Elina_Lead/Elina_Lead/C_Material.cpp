//����������������������������������������������//
// �ڍ�   �F�}�e���A���̃N���X�A�`�掞�̕`����@�̐ݒ���s��
// ����   �F�o�b�t�@�̊Ǘ��⃌���_�����O�ݒ�̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"


// �f�o�b�O���̂݃��O�V�X�e�����g�p
#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MATERIAL;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X���b�g�̏����Z�b�g����
// ����   �Fconst S_All_Shader_Resource_Signatures & �ݒ肷��X���b�g���ʗp�̏��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material::M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data>&, SYSTEM::TEXT::C_Text_And_File_Manager&)
{

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X���b�g�̏����Z�b�g����
// ����   �Fconst S_All_Shader_Resource_Signatures & �ݒ肷��X���b�g���ʗp�̏��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material::M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures& in_resource_signature)
{
	// �� �ϐ��錾 �� //
	int now_index_number = 0;			// ���ݑ��쒆�̃C���f�b�N�X�X���b�g�ԍ�
	int now_constant_index_number = 0;	// ���ݑ��쒆�̒萔�o�b�t�@
	int now_texture_index_number = 0;	// ���ݑ��쒆�̃e�N�X�`���X���b�g


	//-��- ���\�[�X�̐��� -��-//

	//--�� �S�V�F�[�_�[�ɋ��ʂ���X���b�g��ݒ� -��-//

	// ��`�����̒萔�o�b�t�@�����A����ݒ肷��
	mpr_variable.constant_data_list.resize(in_resource_signature.all_shader_signature.constant_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.all_shader_signature.constant_data)
	{
		mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
		mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

		now_constant_index_number += 1;
		now_index_number += 1;
	}

	// �e�N�X�`�������̃X���b�g�����
	mpr_variable.texture_data_list.resize(in_resource_signature.all_shader_signature.texture_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.all_shader_signature.texture_data)
	{
		mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
		mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

		now_texture_index_number += 1;
		now_index_number += 1;
	}

	//--�� �e�V�F�[�_�[���Ƃ̃X���b�g��ݒ� -��-//
	for (int l_now_shader_number = 0; l_now_shader_number < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; l_now_shader_number++)
	{
		// ��`�����̒萔�o�b�t�@�����A����ݒ肷��
		mpr_variable.constant_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].constant_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.signature_list[l_now_shader_number].constant_data)
		{
			mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
			mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

			now_constant_index_number += 1;
			now_index_number += 1;
		}

		// �e�N�X�`�������̃X���b�g�����
		mpr_variable.texture_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].texture_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.signature_list[l_now_shader_number].texture_data)
		{
			mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
			mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

			now_texture_index_number += 1;
			now_index_number += 1;
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O���𐶐�����
// ����   �FC_Text_And_File_Manager & ���݂̃t�@�C��������
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Material::M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform rendering_setting_create_inform;	// �����_�����O�ݒ�̐����p�̏��


	// �V�F�[�_�[���Z�b�g����
	rendering_setting_create_inform.shader_setting = &mpr_variable.shader_setting_data;

	// �u�����h�̐ݒ��ǂݍ���

	

	// �����_�����O�ݒ�𐶐�����
	return mpr_variable.rendering_setting.M_Create_Pipeline_Setting();
}


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
		now_constant_buffer.data->M_Release();
		now_constant_buffer.data.reset();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// �e�N�X�`��
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Release();
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


	// �w�肳�ꂽ�t�@�C���̃��[�h���s���@�G���[�ŏI������
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "�w�肳�ꂽ�}�e���A���̃t�@�C���͂���܂���");
#endif // _DEBUG

		return false;
	}

	// �}�e���A���Ɏg�p����V�F�[�_�[�ݒ薼��������ʒu�ֈړ��@���s�ŃG���[���o���Ĕ�����
	if (material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("Shader�F") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "�}�e���A���̏��ɃV�F�[�_�[�̃f�[�^���ݒ肳��Ă��܂���");
#endif // _DEBUG

		return false;
	}
	

	// �V�F�[�_�[�ݒ薼����V�F�[�_�[��ݒ�����[�h����@���s�ŃG���[���o���Ĕ�����
	if (mpr_variable.shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row()) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "���̃V�F�[�_�[�ݒ�͖����ł��B���݂��Ȃ��t�@�C�����ݒ肪�������Ȃ��\��������܂�");
#endif // _DEBUG

		return false;
	}


	// �V�F�[�_�[�ݒ�̃��\�[�X�̏������ƂɃ��\�[�X�𐶐�����
	M_Create_Resource_By_Signature_Inform(mpr_variable.shader_setting_data.M_Get_Resource_Signature());


	// �����_�����O�ݒ�𐶐�����A���s�ŃG���[���o���Ĕ�����
	if (M_Create_Rendering_Setting(material_inform_file_data) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "�����_�����O�ݒ�̐����Ɏ��s���܂���");
#endif // _DEBUG

		return false;
	}


	// �f�o�b�O���͐����ɐ����������Ƃ��L�^����
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_INIT, "�}�e���A���̐����ɐ������܂���");
#endif // _DEBUG
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
		now_constant_buffer.data->M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// �e�N�X�`���o�b�t�@����ÂK�p����
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Texture_Attach_To_Draw(now_texture_buffer.index);
	}

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�X���b�g�Ƀe�N�X�`�������[�h����
// ����   �Fint �e�N�X�`���X���b�g�ԍ�, string ���[�h����e�N�X�`����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material::M_Load_Texture_For_Slot_By_Index(int in_index, std::string in_load_texture_name)
{
	// �z��O���w�肳�ꂽ�甲����
	if (mpr_variable.texture_data_list.size() <= in_index)
	{
		return;
	}

	mpr_variable.texture_data_list[in_index].data.M_Load_Texture(in_load_texture_name);

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�萔�o�b�t�@�Ǘ��p�f�[�^��Ԃ�
// ����   �Fint �擾����萔�o�b�t�@�Ǘ��p�f�[�^�̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Constant_Buffer_Data & C_Material::M_Get_Constant_Buffer_Data_By_Index(int in_index)
{
	return mpr_variable.constant_data_list[in_index];
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�e�N�X�`���Ǘ��p�f�[�^��Ԃ�
// ����   �Fint �擾����e�N�X�`���Ǘ��p�f�[�^�̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Texture_Buffer_Data & C_Material::M_Get_Texture_Data_By_Index(int in_index)
{
	return mpr_variable.texture_data_list[in_index];
}



