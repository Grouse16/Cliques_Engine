////
// Ú×   FQ[ÌVXe§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <algorithm>

#include "C_Game_Manager.h"
#include "C_OS_Management_System_Base.h"
#include "C_Game_Function_Manager.h"
#include "C_Game_State_Manager.h"
#include "C_APK_Manager.h"
#include "C_Game_Input_Manager.h"
#include "C_Game_Input_Collision_Manager.h"
#include "C_Game_Time_Manager.h"
#include "C_Rendering_API_Interface_User.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace GAME;


//  Ïé¾  //
C_Game_Manager C_Game_Manager::m_this;	// ©NXÖÌANZXpÌÏ

C_Game_Manager::SPr_Variable C_Game_Manager::mpr_variable;		// ©NXÌÏÖÌANZXpÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Manager::C_Game_Manager(void)
{

	return;
}


//-- XV --//

//===============//
// Ú×   Ff[^ÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Data_Update(void)
{
	//  Ïé¾  //
	const std::wstring & executed_scene_name = GAME::STATE::C_Game_State_Manager::M_Get_Execute_Change_Game_Scene_Name();	// ÏXvÌ Á½V[¼ÌQÆ


	// ÏXvªÈ¢ÈçX[
	if (executed_scene_name == GAME::STATE::con_Invalid_Scene_Name)
	{
		return;
	}

	// ÏXæª»ÝÆ¯¶ÈçÏXÛ
	if (GAME::STATE::C_Game_State_Manager::M_Get_Now_Game_Scene_Name() == executed_scene_name)
	{
		GAME::STATE::C_Game_State_Manager::M_Set_Execute_Change_Game_Scene_Name(executed_scene_name);

		return;
	}


	//  ÏXæV[¼©çKvÈ@\Ì¶¬ðs¤  //

	// ^CgV[
	if (executed_scene_name == L"TITLE")
	{

	}

	// Q[V[
	if (executed_scene_name == L"GAME")
	{

	}

	// wè³ê½V[ª¶ÝµÈ¢
	else
	{
		// fobOÍÈ¢±Æð¦·
#ifdef _DEBUG
#endif // _DEBUG
	}


	return;
}


//===============//
// Ú×   FEBhE^CgÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Window_Title_Update(void)
{
	// fobOÌÝÏX
#ifdef _DEBUG
	
	//  Ïé¾  //
	std::wstring new_title;	// Vµ¢^CgÌ¶ñ


	new_title = OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Title_Name() + L"    fps : "
		+ 
		std::to_wstring(TIME::C_Game_Time_Manager::M_Get_FPS()) + L"/" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Frame_Rate())
		+
		L"@speed:" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Delta_Second());
	OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Change_Window_Title(new_title);

#endif	// _DEBUG

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FV[ÌOÉs¤Q[¤Ì
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Init(void)
{
	// Q[Ìú»Jnðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-------- Q[Ìú»ðJn --------");

	// Q[Ì¤ÊîñðÜÆßéVXeð¶¬·é
	GAME::STATE::C_Game_State_Manager::M_Init();

	// Q[ÌüÍVXeð¶¬·é
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Init();
	GAME::INPUT::C_Game_Input_Manager::M_Init();

	// Q[ÌÔVXeð¶¬·é
	GAME::TIME::C_Game_Time_Manager::M_Init();

	// AvP[VVXeÌú»ðs¤
	M_Set_Game_Exist_Flg(GAME::APPLICATION::C_APK_Manager::M_Init());


	// ú»É¸sµ½ç¸sðm·é
	if (M_Get_Game_Exist_Flg() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "-------- Q[Ìú»É¸s --------");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return;
	}


	// ú»É¬÷µ½ç¬÷ðm·é
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-------- Q[Ìú»É¬÷ --------");


	// ANeBuóÔðwè
	mpr_variable.flg_game_activate = true;
	M_Set_Game_Exist_Flg(true);

	return;
}


//===============//
// Ú×   FfXgN^AgpµÄ¢éððú·é
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Manager::~C_Game_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Release(void)
{
	// AvP[VÌI¹ð¦·
	mpr_variable.flg_game_activate = false;
	M_Set_Game_Exist_Flg(false);

	// AvP[VÌðú
	GAME::APPLICATION::C_APK_Manager::M_Release();

	// Q[pVXeðí
	GAME::FUNCTION::C_Game_Function_Manager::M_Release_Memory();
	GAME::INPUT::C_Game_Input_Manager::M_Release();
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Release();
	GAME::TIME::C_Game_Time_Manager::M_Release();
	GAME::STATE::C_Game_State_Manager::M_Release();

	return;
}


//-- Zb^ --//

//===============//
// Ú×   FQ[ð¶ÝµÄ¢éóÔ©Ç¤©ðÝè·é
// ø   FtrueÍ³íÉ¶ÝµÄ¢é
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Set_Game_Exist_Flg(bool in_set_exist)
{
	mpr_variable.flg_game_exist = in_set_exist;

	return;
}


//===============//
// Ú×   FQ[ªÒ­©Ç¤©ðÝè·é
// ø   FtrueÍ³íÉ¶ÝµÄ¢é
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Set_Game_Activate_Flg(bool in_set_active)
{
	mpr_variable.flg_game_activate = in_set_active;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FQ[ð¶ÝµÄ¢éóÔ©Ç¤©ðæ¾·é
// ø   FtrueÍ³íÉ¶ÝµÄ¢é
// ßèl FI¹ÌêÍAtrue
//===============//
bool C_Game_Manager::M_Get_Game_Exist_Flg(void)
{
	return mpr_variable.flg_game_exist;
}


//===============//
// Ú×   FQ[ªANeBuóÔ©Ç¤©ðÔ·
// ø   Fvoid
// ßèl FANeBuÌêÍAtrue
//===============//
bool C_Game_Manager::M_Get_Game_Active_Flg(void)
{
	return mpr_variable.flg_game_activate;
}


//-- Às --//

//===============//
// Ú×   FQ[ÌðÀs·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Manager::M_Executes_Process(void)
{
	//====== ÀsmF ======//

	// Q[ª¶ÝµÄ¢È¢©Ò­ÅÈ¢ÈçÀsµÈ¢
	if ((M_Get_Game_Active_Flg() & M_Get_Game_Exist_Flg()) == false)
	{
		return;
	}


	//====== X^[g ======//

	// _OAPIªí³êÄ¢éÈçQ[ðI¹
	if (RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_User::M_Rendering_API_Safe_Check() == false)
	{
		M_Set_Game_Exist_Flg(false);

		return;
	}

	// OSÌXV@·ÅÉXVÈçX[
	if (mpr_variable.flg_OS_active_now == false)
	{
		mpr_variable.flg_OS_active_now = true;
		OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Update();

		// OSªI¹µÄ¢½çQ[ðI¹·é
		if (OS::BASE::C_OS_Management_System_Base::M_Get_OS_Active() == false)
		{
			M_Set_Game_Exist_Flg(false);

			return;
		}
		mpr_variable.flg_OS_active_now = false;
	}

	// ÔÌXV
	GAME::TIME::C_Game_Time_Manager::M_Time_Update();

	// EBhE^CgðXV
	M_Window_Title_Update();



	//====== üÍ ======//

	// Q[§äVXeÌüÍ
	GAME::INPUT::C_Game_Input_Manager::M_Update();

	// Q[ÌüÍ
	GAME::APPLICATION::C_APK_Manager::M_APK_Input();



	//====== XV ======//

	// Q[XVOÌ@\ÌXV
	GAME::FUNCTION::C_Game_Function_Manager::M_Before_Scene_Update();

	// Q[ÌXV
	GAME::APPLICATION::C_APK_Manager::M_APK_Update();

	// Q[XVãÌ@\ÌXV
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Update();



	//====== `æ ======//

	//  _OVXeÌ`æõ  //
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_User::M_Rendering_Start();

	// Q[Ì`æ
	GAME::APPLICATION::C_APK_Manager::M_APK_Draw();

	// Q[`æãÌ@\ÌXV
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Draw_Update();

	//  _OI¹ÆæÊoÍ  //
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_User::M_Rendering_End_And_Swap_Screen();



	//====== Ìt[ÖÌõ ======//

	// CX^XÌíðs¤
	GAME::APPLICATION::C_APK_Manager::M_Instance_Destroy_Update();

	// KvÌÈ¢@\Ìí
	GAME::FUNCTION::C_Game_Function_Manager::M_Delete_Function();

	// KvÈ@\Ì¶¬
	GAME::FUNCTION::C_Game_Function_Manager::M_Execute_Create_Function_By_List();
	
	// Q[Ì¤Lf[^ÌXV
	M_Data_Update();

	// t[ÌI¹ÌXV
	GAME::TIME::C_Game_Time_Manager::M_Frame_End_Update();

	return;
}
