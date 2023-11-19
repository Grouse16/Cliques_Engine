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
#include "C_Post_Effect_Draw_Manager.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃|�X�g�G�t�F�N�g�̃��X�g�p�R���Z�v�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::POST_EFFECT::LIST::CONCEPT
{
	// �� �R���Z�v�g�N���X �� //

	// �|�X�g�G�t�F�N�g�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Post_Effect_Class = std::is_base_of<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base, C_Check_Instance>::value;
}


// �� �}�N�� �� //
#define D_POST_EFFECT_TEMPLATE template <GAME::INSTANCE::POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>	// �|�X�g�G�t�F�N�g�̃e���v���[�g��`�p�}�N��


// �Q�[���̃|�X�g�G�t�F�N�g�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::POST_EFFECT::LIST
{
	// �� �N���X �� //

	// �|�X�g�G�t�F�N�g�n���̃��X�g�A�|�X�g�G�t�F�N�g���N���X���ƂɊǗ����Ă���
	D_POST_EFFECT_TEMPLATE class C_Post_Effect_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base < C_Post_Effect_List, std::unique_ptr<C_Post_Effect>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Post_Effect> Type_Post_Effect;	// �|�X�g�G�t�F�N�g�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Post_Effect_List<C_Post_Effect> m_post_effect_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g��������
		C_Post_Effect_List(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//
		
		// �f�X�g���N�^
		~C_Post_Effect_List(void);


		//-��- ���� -��-//

		// �|�X�g�G�t�F�N�g�𐶐�����@�����Fstring ���������|�X�g�G�t�F�N�g�̖��O�@�߂�l�FC_Post_Effect * ���������|�X�g�G�t�F�N�g�̃A�h���X
		static C_Post_Effect * M_Create_Post_Effect(std::string);


		//-��- �폜 -��-//

		// �폜�̃t���O�������Ă���|�X�g�G�t�F�N�g������
		static void M_Delete_Post_Effect_Update(void);

		// �V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��|�X�g�G�t�F�N�g��S�č폜����
		static void M_Delete_Post_Effect_Is_Not_Scene_Over(void);

		// �폜�̃t���O�������Ă���C���X�^���X�̍폜�̎��s
		void M_Delete_Instance_Execute(void) override;

		// �啔���̃C���X�^���X�̍폜���s��
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// �S�ẴC���X�^���X�̍폜���s��
		void M_Delete_All_Instance_Execute(void) override;


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g��Ԃ��@�߂�l�Fvector<Type_Post_Effect> & �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g
		static std::vector<Type_Post_Effect> & M_Get_Post_Effect_List(void);

		// �w�肳�ꂽ���O�̃|�X�g�G�t�F�N�g�̃A�h���X��Ԃ��@�߂�l�FC_Post_Effect * ���O����v�����|�X�g�G�t�F�N�g�̃A�h���X
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string);


		//-��- �X�V -��-//

		// �|�X�g�G�t�F�N�g�̍X�V���s��
		void M_Instance_Update(void) override;


		//-��- �`�� -��-//

		// �|�X�g�G�t�F�N�g�̕`�揈�����s���A�����ł́AUI�̑O�ɂ�����|�X�g�G�t�F�N�g��UI�̂��ƂɊ|����|�X�g�G�t�F�N�g�ŕ������
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
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect_List<C_Post_Effect>::C_Post_Effect_List(void)
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
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect_List<C_Post_Effect>::~C_Post_Effect_List(void)
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
	D_POST_EFFECT_TEMPLATE inline static C_Post_Effect * C_Post_Effect_List<C_Post_Effect>::M_Create_Post_Effect(std::string in_post_effect_name)
	{
		// �� �ϐ��錾 �� //
		Type_Post_Effect& post_effect_slot_address =		// �V�����|�X�g�G�t�F�N�g�p�̃X���b�g�̎Q��

			// �V�����|�X�g�G�t�F�N�g�p�̃X���b�g�𐶐�����
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Create_Instance(in_post_effect_name);


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
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Post_Effect_Update(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_lambda = [](Type_Post_Effect& in_check_post_effect)
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


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�V�[���J�ڂō폜���Ȃ��t���O�������Ă��Ȃ��|�X�g�G�t�F�N�g��S�č폜����
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Post_Effect_Is_Not_Scene_Over(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_lambda = [](Type_Post_Effect & in_check_post_effect)
			{
				// �V�[���J�ڎ��Ɏc��t���O�������Ă��Ȃ��Ȃ�폜����
				if (in_check_post_effect->M_Get_Scene_Over_Flg() == false)
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


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Post_Effect_Update();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�啔���̃C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_Post_Effect_Is_Not_Scene_Over();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_All_Instance();

		return;
	}


	//-��- �Q�b�^ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g��Ԃ�
	// ����   �Fvoid
	// �߂�l �Fvector<unique_ptr<C_Post_Effect>> & �w�肳�ꂽ�|�X�g�G�t�F�N�g�̃��X�g
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline std::vector<std::unique_ptr<C_Post_Effect>> & C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ���O�̃|�X�g�G�t�F�N�g�̃A�h���X��Ԃ�
	// ����   �Fvoid
	// �߂�l �FC_Post_Effect * ���O����v�����|�X�g�G�t�F�N�g�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect * C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_By_Name(std::string in_search_name)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// �|�X�g�G�t�F�N�g�̃��X�g


		// �S�Ẵ|�X�g�G�t�F�N�g��T�����A���������炻�̃A�h���X��Ԃ�
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			if (now_post_effect.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_post_effect.get();
			}
		}


		// ������Ȃ������ꍇ�́Anull��Ԃ�
		return nullptr;
	}


	//-��- �X�V -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�|�X�g�G�t�F�N�g�̍X�V���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE void C_Post_Effect_List<C_Post_Effect>::M_Instance_Update(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// �|�X�g�G�t�F�N�g�̃��X�g


		// �|�X�g�G�t�F�N�g�̍X�V���s��
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			now_post_effect->M_Post_Effect_Update();
		}

		return;
	}


	//-��- �`�� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�|�X�g�G�t�F�N�g�̕`�揈�����s���A�����ł́AUI�̑O�ɂ�����|�X�g�G�t�F�N�g��UI�̂��ƂɊ|����|�X�g�G�t�F�N�g�ŕ`��̃��X�g�𕪂���
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_POST_EFFECT_TEMPLATE void C_Post_Effect_List<C_Post_Effect>::M_Instance_Draw(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// �|�X�g�G�t�F�N�g�̃��X�g


		// �|�X�g�G�t�F�N�g��`��p���X�g�ɒǉ�����
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Set_Post_Effect_Before_UI(now_post_effect);
			GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Set_Post_Effect_After_UI(now_post_effect);
		}

		return;
	}
}


// �� �}�N���폜 �� //
#undef D_POST_EFFECT_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


