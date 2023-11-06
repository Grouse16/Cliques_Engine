//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�ݒ���g�p���邽�߂̃N���X
// ����   �F�V�F�[�_�[�ݒ�}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�n�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �N���X �� //

	// �V�F�[�_�[�ݒ���g�p���邽�߂̃N���X
	class C_Shader_Setting_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			C_Shader_Setting * shader_settting_address = nullptr;	// �g�p����V�F�[�_�[�ݒ�̃A�h���X

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Shader_Setting_User(void);

		// �f�X�g���N�^
		~C_Shader_Setting_User(void);

		// ���������������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃V�F�[�_�[�ݒ��ǂݍ��ށ@�����F�V�F�[�_�[�ݒ薼
		void M_Load_Shader_Setting(std::string);


		//-��- �Q�b�^ -��-//

		// ���������Ă���V�F�[�_�[�ݒ��Ԃ��@�߂�l�F���݂̃V�F�[�_�[�ݒ�
		C_Shader_Setting * M_Get_Shader_Setting(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE

