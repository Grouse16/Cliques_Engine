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
		bool m_draw_flg = true;			// �`�悷�邩�ǂ����̃t���O
		bool m_after_draw_flg = false;	// �ʏ�`���ɕ`�悷�邩�ǂ����̃t���O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Actor_Base(void);

		// �f�X�g���N�^
		~C_Actor_Base(void);


		//-��- �D��x -��-//

		// �A�N�^�[�̗D��x��Ԃ��@�߂�l�F�A�N�^�[�̗D��x
		virtual int M_Get_Priority(void) = 0;


		//-��- �X�V -��-//

		// �A�N�^�[�̍X�V���s��
		virtual void M_Actor_Update(void) = 0;


		//-��- �`�� -��-//

		// �A�N�^�[�`�悷��
		virtual void M_Actor_Draw(void) = 0;

		// �ʏ�`���ɃA�N�^�[��`�悷��
		virtual void M_Actor_After_Draw(void) = 0;


		//-��- �Z�b�^ -��-//

		// �A�N�^�[��ʏ�`��ŕ`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�̎��͕`�悷��Afalse�̎��͕`�悵�Ȃ�
		void M_Set_Draw_Flg(bool);

		// �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�̎��͕`�悷��Afalse�̎��͕`�悵�Ȃ�
		void M_Set_After_Draw_Flg(bool);

		
		//-��- �Q�b�^ -��-//

		// �A�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�͕`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_Draw_Flg(void);

		// �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�͕`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_After_Draw_Flg(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


