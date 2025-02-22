////
// Ú×   FQ[Ì@\ð§ä·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_Game_FUNCTION_MANAGER
#define D_INCLUDE_GUARD_C_Game_FUNCTION_MANAGER


//  t@CÐç«  //
#include <string>
#include <vector>

#include "C_Game_Function_Base.h"


//  l[Xy[X  //

// Q[Ì@\ð§ä·éVXeðÄÑo·½ßÌ¼O
namespace GAME::FUNCTION
{
	//  NX  //

	// Q[Ì@\ð§ä·éNX
	class C_Game_Function_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPR_Variable
		{
			std::vector<GAME::FUNCTION::C_Game_Function_Base * > function_list;	// @\ðÇ·ézñ

			std::vector<GAME::FUNCTION::C_Game_Function_Base * > before_func_update_list;	// V[OÉXV·é@\ÌXg
			std::vector<GAME::FUNCTION::C_Game_Function_Base * > after_func_update_list;	// V[ãÉXV·é@\ÌXg
			std::vector<GAME::FUNCTION::C_Game_Function_Base * > before_func_draw_list;		// `æ·é@\ÌXg
			std::vector<GAME::FUNCTION::C_Game_Function_Base * > after_func_draw_list;			// `æ·é@\ÌXg

			std::vector<std::string> function_create_kind_list;	// @\Ì¶¬vðÜÆß½Xg

			bool flg_reset_list = false;	// XgðZbg·é©Ç¤©ÌtOAêÌ@\ÌDæxªÏX³ê½Æ«Éà¤êxÝèµÈ¨·^C~Oðwè·é½ßÉÝè·é

		} static mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static C_Game_Function_Manager m_this;	// Q[§äpÌVXeÌÀÌ(VOg)


		//  Ö  //

		//-- ú» --//

		// RXgN^AVOg»Égp
		C_Game_Function_Manager(void);


		//-- ¶¬ --//

		// wè³ê½@\Ì^Ì¶¬ðÀs·é
		template <class TYPE_CREATE_FUNCTION>
		static C_Game_Function_Base * M_Create_Function_Excute(void)
		{
			//  Ïé¾  //
			C_Game_Function_Base * new_function_address = nullptr;	// Vµ¢


			// ¶¬µÄXgÉÁ¦é
			new_function_address = new TYPE_CREATE_FUNCTION;
			mpr_variable.function_list.reserve(mpr_variable.function_list.size() + 1);
			mpr_variable.function_list.emplace_back(new_function_address);

			return new_function_address;
		}


		//-- @\ --//

		// @\Ì¶¬ðs¤@øF¶¬·é@\Ì¼O
		static void M_Create_Function_By_Kind(std::string);

		// V[OÉXV·é@\ðÇÁ
		static void M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base *);

		// V[ãÉXV·é@\ðÇÁ
		static void M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base *);

		// V[ãÌXV·é@\ðÇÁ·é
		static void M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Game_Function_Base *);

		// wè³ê½AhXÌ@\ð·×ÄÌo^©çí·é@øFí·é@\ÌAhX
		static void M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Game_Function_Base *);


		//== pubN ==//
	public:

		//  Ö  //

		//-- I¹ --//

		// fXgN^
		~C_Game_Function_Manager(void);

		// ðú
		static void M_Release_Memory(void);


		//-- XV --//

		// V[OÌ@\ÌXVðs¤
		static void M_Before_Scene_Update(void);

		// V[ãÌ@\ÌXVðs¤
		static void M_After_Scene_Update(void);

		// V[ãÌ@\Ì`æðs¤
		static void M_After_Scene_Draw_Update(void);


		//-- @\ --//

		// íÌtOª½Á½@\ðÁ·
		static void M_Delete_Function(void);

		// ¶¬·évÌ Á½@\ðSÄ¶¬·é
		static bool M_Execute_Create_Function_By_List(void);

		// @\Ì¶¬ðv·éAøFstring ¶¬·é@\Ì¼O
		static void M_Command_Create_Function(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_FUNCTION_MANAGER


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

