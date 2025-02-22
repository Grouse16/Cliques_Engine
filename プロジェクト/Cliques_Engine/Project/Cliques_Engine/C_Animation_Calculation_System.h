////
// Ú×   FAj[VÌvZð§ä·éNX
// à¾   F{[}gNXÉÎ·éAj[VÌìðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE


//  t@CÐç«  //
#include <memory>
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "S_Bone_Inform.h"
#include "S_Animation_Status.h"
#include "C_Animation_Data_System.h"


//  l[Xy[X  //

// Aj[VÌvZVXeðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION::CALCULATOR
{
	//  è  //

	// Aj[VÌuhI¹ãÌ®ðwè·é½ßÌñ
	enum class E_ANIMATION_BLENDED_AFTER
	{
		e_NOT_BLENDING_NOW,	// ¡ÍuhµÄ¢È¢

		e_PLAY_ANIMATION,	// Aj[VðÊíÄ¶
		e_LOOP_ANIMATION,	// Aj[Vð[vÄ¶
	};


	//  NX  //
	
	// Aj[VÌvZð§ä·éNX
	class C_Animation_Calculation_System
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::unique_ptr<ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base> animation_algorithm = nullptr;	// Aj[VÌASY

			ASSET::ANIMATION::S_Animation_Status animation_status;	// Aj[VÌXe[^X

			E_ANIMATION_BLENDED_AFTER blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;	// Aj[VuhI¹ãÌóÔðwè


			//  Ö  //

			//-- ú» --//

			// ÊíÌRXgN^ð³ø»
			SPr_Variable(void) = delete;

			//===============//
			// Ú×   F{[ú»pÌRXgN^
			// ø   Fint {[
			// ßèl FÈµ
			//===============//
			SPr_Variable(int bone_sum) : animation_status(bone_sum)
			{
				return;
			}

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//  Ö  //

		//-- uh§ä --//
		
		// uhI¹ðmFµAÎµ½Aj[VÉüêÖ¦é
		void M_Check_Blend_End_And_Animation_Setting(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^Éæéú»ð³øµA{[îñÌXgðZbgµÈ¯êÎú»Å«È­·é
		C_Animation_Calculation_System(void) = delete;

		// RXgN^@øF{[îñÌXgÌQÆ(const)
		C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// fXgN^
		~C_Animation_Calculation_System(void);

		// Aj[VÌXe[^XÌú»
		void M_Animation_Status_Reset(void);


		//-- Zb^ --//

		// »ÝÌAj[VÔðZbg·é@øFZbg·éAj[VÔ
		void M_Set_Animation_Time(float);

		// »ÝÌAj[VÔðZbg·é@øFZbg·éAj[VÌXs[h
		void M_Set_Animation_Speed(float);

		// uhÉ©©éÔðZbg·é@øFZbg·éuhÉ©©éÔ
		void M_Set_Need_Blend_Time(float);


		//-- Qb^ --//

		// Aj[VªI¹µÄ¢é©Ç¤©ðÔ·@ßèlFAj[VI¹ÌtO
		bool M_Get_Animation_Is_End(void);

		// »ÝÌAj[VÔðÔ·@ßèlF»ÝÌAj[VÔ
		float M_Get_Animation_Time(void);

		// »ÝÌAj[VÌXs[hðÔ·@ßèlF»ÝÌAj[VÌXs[h
		float M_Get_Animation_Speed(void);

		// »ÝÌAj[VÌuh¦ðÔ·@ßèlF»ÝÌAj[VÌuh¦
		float M_Get_Animation_Blend_Percent(void);


		//-- XV --//

		// Aj[VÔÌoßðs¤@øFoß³¹éÔ
		void M_Update_Time(float);


		//-- Aj[V --//

		// n³ê½Aj[VðÄ¶·é@øFÄ¶·éAj[Vf[^ÌAhX(const)
		void M_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// n³ê½Aj[Vð[vÄ¶·é@øFÄ¶·éAj[Vf[^ÌAhX(const)
		void M_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// n³ê½Aj[VðuhµÄÄ¶·é@øFÄ¶·éAj[Vf[^ÌAhXiuhæj(const)
		void M_Blend_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// n³ê½Aj[VðuhãA[vÄ¶·é@øFÄ¶·éAj[Vf[^ÌAhXiuhæj(const)
		void M_Blend_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// wè³ê½zñÉAj[VÊÌ{[}gNXzñÌf[^ðZbg·é@øFÝèæÌ{[}gNXzñÌf[^ÌQÆ, {[ItZbg}gNXÌXgÌQÆ(const)
		void M_Create_Animation_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & , const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
