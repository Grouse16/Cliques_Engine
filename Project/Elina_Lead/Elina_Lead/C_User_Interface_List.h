//����������������������������������������������//
// �ڍ�   �FUI�n�����Ǘ����郊�X�g�̓�����J�v�Z��������V�X�e��
// ����   �F�����A�폜�A�擾���s���āAUI�̔h���ɂ�����N���X�ȊO��S�ă��X�g����e�����Ƃ��ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_UI_LIST_H_FILE
#define D_INCLUDE_GUARD_C_UI_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_User_Interface_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[����UI�̃��X�g�p�̃R���Z�v�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::UI::LIST::CONCEPT
{
	// �� �R���Z�v�g�N���X �� //

	// UI�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_UI_Class = std::is_base_of<GAME::INSTANCE::UI::BASE::C_User_Interface_Base, C_Check_Instance>::value;
}


// �� �}�N�� �� //
#define D_UI_TEMPLATE template <GAME::INSTANCE::UI::LIST::CONCEPT::C_Checked_UI_Class C_User_Interface>	// UI�̃e���v���[�g��`�p�}�N��


// �Q�[����UI�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::UI::LIST
{
	// �� �N���X �� //

	// UI�n���̃��X�g�AUI���N���X���ƂɊǗ����Ă���
	D_UI_TEMPLATE class C_User_Interface_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, std::unique_ptr<C_User_Interface>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_User_Interface> Type_UI;	// UI�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_User_Interface_List<C_User_Interface> m_UI_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g��������
		C_User_Interface_List(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_User_Interface_List(void);


		//-��- ���� -��-//

		// UI�𐶐�����@�����F��������UI�̖��O�@�߂�l�FC_Instance_List_Base<C_User_Interface_List, Type_UI>::S_Instance_Inform & ��������UI�̃A�h���X
		static C_User_Interface * M_Create_UI(std::string);


		//-��- �폜 -��-//

		// �폜�̃t���O�������Ă���A�N�^�[������
		static void M_Delete_UI_Update(void);

		// �C���X�^���X�̍폜���s��
		void M_Delete_Instance_Execute(void) override;

		// �S�ẴC���X�^���X�̍폜���s��
		void M_Delete_All_Instance_Execute(void) override;


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽUI�̃��X�g��Ԃ��@�߂�l�Fvector<Type_UI> & �w�肳�ꂽUI�̃��X�g
		static std::vector<Type_UI> & M_Get_UI_List(void);

		// �w�肳�ꂽ���O��UI�̃A�h���X��Ԃ��@�߂�l�FC_Type_User_Interface * ���O����v����UI�̃A�h���X
		static C_User_Interface * M_Get_UI_By_Name(std::string);


		//-��- �X�V -��-//

		// UI�̍X�V���s��
		void M_Instance_Update(void) override;


		//-��- �`�� -��-//

		// UI��`�惊�X�g�ɒǉ�����
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
	D_UI_TEMPLATE inline C_User_Interface_List<C_User_Interface>::C_User_Interface_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//==�� �p�u���b�N ��==//

	//-��- �I���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�f�X�g���N�^
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline C_User_Interface_List<C_User_Interface>::~C_User_Interface_List(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_All_Instance();

		return;
	}


	//-��- ���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �FUI�𐶐�����
	// ����   �Fstring ��������UI�̖��O
	// �߂�l �FC_Instance_List_Base<C_User_Interface_List, Type_UI>::S_Instance_Inform & ��������UI�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline C_User_Interface * C_User_Interface_List<C_User_Interface>::M_Create_UI(std::string in_ui_name)
	{
		// �� �ϐ��錾 �� //
		Type_UI& ui_slot_address =		// �V����UI�p�̃X���b�g�̎Q��

			// �V����UI�p�̃X���b�g�𐶐�����
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Create_Instance(in_ui_name);


		// UI�𐶐����A����UI�̃N���X�p�̃��X�g�Ɋi�[����
		ui_slot_address.reset(new C_User_Interface());

		// �V�����������ꂽUI�̃A�h���X��Ԃ�
		return ui_slot_address.get();
	}


	//-��- �폜 -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�폜�̃t���O�������Ă���A�N�^�[������
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_UI_Update(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_lambda = [](Type_UI& in_check_ui)
			{
				// �C���X�^���X�폜�̃t���O�������Ă���Ȃ�폜���A�z�񂩂炱�̗v�f���폜����
				if (in_check_ui->M_Get_Destroy_Instance_Flg())
				{
					in_check_ui.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_Instance_By_Lambda(delete_lambda);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_Instance_Execute(void)
	{
		M_Delete_UI_Update();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_All_Instance();

		return;
	}


	//-��- �Q�b�^ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽUI�̃��X�g��Ԃ�
	// ����   �Fvoid
	// �߂�l �Fvector<unique_ptr<C_User_Interface>> & �w�肳�ꂽUI�̃��X�g
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline std::vector<std::unique_ptr<C_User_Interface>> & C_User_Interface_List<C_User_Interface>::M_Get_UI_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ���O��UI�̃A�h���X��Ԃ�
	// ����   �Fvoid
	// �߂�l �FC_Type_User_Interface * ���O����v����UI�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline C_User_Interface * C_User_Interface_List<C_User_Interface>::M_Get_UI_By_Name(std::string in_search_name)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UI�̃��X�g


		// �S�Ă�UI��T�����A���������炻�̃A�h���X��Ԃ�
		for (Type_UI & now_ui : ui_list)
		{
			if (now_ui.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_ui.get();
			}
		}

		// ������Ȃ������ꍇ�́Anull��Ԃ�
		return nullptr;
	}


	//-��- �X�V -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �FUI�̍X�V���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Instance_Update(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UI�̃��X�g


		// �S�Ă�UI���X�V����
		for (Type_UI & now_ui : ui_list)
		{
			now_ui->M_UI_Update();
		}

		return;
	}


	//-��- �`�� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �FUI��`�惊�X�g�ɒǉ�����
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Instance_Draw(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UI�̃��X�g


		// �S�Ă�UI��`�悷��
		for (Type_UI & now_ui : ui_list)
		{
			now_ui->M_UI_Draw();
		}

		return;
	}
}


// �� �}�N���폜 �� //
#undef D_UI_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_UI_LIST_H_FILE


