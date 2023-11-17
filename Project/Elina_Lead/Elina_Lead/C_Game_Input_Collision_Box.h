//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͔�����Ƃ�{�b�N�X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Input_Collision_Manager.h"

#include "S_Rect.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̓����蔻��̓��͂̃V�X�e�����Ăяo�����߂̖��O
namespace GAME::INPUT::COLLISION
{
	// �� �N���X �� //

	// �Q�[���̓��͔�����Ƃ�{�b�N�X
	class C_Game_Input_Collision_Box : public GAME::INPUT::COLLISION::C_Game_Input_Collision
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			DATA::RECTSETTING::S_Rect collision_rect;	// ���͂��󂯕t����{�b�N�X�͈̔�
			
		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Game_Input_Collision_Box(void);

		// �f�X�g���N�^
		~C_Game_Input_Collision_Box(void) override;


		//-��- �Z�b�^ -��-//

		// �l�p�`�̓����蔻���ݒ肷��@�����F�ݒ肷�铖���蔻��̎Q��
		void M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect &);


		//-��- �Q�b�^ -��-//

		// �l�p�`�̓����蔻��̎Q�Ƃ��擾����@�߂�l�F���݂̓����蔻��̎Q��(const)
		const DATA::RECTSETTING::S_Rect & M_Get_Collision_Box(void);


		//-��- �����蔻�� -��-//

		// �w�肳�ꂽ���W�Əd�Ȃ��Ă��邩�ǂ����@�����F�����蔻��̍��W��, �����蔻��̍��W���@�߂�l�F�������Ă�����true
		bool M_Collision_To_Pixel(int, int) const override;
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


