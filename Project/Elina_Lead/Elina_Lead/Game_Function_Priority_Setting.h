//����������������������������������������������//
// �ڍ�   �F�@�\�̗D��x�ݒ���s�����߂̋��
// ����   �F�X�V�̗D��x��`��̗D��x��ݒ肷��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_FUNCTION_PRIORITY_SETTING_H_FILE
#define D_INCLUDE_GUARD_FUNCTION_PRIORITY_SETTING_H_FILE


// �� �l�[���X�y�[�X �� //

// �@�\�̗D��x�̒�`���Ăяo�����߂̖��O
namespace GAME::FUNCTION::PRIOTRITY
{
	// �� �萔 �� //

	// �V�[���O�̍X�V�̗D��x
	enum class E_Game_BEFORE_UPDATE_PRIORITY
	{
		// �� ����l �� //
		e_INVALID = -1,	// ����


		// �� �ʏ펞�X�V �� //
		e_ALL_TIME_1 = 0,	// �펞�X�V

		// �� ��{�X�V �� //
		e_Game_FRAME_WORK,	// �^�u�̍X�V


		// �� ������ԗD��x������ �� //
	};


	// �V�[����̍X�V�̗D��x
	enum class E_Game_AFTER_UPDATE_PRIORITY
	{
		// �� ����l �� //
		e_INVALID = -1,	// ����

		// �� �ʏ펞�X�V �� //
		e_ALL_TIME_1 = 0,	// �펞�X�V
	};


	// �V�[��������̕`��̗D��x
	enum class E_BEFORE_Game_DRAW_PRIORITY
	{
		// �� ����l �� //
		e_INVALID = -1,	// ����

		// �� ���R��ʗD��x �� //	// ���������͎��R�ɔԍ���U���
		e_SCREEN_1 = 0,	// ���R�ȕ`��̗D��x1
		
		// �� ������ԏ�ɕ\������� �� //
	};


	// �V�[��������̕`��̗D��x
	enum class E_AFTER_Game_DRAW_PRIORITY
	{
		// �� ����l �� //
		e_INVALID = -1,	// ����

		// �� ���R��ʗD��x �� //	// ���������͎��R�ɔԍ���U���
		e_SCREEN_1 = 0,	// ���R�ȕ`��̗D��x1
		e_SCREEN_2,		// ���R�ȕ`��̗D��x2
		e_SCREEN_3,		// ���R�ȕ`��̗D��x3
		e_SCREEN_4,		// ���R�ȕ`��̗D��x4
		e_SCREEN_5,		// ���R�ȕ`��̗D��x5
		e_SCREEN_6,		// ���R�ȕ`��̗D��x6
		e_SCREEN_7,		// ���R�ȕ`��̗D��x7
		e_SCREEN_8,		// ���R�ȕ`��̗D��x8
		e_SCREEN_9,		// ���R�ȕ`��̗D��x9
		e_SCREEN_10,	// ���R�ȕ`��̗D��x10
		e_SCREEN_11,	// ���R�ȕ`��̗D��x11
		e_SCREEN_12,	// ���R�ȕ`��̗D��x12
		e_SCREEN_13,	// ���R�ȕ`��̗D��x13
		e_SCREEN_14,	// ���R�ȕ`��̗D��x14
		e_SCREEN_15,	// ���R�ȕ`��̗D��x15
		e_SCREEN_16,	// ���R�ȕ`��̗D��x16
		e_SCREEN_17,	// ���R�ȕ`��̗D��x17
		e_SCREEN_18,	// ���R�ȕ`��̗D��x18
		e_SCREEN_19,	// ���R�ȕ`��̗D��x19
		e_SCREEN_20,	// ���R�ȕ`��̗D��x20

		e_Game_FRAME_WORK,	// ��{�t���[���g����

		// �� ������ԏ�ɕ\������� �� //
	};
}


#endif // !D_INCLUDE_GUARD_FUNCTION_LAYERS_H_FILE
