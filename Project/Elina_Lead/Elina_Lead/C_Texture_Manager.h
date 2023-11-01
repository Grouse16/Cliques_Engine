//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���𐧌䂷�邽�߂̃V�X�e��
// ����   �F�e�N�X�`���̃��[�h�������s������A�d�����ē����e�N�X�`�������[�h���Ȃ��悤�ɊǗ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>
#include <string>

#include "C_Texture_Data_System.h"


// �� �l�[���X�y�[�X �� //
namespace ASSET::TEXTURE::MANAGER
{
	// �� �N���X �� //

	// �e�N�X�`������p�V�X�e��
	class C_Texture_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// �e�N�X�`���Ǘ��p�̍\����
		struct S_Texture_Manage_Inform
		{
			std::unique_ptr<RENDERING::CAPSULE::C_Texture_Data_System> texture = nullptr;	// �e�N�X�`���p�̃V�X�e��

			std::string name = "DEFAULT";	// �e�N�X�`����

			int user_sum = 0;	// ���̃e�N�X�`�����g�p���Ă���C���X�^���X��
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Texture_Manage_Inform> texture_list;	// �e�N�X�`�����܂Ƃ߂����X�g

			RENDERING::CAPSULE::C_Texture_Data_System reset_texture;	// �e�N�X�`�������Z�b�g���邽�߂̃e�N�X�`���f�[�^

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Texture_Manager m_this;	// �e�N�X�`������p�̃V�X�e��

		
		// �� �ϐ��錾 �� //
		
		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Texture_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �e�N�X�`������p�̃V�X�e��������������
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Texture_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�e�N�X�`����Ԃ��@�����F�e�N�X�`���̖��O�@�߂�l�F�w�肳�ꂽ�e�N�X�`���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Texture_By_Name(std::string);


		//-��- ���[�h -��-//

		// �e�N�X�`��������e�N�X�`�������[�h����@�����F�e�N�X�`�����@�߂�l�F���������e�N�X�`���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Load_Texture_By_Name(std::string);


		//-��- ���� -��-//

		// ���Z�b�g�p�̃e�N�X�`����Ԃ��@�߂�l�F�e�N�X�`����񃊃Z�b�g���̃e�N�X�`���̎Q��(const)
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Reset_Texture(void);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�e�N�X�`���ݒ�̏��L����������邱�Ƃ�ʒm����@�����F���L�����������e�N�X�`���ݒ�̃A�h���X�̎Q��
		static void M_Release_Texture(RENDERING::CAPSULE::C_Texture_Data_System * & );
	};
}


#endif  // !D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE
