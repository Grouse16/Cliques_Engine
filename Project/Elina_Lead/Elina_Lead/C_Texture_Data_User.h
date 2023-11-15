//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���̃f�[�^���g�p���邽�߂̃N���X
// ����   �F�e�N�X�`���̎擾�A���[�h�A������~���ɍs���Astatic�ł���}�l�[�W���𑼂̎���������؂藣�����߂ɂ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
#define D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Data_System.h"


// �� �l�[���X�y�[�X �� //

// �e�N�X�`���̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::TEXTURE
{
	// �� �N���X �� //

	// �e�N�X�`���̃f�[�^���g�p���邽�߂̃N���X
	class C_Texture_Data_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::CAPSULE::C_Texture_Data_System> texture_data = nullptr;	// �g�p����e�N�X�`���f�[�^�ւ̎Q��

			std::string signature_name = "default";	// �e�N�X�`���̎��ʖ��i���[�h�����e�N�X�`���̎��ʖ����㏑������j
			ASSET::SHADER::E_SHADER_KIND shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// �e�N�X�`���̎��ʖ��i���[�h�����e�N�X�`���̐ݒ��V�F�[�_�[���㏑������j

			bool flg_original_texture = false;	// �I���W�i���̃e�N�X�`�����ǂ����̃t���O

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Texture_Data_User(void);

		// �f�X�g���N�^
		~C_Texture_Data_User(void);

		// �e�N�X�`�����������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃e�N�X�`����ǂݍ��ށ@�����F���[�h����e�N�X�`����
		void M_Load_Texture(std::string);

		// �I���W�i���̃e�N�X�`���f�[�^�𐶐�����
		void M_Create_Original_Texture_Data(void);


		//-��- �`�� -��-//

		// ���̃e�N�X�`����`��p���i���ʖ�,�V�F�[�_�[�̎�ށj������GPU�ɃZ�b�g����
		void M_Texture_Attach_To_Draw_By_Inform(void);

		// ���̃e�N�X�`����`��p�ɃZ�b�g����@�����F�ݒ��̃C���f�b�N�X�ԍ�
		void M_Texture_Attach_To_Draw_By_Index(int);


		//-��- �Q�b�^ -��-//

		// �e�N�X�`���f�[�^�̃A�h���X��Ԃ��@�߂�l�F�e�N�X�`���f�[�^�̃A�h���X
		RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Texture_Data(void);


		//-��- �Z�b�^ -��-//

		// �e�N�X�`���̎��ʖ����Z�b�g����@�����F�e�N�X�`�����ʖ�
		void M_Set_Texture_Signature(std::string);

		// �V�F�[�_�[�̎�ނ��Z�b�g����@�����F�V�F�[�_�[�̎��
		void M_Set_Texture_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);
	};
}

#endif // !D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
