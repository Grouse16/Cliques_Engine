////
// Ú×   F3DfpÌ¸_tH[}bgÌè`
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE


//  t@CÐç«  //
#include "C_Color.h"
#include "C_Float_3.h"
#include "C_Float_2.h"


//  l[Xy[X  //

// ¸_f[^ðÄÑo·½ßÌ¼O
namespace DATA::VERTEX
{
	//  \¢Ì  //

	// 3DfpÌ¸_îñÌtH[}bg
	struct S_3D_Model_Vertex
	{
		MATH::FORMAT::C_Float_3 vertex;	// ¸_ÀW

		MATH::FORMAT::C_Float_2 uv;	// UVÀW

		DATA::COLOR::C_Color color;	// J[

		MATH::FORMAT::C_Float_3 normal;	// @üxNg

		MATH::FORMAT::C_Float_3 tangent;	// ^WFgxNgiÚüj

		MATH::FORMAT::C_Float_3 binormal_tangent;	// oCm[}^WFgxNgi]@üj
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
