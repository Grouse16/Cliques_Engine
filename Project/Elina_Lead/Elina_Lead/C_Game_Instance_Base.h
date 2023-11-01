//����������������������������������������������//
// �ڍ�   �F�Q�[���C���X�^���X�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>


// �� �l�[���X�y�[�X �� //

// �Q�[���̃I�u�W�F�N�g�̊��ƂȂ�V�X�e�����Ăяo�����߂̖��O
namespace GAME::INSTANCE::BASE
{
	// �� �N���X �� //

	// �Q�[����̃C���X�^���X�̊��ƂȂ�N���X
	class C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		std::string m_name = "default";	// �C���X�^���X��

		bool m_flg_destroy_instance = false;	// �Q�[���C���X�^���X���폜���邩�ǂ����̃t���O


		//==�� �p�u���b�N ��==//
	public:

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Game_Instance_Base(void);

		// �f�X�g���N�^
		virtual ~C_Game_Instance_Base(void) = 0;


		//-��- �Z�b�^ -��-//

		// �C���X�^���X����ݒ肷��@�����F�ݒ肷��C���X�^���X�̖��O
		void M_Set_Instance_Name(std::string);


		//-��- �Q�b�^ -��-//

		// �C���X�^���X���폜���邩�ǂ����̃t���O�̒l��Ԃ��@�߂�l�F�C���X�^���X���폜���邩�ǂ����̃t���O
		bool M_Get_Destroy_Instance_Flg(void);

		// �C���X�^���X����Ԃ��@�߂�l�F�C���X�^���X�̖��O�iconst�^�j
		const std::string & M_Get_Instance_Name(void);


		//-��- �폜 -��-//

		// �폜�̎��s��\������
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE



