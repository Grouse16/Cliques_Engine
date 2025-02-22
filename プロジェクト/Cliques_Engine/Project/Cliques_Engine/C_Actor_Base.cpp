////
// Ú×   FAN^[ÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Actor_Base.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE::ACTOR::BASE;


//  Ö  //

//== vCx[g ==//

//-- R|[lg --//

//===============//
// Ú×   Fwè³ê½¼OÌR|[lgðí·é
// ø   Fstring í·éR|[lg¼
// ßèl Fvoid
//===============//
void C_Actor_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// wè³ê½ðÊèÌCX^Xðí·é
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// R|[lgÌ¼Oªêv·éàÌðí
			[in_delete_ui_component_name](S_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_component_list.end()
	);

	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Actor_Base::C_Actor_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Actor_Base::~C_Actor_Base(void)
{
	m_component_list.clear();
	m_component_list.shrink_to_fit();

	return;
}


//-- XV --//

//===============//
// Ú×   FR|[lgÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Actor_Base::M_Component_Update(void)
{
	for (S_Component_Inform & now_component : m_component_list)
	{
		now_component.component->M_Update();
	}

	return;
}


//===============//
// Ú×   FíÌtOª§ÁÄ¢éR|[lgðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Actor_Base::M_Delete_Component_Update(void)
{
	// wè³ê½ðÊèÌCX^Xðí·é
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// íÌtOª§ÁÄ¢éR|[lgðí
			[](S_Component_Inform& in_component_inform)
			{
				if (in_component_inform.component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.component.reset();

					return true;
				}

				return false;
			}
		),

		m_component_list.end()
	);

	return;
}


//-- Zb^ --//

//===============//
// Ú×   FAN^[ð`æ·é©Ç¤©ÌtOðZbg·é
// ø   Fbool AN^[ðZbg·é©Ç¤©ÌtO
// ßèl Fvoid
//===============//
void C_Actor_Base::M_Set_Draw_Flg(bool in_set_draw_flg)
{
	m_draw_flg = in_set_draw_flg;

	return;
}


//===============//
// Ú×   FÊí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðZbg·é
// ø   Fbool Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOAtrueÌÌÝ`æ·é
// ßèl Fvoid
//===============//
void C_Actor_Base::M_Set_After_Draw_Flg(bool in_after_draw_flg)
{
	m_after_draw_flg = in_after_draw_flg;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FAN^[ð`æ·é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool AN^[ð`æ·é©Ç¤©ÌtOAtrueÍ`æ·é
//===============//
bool C_Actor_Base::M_Get_Draw_Flg(void)
{
	return m_draw_flg;
}


//===============//
// Ú×   FÊí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOAtrueÍ`æ·é
//===============//
bool C_Actor_Base::M_Get_After_Draw_Flg(void)
{
	return m_after_draw_flg;
}

