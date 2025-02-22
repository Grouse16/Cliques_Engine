////
// Ú×   FQ[ãÌCX^Xð§ä·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>
#include <memory>

#include "C_Actor_List.h"
#include "C_User_Interface_List.h"
#include "C_Post_Effect_List.h"
#include "C_Sound_List.h"
#include "C_Game_System_List.h"


//  l[Xy[X  //

// Q[ÌIuWFNgnÌXgðÄÑo·½ßÌ¼O
namespace GAME::INSTANCE
{
	//  NX  //

	// Q[ãÌCX^Xð§ä·éNX
	class C_Game_Instance_Manager
	{
		//== vCx[g ==//
	private:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Instance_Manager(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- í --//

		// Q[ãÌSÄÌCX^XÌÈ©©çAíÌtOª§ÁÄ¢éàÌðÁ·
		static void M_All_Instance_Destroy_Update(void);

		// CX^XÌV[JÚÌíðs¤
		static void M_Instance_Destroy_On_Scene_Change(void);

		// SÄÌCX^Xðí·é
		static void M_Delete_All_Instance(void);


		//-- XV --//

		// SÄÌAN^[ÌXVð·é
		static void M_Update_Actor(void);

		// SÄÌUIÌXVð·é
		static void M_Update_UI(void);

		// SÄÌ|XgGtFNgÌXVð·é
		static void M_Update_Post_Effect(void);

		// SÄÌTEhÌXVð·é
		static void M_Update_Sound(void);

		// SÄÌQ[VXeÌXVð·é
		static void M_Update_Game_System(void);


		//-- `æ --//

		// SÄÌAN^[Ì`æð·é
		static void M_Draw_Actor(void);

		// |XgGtFNgð`æpXgÉÇÁ·é
		static void M_Set_Post_Effect_To_Draw_List(void);

		// UIÌOÉ|XgGtFNgð©¯é`æð·é
		static void M_Draw_Post_Effect_Before_UI(void);

		// SÄÌUIð`æ·é
		static void M_Draw_UI(void);

		// UIÌãÉ|XgGtFNgð©¯é`æð·é
		static void M_Draw_Post_Effect_After_UI(void);


		//-- ¶¬ --//

		//===============//
		// Ú×   Fwè³ê½íÞÌAN^[ð¶¬·é
		// ø   Fstring Ýè·éAN^[¼
		// ßèl FC_Actor * ¶¬³ê½AN^[ÌAhX
		//===============//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Create_Actor(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Create_Actor(in_actor_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌUIð¶¬·é
		// ø   Fstring Ýè·éUI¼
		// ßèl FC_UI * ¶¬³ê½UIÌAhX
		//===============//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Create_UI_List(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Create_UI(in_ui_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌ|XgGtFNgð¶¬·é
		// ø   Fstring Ýè·é|XgGtFNg¼
		// ßèl FC_Post_Effect * ¶¬³ê½|XgGtFNgÌAhX
		//===============//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Create_Post_Effect_List(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Create_Post_Effect(in_post_effect_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌTEhð¶¬·é
		// ø   Fstring Ýè·éTEh¼
		// ßèl FC_Sound * ¶¬³ê½TEhÌAhX
		//===============//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Create_Sound_List(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Create_Sound(in_sound_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌQ[VXeð¶¬·é
		// ø   Fstring Ýè·éQ[VXe¼
		// ßèl FC_Game_System * ¶¬³ê½Q[VXeÌAhX
		//===============//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_List(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Create_System(in_game_system_name);
		}


		//-- Qb^ --//

		//===============//
		// Ú×   Fwè³ê½íÞÌAN^[ÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Actor>> & wè³ê½AN^[ÌXgÌQÆ
		//===============//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static std::vector<std::unique_ptr<C_Actor>> & M_Get_Actor_List(void)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌUIÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_UI>> & wè³ê½UIÌXgÌQÆ
		//===============//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static std::vector<std::unique_ptr<C_UI>> & M_Get_UI_List(void)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌ|XgGtFNgÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Post_Effect>> & wè³ê½|XgGtFNgÌXgÌQÆ
		//===============//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static std::vector<std::unique_ptr<C_Post_Effect>>& M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌTEhÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Sound>> & wè³ê½TEhÌXgÌQÆ
		//===============//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÌQ[VXeÌXgðæ¾·é
		// ø   Fvoid
		// ßèl Fvector<unique_ptr<C_Game_System>> & wè³ê½Q[VXeÌXgÌQÆ
		//===============//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static std::vector<std::unique_ptr<C_Game_System>> & M_Get_Game_System_List(void)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_List();
		}


		//===============//
		// Ú×   Fwè³ê½íÞÅAwè³ê½¼OÌAN^[æ¾·é
		// ø   Fstring æ¾·éAN^[¼
		// ßèl FC_Actor * wè³ê½AN^[ÌAhX
		//===============//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Get_Actor_By_Name(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_By_Name(in_actor_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÅAwè³ê½¼OÌUIÌXgðæ¾·é
		// ø   Fstring æ¾·éUI¼
		// ßèl FC_UI * wè³ê½UIÌAhX
		//===============//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Get_UI_By_Name(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_By_Name(in_ui_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÅAwè³ê½¼OÌ|XgGtFNgÌXgðæ¾·é
		// ø   Fstring æ¾·é|XgGtFNg¼
		// ßèl FC_Post_Effect * wè³ê½|XgGtFNgÌAhX
		//===============//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_By_Name(in_post_effect_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÅAwè³ê½¼OÌTEhÌXgðæ¾·é
		// ø   Fstring æ¾·éTEh¼
		// ßèl FC_Sound * wè³ê½TEhÌAhX
		//===============//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Get_Sound_By_Name(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_By_Name(in_sound_name);
		}


		//===============//
		// Ú×   Fwè³ê½íÞÅAwè³ê½¼OÌQ[VXeÌXgðæ¾·é
		// ø   Fstirng æ¾·éQ[VXe¼
		// ßèl FC_Game_System * wè³ê½Q[VXeÌAhX
		//===============//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_By_Name(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_By_Name(in_game_system_name);
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
