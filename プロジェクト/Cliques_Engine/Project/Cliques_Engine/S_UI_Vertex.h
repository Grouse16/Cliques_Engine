////
// Ú×   FUIpÌ¸_Ìè`Ì\¢Ì
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE


//  t@CÐç«  //
#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"


//  l[Xy[X  //

// ¸_f[^ðÄÑo·½ßÌ¼O
namespace DATA::VERTEX
{
	//  \¢Ì  //

	// UIpÌ¸_Ìè`Ì\¢Ì
	struct S_UI_Vertex
	{
		DATA::POSITION_2D::C_2D_Position position;	// sNZÅÌ¸_ÀW

		DATA::COLOR::C_Color color;	// F

		DATA::TEXTURE_UV::C_Texture_UV uv;	// eNX`ÀW
	};
}

#endif // !D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
