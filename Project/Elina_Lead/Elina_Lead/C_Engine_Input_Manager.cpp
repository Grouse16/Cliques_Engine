//����������������������������������������������//
// �ڍ�   �F�G���W���̓��͂𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#include "C_OS_System_Base.h"
#include "C_Engine_Input_Manager.h"

#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INPUT;


// �� �X�^�e�B�b�N�ϐ� �� //
std::unique_ptr<C_Engine_Input_Manager> C_Engine_Input_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Manager::C_Engine_Input_Manager(void)
{
	// �f�o�b�O���͐����������Ƃ����O�Ɏc��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�G���W���p���̓V�X�e���𐶐�");
#endif // _DEBUG

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�E�X���͔���̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Update_Mouse_Input(void)
{
	// �� �ϐ��錾 �� //
	const OS::S_Mouse_State & now_mouse_state = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Mouse_State();	// ���݂̃}�E�X�̏�Ԃ̎Q��
	

	// �}�E�X�̍��W���擾
	mpr_variable.mouse.cursor_pixel.x = now_mouse_state.x;
	mpr_variable.mouse.cursor_pixel.y = now_mouse_state.y;

	// �� �}�E�X�̃N���b�N��Ԃ��X�V �� //
	switch (now_mouse_state.left_click)
	{
		// �������͂���Ă��Ȃ�
	case OS::E_MOUSE_CLICK_STATE::e_NON:

		// �N���b�N�n�I�����͏I�����̍��W���L�^
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking)
		{
			mpr_variable.mouse.end_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// ���͒�
	case OS::E_MOUSE_CLICK_STATE::e_CLICK:

		// �N���b�N�J�n���͊J�n�ʒu���L�^
		if (mpr_variable.mouse.flg_clicking == false)
		{
			mpr_variable.mouse.start_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = true;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// �_�u���N���b�N��
	case OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK:
		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = true;
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ펞�̓��͔���̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Update_Input_Collision_On_Normal_Timing(void)
{
	// �� �ϐ��錾 �� //
	std::vector<GAME::INPUT::COLLISION::C_Engine_Input_Collision* > & input_collision_list =	// ���͔��胊�X�g�ւ̎Q��
		GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_ones_overed = false;	// ��̔���Əd�Ȃ������ǂ����̃t���O

	// ���͔���̍X�V
	for (GAME::INPUT::COLLISION::C_Engine_Input_Collision * & input_collision : input_collision_list)
	{
		// ���肪�A�N�e�B�u�ȏ�ԂłȂ��Ȃ��΂�
		if (input_collision->M_Get_Is_Active() == false)
		{
			continue;
		}

		// �������łɏd�Ȃ������͔��肪����Ȃ�A������ɂ͂Ƃ�Ȃ��̂œ��͂���Ă��Ȃ���Ԃɂ���
		if (flg_ones_overed)
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}

		// �}�E�X���W�Ƃ̔�����s���A�������Ă���Ȃ��Ԃ̍X�V���s��
		else if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			// �N���b�N���֑J�ڂ��A���͂��ꂽ������擾
			if (mpr_variable.mouse.flg_clicking)
			{
				input_collision->M_Change_State_Command_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// �_�u���N���b�N���֑J�ڂ��A���͂��ꂽ������擾
			else if (mpr_variable.mouse.flg_double_clicking)
			{
				input_collision->M_Change_State_Command_Double_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// �d�Ȃ��Ă��鎞�֑J�ڂ���
			else
			{
				input_collision->M_Change_State_Command_Overed();
			}
		}

		// ���͂���Ă��Ȃ�
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�N���b�N���͌�̔���̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Update_Input_Collision_After_Clicked(void)
{
	// �� �ϐ��錾 �� //
	std::vector<GAME::INPUT::COLLISION::C_Engine_Input_Collision * > & input_collision_list =	// ���͔��胊�X�g�ւ̎Q��
		GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_exist_collision = false;	// �܂������蔻�肪���݂��Ă��邩�ǂ����̃t���O
	bool flg_overed = false;			// ��ł��d�Ȃ������肪���邩�ǂ���


	// �h���b�O���ɏd�Ȃ��Ă��锻��̎擾�͖���X�V����̂ł����ŏ�����
	mpr_variable.mouse.drag_overed_add = nullptr;


	// ���͔���̍X�V
	for (GAME::INPUT::COLLISION::C_Engine_Input_Collision * & input_collision : input_collision_list)
	{
		// �N���b�N���̔��肪����Ȃ炠�邱�Ƃ�����
		if (input_collision == mpr_variable.mouse.clicking_collision_add)
		{
			flg_exist_collision = true;


			// �h���b�O���Ɏ��g�Əd�Ȃ��Ă���Ȃ�A�d�Ȃ��Ă��邱�Ƃ�����
			if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
			{
				flg_overed = true;
			}
		}

		// �h���b�O���͂ǂ̔���Əd�Ȃ��Ă��邩�𔻒肷��A�������łɏd�Ȃ��Ă��锻�肪����Ȃ炵�Ȃ��A�d�Ȃ��Ă����炻�̂��Ƃ�����
		if (mpr_variable.mouse.flg_dragging && !flg_overed && input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			flg_overed = true;

			mpr_variable.mouse.drag_overed_add = input_collision;

			input_collision->M_Change_State_Command_Dragging_Over();
		}

		// �h���b�O���łȂ��Ȃ���͂���Ă��Ȃ���Ԃɂ���
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}


	// ���͔��肪�Ȃ�炩�̗��R�ō폜����Ă���Ȃ���͏I�����܂�
	if (flg_exist_collision == false)
	{
		// ���͏I���܂ł͂����őҋ@����
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking || mpr_variable.mouse.flg_dragging)
		{
			return;
		}

		// ���͂��I����������͏�Ԃ��������Ė߂�
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;

		return;
	}


	// �� ���͒��̏��� �� //

	// �N���b�N���̓N���b�N����Ă����Ԃ��w�肵������
	if (mpr_variable.mouse.flg_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Clicking();
	}

	// �_�u���N���b�N���̓_�u���N���b�N����Ă����Ԃ��w�肵������
	else if (mpr_variable.mouse.flg_double_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Double_Clicking();
	}

	// �h���b�O���̓h���b�O���������Ă����Ԃ��w�肵������
	else if (mpr_variable.mouse.flg_dragging)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Dragging();
	}

	// �������삳��Ȃ��Ȃ�����ʏ��Ԃɖ߂�
	else
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();

		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͔���̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Update_Input_Collision(void)
{
	// �N���b�N���͂�����Ă��Ȃ���ԂȂ�ʏ�ʂ�̓��͔��������
	if (mpr_variable.mouse.clicking_collision_add == nullptr)
	{
		M_Update_Input_Collision_On_Normal_Timing();
	}

	// �N���b�N���͂����łɂ���Ȃ�N���b�N���͒��̔�����s��
	else
	{
		M_Update_Input_Collision_After_Clicked();
	}

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͗p�V�X�e���𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Init(void)
{
	m_this.reset(new C_Engine_Input_Manager);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Manager::~C_Engine_Input_Manager(void)
{	
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͂̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Manager::M_Update(void)
{
	// �}�E�X�̔�����s��
	m_this->M_Update_Mouse_Input();

	// ���͔���̍X�V���s��
	m_this->M_Update_Input_Collision();

	return;
}

