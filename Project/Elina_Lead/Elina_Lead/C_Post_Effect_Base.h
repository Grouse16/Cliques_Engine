//����������������������������������������������//
// �ڍ�   �F�|�X�g�G�t�F�N�g�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃|�X�g�G�t�F�N�g�̊��N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::POST_EFFECT::BASE
{
	// �� �N���X �� //

	// �|�X�g�G�t�F�N�g�̊��ƂȂ�N���X
	class C_Post_Effect_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		bool m_flg_draw_before_ui = true;	// UI�`��O�Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O�Atrue�ŕ`�悷��
		bool m_flg_draw_after_ui = false;	// UI�`���Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O�Atrue�ŕ`�悷��


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Post_Effect_Base(void);

		// �f�X�g���N�^
		virtual ~C_Post_Effect_Base(void);


		//-��- �X�V -��-//

		// �|�X�g�G�t�F�N�g�̍X�V���s��
 		virtual void M_Post_Effect_Update(void) = 0;


		//-��- �`�� -��-//

		// �|�X�g�G�t�F�N�g��UI�O�̕`����s��
		virtual void M_Post_Effect_Draw_Before_UI(void) = 0;

		// �|�X�g�G�t�F�N�g��UI��̕`����s��
		virtual void M_Post_Effect_Draw_After_UI(void) = 0;


		//-��- �Z�b�^ -��-//

		// UI�`��O�Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�ŕ`�悷��Afalse�͕`�悵�Ȃ�
		void M_Set_Flg_Post_Effect_Before_UI_Draw(bool);

		// UI�`���Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�ŕ`�悷��Afalse�͕`�悵�Ȃ�
		void M_Set_Flg_Post_Effect_After_UI_Draw(bool);


		//-��- �Q�b�^ -��-//

		// UI�`��O�Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�ŕ`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_Flg_Post_Effect_Before_UI_Draw(void);

		// UI�`���Ƀ|�X�g�G�t�F�N�g��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�ŕ`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_Flg_Post_Effect_After_UI_Draw(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
