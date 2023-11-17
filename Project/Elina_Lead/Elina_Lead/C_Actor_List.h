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


// �� �l�[���X�y�[�X �� //

// �Q�[���̃A�N�^�[�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::LIST
{
	// �� �R���Z�v�g�N���X �� //

	// �A�N�^�[�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Actor_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;


	// �� �N���X �� //

	// �A�N�^�[�n���̃��X�g�A�A�N�^�[���N���X���ƂɊǗ����Ă���
	template <C_Checked_Actor_Class C_Actor>
	class C_Actor_List : protected SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
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

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_Actor_List(void)
		{
			return;
		}


		//-��- �\�[�g -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�A�N�^�[���N���X���ƂɗD��x���Ƀ\�[�g����
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Sort_Actor_By_Class(void)
		{
			// �\�[�g�p�̃����_���A�~���Ƀ\�[�g����
			bool sort_lambda = [](SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * & in_left_actor, SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * & in_right_actor)
				{
					return in_left_actor->M_Get_Priority_List()[0] >= in_right_actor->M_Get_Priority_List()[0];
				};


			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda(sort_lambda);

			return;
		}


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�f�X�g���N�^
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		~C_Actor_List(void)
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
		static C_Actor * M_Creat_Actor(std::string in_actor_name)
		{
			// �� �ϐ��錾 �� //
			Type_Actor & actor_slot_address =		// �V�����A�N�^�[�p�̃X���b�g�̎Q��

				// �V�����A�N�^�[�p�̃X���b�g�𐶐�����
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Creat_Instance(in_actor_name);


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
		static void M_Delete_Actor_Update(void)
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


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�A�N�^�[�̃��X�g��Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<Type_Actor> & �w�肳�ꂽ�A�N�^�[�̃��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<Type_Actor> & M_Get_Actor_List(void)
		{
			return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���O�̃A�N�^�[�̃A�h���X��Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Actor * ���O����v�����A�N�^�[�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Actor * M_Get_Actor_By_Name(std::string in_search_name)
		{
			// �S�ẴA�N�^�[��T�����A���������炻�̃A�h���X��Ԃ�
			for (Type_Actor & now_actor : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List())
			{
				if (now_actor.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_actor.get();
				}
			}

			// ������Ȃ������ꍇ�́Anull��Ԃ�
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


