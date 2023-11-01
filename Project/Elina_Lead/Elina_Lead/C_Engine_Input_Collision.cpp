//����������������������������������������������//
// �ڍ�   �F�G���W���̓��͔�����Ƃ铖���蔻��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Engine_Input_Collision_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INPUT::COLLISION;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Collision::C_Engine_Input_Collision(void)
{
	C_Engine_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(this);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Collision::~C_Engine_Input_Collision(void)
{
	C_Engine_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(this);

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�{�b�N�X�̖��O���Z�b�g����
// ����   �Fwstring �ݒ肷��{�b�N�X��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Set_Box_Name(std::wstring in_set_name)
{
	mpr_variable.collision_name = in_set_name;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����蔻���L���ɂ��邩�ǂ������Z�b�g����
// ����   �Fbool true�ŃA�N�e�B�u�ɂ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Set_Is_Active(bool in_set_active_state)
{
	mpr_variable.is_active = in_set_active_state;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����蔻��̗D��x���Z�b�g����
// ����   �Fint �ݒ肷��D��x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Set_Priority(int in_set_priority)
{
	mpr_variable.priority = in_set_priority;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����蔻��̖��O���擾����
// ����   �Fconst wstring & ���݂̓����蔻��̖��O�̕ϐ��̎Q��(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::wstring & C_Engine_Input_Collision::M_Get_Collision_Name(void) const
{
	return mpr_variable.collision_name;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����蔻���L���ɂ��邩�ǂ������擾����
// ����   �Fvoid
// �߂�l �Fbool true�Ȃ�A�N�e�B�u
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Engine_Input_Collision::M_Get_Is_Active(void) const
{
	return mpr_variable.is_active;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̓����蔻��̗D��x��Ԃ�
// ����   �Fvoid
// �߂�l �Fint �����蔻��̗D��x
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Engine_Input_Collision::M_Get_Priority(void) const
{
	return mpr_variable.priority;
}


//-��- ��Ԃ̑J�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��������Ă��Ȃ���Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Not_Hit(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
	// �N���b�N���͒��Ȃ�A���͏I��������
	case E_Engine_Input_Collision_State::e_CLICK_START:
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_END;
		break;

	// �_�u���N���b�N���Ȃ�A���͏I��������
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

	// �h���b�O���͒��́A�h���b�O���͂��I������
	case E_Engine_Input_Collision_State::e_DRAG_START:
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_END;
		break;

	// �d�Ȃ��Ă��鎞���A�ʏ��Ԃɖ߂�Ƃ��́A�ʏ��Ԃɖ߂�
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_NOT_HIT;
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�[�\�����d�Ȃ��Ă����Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Overed(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �N���b�N���͒��Ȃ�A���͏I��������
	case E_Engine_Input_Collision_State::e_CLICK_START:
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_END;
		break;

		// �_�u���N���b�N���Ȃ�A���͏I��������
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

		// �h���b�O���͒��́A�h���b�O���͂��I������
	case E_Engine_Input_Collision_State::e_DRAG_START:
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_END;
		break;

		// �ʏ��Ԃ��A�ʏ��Ԃɖ߂��ԂȂ�d�Ȃ��Ă����ԂɂȂ�
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_OVERED;
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�N���b�N���̏�Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Clicking(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �N���b�N���͂���Ă��Ȃ���ԂȂ�N���b�N���͂��n�߂�
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_START;
		break;

		// �N���b�N���͊J�n���Ȃ�N���b�N���͂𑱍s
	case E_Engine_Input_Collision_State::e_CLICK_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_DOING;
		break;

		// �N���b�N���͒��͉������Ȃ�(default�p)
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�_�u���N���b�N���̏�Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Double_Clicking(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �_�u���N���b�N���͂���Ă��Ȃ���ԂȂ�_�u���N���b�N���͂��n�߂�
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START;
		break;

		// �_�u���N���b�N���͊J�n���Ȃ�_�u���N���b�N���͂𑱍s
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING;
		break;

		// �_�u���N���b�N���͒��͉������Ȃ�(default�p)
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�h���b�O���̏�Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Dragging(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �h���b�O���͂���Ă��Ȃ���ԂȂ�h���b�O���͂��n�߂�
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_START;
		break;

		// �h���b�O���͊J�n���Ȃ�h���b�O���͂𑱍s
	case E_Engine_Input_Collision_State::e_DRAG_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_DOING;
		break;

		// �h���b�O���͒��͉������Ȃ�(default�p)
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�h���b�O���ɃJ�[�\�����d�Ȃ��Ă����Ԃ֑J��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Dragging_Over(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �h���b�O���͂ɂ����Ȃ��Ă��Ȃ���ԂȂ�h���b�O���͂ɏd�Ȃ��Ă����Ԃ��w��
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_OVERED;
		break;

		// �h���b�O���͂ɏd�Ȃ��Ă��锻�蒆�͉������Ȃ�(default�p)
	case E_Engine_Input_Collision_State::e_DRAG_OVERED:
		break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�h���b�O���ɓ����蔻��̏�Ńh���b�v���ꂽ���Ƃ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision::M_Change_State_Command_Drag_Dropped(void)
{
	//  �O��̓��͔���̏�Ԃɂ���ĕ���  //
	switch (mpr_variable.collision_state)
	{
		// �h���b�v���ꂽ��ԂłȂ��Ȃ��ԂȂ�h���b�v���ꂽ��Ԃ��w��
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_OVER_DROPPED;
		break;

		// �h���b�v���ꂽ��ԂɂȂ��Ă���Ȃ牽�����Ȃ�(default�p)
	case E_Engine_Input_Collision_State::e_DRAG_OVER_DROPPED:
		break;
	}

	return;
}


