//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͂̓����蔻��𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h ���@//
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>
#include <vector>

#include "E_Game_Input_Collision_State.h"
#include "Game_Input_Collision_Names.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̓��͌n�����Ăяo�����߂̖��O
namespace GAME::INPUT::COLLISION
{
	// �� �N���X �� //

	// �Q�[���̓��͂��󂯎��V�X�e���A���N���X
	class C_Game_Input_Collision
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			E_Game_Input_Collision_State collision_state;	// �����蔻��̏��

			std::wstring collision_name = GAME::INPUT::COLLISION::NAME::con_Game_INPUT_COLLISION_INITIALIZED_NAME;	// ���̓{�b�N�X��

			bool is_active = true;	// �����蔻���L���ɂ��邩�ǂ���

			int priority = 0;	// �D��x

		} mpr_variable;	// �v���C�x�[�g�ϐ����܂Ƃ߂����O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Game_Input_Collision(void);

		// �f�X�g���N�^
		virtual ~C_Game_Input_Collision(void);


		//-��- �Z�b�^ -��-//

		// �{�b�N�X�̖��O���Z�b�g����@�����F�ݒ肷��{�b�N�X��
		void M_Set_Box_Name(std::wstring);

		// �����蔻���L���ɂ��邩�ǂ������Z�b�g����@�����Ftrue�ŃA�N�e�B�u��
		void M_Set_Is_Active(bool);

		// �����蔻��̗D��x���Z�b�g����@�����F�ݒ肷��D��x
		void M_Set_Priority(int);


		//-��- �Q�b�^ -��-//

		// �����蔻��̖��O���擾����@�߂�l�F���݂̓����蔻��̖��O�̎Q��(const)
		const std::wstring & M_Get_Collision_Name(void) const;

		// �����蔻�肪�L�����ǂ������擾����@�߂�l�Ftrue�Ȃ�A�N�e�B�u
		bool M_Get_Is_Active(void) const;

		// ���݂̓����蔻��̗D��x��Ԃ��@�߂�l�F�����蔻��̗D��x
		int M_Get_Priority(void) const;


		//-��- ���� -��-//

		// �w�肳�ꂽ���W�Əd�Ȃ��Ă��邩�ǂ����@�����F�����蔻��̍��W��, �����蔻��̍��W���@�߂�l�F�������Ă�����true
		virtual bool M_Collision_To_Pixel(int, int) const = 0;


		//-��- ��Ԃ̑J�� -��-//

		// ��������Ă��Ȃ���Ԃ֑J��
		void M_Change_State_Command_Not_Hit(void);

		// �J�[�\�����d�Ȃ��Ă����Ԃ֑J��
		void M_Change_State_Command_Overed(void);

		// �N���b�N���̏�Ԃ֑J��
		void M_Change_State_Command_Clicking(void);

		// �_�u���N���b�N���̏�Ԃ֑J��
		void M_Change_State_Command_Double_Clicking(void);

		// �h���b�O���̏�Ԃ֑J��
		void M_Change_State_Command_Dragging(void);

		// �h���b�O���ɃJ�[�\�����d�Ȃ��Ă����Ԃ֑J��
		void M_Change_State_Command_Dragging_Over(void);

		// �h���b�O���ɓ����蔻��̏�Ńh���b�v���ꂽ���Ƃ�����
		void M_Change_State_Command_Drag_Dropped(void);
	};


	// �Q�[���̓��͂̓����蔻��𐧌䂷��V�X�e��
	class C_Game_Input_Collision_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<C_Game_Input_Collision * > collision_list;	// ���͔���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static std::unique_ptr<C_Game_Input_Collision_Manager> m_this;	// ���̃N���X���C���X�^���X�����邽�߂̕ϐ��i�V���O���g�����j


		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_Input_Collision_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		//-��- �������ƏI���� -��-//

		// �Q�[���̓��̓{�b�N�X����p�V�X�e���̐���
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_Input_Collision_Manager(void);

		// ���������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// ���͔���̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���͔���̃��X�g�̎Q��
		static std::vector<C_Game_Input_Collision * > & M_Get_Input_Collision_List(void);

		
		//-��- ���X�g -��-//

		// �w�肳�ꂽ���͔���̃A�h���X���Ǘ��p���X�g�ɒǉ�����@�����F���X�g�ɒǉ�������͔���̃A�h���X
		static void M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * );

		// �w�肳�ꂽ���͔���̃A�h���X���Ǘ��p���X�g����폜����@�����F���X�g����폜���������͔���̃A�h���X
		static void M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * );
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER



