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
			RENDERING::CAPSULE::C_Texture_Data_System * texture_data = nullptr;	// �g�p����e�N�X�`���f�[�^�ւ̎Q��

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

		// �w�肳�ꂽ���O�̃e�N�X�`����ǂݍ��ށ@�����F�e�N�X�`����
		void M_Load_Texture(std::string);


		//-��- �`�� -��-//

		// ���̃e�N�X�`����`��p�ɃZ�b�g����@�����F�ݒ��̃C���f�b�N�X�ԍ�
		void M_Texture_Attach_To_Draw(int);
	};
}

#endif // !D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
