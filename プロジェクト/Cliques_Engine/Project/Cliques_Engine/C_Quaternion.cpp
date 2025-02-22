////
// Ú×   FNH[^jIVXeÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Quaternion.h"


//  l[Xy[XÌÈª  //
using namespace MATH::QUATERNION;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Quaternion::C_Quaternion(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Quaternion::~C_Quaternion(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FNH[^jIðZbg·é
// ø   Fconst XMVECTOR & Zbg·éNH[^jIÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Quaternion::M_Set_Quaternion(const DirectX::XMVECTOR & in_set_quaternion)
{
	mpr_variable.m_rotation_vector = in_set_quaternion;

	return;
}


//===============//
// Ú×   FxÌñ]Ìîñ©çNH[^jIðZbg·é
// ø   FXMFLOAT3 ñ]îñ
// ßèl Fvoid
//===============//
void C_Quaternion::M_Set_Quaternion_By_Angle(DirectX::XMFLOAT3 in_set_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_set_rotation.x),
			DirectX::XMConvertToRadians(in_set_rotation.y),
			DirectX::XMConvertToRadians(in_set_rotation.z)
		)
	);

	return;
}


//===============//
// Ú×   FxÌñ]Ìîñ©çNH[^jIðZbg·é
// ø   Ffloat [, float sb`, float E
// ßèl Fvoid
//===============//
void C_Quaternion::M_Set_Quaternion_By_Angle(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_roll),
			DirectX::XMConvertToRadians(in_pitch),
			DirectX::XMConvertToRadians(in_yaw)
		)
	);

	return;
}


//===============//
// Ú×   FWAÌñ]Ìîñ©çNH[^jIðZbg·é
// ø   FXMFLOAT3 ñ]îñ
// ßèl Fvoid
//===============//
void C_Quaternion::M_Set_Quaternion_By_Radian(DirectX::XMFLOAT3 in_set_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			in_set_rotation.x,
			in_set_rotation.y,
			in_set_rotation.z
		)
	);

	return;
}


//===============//
// Ú×   FWAÌñ]Ìîñ©çNH[^jIðZbg·é
// ø   Ffloat [, float sb`, float E
// ßèl Fvoid
//===============//
void C_Quaternion::M_Set_Quaternion_By_Radian(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			in_roll,
			in_pitch,
			in_yaw
		)
	);

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FNH[^jIÌñ]xNgðÔ·
// ø   Fvoid
// ßèl FXMVECTOR NH[^jIÌñ]xNg
//===============//
DirectX::XMVECTOR C_Quaternion::M_Get_Quaternion_Rotation_Vector(void) const
{
	return mpr_variable.m_rotation_vector;
}


//===============//
// Ú×   Fñ]Ì}gNXÏ·sñðÔ·
// ø   Fvoid
// ßèl FXMMATRIX ñ]}gNXsñ
//===============//
DirectX::XMMATRIX C_Quaternion::M_Get_Rotation_Matrix(void) const
{
	return DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector);
}


//===============//
// Ú×   F»ÝÌNH[^jI©çwè³ê½ñ]ûüÖÌxNgðÔ·
// ø   Fconst XMFLOAT3 & ñ]ûü
// ßèl FXMFLOAT3 wè³ê½ñ]ûüÖÌxNg
//===============//
DirectX::XMFLOAT3 C_Quaternion::M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & in_rotation_vector) const
{
	//  Ïé¾  //
	DirectX::XMFLOAT3 result_vector = DirectX::XMFLOAT3();	// ñ]Ê
	

	// }gNXsñÅwè³ê½ûüÖÌxNgð¶¬
	DirectX::XMStoreFloat3
	(
		// ûüÌÝèæ
		&result_vector,
		
		// ûüxNgÌvZ
		DirectX::XMVector3TransformNormal
		(
			DirectX::XMLoadFloat3(&in_rotation_vector),
			DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector)
		)
	);

	return result_vector;
}


//-- NH[^jI --//

//===============//
// Ú×   FxÅwèlª¾¯ñ]³¹é
// ø   Ffloat [, float sb`, float E
// ßèl Fvoid
//===============//
void C_Quaternion::M_Add_Rotation_By_Angle(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_roll),
			DirectX::XMConvertToRadians(in_pitch),
			DirectX::XMConvertToRadians(in_yaw)
		)
	);

	return;
}


//===============//
// Ú×   FxÅwèlª¾¯ñ]³¹é
// ø   FXMFLOAT3 ñ]îñ
// ßèl Fvoid
//===============//
void C_Quaternion::M_Add_Rotation_By_Angle(DirectX::XMFLOAT3 in_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_rotation.x),
			DirectX::XMConvertToRadians(in_rotation.y),
			DirectX::XMConvertToRadians(in_rotation.z)
		)
	);

	return;
}


//===============//
// Ú×   FWAÅwèlª¾¯ñ]³¹é
// ø   Ffloat [, float sb`, float E
// ßèl Fvoid
//===============//
void C_Quaternion::M_Add_Rotation_By_Radian(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			in_roll,
			in_pitch,
			in_yaw
		)
	);

	return;
}


//===============//
// Ú×   FWAÅwèlª¾¯ñ]³¹é
// ø   FXMFLOAT3 ñ]îñ
// ßèl Fvoid
//===============//
void C_Quaternion::M_Add_Rotation_By_Radian(DirectX::XMFLOAT3 in_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			in_rotation.x,
			in_rotation.y,
			in_rotation.z
		)
	);

	return;
}


//===============//
// Ú×   F»ÝÌñ]xNg©çwè³ê½NH[^jIÜÅâÔ¦ÉæéÊü`âÔðs¤
// ø   Fconst XMVECTOR & âÔæÌNH[^jIÖÌQÆ(const), float âÔ¦i0%Å³lA100%ÅÚ®æÆ¯¶lj
// ßèl Fvoid
//===============//
void C_Quaternion::M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(mpr_variable.m_rotation_vector, in_slerp_to, in_percent);

	return;
}


//===============//
// Ú×   FêÂÚÌNH[^jI©çñÂÚÌNH[^jIÖwè³ê½âÔ¦ÌÊü`âÔðs¤
// ø   Fconst XMVECTOR & âÔ³NH[^jIÌQÆ(const), const XMVECTOR & âÔ³NH[^jIÌQÆ(const), float âÔ¦i0%ÅêÂÚA100%ÅñÂÆ¯¶Êuj
// ßèl Fvoid
//===============//
void C_Quaternion::M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_slerp_base, const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(in_slerp_base, in_slerp_to, in_percent);

	return;
}


//===============//
// Ú×   F»ÝÌñ]xNg©çwè³ê½NH[^jIÜÅâÔ¦Éæéü`âÔðs¤
// ø   Fconst XMVECTOR & âÔæNH[^jIÌQÆ(const), float âÔ¦i0%Å³lA100%ÅÚ®æÆ¯¶lj
// ßèl Fvoid
//===============//
void C_Quaternion::M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(mpr_variable.m_rotation_vector, in_lerp_to, in_percent);

	return;
}


//===============//
// Ú×   FêÂÚÌNH[^jI©çñÂÚÌNH[^jIÖwè³ê½âÔ¦Ìü`âÔðs¤
// ø   Fconst XMVECTOR & âÔ³NH[^jIÌQÆ(const), const XMVECTOR & âÔæNH[^jIÌQÆ(const), float âÔ¦i0%ÅêÂÚA100%ÅñÂÆ¯¶Êuj
// ßèl Fvoid
//===============//
void C_Quaternion::M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_lerp_base, const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(in_lerp_base, in_lerp_to, in_percent);

	return;
}
