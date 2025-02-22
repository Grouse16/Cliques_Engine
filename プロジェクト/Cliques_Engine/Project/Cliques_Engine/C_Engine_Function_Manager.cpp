////
// Ú×   FQ[Ì@\ð§ä·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <algorithm>

#include "C_Game_Function_Manager.h"
#include "Game_Function_Include_List.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace GAME::FUNCTION;


//  Ïé¾  //

// vCx[gÏðÜÆß½\¢Ì
C_Game_Function_Manager::SPR_Variable C_Game_Function_Manager::mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

C_Game_Function_Manager C_Game_Function_Manager::m_this;	// ©gðÄÑo·½ßÌ¼O


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Function_Manager::C_Game_Function_Manager(void)
{
	return;
}


//-- @\ --//

//===============//
// Ú×   F@\Ì¶¬ðs¤
// ø   Fstring ¶¬·é@\ÌíÞ
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Create_Function_By_Kind(std::string in_create_kind)
{
	//  Ïé¾  //
	GAME::FUNCTION::C_Game_Function_Base * new_function_address = nullptr;	// Vµ¢@\ÌAhX
	

	//  wè³ê½íÞÉæÁÄ¶¬àeðªò  //

	// Ü¾È¢
	if (in_create_kind == "non")
	{

	}

	// ¼OªÝÂ©çÈ©Á½çG[
	else
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_CREATE_FUNCTION, "@\Ì¶¬É¸s@wè³ê½^CvF" + in_create_kind + "@Í©Â©èÜ¹ñÅµ½B¢è`Ì@\A¨æÑXy~XÌÂ\«ª èÜ·B");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return;
	}


	// ÌXgÉVµ­¶¬³ê½@\ðÇÁ
	M_Set_Before_Update_Func_To_List(new_function_address);
	M_Set_After_Update_Func_To_List(new_function_address);
	M_Set_After_Draw_Func_To_List(new_function_address);

	return;
}


//===============//
// Ú×   FV[OÉXV·é@\ðÇÁ
// ø   FC_Game_Function_Base * ÇÁ·é@\ÌAhX
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// V[OÌXVðsíÈ¢ÈçÇÁµÈ¢
	if (in_add_function->M_Get_Before_Update_Priority() < 0)
	{
		return;
	}


	// zñÉ¶¬³ê½¼ßÌ@\ðÇÁ
	mpr_variable.before_func_update_list.reserve(mpr_variable.before_func_update_list.size() + 1);
	mpr_variable.before_func_update_list.emplace_back(in_add_function);


	// Dæxð³É~É\[g·é
	std::sort
	(
		mpr_variable.before_func_update_list.begin(),	// \[gÌJn
		mpr_variable.before_func_update_list.end(),		// \[gÌ¨íè

		// _®AEÌvfª¶Ìvfæèàlªå«¯êÎAÔðüêÖ¦é
		[](GAME::FUNCTION::C_Game_Function_Base * & l_vec, GAME::FUNCTION::C_Game_Function_Base * & r_vec)
		{
			return l_vec->M_Get_Before_Update_Priority() >= r_vec->M_Get_Before_Update_Priority();
		}
	);

	return;
}

//===============//
// Ú×   FV[ãÉXV·é@\ðÇÁ
// ø   FC_Game_Function_Base * ÇÁ·é@\ÌAhX
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// V[ãÌXVðsíÈ¢ÈçÇÁµÈ¢
	if (in_add_function->M_Get_After_Update_Priority() < 0)
	{
		return;
	}


	// zñÉ¶¬³ê½¼ßÌ@\ðÇÁ
	mpr_variable.after_func_update_list.reserve(mpr_variable.after_func_update_list.size() + 1);
	mpr_variable.after_func_update_list.emplace_back(in_add_function);


	// Dæxð³É~É\[g·é
	std::sort
	(
		mpr_variable.after_func_update_list.begin(),	// \[gÌJn
		mpr_variable.after_func_update_list.end(),		// \[gÌ¨íè

		// _®AEÌvfª¶Ìvfæèàlªå«¯êÎAÔðüêÖ¦é
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_Before_Update_Priority() >= right_function->M_Get_Before_Update_Priority();
		}
	);

	return;
}


