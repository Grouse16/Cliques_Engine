////
// Ú×   F|XgGtFNgÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


// @t@CÐç«  //
#include "C_Post_Effect_Base.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE::POST_EFFECT::BASE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Post_Effect_Base::C_Post_Effect_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Post_Effect_Base::~C_Post_Effect_Base(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FUI`æOÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðZbg·é
// ø   Fbool trueÅ`æ·éAfalseÍ`æµÈ¢
// ßèl Fvoid
//===============//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_Before_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_before_ui = in_set_draw_flg;

	return;
}


//===============//
// Ú×   FUI`æãÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðZbg·é
// ø   Fbool trueÅ`æ·éAfalseÍ`æµÈ¢
// ßèl Fvoid
//===============//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_After_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_after_ui = in_set_draw_flg;
}


//-- Qb^ --//

//===============//
// Ú×   FUI`æOÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool trueÅ`æ·éAfalseÍ`æµÈ¢
//===============//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_Before_UI_Draw(void)
{
	return m_flg_draw_before_ui;
}


//===============//
// Ú×   FUI`æãÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool trueÅ`æ·éAfalseÍ`æµÈ¢
//===============//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_After_UI_Draw(void)
{
	return m_flg_draw_after_ui;
}
