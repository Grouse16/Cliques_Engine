//����������������������������������������������//
// �ڍ�   �F��g�̃V�F�[�_�[�̐ݒ���܂Ƃ߂邽�߂̃N���X
// ����   �F�V�F�[�_�[���o���o���ɐݒ肷��K�v���Ȃ����A�J�v�Z����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting.h"
#include "C_Text_And_File_Manager.h"


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


	// ���_���C�A�E�g�̊J�n�ʒu��T���A�Ȃ���Έ�ԍŏ��ɖ߂��Ă�����x�T������A����ł��Ȃ���΃G���[
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("VERTEXLAYOUT=") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("VERTEXLAYOUT=") == false)
		{
			return false;
		}
	}


	// ���_���C�A�E�g�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("LAYOUTSUM:");
	vertex_layout_sum = in_shader_data_file.M_Get_Number();


	// ���_���C�A�E�g��ݒ肷��
	mpr_variable.vertex_layout_setting.resize(vertex_layout_sum);
	for (int layout_number = 0; layout_number < vertex_layout_sum; layout_number++)
	{
		// �� �ϐ��錾 �� //
		std::string get_text;		// �擾�������ʗp�̕�����
		

		// ���݂̔ԍ��̒��_���C�A�E�g���̍ŏ��Ɉړ�
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("LOT" + std::to_string(layout_number) + ":");


		// �r�b�g�T�C�Y�̕�������擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("BITSIZE:");
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// 1�o�C�g
		if (get_text == "8")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 2�o�C�g
		else if (get_text == "16")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 4�o�C�g
		else
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT;
		}


		// �f�[�^�`�����擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("FORMAT:");
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
		else
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT;
		}


		// �f�[�^�`�����擾
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("SUM:");
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
		else
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4;
		}
	}

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�S�ẴV�F�[�_�[�ɋ��ʂ��郊�\�[�X�̒�`���s��
// ����   �FC_Text_And_File_Manager & �V�F�[�_�[���t�@�C���̃f�[�^
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_All_Shader_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager& in_shader_data_file)
{
	// �S�ẴV�F�[�_�[�̋��ʏ��̈ʒu��T���A�Ȃ���Έ�ԍŏ��ɖ߂��Ă�����x�T������A����ł��Ȃ���΃G���[
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("ASSTART=") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("ASSTART=") == false)
		{
			return false;
		}
	}
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("ASSUM=");


	// �� �ϐ��錾 �� //
	int constant_sum = 0;	// �萔�̐�
	int texture_sum = 0;	// �e�L�X�g�̐�


	// �萔�o�b�t�@�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("CON:");
	constant_sum = in_shader_data_file.M_Get_Number();

	// �e�L�X�g�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("TEX:");
	texture_sum = in_shader_data_file.M_Get_Number();

	// �T���v���[�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("SAMP:");
	mpr_variable.resource_signature.all_shader_signature.sampler_sum = in_shader_data_file.M_Get_Number();


	// �擾�����������\�[�X�̎��ʂ𐶐�
	mpr_variable.resource_signature.all_shader_signature.constant_data.resize(constant_sum);
	mpr_variable.resource_signature.all_shader_signature.texture_data.resize(texture_sum);


	// ���ʖ��������Ă���ꏊ�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("ASRESOURCE=");


	// �萔�o�b�t�@�̎��ʖ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("CON:");

	// �萔�o�b�t�@�̎��ʖ����擾����
	for (int now_constant = 0; now_constant < constant_sum; now_constant++)
	{
		mpr_variable.resource_signature.all_shader_signature.constant_data[now_constant].signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
	}


	// �e�N�X�`���̎��ʖ��̍s�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("TEX:");

	// �e�N�X�`���̎��ʖ����擾����
	for (int now_texture = 0; now_texture < texture_sum; now_texture++)
	{
		mpr_variable.resource_signature.all_shader_signature.texture_data[now_texture].signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
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
	// �S�ẴV�F�[�_�[�̋��ʏ��̈ʒu��T���A�Ȃ���Έ�ԍŏ��ɖ߂��Ă�����x�T������A����ł��Ȃ���΃G���[
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("SHADERSTART=") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("SHADERSTART=") == false)
		{
			return false;
		}
	}


	// �S�ẴV�F�[�_�[�ɋ��ʂ���ݒ�����[�h
	M_Load_All_Shader_Resource_Signature(in_shader_data_file);

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


	// �� �V�F�[�_�[�̎�ނ��ƂɎ��ʂɎg�p���镶����ς��� ���@//
	switch (in_shader_kind)
	{
	//  ���_�V�F�[�_�[  //
	case (int)ASSET::SHADER::E_SHADER_KIND::e_VERTEX:
		shader_type_text = "VS";
		break;

		//  �n���V�F�[�_�[  //
	case (int)ASSET::SHADER::E_SHADER_KIND::e_HUL_TCS:
		shader_type_text = "HS";
		break;

		//  �h���C���V�F�[�_�[  //
	case (int)ASSET::SHADER::E_SHADER_KIND::e_DOMAIN_TES:
		shader_type_text = "DS";
		break;

		//  �W�I���g���V�F�[�_�[  //
	case (int)ASSET::SHADER::E_SHADER_KIND::e_GEOMETRY:
		shader_type_text = "GS";
		break;

		//  �s�N�Z���V�F�[�_�[  //
	case (int)ASSET::SHADER::E_SHADER_KIND::e_PIXEL_FRAGMENT:
		shader_type_text = "PS";
		break;
	}


	// �V�F�[�_�[�̏��̈ʒu��T���A�Ȃ���Έ�ԍŏ��ɖ߂��Ă�����x�T������A����ł��Ȃ���΂��̃V�F�[�_�[�͖��g�p
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START=") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START=") == false)
		{
			return true;
		}
	}


	// �� �ϐ��錾 �� //
	std::string shader_name;	// �V�F�[�_�[��


	// �V�F�[�_�[�����擾����
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "NAME:");
	shader_name = in_shader_data_file.M_Get_Data_By_Text(",");

	// �V�F�[�_�[���擾����
	mpr_variable.shader_code.list[in_shader_kind] = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Get_Shader_Setting((ASSET::SHADER::E_SHADER_KIND)in_shader_kind, shader_name);

	// �擾�ł��Ă��Ȃ���΂܂���������Ă��Ȃ��̂Ń��[�h����
	if (mpr_variable.shader_code.list[in_shader_kind] == nullptr)
	{
		mpr_variable.shader_code.list[in_shader_kind] = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Load_Shader_Setting_By_Name((ASSET::SHADER::E_SHADER_KIND)in_shader_kind, shader_name);


		// ���[�h�Ɏ��s������false�Ŕ�����
		if (mpr_variable.shader_code.list[in_shader_kind] == nullptr)
		{
			return false;
		}
	}


	// �� �ϐ��錾 �� //
	int constant_sum = 0;	// �萔�̐�
	int texture_sum = 0;	// �e�L�X�g�̐�


	// ���\�[�X���̏ꏊ�܂ňړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "SUM=");

	// �萔�o�b�t�@�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("CON:");
	constant_sum = in_shader_data_file.M_Get_Number();

	// �e�L�X�g�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("TEX:");
	texture_sum = in_shader_data_file.M_Get_Number();

	// �T���v���[�����擾
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("SAMP:");
	mpr_variable.resource_signature.signature_list[in_shader_kind].sampler_sum = in_shader_data_file.M_Get_Number();


	// ���ʖ��������Ă���ꏊ�Ɉړ�
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "RESOUCE=");


	// �萔�o�b�t�@������Ȃ环�ʗp�̏���ݒ肷��
	if (constant_sum > 0)
	{
		// �擾���������萔�o�b�t�@�̎��ʖ��𐶐�
		mpr_variable.resource_signature.signature_list[in_shader_kind].constant_data.resize(constant_sum);

		// �萔�o�b�t�@�̎��ʖ����擾����
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("CON:");
		for (int now_constant = 0; now_constant < constant_sum; now_constant++)
		{
			mpr_variable.resource_signature.signature_list[in_shader_kind].constant_data[now_constant].signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
			in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		}
	}


	// �e�N�X�`��������Ȃ环�ʗp�̏���ݒ肷��
	if (texture_sum > 0)
	{
		// �擾���������萔�o�b�t�@�̎��ʖ��𐶐�
		mpr_variable.resource_signature.signature_list[in_shader_kind].texture_data.resize(texture_sum);

		// �e�N�X�`���̎��ʖ����擾����
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column("TEX:");
		for (int now_texture = 0; now_texture < texture_sum; now_texture++)
		{
			mpr_variable.resource_signature.signature_list[in_shader_kind].texture_data[now_texture].signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
			in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		}
	}

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
	for (int now_kind = 0; now_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_kind++)
	{
		if (mpr_variable.shader_code.list[now_kind])
		{
			ASSET::SHADER::MANAGER::C_Shader_Manager::M_Released_Shader_Setting_Once((ASSET::SHADER::E_SHADER_KIND)now_kind, mpr_variable.shader_code.list[now_kind]);
		}
	}


	// ���_���C�A�E�g�̍폜
	mpr_variable.vertex_layout_setting.clear();
	mpr_variable.vertex_layout_setting.shrink_to_fit();


	// �S�̋��ʂ̃��\�[�X��`�p�������ׂč폜
	mpr_variable.resource_signature.all_shader_signature.constant_data.clear();
	mpr_variable.resource_signature.all_shader_signature.constant_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.texture_data.clear();
	mpr_variable.resource_signature.all_shader_signature.texture_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.sampler_sum = 0;


	// �V�F�[�_�[���Ƃ̃��\�[�X��`�p�������ׂč폜
	for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
	{
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].sampler_sum = 0;
	}

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[���t�@�C���̓��e��ǂݎ���Ċe��V�F�[�_�[�����[�h���A���_���C�A�E�g�ƃ��\�[�X�̒�`��ݒ肷��
// ����   �Fstd::string �ǂݍ��ރV�F�[�_�[���̖��O
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Setting::M_Load_Shaders_Inform_By_Shader_Setting_Name(std::string in_shader_setting_name)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager text_file_system;	// �e�L�X�g�ƃt�@�C���p�V�X�e��

	std::string shader_name;	// �V�F�[�_�[�f�[�^������t�H���_�p�X


	// �V�F�[�_�[�ݒ薼���t�@�C���p�X�ɕϊ�����
	in_shader_setting_name = "project/asset/shader/inform/setting/" + in_shader_setting_name + ".elshadersetting";


	// �t�@�C���ǂݎ��	// ���s�����甲����
	if (text_file_system.M_Load_Select_File(in_shader_setting_name) == false)
	{
		return false;
	}


	// ���_���C�A�E�g�����	// ���s�����甲����
	if (M_Load_Vertex_Layout(text_file_system) == false)
	{
		return false;
	}


	// �V�F�[�_�[�����[�h���ă��\�[�X�̒�`������	// ���s�����甲����
	if (M_Load_Shaders_And_Setting_Resource_Signature(text_file_system) == false)
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
const S_Shader_Byte_Code_List & C_Shader_Setting::M_Get_Shader_Code_List(void) const
{
	return mpr_variable.shader_code;
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