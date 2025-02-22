////
// Ú×   FCJÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Main_Camera.h"
#include "C_Projection_System.h"
#include "C_OS_User_System.h"


//  l[Xy[XÌÈª  //
using namespace GAME::CAMERA::MAIN_CAMERA;


//  X^eBbNÏ  //
C_Main_Camera C_Main_Camera::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Main_Camera::C_Main_Camera(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FCJðú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Main_Camera::M_Reset(void)
{
	//  è  //
	GAME::CAMERA::PROJECTION::C_Projection_System projection_init;	// vWFNVÌúl


	// r[Ì}gNXðú»·é
	m_this.mpr_variable.view = DirectX::XMMATRIX();

	// vWFNVÌ}gNXðú»·é
	projection_init.aspect_ratio = OS::C_OS_User_System::M_Get_Window_Aspect_Ratio();
	projection_init.M_Get_Projection(m_this.mpr_variable.projection);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Main_Camera::~C_Main_Camera(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   Fr[Ì}gNXÏ·sñðZbg·é
// ø   Fconst XMMATRIX & Zbg·ér[Ì}gNXÏ·sñÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Main_Camera::M_Set_View_Matrix(const DirectX::XMMATRIX & in_set_view)
{
	m_this.mpr_variable.view = in_set_view;

	return;
}


//===============//
// Ú×   FvWFNVÌ}gNXÏ·sñðZbg·é
// ø   Fconst XMMATRIX & Zbg·évWFNVÌ}gNXÏ·sñÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Main_Camera::M_Set_Projection_Matrix(const DirectX::XMMATRIX & in_set_projection)
{
	m_this.mpr_variable.projection = in_set_projection;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fr[Ì}gNXÏ·sñÌQÆðÔ·
// ø   Fvoid
// ßèl Fconst XMMATRIX & r[Ì}gNXÏ·sñÌQÆiconstj
//===============//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_View_Matrix(void)
{
	return m_this.mpr_variable.view;
}


//===============//
// Ú×   FvWFNVÌ}gNXÏ·sñÌQÆðÔ·
// ø   Fvoid
// ßèl Fconst XMMATRIX & vWFNVÌ}gNXÏ·sñÌQÆiconstj
//===============//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_Projection_Matrix(void)
{
	return m_this.mpr_variable.projection;
}
