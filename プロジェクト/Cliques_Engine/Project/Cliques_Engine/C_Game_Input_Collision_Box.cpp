////
// Ú×   FQ[ÌüÍ»èðÆé{bNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Input_Collision_Box.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INPUT::COLLISION;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision_Box::C_Game_Input_Collision_Box(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision_Box::~C_Game_Input_Collision_Box(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   Flp`Ì½è»èðÝè·é
// ø   Fconst S_Rect & Ýè·é½è»èÌQÆ
// ßèl Fvoid
//===============//
void C_Game_Input_Collision_Box::M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect & in_set_rect)
{
	mpr_variable.collision_rect = in_set_rect;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Flp`Ì½è»èÌQÆðæ¾·é
// ø   Fvoid
// ßèl Fconst S_Rect & »ÝÌ½è»èÌQÆ(const)
//===============//
const DATA::RECTSETTING::S_Rect & C_Game_Input_Collision_Box::M_Get_Collision_Box(void)
{
	return mpr_variable.collision_rect;
}


//===============//
// Ú×   Flp`Ì½è»èÌQÆðæ¾·é
// ø   Fvoid
// ßèl Fconst S_Rect & »ÝÌ½è»èÌQÆ(const)
//===============//
bool C_Game_Input_Collision_Box::M_Collision_To_Pixel(int in_x, int in_y) const
{
	return(mpr_variable.collision_rect.left_x <= in_x) * (in_x <= mpr_variable.collision_rect.right_x)
		* (mpr_variable.collision_rect.bottom_y <= in_y) * (in_y <= mpr_variable.collision_rect.top_y);
}


