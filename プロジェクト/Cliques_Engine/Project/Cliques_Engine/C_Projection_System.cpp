////
// Ú×   FvWFNVÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Projection_System.h"


//  l[Xy[XÌÈª  //
using namespace GAME::CAMERA::PROJECTION;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Projection_System::C_Projection_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Projection_System::~C_Projection_System(void)
{
	return;
}


//-- Qb^ --//

//===============//
// Ú×   FvWFNVÌ}gNXÏ·sñðn³ê½QÆæÉZbg·é
// ø   FXMMATRIX & vWFNVÌ}gNXÏ·sñÌÝèæÌQÆ
// ßèl Fvoid
//===============//
void C_Projection_System::M_Get_Projection(DirectX::XMMATRIX & out_projection_matrix) const
{
	out_projection_matrix = DirectX::XMMatrixPerspectiveFovLH
	(
		// ìp
		field_of_view_angle,

		// AXyNgä
		aspect_ratio,

		// `æÍÍJnÜÅÌ£iäJOj
		near_clip_plane,

		// `æÍÍI¹ÜÅÌ£iäJOj
		far_clip_plane
	);

	return;
}
