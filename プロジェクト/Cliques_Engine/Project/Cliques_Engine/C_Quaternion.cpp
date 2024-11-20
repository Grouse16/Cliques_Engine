//����������������������������������������������//
// �ڍ�   �F�N�H�[�^�j�I���V�X�e���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Quaternion.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH::QUATERNION;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Quaternion::C_Quaternion(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Quaternion::~C_Quaternion(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�N�H�[�^�j�I�����Z�b�g����
// ����   �Fconst XMVECTOR & �Z�b�g����N�H�[�^�j�I���̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Quaternion::M_Set_Quaternion(const DirectX::XMVECTOR & in_set_quaternion)
{
	mpr_variable.m_rotation_vector = in_set_quaternion;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�x���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����
// ����   �FXMFLOAT3 ��]���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�x���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����
// ����   �Ffloat ���[��, float �s�b�`, float ���E
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���W�A���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����
// ����   �FXMFLOAT3 ��]���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���W�A���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����
// ����   �Ffloat ���[��, float �s�b�`, float ���E
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�N�H�[�^�j�I���̉�]�x�N�g����Ԃ�
// ����   �Fvoid
// �߂�l �FXMVECTOR �N�H�[�^�j�I���̉�]�x�N�g��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DirectX::XMVECTOR C_Quaternion::M_Get_Quaternion_Rotation_Vector(void) const
{
	return mpr_variable.m_rotation_vector;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��]�̃}�g���N�X�ϊ��s���Ԃ�
// ����   �Fvoid
// �߂�l �FXMMATRIX ��]�}�g���N�X�s��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DirectX::XMMATRIX C_Quaternion::M_Get_Rotation_Matrix(void) const
{
	return DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃N�H�[�^�j�I������w�肳�ꂽ��]�����ւ̃x�N�g����Ԃ�
// ����   �Fconst XMFLOAT3 & ��]����
// �߂�l �FXMFLOAT3 �w�肳�ꂽ��]�����ւ̃x�N�g��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DirectX::XMFLOAT3 C_Quaternion::M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & in_rotation_vector) const
{
	// �� �ϐ��錾 �� //
	DirectX::XMFLOAT3 result_vector = DirectX::XMFLOAT3();	// ��]����
	

	// �}�g���N�X�s��Ŏw�肳�ꂽ�����ւ̃x�N�g���𐶐�
	DirectX::XMStoreFloat3
	(
		// �����̐ݒ��
		&result_vector,
		
		// �����x�N�g���̌v�Z
		DirectX::XMVector3TransformNormal
		(
			DirectX::XMLoadFloat3(&in_rotation_vector),
			DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector)
		)
	);

	return result_vector;
}


//-��- �N�H�[�^�j�I�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�x���Ŏw��l��������]������
// ����   �Ffloat ���[��, float �s�b�`, float ���E
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�x���Ŏw��l��������]������
// ����   �FXMFLOAT3 ��]���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���W�A���Ŏw��l��������]������
// ����   �Ffloat ���[��, float �s�b�`, float ���E
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���W�A���Ŏw��l��������]������
// ����   �FXMFLOAT3 ��]���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̉�]�x�N�g������w�肳�ꂽ�N�H�[�^�j�I���܂ŕ�ԗ��ɂ�鋅�ʐ��`��Ԃ��s��
// ����   �Fconst XMVECTOR & ��Ԑ�̃N�H�[�^�j�I���ւ̎Q��(const), float ��ԗ��i0%�Ō��l�A100%�ňړ���Ɠ����l�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Quaternion::M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(mpr_variable.m_rotation_vector, in_slerp_to, in_percent);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ڂ̃N�H�[�^�j�I�������ڂ̃N�H�[�^�j�I���֎w�肳�ꂽ��ԗ��̋��ʐ��`��Ԃ��s��
// ����   �Fconst XMVECTOR & ��Ԍ��N�H�[�^�j�I���̎Q��(const), const XMVECTOR & ��Ԍ��N�H�[�^�j�I���̎Q��(const), float ��ԗ��i0%�ň�ځA100%�œ�Ɠ����ʒu�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Quaternion::M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_slerp_base, const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(in_slerp_base, in_slerp_to, in_percent);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̉�]�x�N�g������w�肳�ꂽ�N�H�[�^�j�I���܂ŕ�ԗ��ɂ����`��Ԃ��s��
// ����   �Fconst XMVECTOR & ��Ԑ�N�H�[�^�j�I���̎Q��(const), float ��ԗ��i0%�Ō��l�A100%�ňړ���Ɠ����l�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Quaternion::M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(mpr_variable.m_rotation_vector, in_lerp_to, in_percent);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ڂ̃N�H�[�^�j�I�������ڂ̃N�H�[�^�j�I���֎w�肳�ꂽ��ԗ��̐��`��Ԃ��s��
// ����   �Fconst XMVECTOR & ��Ԍ��N�H�[�^�j�I���̎Q��(const), const XMVECTOR & ��Ԑ�N�H�[�^�j�I���̎Q��(const), float ��ԗ��i0%�ň�ځA100%�œ�Ɠ����ʒu�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Quaternion::M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_lerp_base, const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(in_lerp_base, in_lerp_to, in_percent);

	return;
}
