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

#include "C_Actor_List.h"
#include "C_User_Interface_List.h"
#include "C_Sound_List.h"
#include "C_Post_Effect_List.h"


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


		//-��- �X�V -��-//


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃A�N�^�[�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_Actor>> & �w�肳�ꂽ�A�N�^�[�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static std::vector<std::unique_ptr<C_Actor>> & M_Get_Actor_List(void)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ�UI�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_UI>> & �w�肳�ꂽUI�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static std::vector<std::unique_ptr<C_UI>> & M_Get_UI_List(void)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃T�E���h�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_Sound>> & �w�肳�ꂽ�T�E���h�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<SOUND::LIST::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃|�X�g�G�t�F�N�g�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<UI>> & �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<SOUND::LIST::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Sound>::M_Get_Post_Effect_List();
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
