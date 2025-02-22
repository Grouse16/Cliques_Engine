////
// Ú×   FQ[ÌüÍð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <algorithm>

#include "C_OS_User_System.h"
#include "C_Game_Input_Manager.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INPUT;


//  X^eBbNÏ  //
std::unique_ptr<C_Game_Input_Manager> C_Game_Input_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Manager::C_Game_Input_Manager(void)
{
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "Q[püÍVXeð¶¬");

	return;
}


//-- XV --//

//===============//
// Ú×   F}EXüÍ»èÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Update_Mouse_Input(void)
{
	//  Ïé¾  //
	const OS::S_Mouse_State & now_mouse_state = OS::C_OS_User_System::M_Get_Mouse_State();	// »ÝÌ}EXÌóÔÌQÆ
	

	// }EXÌÀWðæ¾
	mpr_variable.mouse.cursor_pixel.x = now_mouse_state.x;
	mpr_variable.mouse.cursor_pixel.y = now_mouse_state.y;

	//  }EXÌNbNóÔðXV  //
	switch (now_mouse_state.left_click)
	{
		// ½àüÍ³êÄ¢È¢
	case OS::E_MOUSE_CLICK_STATE::e_NON:

		// NbNnI¹ÍI¹ÌÀWðL^
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking)
		{
			mpr_variable.mouse.end_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// üÍ
	case OS::E_MOUSE_CLICK_STATE::e_CLICK:

		// NbNJnÍJnÊuðL^
		if (mpr_variable.mouse.flg_clicking == false)
		{
			mpr_variable.mouse.start_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = true;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// _uNbN
	case OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK:
		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = true;
		break;
	}

	return;
}


//===============//
// Ú×   FÊíÌüÍ»èÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Update_Input_Collision_On_Normal_Timing(void)
{
	//  Ïé¾  //
	std::vector<GAME::INPUT::COLLISION::C_Game_Input_Collision* > & input_collision_list =	// üÍ»èXgÖÌQÆ
		GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_ones_overed = false;	// êÂÌ»èÆdÈÁ½©Ç¤©ÌtO

	// üÍ»èÌXV
	for (GAME::INPUT::COLLISION::C_Game_Input_Collision * & input_collision : input_collision_list)
	{
		// »èªANeBuÈóÔÅÈ¢ÈçòÎ·
		if (input_collision->M_Get_Is_Active() == false)
		{
			continue;
		}

		// à¤·ÅÉdÈÁ½üÍ»èª éÈçAñÂ¯ÉÍÆçÈ¢ÌÅüÍ³êÄ¢È¢óÔÉ·é
		if (flg_ones_overed)
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}

		// }EXÀWÆÌ»èðs¢A½ÁÄ¢éÈçóÔÌXVðs¤
		else if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			// NbNÖJÚµAüÍ³ê½»èðæ¾
			if (mpr_variable.mouse.flg_clicking)
			{
				input_collision->M_Change_State_Command_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// _uNbNÖJÚµAüÍ³ê½»èðæ¾
			else if (mpr_variable.mouse.flg_double_clicking)
			{
				input_collision->M_Change_State_Command_Double_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// dÈÁÄ¢éÖJÚ·é
			else
			{
				input_collision->M_Change_State_Command_Overed();
			}
		}

		// üÍ³êÄ¢È¢
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}

	return;
}


//===============//
// Ú×   FNbNüÍãÌ»èÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Update_Input_Collision_After_Clicked(void)
{
	//  Ïé¾  //
	std::vector<GAME::INPUT::COLLISION::C_Game_Input_Collision * > & input_collision_list =	// üÍ»èXgÖÌQÆ
		GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_exist_collision = false;	// Ü¾½è»èª¶ÝµÄ¢é©Ç¤©ÌtO
	bool flg_overed = false;			// êÂÅàdÈÁ½»èª é©Ç¤©


	// hbOÉdÈÁÄ¢é»èÌæ¾ÍñXV·éÌÅ±±Åú»
	mpr_variable.mouse.drag_overed_add = nullptr;


	// üÍ»èÌXV
	for (GAME::INPUT::COLLISION::C_Game_Input_Collision * & input_collision : input_collision_list)
	{
		// NbNÌ»èª éÈç é±Æð¦·
		if (input_collision == mpr_variable.mouse.clicking_collision_add)
		{
			flg_exist_collision = true;


			// hbOÉ©gÆdÈÁÄ¢éÈçAdÈÁÄ¢é±Æð¦·
			if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
			{
				flg_overed = true;
			}
		}

		// hbOÍÇÌ»èÆdÈÁÄ¢é©ð»è·éAà¤·ÅÉdÈÁÄ¢é»èª éÈçµÈ¢AdÈÁÄ¢½ç»Ì±Æð¦·
		if (mpr_variable.mouse.flg_dragging && !flg_overed && input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			flg_overed = true;

			mpr_variable.mouse.drag_overed_add = input_collision;

			input_collision->M_Change_State_Command_Dragging_Over();
		}

		// hbOÅÈ¢ÈçüÍ³êÄ¢È¢óÔÉ·é
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}


	// üÍ»èªÈñç©ÌRÅí³êÄ¢éÈçüÍI¹ðÜÂ
	if (flg_exist_collision == false)
	{
		// üÍI¹ÜÅÍ±±ÅÒ@·é
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking || mpr_variable.mouse.flg_dragging)
		{
			return;
		}

		// üÍªI¹µ½çüÍóÔððµÄßé
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;

		return;
	}


	//  üÍÌ  //

	// NbNÍNbN³êÄ¢éóÔðwèµ±¯é
	if (mpr_variable.mouse.flg_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Clicking();
	}

	// _uNbNÍ_uNbN³êÄ¢éóÔðwèµ±¯é
	else if (mpr_variable.mouse.flg_double_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Double_Clicking();
	}

	// hbOÍhbOìð³êÄ¢éóÔðwèµ±¯é
	else if (mpr_variable.mouse.flg_dragging)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Dragging();
	}

	// ½àì³êÈ­ÈÁ½çÊíóÔÉßé
	else
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();

		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;
	}

	return;
}


//===============//
// Ú×   FüÍ»èÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Update_Input_Collision(void)
{
	// NbNüÍª³êÄ¢È¢óÔÈçÊíÊèÌüÍ»èð·é
	if (mpr_variable.mouse.clicking_collision_add == nullptr)
	{
		M_Update_Input_Collision_On_Normal_Timing();
	}

	// NbNüÍª·ÅÉ éÈçNbNüÍÌ»èðs¤
	else
	{
		M_Update_Input_Collision_After_Clicked();
	}

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FüÍpVXeð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Input_Manager);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Manager::~C_Game_Input_Manager(void)
{	
	M_Release();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-- XV --//

//===============//
// Ú×   FüÍÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Manager::M_Update(void)
{
	// }EXÌ»èðs¤
	m_this->M_Update_Mouse_Input();

	// üÍ»èÌXVðs¤
	m_this->M_Update_Input_Collision();

	return;
}

