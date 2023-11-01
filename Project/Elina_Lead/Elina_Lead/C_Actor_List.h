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
	// �� �N���X �� //

	// �A�N�^�[�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;

	// �A�N�^�[�n���̃��X�g�A�A�N�^�[���N���X���ƂɊǗ����Ă���
	template <C_Checked_Instance_Class C_Actor>
	class C_Actor_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Actor> Type_Actor;	// �A�N�^�[�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Actor_List<C_Actor> m_actor_list_this;	// �V���O���g�����p�̃C���X�^���X


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
		static void C_Sort_Actor_By_Class(void)
		{
			// �\�[�g�p�̃����_���A�~���Ƀ\�[�g����
			bool sort_lambda = [](C_Actor_List * & in_left_actor, C_Actor_List * & in_right_actor)
				{
					return in_left_actor->C_Get_Object_List()->M_Get_Priority() >= in_right_actor->C_Get_Object_List()->M_Get_Priority();
				};


			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda<>(sort_lambda);

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
		static C_Actor * C_Creat_Actor(std::string in_actor_name)
		{
			// �� �ϐ��錾 �� //
			Type_Actor & actor_slot_address =		// �V�����A�N�^�[�p�̃X���b�g�̎Q��

				// �V�����A�N�^�[�p�̃X���b�g�𐶐�����
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Creat_Instance(in_actor_name);


			// �A�N�^�[�𐶐����A���̃A�N�^�[�̃N���X�p�̃��X�g�Ɋi�[����
			actor_slot_address.reset(new Type_Actor());

			// �V�����������ꂽ�A�N�^�[�̃A�h���X��Ԃ�
			return actor_slot_address.get();
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�폜�̃t���O�������Ă���A�N�^�[������
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void C_Delete_Actor_Update(void)
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
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_Instance_By_Lambda(delete_lambda);

			return;
		}


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�A�N�^�[�̃��X�g��Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<Type_Actor> & �w�肳�ꂽ�A�N�^�[�̃��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<Type_Actor> & C_Get_Actor_List(void)
		{
			return m_this.m_instance_list;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���O�̃A�N�^�[�̃A�h���X��Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Actor * ���O����v�����A�N�^�[�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Actor * C_Get_Actor_By_Name(std::string in_search_name)
		{
			// �S�ẴA�N�^�[��T�����A���������炻�̃A�h���X��Ԃ�
			for (Type_Actor & now_actor : m_this.m_instance_list)
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


