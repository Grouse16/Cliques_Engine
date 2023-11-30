//����������������������������������������������//
// �ڍ�   �F�J�����̃N���X
// ����   �F�J�����r���[�ƃv���W�F�N�V������S������V�X�e��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Camera_System.h"
#include "E_MATRIX_DIRECTION.h"
#include "C_OS_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::CAMERA;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Camera_System::C_Camera_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Camera_System::~C_Camera_System(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�g���N�X�ϊ��s����X�V����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Camera_System::M_Update_Matrix(void)
{
	// �� �ϐ��錾 �� //
	DirectX::XMMATRIX rotation_matrix;	// ��]�}�g���N�X

	DirectX::XMFLOAT3 camera_target_position = DirectX::XMFLOAT3();	// �J�����̒����_
	DirectX::XMFLOAT3 camera_front_vector = DirectX::XMFLOAT3();	// �J�����̑O���x�N�g��


	// ��]�}�g���N�X���擾����
	rotation_matrix = mpr_variable.quaternion.M_Get_Rotation_Matrix();

	// �J�����̃^�[�Q�b�g���J�����̉�]�������狁�߂�
	DirectX::XMStoreFloat3(&camera_front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);
	camera_target_position.x = mpr_variable.position.xyz.x + camera_front_vector.x * 100.0f;
	camera_target_position.y = mpr_variable.position.xyz.y + camera_front_vector.y * 100.0f;
	camera_target_position.z = mpr_variable.position.xyz.z + camera_front_vector.z * 100.0f;

	// �r���[�ϊ��s��𐶐�����
	mpr_variable.view_matrix = DirectX::XMMatrixLookAtLH
	(
		// �J�������W
		DirectX::XMLoadFloat3(&mpr_variable.position.xyz),

		// �J�����^�[�Q�b�g���W
		DirectX::XMLoadFloat3(&camera_target_position),

		// ������x�N�g��
		rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]
	);


	// �A�X�y�N�g����X�V
	mpr_variable.projection_system.aspect_ratio = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Aspect_Size();

	// �v���W�F�N�V�����ϊ��s��𐶐�����
	mpr_variable.projection_system.M_Get_Projection(mpr_variable.projection_matrix);

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̎���p�����W�A����̊p�x�ŃZ�b�g����
// ����   �Ffloat ���W�A���ł̊p�x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Radian(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = in_set_field_of_view_angle;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̎���p��x����̊p�x�ŃZ�b�g����
// ����   �Ffloat �x���ł̊p�x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Degree(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = DirectX::XMConvertToDegrees(in_set_field_of_view_angle);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̃j�A�N���b�v�������Z�b�g����
// ����   �Ffloat �j�A�N���b�v�����i������J�����O�̕`��͈͂̍ł��߂������j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Camera_System::M_Set_Near_Clip(float in_near_clip_distance)
{
	mpr_variable.projection_system.near_clip_plane = in_near_clip_distance;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̃t�@�[�N���b�v�������Z�b�g����
// ����   �Ffloat �t�@�[�N���b�v�����i������J�����O�̕`��͈͂̍ł��߂������j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Camera_System::M_Set_Far_Clip(float in_far_clip_distance)
{
	mpr_variable.projection_system.far_clip_plane = in_far_clip_distance;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�r���[�̃}�g���N�X�ϊ��s���Ԃ�
// ����   �Fvoid
// �߂�l �Fconst XMMATRIX & �r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const DirectX::XMMATRIX & C_Camera_System::M_Get_View_Matrix(void) const
{
	return mpr_variable.view_matrix;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�v���W�F�N�V�����̃}�g���N�X�ϊ��s���Ԃ�
// ����   �Fvoid
// �߂�l �Fconst XMMATRIX & �v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const DirectX::XMMATRIX & C_Camera_System::M_Get_Projection_Matrix(void) const
{
	return mpr_variable.projection_matrix;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̍��W�ւ̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Position & �J�����̍��W�ւ̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
MATH::POSITION::C_Position & C_Camera_System::M_Get_Position(void)
{
	return mpr_variable.position;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̉�]�i�N�H�[�^�j�I���j�ւ̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Quaternion & ��]�i�N�H�[�^�j�I���j�ւ̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
MATH::QUATERNION::C_Quaternion & C_Camera_System::M_Get_Quaternion(void)
{
	return mpr_variable.quaternion;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̎���p�����W�A����̊p�x�ŕԂ�
// ����   �Fvoid
// �߂�l �Ffloat ���W�A���ł̊p�x
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Camera_System::M_Get_Camera_Field_Of_View_Angle(void)
{
	return mpr_variable.projection_system.field_of_view_angle;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̃j�A�N���b�v������Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �j�A�N���b�v�����i������J�����O�̕`��͈͂̍ł��߂������j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Camera_System::M_Get_Near_Clip(float)
{
	return mpr_variable.projection_system.near_clip_plane;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�J�����̃t�@�[�N���b�v������Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �t�@�[�N���b�v�����i������J�����O�̕`��͈͂̍ł����������j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Camera_System::M_Get_Far_Clip(float)
{
	return mpr_variable.projection_system.far_clip_plane;
}
