////
// Ú×   FQ[ÌóÔð¤L·é½ßÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_State_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::STATE;


//  Ïé¾  //
std::unique_ptr<C_Game_State_Manager> C_Game_State_Manager::m_this;	// ©gðÄÑo·½ßÌ¼O


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_State_Manager::C_Game_State_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FVXeð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_State_Manager::M_Init(void)
{
	m_this.reset(new C_Game_State_Manager);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_State_Manager::~C_Game_State_Manager(void)
{
	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_State_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-- Zb^ --//

//===============//
// Ú×   F»ÝÌV[¼ðZbg·é
// ø   Fwstring Ýè·é»ÝÌV[¼
// ßèl Fvoid
//===============//
void C_Game_State_Manager::M_Set_Now_Game_Scene_Name(std::wstring in_set_name)
{
	m_this->mpr_variable.now_Game_scene_name = in_set_name;

	return;
}


//===============//
// Ú×   FV[ÏXvÌÏXæV[¼ðZbg·é
// ø   Fwstring V[ÏXvÌÏXæV[¼
// ßèl Fvoid
//===============//
void C_Game_State_Manager::M_Set_Execute_Change_Game_Scene_Name(std::wstring in_set_name)
{
	m_this->mpr_variable.excute_change_Game_scene_name = in_set_name;
}


//-- Qb^ --//

//===============//
// Ú×   F»ÝÌV[¼ÌQÆðæ¾·é
// ø   Fvoid
// ßèl Fconst wstring & »ÝÌV[¼ÌQÆ(const)
//===============//
const std::wstring & C_Game_State_Manager::M_Get_Now_Game_Scene_Name(void)
{
	return m_this->mpr_variable.now_Game_scene_name;
}


//===============//
// Ú×   FV[ÏXvÌÏXæV[¼ÌQÆðæ¾·é
// ø   Fvoid
// ßèl Fconst wstring & V[ÏXvÌÏXæV[¼ÌQÆ(const)
//===============//
const std::wstring & C_Game_State_Manager::M_Get_Execute_Change_Game_Scene_Name(void)
{
	return m_this->mpr_variable.excute_change_Game_scene_name;
}


