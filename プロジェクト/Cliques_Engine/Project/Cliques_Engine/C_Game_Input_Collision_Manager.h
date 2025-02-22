////
// Ú×   FQ[ÌüÍÌ½è»èð§ä·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h @//
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE


//  t@CÐç«  //
#include <memory>
#include <string>
#include <vector>

#include "E_Game_Input_Collision_State.h"
#include "Game_Input_Collision_Names.h"


//  l[Xy[X  //

// Q[ÌüÍnðÄÑo·½ßÌ¼O
namespace GAME::INPUT::COLLISION
{
	//  NX  //

	// Q[ÌüÍðó¯æéVXeAîêNX
	class C_Game_Input_Collision
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			E_Game_Input_Collision_State collision_state;	// ½è»èÌóÔ

			std::wstring collision_name = GAME::INPUT::COLLISION::NAME::con_Game_INPUT_COLLISION_INITIALIZED_NAME;	// üÍ{bNX¼

			bool is_active = true;	// ½è»èðLøÉ·é©Ç¤©

			int priority = 0;	// Dæx

		} mpr_variable;	// vCx[gÏðÜÆß½¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Input_Collision(void);

		// fXgN^
		virtual ~C_Game_Input_Collision(void);


		//-- Zb^ --//

		// {bNXÌ¼OðZbg·é@øFÝè·é{bNX¼
		void M_Set_Box_Name(std::wstring);

		// ½è»èðLøÉ·é©Ç¤©ðZbg·é@øFtrueÅANeBuÉ
		void M_Set_Is_Active(bool);

		// ½è»èÌDæxðZbg·é@øFÝè·éDæx
		void M_Set_Priority(int);


		//-- Qb^ --//

		// ½è»èÌ¼Oðæ¾·é@ßèlF»ÝÌ½è»èÌ¼OÌQÆ(const)
		const std::wstring & M_Get_Collision_Name(void) const;

		// ½è»èªLø©Ç¤©ðæ¾·é@ßèlFtrueÈçANeBu
		bool M_Get_Is_Active(void) const;

		// »ÝÌ½è»èÌDæxðÔ·@ßèlF½è»èÌDæx
		int M_Get_Priority(void) const;


		//-- »è --//

		// wè³ê½ÀWÆdÈÁÄ¢é©Ç¤©@øF½è»èÌÀW, ½è»èÌÀW@ßèlF½ÁÄ¢½çtrue
		virtual bool M_Collision_To_Pixel(int, int) const = 0;


		//-- óÔÌJÚ --//

		// ½à³êÄ¢È¢óÔÖJÚ
		void M_Change_State_Command_Not_Hit(void);

		// J[\ªdÈÁÄ¢éóÔÖJÚ
		void M_Change_State_Command_Overed(void);

		// NbNÌóÔÖJÚ
		void M_Change_State_Command_Clicking(void);

		// _uNbNÌóÔÖJÚ
		void M_Change_State_Command_Double_Clicking(void);

		// hbOÌóÔÖJÚ
		void M_Change_State_Command_Dragging(void);

		// hbOÉJ[\ªdÈÁÄ¢éóÔÖJÚ
		void M_Change_State_Command_Dragging_Over(void);

		// hbOÉ½è»èÌãÅhbv³ê½±Æð¦·
		void M_Change_State_Command_Drag_Dropped(void);
	};


	// Q[ÌüÍÌ½è»èð§ä·éVXe
	class C_Game_Input_Collision_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<C_Game_Input_Collision * > collision_list;	// üÍ»èÌXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static std::unique_ptr<C_Game_Input_Collision_Manager> m_this;	// ±ÌNXðCX^X»·é½ßÌÏiVOg»j


		//-- ú» --//

		// RXgN^
		C_Game_Input_Collision_Manager(void);


		//== pubN ==//
	public:

		//-- ú»ÆI¹ --//

		// Q[ÌüÍ{bNX§äpVXeÌ¶¬
		static void M_Init(void);

		// fXgN^
		~C_Game_Input_Collision_Manager(void);

		// ðú
		static void M_Release(void);


		//-- Qb^ --//

		// üÍ»èÌXgÌQÆðÔ·@ßèlFüÍ»èÌXgÌQÆ
		static std::vector<C_Game_Input_Collision * > & M_Get_Input_Collision_List(void);

		
		//-- Xg --//

		// wè³ê½üÍ»èÌAhXðÇpXgÉÇÁ·é@øFXgÉÇÁ·éüÍ»èÌAhX
		static void M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * );

		// wè³ê½üÍ»èÌAhXðÇpXg©çí·é@øFXg©çíµ½¢üÍ»èÌAhX
		static void M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * );
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER



