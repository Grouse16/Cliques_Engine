//����������������������������������������������//
// �ڍ�   �F�G���W���̓��͂𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Time_Manager.h"

#include "C_OS_System_Base.h"

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
	// �f�o�b�O���͐����������Ƃ����O�Ɏc��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�G���W���p�̎��ԃV�X�e���𐶐�");
#endif // _DEBUG

	// �������Ԃ��L�^
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(mpr_variable.now_timer);
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
	// �f�o�b�O���͍폜�������Ƃ����O�Ɏc��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�G���W���p�̎��ԃV�X�e�����폜");
#endif // _DEBUG

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


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Time_Update(void)
{
	// �ŐV�̎��Ԃ��擾����
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(m_this->mpr_variable.now_timer);


	//�o�ߎ��Ԃƌ��݂̎��Ԃ��X�V
	m_this->mpr_variable.delta_second = ((float)(m_this->mpr_variable.now_timer - m_this->mpr_variable.then_timer)) / 1000.0f;

	// �t���[�������X�V
	m_this->mpr_variable.now_frame += 1;

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
			OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second(m_this->mpr_variable.now_timer);
		}
	}

	// ��b�Ԉȏ�o�߂�����t���[�����[�g�����X�V
	if (m_this->mpr_variable.now_timer - m_this->mpr_variable.time_of_seconds_start >= 1000)
	{
		m_this->mpr_variable.time_of_seconds_start = m_this->mpr_variable.now_timer;
		m_this->mpr_variable.fps = m_this->mpr_variable.now_frame;
		m_this->mpr_variable.now_frame = 0;
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
	return m_this->mpr_variable.delta_second * m_this->mpr_variable.game_speed;
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


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t���[�����[�g���Z�b�g����
// ����   �Fint �ݒ肷��t���[�����[�g
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Time_Manager::M_Set_Frame_Rate(int in_set_frame_rate)
{
	m_this->mpr_variable.frame_rate = in_set_frame_rate;
	m_this->mpr_variable.one_frame_time = (1.0f / (float)m_this->mpr_variable.frame_rate);

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



