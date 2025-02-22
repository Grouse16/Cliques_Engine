////
// Ú×   FAj[VÌvZð§ä·éNX
// à¾   F{[}gNXÉÎ·éAj[VÌìðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Calculation_System.h"
#include "C_Animation_Algorithm_No_Animation.h"
#include "C_Animation_Algorithm_Play.h"
#include "C_Animation_Algorithm_Loop_Play.h"
#include "C_Animation_Algorithm_Blend_Play.h"
#include "C_Animation_Algorithm_Blend_And_Loop.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION::CALCULATOR;


//  Ö  //

//== vCx[g ==//

//-- uh§ä --//

//===============//
// Ú×   FuhI¹ðmFµAÎµ½Aj[VÉüêÖ¦é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Check_Blend_End_And_Animation_Setting(void)
{
	// uhª®¹µÄ¢éÈçªòðuhãÉJÚ·éªòðÀs
	if (mpr_variable.animation_status.need_blend_time >= 1.0f)
	{
		//  uhãÌ®Åðªò  //
		switch (mpr_variable.blend_after)
		{
			//-- ÊíÌÄ¶ÉJÚ·é --//
		case E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION:
			M_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//-- [vÄ¶ÉJÚ·é --//
		case E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION:
			M_Loop_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//-- uhµÄ¢È¢Æ« --//
		case E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW:
		default:
			break;
		}
	}

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fconst vector<S_Bone_Inform> & {[îñÌXgÌQÆ
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list) : mpr_variable((int)in_bone_list.size())
{
	// úóÔÌ{[ðÝè·éASYð¶¬
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation());

	// úóÔÍÅ©çAj[VI¹óÔ
	mpr_variable.animation_status.flg_animation_end = true;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset();

	return;
}


//===============//
// Ú×   FAj[VÌXe[^XÌú»
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Animation_Status_Reset(void)
{
	mpr_variable.animation_status.animation_time = 0.0f;
	mpr_variable.animation_status.animation_blend_percent = 0.0f;
	mpr_variable.animation_status.animation_speed = 1.0f;
	mpr_variable.animation_status.flg_animation_end = false;

	return;
}


//-- Zb^ --//

//===============//
// Ú×   F»ÝÌAj[VÔðZbg·é
// ø   Ffloat Zbg·éAj[VÔ
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Set_Animation_Time(float in_set_animation_time)
{
	mpr_variable.animation_status.animation_time = in_set_animation_time;

	return;
}


//===============//
// Ú×   F»ÝÌAj[VÔðZbg·é
// ø   Ffloat Zbg·éAj[VÌXs[h
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Set_Animation_Speed(float in_set_speed)
{
	mpr_variable.animation_status.animation_speed = in_set_speed;

	return;
}


//===============//
// Ú×   FuhÉ©©éÔðZbg·é
// ø   Ffloat Zbg·éuhÉ©©éÔ
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Set_Need_Blend_Time(float in_set_need_blend_time)
{
	mpr_variable.animation_status.need_blend_time = in_set_need_blend_time;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FAj[VªI¹µÄ¢é©Ç¤©ðÔ·
// ø   Fvoid
// ßèl Fbool Aj[VI¹ÌtO
//===============//
bool C_Animation_Calculation_System::M_Get_Animation_Is_End(void)
{
	return mpr_variable.animation_status.flg_animation_end;
}


//===============//
// Ú×   F»ÝÌAj[VÔðÔ·
// ø   Fvoid
// ßèl Ffloat »ÝÌAj[VÔ
//===============//
float C_Animation_Calculation_System::M_Get_Animation_Time(void)
{
	return mpr_variable.animation_status.animation_time;
}


//===============//
// Ú×   F»ÝÌAj[VÌXs[hðÔ·
// ø   Fvoid
// ßèl Ffloat »ÝÌAj[VÌXs[h
//===============//
float C_Animation_Calculation_System::M_Get_Animation_Speed(void)
{
	return mpr_variable.animation_status.animation_speed;
}


//===============//
// Ú×   F»ÝÌAj[VÌuh¦ðÔ·
// ø   Fvoid
// ßèl Ffloat »ÝÌAj[VÌuh¦
//===============//
float C_Animation_Calculation_System::M_Get_Animation_Blend_Percent(void)
{
	return mpr_variable.animation_status.animation_blend_percent;
}


//-- XV --//

//===============//
// Ú×   FAj[VÔÌoßðs¤
// ø   Ffloat oß³¹éÔ
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Update_Time(float in_pass_time)
{
	mpr_variable.animation_status.passed_time = 
		in_pass_time 
		* mpr_variable.animation_status.animation_speed
		* (1.0f - 2.0f * mpr_variable.animation_status.flg_animation_reverse);

	return;
}


//-- Aj[V --//

//===============//
// Ú×   Fn³ê½Aj[VðÄ¶·é
// ø   Fconst C_Animation_Data_System * Ä¶·éAj[Vf[^ÌAhX(const)
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//===============//
// Ú×   Fn³ê½Aj[Vð[vÄ¶·é
// ø   Fconst C_Animation_Data_System * [vÄ¶·éAj[Vf[^ÌAhX(const)
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_loop_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_loop_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//===============//
// Ú×   Fn³ê½Aj[VðuhµÄÄ¶·é
// ø   Fconst C_Animation_Data_System * Ä¶·éAj[Vf[^ÌAhXiuhæj(const)
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Blend_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_play_animation)
{
	//  Ïé¾  //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// »ÝÌAj[VÌf[^iuh³j


	// uh³ÌAj[Vª éÈçAuhAj[VðJn
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_Play(mpr_variable.animation_status, now_animation_data, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION;
	}

	// uh³ÌAj[VªÈ¢ÈçÊíÌAj[Vðs¤
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//===============//
// Ú×   Fn³ê½Aj[VðuhãA[vÄ¶·é
// ø   Fconst C_Animation_Data_System * Ä¶·éAj[Vf[^ÌAhXiuhæj(const)
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Blend_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_loop_animation)
{
	//  Ïé¾  //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// »ÝÌAj[VÌf[^iuh³j


	// uh³ÌAj[Vª éÈçAuhAj[VðJn
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_And_Loop(mpr_variable.animation_status, now_animation_data, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION;
	}

	// uh³ÌAj[VªÈ¢Èç[vAj[Vðs¤
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//===============//
// Ú×   Fwè³ê½zñÉAj[VÊÌ{[}gNXzñÌf[^ðZbg·é
// ø   Fvector<XMFLOAT4X4> & ÝèæÌ{[}gNXzñÌf[^ÌQÆ, const vector<S_Bone_Inform> & {[ItZbgsñÌXgÌQÆ(const)
// ßèl Fvoid
//===============//
void C_Animation_Calculation_System::M_Create_Animation_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_offset_matrix_list)
{
	// {[f[^pÌzñðmÛ·é
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.animation_status.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list, in_bone_offset_matrix_list);

	// Aj[VuhÅ êÎAuh®¹µ½^C~OÅÊíÌAj[VÉßéiuhÌ¾¯ð²¢½o[WÉüêÖ¦éj
	M_Check_Blend_End_And_Animation_Setting();

	return;
}
