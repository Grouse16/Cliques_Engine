//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����f�[�^�̃N���X
// ����   �F���[�h�A�w�肳�ꂽ���Ԃł̃}�g���N�X�ϊ�����Ԃ��Ȃǂ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Data_System.h"
#include "C_Text_And_File_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::DATA;


// �� �֐� �� //

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
	for (ASSET::ANIMATION::BONE::S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		now_bone_key.position_key_list.clear();
		now_bone_key.position_key_list.shrink_to_fit();

		now_bone_key.rotation_key_list.clear();
		now_bone_key.rotation_key_list.shrink_to_fit();

		now_bone_key.scale_key_list.clear();
		now_bone_key.scale_key_list.shrink_to_fit();
	}

	mpr_variable.bone_key_list.clear();
	mpr_variable.bone_key_list.shrink_to_fit();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����
// ����   �Fstring �A�j���[�V�����f�[�^�܂ł̃p�X, vector<S_Bone_Inform> & �A�^�b�`�惂�f���̃{�[���̏��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Data_System::M_Load_Anmation_Data_By_Path(std::string in_animation_data_path, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_inform_list)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// �t�@�C���̃f�[�^��ǂݎ��V�X�e��


	// �t�@�C���̃��[�h
	if (file_data.M_Load_Select_File(in_animation_data_path) == false)
	{
		// ���[�h�ɐ����A�f�o�b�O���͐������O��\��
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃A�j���[�V�����f�[�^�̃t�@�C���͂���܂���F" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}

	// �F�ؖ���T������
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMDT") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃t�@�C����.elanmdt�`���ł͂���܂���F" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}
	
	// �f�[�^�̊J�n�ʒu�ֈړ�
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("ANIMATION:"))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�A�j���[�V�����̃f�[�^���m�F�ł��܂���ł����F" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}


	// ���ݎ����Ă���A�j���[�V�����f�[�^�͍폜����
	M_Release();


	// �A�j���[�V��������{�[�������擾���A���̐����z��𐶐�
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_key_list.resize(file_data.M_Get_Number());

	// �S�ẴA�j���[�V��������{�[���̏������[�h����
	for (ASSET::ANIMATION::BONE::S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		// ���̃{�[�����܂ňړ�
		file_data.M_Goto_Right_By_Text_In_Front_Row("BONE:");


		// �{�[���̃C���f�b�N�X�̃��[�h
		{
			// �� �ϐ��錾 �� //
			std::string now_bone_name = file_data.M_Get_Data_Right_In_Row();	// ���݂̃{�[����


			// �{�[�������瑀���̃{�[���̃C���f�b�N�X�ԍ����擾
			for (int now_bone_index = 0; now_bone_index < in_bone_inform_list.size(); now_bone_index++)
			{
				if (in_bone_inform_list[now_bone_index].bone_name == now_bone_name)
				{
					now_bone_key.bone_index = now_bone_index;
				}
			}
		}


		// ���W�̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("POS:");
		now_bone_key.position_key_list.resize(file_data.M_Get_Number());

		// ���W�̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION::DATA::S_Key_Frame & now_position_key : now_bone_key.position_key_list)
		{
			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_position_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.z = file_data.M_Get_Float_Double_Number();
		}


		// ��]�̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("ROT:");
		now_bone_key.rotation_key_list.resize(file_data.M_Get_Number());

		// ��]�̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION::DATA::S_Rotation_Key_Frame & now_rotation_key : now_bone_key.rotation_key_list)
		{
			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_rotation_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.z = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.w = file_data.M_Get_Float_Double_Number();
		}


		// �X�P�[���̃L�[�t���[�������擾���A���̕��z��𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("SCL:");
		now_bone_key.scale_key_list.resize(file_data.M_Get_Number());

		// �X�P�[���̃L�[�t���[����S�ă��[�h����
		for (ASSET::ANIMATION::DATA::S_Key_Frame & now_scale_key : now_bone_key.scale_key_list)
		{
			// ���݂̃L�[�t���[�����̈ʒu�Ɉړ�
			file_data.M_Move_Next_Raw();

			// ���̃L�[�̃^�C�~���O�����ԂŎ擾
			now_scale_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// �L�[�����擾
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.z = file_data.M_Get_Float_Double_Number();
		}
	}


	// ���[�h�ɐ����A�f�o�b�O���͐������O��\��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�A�j���[�V�����f�[�^�̃��[�h�ɐ������܂����F" + in_animation_data_path);
#endif // _DEBUG

	return true;
}


//-��- �L�[�t���[�� -��-//



