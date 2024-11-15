//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͔���̏�Ԃ��w�肷���
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE
#define D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE


// �� �l�[���X�y�[�X �� //

// �Q�[���̓��͌n�����Ăяo�����߂̖��O
namespace GAME::INPUT::COLLISION
{
	// �� �� �� //

	// �Q�[���̓��͔���̏�Ԃ��w�肷���
	enum class E_Game_Input_Collision_State
	{
		e_NOT_HIT,		// �J�[�\���ɐG��Ă��Ȃ�
		
		e_OVERED,		// �J�[�\������ɂ���
		
		e_CLICK_START,	// �N���b�N���J�n���ꂽ
		e_CLICK_DOING,	// �N���b�N��
		e_CLICK_END,	// �N���b�N�I��
		
		e_DOUBLE_CLICK_START,	// �_�u���N���b�N�J�n
		e_DOUBLE_CLICK_DOING,	// �_�u���N���b�N��
		e_DOUBLE_CLICK_END,		// �_�u���N���b�N�I��

		e_DRAG_START,	// �h���b�O�J�n��
		e_DRAG_DOING,	// �h���b�O��
		e_DRAG_END,		// �h���b�O�I��

		e_DRAG_OVERED,			// ���̓��͔���̃h���b�O���쒆�ɃJ�[�\�����d�Ȃ��Ă���
		e_DRAG_OVER_DROPPED,	// ���̓��͔���̃h���b�O���쒆�ɏ�ŃJ�[�\���𗣂��ꂽ
	};
}


#endif // !D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE
