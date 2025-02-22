////
// Ú×   FUIÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE


//  t@CÐç«  //
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "C_Game_Instance_Base.h"
#include "C_UI_Component_Base.h"


//  l[Xy[X  //

// Q[ÌUIÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::UI::BASE
{
	//  RZvgNX  //

	// UIR|[lgÌh¶NXÌÝðo^Å«éæ¤É·éiev[gøð§À·éj (C++20ÈÌÅÓ)
	template<typename C_Check_Instance>
	concept C_Checked_UI_Component_Class = std::is_base_of<GAME::UI_COMPONENT::BASE::C_UI_Component_Base, C_Check_Instance>::value;


	//  NX  //

	// UIÌîêÆÈéNX
	class C_User_Interface_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//== vCx[g ==//
	private:

		//  \¢Ì  //

		// thpÌR|[lgðÇ·é½ßÌ\¢Ì
		struct S_UI_Component_Inform
		{
			std::unique_ptr<GAME::UI_COMPONENT::BASE::C_UI_Component_Base> ui_component;	// thÌR|[lg

			std::string name = "default";	// thR|[lg¼
		};


		//  Ïé¾  //
		std::vector<S_UI_Component_Inform> m_ui_component_list;	// UIÌR|[lgÌXg


		//  Ö  //

		//-- R|[lg --//

		// wè³ê½UIpÌR|[lgð¶¬µA»ÌAhXðÔ·@øFstring ¶¬·éR|[lg¼@ßèlFC_UI_Component_Base * ¶¬µ½R|[lgÌAhX
		template <C_Checked_UI_Component_Class C_UI_Component_Class>
		C_UI_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// wè³ê½¼OÌUIÌR|[lgðí·é@øFstring í·éR|[lg¼
		void M_Delete_Component_By_Name(std::string);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_User_Interface_Base(void);

		// fXgN^
		virtual ~C_User_Interface_Base(void);


		//-- XV --//

		// R|[lgÌXVðs¤
		void M_Update_Component(void);

		// UIÌXVðs¤
		virtual void M_UI_Update(void) = 0;

		// íÌtOª§ÁÄ¢éR|[lgðí·é
		void M_Delete_Component_Update(void);


		//-- `æ --//

		// UIÌ`æðs¤
		virtual void M_UI_Draw(void) = 0;
	};


	//  Ö  //

	//== vCx[g ==//

	//-- R|[lg --//
	
	//===============//
	// Ú×   Fwè³ê½UIpÌR|[lgð¶¬µA»ÌAhXðÔ·
	// ø   Fstring ¶¬·éR|[lg¼
	// ßèl FC_UI_Component_Base * ¶¬µ½R|[lgÌAhX
	//===============//
	template<C_Checked_UI_Component_Class C_UI_Component_Class>
	inline C_UI_Component_Class * C_User_Interface_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		//  Ïé¾  //
		C_UI_Component_Class * new_ui_component = new C_UI_Component_Class();	// Vµ¢UIÌR|[lgÌAhX

		int new_ui_component_slot = m_ui_component_list.size();	// Vµ¢UIÌR|[lgpÌXbgÔ


		// Vµ¢UIÌR|[lgðXgÉÇÁ
		m_ui_component_list.resize(new_ui_component_slot + 1);
		m_ui_component_list[new_ui_component_slot].ui_component.reset(new_ui_component);
		m_ui_component_list[new_ui_component_slot].name = in_set_ui_component_name;

		// ¶¬³ê½R|[lgÌAhXðÔ·
		return new_ui_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
