//����������������������������������������������//
// �ڍ�   �F�C���X�^���X�������X�g�̑S�Ă̌��ƂȂ���N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_LIST_ALL_BASE
#define D_INCLUDE_GUARD_C_LIST_ALL_BASE


// �� �t�@�C���Ђ炫 �� //
#include <vector>


// �� �l�[���X�y�[�X �� //

// �C���X�^���X�������X�g�̑S�Ă̌��ƂȂ���N���X���Ăяo�����߂̖��O
namespace SYSTEM::LIST::BASE::ALL_LIST_BASE
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

		// �D��x�̃��X�g��Ԃ��@�߂�l�Fvector<int> & �D��x�̃��X�g
		std::vector<int> & M_Get_Priority_List(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_List_All_Base(void);

		// �f�X�g���N�^
		virtual ~C_List_All_Base(void);


		//-��- �X�V -��-//

		// ���X�g���̃C���X�^���X�̍X�V���s��
		virtual void M_Instance_Update(void) = 0;


		//-��- �`�� -��-//

		// ���X�g���̃C���X�^���X�̕`����s��
		virtual void M_Instance_Draw(void) = 0;


		//-��- �폜 -��-//

		// �ꕔ�̃C���X�^���X�̍폜���s��
		virtual void M_Delete_Instance_Execute(void) = 0;

		// �S�ẴC���X�^���X�̍폜���s��
		virtual void M_Delete_All_Instance_Execute(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_LIST_ALL_BASE

