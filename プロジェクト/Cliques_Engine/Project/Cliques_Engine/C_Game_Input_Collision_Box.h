////
// Ú×   FQ[ÌüÍ»èðÆé{bNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


//  t@CÐç«  //
#include "C_Game_Input_Collision_Manager.h"

#include "S_Rect.h"


//  l[Xy[X  //

// Q[Ì½è»èÌüÍÌVXeðÄÑo·½ßÌ¼O
namespace GAME::INPUT::COLLISION
{
	//  NX  //

	// Q[ÌüÍ»èðÆé{bNX
	class C_Game_Input_Collision_Box : public GAME::INPUT::COLLISION::C_Game_Input_Collision
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			DATA::RECTSETTING::S_Rect collision_rect;	// üÍðó¯t¯é{bNXÌÍÍ
			
		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Game_Input_Collision_Box(void);

		// fXgN^
		~C_Game_Input_Collision_Box(void) override;


		//-- Zb^ --//

		// lp`Ì½è»èðÝè·é@øFÝè·é½è»èÌQÆ
		void M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect &);


		//-- Qb^ --//

		// lp`Ì½è»èÌQÆðæ¾·é@ßèlF»ÝÌ½è»èÌQÆ(const)
		const DATA::RECTSETTING::S_Rect & M_Get_Collision_Box(void);


		//-- ½è»è --//

		// wè³ê½ÀWÆdÈÁÄ¢é©Ç¤©@øF½è»èÌÀW, ½è»èÌÀW@ßèlF½ÁÄ¢½çtrue
		bool M_Collision_To_Pixel(int, int) const override;
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


