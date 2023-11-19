//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�n�����Ǘ����郊�X�g�̓�����J�v�Z��������V�X�e��
// ����   �F�����A�폜�A�擾���s���āA�A�N�^�[�̔h���ɂ�����N���X�ȊO��S�ă��X�g����e�����Ƃ��ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Actor_Base.h"
#include "C_Actor_Draw_Manager.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃A�N�^�[�̃��X�g�p�̃R���Z�v�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::LIST::CONCEPT
{
	// �� �R���Z�v�g�N���X �� //

	// �A�N�^�[�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Actor_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;
}


// �� �}�N�� �� //
#define D_ACTOR_TEMPLATE template <GAME::INSTANCE::ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>	// �e���v���[�g�^��`�p�}�N��


// �� �l�[���X�y�[�X �� //

// �Q�[���̃A�N�^�[�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::LIST
{
	// �� �N���X �� //
	
	// �A�N�^�[�n���̃��X�g�A�A�N�^�[���N���X���ƂɊǗ����Ă���
	D_ACTOR_TEMPLATE class C_Actor_List : protected SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Actor> Type_Actor;	// �A�N�^�[�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Actor_List<C_Actor> m_this;	// �V���O���g�����p�̃C���X�^���X

		bool m_actor_is_nothing = true;	// �A�N�^�[�������Ă��Ȃ���Ԃ̎��݂̂��t���O


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g��������
		C_Actor_List(void);


		//-��- �\�[�g -��-//

		// �A�N�^�[���N���X���ƂɗD��x���Ƀ\�[�g����
		static void M_Sort_Actor_By_Class(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Actor_List(void);

		
		//-��- ���� -��-//

		// �A�N�^�[�𐶐�����@�����Fstring ���������A�N�^�[�̖��O�@�߂�l�FC_Actor * ���������A�N�^�[�̃A�h���X
		static C_Actor * M_Create_Actor(std::string);


		//-��- �폜 -��-//

		// �폜�̃t���O�������Ă���A�N�^�[������
		static void M_Delete_Actor_Update(void);

		// �V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��A�N�^�[��S�č폜����
		static void M_Delete_Actor_Is_Not_Scene_Over(void);

		// �폜�̃t���O�������Ă���C���X�^���X�̍폜�̎��s
		void M_Delete_Instance_Execute(void) override;

		// �啔���̃C���X�^���X�̍폜���s��
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// �S�ẴC���X�^���X�̍폜���s��
		void M_Delete_All_Instance_Execute(void) override;


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�A�N�^�[�̃��X�g��Ԃ��@�߂�l�Fvector<Type_Actor> & �w�肳�ꂽ�A�N�^�[�̃��X�g
		static std::vector<Type_Actor> & M_Get_Actor_List(void);

		// �w�肳�ꂽ���O�̃A�N�^�[�̃A�h���X��Ԃ��@�߂�l�FC_Actor * ���O����v�����A�N�^�[�̃A�h���X
		static C_Actor * M_Get_Actor_By_Name(std::string);


		//-��- �X�V -��-//

		// �A�N�^�[�̍X�V���s��
		void M_Instance_Update(void) override;


		//-��- �`�� -��-//

		// �A�N�^�[�̕`�揈�����s���A�����ł͋߂��A�N�^�[���珇�ɕ��ׂ��`��p�̔z������
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
	D_ACTOR_TEMPLATE inline C_Actor_List<C_Actor>::C_Actor_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�A�N�^�[���N���X���ƂɗD��x���Ƀ\�[�g����
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Sort_Actor_By_Class(void)
	{
		// �\�[�g�p�̃����_���A�~���Ƀ\�[�g����
		bool sort_lambda = [](SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base*& in_left_actor, SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base*& in_right_actor)
			{
				return in_left_actor->M_Get_Priority_List()[0] >= in_right_actor->M_Get_Priority_List()[0];
			};


		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda(sort_lambda);

		return;
	}


	//==�� �p�u���b�N ��==//

	//-��- �I���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�f�X�g���N�^
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline C_Actor_List<C_Actor>::~C_Actor_List(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_All_Instance();

		return;
	}


	//-��- ���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�A�N�^�[�𐶐�����
	// ����   �Fstring ���������A�N�^�[�̖��O
	// �߂�l �FC_Actor * ���������A�N�^�[�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline C_Actor * C_Actor_List<C_Actor>::M_Create_Actor(std::string in_actor_name)
	{
		// �� �ϐ��錾 �� //
		Type_Actor & actor_slot_address =		// �V�����A�N�^�[�p�̃X���b�g�̎Q��

			// �V�����A�N�^�[�p�̃X���b�g�𐶐�����
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Create_Instance(in_actor_name);


		// �A�N�^�[�𐶐����A���̃A�N�^�[�̃N���X�p�̃��X�g�Ɋi�[����
		actor_slot_address.reset(new C_Actor());


		// ��̖ڂ��V�����ǉ����ꂽ��N���X�̗D��x��ǉ����đS�̂��\�[�g����
		if (m_actor_is_nothing)
		{
			// �� �ϐ��錾 �� //
			std::vector<int> & priority_list = SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base::M_Get_Priority_List();	// �D��x�̃��X�g

			int priority_list_slot = priority_list.size();	// �D��x�ݒ��̃X���b�g


			// �D��x��o�^����
			priority_list.resize(priority_list_slot + 1);
			priority_list[priority_list_slot] = actor_slot_address->M_Get_Priority();

			// �\�[�g�����s
			M_Sort_Actor_By_Class();

			// �A�N�^�[���������̂ŃA�N�^�[���Ȃ���Ԃ̃t���O��������
			m_actor_is_nothing = false;
		}


		// �V�����������ꂽ�A�N�^�[�̃A�h���X��Ԃ�
		return actor_slot_address.get();
	}


	//-��- �폜 -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�폜�̃t���O�������Ă���A�N�^�[������
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Actor_Update(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_lambda = [](Type_Actor & in_check_actor)
			{
				// �C���X�^���X�폜�̃t���O�������Ă���Ȃ�폜���A�z�񂩂炱�̗v�f���폜����
				if (in_check_actor->M_Get_Destroy_Instance_Flg())
				{
					in_check_actor.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		m_actor_is_nothing = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_Instance_By_Lambda(delete_lambda);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��A�N�^�[��S�č폜����
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Actor_Is_Not_Scene_Over(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_lambda = [](Type_Actor & in_check_actor)
			{
				// �V�[���J�ڎ��Ɏc��t���O�������Ă��Ȃ��Ȃ�폜����
				if (in_check_actor->M_Get_Scene_Over_Flg() == false)
				{
					in_check_actor.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		m_actor_is_nothing = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_Instance_By_Lambda(delete_lambda);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�폜�̃t���O�������Ă���C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Actor_Update();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�啔���̃C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_Actor_Is_Not_Scene_Over();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_All_Instance();
		C_Actor_List<C_Actor>::Type_Actor;
		return;
	}


	//-��- �Q�b�^ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ�A�N�^�[�̃��X�g��Ԃ�
	// ����   �Fvoid
	// �߂�l �Fvector<unique_ptr<C_Actor>> & �w�肳�ꂽ�A�N�^�[�̃��X�g
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline std::vector<std::unique_ptr<C_Actor>> & C_Actor_List<C_Actor>::M_Get_Actor_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ���O�̃A�N�^�[�̃A�h���X��Ԃ�
	// ����   �Fvoid
	// �߂�l �FC_Actor * ���O����v�����A�N�^�[�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline C_Actor * C_Actor_List<C_Actor>::M_Get_Actor_By_Name(std::string in_search_name)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// �A�N�^�[�̃��X�g


		// �S�ẴA�N�^�[��T�����A���������炻�̃A�h���X��Ԃ�
		for (Type_Actor & now_actor : actor_list)
		{
			if (now_actor.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_actor.get();
			}
		}

		// ������Ȃ������ꍇ�́Anull��Ԃ�
		return nullptr;
	}


	//-��- �X�V -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�A�N�^�[�̍X�V���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Instance_Update(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// �A�N�^�[�̃��X�g


		// �S�ẴA�N�^�[���X�V����
		for (Type_Actor & now_actor : actor_list)
		{
			now_actor->M_Component_Update();
			now_actor->M_Actor_Update();
			now_actor->M_Delete_Component_Update();
		}

		return;
	}


	//-��- �`�� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�A�N�^�[�̕`�揈�����s���A�����ł͋߂��A�N�^�[���珇�ɕ��ׂ��`��p�̔z������
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Instance_Draw(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// �A�N�^�[�̃��X�g


		// �A�N�^�[��`�惊�X�g�ɒǉ�
		for (std::unique_ptr<C_Actor> & actor_address : actor_list)
		{
			GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Set_Actor_To_Draw_List(actor_address.get());
			GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Set_Actor_To_After_Draw_List(actor_address.get());
		}

		return;
	}
}


// �� �}�N���폜 �� //
#undef D_ACTOR_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


