//����������������������������������������������//
// �ڍ�   �F�Q�[���̋@�\�̊��C���X�^���X�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE
#define D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "Game_Function_Priority_Setting.h"



// �� �l�[���X�y�[�X �� //

// �@�\�̊��N���X���Ăяo�����߂̖��O
namespace GAME::FUNCTION
{
	// �� �N���X �� //

	// �Q�[���̃C�x���g�p�̊��N���X���`
	class C_Game_Function_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���e�N�g�̕ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			float update_period_time = 0.0f;	// �C�x���g���s�̎���

			int after_draw_priority = (int)GAME::FUNCTION::PRIOTRITY::E_AFTER_GAME_DRAW_PRIORITY::e_INVALID;	// �V�[����̕`��̗D��x�A�����قǏ�ɕ\�������

			int before_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_BEFORE_UPDATE_PRIORITY::e_INVALID;	// �V�[���O�̍X�V�̗D��x�A�����قǐ�ɍX�V�����
			int after_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_AFTER_UPDATE_PRIORITY::e_INVALID;	// �V�[����̍X�V�̗D��x�A�����قǐ�ɍX�V�����

			bool flg_function_end = false;	// �@�\���I�����邩�ǂ����̃t���O

		} mpr_variable;	// �v���e�N�g�̕ϐ����Ăяo�����߂̖��O


		//==�� �v���e�N�g ��==//
	protected:

		//-��- �X�V -��-//

		// �V�[���O�̍X�V
		virtual void M_Before_Event_Update(void);

		// �V�[����̍X�V
		virtual void M_After_Event_Update(void);


		//-��- �Z�b�^ -��-//

		// �V�[���O�̍X�V�̗D��x���x����ݒ肷��@�����F�ݒ肷��D��x
		void M_Set_Before_Update_Priority(int);

		// �V�[����̍X�V�̗D��x���x����ݒ肷��@�����F�ݒ肷��D��x
		void M_Set_After_Update_Priority(int);

		// �V�[����̕`��̗D��x���x����ݒ肷��@�����F�ݒ肷��D��x
		void M_Set_After_Draw_Priority(int);


		//== �� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Game_Function_Base(void);

		// �f�X�g���N�^
		virtual ~C_Game_Function_Base(void);


		//-��- �X�V -��-//

		// �V�[�������O�̃C�x���g���Ăяo���Ď��s����
		void M_Call_Event_Before_Scene_Process(void);

		// �V�[��������̃C�x���g���Ăяo���Ď��s����
		void M_Call_Event_After_Scene_Process(void);


		//-��- �o�� -��-//

		// �V�[���O�ɍs���o�͏���
		virtual void M_Draw_Before_Scene_Process(void);

		// �V�[����ɍs���o�͏���
		virtual void M_After_Draw_Process(void);


		//-��- �Z�b�^ -��-//

		// �C�x���g���s�̎�����ݒ肷��@�����F�ݒ肷�鎟�̎��s�܂ł̑҂�����
		void M_Set_Update_Period_Time(float);

		// �@�\���I�������邩�ǂ�����ݒ肷��@�����F�ݒ肷��I�����邩�ǂ����̃t���O
		void M_Set_Flg_End_Function(bool);


		//-��- �Q�b�^ -��-//

		// �V�[���O�̍X�V�̗D��x�̃��x����Ԃ��@�߂�l�F�D��x�̒l�̎Q��
		const int & M_Get_Before_Update_Priority(void);

		// �V�[����̍X�V�̗D��x�̃��x����Ԃ��@�߂�l�F�D��x�̒l�̎Q��
		const int & M_Get_After_Update_Priority(void);

		// �V�[����̕`��̗D��x�̃��x���Ԃ��@�߂�l�F�D��x�̒l�̎Q��
		const int & M_Get_After_Draw_Priority(void);

		// �@�\���I�����邩�ǂ����̃t���O��Ԃ��@�߂�l�F�@�\���I�����邩�ǂ����̃t���O�̎Q��
		const bool & M_Get_Flg_End_Function(void);
	};
}


#endif // !D_INCLUDE_GUARD_EVENT_BASE_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

