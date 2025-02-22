////
// Ú×   FQ[ÌüÍÌ½è»èð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <algorithm>

#include "C_Game_Input_Collision_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INPUT::COLLISION;


//  X^eBbNÏ  //
std::unique_ptr<C_Game_Input_Collision_Manager> C_Game_Input_Collision_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision_Manager::C_Game_Input_Collision_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FQ[ÌüÍ{bNX§äpVXeÌ¶¬
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Input_Collision_Manager);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision_Manager::~C_Game_Input_Collision_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FüÍ»èÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<C_Game_Input_Collision * > & üÍ»èÌXgÌQÆ
//===============//
std::vector<C_Game_Input_Collision * > & C_Game_Input_Collision_Manager::M_Get_Input_Collision_List(void)
{
	return m_this->mpr_variable.collision_list;
}


//-- Xg --//

//===============//
// Ú×   Fwè³ê½üÍ»èÌAhXðÇpXgÉÇÁ·é
// ø   FC_Game_Input_Collision * XgÉÇÁ·éüÍ»èÌAhX
// ßèl Fvoid
//===============//
void C_Game_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * in_add_input_box)
{
	m_this->mpr_variable.collision_list.reserve(m_this->mpr_variable.collision_list.size() + 1);
	m_this->mpr_variable.collision_list.emplace_back(in_add_input_box);

	// Dæxð³É~É\[g·é
	std::sort
	(
		m_this->mpr_variable.collision_list.begin(),	// \[gÌJn
		m_this->mpr_variable.collision_list.end(),		// \[gÌ¨íè

		// _®AEÌvfª¶Ìvfæèàlªå«¯êÎAÔðüêÖ¦é
		[](C_Game_Input_Collision * & left_function, C_Game_Input_Collision * & right_function)
		{
			return left_function->M_Get_Priority() >= right_function->M_Get_Priority();
		}
	);

	return;
}


//===============//
// Ú×   Fwè³ê½üÍ»èÌAhXðÇpXg©çí·é
// ø   FC_Game_Input_Collision * Xg©çí·éüÍ»èÌAhX
// ßèl FÈµ
//===============//
void C_Game_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * in_delete_input_box)
{
	m_this->mpr_variable.collision_list.erase(std::remove(m_this->mpr_variable.collision_list.begin(), m_this->mpr_variable.collision_list.end(), in_delete_input_box), m_this->mpr_variable.collision_list.end());
	m_this->mpr_variable.collision_list.shrink_to_fit();

	return;
}
