////
// Ú×   FQ[Ì@\ÌîêCX^XÌè`
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE
#define D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE


//  t@CÐç«  //
#include "Game_Function_Priority_Setting.h"



//  l[Xy[X  //

// @\ÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::FUNCTION
{
	//  NX  //

	// Q[ÌCxgpÌîêNXðè`
	class C_Game_Function_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// veNgÌÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			float update_period_time = 0.0f;	// CxgÀsÌüú

			int after_draw_priority = (int)GAME::FUNCTION::PRIOTRITY::E_AFTER_GAME_DRAW_PRIORITY::e_INVALID;	// V[ãÌ`æÌDæxA¢ÙÇãÉ\¦³êé

			int before_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_BEFORE_UPDATE_PRIORITY::e_INVALID;	// V[OÌXVÌDæxA¢ÙÇæÉXV³êé
			int after_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_AFTER_UPDATE_PRIORITY::e_INVALID;	// V[ãÌXVÌDæxA¢ÙÇæÉXV³êé

			bool flg_function_end = false;	// @\ðI¹·é©Ç¤©ÌtO

		} mpr_variable;	// veNgÌÏðÄÑo·½ßÌ¼O


		//== veNg ==//
	protected:

		//-- XV --//

		// V[OÌXV
		virtual void M_Before_Event_Update(void);

		// V[ãÌXV
		virtual void M_After_Event_Update(void);


		//-- Zb^ --//

		// V[OÌXVÌDæxxðÝè·é@øFÝè·éDæx
		void M_Set_Before_Update_Priority(int);

		// V[ãÌXVÌDæxxðÝè·é@øFÝè·éDæx
		void M_Set_After_Update_Priority(int);

		// V[ãÌ`æÌDæxxðÝè·é@øFÝè·éDæx
		void M_Set_After_Draw_Priority(int);


		//==  pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Function_Base(void);

		// fXgN^
		virtual ~C_Game_Function_Base(void);


		//-- XV --//

		// V[OÌCxgðÄÑoµÄÀs·é
		void M_Call_Event_Before_Scene_Process(void);

		// V[ãÌCxgðÄÑoµÄÀs·é
		void M_Call_Event_After_Scene_Process(void);


		//-- oÍ --//

		// V[OÉs¤oÍ
		virtual void M_Draw_Before_Scene_Process(void);

		// V[ãÉs¤oÍ
		virtual void M_After_Draw_Process(void);


		//-- Zb^ --//

		// CxgÀsÌüúðÝè·é@øFÝè·éÌÀsÜÅÌÒ¿Ô
		void M_Set_Update_Period_Time(float);

		// @\ðI¹³¹é©Ç¤©ðÝè·é@øFÝè·éI¹·é©Ç¤©ÌtO
		void M_Set_Flg_End_Function(bool);


		//-- Qb^ --//

		// V[OÌXVÌDæxÌxðÔ·@ßèlFDæxÌlÌQÆ
		const int & M_Get_Before_Update_Priority(void);

		// V[ãÌXVÌDæxÌxðÔ·@ßèlFDæxÌlÌQÆ
		const int & M_Get_After_Update_Priority(void);

		// V[ãÌ`æÌDæxÌxÔ·@ßèlFDæxÌlÌQÆ
		const int & M_Get_After_Draw_Priority(void);

		// @\ðI¹·é©Ç¤©ÌtOðÔ·@ßèlF@\ðI¹·é©Ç¤©ÌtOÌQÆ
		const bool & M_Get_Flg_End_Function(void);
	};
}


#endif // !D_INCLUDE_GUARD_EVENT_BASE_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

