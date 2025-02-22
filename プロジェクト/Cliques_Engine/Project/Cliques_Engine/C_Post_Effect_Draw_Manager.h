////
// Ú×   F|XgGtFNgÌ`æ§äVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE


//  t@CÐç«  //
#include <vector>

#include "C_Post_Effect_Base.h"


//  l[Xy[X  //

// |XgGtFNgÌ`æ§äVXeðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER
{
	//  NX  //

	// |XgGtFNgÌ`æ§äð·éNX
	class C_Post_Effect_Draw_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_before_ui_list;	// UIÌ`æOÉ`æ·é|XgGtFNgÌXg
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_after_ui_list;	// UIÌ`æãÉ`æ·é|XgGtFNgÌXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static C_Post_Effect_Draw_Manager m_this;	// |XgGtFNgÌ`æ§äVXeðVOg»·é½ßÌCX^X


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Post_Effect_Draw_Manager(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- I¹ --//

		// fXgN^
		~C_Post_Effect_Draw_Manager(void);


		//-- Zb^ --//

		// UIÌOÉ`æ·é|XgGtFNgð`æXgÉÇÁ·é@øFÇÁ·é|XgGtFNg
		static void M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );

		// UIÌãÉ`æ·é|XgGtFNgð`æXgÉÇÁ·é@øFÇÁ·é|XgGtFNg
		static void M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );


		//-- `æ --//

		// UIÌOÌ|XgGtFNgð`æ·é
		static void M_Draw_Post_Effect_Before_UI(void);

		// UIÌãÌ|XgGtFNgð`æ·é
		static void M_Draw_Post_Effect_After_UI(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE

