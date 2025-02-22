////
// Ú×   F¿´îñpÌf[^
// à¾   FVF[_[è`ÈÇ}eAÝèðMaterial@¿´îñðMaterial_DetailÆ·é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
#define D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE


//  t@CÐç«  //
#include "C_Float_4.h"


//  l[Xy[X  //

// ¿´îñÌè`ðÄÑo·½ßÌ¼O
namespace DATA::MATERIAL_DETAIL
{
	//  \¢Ì  //

	// ¿´îñÌ\¢Ì
	struct S_Material_Detail
	{
		MATH::FORMAT::C_Float_4 ambient;		// ArGg
		MATH::FORMAT::C_Float_4 diffuse;		// fBt[Y
		MATH::FORMAT::C_Float_4 emission;		// G~bV
		MATH::FORMAT::C_Float_4 reflection;		// tNV
		MATH::FORMAT::C_Float_4 specular;		// XyL[
		MATH::FORMAT::C_Float_4 transparent;	// gXyAg
	};
}


#endif // !D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
