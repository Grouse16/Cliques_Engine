//����������������������������������������������//
// �ڍ�   �F�V�X�e���n�����Ǘ����郊�X�g�̓�����J�v�Z��������V�X�e��
// ����   �F�����A�폜�A�擾���s���āA�V�X�e���̔h���ɂ�����N���X�ȊO��S�ă��X�g����e�����Ƃ��ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE
#define D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Game_System_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃V�X�e���̃��X�g�̃R���Z�v�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::GAME_SYSTEM::LIST::CONCEPT
{
	// �� �R���Z�v�g�N���X �� //

	// �V�X�e���̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_System_Class = std::is_base_of<GAME::INSTANCE::GAME_SYSTEM::BASE::C_Game_System_Base, C_Check_Instance > ::value;
}


// �� �}�N�� �� //
#define D_SYSTEM_TEMPLATE template <GAME::INSTANCE::GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_System>	// �V�X�e���̃e���v���[�g��`�p�}�N��


// �Q�[���̃V�X�e���̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::GAME_SYSTEM::LIST
{
	// �� �N���X �� //

	// �V�X�e���n���̃��X�g�A�V�X�e�����N���X���ƂɊǗ����Ă���
	D_SYSTEM_TEMPLATE class C_Game_System_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, std::unique_ptr<C_System>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_System> Type_System;	// �V�X�e���̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Game_System_List<C_System> m_sound_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g��������
		C_Game_System_List(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Game_System_List(void);


		//-��- ���� -��-//

		// �V�X�e���𐶐�����@�����Fstring ��������V�X�e���̖��O�@�߂�l�FC_System * ���������V�X�e���̃A�h���X
		static C_System * M_Create_System(std::string);


		//-��- �폜 -��-//

		// �폜�̃t���O�������Ă���V�X�e��������
		static void M_Delete_System_Update(void);

		// �V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��V�X�e����S�č폜����
		static void M_Delete_System_Is_Not_Scene_Over(void);

		// �폜�̃t���O�������Ă���C���X�^���X�̍폜�̎��s
		void M_Delete_Instance_Execute(void) override;

		// �啔���̃C���X�^���X�̍폜���s��
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// �S�ẴC���X�^���X�̍폜���s��
		void M_Delete_All_Instance_Execute(void) override;


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�V�X�e���̃��X�g��Ԃ��@�߂�l�Fvector<Type_System> & �w�肳�ꂽ�V�X�e���̃��X�g
		static std::vector<Type_System> & M_Get_System_List(void);

		// �w�肳�ꂽ���O�̃V�X�e���̃A�h���X��Ԃ��@�߂�l�FC_System * ���O����v�����V�X�e���̃A�h���X
		static C_System* M_Get_System_By_Name(std::string);


		//-��- �X�V -��-//

		// �V�X�e���̍X�V���s��
		void M_Instance_Update(void) override;


		//-��- �`�� -��-//

		// �`��͂Ȃ����G���[�h�~�p�ɒ�`
		void M_Instance_Draw(void) override;
	};


	// �� �֐� �� //

	//==�� �v���C�x�[�g ��==//

	//-��- ������ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline C_Game_System_List<C_System>::C_Game_System_List()
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//==�� �p�u���b�N ��==//

	// �� �֐� �� //

	//-��- �I���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�f�X�g���N�^
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline C_Game_System_List<C_System>::~C_Game_System_List(void)
	{
		// �������Ă��郊�X�g��S�ĊJ�����z���_�[���폜����
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_All_Instance();

		return;
	}


	//-��- ���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�V�X�e���𐶐�����
	// ����   �Fstring ��������V�X�e���̖��O
	// �߂�l �FC_System * ���������V�X�e���̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline C_System* C_Game_System_List<C_System>::M_Create_System(std::string in_sound_name)
	{
		// �� �ϐ��錾 �� //
		Type_System& sound_slot_address =		// �V�����V�X�e���p�̃X���b�g�̎Q��

			// �V�����V�X�e���p�̃X���b�g�𐶐�����
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Create_Instance(in_sound_name);


		// �V�X�e���𐶐����A���̃V�X�e���̃N���X�p�̃��X�g�Ɋi�[����
		sound_slot_address.reset(new C_System());

		// �V�����������ꂽ�V�X�e���̃A�h���X��Ԃ�
		return sound_slot_address.get();
	}


	//-��- �폜 -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�폜�̃t���O�������Ă���V�X�e��������
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_System_Update(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_ramada = [](Type_System& in_check_sound)
			{
				// �C���X�^���X�폜�̃t���O�������Ă���Ȃ�폜���A�z�񂩂炱�̗v�f���폜����
				if (in_check_sound->M_Get_Destroy_Instance_Flg())
				{
					in_check_sound.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��V�X�e����S�č폜����
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_System_Is_Not_Scene_Over(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_ramada = [](Type_System& in_check_sound)
			{
				// �V�[���J�ڎ��Ɏc��t���O�������Ă��Ȃ��Ȃ�폜����
				if (in_check_sound->M_Get_Scene_Over_Flg() == false)
				{
					in_check_sound.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_Instance_Execute(void)
	{
		M_Delete_System_Update();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�啔���̃C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_System_Is_Not_Scene_Over();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_All_Instance();

		return;
	}


	//-��- �Q�b�^ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ�V�X�e���̃��X�g��Ԃ�
	// ����   �Fvoid
	// �߂�l �Fvector<unique_ptr<C_System>> & �w�肳�ꂽ�V�X�e���̃��X�g
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline std::vector<std::unique_ptr<C_System>> & C_Game_System_List<C_System>::M_Get_System_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ���O�̃V�X�e���̃A�h���X��Ԃ�
	// ����   �Fvoid
	// �߂�l �FC_System * ���O����v�����V�X�e���̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline C_System * C_Game_System_List<C_System>::M_Get_System_By_Name(std::string in_search_name)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_System>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();	// �V�X�e���̃��X�g


		// �S�ẴV�X�e����T�����A���������炻�̃A�h���X��Ԃ�
		for (Type_System & now_sound : sound_list)
		{
			if (now_sound.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_sound.get();
			}
		}

		// ������Ȃ������ꍇ�́Anull��Ԃ�
		return nullptr;
	}


	//-��- �X�V -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�V�X�e���̍X�V���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Instance_Update(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_System>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();	// �V�X�e���̃��X�g


		// �V�X�e�����X�V����
		for (Type_System & now_sound : sound_list)
		{
			now_sound->M_System_Update();
		}

		return;
	}


	//-��- �`�� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�`��͂Ȃ����G���[�h�~�p�ɒ�`
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Instance_Draw(void)
	{
		return;
	}
}


// �� �}�N���폜 �� //
#undef D_SYSTEM_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE


