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

// �Q�[����UI�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::UI::LIST
{
	// �� �N���X �� //

	// UI�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::UI::BASE::C_User_Interface_Base, C_Check_Instance>::value;

	// UI�n���̃��X�g�AUI���N���X���ƂɊǗ����Ă���
	template <C_Checked_Instance_Class C_User_Interface>
	class C_User_Interface_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, std::unique_ptr<C_User_Interface>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_User_Interface> Type_UI;	// UI�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_User_Interface_List<C_User_Interface> m_UI_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_User_Interface_List(void)
		{
			return;
		}


		//-��- �\�[�g -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�z���_�[�Ƀ\�[�g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void C_User_Interface_List(void)
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
		~C_User_Interface_List(void)
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
		static C_User_Interface * C_Creat_UI(std::string in_ui_name)
		{
			// �� �ϐ��錾 �� //
			Type_UI & ui_slot_address =		// �V����UI�p�̃X���b�g�̎Q��

				// �V����UI�p�̃X���b�g�𐶐�����
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Creat_Instance(in_ui_name);


			// UI�𐶐����A����UI�̃N���X�p�̃��X�g�Ɋi�[����
			ui_slot_address.reset(new Type_UI());

			// �V�����������ꂽUI�̃A�h���X��Ԃ�
			return ui_slot_address.get();
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�폜�̃t���O�������Ă���A�N�^�[������
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void C_Delete_UI_Update(void)
		{
			// �� �����_�� �� //

			// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
			auto delete_lambda = [](Type_UI & in_check_ui)
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


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽUI�̃��X�g��Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<Type_UI> & �w�肳�ꂽUI�̃��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<Type_UI> & C_Get_UI_List(void)
		{
			return m_this.m_instance_list;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���O��UI�̃A�h���X��Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Type_User_Interface * ���O����v����UI�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_User_Interface * C_Get_UI_By_Name(std::string in_search_name)
		{
			// �S�Ă�UI��T�����A���������炻�̃A�h���X��Ԃ�
			for (Type_UI & now_ui : m_this.m_instance_list)
			{
				if (now_ui.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_ui.get();
				}
			}

			// ������Ȃ������ꍇ�́Anull��Ԃ�
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_UI_LIST_H_FILE


