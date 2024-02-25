//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̐ݒ���܂Ƃ߂������Ǘ�����N���X
// ����   �F���d�ɓ������̂����[�h����Ȃ��悤�ɐ��䂵�A�K�v���Ȃ��Ȃ����V�F�[�_�[�̐ݒ���폜����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER
#define D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>
#include <string>

#include "C_Shader_Setting.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�̐ݒ�𐧌䂷�邽�߂̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::SHADER::MANAGER
{
	// �� �N���X �� //

	// �V�F�[�_�[�̐ݒ���܂Ƃ߂������Ǘ�����N���X
	class C_Shader_Setting_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// �V�F�[�_�[�̐ݒ���Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Shader_Setting_Inform
		{
			std::unique_ptr<C_Shader_Setting> shader_setting_data = nullptr;	// �V�F�[�_�[�ݒ�

			std::string name = "default";	// �V�F�[�_�[�ݒ薼
			
			int user_sum = 0;	// ���̃f�[�^���g�p���Ă���C���X�^���X��
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Shader_Setting_Inform> shader_setting_list;	// �V�F�[�_�[�ݒ�̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Shader_Setting_Manager m_this;	// ���N���X���V���O���g�������邽�߂̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g��������
		C_Shader_Setting_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Shader_Setting_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�V�F�[�_�[�ݒ��Ԃ��@�����F�V�F�[�_�[�ݒ�̖��O�@�߂�l�F�w�肳�ꂽ�V�F�[�_�[�ݒ�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static ASSET::SHADER::C_Shader_Setting * M_Get_Shader_Setting_By_Name(std::string);


		//-��- ���[�h -��-//

		// �V�F�[�_�[�ݒ薼����V�F�[�_�[�ݒ�����[�h����@�����F�V�F�[�_�[�ݒ薼�@�߂�l�F���������V�F�[�_�[�ݒ�ւ̃A�h���X
		static ASSET::SHADER::C_Shader_Setting * M_Load_Shader_Setting_By_Name(std::string);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�V�F�[�_�[�ݒ�̏��L����������邱�Ƃ�ʒm����@�����F���L�����������V�F�[�_�[�ݒ�̃A�h���X�̎Q��
		static void M_Release_Shader(ASSET::SHADER::C_Shader_Setting * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER
