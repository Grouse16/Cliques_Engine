////
// Ú×   FÊuÀWÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Position.h"
#include "E_MATRIX_DIRECTION.h"


//  l[Xy[XÌÈª  //
using namespace MATH::POSITION;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Position::C_Position(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Position::~C_Position(void)
{
	return;
}


//-- Qb^ --//

//===============//
// Ú×   FÊuÀWÌ}gNXÏ·sñðÔ·
// ø   Fvoid
// ßèl FXMMATRIX ÊuÀWÌ}gNXÏ·sñ
//===============//
DirectX::XMMATRIX C_Position::M_Get_Position_Matrix(void) const
{
	return DirectX::XMMatrixTranslationFromVector(DirectX::XMVectorSet(xyz.x, xyz.y, xyz.z, 1.0f));
}


//-- Ú® --//

//===============//
// Ú×   Fwè³ê½ÊuÀWÜÅðwè³ê½ªÚ®·é
// ø   Fconst XMFLOAT3 & Ú®æÌÀWÌQÆ(const), float Ú®¦
// ßèl Fvoid
//===============//
void C_Position::M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x += in_to_position.x * in_percent;
	xyz.y += in_to_position.y * in_percent;
	xyz.z += in_to_position.z * in_percent;

	return;
}


//===============//
// Ú×   Fwè³ê½Ú®³©çÚ®æÜÅ©çwè³ê½ªÚ®·é
// ø   Fconst XMFLOAT3 & Ú®³ÌÀWÌQÆ(const), const XMFLOAT3 & Ú®æÌÀWÌQÆ(const), float Ú®¦
// ßèl Fvoid
//===============//
void C_Position::M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & in_base_position, const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x = in_base_position.x + in_to_position.x * in_percent;
	xyz.y = in_base_position.y + in_to_position.y * in_percent;
	xyz.z = in_base_position.z + in_to_position.z * in_percent;

	return;
}


//===============//
// Ú×   Fwè³ê½ûüðOûÆµÄAwè³ê½Ú®ÊªÚ®·é
// ø   FXMFLOAT3 Ú®ûü, XMFLOAT3 Ú®Ê
// ßèl Fvoid
//===============//
void C_Position::M_Move_By_Direction(DirectX::XMFLOAT3 in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	//  Ïé¾  //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// ñ]Ì}gNX
	
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// ¡ûüxNgiEîj
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// cûüxNgiãîj
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// OãûüxNgiOîj

	
	// Ú®ûüÖÌñ]}gNXðæ¾
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// »ê¼êÌûüðæ¾
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ûü¬ªÉÎ·éÚ®ðs¤
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//===============//
// Ú×   Fwè³ê½ûüðOûÆµÄAwè³ê½Ú®ÊªÚ®·é
// ø   FXMMATRIX ûüÌ}gNX, XMFLOAT3 Ú®Ê
// ßèl Fvoid
//===============//
void C_Position::M_Move_By_Direction(DirectX::XMMATRIX in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	//  Ïé¾  //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// ¡ûüxNgiEîj
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// cûüxNgiãîj
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// OãûüxNgiOîj


	// »ê¼êÌûüðæ¾
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ûü¬ªÉÎ·éÚ®ðs¤
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//===============//
// Ú×   Fwè³ê½Ú®ûüÖÌÝwè³ê½Ú®ÊªÚ®·é
// ø   FXMFLOAT3 ûüÌ}gNX, float Ú®Ê
// ßèl Fvoid
//===============//
void C_Position::M_Move_Front_By_Direction(DirectX::XMFLOAT3 in_move_dire, float in_move_value)
{
	//  Ïé¾  //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// ñ]Ì}gNX

	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// ¡ûüxNgiEîj
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// cûüxNgiãîj
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// OãûüxNgiOîj


	// Ú®ûüÖÌñ]}gNXðæ¾
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// »ê¼êÌûüðæ¾
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ûü¬ªÉÎ·éÚ®ðs¤
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}


//===============//
// Ú×   Fwè³ê½Ú®ûüÖÌÝwè³ê½Ú®ÊªÚ®·é
// ø   FXMMATRIX ûüÌ}gNX, float Ú®Ê
// ßèl Fvoid
//===============//
void C_Position::M_Move_Front_By_Direction(DirectX::XMMATRIX in_move_dire, float in_move_value)
{
	//  Ïé¾  //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// ¡ûüxNgiEîj
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// cûüxNgiãîj
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// OãûüxNgiOîj


	// »ê¼êÌûüðæ¾
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ûü¬ªÉÎ·éÚ®ðs¤
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}
