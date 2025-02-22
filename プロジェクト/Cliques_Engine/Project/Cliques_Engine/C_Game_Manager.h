////
// Ú×   FQ[ÌVXe§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  CN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


//  t@CÐç«  //
#include "C_Game_State_Manager.h"

#include <vector>


//  l[Xy[X  //

// Q[Ì§äpÌVXe
namespace GAME
{
	//  NX  //

	// Q[§äpVXe
	class C_Game_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// ÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			bool flg_game_exist = true;		// Q[ª¶ÝµÄ¢é©Ç¤©ÌtO
			bool flg_game_activate = false;	// Q[ªÒ­©Ç¤©ÌtO
			bool flg_OS_active_now = false;		// OSVXeªÒ­©Ç¤©ÌtO

		} static mpr_variable;	// ÏðÄÑo·½ßÌ¼O

		static C_Game_Manager m_this;	// Q[§äpÌVXeÌÀÌ(VOg)


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_Game_Manager(void);

		
		//-- XV --//

		// f[^ÌXVðs¤
		static void M_Data_Update(void);

		// EBhE^CgÌXV
		static void M_Window_Title_Update(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// Q[Ìú»
		static void M_Init(void);

		// fXgN^
		~C_Game_Manager(void);

		// ðú
		static void M_Release(void);


		//-- Zb^ --//

		// Q[ð¶ÝµÄ¢éóÔ©Ç¤©ðÝè·é@øFtrueÍ³íÉ¶ÝµÄ¢é
		static void M_Set_Game_Exist_Flg(bool);

		// Q[ªÒ­©Ç¤©ðÝè·é@øFtrueÍÒ­
		static void M_Set_Game_Activate_Flg(bool);


		//-- Qb^ --//

		// Q[ð¶ÝµÄ¢éóÔ©Ç¤©ðæ¾·é@øFtrueÍ³íÉ¶ÝµÄ¢é
		static bool M_Get_Game_Exist_Flg(void);

		// Q[ªANeBuóÔ©Ç¤©ðÔ·@ßèlFANeBuÌÝture
		static bool M_Get_Game_Active_Flg(void);


		//-- Às --//

		// Q[ÌðÀs·é
		static void M_Executes_Process(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================
