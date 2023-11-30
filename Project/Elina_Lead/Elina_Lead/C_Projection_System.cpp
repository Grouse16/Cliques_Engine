//����������������������������������������������//
// �ڍ�   �F�v���W�F�N�V�����̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Projection_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::CAMERA::PROJECTION;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Projection_System::C_Projection_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Projection_System::~C_Projection_System(void)
{
	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�v���W�F�N�V�����̃}�g���N�X�ϊ��s���n���ꂽ�Q�Ɛ�ɃZ�b�g����
// ����   �FXMMATRIX & �v���W�F�N�V�����̃}�g���N�X�ϊ��s��̐ݒ��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Projection_System::M_Get_Projection(DirectX::XMMATRIX & out_projection_matrix) const
{
	out_projection_matrix = DirectX::XMMatrixPerspectiveFovLH
	(
		// ����p
		field_of_view_angle,

		// �A�X�y�N�g��
		aspect_ratio,

		// �`��͈͊J�n�܂ł̋����i������J�����O�j
		near_clip_plane,

		// �`��͈͏I���܂ł̋����i������J�����O�j
		far_clip_plane
	);

	return;
}
