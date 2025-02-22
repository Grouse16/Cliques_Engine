////
// Ú×   F¸_obt@ÌüÍCAEgðè`·é½ßÌf[^
// à¾   FGLSLQl¿ https://www.khronos.org/opengl/wiki/OpenGL_Type
// à¾   FHLSLQl¿ https://learn.microsoft.com/en-us/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
#define D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE


//  l[Xy[X  //

// üÍCAEgÝèpÌf[^ðÄÑo·½ßÌ¼O
namespace DATA::INPUTLAYOUT
{
	//  è  //

	// T|[g·éf[^ÌrbgTCY
	enum class E_INPUT_DATA_BITSIZE
	{
		e_1BYTE_8BIT,		// 8rbgA1oCgª@­§IÉInt`®ÉÈéÌÅFLOATÌZbgÍµÈ¢æ¤É·é±Æ
		e_2BYTE_16BIT,	// 16rbgA2oCgª
		e_4BYTE_32BIT,	// 32rbgA4oCgª

		// 64ÍGLSLÌÝÉÈéÌÅT|[gµÈ¢
	};

	// f[^^
	enum class E_INPUT_DATA_FORMAT
	{
		e_INT,		// INT^
		e_UINT,		// UINT^
		e_FLOAT,	// FLOAT^ Í half
	};

	// ÏÌ@ifloat4 â int3ÈÇAxyzwÌwèj
	enum class E_INPUT_DATA_PARAMATOR_SUM
	{
		e_1 = 1,	// PÂ
		e_2 = 2,	// QÂ
		e_3 = 3,	// RÂ
		e_4 = 4,	// SÂ
	};


	//  \¢Ì  //

	// ¶¬pÌîñ
	struct S_INPUT_LAYOUT_SETTING
	{
		E_INPUT_DATA_BITSIZE size;	// ÏêÂªÌrbgTCYivec.xÈÇÌTCYj

		E_INPUT_DATA_FORMAT format;	// `®if[^^j
		
		E_INPUT_DATA_PARAMATOR_SUM sum;	// ÏÌ@ifloat4 â int3ÈÇAxyzwÌwèj
	};
}


#endif // !D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
