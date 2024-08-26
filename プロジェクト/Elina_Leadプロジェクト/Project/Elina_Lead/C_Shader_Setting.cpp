//����������������������������������������������//
// �ڍ�   �F��g�̃V�F�[�_�[�̐ݒ���܂Ƃ߂邽�߂̃N���X
// ����   �F�V�F�[�_�[���o���o���ɐݒ肷��K�v���Ȃ����A�J�v�Z����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting.h"

#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER;


// �� �N���X �� //

// �f�[�^�Ɩ��O���֘A�t���邽�߂̍\����
class C_Store_Data
{
	//==�� �p�u���b�N ��==//
public:

	// �� �ϐ��錾 �� //
	std::string name = "default";	// ���O

	int & data;	// �f�[�^


	// �� �֐� �� //

	//-��- �������ƏI���� -��-//
	C_Store_Data(int & in_data, std::string in_set_name) : data(in_data)
	{
		name = in_set_name;

		return;
	}
};


// �� �C�����C���֐� �� //

//-��- �ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t���O�^�𕶎���ɕϊ�����
// ����   �Fbool �ϊ�����t���O
// �߂�l �Fstring �ϊ�����������
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string M_Convert_Bool_To_String(bool in_flg)
{
	// true�Ȃ�"TRUE"��Ԃ�
	if (in_flg == true)
	{
		return "TRUE";
	}

	// false�Ȃ�"FALSE"��Ԃ�
	return "FALSE";
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̎�ނ��w�肷��񋓂𕶎���ɕϊ�����
// ����   �FE_SHADER_KIND �ϊ�����V�F�[�_�[�̎��
// �߂�l �Fstring �ϊ�����������
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string M_Convert_Shader_Kind_Flg_To_String(E_SHADER_KIND in_shader_kind)
{
	switch (in_shader_kind)
	{
	case ASSET::SHADER::E_SHADER_KIND::e_VERTEX:
		return "VS";
	case ASSET::SHADER::E_SHADER_KIND::e_HULL_TCS:
		return "HS";
	case ASSET::SHADER::E_SHADER_KIND::e_DOMAIN_TES:
		return "DS";
	case ASSET::SHADER::E_SHADER_KIND::e_GEOMETRY:
		return "GS";
	case ASSET::SHADER::E_SHADER_KIND::e_PIXEL_FRAGMENT:
		return "PS";
	case ASSET::SHADER::E_SHADER_KIND::e_ALL:
	default:
		return "AS";
	}
}


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
	vertex_layout_sum = (int)in_shader_data_file.M_Get_Number();


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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�o�C�g��" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�t�H�[�}�b�g" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"���̒��_���C�A�E�g�͖����ł��@" + in_shader_data_file.M_Get_File_Path_Refer() + "�F�ϐ��̐��@x,y,z,w" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

			return false;
		}
	}

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̃��\�[�X�����[�h������񂩂�ݒ肷��
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎�ޖ�, C_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Resource_Signature(E_SHADER_KIND in_shader_kind, SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// �� �ϐ��錾 �� //
	std::string shader_kind_name = "default";	// �V�F�[�_�[�̎�ޖ�


	// �V�F�[�_�[�̎�ޖ����擾
	shader_kind_name = M_Convert_Shader_Kind_Flg_To_String(in_shader_kind);


	// �V�F�[�_�[�̏��̊J�n�ʒu��T���A�Ȃ���΃G���[
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_kind_name + "START:") == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	int constant_number = (int)mpr_variable.resource_inform.constant_list.size();	// ���݂̒萔�o�b�t�@�̔ԍ�
	int sampler_number = (int)mpr_variable.resource_inform.sampler_list.size();		// ���݂̃T���v���[�o�b�t�@�̔ԍ�

	int texture_number = (int)mpr_variable.resource_inform.texture_list.size();		// ���݂̃e�N�X�`���o�b�t�@�̔ԍ�
	int screen_number = (int)mpr_variable.resource_inform.screen_list.size();		// ���݂̃����_�����O��ʂ̔ԍ�
	int depth_stencil_number = (int)mpr_variable.resource_inform.depth_stencil_list.size();		// ���݂̐[�x�X�e���V���o�b�t�@�̔ԍ�
	
	int texture_kind_number = texture_number + screen_number + depth_stencil_number;		// ���݂̃e�N�X�`���n�̃o�b�t�@�̔ԍ�
	
	int constant_sum = constant_number;		// �萔�̐�
	int texture_sum = texture_kind_number;	// �e�L�X�g�̐�
	int sampler_sum = sampler_number;		// �T���v���[�̐�


	// �萔�o�b�t�@�����擾
	in_shader_data_file.M_Move_Next_Raw();
	constant_sum += (int)in_shader_data_file.M_Get_Number();

	// �e�L�X�g�����擾
	in_shader_data_file.M_Move_Next_Raw();
	texture_sum += (int)in_shader_data_file.M_Get_Number();

	// �T���v���[�����擾
	in_shader_data_file.M_Move_Next_Raw();
	sampler_sum += (int)in_shader_data_file.M_Get_Number();


	// �擾�����������\�[�X�̎��ʂ𐶐�
	mpr_variable.resource_inform.constant_list.resize(constant_sum);
	mpr_variable.resource_inform.sampler_list.resize(sampler_sum);

	// �X���b�g�̏��𐶐�
	mpr_variable.resource_inform.slot_list.resize(mpr_variable.slot_number + constant_sum + texture_sum);


	// �萔�o�b�t�@�̎��ʖ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "CON:");

	// �萔�o�b�t�@�̏����擾
	for (constant_number; constant_number < constant_sum; constant_number++)
	{
		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// ���ʖ����擾
		mpr_variable.resource_inform.constant_list[constant_number].resource_name = in_shader_data_file.M_Get_Data_By_Text(",");

		// �z�񐔂��擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		mpr_variable.resource_inform.constant_list[constant_number].array_sum = (int)in_shader_data_file.M_Get_Number();

		// �z�񐔂��O�Ȃ班�Ȃ��Ƃ���͊m�ۂ���
		mpr_variable.resource_inform.constant_list[constant_number].array_sum =
			(mpr_variable.resource_inform.constant_list[constant_number].array_sum <= 0)
			+
			(mpr_variable.resource_inform.constant_list[constant_number].array_sum > 0) * mpr_variable.resource_inform.constant_list[constant_number].array_sum;

		// �f�[�^�𐶐����邩�ǂ����̃t���O���擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		mpr_variable.resource_inform.constant_list[constant_number].flg_data_creation = in_shader_data_file.M_Get_Data_By_Text(",") == "TRUE";

		// �V�F�[�_�[�̎�ނ��w��
		mpr_variable.resource_inform.constant_list[constant_number].shader_kind = in_shader_kind;

		// �X���b�g�ԍ����L�^
		mpr_variable.resource_inform.constant_list[constant_number].slot_number = mpr_variable.slot_number;


		// �X���b�g�̏���ݒ�
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].shader_kind = in_shader_kind;


		// ���̃X���b�g�ֈړ�
		mpr_variable.slot_number += 1;
	}


	// �e�N�X�`���̎��ʖ��Ɛ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "TEX:");

	// �e�N�X�`���̎��ʖ����擾����
	for (texture_kind_number; texture_kind_number < texture_sum; texture_kind_number++)
	{
		// �� �ϐ��錾 �� //
		std::string resource_name = "\0";	// ���\�[�X��

		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// ���ʖ����擾
		resource_name = in_shader_data_file.M_Get_Data_By_Text(",");


		// �����_�����O��ʂ̎��ʖ��̎��́A�����_�����O��ʂ̏���ݒ�
		if (resource_name.substr(0, 3) == "RSC")
		{
			// �����_�����O��ʗp�̃X���b�g�𑝂₷
			mpr_variable.resource_inform.screen_list.resize(screen_number + 1);

			// �����_�����O��ʂ̎��ʖ����擾
			mpr_variable.resource_inform.screen_list[screen_number].resource_name = resource_name;

			// �V�F�[�_�[�̎�ނ��w��
			mpr_variable.resource_inform.screen_list[screen_number].shader_kind = in_shader_kind;

			// �X���b�g�ԍ����L�^
			mpr_variable.resource_inform.screen_list[screen_number].slot_number = mpr_variable.slot_number;

			// ���̃X���b�g�ֈړ�
			screen_number += 1;
		}

		// �[�x�X�e���V���o�b�t�@�̎��ʖ��̎��́A�[�x�X�e���V���o�b�t�@�̏���ݒ�
		else if (resource_name.substr(0,3) == "DSB")
		{
			// �[�x�X�e���V���o�b�t�@�p�̃X���b�g�𑝂₷
			mpr_variable.resource_inform.depth_stencil_list.resize(depth_stencil_number + 1);

			// �����_�����O��ʂ̎��ʖ����擾
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].resource_name = resource_name;

			// �V�F�[�_�[�̎�ނ��w��
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].shader_kind = in_shader_kind;

			// �X���b�g�ԍ����L�^
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].slot_number = mpr_variable.slot_number;

			// ���̃X���b�g�ֈړ�
			depth_stencil_number += 1;
		}

		// �ʏ펞�́A�e�N�X�`���̏���ݒ�
		else
		{
			// �e�N�X�`���p�̃X���b�g�𑝂₷
			mpr_variable.resource_inform.texture_list.resize(texture_number + 1);

			// ���ʖ���ݒ�
			mpr_variable.resource_inform.texture_list[texture_number].resource_name = resource_name;

			// �������[�h���鎞�̃e�N�X�`���̓�����擾
			in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
			mpr_variable.resource_inform.texture_list[texture_number].initialize_texture_name = in_shader_data_file.M_Get_Data_By_Text(",");

			// �V�F�[�_�[�̎�ނ��w��
			mpr_variable.resource_inform.texture_list[texture_number].shader_kind = in_shader_kind;

			// �X���b�g�ԍ����L�^
			mpr_variable.resource_inform.texture_list[texture_number].slot_number = mpr_variable.slot_number;

			// ���̃X���b�g�ֈړ�
			texture_number += 1;
		}

		// �X���b�g�̏���ݒ�
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].resource_kind = E_RESOURCE_KIND::e_TEXTURE;
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].shader_kind = in_shader_kind;

		// ���̃X���b�g�ֈړ�
		mpr_variable.slot_number += 1;
	}


	// �T���v���[�̎��ʖ��Ɛ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "SAM:");

	// �T���v���[�̎��ʖ����擾����
	for (sampler_number; sampler_number < sampler_sum; sampler_number++)
	{
		// ���̍s�Ɉړ�
		in_shader_data_file.M_Move_Next_Raw();

		// UV�̎g�p���@���擾
		mpr_variable.resource_inform.sampler_list[sampler_number].uv_setting = in_shader_data_file.M_Get_Data_By_Text(",");

		// �V�F�[�_�[�̎�ނ��w��
		mpr_variable.resource_inform.sampler_list[sampler_number].shader_kind = in_shader_kind;
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
	M_Load_Resource_Signature(E_SHADER_KIND::e_ALL, in_shader_data_file);

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
	case (int)E_SHADER_KIND::e_HULL_TCS:
		shader_type_text = "HS";
		shader_kind = E_SHADER_KIND::e_HULL_TCS;
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
	int shader_slot_num = (int)mpr_variable.shader_list.size();	// ���삷��V�F�[�_�[�̔z��ԍ�

	
	// �V�F�[�_�[���擾����A�����Ɏ��s������G���[���o���Ĕ�����
	mpr_variable.shader_list.resize(shader_slot_num + 1);
	if (mpr_variable.shader_list[shader_slot_num].M_Load_Shader_Code(shader_kind, in_shader_data_file.M_Get_Data_Right_In_Row()) == false)
	{
		return false;
	}

	// �V�F�[�_�[�̃��\�[�X���擾
	M_Load_Resource_Signature(shader_kind, in_shader_data_file);

	// ����
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̃X���b�g���𐮗񂷂�
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting::M_Slot_Inform_Alignment(void)
{
	// �� �萔 �� //
	constexpr int con_CONSTANT_UNIQUE_BUFFER_KIND_SUM = 8;	// ����Ȓ萔�o�b�t�@�X���b�g�̑�����


	// �� �ϐ��錾 �� //
	std::vector <std::unique_ptr<C_Store_Data>> data_list;	// �f�[�^�̃��X�g

	int constant_slot_sum = 0;	// �C���X�^���X�X���b�g�̐�
	

	// ���O�ƕϐ��̊֘A��o�^
	data_list.resize(con_CONSTANT_UNIQUE_BUFFER_KIND_SUM);
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.wvp, "CB_WVP"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.bone, "CB_BONE"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.material, "CB_MATERIAL"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.ambient_light, "CB_AMBIENT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.directional_light, "CB_DIRECTIONAL_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.point_light, "CB_POINT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.spot_light, "CB_SPOT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.area_light, "CB_AREA_LIGHT"));


	// �萔�o�b�t�@�̃X���b�g�̑������擾
	constant_slot_sum = (int)mpr_variable.resource_inform.constant_list.size();

	// �V�F�[�_�[���ʏ��̒萔�o�b�t�@��T�����A����Ȗ��O�̃X���b�g�̔ԍ����擾����
	for (int l_now_constant_buffer_num = 0; l_now_constant_buffer_num < constant_slot_sum; l_now_constant_buffer_num++)
	{
		// �� �ϐ��錾 �� //
		S_Constant_Resource_Inform & now_resource_data = mpr_variable.resource_inform.constant_list[l_now_constant_buffer_num];	// ���݂̃��\�[�X���


		// �S�Ă̖��O��T�����I�����甲����
		if (data_list.size() <= 0)
		{
			return;
		}

		// �f�[�^�����ϐ��֘A���X�g���疼�O����v������̂Ƀf�[�^��ݒ肵�A�ݒ肪�����������̂̓��X�g����폜
		data_list.erase
		(
			std::remove_if
			(
				data_list.begin(),
				data_list.end(),

				// ���O����v����Δԍ����Z�b�g���č폜�A�����łȂ���΃X���[���郉���_
				[now_resource_data, l_now_constant_buffer_num](std::unique_ptr<C_Store_Data>& in_data)
				{
					if (in_data->name == now_resource_data.resource_name)
					{
						in_data->data = l_now_constant_buffer_num;
						in_data.reset();

						return true;
					}

					return false;
				}
			)
		);
		data_list.shrink_to_fit();
	}

	return;
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

	// ���\�[�X���̍폜
	mpr_variable.resource_inform.constant_list.clear();
	mpr_variable.resource_inform.constant_list.shrink_to_fit();
	mpr_variable.resource_inform.texture_list.clear();
	mpr_variable.resource_inform.texture_list.shrink_to_fit();
	mpr_variable.resource_inform.screen_list.clear();
	mpr_variable.resource_inform.screen_list.shrink_to_fit();
	mpr_variable.resource_inform.depth_stencil_list.clear();
	mpr_variable.resource_inform.depth_stencil_list.shrink_to_fit();
	mpr_variable.resource_inform.sampler_list.clear();
	mpr_variable.resource_inform.sampler_list.shrink_to_fit();
	mpr_variable.resource_inform.slot_list.clear();
	mpr_variable.resource_inform.slot_list.shrink_to_fit();
	mpr_variable.slot_number = 0;

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


	// �V�F�[�_�[�̃��\�[�X���𐮗�
	M_Slot_Inform_Alignment();

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
// �ڍ�   �F���_���̓��C�A�E�g�̃��X�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst vector<S_INPUT_LAYOUT_SETTING> & ���̓��C�A�E�g�ւ̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & C_Shader_Setting::M_Get_Input_Layout(void) const
{
	return mpr_variable.vertex_layout_setting;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F����ȃV�F�[�_�[�̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Unique_Buffer_Slot & ����ȃV�F�[�_�[�̃��X�g�̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot & C_Shader_Setting::M_Get_Unique_Buffer_Slot(void) const
{
	return mpr_variable.unique_buffer_slot_list;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���\�[�X���̃��X�g��Ԃ�
// ����   �Fvoid
// �߂�l �FS_Resource_Inform & ���\�[�X���̃��X�g�̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Resource_Inform_List & C_Shader_Setting::M_Get_Resource_Inform(void) const
{
	return mpr_variable.resource_inform;
}




