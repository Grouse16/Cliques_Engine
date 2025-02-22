////
// Ú×   FJÌNX
// à¾   FJr[ÆvWFNVðS·éVXe
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE


//  t@CÐç«  //
#include <DirectXMath.h>

#include "C_Position.h"
#include "C_Quaternion.h"
#include "C_Projection_System.h"


//  l[Xy[X  //

// JðÄÑo·½ßÌ¼O
namespace GAME::CAMERA
{
	//  NX  //

	// JÌVXe
	class C_Camera_System
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			MATH::POSITION::C_Position position;	// JÌ|WV

			MATH::QUATERNION::C_Quaternion quaternion;	// JÌñ]iNH[^jIj

			GAME::CAMERA::PROJECTION::C_Projection_System projection_system;	// vWFNV

			DirectX::XMMATRIX view_matrix = DirectX::XMMATRIX();		// r[Ì}gNXÏ·sñ
			DirectX::XMMATRIX projection_matrix = DirectX::XMMATRIX();	// vWFNVÌ}gNXÏ·sñ

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Camera_System(void);

		// fXgN^
		~C_Camera_System(void);


		//-- XV --//

		// }gNXÏ·sñðXV·é
		void M_Update_Matrix(void);


		//-- Zb^ --//

		// JÌìpðWAîÌpxÅZbg·é@øFWAÅÌpx
		void M_Set_Camera_Field_Of_View_Angle_By_Radian(float);

		// JÌìpðxîÌpxÅZbg·é@øFxÅÌpx
		void M_Set_Camera_Field_Of_View_Angle_By_Degree(float);

		// JÌjANbv£ðZbg·é@øFjANbv£iäJOÌ`æÍÍÌÅàß¢£j
		void M_Set_Near_Clip(float);

		// JÌt@[Nbv£ðZbg·é@øFt@[Nbv£iäJOÌ`æÍÍÌÅà¢£j
		void M_Set_Far_Clip(float);


		//-- Qb^ --//

		// r[Ì}gNXÏ·sñðÔ·@ßèlFr[Ì}gNXÏ·sñÌQÆiconstj
		const DirectX::XMMATRIX & M_Get_View_Matrix(void) const;

		// vWFNVÌ}gNXÏ·sñðÔ·@ßèlFvWFNVÌ}gNXÏ·sñÌQÆiconstj
		const DirectX::XMMATRIX & M_Get_Projection_Matrix(void) const;

		// JÌÀWÖÌQÆðÔ·@ßèlFJÌÀWÖÌQÆ
		MATH::POSITION::C_Position & M_Get_Position(void);

		// JÌñ]iNH[^jIjÖÌQÆðÔ·@ßèlFñ]iNH[^jIjÖÌQÆ
		MATH::QUATERNION::C_Quaternion & M_Get_Quaternion(void);

		// JÌìpðWAîÌpxÅÔ·@øFWAÅÌpx
		float M_Get_Camera_Field_Of_View_Angle(void);

		// JÌjANbv£ðÔ·@øFjANbv£iäJOÌ`æÍÍÌÅàß¢£j
		float M_Get_Near_Clip(float);

		// JÌt@[Nbv£ðÔ·@øFt@[Nbv£iäJOÌ`æÍÍÌÅà¢£j
		float M_Get_Far_Clip(float);
	};
}


#endif // !D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE

