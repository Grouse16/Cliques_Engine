//����������������������������������������������//
// �ڍ�   �F�N���X���Ƃɕ����������X�g���Ǘ�����V�X�e���̊��N���X
// ����   �FC_Instance_List_Overall_Base�̔h���N���X�ɂ�����x���ʂ��ĕK�v�ȋ@�\���܂Ƃ߂��N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE
#define D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE


// �� ���ӏ��� �� //

// �h���N���X�ł͊Ǘ��͈͂ɉ����āAconcept���g������

// **** C++ 20 �ȍ~�̋@�\ **** //
// �e���v���[�g�����ɐ������������
// ���̗�ł́A�e���v���[�g�����̊��N���X��TEST_CLASS�łȂ���΃G���[���o��悤�ɂȂ�R�[�h�������Ă���i�L�^�p�j
#ifdef false
template<typename C_Class>
concept CONCEPT_CLASS = std::is_base_of<TEST_CLASS, C_Class>::value;

template <CONCEPT_CLASS TEMPLATE>
class C_INS1 : public C_Instance_List_Base<C_INS1, CONCEPT_CLASS> { };
#endif // false


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

#include "C_List_Divided_By_Class_Overall_Base.h"


// �� �l�[���X�y�[�X �� //

// ���X�g�̊��ƂȂ�V�X�e�����Ăяo�����߂̖��O
namespace SYSTEM::LIST::BASE
{
	// �� �N���X �� //

	// �N���X���Ƃɕ����������X�g���Ǘ�����V�X�e���̊��N���X
	template <template <typename> class C_List, class C_Instance>	// template <typename> class �̓e���v���[�g�����Ƀe���v���[�g�^�̃N���X��v������Ƃ�������
	class C_List_Divided_By_Class_Base : public C_List_Divided_By_Class_Overall_Base <C_List>
	{
		//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		std::vector <C_Instance> m_instance_list;	// �C���X�^���X�̊Ǘ��p���X�g

		static inline C_List_Divided_By_Class_Base<C_List, C_Instance> m_this;	// �C���X�^���X�̎��̂̃A�h���X


		// �� �֐� �� //

		//-��- ������ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_List_Divided_By_Class_Base(void)
		{
			return;
		}


		//-��- ���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�C���X�^���X�̐������s��
		// ����   �Fvoid
		// �߂�l �FC_Instance & ���������C���X�^���X�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Instance & M_Creat_Instance(void)
		{
			// ���̃��X�g���܂��C���X�^���X�������Ă��Ȃ���Ԃł�������A�Ǘ��p�z��Ƀ��X�g��o�^
			if (m_this.m_instance_list.size() <= 0)
			{
				// ���̃��X�g���܂��C���X�^���X�������Ă��Ȃ���Ԃł�������A�Ǘ��p�z��Ƀ��X�g��o�^
				C_List_Divided_By_Class_Overall_Base<C_List>::M_Add_To_List_Of_All_Instance_List(this);
			}

			// �C���X�^���X�𐶐�����
			m_this.m_instance_list.resize(m_this.m_instance_list.size() + 1);
			return m_this.m_instance_list[m_this.m_instance_list.size() - 1];
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�Ǘ����Ă���S�ẴC���X�^���X���폜����
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Delete_All_Instance(void)
		{
			// �z��f�[�^���폜
			m_this.m_instance_list.clear();
			m_this.m_instance_list.shrink_to_fit();

			// �f�[�^�������Ă��Ȃ��̂Ń��X�g����o�^����
			C_List_Divided_By_Class_Overall_Base<C_List>::M_Delete_By_List_Of_All_Instance_List(this);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�n���ꂽ�����_���̏����ɓ��Ă͂܂�C���X�^���X������
		// ����   �Ffunction<bool(C_Instance &)> �폜�C���X�^���X�̃`�F�b�N�p�̃����_��
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static void M_Delete_Instance_By_Lambda(std::function<bool(C_Instance & )> in_delete_lambda)
		{
			// �w�肳�ꂽ�����ʂ�̃C���X�^���X���폜����
			m_this.m_instance_list.before_func_update_list.erase
			(
				std::remove_if
				(
					m_this.m_instance_list.begin(), 
					m_this.m_instance_list.end(), 
					in_delete_lambda
				), 
				m_this.m_instance_list.end()
			);


			// ���X�g�̃f�[�^��S�č폜�����̂Ȃ�A���X�g��o�^��������
			if (m_this.m_instance_list.size() <= 0)
			{
				C_List_Divided_By_Class_Overall_Base<C_List>::M_Delete_By_List_Of_All_Instance_List(this);
			}

			return;
		}


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���̃��X�g�̎��̂̎Q�Ƃ�Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Instance_List_Base<C_List, C_Instance> & ���X�g�̎��̂̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_List_Divided_By_Class_Base<C_List, C_Instance> & M_Get_List_Instance(void)
		{
			return m_this;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�C���X�^���X�̃��X�g�̎Q�Ƃ�Ԃ�
		// ����   �Fvoid
		// �߂�l �Fstd::vector <C_Instance> & ���X�g�̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<C_Instance> & M_Get_List(void)
		{
			return m_this.m_instance_list;
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
		virtual ~C_List_Divided_By_Class_Base(void) override
		{
			return;
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



