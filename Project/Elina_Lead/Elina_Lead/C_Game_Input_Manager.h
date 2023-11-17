//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͂𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Input_Collision_Manager.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̓��͂𐧌䂷��V�X�e��
namespace GAME::INPUT
{
	// �� �N���X �� //

	// �Q�[���̓��͂𐧌䂷��V�X�e��
	class C_Game_Input_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			// �J�[�\���̍��W�p�̍\����
			struct S_Cursor_Pixel
			{
				int x = 0;	// �����W
				int y = 0;	// �����W

			};

			// �}�E�X�̔���p�̏����܂Ƃ߂��\����
			struct S_Game_Mouse_Inform
			{
				bool flg_clicking = false;			// �N���b�N���݂̂��t���O
				bool flg_double_clicking = false;	// �_�u���N���b�N���݂̂��t���O
				bool flg_dragging = false;			// �h���b�O���쒆�݂̂��t���O

				GAME::INPUT::COLLISION::C_Game_Input_Collision * clicking_collision_add = nullptr;	// �N���b�N���̔���̃A�h���X
				GAME::INPUT::COLLISION::C_Game_Input_Collision * drag_overed_add = nullptr;			// �h���b�O���̃J�[�\���̉��ɂ��锻��̃A�h���X

				S_Cursor_Pixel cursor_pixel;		// ���݂̃J�[�\���̍��W
				S_Cursor_Pixel start_clicked_pixel;	// �N���b�N���͊J�n�ʒu
				S_Cursor_Pixel end_clicked_pixel;	// �N���b�N���͏I���ʒu

			}mouse;	// �}�E�X�p�̏����Ăяo�����߂̖��O

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static std::unique_ptr<C_Game_Input_Manager> m_this;	// �C���X�^���X�����邽�߂̎��́i�V���O���g���p�j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_Input_Manager(void);


		//-��- �X�V -��-//

		// �}�E�X���͔���̍X�V
		void M_Update_Mouse_Input(void);

		// �ʏ펞�̓��͔���̍X�V
		void M_Update_Input_Collision_On_Normal_Timing(void);

		// �N���b�N���͌�̔���̍X�V
		void M_Update_Input_Collision_After_Clicked(void);

		// ���͔���̍X�V
		void M_Update_Input_Collision(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// ���͗p�V�X�e���𐶐�����
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_Input_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �X�V -��-//

		// ���͂̍X�V
		static void M_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE

