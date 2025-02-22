////
// Ú×   FCxgwèpÌîêCX^XÌè`
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Function_Base.h"


//  l[Xy[XÌÈª  //
using namespace GAME::FUNCTION;


//  Ö  //

//== veNg ==//

//-- XV --//

//===============//
// Ú×   FV[OÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Before_Event_Update(void)
{
	return;
}


//===============//
// Ú×   FV[ãÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_After_Event_Update(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FV[OÌXVÌDæxxðÝè·é
// ø   Fint Ýè·éDæx
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Set_Before_Update_Priority(int in_set_priority)
{
	mpr_variable.before_update_priority = in_set_priority;

	return;
}


//===============//
// Ú×   FV[ãÌXVÌDæxxðÝè·é
// ø   Fint Ýè·éDæx
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Set_After_Update_Priority(int in_set_priority)
{
	mpr_variable.after_update_priority = in_set_priority;

	return;
}


//===============//
// Ú×   FV[ãÌ`æÌDæxxðÝè·é
// ø   Fint Ýè·éDæx
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Set_After_Draw_Priority(int in_set_priority)
{
	mpr_variable.after_draw_priority = in_set_priority;

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Function_Base::C_Game_Function_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Function_Base::~C_Game_Function_Base(void)
{
	return;
}


//-- XV --//

//===============//
// Ú×   FV[ãÌCxgÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Call_Event_Before_Scene_Process(void)
{
	// Ò¿Ôª éÈçÄÎêÄàÒ@
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// V[OÌXV
	M_Before_Event_Update();

	return;
}


//===============//
// Ú×   FV[ãÌCxgÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Call_Event_After_Scene_Process(void)
{
	// Ò¿Ôª éÈçÄÎêÄàÒ@
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// V[ãÌXV
	M_After_Event_Update();

	return;
}


//===============//
// Ú×   FV[OÉs¤oÍ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Draw_Before_Scene_Process(void)
{
	return;
}


//===============//
// Ú×   FV[ãÉs¤oÍ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_After_Draw_Process(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FCxgÀsÌüúðÝè·é
// ø   Ffloat Ýè·éÌÀsÜÅÌÒ¿Ô
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Set_Update_Period_Time(float in_set_period)
{
	mpr_variable.update_period_time = in_set_period;

	return;
}


//===============//
// Ú×   F@\ðI¹³¹é©Ç¤©ðÝè·é
// ø   Fbool Ýè·éI¹·é©Ç¤©ÌtO
// ßèl Fvoid
//===============//
void C_Game_Function_Base::M_Set_Flg_End_Function(bool in_set_flg_end_function)
{
	mpr_variable.flg_function_end = in_set_flg_end_function;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FV[OÌXVÌDæxÌxðÔ·
// ø   Fvoid
// ßèl Fconst int & DæxÌlÌQÆ
//===============//
const int & C_Game_Function_Base::M_Get_Before_Update_Priority(void)
{
	return mpr_variable.before_update_priority;
}


//===============//
// Ú×   FV[ãÌXVÌDæxÌxðÔ·
// ø   Fvoid
// ßèl Fconst int & DæxÌlÌQÆ
//===============//
const int & C_Game_Function_Base::M_Get_After_Update_Priority(void)
{
	return mpr_variable.after_update_priority;
}


//===============//
// Ú×   FV[ãÌ`æÌDæxÌxðÔ·
// ø   Fvoid
// ßèl Fconst int & DæxÌlÌQÆ
//===============//
const int & C_Game_Function_Base::M_Get_After_Draw_Priority(void)
{
	return mpr_variable.after_draw_priority;
}


//===============//
// Ú×   F@\ðI¹·é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fconst bool & @\ðI¹·é©Ç¤©ÌtOÌQÆ
//===============//
const bool & C_Game_Function_Base::M_Get_Flg_End_Function(void)
{
	return mpr_variable.flg_function_end;
}
