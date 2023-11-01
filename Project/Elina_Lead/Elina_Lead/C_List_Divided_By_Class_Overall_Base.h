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
	// �� �N���X �� //

	// �N���X���Ƃɕ����������X�g���Ǘ�����N���X�̊��A�h����̃��X�g���܂Ƃ߂����X�g�𐶐��ł���i�e���v���[�g�ɂ͔h����̃��X�g�̃N���X��ݒ�j
	template <template <typename> class C_List>
	class C_List_Divided_By_Class_Overall_Base
	{
		//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		std::vector<C_List * > m_list_of_all_instance_list;	// ���݂���C���X�^���X�Ǘ����X�g���܂Ƃ߂��z��

		static inline C_List_Divided_By_Class_Overall_Base<C_List> m_this;	// �V���O���g�����p�C���X�^���X


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
		// ����   �FC_List * �C���X�^���X�Ǘ����X�g�̃A�h���X
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Add_To_List_Of_All_Instance_List(C_List * in_instance_list_address)
		{
			m_this.m_list_of_all_instance_list.reserve(m_this.m_list_of_all_instance_list.size() + 1);
			m_this.m_list_of_all_instance_list.emplace_back(in_instance_list_address);

			return;
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���X�g���C���X�^���X�Ǘ����X�g�̃��X�g����폜����
		// ����   �FC_List * �C���X�^���X�Ǘ����X�g�̃A�h���X
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Delete_By_List_Of_All_Instance_List(C_List * in_instance_list_address)
		{
			m_this.m_list_of_all_instance_list.erase
			(
				std::remove_if
				(
					m_this.m_list_of_all_instance_list.begin(),
					m_this.m_list_of_all_instance_list.end(),
					[in_instance_list_address](C_List * & in_check_list)
					{
						return in_check_list == in_instance_list_address;
					}
				),
				m_this.m_list_of_all_instance_list.end()
			);
			m_this.m_list_of_all_instance_list.shrink_to_fit();

			return;
		}


		//-��- �\�[�g -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�����_���ŃC���X�^���X�z����\�[�g����
		// ����   �Ffunction<bool(C_Instance &)> �\�[�g�p�̃����_���A�S�Ă̗v�f�̊֌W��true�ɂȂ�܂Ń\�[�g�𑱂���
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Sort_Instance_By_Lambda(std::function<bool(C_List &, C_List&)> in_sort_lamda)
		{
			// �\�[�g����
			std::sort
			(
				m_this.m_list_of_all_instance_list.begin(),	// �\�[�g�̊J�n�ʒu
				m_this.m_list_of_all_instance_list.end(),	// �\�[�g�̏I���ʒu

				// �\�[�g�p�����_���A�S�Ă̗v�f�̊֌W��true�ɂȂ�܂Ń\�[�g�𑱂���A�N�C�b�N�\�[�g���s��
				in_delete_lamda
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
		// �߂�l �Fvector<C_Instance_List_Overall_Base<C_List> * > &  �����^�̑S�Ẵ��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<C_List * > & M_Get_List_Of_All_Instance_List(void)
		{
			return m_this.m_list_of_all_instance_list;
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


