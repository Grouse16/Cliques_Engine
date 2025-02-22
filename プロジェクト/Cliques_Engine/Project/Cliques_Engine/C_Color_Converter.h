////
// Ú×   FOíÞÌFîñÔÌÏ·ðs¤NX
// à¾   FOíÞÌFÆÍAC_Color C_Half_Color C_1_Byte_ColorÌ±Æ
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
#define D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE


//  t@CÐç«  //
#include "C_Color.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"


//  l[Xy[X  //

// FÌè`ðÄÑo·½ßÌ¼O
namespace DATA::COLOR
{
	//  NX  //

	// OíÞÌFîñÔÌÏ·ðs¤NX
	class C_Color_Converter
	{
		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^AÀÌ»h~Ì½ßÉí·é
		C_Color_Converter(void) = delete;


		//-- 4oCgFÖÌÏ· --//

		// 1oCgF©ç4oCgFÖÌÏ·@øF1oCgFÌQÆ@ßèlF4oCgF
		static C_Color M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color &);

		// QoCgF©ç4oCgFÖÌÏ·@øFQoCgFÌQÆ@ßèlF4oCgF
		static C_Color M_Convert_Half_Color_To_Color(const C_Half_Color &);


		//-- 2oCgFÖÌÏ· --//

		// 1oCgF©ç2oCgFÖÌÏ·@øF1oCgFÌQÆ@ßèlF2oCgF
		static C_Half_Color M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color &);

		// 4oCgF©ç2oCgFÖÌÏ·@øF4oCgFÌQÆ@ßèlF2oCgF
		static C_Half_Color M_Convert_Color_To_Half_Color(const C_Color &);


		//-- 1oCgFÖÌÏ· --//

		// 2oCgF©ç1oCgFÖÌÏ·@øF2oCgFÌQÆ@ßèlF1oCgF
		static C_1_Byte_Color M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color &);

		// 4oCgF©ç1oCgFÖÌÏ·@øF4oCgFÌQÆ@ßèlF1oCgF
		static C_1_Byte_Color M_Convert_Color_To_1_Byte_Color(const C_Color &);
	};
}


#endif // !D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
