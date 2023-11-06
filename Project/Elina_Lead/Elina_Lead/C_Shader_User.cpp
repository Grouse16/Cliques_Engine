//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[���g�p���邽�߂̃N���X
// ����   �F�V�F�[�_�[�}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_User.h"
#include "C_Shader_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_User::C_Shader_User(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_User::~C_Shader_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_User::M_Release(void)
{
	if (mpr_variable.shader_code_address)
	{
		ASSET::SHADER::MANAGER::C_Shader_Manager::M_Released_Shader_Setting_Once(mpr_variable.use_shader_kind, mpr_variable.shader_code_address);
	}

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃V�F�[�_�[��ǂݍ���
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎��, string �V�F�[�_�[��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_User::M_Load_Shader_Code(ASSET::SHADER::E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// �� �ϐ��錾 �� //
	C_Shader_Code * new_shader_code_address = nullptr;	// �V�����V�F�[�_�[�̃A�h���X


	// �V�F�[�_�[�̖��O����T�����Ď擾
	new_shader_code_address = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Get_Shader_Setting(in_shader_kind, in_shader_name);

	// �w�肵���V�F�[�_�[���܂��Ȃ��Ȃ琶������
	if (new_shader_code_address == nullptr)
	{
		new_shader_code_address = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Load_Shader_By_Name(in_shader_kind, in_shader_name);

		// �����Ɏ��s�����甲����
		if (new_shader_code_address == nullptr)
		{
			return;
		}
	}


	// �擾�ł����V�F�[�_�[�Ɠ���ւ���
	M_Release();
	mpr_variable.use_shader_kind = in_shader_kind;
	mpr_variable.shader_code_address = new_shader_code_address;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������Ă���V�F�[�_�[�R�[�h��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Shader_Code * ���݂̃V�F�[�_�[�R�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Code * C_Shader_User::M_Get_Shader_Code(void) const
{
	return mpr_variable.shader_code_address;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������Ă���V�F�[�_�[�R�[�h�̃V�F�[�_�[�̎�ނ�Ԃ�
// ����   �Fvoid
// �߂�l �FE_SHADER_KIND �V�F�[�_�[�̎��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
E_SHADER_KIND C_Shader_User::M_Get_Shader_Kind(void) const
{
	return mpr_variable.use_shader_kind;
}


