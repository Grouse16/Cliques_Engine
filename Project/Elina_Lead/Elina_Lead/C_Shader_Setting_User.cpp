//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�ݒ���g�p���邽�߂̃N���X
// ����   �F�V�F�[�_�[�ݒ�}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting_User.h"
#include "C_Shader_Setting_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ��������������� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting_User::C_Shader_Setting_User(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting_User::~C_Shader_Setting_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting_User::M_Release(void)
{
	if (mpr_variable.shader_settting_address)
	{
		ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Release_Shader(mpr_variable.shader_settting_address);
	}

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃V�F�[�_�[�ݒ��ǂݍ���
// ����   �Fstring �V�F�[�_�[�ݒ薼
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting_User::M_Load_Shader_Setting(std::string in_shader_setting_name)
{
	// �� �ϐ��錾 �� //
	C_Shader_Setting * new_shader_setting_address = nullptr;	// �V�����V�F�[�_�[�ݒ�̃A�h���X


	// �V�F�[�_�[�ݒ�̖��O����T�����Ď擾
	new_shader_setting_address = ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Get_Shader_Setting_By_Name(in_shader_setting_name);

	// �w�肵���V�F�[�_�[�ݒ肪�܂��Ȃ��Ȃ琶������
	if (new_shader_setting_address == nullptr)
	{
		new_shader_setting_address = ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Load_Shader_Setting_By_Name(in_shader_setting_name);

		// �����Ɏ��s�����甲����
		if (new_shader_setting_address == nullptr)
		{
			return;
		}
	}


	// �擾�ł����V�F�[�_�[�ݒ�Ɠ���ւ���
	M_Release();
	mpr_variable.shader_settting_address = new_shader_setting_address;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������Ă���V�F�[�_�[�ݒ��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Shader_Setting * ���݂̃V�F�[�_�[�ݒ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting * ASSET::SHADER::C_Shader_Setting_User::M_Get_Shader_Setting(void)
{
	return mpr_variable.shader_settting_address;
}


