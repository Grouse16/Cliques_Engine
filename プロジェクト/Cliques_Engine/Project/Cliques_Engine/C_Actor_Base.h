////
// Ú×   FAN^[ÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


//  t@CÐç«  //
#include <vector>
#include <memory>

#include "C_Game_Instance_Base.h"
#include "C_Component_Base.h"


//  l[Xy[X  //

// Q[ÌAN^[ÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::ACTOR::BASE
{
	//  RZvgNX  //

	// R|[lgÌh¶NXÌÝðo^Å«éæ¤É·éiev[gøð§À·éj (C++20ÈÌÅÓ)
	template<typename C_Check_Instance>
	concept C_Checked_Component_Class = std::is_base_of<GAME::COMPONENT::BASE::C_Component_Base, C_Check_Instance>::value;


	//  NX  //

	// AN^[ÌîêÆÈéNX
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//== vCx[g ==// 
	private:

		//  \¢Ì  //

		// R|[lg§äpÌîñÌ\¢Ì
		struct S_Component_Inform
		{
			std::unique_ptr<GAME::COMPONENT::BASE::C_Component_Base> component;	// R|[lg

			std::string name = "default";	// R|[lg¼
		};


		//  Ïé¾  //
		std::vector<S_Component_Inform> m_component_list;	// R|[lgÌXg

		bool m_draw_flg = true;			// `æ·é©Ç¤©ÌtO
		bool m_after_draw_flg = false;	// Êí`æãÉ`æ·é©Ç¤©ÌtO


		//  Ö  //

		//-- R|[lg --//

		// wè³ê½R|[lgð¶¬µA»ÌAhXðÔ·@øFstring ¶¬·éR|[lg¼@ßèlFC_UI_Component_Base * ¶¬µ½R|[lgÌAhX
		template <C_Checked_Component_Class C_Component_Class>
		C_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// wè³ê½¼OÌR|[lgðí·é@øFstring í·éR|[lg¼
		void M_Delete_Component_By_Name(std::string);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Actor_Base(void);

		// fXgN^
		virtual ~C_Actor_Base(void);


		//-- Dæx --//

		// AN^[ÌDæxðÔ·@ßèlFAN^[ÌDæx
		virtual int M_Get_Priority(void) = 0;


		//-- XV --//

		// R|[lgÌXVðs¤
		void M_Component_Update(void);

		// AN^[ÌXVðs¤
		virtual void M_Actor_Update(void) = 0;

		// íÌtOª§ÁÄ¢éR|[lgðí·é
		void M_Delete_Component_Update(void);


		//-- `æ --//

		// AN^[`æ·é
		virtual void M_Actor_Draw(void) = 0;

		// Êí`æãÉAN^[ð`æ·é
		virtual void M_Actor_After_Draw(void) = 0;


		//-- Zb^ --//

		// AN^[ðÊí`æÅ`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÌÍ`æ·éAfalseÌÍ`æµÈ¢
		void M_Set_Draw_Flg(bool);

		// Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÌÍ`æ·éAfalseÌÍ`æµÈ¢
		void M_Set_After_Draw_Flg(bool);

		
		//-- Qb^ --//

		// AN^[ð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÍ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_Draw_Flg(void);

		// Êí`æãÉAN^[ð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÍ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_After_Draw_Flg(void);
	};


	//  Ö  //

	//== vCx[g ==//

	//-- R|[lg --//

	//===============//
	// Ú×   Fwè³ê½R|[lgð¶¬µA»ÌAhXðÔ·
	// ø   Fstring ¶¬·éR|[lg¼
	// ßèl FC_UI_Component_Base * ¶¬µ½R|[lgÌAhX
	//===============//
	template<C_Checked_Component_Class C_Component_Class>
	inline C_Component_Class * C_Actor_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		//  Ïé¾  //
		C_Component_Class * new_component = new C_Component_Class();	// Vµ¢R|[lgÌAhX

		int new_component_slot = m_component_list.size();	// Vµ¢R|[lgpÌXbgÔ


		// Vµ¢R|[lgðXgÉÇÁ
		m_component_list.resize(new_component_slot + 1);
		m_component_list[new_component_slot].component.reset(new_component);
		m_component_list[new_component_slot].name = in_set_ui_component_name;

		// ¶¬³ê½R|[lgÌAhXðÔ·
		return new_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


