//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[����p�̃N���X
// ����   �F�V�F�[�_�[�̓ǂݎ��Ə����o���A�Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Shader_Code.h"
#include "E_Shader_Kind.h"


// �� �l�[���X�y�[�X �� //

// �����_�����O�Ɏg�p����V�F�[�_�[���Ăяo�����߂̖��O
namespace ASSET::SHADER::MANAGER
{
	// �� �N���X �� //

	// �V�F�[�_�[�̐���p�V�X�e��
	class C_Shader_Manager
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //
		
		// �V�F�[�_�[���̍\����
		struct S_Shader_Manage_Inform
		{
			std::unique_ptr<C_Shader_Code> shader = nullptr;	// �V�F�[�_�[�ݒ�

			std::string name = "DEFAULT";	// �V�F�[�_�[�ݒ薼

			int user_sum = 0;	// ���̃V�F�[�_�[���������Ă���V�X�e���̐�
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<std::vector<S_Shader_Manage_Inform>> shader_inform_list;	// �V�F�[�_�[���̃��X�g
		};

		SPr_Variable mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Shader_Manager m_this;	// �V�F�[�_�[����p�V�X�e���̃V���O���g�����p�C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g��������
		C_Shader_Manager(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Shader_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�V�F�[�_�[�f�[�^��Ԃ��@�����F�V�F�[�_�[�̎��, �V�F�[�_�[�ݒ�̖��O�@�߂�l�F�w�肳�ꂽ�V�F�[�_�[�f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static C_Shader_Code * M_Get_Shader_Setting(E_SHADER_KIND, std::string);


		//-��- ���[�h -��-//

		// �V�F�[�_�[������}�e���A�������[�h����@�����F�V�F�[�_�[�̎�ށ@�߂�l�F���������V�F�[�_�[�f�[�^�ւ̃A�h���X
		static C_Shader_Code * M_Load_Shader_Setting_By_Name(E_SHADER_KIND, std::string);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�V�F�[�_�[�ݒ�̏��L����������邱�Ƃ�ʒm����@�����F�V�F�[�_�[�̎��, ���L�����������V�F�[�_�[�ݒ�̃A�h���X�̎Q��
		static void M_Released_Shader_Setting_Once(E_SHADER_KIND, C_Shader_Code * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

