////
// Ú×   FCJÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
#define D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE


//  t@CÐç«  //
#include <DirectXMath.h>


//  l[Xy[X  //

// CÆÈéJðÄÑo·½ßÌ¼O
namespace GAME::CAMERA::MAIN_CAMERA
{
	//  NX  //
	
	// CJÌNX
	class C_Main_Camera
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			DirectX::XMMATRIX view = DirectX::XMMATRIX();	// r[Ì}gNXÏ·sñ
			DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// vWFNVÌ}gNXÏ·sñ

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static C_Main_Camera m_this;	// VOg»·é½ßÌCX^X


		//-- ú» --//

		// RXgN^
		C_Main_Camera(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// CJðú»·é
		static void M_Reset(void);

		// fXgN^
		~C_Main_Camera(void);


		//-- Zb^ --//

		// r[Ì}gNXÏ·sñðZbg·é@øFZbg·ér[Ì}gNXÏ·sñÌQÆiconstj
		static void M_Set_View_Matrix(const DirectX::XMMATRIX & );

		// vWFNVÌ}gNXÏ·sñðZbg·é@øFZbg·évWFNVÌ}gNXÏ·sñÌQÆiconstj
		static void M_Set_Projection_Matrix(const DirectX::XMMATRIX & );

		
		//-- Qb^ --//

		// r[Ì}gNXÏ·sñÌQÆðÔ·@ßèlFr[Ì}gNXÏ·sñÌQÆiconstj
		static const DirectX::XMMATRIX & M_Get_View_Matrix(void);

		// vWFNVÌ}gNXÏ·sñÌQÆðÔ·@ßèlFvWFNVÌ}gNXÏ·sñÌQÆiconstj
		static const DirectX::XMMATRIX & M_Get_Projection_Matrix(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
