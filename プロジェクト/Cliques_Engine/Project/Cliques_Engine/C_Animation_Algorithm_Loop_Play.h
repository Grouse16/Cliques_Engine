////
// Ú×   FAj[Vð[vÄ¶·éNX
// à¾   FêÂÌAj[Vð[vÄ¶µ±¯é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_LOOP_PLAY_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_LOOP_PLAY_H_FILE


//  t@CÐç«  //
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "C_Animation_Data_System.h"
#include "S_Animation_Status.h"


//  l[Xy[X  //

// Aj[VÌvZASYðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION::ALGORITHM
{
	//  NX  //

	// Aj[Vð[vÅÄ¶·éNX
	class C_Animation_Algorithm_Loop_Play : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		ASSET::ANIMATION::S_Animation_Status & m_animation_status;	// Aj[VXe[^X

		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_now_animation = nullptr;	// »ÝÌAj[V


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^@½àøÉÝèµÈ¢RXgN^ð³ø»
		C_Animation_Algorithm_Loop_Play(void) = delete;

		// RXgN^@øFAj[VXe[^XÌQÆ, Aj[V·éf[^ÌZbg(const)
		C_Animation_Algorithm_Loop_Play(ASSET::ANIMATION::S_Animation_Status &, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System *);

		// fXgN^
		~C_Animation_Algorithm_Loop_Play(void) override;


		//-- XV --//

		// Aj[VÔÌXV
		void M_Animation_Time_Update(void) override;

		// Aj[VÌXV@øFXVð©¯é{[Ì}gNXÌzñÌQÆ, {[ÌItZbg}gNXÌXgÌQÆiconstj
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & ) override;


		//-- Qb^ --//

		// »ÝÌAj[VðÔ·@ßèlF»ÝÌAj[VÌAhX(const)
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_LOOP_PLAY_H_FILE
