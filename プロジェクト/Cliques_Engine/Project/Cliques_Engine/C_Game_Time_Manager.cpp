////
// Ú×   FQ[ÌüÍð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Time_Manager.h"
#include "C_OS_User_System.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace GAME::TIME;


//  X^eBbNÏ  //
std::unique_ptr<C_Game_Time_Manager> C_Game_Time_Manager::m_this;	// CX^X»·é½ßÌÀÌiVOgpj


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Time_Manager::C_Game_Time_Manager(void)
{
	// Q[pÌÔVXeÌ¶¬ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Q[pÌÔVXeð¶¬");

	// úÔðL^
	mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
	mpr_variable.time_of_seconds_start = mpr_variable.now_timer;
	mpr_variable.then_timer = mpr_variable.now_timer;

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FÔpVXeð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Time_Manager);
	M_Set_Frame_Rate(m_this->mpr_variable.frame_rate);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Time_Manager::~C_Game_Time_Manager(void)
{
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Q[pÌÔVXeðí");

	M_Release();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//===============//
// Ú×   F ^CCðZbg·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Reset_Time_Line(void)
{
	m_this->mpr_variable.time_line_list.clear();
	m_this->mpr_variable.time_line_list.shrink_to_fit();

	return;
}


//-- XV --//

//===============//
// Ú×   FÔÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Time_Update(void)
{
	// ÅVÌÔðæ¾·é
	m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();


	//oßÔðXV
	m_this->mpr_variable.delta_second = ((float)(m_this->mpr_variable.now_timer - m_this->mpr_variable.then_timer)) / 1000.0f;
	m_this->mpr_variable.delta_second =
		(m_this->mpr_variable.delta_second >= m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second_limit
		+
		(m_this->mpr_variable.delta_second < m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second;

	// Q[ÌoßÔðvª·é
	m_this->mpr_variable.game_delta_second = m_this->mpr_variable.delta_second * m_this->mpr_variable.game_speed;

	// t[îñðXV
	m_this->mpr_variable.now_frame += 1;


	// »ê¼êÌÔÌ¬êÌoßðÝè
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		now_time_line.delta_second = now_time_line.time_speed * m_this->mpr_variable.delta_second;
	}

	return;
}


//===============//
// Ú×   Ft[ÌI¹És¤XV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Frame_End_Update(void)
{
	// Pt[oßÌîñXV
	m_this->mpr_variable.need_spend_time = ((float)m_this->mpr_variable.time_of_seconds_start / 1000.0f) + m_this->mpr_variable.one_frame_time * m_this->mpr_variable.now_frame;
	m_this->mpr_variable.then_timer = m_this->mpr_variable.now_timer;


	// t[[gðÛÂ½ßÌÔªoß·éÜÅÒ@·é
	if (m_this->mpr_variable.flg_constant_frame)
	{
		while (M_Get_FPS_Request_Time_Passed() == false)
		{
			m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
		}
	}

	// êbÔÈãoßµ½çt[[gîñðXV
	if (m_this->mpr_variable.now_timer - m_this->mpr_variable.time_of_seconds_start >= 1000)
	{
		m_this->mpr_variable.time_of_seconds_start = m_this->mpr_variable.now_timer;
		m_this->mpr_variable.fps = m_this->mpr_variable.now_frame;
		m_this->mpr_variable.now_frame = 0;
	}


	// ^CCðí·évªÄ¢éêÍíðs¤
	if (m_this->mpr_variable.time_line_list.size() > 0)
	{
		m_this->mpr_variable.time_line_list.erase
		(
			std::remove_if
			(
				m_this->mpr_variable.time_line_list.begin(),
				m_this->mpr_variable.time_line_list.end(),

				// ^CC¼ªêv·éàÌðí·é_
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


//-- Qb^ --//

//===============//
// Ú×   FFPSðÛ·é½ßÌÔªoßµÄ¢é©Ç¤©ðÔ·
// ø   Fvoid
// ßèl Fbool trueÈçoßµÄ¢é
//===============//
bool C_Game_Time_Manager::M_Get_FPS_Request_Time_Passed(void)
{
	return ((float)m_this->mpr_variable.now_timer / 1000.0f) >= m_this->mpr_variable.need_spend_time;
}


//===============//
// Ú×   F»ÝÌKèt[[gðÔ·
// ø   Fvoid
// ßèl Fint Kèt[[g
//===============//
int C_Game_Time_Manager::M_Get_Frame_Rate(void)
{
	return m_this->mpr_variable.frame_rate;
}


//===============//
// Ú×   F»ÝÌfpsðÔ·
// ø   Fvoid
// ßèl Fint »ÝÌfpsiêbÔÌt[j
//===============//
int C_Game_Time_Manager::M_Get_FPS(void)
{
	return m_this->mpr_variable.fps;
}


//===============//
// Ú×   F»ÝÌoßÔðÔ·
// ø   Fvoid
// ßèl Ffloat »ÝÌoßÔ
//===============//
float C_Game_Time_Manager::M_Get_Delta_Second(void)
{
	return m_this->mpr_variable.delta_second;
}


//===============//
// Ú×   FQ[àÅÌoßÔðÔ·
// ø   Fvoid
// ßèl Ffloat Q[ÅÌoßÔ
//===============//
float C_Game_Time_Manager::M_Get_Game_Second(void)
{
	return m_this->mpr_variable.game_delta_second;
}


//===============//
// Ú×   FQ[àÔÌXs[hðÔ·
// ø   Fvoid
// ßèl Ffloat Q[àÔÌXs[h
//===============//
float C_Game_Time_Manager::M_Get_Game_Speed(void)
{
	return m_this->mpr_variable.game_speed;
}


//===============//
// Ú×   Fwè³ê½¼OÌ^CCÌoßÔðÔ·
// ø   Fstring æ¾·é^CC¼
// ßèl Ffloat »Ì^CCÅÌoßXs[h
//===============//
float C_Game_Time_Manager::M_Get_Time_Line_Delta_Second(std::string in_time_line_name)
{
	// êv·é¼Oª êÎoßÔðÔ·
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			return now_time_line.delta_second;
		}
	}

	// È¯êÎQ[ÔðÔ·
	return m_this->mpr_variable.game_delta_second;
}


//-- Zb^ --//

//===============//
// Ú×   Ft[[gðZbg·é
// ø   Fint Ýè·ét[[g
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Set_Frame_Rate(int in_set_frame_rate)
{
	//  è  //
	constexpr float con_LIMIT_BASE_OF_FRAME_COUNT = 10.0f;	// oßÔÌÅålð½t[ÔªÆ·é©


	m_this->mpr_variable.frame_rate = in_set_frame_rate;
	m_this->mpr_variable.one_frame_time = (1.0f / (float)m_this->mpr_variable.frame_rate);
	m_this->mpr_variable.delta_second_limit = con_LIMIT_BASE_OF_FRAME_COUNT * m_this->mpr_variable.one_frame_time;

	return;
}


//===============//
// Ú×   FQ[àÔÌXs[hðZbg·é
// ø   Ffloat Zbg·éQ[àÔÌXs[h
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Set_Game_Speed(float in_set_game_speed)
{
	m_this->mpr_variable.game_speed = in_set_game_speed;

	return;
}


//===============//
// Ú×   Fwè³ê½¼OÌ^CCÉwè³ê½Xs[hðZbg·é
// ø   Fstring ÝèæÌ^CC¼, float Ýè·éÔÌ¬êÌXs[h
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Set_Time_Line_Speed(std::string in_time_line_name, float in_time_line_speed)
{
	// ^CC¼ªêv·éàÌª êÎAÔÌ¬êÌXs[hðZbg·é
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			now_time_line.delta_second = in_time_line_speed;
		}
	}

	return;
}


//===============//
// Ú×   F^CCiÔÌ¬êjð¶¬·é
// ø   Fstring ¶¬·éÔÌ¬êÌ¼O, float ÔÌ¬êÌúXs[h
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Create_New_Time_Line(std::string in_set_time_line_name, float in_set_speed)
{
	// ·ÅÉgp³êÄ¢é¼OÈçX[
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_set_time_line_name)
		{
			return;
		}
	}


	//  Ïé¾  //
	int new_time_line_number = (int)m_this->mpr_variable.time_line_list.size();	// Vµ¢^CCÌÔ


	// Vµ¢^CCð¶¬µA¼OÆXs[hðÝèµAoßÔðo^·é
	m_this->mpr_variable.time_line_list.resize(new_time_line_number + 1);
	m_this->mpr_variable.time_line_list[new_time_line_number].time_name = in_set_time_line_name;
	m_this->mpr_variable.time_line_list[new_time_line_number].time_speed = in_set_speed;
	m_this->mpr_variable.time_line_list[new_time_line_number].delta_second = m_this->mpr_variable.game_delta_second * in_set_speed;

	return;
}


//===============//
// Ú×   Fwè³ê½¼OÌ^CCðí·é
// ø   Fstring í·é^CC¼
// ßèl Fvoid
//===============//
void C_Game_Time_Manager::M_Delete_Time_Line_By_Name(std::string in_delete_time_line_name)
{
	//  Ïé¾  //
	int set_delete_name_slot = (int)m_this->mpr_variable.delete_time_line_list.size();	// ÝèæÌ^CCÔ


	m_this->mpr_variable.delete_time_line_list.resize(set_delete_name_slot + 1);
	m_this->mpr_variable.delete_time_line_list[set_delete_name_slot + 1] = in_delete_time_line_name;

	return;
}



