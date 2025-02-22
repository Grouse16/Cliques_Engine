////
// Ú×   FUIÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_User_Interface_Base.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INSTANCE::UI::BASE;


//  Ö  //

//== vCx[g ==//

//-- R|[lg --//

//===============//
// Ú×   Fwè³ê½¼OÌUIÌR|[lgðí·é
// ø   Fstring í·éR|[lg¼
// ßèl Fvoid
//===============//
void C_User_Interface_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// wè³ê½ðÊèÌCX^Xðí·é
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// R|[lgÌ¼Oªêv·éàÌðí
			[in_delete_ui_component_name](S_UI_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_ui_component_list.end()
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
C_User_Interface_Base::C_User_Interface_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_User_Interface_Base::~C_User_Interface_Base(void)
{
	m_ui_component_list.clear();
	m_ui_component_list.shrink_to_fit();

	return;
}


//-- XV --//

//===============//
// Ú×   FR|[lgÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_User_Interface_Base::M_Update_Component(void)
{
	for (S_UI_Component_Inform & m_component_list : m_ui_component_list)
	{
		m_component_list.ui_component->M_Update();
	}

	return;
}


//===============//
// Ú×   FíÌtOª§ÁÄ¢éR|[lgðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_User_Interface_Base::M_Delete_Component_Update(void)
{
	// wè³ê½ðÊèÌCX^Xðí·é
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// íÌtOª§ÁÄ¢éR|[lgðí
			[](S_UI_Component_Inform& in_component_inform)
			{
				if (in_component_inform.ui_component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.ui_component.reset();

					return true;
				}

				return false;
			}
		),

		m_ui_component_list.end()
	);

	return;
}

