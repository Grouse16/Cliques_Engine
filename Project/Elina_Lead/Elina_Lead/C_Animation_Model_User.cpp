//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
// ����   �F�A�j���[�V�������f���}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������@�A�j���[�V�����̎��s���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Model_User.h"
#include "C_3D_Animation_Model_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION_MODEL;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �A�j���[�V���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����f������擾����V�X�e��
// ����   �Fstring & �A�j���[�V�������̎Q��
// �߂�l �Fconst C_Animation_Data_System * �A�j���[�V�����f�[�^�̃A�h���X(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Model_User::M_Get_Animation(std::string & in_animation_name)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = mpr_variable.animation_model->M_Get_Animation_Data_By_Name(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�������擾�ł��Ȃ�������G���[���o���Ĕ�����
	if (selected_animation == nullptr)
	{
#ifdef _DEBUG

		// �� �ϐ��錾 �� //
		std::string print_log = "���f�����F" + mpr_variable.model_name + "\n�w�肳�ꂽ���O�̃A�j���[�V�����f�[�^��������܂���ł����F" + in_animation_name + "\n���݂̂̃A�j���[�V�����ꗗ�F";	// �o�͂��郍�O

		const std::vector<ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System::S_Animation_Data_Inform>& animation_list = mpr_variable.animation_model->M_Get_Animation_Inform_List();	// �A�j���[�V�����f�[�^�̃��X�g


		// �A�j���[�V���������L�^
		for (const ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System::S_Animation_Data_Inform& now_animation : animation_list)
		{
			print_log += "\n" + now_animation.name;
		}

		// ���O���o�͂��S�Ă̎��s���~����
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, print_log);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return nullptr;
	}

	return selected_animation;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_User::C_Animation_Model_User(void)
{
	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_User::~C_Animation_Model_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Release(void)
{
	// �A�j���[�V�������f���������ĂȂ��Ȃ�X���[
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	// ����V�X�e���ɂ��̃A�j���[�V�������f���̎g�p������ʒm����
	ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Release_Animation_Model(mpr_variable.animation_model);

	// �A�j���[�V�����̌v�Z�V�X�e��������������
	mpr_variable.animation_calculator.reset();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�������f����ǂݍ���
// ����   �Fstring ���[�h����A�j���[�V�������f����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Load_Animation_Model(std::string in_load_animation_model_name)
{
	// �� �ϐ��錾 �� //
	ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * new_animation_model_address = nullptr;	// �V�����A�j���[�V�������f���̃A�h���X


	// �A�j���[�V�������f���̖��O����T�����Ď擾
	new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Get_Animation_Model_By_Name(in_load_animation_model_name);

	// �w�肵���A�j���[�V�������f�����܂��Ȃ��Ȃ琶������
	if (new_animation_model_address == nullptr)
	{
		new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Load_Animation_Model_By_Name(in_load_animation_model_name);

		// �����Ɏ��s�����甲����
		if (new_animation_model_address == nullptr)
		{
			return;
		}
	}


	// �擾�ł����A�j���[�V�������f���Ɠ���ւ���
	M_Release();
	mpr_variable.animation_model = new_animation_model_address;
	mpr_variable.animation_calculator.reset(new ANIMATION::CALCULATOR::C_Animation_Calculation_System(new_animation_model_address->M_Get_Bone_Inform_List()));

	// ���f�������L�^
	mpr_variable.model_name = in_load_animation_model_name;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����[�h����
// ����   �Fstring ���[�h����A�j���[�V�����f�[�^��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Load_Animation_Data_By_Name(std::string in_load_animation_data_name)
{
	// �f�o�b�O���̓G���[�`�F�b�N������
#ifdef _DEBUG

	// �� �ϐ��錾 �� //
	bool flg_succeed = mpr_variable.animation_model->M_Load_Animation_Data_By_Name(in_load_animation_data_name);	// �����������ǂ����̃t���O


	// �G���[���̓G���[���O���o��
	if (flg_succeed == false)
	{
		// ���O���o�͂��S�Ă̎��s���~����
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���f�����F" + mpr_variable.model_name + "\n�w�肳�ꂽ�A�j���[�V�����f�[�^�͂���܂���F" + in_load_animation_data_name);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	}

	return flg_succeed;

	// �����[�X���͒ʏ�ʂ�f�[�^��Ԃ�
#else
	return mpr_variable.animation_model->M_Load_Animation_Data_By_Name(in_load_animation_data_name);
#endif // _DEBUG
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃A�j���[�V�������f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Animation_Model_Draw(void)
{
	// �A�j���[�V�������f���������Ă��Ȃ��Ȃ�`�悵�Ȃ�
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	
	// �� �ϐ��錾 �� //
	std::vector<DirectX::XMFLOAT4X4> bone_matrix_list;	// �{�[���}�g���N�X�̔z��


	// �A�j���[�V�������ʂ��Z�b�g����
	mpr_variable.animation_calculator->M_Create_Animation_Bone_Matrix(bone_matrix_list);
	mpr_variable.animation_model->M_Set_Bone_Matrix(bone_matrix_list);


	// �`����s��
	mpr_variable.animation_model->M_Draw_3D_Model();

	return;
}


//-��- �A�j���[�V���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V���������݂̎��Ԃ̂܂܍Đ�����i�u�����h����j
// ����   �Fstring �A�j���[�V������, float �u�����h�ɕK�v�Ȏ���
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Play_Animation(std::string in_animation_name, float in_need_blend_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݃A�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������w�肳�ꂽ���Ԃ���Đ�����i�u�����h����j
// ����   �Fstring �A�j���[�V������, float �u�����h�ɕK�v�Ȏ���, float �A�j���[�V�����J�n����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Play_Animation_Set_Time(std::string in_animation_name, float in_need_blend_time, float in_start_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ăA�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V���������݂̎��Ԃ̂܂܃��[�v�Đ�����i�u�����h����j
// ����   �Fstring �A�j���[�V������, float �u�����h�ɕK�v�Ȏ���
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Loop_Play_Animation(std::string in_animation_name, float in_need_blend_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݃��[�v�A�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������w�肳�ꂽ���Ԃ��烋�[�v�Đ�����i�u�����h����j�i�u�����h��̃A�j���[�V������0�b����n�܂�j
// ����   �Fstring �A�j���[�V������, float �u�����h�ɕK�v�Ȏ���, float �A�j���[�V�����J�n����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Loop_Play_Animation_And_Set_Time(std::string in_animation_name, float in_need_blend_time, float in_start_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ă��[�v�A�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Blend_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V���������݂̎��Ԃ̂܂܋����I�ɍĐ�����i�u�����h�Ȃ��j
// ����   �Fstring �A�j���[�V������
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Force_Play_Animation(std::string in_animation_name)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ăA�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������w�肳�ꂽ���Ԃ��狭���I�ɍĐ�����i�u�����h�Ȃ��j
// ����   �Fstring �A�j���[�V������, float �A�j���[�V�����̊J�n����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Force_Play_Animation_And_Set_Time(std::string in_animation_name, float in_start_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ăA�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V���������݂̎��Ԃ̂܂܋����I�Ƀ��[�v�Đ�����i�u�����h�Ȃ��j
// ����   �Fstring �A�j���[�V������
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Force_Loop_Play_Animation(std::string in_animation_name)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ă��[�v�A�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������w�肳�ꂽ���Ԃ��狭���I�Ƀ��[�v�Đ�����i�u�����h�Ȃ��j
// ����   �Fstring �A�j���[�V������, float �A�j���[�V�����̊J�n����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_User::M_Force_Loop_Play_Animation_And_Set_Time(std::string in_animation_name, float in_start_time)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^


	// �A�j���[�V�����̃f�[�^�����������[�h����Ă���Ƃ��̂݊J�n���Ԃ�ݒ肵�ă��[�v�A�j���[�V�������Đ�
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������x���Z�b�g����
// ����   �Ffloat �Z�b�g����A�j���[�V�������x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Set_Animation_Speed(float in_set_animation_speed)
{
	mpr_variable.animation_calculator->M_Set_Animation_Speed(in_set_animation_speed);

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�������f����Ԃ�
// ����   �Fvoid
// �߂�l �FC_3D_Animation_Model_System * ���݂̃A�j���[�V�������f���ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_Animation_Model_User::M_Get_Animation_Model_Address(void)
{
	return mpr_variable.animation_model;
}
