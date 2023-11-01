//����������������������������������������������//
// �ڍ�   �F�Q�[����̃C���X�^���X�𐧌䂷��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>
#include <memory>


// �� �l�[���X�y�[�X �� //

// �Q�[���̃I�u�W�F�N�g�n���̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE
{
	// �� �N���X �� //

	// �Q�[����̃C���X�^���X�𐧌䂷��N���X
	class C_Game_Instance_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Game_Instance_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �폜 -��-//

		// �Q�[����̑S�ẴC���X�^���X�̂Ȃ�����A�폜�̃t���O�������Ă�����̂�����
		void M_All_Instance_Destroy_Update(void);

		// �S�ẴC���X�^���X���폜����
		void M_Delete_All_Instance(void);


		//-��- �Q�b�^ -��-//
		
		// �w�肳�ꂽ��ނ̃A�N�^�[�̃��X�g���擾����
		template<class C_Actor>
		void M_Get_Actor_List(void);

		// �w�肳�ꂽ��ނ�UI�����X�g�̎擾����
		template<class C_UI>
		void M_Get_User_Interface_List(void);

		// �w�肳�ꂽ��ނ̃T�E���h�̃��X�g���擾����
		template<class C_Sound>
		void M_Get_Sound_List(void);

		// �w�肳�ꂽ��ނ̃|�X�g�G�t�F�N�g�̃��X�g���擾����
		template<class C_Post_Effect>
		void M_Get_Post_Effect_List(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
