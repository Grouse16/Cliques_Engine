////
// Ú×   FJÌNX
// à¾   FJr[ÆvWFNVðS·éVXe
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Camera_System.h"
#include "E_MATRIX_DIRECTION.h"
#include "C_OS_User_System.h"


//  l[Xy[XÌÈª  //
using namespace GAME::CAMERA;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Camera_System::C_Camera_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Camera_System::~C_Camera_System(void)
{
	return;
}


//-- XV --//

//===============//
// Ú×   F}gNXÏ·sñðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Camera_System::M_Update_Matrix(void)
{
	//  Ïé¾  //
	DirectX::XMMATRIX rotation_matrix;	// ñ]}gNX

	DirectX::XMFLOAT3 camera_target_position = DirectX::XMFLOAT3();	// JÌ_
	DirectX::XMFLOAT3 camera_front_vector = DirectX::XMFLOAT3();	// JÌOûxNg


	// ñ]}gNXðæ¾·é
	rotation_matrix = mpr_variable.quaternion.M_Get_Rotation_Matrix();

	// JÌ^[QbgðJÌñ]ûü©çßé
	DirectX::XMStoreFloat3(&camera_front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);
	camera_target_position.x = mpr_variable.position.xyz.x + camera_front_vector.x * 100.0f;
	camera_target_position.y = mpr_variable.position.xyz.y + camera_front_vector.y * 100.0f;
	camera_target_position.z = mpr_variable.position.xyz.z + camera_front_vector.z * 100.0f;

	// r[Ï·sñð¶¬·é
	mpr_variable.view_matrix = DirectX::XMMatrixLookAtLH
	(
		// JÀW
		DirectX::XMLoadFloat3(&mpr_variable.position.xyz),

		// J^[QbgÀW
		DirectX::XMLoadFloat3(&camera_target_position),

		// ãûüxNg
		rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]
	);


	// AXyNgäðXV
	mpr_variable.projection_system.aspect_ratio = OS::C_OS_User_System::M_Get_Window_Aspect_Ratio();

	// vWFNVÏ·sñð¶¬·é
	mpr_variable.projection_system.M_Get_Projection(mpr_variable.projection_matrix);

	return;
}


//-- Zb^ --//

//===============//
// Ú×   FJÌìpðWAîÌpxÅZbg·é
// ø   Ffloat WAÅÌpx
// ßèl Fvoid
//===============//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Radian(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = in_set_field_of_view_angle;

	return;
}


//===============//
// Ú×   FJÌìpðxîÌpxÅZbg·é
// ø   Ffloat xÅÌpx
// ßèl Fvoid
//===============//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Degree(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = DirectX::XMConvertToDegrees(in_set_field_of_view_angle);

	return;
}


//===============//
// Ú×   FJÌjANbv£ðZbg·é
// ø   Ffloat jANbv£iäJOÌ`æÍÍÌÅàß¢£j
// ßèl Fvoid
//===============//
void C_Camera_System::M_Set_Near_Clip(float in_near_clip_distance)
{
	mpr_variable.projection_system.near_clip_plane = in_near_clip_distance;

	return;
}


//===============//
// Ú×   FJÌt@[Nbv£ðZbg·é
// ø   Ffloat t@[Nbv£iäJOÌ`æÍÍÌÅàß¢£j
// ßèl Fvoid
//===============//
void C_Camera_System::M_Set_Far_Clip(float in_far_clip_distance)
{
	mpr_variable.projection_system.far_clip_plane = in_far_clip_distance;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fr[Ì}gNXÏ·sñðÔ·
// ø   Fvoid
// ßèl Fconst XMMATRIX & r[Ì}gNXÏ·sñÌQÆiconstj
//===============//
const DirectX::XMMATRIX & C_Camera_System::M_Get_View_Matrix(void) const
{
	return mpr_variable.view_matrix;
}


//===============//
// Ú×   FvWFNVÌ}gNXÏ·sñðÔ·
// ø   Fvoid
// ßèl Fconst XMMATRIX & vWFNVÌ}gNXÏ·sñÌQÆiconstj
//===============//
const DirectX::XMMATRIX & C_Camera_System::M_Get_Projection_Matrix(void) const
{
	return mpr_variable.projection_matrix;
}


//===============//
// Ú×   FJÌÀWÖÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Position & JÌÀWÖÌQÆ
//===============//
MATH::POSITION::C_Position & C_Camera_System::M_Get_Position(void)
{
	return mpr_variable.position;
}


//===============//
// Ú×   FJÌñ]iNH[^jIjÖÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Quaternion & ñ]iNH[^jIjÖÌQÆ
//===============//
MATH::QUATERNION::C_Quaternion & C_Camera_System::M_Get_Quaternion(void)
{
	return mpr_variable.quaternion;
}


//===============//
// Ú×   FJÌìpðWAîÌpxÅÔ·
// ø   Fvoid
// ßèl Ffloat WAÅÌpx
//===============//
float C_Camera_System::M_Get_Camera_Field_Of_View_Angle(void)
{
	return mpr_variable.projection_system.field_of_view_angle;
}


//===============//
// Ú×   FJÌjANbv£ðÔ·
// ø   Fvoid
// ßèl Ffloat jANbv£iäJOÌ`æÍÍÌÅàß¢£j
//===============//
float C_Camera_System::M_Get_Near_Clip(float)
{
	return mpr_variable.projection_system.near_clip_plane;
}


//===============//
// Ú×   FJÌt@[Nbv£ðÔ·
// ø   Fvoid
// ßèl Ffloat t@[Nbv£iäJOÌ`æÍÍÌÅà¢£j
//===============//
float C_Camera_System::M_Get_Far_Clip(float)
{
	return mpr_variable.projection_system.far_clip_plane;
}