//===============//
// Ú×   FV[ãÉ`æ·é@\ðÇÁ·é
// ø   FC_Game_Function_Base * ÇÁ·é@\ÌAhX
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// V[ãÌXVðsíÈ¢ÈçÇÁµÈ¢
	if (in_add_function->M_Get_After_Draw_Priority() < 0)
	{
		return;
	}


	// zñÉ¶¬³ê½¼ßÌ@\ðÇÁ
	mpr_variable.after_func_draw_list.reserve(mpr_variable.after_func_draw_list.size() + 1);
	mpr_variable.after_func_draw_list.emplace_back(in_add_function);


	// Dæxð³É¸É\[g·é
	std::sort
	(
		mpr_variable.after_func_draw_list.begin(),	// \[gÌJn
		mpr_variable.after_func_draw_list.end(),	// \[gÌ¨íè

		// _®A¶ÌvfªEÌvfæèàlªå«¯êÎAÔðüêÖ¦é
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_After_Draw_Priority() <= right_function->M_Get_After_Draw_Priority();
		}
	);

	return;
}


//===============//
// Ú×   Fwè³ê½AhXÌ@\ð·×ÄÌo^©çí·é
// ø   FC_Game_Function_Base * í·é@\ÌAhX
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Game_Function_Base * in_delete_function)
{
	//  _®  //

	// xN^[©ç@\ípÌ»èðs¤_®
	auto delete_lambda = [] (GAME::FUNCTION::C_Game_Function_Base * & in_function)
	{
		return in_function->M_Get_Flg_End_Function();
	};


	// @\ð»ê¼êÌXg©çí·é
	mpr_variable.before_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();

	return;
}


//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
C_Game_Function_Manager::~C_Game_Function_Manager(void)
{
	M_Release_Memory();

	return;
}

//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Release_Memory(void)
{
	// @\ÌwèpÌXgÌððú·é
	mpr_variable.before_func_update_list.clear();
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.clear();
	mpr_variable.after_func_update_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.clear();
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.clear();
	mpr_variable.after_func_draw_list.shrink_to_fit();


	// @\ÌXgÌððú·é
	for (GAME::FUNCTION::C_Game_Function_Base * & now_func : mpr_variable.function_list)
	{
		if (now_func != nullptr)
		{
			delete[] now_func;
			now_func = nullptr;
		}
	}


	mpr_variable.function_list.clear();
	mpr_variable.function_list.shrink_to_fit();


	// @\¶¬½ßðú»·é
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return;
}


//===============//
// Ú×   FV[OÌ@\ÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Before_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.before_func_update_list)
	{
		now_function->M_Call_Event_Before_Scene_Process();
	}

	return;
}


//===============//
// Ú×   FV[ãÌ@\ÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_After_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_update_list)
	{
		now_function->M_Call_Event_After_Scene_Process();
	}

	return;
}


//===============//
// Ú×   FV[ãÌ@\Ì`æðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_After_Scene_Draw_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_draw_list)
	{
		now_function->M_After_Draw_Process();
	}

	return;
}


//-- @\ --//

//===============//
// Ú×   FíÌtOª½Á½@\ðÁ·
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Delete_Function(void)
{
	// íÌtOª½ÁÄ¢évfðÁ·
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.function_list)
	{
		if (now_function != nullptr)
		{
			if (now_function->M_Get_Flg_End_Function() == true)
			{
				M_Erase_This_Function_On_All_List(now_function);

				delete[] now_function;
				now_function = nullptr;
			}
		}
	}

	// ðú³ê½zñðí
	mpr_variable.function_list.erase(std::remove(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), nullptr), mpr_variable.function_list.end());
	mpr_variable.function_list.shrink_to_fit();

	return;
}


//===============//
// Ú×   F¶¬·évÌ Á½@\ðSÄ¶¬·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Game_Function_Manager::M_Execute_Create_Function_By_List(void)
{
	// ¶¬·é@\ªÈ¯êÎ½àµÈ¢
	if (mpr_variable.function_create_kind_list.size() <= 0)
	{
		return true;
	}


	// ¶¬vÌ Á½@\ðSÄ¶¬
	for (std::string & create_kind : mpr_variable.function_create_kind_list)
	{
		M_Create_Function_By_Kind(create_kind);
	}


	// ®¹µ½¶¬vðí
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return true;
}


//===============//
// Ú×   F@\Ì¶¬ðv·é
// ø   Fstring ¶¬·é@\ÌíÞ
// ßèl Fvoid
//===============//
void C_Game_Function_Manager::M_Command_Create_Function(std::string in_creat_kind)
{
	mpr_variable.function_create_kind_list.reserve(mpr_variable.function_create_kind_list.size() + 1);
	mpr_variable.function_create_kind_list.emplace_back(in_creat_kind);

	return;
}

