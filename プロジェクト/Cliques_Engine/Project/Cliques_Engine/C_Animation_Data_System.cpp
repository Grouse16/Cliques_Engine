//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����f�[�^�̃N���X
// ����   �F���[�h�A�w�肳�ꂽ���Ԃł̃}�g���N�X�ϊ�����Ԃ��Ȃǂ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Data_System.h"
#include "C_Text_And_File_Manager.h"

#include "C_Console_Log_Interface.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION_SYSTEM;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �L�[�t���[���u�����h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�������ɃL�[�l�����ԂŊ���o���Ă�Ԃ�
// ����   �Ffloat �J�n�̃L�[�l, float �I���̃L�[�l, float ���Ԃ̃p�[�Z���g
// �߂�l �Ffloat �v�Z���ʂ̃L�[�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline float C_Animation_Data_System::M_Key_To_Key_Value_Calculation_By_Time(float in_start_key, float in_end_key, float in_time_percent) const
{
	return (in_end_key - in_start_key) * in_time_percent + in_start_key;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ��񂩂�L�[�t���[���̌v�Z���s�������Z�b�g����
// ����   �Ffloat ���̎���, float �u�����h��, const vector<S_Key_Frame> & �ݒ茳�̃L�[�t���[�����, XMFLOAT3 & �ݒ��̃L�[�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Data_System::M_Blend_Key_Frame(float in_time, float in_blend_percent, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & in_blend_key, DirectX::XMFLOAT3 & out_set_key) const
{
	// �� �ϐ��錾 �� //
	DirectX::XMFLOAT3 result_key;	// ���ʂƂȂ�L�[�l
	
	int key_value_sum = (int)in_blend_key.size();	// �L�[���̑���
	int start_key_slot = (int)in_blend_key.size() - 1;	// �n�܂�̃L�[�̃X���b�g

	bool key_is_end = true;	// �g�p����L�[���z����Ō�̏ꍇ��true�A�z��̓r���ł����false


	// �ʒu�̃L�[�̂����w�肳�ꂽ���Ԃɂ�����L�[��T���i������Ȃ�������Ō�̎��Ԉȍ~�ł��邽�ߍŌ�̃L�[���w��j
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// ���w�肵�Ă���L�[�̎��Ԉȏ�A���̃L�[�̎��Ԉȉ��̏ꍇ�́A�������g�p����L�[�Ƃ���
		if (in_blend_key[now_key_num].time_of_frame <= in_time && in_blend_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// ���݂̃L�[���z��̍Ō�ł���΂�������̂܂܎g�p����
	if (key_is_end)
	{
		result_key = in_blend_key[start_key_slot].key_value;
	}

	// ���݂̃L�[���z��̓r���ł���Ύ��̃L�[�t���[���܂ł̎��Ԃ��猻�݂̈ʒu������o��
	else
	{
		// �� �ϐ��錾 �� //
		float time_percent = 0.0f;	// ���Ԃ̑J�ڗ�


		// ���݂̎��Ԃ���A���݂̃L�[�Ǝ��̃L�[�܂ł̎��Ԃ̉��p�[�Z���g���o�߂��Ă��邩������o��
		time_percent = (in_time - in_blend_key[start_key_slot].time_of_frame) / (in_blend_key[start_key_slot + 1].time_of_frame - in_blend_key[start_key_slot].time_of_frame);

		result_key.x =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.x, in_blend_key[start_key_slot + 1].key_value.x, time_percent);

		result_key.y =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.y, in_blend_key[start_key_slot + 1].key_value.y, time_percent);

		result_key.z =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.z, in_blend_key[start_key_slot + 1].key_value.z, time_percent);
	}


	// ���ʂ��u�����h�����u�����h����
	out_set_key.x = out_set_key.x * (1.0f - in_blend_percent) + result_key.x * in_blend_percent;
	out_set_key.y = out_set_key.y * (1.0f - in_blend_percent) + result_key.y * in_blend_percent;
	out_set_key.z = out_set_key.z * (1.0f - in_blend_percent) + result_key.z * in_blend_percent;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ��񂩂�N�H�[�^�j�I���̃L�[�t���[���̌v�Z���s�������Z�b�g����
// ����   �Ffloat ���̎���, float �u�����h��, const vector<S_Quaternion_Key_Frame> & �ݒ茳�̃N�H�[�^�j�I���L�[�t���[�����, XMVECTOR & �ݒ��̃L�[�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Data_System::M_Blend_Quaternion_Key_Frame(float in_time, float in_blend_percent, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> & in_quaternion_key, DirectX::XMVECTOR & out_set_quaternion) const
{
	// �� �ϐ��錾 �� //
	DirectX::XMVECTOR result_quaternion;	// ���ʂƂȂ�N�H�[�^�j�I���l

	int key_search_end_slot = (int)in_quaternion_key.size() - 1;	// �T���͈͍Ō�̃L�[�̃X���b�g�ԍ�
	int use_key_slot = 0;	// �g�p����X���b�g�ԍ�

	bool key_is_end = true;	// �g�p����L�[���z����Ō�̏ꍇ��true�A�z��̓r���ł����false


	// �ʒu�̃L�[�̂����w�肳�ꂽ���Ԃɂ�����L�[��T���i������Ȃ�������Ō�̎��Ԉȍ~�ł��邽�ߍŌ�̃L�[���w��j
	for (int now_key_num = 0; now_key_num < key_search_end_slot; now_key_num++)
	{
		// ���w�肵�Ă���L�[�̎��Ԉȏ�A���̃L�[�̎��Ԉȉ��̏ꍇ�́A�������g�p����L�[�Ƃ���
		if (in_quaternion_key[now_key_num].time_of_frame <= in_time && in_time < in_quaternion_key[now_key_num + 1].time_of_frame)
		{
			use_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// ���݂̃L�[���z��̍Ō�ł���΂�������̂܂܎g�p����
	if (key_is_end)
	{
		use_key_slot = key_search_end_slot;
		result_quaternion = in_quaternion_key[use_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector();
	}

	// ���݂̃L�[���z��̓r���ł���Ύ��̃L�[�t���[���܂ł̎��Ԃ��猻�݂̈ʒu������o��
	else
	{
		// �� �ϐ��錾 �� //
		float time_percent = 0.0f;	// ���Ԃ̑J�ڗ�


		// ���݂̎��Ԃ���A���݂̃L�[�Ǝ��̃L�[�܂ł̎��Ԃ̉��p�[�Z���g���o�߂��Ă��邩������o��
		time_percent = (in_time - in_quaternion_key[use_key_slot].time_of_frame) / (in_quaternion_key[use_key_slot + 1].time_of_frame - in_quaternion_key[use_key_slot].time_of_frame);

		// �J�ڐ�܂ł̃L�[�̃N�H�[�^�j�I���̕�Ԃ����Ԃ̃p�[�Z���g����|����i���ʐ��`��ԁj
		result_quaternion = DirectX::XMQuaternionSlerp
		(
			in_quaternion_key[use_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector(),
			in_quaternion_key[use_key_slot + 1].quaternion.M_Get_Quaternion_Rotation_Vector(), 
			time_percent
		);
	}


	// ���ʂ��u�����h�����u�����h����i���ʐ��`��ԂŃu�����h�����̏ꏊ���Ԃ���j
	out_set_quaternion = DirectX::XMQuaternionSlerp(out_set_quaternion, result_quaternion, in_blend_percent);

	return;
}


//-��- �L�[�t���[���Z�b�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ��񂩂�L�[�t���[���̌v�Z���s�������Z�b�g����
// ����   �Ffloat ���̎���, const vector<S_Key_Frame> & �ݒ茳�̃L�[�t���[�����, XMFLOAT3 & �ݒ��̃L�[�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Data_System::M_Set_Key_Frame(float in_time, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & in_set_key, DirectX::XMFLOAT3 & out_set_key) const
{
	// �� �ϐ��錾 �� //
	int key_search_end_slot = (int)in_set_key.size() - 1;	// �T���͈͍Ō�̃X���b�g�̔ԍ�
	int use_key_slot = 0;	// �g�p����L�[�̃X���b�g�ԍ�

	bool key_is_end = true;	// �g�p����L�[���z����Ō�̏ꍇ��true�A�z��̓r���ł����false


	// �ʒu�̃L�[�̂����w�肳�ꂽ���Ԃɂ�����L�[��T���i������Ȃ�������Ō�̎��Ԉȍ~�ł��邽�ߍŌ�̃L�[���w��j
	for (int now_key_num = 0; now_key_num < key_search_end_slot; now_key_num++)
	{
		// ���w�肵�Ă���L�[�̎��Ԉȏ�A���̃L�[�̎��Ԉȉ��̏ꍇ�́A�������g�p����L�[�Ƃ���
		if (in_set_key[now_key_num].time_of_frame <= in_time && in_time < in_set_key[now_key_num + 1].time_of_frame)
		{
			use_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// ���݂̃L�[���z��̍Ō�ł���΂�������̂܂܎g�p����
	if (key_is_end)
	{
		use_key_slot = key_search_end_slot;
		out_set_key = in_set_key[use_key_slot].key_value;
	}

	// ���݂̃L�[���z��̓r���ł���Ύ��̃L�[�t���[���܂ł̎��Ԃ��猻�݂̈ʒu������o��
	else
	{
		// �� �ϐ��錾 �� //
		float time_percent = 0.0f;	// ���Ԃ̑J�ڗ�


		// ���݂̎��Ԃ���A���݂̃L�[�Ǝ��̃L�[�܂ł̎��Ԃ̉��p�[�Z���g���o�߂��Ă��邩������o��
		time_percent = (in_time - in_set_key[use_key_slot].time_of_frame) / (in_set_key[use_key_slot + 1].time_of_frame - in_set_key[use_key_slot].time_of_frame);

		out_set_key.x =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[use_key_slot].key_value.x, in_set_key[use_key_slot + 1].key_value.x, time_percent);

		out_set_key.y =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[use_key_slot].key_value.y, in_set_key[use_key_slot + 1].key_value.y, time_percent);

		out_set_key.z =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[use_key_slot].key_value.z, in_set_key[use_key_slot + 1].key_value.z, time_percent);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ��񂩂�N�H�[�^�j�I���̃L�[�t���[���̌v�Z���s�������Z�b�g����
// ����   �Ffloat ���̎���, const vector<S_Key_Frame> & �ݒ茳�̃N�H�[�^�j�I���L�[�t���[�����, XMFLOAT3 & �ݒ��̃L�[�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Data_System::M_Set_Quaternion_Key_Frame(float in_time, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> & in_quaternion_key, DirectX::XMVECTOR & out_set_quaternion) const
{
	// �� �ϐ��錾 �� //
	int key_quaternion_sum = (int)in_quaternion_key.size();	// �N�H�[�^�j�I���̃L�[���̑���
	int start_key_slot = (int)in_quaternion_key.size() - 1;	// �n�܂�̃L�[�̃X���b�g

	bool key_is_end = true;	// �g�p����L�[���z����Ō�̏ꍇ��true�A�z��̓r���ł����false


	// �ʒu�̃L�[�̂����w�肳�ꂽ���Ԃɂ�����L�[��T���i������Ȃ�������Ō�̎��Ԉȍ~�ł��邽�ߍŌ�̃L�[���w��j
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// ���w�肵�Ă���L�[�̎��Ԉȏ�A���̃L�[�̎��Ԉȉ��̏ꍇ�́A�������g�p����L�[�Ƃ���
		if (in_quaternion_key[now_key_num].time_of_frame <= in_time && in_quaternion_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// ���݂̃L�[���z��̍Ō�ł���΂�������̂܂܎g�p����
	if (key_is_end)
	{
		out_set_quaternion = in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector();
	}

	// ���݂̃L�[���z��̓r���ł���Ύ��̃L�[�t���[���܂ł̎��Ԃ��猻�݂̈ʒu������o��
	else
	{
		// �� �ϐ��錾 �� //
		float time_percent = 0.0f;	// ���Ԃ̑J�ڗ�


		// ���݂̎��Ԃ���A���݂̃L�[�Ǝ��̃L�[�܂ł̎��Ԃ̉��p�[�Z���g���o�߂��Ă��邩������o��
		time_percent = (in_time - in_quaternion_key[start_key_slot].time_of_frame) / (in_quaternion_key[start_key_slot + 1].time_of_frame - in_quaternion_key[start_key_slot].time_of_frame);

		// �J�ڐ�܂ł̃L�[�̃N�H�[�^�j�I���̕�Ԃ����Ԃ̃p�[�Z���g����|����i���ʐ��`��ԁj
		out_set_quaternion = DirectX::XMQuaternionSlerp
		(
			in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector(),
			in_quaternion_key[start_key_slot + 1].quaternion.M_Get_Quaternion_Rotation_Vector(),
			time_percent
		);
	}

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Data_System::C_Animation_Data_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Data_System::~C_Animation_Data_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Data_System::M_Release(void)
{
	for (S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		now_bone_key.key.position_key_list.clear();
		now_bone_key.key.position_key_list.shrink_to_fit();

		now_bone_key.key.quaternion_key_list.clear();
		now_bone_key.key.quaternion_key_list.shrink_to_fit();

		now_bone_key.key.scale_key_list.clear();
		now_bone_key.key.scale_key_list.shrink_to_fit();
	}

	mpr_variable.bone_key_list.clear();
	mpr_variable.bone_key_list.shrink_to_fit();

	return;
}


//-��- �Z�b�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����f�[�^�̖��O��ݒ肷��
// ����   �Fstring �A�j���[�V�����f�[�^�̖��O
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Data_System::M_Set_Name(std::string in_set_name)
{
	mpr_variable.name = in_set_name;

	return;
}


//-��- �Q�b�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����f�[�^�̖��O��Ԃ�
// ����   �Fvoid
// �߂�l �Fstring �A�j���[�V�����f�[�^�̖��O
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Animation_Data_System::M_Get_Name(void) const
{
	return mpr_variable.name;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����
// ����   �Fstring �A�j���[�V�����f�[�^�܂ł̃p�X, vector<C_Bone_Inform> & �A�^�b�`�惂�f���̃{�[���̏��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Data_System::M_Load_Animation_Data_By_Path(std::string in_animation_data_path, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_inform_list)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// �t�@�C���̃f�[�^��ǂݎ��V�X�e��


	// �t�@�C���̃��[�h
	if (file_data.M_Load_Select_File(in_animation_data_path) == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃A�j���[�V�����f�[�^�̃t�@�C���͂���܂���F" + in_animation_data_path);

		return false;
	}

	// �F�ؖ���T������
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMDT") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃t�@�C����.elanmdt�`���ł͂���܂���F" + in_animation_data_path);

		return false;
	}
	
	// �f�[�^�̊J�n�ʒu�ֈړ�
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("ANIMATION:"))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�A�j���[�V�����̃f�[�^���m�F�ł��܂���ł����F" + in_animation_data_path);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// �� �ϐ��錾 �� //
	int bone_sum_of_base = (int)in_bone_inform_list.size();	// �{�[���̑���
	int now_use_offset_bone_number_slot = 0;	// ���ݎg�p����I�t�Z�b�g�s���ݒ肷��{�[���̃X���b�g�ԍ�
	int before_bone_number = 0;	// �O�̃{�[���̔ԍ�


	// ���ݎ����Ă���A�j���[�V�����f�[�^�͍폜����
	M_Release();


	// �A�j���[�V�������Ԃ��擾
	file_data.M_Goto_Right_By_Text_In_Front_Row("ENDTIME:");
	mpr_variable.animation_end_time = (float)file_data.M_Get_Float_Double_Number();

	// �A�j���[�V��������{�[�������擾���A���̐����z��𐶐�
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_key_list.resize(file_data.M_Get_Number());

	// �I�t�Z�b�g�s���ݒ肷��{�[�������z��𐶐�
	mpr_variable.use_offset_bone_list.resize(bone_sum_of_base - mpr_variable.bone_key_list.size());


	// �S�ẴA�j���[�V��������{�[���̏������[�h����
	for (S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		// �� �ϐ��錾 �� //
		int now_bone_number = 0;	// ���݂̃{�[���̔ԍ�


		// ���̃{�[�����܂ňړ�
		file_data.M_Goto_Right_By_Text_In_Front_Row("BONE:");


		// �{�[���̃C���f�b�N�X�̃��[�h
		{
			// �� �ϐ��錾 �� //
			std::string now_bone_name = file_data.M_Get_Data_Right_In_Row();	// ���݂̃{�[����


			// �{�[�������瑀���̃{�[���̃C���f�b�N�X�ԍ����擾
			for (int now_bone_index = 0; now_bone_index < bone_sum_of_base; now_bone_index++)
			{
				if (in_bone_inform_list[now_bone_index].bone_name == now_bone_name)
				{
					now_bone_key.attach_bone_index = now_bone_index;

					now_bone_number = now_bone_index;

					break;
				}
			}
		}


		// �O��̃{�[���ԍ��ƌ��݂̃{�[���ԍ��̊Ԃ̃{�[���̓I�t�Z�b�g�s����g�p����
		for (int l_now_use_offset_bone_number = before_bone_number + 1; l_now_use_offset_bone_number < now_bone_number; l_now_use_offset_bone_number++)
		{
			mpr_variable.use_offset_bone_list[now_use_offset_bone_number_slot] = l_now_use_offset_bone_number;
			now_use_offset_bone_number_slot += 1;
		}


		// ���W�̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("POS:");
		now_bone_key.key.position_key_list.resize(file_data.M_Get_Number());

		// ���W�̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION_SYSTEM::S_Key_Frame & now_position_key : now_bone_key.key.position_key_list)
		{
			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_position_key.time_of_frame = (float)file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.x = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.y = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.z = (float)file_data.M_Get_Float_Double_Number();
		}


		// ��]�̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("ROT:");
		now_bone_key.key.quaternion_key_list.resize(file_data.M_Get_Number());

		// ��]�̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame & now_rotation_key : now_bone_key.key.quaternion_key_list)
		{
			// �� �ϐ��錾 �� //
			DirectX::XMFLOAT4 set_rotation_value;	// ��]�̐ݒ�l


			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_rotation_key.time_of_frame = (float)file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.x = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.y = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.z = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.w = (float)file_data.M_Get_Float_Double_Number();

			// �N�H�[�^�j�I���ɃZ�b�g
			now_rotation_key.quaternion.M_Set_Quaternion(DirectX::XMVectorSet(set_rotation_value.x, set_rotation_value.y, set_rotation_value.z, set_rotation_value.w));
		}


		// �X�P�[���̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("SCL:");
		now_bone_key.key.scale_key_list.resize(file_data.M_Get_Number());

		// �X�P�[���̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION_SYSTEM::S_Key_Frame & now_scale_key : now_bone_key.key.scale_key_list)
		{
			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_scale_key.time_of_frame = (float)file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.x = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.y = (float)file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.z = (float)file_data.M_Get_Float_Double_Number();
		}

		// ���݂̃{�[���ԍ���O��̃{�[���ԍ��Ƃ��ĕۑ�
		before_bone_number = now_bone_number;
	}


	// �O��̃{�[���ԍ�����Ō�̃{�[���܂ł̊Ԃɂ���{�[���̓{�[���I�t�Z�b�g�s����g�p����
	for (int l_now_use_offset_bone_number = before_bone_number + 1; l_now_use_offset_bone_number < bone_sum_of_base; l_now_use_offset_bone_number++)
	{
		mpr_variable.use_offset_bone_list[now_use_offset_bone_number_slot] = l_now_use_offset_bone_number;
		now_use_offset_bone_number_slot += 1;
	}


	// ���[�h�ɐ����������Ƃ����O�ɕ\��
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�A�j���[�V�����f�[�^�̃��[�h�ɐ������܂����F" + in_animation_data_path);

	return true;
}


//-��- �L�[�t���[���u�����h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���ԂƃL�[�̃u�����h�����炻�ꂼ��̃{�[���̃L�[���𐶐����A�ݒ��փu�����h����
// ����   �Ffloat ����, float �u�����h��, vector<C_Bone_Data> & �ݒ��̃{�[���L�[�̔z��̎Q��, �{�[���I�t�Z�b�g�s��̎Q��(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Data_System::M_Blend_Bone_Key(float in_time, float in_key_blend_percent, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> & out_set_bone_key_list) const
{
	// �� �ϐ��錾 �� //
	int animation_bone_sum = (int)mpr_variable.bone_key_list.size();	// �A�j���[�V��������{�[���̑���


	// �{�[���̃f�[�^���̔z��𐶐�����
	out_set_bone_key_list.resize(animation_bone_sum);


	// �A�j���[�V�����̉e�����󂯂�{�[���̂݃u�����h����
	for (int l_now_bone = 0; l_now_bone < animation_bone_sum; l_now_bone++)
	{
		// �� �ʒu�̃u�����h �� //
		M_Blend_Key_Frame(in_time, in_key_blend_percent, mpr_variable.bone_key_list[l_now_bone].key.position_key_list, out_set_bone_key_list[l_now_bone].position);

		// �� �X�P�[���̃u�����h �� //
		M_Blend_Key_Frame(in_time, in_key_blend_percent, mpr_variable.bone_key_list[l_now_bone].key.scale_key_list, out_set_bone_key_list[l_now_bone].scale);

		// �� �N�H�[�^�j�I���̃u�����h �� //
		M_Blend_Quaternion_Key_Frame(in_time, in_key_blend_percent, mpr_variable.bone_key_list[l_now_bone].key.quaternion_key_list, out_set_bone_key_list[l_now_bone].quaternion);
	}

	return;
}


//-��- �L�[�t���[���Z�b�g -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���Ԃ��炻�ꂼ��̃{�[���̃L�[���𐶐����A�ݒ��փZ�b�g����
// ����   �Ffloat ����, vector<C_Bone_Data> & �ݒ��̃{�[���L�[�̃{�[�����Ƃ̔z��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Data_System::M_Set_Bone_Key(float in_time, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> & out_set_bone_list) const
{
	// �� �ϐ��錾 �� //
	int animation_bone_sum = (int)mpr_variable.bone_key_list.size();	// �A�j���[�V��������{�[���̑���


	// �{�[���̃f�[�^���̔z��𐶐�����
	out_set_bone_list.resize(animation_bone_sum);


	// �A�j���[�V�����̉e�����󂯂�{�[���̂݃Z�b�g����
	for (int l_now_bone = 0; l_now_bone < animation_bone_sum; l_now_bone++)
	{
		// �� �ʒu�̃Z�b�g �� //
		M_Set_Key_Frame(in_time, mpr_variable.bone_key_list[l_now_bone].key.position_key_list, out_set_bone_list[l_now_bone].position);

		// �� �X�P�[���̃Z�b�g �� //
		M_Set_Key_Frame(in_time, mpr_variable.bone_key_list[l_now_bone].key.scale_key_list, out_set_bone_list[l_now_bone].scale);

		// �� �N�H�[�^�j�I���̃Z�b�g �� //
		M_Set_Quaternion_Key_Frame(in_time, mpr_variable.bone_key_list[l_now_bone].key.quaternion_key_list, out_set_bone_list[l_now_bone].quaternion);
	}

	return;
}


//-��- �}�g���N�X -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�{�[���}�g���N�X�̔z��𐶐�����
// ����   �Fvoid
// �߂�l �Fvector<XMFLOAT4X4> & �ݒ��̃{�[���}�g���N�X�̔z��̎Q��, const vector<C_Bone_Data> & �{�[���̃L�[�t���[�����̃��X�g�̎Q��(const), const vector<S_Bone_Inform> & �{�[���I�t�Z�b�g�}�g���N�X�̔z��̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Data_System::M_Create_Bone_Matrix_List(std::vector<DirectX::XMFLOAT4X4> & out_set_matrix_list, const std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> & in_bone_data_list, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_offset_matrix_list) const
{
	// �� �ϐ��錾 �� //
	int animation_bone_sum = (int)mpr_variable.bone_key_list.size();	// �A�j���[�V��������{�[���̑���

	int offset_bone_sum = (int)mpr_variable.use_offset_bone_list.size();	// �I�t�Z�b�g�s����g�p����{�[���̑���


	// �A�j���[�V�����̉e�����󂯂�{�[���̂݃}�g���N�X�𐶐�����
	for (int l_now_bone = 0; l_now_bone < animation_bone_sum; l_now_bone++)
	{
		// �A�j���[�V�����ɂ��}�g���N�X�𐶐�
		in_bone_data_list[l_now_bone].M_Convert_Bone_Data_To_Matrix(out_set_matrix_list[mpr_variable.bone_key_list[l_now_bone].attach_bone_index]);

		// �I�t�Z�b�g�s����|����
		DirectX::XMStoreFloat4x4
		(
			// �ݒ��̃}�g���N�X
			&out_set_matrix_list[mpr_variable.bone_key_list[l_now_bone].attach_bone_index],

			// �|����
			DirectX::XMMatrixMultiply
			(
				DirectX::XMLoadFloat4x4
				(
					&out_set_matrix_list[mpr_variable.bone_key_list[l_now_bone].attach_bone_index]),
					DirectX::XMLoadFloat4x4(&in_bone_offset_matrix_list[mpr_variable.bone_key_list[l_now_bone].attach_bone_index].offset_matrix
				)
			)
		);
	}


	// �I�t�Z�b�g�}�g���N�X���g�p����{�[���ɃI�t�Z�b�g�}�g���N�X���Z�b�g����
	for (int l_now_bone = 0; l_now_bone < offset_bone_sum; l_now_bone++)
	{
		out_set_matrix_list[mpr_variable.use_offset_bone_list[l_now_bone]] = in_bone_offset_matrix_list[mpr_variable.use_offset_bone_list[l_now_bone]].offset_matrix;
	}

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����J�n����I���܂ł̎���
// ����   �Fvoid
// �߂�l �Ffloat �A�j���[�V�����J�n����I���܂ł̎���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Animation_Data_System::M_Get_Animation_Time(void) const
{
	return mpr_variable.animation_end_time;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�{�[���I�t�Z�b�g�s����g�p����{�[���̃C���f�b�N�X�ԍ��̃��X�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<int> & �{�[���I�t�Z�b�g�s����g�p����{�[���̃C���f�b�N�X�ԍ��̃��X�g�̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<int> & C_Animation_Data_System::M_Get_Use_Offset_Bone_List(void) const
{
	return mpr_variable.use_offset_bone_list;
}


