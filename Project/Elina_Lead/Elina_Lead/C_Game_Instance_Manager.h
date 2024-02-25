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
#include "C_Post_Effect_List.h"
#include "C_Sound_List.h"
#include "C_Game_System_List.h"


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
		static void M_All_Instance_Destroy_Update(void);

		// �C���X�^���X�̃V�[���J�ڎ��̍폜���s��
		static void M_Instance_Destroy_On_Scene_Change(void);

		// �S�ẴC���X�^���X���폜����
		static void M_Delete_All_Instance(void);


		//-��- �X�V -��-//

		// �S�ẴA�N�^�[�̍X�V������
		static void M_Update_Actor(void);

		// �S�Ă�UI�̍X�V������
		static void M_Update_UI(void);

		// �S�Ẵ|�X�g�G�t�F�N�g�̍X�V������
		static void M_Update_Post_Effect(void);

		// �S�ẴT�E���h�̍X�V������
		static void M_Update_Sound(void);

		// �S�ẴQ�[���V�X�e���̍X�V������
		static void M_Update_Game_System(void);


		//-��- �`�� -��-//

		// �S�ẴA�N�^�[�̕`�������
		static void M_Draw_Actor(void);

		// �|�X�g�G�t�F�N�g��`��p���X�g�ɒǉ�����
		static void M_Set_Post_Effect_To_Draw_List(void);

		// UI�̑O�Ƀ|�X�g�G�t�F�N�g��������`�������
		static void M_Draw_Post_Effect_Before_UI(void);

		// �S�Ă�UI��`�悷��
		static void M_Draw_UI(void);

		// UI�̌�Ƀ|�X�g�G�t�F�N�g��������`�������
		static void M_Draw_Post_Effect_After_UI(void);


		//-��- ���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃A�N�^�[�𐶐�����
		// ����   �Fstring �ݒ肷��A�N�^�[��
		// �߂�l �FC_Actor * �������ꂽ�A�N�^�[�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Create_Actor(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Create_Actor(in_actor_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ�UI�𐶐�����
		// ����   �Fstring �ݒ肷��UI��
		// �߂�l �FC_UI * �������ꂽUI�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Create_UI_List(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Create_UI(in_ui_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃|�X�g�G�t�F�N�g�𐶐�����
		// ����   �Fstring �ݒ肷��|�X�g�G�t�F�N�g��
		// �߂�l �FC_Post_Effect * �������ꂽ�|�X�g�G�t�F�N�g�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Create_Post_Effect_List(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Create_Post_Effect(in_post_effect_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃T�E���h�𐶐�����
		// ����   �Fstring �ݒ肷��T�E���h��
		// �߂�l �FC_Sound * �������ꂽ�T�E���h�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Create_Sound_List(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Create_Sound(in_sound_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃Q�[���V�X�e���𐶐�����
		// ����   �Fstring �ݒ肷��Q�[���V�X�e����
		// �߂�l �FC_Game_System * �������ꂽ�Q�[���V�X�e���̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_List(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Create_System(in_game_system_name);
		}


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
		// �ڍ�   �F�w�肳�ꂽ��ނ̃|�X�g�G�t�F�N�g�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_Post_Effect>> & �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static std::vector<std::unique_ptr<C_Post_Effect>>& M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃T�E���h�̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_Sound>> & �w�肳�ꂽ�T�E���h�̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނ̃Q�[���V�X�e���̃��X�g���擾����
		// ����   �Fvoid
		// �߂�l �Fvector<unique_ptr<C_Game_System>> & �w�肳�ꂽ�Q�[���V�X�e���̃��X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static std::vector<std::unique_ptr<C_Game_System>> & M_Get_Game_System_List(void)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނŁA�w�肳�ꂽ���O�̃A�N�^�[�擾����
		// ����   �Fstring �擾����A�N�^�[��
		// �߂�l �FC_Actor * �w�肳�ꂽ�A�N�^�[�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Get_Actor_By_Name(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_By_Name(in_actor_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނŁA�w�肳�ꂽ���O��UI�̃��X�g���擾����
		// ����   �Fstring �擾����UI��
		// �߂�l �FC_UI * �w�肳�ꂽUI�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Get_UI_By_Name(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_By_Name(in_ui_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނŁA�w�肳�ꂽ���O�̃|�X�g�G�t�F�N�g�̃��X�g���擾����
		// ����   �Fstring �擾����|�X�g�G�t�F�N�g��
		// �߂�l �FC_Post_Effect * �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_By_Name(in_post_effect_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނŁA�w�肳�ꂽ���O�̃T�E���h�̃��X�g���擾����
		// ����   �Fstring �擾����T�E���h��
		// �߂�l �FC_Sound * �w�肳�ꂽ�T�E���h�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Get_Sound_By_Name(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_By_Name(in_sound_name);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ��ނŁA�w�肳�ꂽ���O�̃Q�[���V�X�e���̃��X�g���擾����
		// ����   �Fstirng �擾����Q�[���V�X�e����
		// �߂�l �FC_Game_System * �w�肳�ꂽ�Q�[���V�X�e���̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_By_Name(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_By_Name(in_game_system_name);
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
