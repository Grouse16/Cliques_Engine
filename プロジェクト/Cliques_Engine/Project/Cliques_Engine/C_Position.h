////
// Ú×   FÊuÀWÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_POSITION_H_FILE
#define D_INCLUDE_GUARD_C_POSITION_H_FILE


//  Ïé¾  //
#include <DirectXMath.h>


//  l[Xy[X  //

// ÊuÀWðÄÑo·½ßÌ¼O
namespace MATH::POSITION
{
	//  NX  //

	// ÊuÀWÌNX
	class C_Position
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		DirectX::XMFLOAT3 xyz = DirectX::XMFLOAT3();	// ÀWl


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Position(void);

		// fXgN^
		~C_Position(void);


		//-- Qb^ --//

		// ÊuÀWÌ}gNXÏ·sñðÔ·@ßèlFÊuÀWÌ}gNXÏ·ðsñ
		DirectX::XMMATRIX M_Get_Position_Matrix(void) const;


		//-- Ú® --//

		// wè³ê½ÊuÀWÜÅðwè³ê½ªÚ®·é@øFÚ®æÌÀWÌQÆ(const), Ú®¦
		void M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & , float);

		// wè³ê½Ú®³©çÚ®æÜÅ©çwè³ê½ªÚ®·é@øFÚ®³ÌÀWÌQÆ(const), Ú®æÌÀWÌQÆ(const), Ú®¦
		void M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & , const DirectX::XMFLOAT3 & , float);

		// wè³ê½ûüðOûÆµÄAwè³ê½Ú®ÊªÚ®·é@øFÚ®ûü, Ú®Ê
		void M_Move_By_Direction(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

		// wè³ê½ûüðOûÆµÄAwè³ê½Ú®ÊªÚ®·é@øFûüÌ}gNX, XMFLOAT3 Ú®Ê
		void M_Move_By_Direction(DirectX::XMMATRIX, DirectX::XMFLOAT3);

		// wè³ê½Ú®ûüÖÌÝÚ®ÊªÚ®·é@øFÚ®ûü, Ú®Ê
		void M_Move_Front_By_Direction(DirectX::XMFLOAT3, float);

		// wè³ê½Ú®ûüÖÌÝÚ®ÊªÚ®·é@øFXMMATRIX ûüÌ}gNX, float Ú®Ê
		void M_Move_Front_By_Direction(DirectX::XMMATRIX, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_POSITION_H_FILE
