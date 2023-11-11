//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[���g�p���邽�߂̃N���X
// ����   �F�V�F�[�_�[�}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SHADER_USER_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "E_Shader_Kind.h"
#include "C_Shader_Code.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�n���̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �N���X �� //
	
	// �V�F�[�_�[���g�p���邽�߂̃N���X
	class C_Shader_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::SHADER::C_Shader_Code * shader_code_address = nullptr;	// �g�p����V�F�[�_�[�R�[�h�ւ̃A�h���X

			ASSET::SHADER::E_SHADER_KIND use_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_VERTEX;	// �擾�����V�F�[�_�[�̎��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //
		
		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Shader_User(void);

		// �f�X�g���N�^
		~C_Shader_User(void);

		// ���������������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃V�F�[�_�[��ǂݍ��ށ@�����F���[�h����V�F�[�_�[�̎��, ���[�h����V�F�[�_�[��
		void M_Load_Shader_Code(ASSET::SHADER::E_SHADER_KIND, std::string);


		//-��- �Q�b�^ -��-//

		// ���������Ă���V�F�[�_�[�R�[�h��Ԃ��@�߂�l�F���݂̃V�F�[�_�[�R�[�h
		C_Shader_Code * M_Get_Shader_Code(void) const;

		// �������Ă���V�F�[�_�[�R�[�h�̃V�F�[�_�[�̎�ނ�Ԃ��@�߂�l�F�V�F�[�_�[�̎��
		E_SHADER_KIND M_Get_Shader_Kind(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_USER_H_FILE
