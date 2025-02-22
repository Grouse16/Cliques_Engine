////
// Ú×   FAj[Vð[vÄ¶·éNX
// à¾   FêÂÌAj[Vð[vÄ¶µ±¯é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Algorithm_Loop_Play.h"
#include "C_Bone_Data.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION::ALGORITHM;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   FS_Animation_Status & Aj[VXe[^XÌQÆ, const C_Animation_Data_System * Aj[V·éf[^ÌZbg(const)
// ßèl FÈµ
//===============//
C_Animation_Algorithm_Loop_Play::C_Animation_Algorithm_Loop_Play(ASSET::ANIMATION::S_Animation_Status & in_set_animation_status, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_set_animation_data) : m_animation_status(in_set_animation_status)
{
	m_now_animation = in_set_animation_data;
	m_animation_status.flg_animation_end = false;
	m_animation_status.animation_blend_percent = 0.0f;

	// »ÝÌAj[VÔªVµ¢Aj[VÌI¹Ôð´¦éÈç´¦È¢æ¤É¼·
	M_Guard_1_Over_2(m_animation_status.animation_time, in_set_animation_data->M_Get_Animation_Time());

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Algorithm_Loop_Play::~C_Animation_Algorithm_Loop_Play(void)
{
	return;
}


//-- XV --//

//===============//
// Ú×   FAj[VÔÌXV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Algorithm_Loop_Play::M_Animation_Time_Update(void)
{
	// [v·éAj[VÌÔÌXVðs¤
	M_Loop_Animation_Time_Base_Update(m_animation_status, m_now_animation->M_Get_Animation_Time());

	return;
}


//===============//
// Ú×   FAj[VÌXV
// ø   Fvector<XMFLOAT4X4> & XVð©¯é{[Ì}gNXÌzñÌQÆ, const vector<S_Bone_Inform> & {[ItZbg}gNXÌzñÌQÆ(const)
// ßèl Fvoid
//===============//
void C_Animation_Algorithm_Loop_Play::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & out_set_matrix, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_offset_matrix)
{
	//  Ïé¾  //
	std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> bone_data_list;	// {[Ìf[^ÌXg


	// Aj[VÉæé{[f[^ðó¯æé
	bone_data_list.resize(m_animation_status.bone_sum);
	m_now_animation->M_Set_Bone_Key(m_animation_status.animation_time, bone_data_list);


	// {[f[^ð}gNXÉÏ·µÄZbg·é
	m_now_animation->M_Create_Bone_Matrix_List(out_set_matrix, bone_data_list, in_offset_matrix);

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F»ÝÌAj[VðÔ·
// ø   Fvoid
// ßèl FC_Animation_Data_System * »ÝÌAj[VÌAhX(const)
//===============//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Algorithm_Loop_Play::M_Get_Now_Animation(void)
{
	return m_now_animation;
}

