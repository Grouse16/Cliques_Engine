//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃A�N�^�[�̊��N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::BASE
{
	// �� �N���X �� //

	// �A�N�^�[�̊��ƂȂ�N���X
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==// 
	private:

		// �� �ϐ��錾 �� //
		



		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �D��x -��-//

		// �A�N�^�[�̗D��x��Ԃ��@�߂�l�F�A�N�^�[�̗D��x
		virtual int M_Get_Priority(void) = 0;


		//-��- �X�V -��-//

		// �A�N�^�[�̍X�V���s��
		virtual void M_Actor_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


