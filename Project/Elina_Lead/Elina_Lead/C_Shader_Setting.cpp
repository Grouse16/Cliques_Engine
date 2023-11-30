//����������������������������������������������//
// �ڍ�   �F��g�̃V�F�[�_�[�̐ݒ���܂Ƃ߂邽�߂̃N���X
// ����   �F�V�F�[�_�[���o���o���ɐݒ肷��K�v���Ȃ����A�J�v�Z����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER;


// �� �֐� �� //

//==���@�v���C�x�[�g ��==//

//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_���C�A�E�g�����[�h����
// ����   �FC_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// �� �ϐ��錾 �� //
	int vertex_layout_sum = 0;	// ���_���C�A�E�g��


	// ���_���C�A�E�g�̈ʒu�Ɉړ�����A�Ȃ���΃G���[
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("VERTEXLAYOUT=") == false)
	{
		return false;
	}


	// ���_���C�A�E�g�����擾
	in_shader_data_file.M_Move_Next_Raw();
	vertex_layout_sum = in_shader_data_file.M_Get_Number();


	// ���_���C�A�E�g��ݒ肷��
	mpr_variable.vertex_layout_setting.resize(vertex_layout_sum);
	for (int layout_number = 0; layout_number < vertex_layout_sum; layout_number++)
	{
		// �� �ϐ��錾 �� //
		std::string get_text;		// �擾�������ʗp�̕�����
		

		// ���݂̔ԍ��̒��_���C�A�E�g���̍ŏ��Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();


		// �r�b�g�T�C�Y�̕�������擾
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// 1�o�C�g
		if (get_text == "1")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 2�o�C�g
		else if (get_text == "2")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 4�o�C�g
		else if(get_text == "4")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT;
		}
		// �w�肷�镶��������Ă���Ȃ�G���[
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�o�C�g��" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}


		// �f�[�^�`�����擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(",");
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// float�^
		if (get_text == "FLOAT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT;
		}
		// unsigned int�^
		else if (get_text == "UINT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT;
		}
		// int�^
		else if(get_text == "INT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT;
		}
		// �^���������w�肳��Ă��Ȃ��Ȃ�G���[
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�t�H�[�}�b�g" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}

		// �f�[�^�`�����擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(",");
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// �ϐ��͂P�@��
		if (get_text == "1")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_1;
		}
		// �ϐ��͂Q�@��,y
		else if (get_text == "2")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2;
		}
		// �ϐ��͂R�@��,y,z
		else if (get_text == "3")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2;
		}
		// �ϐ��͂S�@��,y,z,w
		else if (get_text == "4")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4;
		}
		// �ϐ��̐��������Ȃ�G���[
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�ϐ��̐��@x,y,z,w" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}
	}

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̃��\�[�X�����[�h������񂩂�ݒ肷��
// ����   �Fstring �V�F�[�_�[�̎�ޖ�, C_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Shader_Resource_Signature(std::string in_shader_kind_name, SYSTEM::TEXT::C_Text_And_File_Manager& in_shader_data_file)
{
	// �V�F�[�_�[�̏��̊J�n�ʒu��T���A�Ȃ���΃G���[
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(in_shader_kind_name + "START:") == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	int constant_sum = 0;	// �萔�̐�
	int texture_sum = 0;	// �e�L�X�g�̐�
	int sampler_sum = 0;	// �T���v���[�̐�


	// �萔�o�b�t�@�����擾
	in_shader_data_file.M_Move_Next_Raw();
	constant_sum = in_shader_data_file.M_Get_Number();

	// �e�L�X�g�����擾
	in_shader_data_file.M_Move_Next_Raw();
	texture_sum = in_shader_data_file.M_Get_Number();

	// �T���v���[�����擾
	in_shader_data_file.M_Move_Next_Raw();
	sampler_sum = in_shader_data_file.M_Get_Number();


	// �擾�����������\�[�X�̎��ʂ𐶐�
	mpr_variable.resource_signature.all_shader_signature.constant_data.resize(constant_sum);
	mpr_variable.resource_signature.all_shader_signature.texture_data.resize(texture_sum);
	mpr_variable.resource_signature.all_shader_signature.sampler_data.resize(sampler_sum);


	// �萔�o�b�t�@�̎��ʖ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "CON:");

	// �萔�o�b�t�@�̏����擾
	for (ASSET::SHADER::S_Constant_Resource_Signature & now_constant_data : mpr_variable.resource_signature.all_shader_signature.constant_data)
	{
		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// ���ʖ����擾
		now_constant_data.signature_name = in_shader_data_file.M_Get_Data_By_Text(",");

		// �z�񐔂��擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		now_constant_data.array_sum = in_shader_data_file.M_Get_Number();

		// �f�[�^�𐶐����邩�ǂ����̃t���O���擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		now_constant_data.data_create_flg = in_shader_data_file.M_Get_Data_By_Text(",") == "TRUE";

		// �z�񐔂��O�Ȃ班�Ȃ��Ƃ���͊m�ۂ���
		now_constant_data.array_sum =
			(now_constant_data.array_sum <= 0)
			+
			(now_constant_data.array_sum > 0) * now_constant_data.array_sum;
	}


	// �e�N�X�`���̎��ʖ��Ɛ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "TEX:");

	// �e�N�X�`���̎��ʖ����擾����
	for (ASSET::SHADER::S_Texture_Resource_Signature & now_texture_data : mpr_variable.resource_signature.all_shader_signature.texture_data)
	{
		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// ���ʖ����擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");

		// �������[�h���鎞�̃e�N�X�`���̓�����擾
		now_texture_data.signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
		now_texture_data.initialized_texture_name = in_shader_data_file.M_Get_Data_By_Text(",");
	}


	// �T���v���[�̎��ʖ��Ɛ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "SAM:");

	// �T���v���[�̎��ʖ����擾����
	for (ASSET::SHADER::S_Sampler_Resource_Signature & now_sampler_data : mpr_variable.resource_signature.all_shader_signature.sampler_data)
	{
		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// UV�̎g�p���@���擾
		now_sampler_data.uv_setting = in_shader_data_file.M_Get_Data_By_Text(",");
	}
	
	// ����
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e��V�F�[�_�[�̃��[�h�ƃ��\�[�X�̒�`���s��
// ����   �FC_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// �S�ẴV�F�[�_�[�ɋ��ʂ���ݒ�����[�h
	M_Load_Shader_Resource_Signature("AS", in_shader_data_file);

	// �e��V�F�[�_�[�̏���ǂݎ��R���p�C�����ʂ��擾
	for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
	{
		if (M_Load_Shader_And_Setting_Resource_Signature(in_shader_data_file, now_shader_kind) == false)
		{
			return false;
		}
	}

	// ����
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���ޕ��̃V�F�[�_�[���[�h���s������
// ����   �FC_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^, int �V�F�[�_�[�̎��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file, int in_shader_kind)
{
	// �� �ϐ��錾 �� //
	std::string shader_type_text;	// �V�F�[�_�[�^�C�v�̕�����

	E_SHADER_KIND shader_kind = E_SHADER_KIND::e_VERTEX;	// �g�p����V�F�[�_�[�̎��


	// �� �V�F�[�_�[�̎�ނ��ƂɎ��ʂɎg�p���镶����ς��� ���@//
	switch (in_shader_kind)
	{
	//  ���_�V�F�[�_�[  //
	case (int)E_SHADER_KIND::e_VERTEX:
		shader_type_text = "VS";
		shader_kind = E_SHADER_KIND::e_VERTEX;
		break;

		//  �n���V�F�[�_�[  //
	case (int)E_SHADER_KIND::e_HUL_TCS:
		shader_type_text = "HS";
		shader_kind = E_SHADER_KIND::e_HUL_TCS;
		break;

		//  �h���C���V�F�[�_�[  //
	case (int)E_SHADER_KIND::e_DOMAIN_TES:
		shader_type_text = "DS";
		shader_kind = E_SHADER_KIND::e_DOMAIN_TES;
		break;

		//  �W�I���g���V�F�[�_�[  //
	case (int)E_SHADER_KIND::e_GEOMETRY:
		shader_type_text = "GS";
		shader_kind = E_SHADER_KIND::e_GEOMETRY;
		break;

		//  �s�N�Z���V�F�[�_�[  //
	case (int)E_SHADER_KIND::e_PIXEL_FRAGMENT:
		shader_type_text = "PS";
		shader_kind = E_SHADER_KIND::e_PIXEL_FRAGMENT;
		break;
	}


	// �V�F�[�_�[�̏��̈ʒu��T���A�Ȃ���Έ�ԍŏ��ɖ߂��Ă�����x�T������A����ł��Ȃ���΂��̃V�F�[�_�[�͖��g�p
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START:") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START:") == false)
		{
			return true;
		}
	}


	// �� �ϐ��錾 �� //
	int shader_slot_num = mpr_variable.shader_list.size();	// ���삷��V�F�[�_�[�̔z��ԍ�

	
	// �V�F�[�_�[���擾����
	mpr_variable.shader_list.resize(shader_slot_num + 1);
	mpr_variable.shader_list[shader_slot_num].M_Load_Shader_Code(shader_kind, in_shader_data_file.M_Get_Data_Right_In_Row());

	// �����Ɏ��s������G���[���o���Ĕ�����
	if (mpr_variable.shader_list[shader_slot_num].M_Get_Shader_Code() == nullptr)
	{
		return false;
	}

	// �V�F�[�_�[�̃��\�[�X���擾
	M_Load_Shader_Resource_Signature(shader_type_text, in_shader_data_file);

	// ����
	return true;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting::C_Shader_Setting(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting::~C_Shader_Setting(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting::M_Release(void)
{
	// �V�F�[�_�[�̎�ޕ��A�g�p���Ă����Ԃ�����
	for (C_Shader_User & now_shader_user : mpr_variable.shader_list)
	{
		now_shader_user.M_Release();
	}
	mpr_variable.shader_list.clear();
	mpr_variable.shader_list.shrink_to_fit();


	// ���_���C�A�E�g�̍폜
	mpr_variable.vertex_layout_setting.clear();
	mpr_variable.vertex_layout_setting.shrink_to_fit();


	// �S�̋��ʂ̃��\�[�X��`�p�������ׂč폜
	mpr_variable.resource_signature.all_shader_signature.constant_data.clear();
	mpr_variable.resource_signature.all_shader_signature.constant_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.texture_data.clear();
	mpr_variable.resource_signature.all_shader_signature.texture_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.sampler_data.clear();
	mpr_variable.resource_signature.all_shader_signature.sampler_data.shrink_to_fit();


	// �V�F�[�_�[���Ƃ̃��\�[�X��`�p�������ׂč폜
	for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
	{
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].sampler_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].sampler_data.shrink_to_fit();
	}

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[���t�@�C���̓��e��ǂݎ���Ċe��V�F�[�_�[�����[�h���A���_���C�A�E�g�ƃ��\�[�X�̒�`��ݒ肷��
// ����   �Fstd::string �ǂݍ��ރV�F�[�_�[�ݒ�t�@�C���܂ł̑��΃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Shaders_Inform_By_Shader_Setting_File_Path(std::string in_shader_setting_file_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager text_file_system;	// �e�L�X�g�ƃt�@�C���p�V�X�e��

	std::string shader_name;	// �V�F�[�_�[�f�[�^������t�H���_�p�X


	// �t�@�C���ǂݎ��	// ���s�����甲����
	if (text_file_system.M_Load_Select_File(in_shader_setting_file_path) == false)
	{
		return false;
	}


	// ���[�h�ł����t�@�C���̃p�X���L�^
	text_file_system.M_Set_File_Path(in_shader_setting_file_path);


	// �V�F�[�_�[�����[�h���ă��\�[�X�̒�`������	// ���s�����甲����
	if (M_Load_Shaders_And_Setting_Resource_Signature(text_file_system) == false)
	{
		return false;
	}


	// ���_���C�A�E�g�����	// ���s�����甲����
	if (M_Load_Vertex_Layout(text_file_system) == false)
	{
		return false;
	}

	// ��������
	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̃R�[�h�̃Z�b�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Shader_Byte_Code_List & �V�F�[�_�[�̃R�[�h�̎�ޕʃ��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<C_Shader_User> & C_Shader_Setting::M_Get_Shader_Code_List(void) const
{
	return mpr_variable.shader_list;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���\�[�X���ʗp����Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_All_Shader_Resource_Signatures & ���\�[�X���ʗp���̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_All_Shader_Resource_Signatures & C_Shader_Setting::M_Get_Resource_Signature(void) const
{
	return mpr_variable.resource_signature;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_���̓��C�A�E�g�̃��X�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst vector<S_INPUT_LAYOUT_SETTING> & ���̓��C�A�E�g�ւ̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & C_Shader_Setting::M_Get_Input_Layout(void) const
{
	return mpr_variable.vertex_layout_setting;
}
