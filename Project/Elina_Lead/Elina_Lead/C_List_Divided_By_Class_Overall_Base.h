//����������������������������������������������//
// �ڍ�   �F�N���X���Ƃɕ����������X�g���Ǘ�����N���X�̊��A�h����̃��X�g���܂Ƃ߂����X�g�𐶐��ł���i�e���v���[�g�ɂ͔h����̃��X�g�̃N���X��ݒ�j
// ����   �F�e���v���[�g�ɔh����̃��X�g�̃N���X��ݒ肷�邱�ƂŁA�ݒ肵�����X�g���������ꂽ�ꍇ�ł��A�����̃��X�g��z��Ƃ��Ă܂Ƃ߂���V�X�e����p�ӂ��Ă���iOverall�́u�S�̂́v�Ƃ����Ӗ��j
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h ���@//
#ifndef D_INCLUDE_GUARD_C_INSTANCE_LIST_OVERALL_BASE_H_FILE
#define D_INCLUDE_GUARD_C_INSTANCE_LIST_OVERALL_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X �� //

// ���X�g�̊��ƂȂ�V�X�e�����Ăяo�����߂̖��O
namespace SYSTEM::LIST::BASE
{
	// �C���X�^���X�������X�g�̑S�Ă̌��ƂȂ���N���X���Ăяo�����߂̖��O
	namespace ALL_LIST_BASE
	{
		// �� �N���X �� //

		// �C���X�^���X�������X�g�̑S�Ă̌��ƂȂ���N���X
		class C_List_All_Base
		{
			//==�� �v���e�N�g ��==//
		protected:

			// �� �ϐ��錾 �� //
			std::vector<int> m_priority_list;	// �D��x�̃��X�g


			// �� �֐� �� //

			//-��- �Q�b�^ -��-//

			//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
			// �ڍ�   �F�D��x�̃��X�g��Ԃ�
			// ����   �Fvoid
			// �߂�l �Fvector<int> & �D��x�̃��X�g
			//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
			std::vector<int> & M_Get_Priority_List(void)
			{
				return m_priority_list;
			}
		};
	}


	// �� �N���X �� //

	// �N���X���Ƃɕ����������X�g���Ǘ�����N���X�̊��A�h����̃��X�g���܂Ƃ߂����X�g�𐶐��ł���i�e���v���[�g�ɂ͔h����̃��X�g�̃N���X��ݒ�j
	template <template <typename> class C_List>
	class C_List_Divided_By_Class_Overall_Base : public ALL_LIST_BASE::C_List_All_Base
	{
		//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		static inline std::vector<C_List_All_Base * > m_list_of_all_instance_list;	// ���݂���C���X�^���X�Ǘ����X�g���܂Ƃ߂��z��


		// �� �֐� �� //

		//-��- ������ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�A�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_List_Divided_By_Class_Overall_Base(void)
		{
			return;
		}


		//-��- �ǉ� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���X�g���C���X�^���X�Ǘ����X�g�̃��X�g�ɉ�����
		// ����   �FC_List_All_Base * �C���X�^���X�Ǘ����X�g�̃A�h���X
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Add_To_List_Of_All_Instance_List(C_List_All_Base * in_instance_list_address)
		{
			m_list_of_all_instance_list.reserve(m_list_of_all_instance_list.size() + 1);
			m_list_of_all_instance_list.emplace_back(in_instance_list_address);

			return;
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���X�g���C���X�^���X�Ǘ����X�g�̃��X�g����폜����
		// ����   �FC_List_All_Base * �C���X�^���X�Ǘ����X�g�̃A�h���X
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Delete_By_List_Of_All_Instance_List(C_List_All_Base * in_instance_list_address)
		{
			m_list_of_all_instance_list.erase
			(
				std::remove_if
				(
					m_list_of_all_instance_list.begin(),
					m_list_of_all_instance_list.end(),
					[in_instance_list_address](C_List_All_Base * & in_check_list)
					{
						return in_check_list == in_instance_list_address;
					}
				),
				m_list_of_all_instance_list.end()
			);
			m_list_of_all_instance_list.shrink_to_fit();

			return;
		}


		//-��- �\�[�g -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�����_���ŃC���X�^���X�z����\�[�g����
		// ����   �Ffunction<bool(C_List_All_Base &, C_List_All_Base &)> �\�[�g�p�̃����_���A�S�Ă̗v�f�̊֌W���Atrue�ɂȂ�܂Ń\�[�g�𑱂���
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Sort_Instance_By_Lambda(std::function<bool(C_List_All_Base &, C_List_All_Base &)> in_sort_lambda)
		{
			// �\�[�g����
			std::sort
			(
				m_list_of_all_instance_list.begin(),	// �\�[�g�̊J�n�ʒu
				m_list_of_all_instance_list.end(),	// �\�[�g�̏I���ʒu

				// �\�[�g�p�����_���A�S�Ă̗v�f�̊֌W���Atrue�ɂȂ�܂Ń\�[�g�𑱂���A�N�C�b�N�\�[�g���s��
				in_sort_lambda
			);

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
		virtual ~C_List_Divided_By_Class_Overall_Base(void)
		{
			return;
		}


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�e���v���[�g�����^�̃C���X�^���X�Ǘ����X�g���܂Ƃ߂��z��̎Q�Ƃ�Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<C_List_All_Base * > &  �����^�̑S�Ẵ��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<C_List_All_Base * > & M_Get_List_Of_All_Instance_List(void)
		{
			return m_list_of_all_instance_list;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��


