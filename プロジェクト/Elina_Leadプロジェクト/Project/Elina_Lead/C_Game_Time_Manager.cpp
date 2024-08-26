//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͂𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Time_Manager.h"
#include "C_OS_User_System.h"

#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::TIME;


// �� �X�^�e�B�b�N�ϐ� �� //
std::unique_ptr<C_Game_Time_Manager> C_Game_Time_Manager::m_this;	// �C���X�^���X�����邽�߂̎��́i�V���O���g���p�j


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Time_Manager::C_Game_Time_Manager(void)
{
	// �Q�[���p�̎��ԃV�X�e���̐��������m
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�Q�[���p�̎��ԃV�X�e���𐶐�");

	// �������Ԃ��L�^
	mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
	mpr_variable.time_of_seconds_start = mpr_variable.now_timer;
	mpr_variable.then_timer = mpr_variable.now_timer;

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���ԗp�V�X�e���𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Time_Manager);
	M_Set_Frame_Rate(m_this->mpr_variable.frame_rate);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Time_Manager::~C_Game_Time_Manager(void)
{
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�Q�[���p�̎��ԃV�X�e�����폜");

	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F �^�C�����C�������Z�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Reset_Time_Line(void)
{
	m_this->mpr_variable.time_line_list.clear();
	m_this->mpr_variable.time_line_list.shrink_to_fit();

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Time_Update(void)
{
	// �ŐV�̎��Ԃ��擾����
	m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();


	//�o�ߎ��Ԃ��X�V
	m_this->mpr_variable.delta_second = ((float)(m_this->mpr_variable.now_timer - m_this->mpr_variable.then_timer)) / 1000.0f;
	m_this->mpr_variable.delta_second =
		(m_this->mpr_variable.delta_second >= m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second_limit
		+
		(m_this->mpr_variable.delta_second < m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second;

	// �Q�[���̌o�ߎ��Ԃ��v������
	m_this->mpr_variable.game_delta_second = m_this->mpr_variable.delta_second * m_this->mpr_variable.game_speed;

	// �t���[�������X�V
	m_this->mpr_variable.now_frame += 1;


	// ���ꂼ��̎��Ԃ̗���̌o�߂�ݒ�
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		now_time_line.delta_second = now_time_line.time_speed * m_this->mpr_variable.delta_second;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t���[���̏I�����ɍs���X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Frame_End_Update(void)
{
	// �P�t���[���o�ߎ��̏��X�V
	m_this->mpr_variable.need_spend_time = ((float)m_this->mpr_variable.time_of_seconds_start / 1000.0f) + m_this->mpr_variable.one_frame_time * m_this->mpr_variable.now_frame;
	m_this->mpr_variable.then_timer = m_this->mpr_variable.now_timer;


	// �t���[�����[�g��ۂ��߂̎��Ԃ��o�߂���܂őҋ@����
	if (m_this->mpr_variable.flg_constant_frame)
	{
		while (M_Get_FPS_Request_Time_Passed() == false)
		{
			m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
		}
	}

	// ��b�Ԉȏ�o�߂�����t���[�����[�g�����X�V
	if (m_this->mpr_variable.now_timer - m_this->mpr_variable.time_of_seconds_start >= 1000)
	{
		m_this->mpr_variable.time_of_seconds_start = m_this->mpr_variable.now_timer;
		m_this->mpr_variable.fps = m_this->mpr_variable.now_frame;
		m_this->mpr_variable.now_frame = 0;
	}


	// �^�C�����C�����폜����v�������Ă���ꍇ�͍폜���s��
	if (m_this->mpr_variable.time_line_list.size() > 0)
	{
		m_this->mpr_variable.time_line_list.erase
		(
			std::remove_if
			(
				m_this->mpr_variable.time_line_list.begin(),
				m_this->mpr_variable.time_line_list.end(),

				// �^�C�����C��������v������̂��폜���郉���_
				[](S_Time_Line & in_time_line)
				{
					for (std::string now_delete_name : m_this->mpr_variable.delete_time_line_list)
					{
						if (in_time_line.time_name == now_delete_name)
						{
							return true;
						}
					}

					return false;
				}
			)
		);
	}

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FFPS���ێ����邽�߂̎��Ԃ��o�߂��Ă��邩�ǂ�����Ԃ�
// ����   �Fvoid
// �߂�l �Fbool true�Ȃ�o�߂��Ă���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Time_Manager::M_Get_FPS_Request_Time_Passed(void)
{
	return ((float)m_this->mpr_variable.now_timer / 1000.0f) >= m_this->mpr_variable.need_spend_time;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̋K��t���[�����[�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fint �K��t���[�����[�g
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Game_Time_Manager::M_Get_Frame_Rate(void)
{
	return m_this->mpr_variable.frame_rate;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂�fps��Ԃ�
// ����   �Fvoid
// �߂�l �Fint ���݂�fps�i��b�Ԃ̃t���[�����j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Game_Time_Manager::M_Get_FPS(void)
{
	return m_this->mpr_variable.fps;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̌o�ߎ��Ԃ�Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat ���݂̌o�ߎ���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Game_Time_Manager::M_Get_Delta_Second(void)
{
	return m_this->mpr_variable.delta_second;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[�����ł̌o�ߎ��Ԃ�Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �Q�[���ł̌o�ߎ���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Game_Time_Manager::M_Get_Game_Second(void)
{
	return m_this->mpr_variable.game_delta_second;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[�������Ԃ̃X�s�[�h��Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �Q�[�������Ԃ̃X�s�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Game_Time_Manager::M_Get_Game_Speed(void)
{
	return m_this->mpr_variable.game_speed;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃^�C�����C���̌o�ߎ��Ԃ�Ԃ�
// ����   �Fstring �擾����^�C�����C����
// �߂�l �Ffloat ���̃^�C�����C���ł̌o�߃X�s�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Game_Time_Manager::M_Get_Time_Line_Delta_Second(std::string in_time_line_name)
{
	// ��v���閼�O������Όo�ߎ��Ԃ�Ԃ�
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			return now_time_line.delta_second;
		}
	}

	// �Ȃ���΃Q�[�����Ԃ�Ԃ�
	return m_this->mpr_variable.game_delta_second;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t���[�����[�g���Z�b�g����
// ����   �Fint �ݒ肷��t���[�����[�g
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Set_Frame_Rate(int in_set_frame_rate)
{
	// �� �萔 �� //
	constexpr float con_LIMIT_BASE_OF_FRAME_COUNT = 10.0f;	// �o�ߎ��Ԃ̍ő�l�����t���[�����ԕ��Ƃ��邩


	m_this->mpr_variable.frame_rate = in_set_frame_rate;
	m_this->mpr_variable.one_frame_time = (1.0f / (float)m_this->mpr_variable.frame_rate);
	m_this->mpr_variable.delta_second_limit = con_LIMIT_BASE_OF_FRAME_COUNT * m_this->mpr_variable.one_frame_time;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[�������Ԃ̃X�s�[�h���Z�b�g����
// ����   �Ffloat �Z�b�g����Q�[�������Ԃ̃X�s�[�h
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Set_Game_Speed(float in_set_game_speed)
{
	m_this->mpr_variable.game_speed = in_set_game_speed;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃^�C�����C���Ɏw�肳�ꂽ�X�s�[�h���Z�b�g����
// ����   �Fstring �ݒ��̃^�C�����C����, float �ݒ肷�鎞�Ԃ̗���̃X�s�[�h
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Set_Time_Line_Speed(std::string in_time_line_name, float in_time_line_speed)
{
	// �^�C�����C��������v������̂�����΁A���Ԃ̗���̃X�s�[�h���Z�b�g����
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			now_time_line.delta_second = in_time_line_speed;
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�^�C�����C���i���Ԃ̗���j�𐶐�����
// ����   �Fstring �������鎞�Ԃ̗���̖��O, float ���Ԃ̗���̏����X�s�[�h
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Create_New_Time_Line(std::string in_set_time_line_name, float in_set_speed)
{
	// ���łɎg�p����Ă��閼�O�Ȃ�X���[
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_set_time_line_name)
		{
			return;
		}
	}


	// �� �ϐ��錾 �� //
	int new_time_line_number = (int)m_this->mpr_variable.time_line_list.size();	// �V�����^�C�����C���̔ԍ�


	// �V�����^�C�����C���𐶐����A���O�ƃX�s�[�h��ݒ肵�A�o�ߎ��Ԃ�o�^����
	m_this->mpr_variable.time_line_list.resize(new_time_line_number + 1);
	m_this->mpr_variable.time_line_list[new_time_line_number].time_name = in_set_time_line_name;
	m_this->mpr_variable.time_line_list[new_time_line_number].time_speed = in_set_speed;
	m_this->mpr_variable.time_line_list[new_time_line_number].delta_second = m_this->mpr_variable.game_delta_second * in_set_speed;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃^�C�����C�����폜����
// ����   �Fstring �폜����^�C�����C����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Delete_Time_Line_By_Name(std::string in_delete_time_line_name)
{
	// �� �ϐ��錾 �� //
	int set_delete_name_slot = (int)m_this->mpr_variable.delete_time_line_list.size();	// �ݒ��̃^�C�����C���ԍ�


	m_this->mpr_variable.delete_time_line_list.resize(set_delete_name_slot + 1);
	m_this->mpr_variable.delete_time_line_list[set_delete_name_slot + 1] = in_delete_time_line_name;

	return;
}



