////
// Ú×   FQ[CX^XÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Instance_Base.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE::BASE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Instance_Base::C_Game_Instance_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Instance_Base::~C_Game_Instance_Base(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FCX^X¼ðÝè·é
// ø   Fstring Ýè·éCX^XÌ¼O
// ßèl Fvoid
//===============//
void C_Game_Instance_Base::M_Set_Instance_Name(std::string in_set_name)
{
	m_name = in_set_name;

	return;
}


//===============//
// Ú×   FV[JÚÉí³êé©Ç¤©ÌtOðZbg·é
// ø   Fbool trueÅí³êÈ¢AfalseÅí³êé
// ßèl Fvoid
//===============//
void C_Game_Instance_Base::M_Set_Scene_Over_Flg(bool in_set_scene_over_flg)
{
	m_flg_scene_over = in_set_scene_over_flg;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FíÌÀsð\·é
// ø   Fvoid
// ßèl Fvoid
//===============//
bool C_Game_Instance_Base::M_Get_Destroy_Instance_Flg(void)
{
	return m_flg_destroy_instance;
}


//===============//
// Ú×   FV[JÚÉí³êé©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool trueÅí³êÈ¢AfalseÅí³êé
//===============//
bool C_Game_Instance_Base::M_Get_Scene_Over_Flg(void)
{
	return m_flg_scene_over;
}


//===============//
// Ú×   FCX^X¼ÌQÆðÔ·
// ø   Fvoid
// ßèl Fconst std::string & CX^X¼
//===============//
const std::string & C_Game_Instance_Base::M_Get_Instance_Name(void)
{
	return m_name;
}


//-- í --//

//===============//
// Ú×   FíÌÀsð\·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Instance_Base::M_Destroy(void)
{
	m_flg_destroy_instance = true;

	return;
}


