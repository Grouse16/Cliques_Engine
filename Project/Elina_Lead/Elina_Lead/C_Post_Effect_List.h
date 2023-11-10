//����������������������������������������������//
// �ڍ�   �F�|�X�g�G�t�F�N�g�n�����Ǘ����郊�X�g�̓�����J�v�Z��������V�X�e��
// ����   �F�����A�폜�A�擾���s���āA�|�X�g�G�t�F�N�g�̔h���ɂ�����N���X�ȊO��S�ă��X�g����e�����Ƃ��ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Post_Effect_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃|�X�g�G�t�F�N�g�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::POST_EFFECT::LIST
{
	// �� �R���Z�v�g�N���X �� //

	// �|�X�g�G�t�F�N�g�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base, C_Check_Instance>::value;


	// �� �N���X �� //

	// �|�X�g�G�t�F�N�g�n���̃��X�g�A�|�X�g�G�t�F�N�g���N���X���ƂɊǗ����Ă���
	template <C_Checked_Instance_Class C_Post_Effect>
	class C_Post_Effect_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base < C_Post_Effect_List, std::unique_ptr<C_Post_Effect>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Post_Effect> Type_Post_Effect;	// �|�X�g�G�t�F�N�g�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Post_Effect_List<C_Post_Effect> m_post_effect_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_Post_Effect_List(void)
		{
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
		~C_Post_Effect_List(void)
		{
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_All_Instance();

			return;
		}


		//-��- ���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�|�X�g�G�t�F�N�g�𐶐�����
		// ����   �Fstring ���������|�X�g�G�t�F�N�g�̖��O
		// �߂�l �FC_Post_Effect * ���������|�X�g�G�t�F�N�g�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Post_Effect * M_Creat_Post_Effect(std::string in_post_effect_name)
		{
			// �� �ϐ��錾 �� //
			Type_Post_Effect & post_effect_slot_address =		// �V�����|�X�g�G�t�F�N�g�p�̃X���b�g�̎Q��

				// �V�����|�X�g�G�t�F�N�g�p�̃X���b�g�𐶐�����
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Creat_Instance(in_post_effect_name);


			// �|�X�g�G�t�F�N�g�𐶐����A���̃|�X�g�G�t�F�N�g�̃N���X�p�̃��X�g�Ɋi�[����
			post_effect_slot_address.reset(new C_Post_Effect());

			// �V�����������ꂽ�|�X�g�G�t�F�N�g�̃A�h���X��Ԃ�
			return post_effect_slot_address.get();
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�폜�̃t���O�������Ă���|�X�g�G�t�F�N�g������
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Delete_Post_Effect_Update(void)
		{
			// �� �����_�� �� //

			// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
			auto delete_lambda = [](Type_Post_Effect & in_check_post_effect)
				{
					// �C���X�^���X�폜�̃t���O�������Ă���Ȃ�폜���A�z�񂩂炱�̗v�f���폜����
					if (in_check_post_effect->M_Get_Destroy_Instance_Flg())
					{
						in_check_post_effect.reset();
						return true;
					}

					return false;
				};


			// ���X�g����̍폜���s��
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_Instance_By_Lambda(delete_lambda);

			return;
		}


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g��Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<Type_Post_Effect> & �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<Type_Post_Effect> & M_Get_Post_Effect_List(void)
		{
			return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���O�̃|�X�g�G�t�F�N�g�̃A�h���X��Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Post_Effect * ���O����v�����|�X�g�G�t�F�N�g�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string in_search_name)
		{
			// �S�Ẵ|�X�g�G�t�F�N�g��T�����A���������炻�̃A�h���X��Ԃ�
			for (Type_Post_Effect & now_post_effect : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List())
			{
				if (now_post_effect.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_post_effect.get();
				}
			}


			// ������Ȃ������ꍇ�́Anull��Ԃ�
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


