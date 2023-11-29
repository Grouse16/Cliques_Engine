//����������������������������������������������//
// �ڍ�   �F�ʒu���W�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Position.h"
#include "E_MATRIX_DIRECTION.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH::POSITION;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Position::C_Position(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Position::~C_Position(void)
{
	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʒu���W�̃}�g���N�X�ϊ��s���Ԃ�
// ����   �Fvoid
// �߂�l �FXMMATRIX �ʒu���W�̃}�g���N�X�ϊ��s��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DirectX::XMMATRIX C_Position::M_Get_Position_Matrix(void) const
{
	return DirectX::XMMatrixTranslationFromVector(DirectX::XMVectorSet(xyz.x, xyz.y, xyz.z, 1.0f));
}


//-��- �ړ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ʒu���W�܂ł��w�肳�ꂽ�������ړ�����
// ����   �Fconst XMFLOAT3 & �ړ���̍��W�̎Q��(const), float �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x += in_to_position.x * in_percent;
	xyz.y += in_to_position.y * in_percent;
	xyz.z += in_to_position.z * in_percent;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ړ�������ړ���܂ł���w�肳�ꂽ�������ړ�����
// ����   �Fconst XMFLOAT3 & �ړ����̍��W�̎Q��(const), const XMFLOAT3 & �ړ���̍��W�̎Q��(const), float �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & in_base_position, const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x = in_base_position.x + in_to_position.x * in_percent;
	xyz.y = in_base_position.y + in_to_position.y * in_percent;
	xyz.z = in_base_position.z + in_to_position.z * in_percent;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ������O���Ƃ��āA�w�肳�ꂽ�ړ��ʕ��ړ�����
// ����   �FXMFLOAT3 �ړ�����, XMFLOAT3 �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Move_By_Direction(DirectX::XMFLOAT3 in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	// �� �ϐ��錾 �� //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// ��]�̃}�g���N�X
	
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// �������x�N�g���i�E��j
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// �c�����x�N�g���i���j
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// �O������x�N�g���i�O��j

	
	// �ړ������ւ̉�]�}�g���N�X���擾
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// ���ꂼ��̕������擾
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ���������ɑ΂���ړ����s��
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ������O���Ƃ��āA�w�肳�ꂽ�ړ��ʕ��ړ�����
// ����   �FXMMATRIX �����̃}�g���N�X, XMFLOAT3 �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Move_By_Direction(DirectX::XMMATRIX in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	// �� �ϐ��錾 �� //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// �������x�N�g���i�E��j
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// �c�����x�N�g���i���j
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// �O������x�N�g���i�O��j


	// ���ꂼ��̕������擾
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ���������ɑ΂���ړ����s��
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ړ������ւ̂ݎw�肳�ꂽ�ړ��ʕ��ړ�����
// ����   �FXMFLOAT3 �����̃}�g���N�X, float �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Move_Front_By_Direction(DirectX::XMFLOAT3 in_move_dire, float in_move_value)
{
	// �� �ϐ��錾 �� //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// ��]�̃}�g���N�X

	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// �������x�N�g���i�E��j
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// �c�����x�N�g���i���j
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// �O������x�N�g���i�O��j


	// �ړ������ւ̉�]�}�g���N�X���擾
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// ���ꂼ��̕������擾
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ���������ɑ΂���ړ����s��
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ړ������ւ̂ݎw�肳�ꂽ�ړ��ʕ��ړ�����
// ����   �FXMMATRIX �����̃}�g���N�X, float �ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Position::M_Move_Front_By_Direction(DirectX::XMMATRIX in_move_dire, float in_move_value)
{
	// �� �ϐ��錾 �� //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// �������x�N�g���i�E��j
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// �c�����x�N�g���i���j
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// �O������x�N�g���i�O��j


	// ���ꂼ��̕������擾
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// ���������ɑ΂���ړ����s��
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}
