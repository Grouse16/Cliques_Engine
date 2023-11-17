//����������������������������������������������//
// �ڍ�   �F�Q�[���̃V�X�e������p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_State_Manager.h"

#include <vector>


// �� �l�[���X�y�[�X �� //

// �Q�[���̐���p�̃V�X�e��
namespace GAME
{
	// �� �N���X �� //

	// �Q�[������p�V�X�e��
	class C_Game_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			bool flg_Game_exist = true;		// �Q�[�������݂��Ă��邩�ǂ����̃t���O
			bool flg_Game_activate = false;	// �Q�[�����ғ������ǂ����̃t���O
			bool flg_OS_active_now = false;		// OS�V�X�e�����ғ������ǂ����̃t���O

		} static mpr_variable;	// �ϐ����Ăяo�����߂̖��O

		static C_Game_Manager m_this;	// �Q�[������p�̃V�X�e���̎���(�V���O���g��)


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_Manager(void);

		
		//-��- �X�V -��-//

		// �f�[�^�̍X�V���s��
		static void M_Data_Update(void);

		// �E�B���h�E�^�C�g���̍X�V
		static void M_Window_Title_Update(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �Q�[���̏�����
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_Manager(void);

		// ���������
		static void M_Release(void);


		//-��- �Z�b�^ -��-//

		// �Q�[���𑶍݂��Ă����Ԃ��ǂ�����ݒ肷��@�����Ftrue�͐���ɑ��݂��Ă���
		static void M_Set_Game_Exist_Flg(bool);

		// �Q�[�����ғ������ǂ�����ݒ肷��@�����Ftrue�͉ғ���
		static void M_Set_Game_Activate_Flg(bool);


		//-��- �Q�b�^ -��-//

		// �Q�[���𑶍݂��Ă����Ԃ��ǂ������擾����@�����Ftrue�͐���ɑ��݂��Ă���
		static bool M_Get_Game_Exist_Flg(void);

		// �Q�[�����A�N�e�B�u��Ԃ��ǂ�����Ԃ��@�߂�l�F�A�N�e�B�u���̂�ture
		static bool M_Get_Game_Active_Flg(void);


		//-��- ���s -��-//

		// �Q�[���̏��������s����
		static void M_Executes_Process(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
