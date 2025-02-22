////
// Ú×   F|XgGtFNgÌîêÆÈéNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE


//  t@CÐç«  //
#include "C_Game_Instance_Base.h"


//  l[Xy[X  //

// Q[Ì|XgGtFNgÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE::POST_EFFECT::BASE
{
	//  NX  //

	// |XgGtFNgÌîêÆÈéNX
	class C_Post_Effect_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		bool m_flg_draw_before_ui = true;	// UI`æOÉ|XgGtFNgð`æ·é©Ç¤©ÌtOAtrueÅ`æ·é
		bool m_flg_draw_after_ui = false;	// UI`æãÉ|XgGtFNgð`æ·é©Ç¤©ÌtOAtrueÅ`æ·é


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Post_Effect_Base(void);

		// fXgN^
		virtual ~C_Post_Effect_Base(void);


		//-- XV --//

		// |XgGtFNgÌXVðs¤
 		virtual void M_Post_Effect_Update(void) = 0;


		//-- `æ --//

		// |XgGtFNgÌUIOÌ`æðs¤
		virtual void M_Post_Effect_Draw_Before_UI(void) = 0;

		// |XgGtFNgÌUIãÌ`æðs¤
		virtual void M_Post_Effect_Draw_After_UI(void) = 0;


		//-- Zb^ --//

		// UI`æOÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÅ`æ·éAfalseÍ`æµÈ¢
		void M_Set_Flg_Post_Effect_Before_UI_Draw(bool);

		// UI`æãÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðZbg·é@øFtrueÅ`æ·éAfalseÍ`æµÈ¢
		void M_Set_Flg_Post_Effect_After_UI_Draw(bool);


		//-- Qb^ --//

		// UI`æOÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÅ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_Flg_Post_Effect_Before_UI_Draw(void);

		// UI`æãÉ|XgGtFNgð`æ·é©Ç¤©ÌtOðÔ·@ßèlFtrueÅ`æ·éAfalseÍ`æµÈ¢
		bool M_Get_Flg_Post_Effect_After_UI_Draw(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
