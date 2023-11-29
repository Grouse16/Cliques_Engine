//����������������������������������������������//
// �ڍ�   �F�v���W�F�N�V�����̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// �v���W�F�N�V�����̃V�X�e�����Ăяo�����߂̖��O
namespace GAME::CAMERA::PROJECTION
{
	// �� �\���� �� //

	// �v���W�F�N�V�����̃V�X�e���̍\����
	class C_Projection_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float field_of_view_angle = 0.7853f;	// ����p�i���W�A���j
		float aspect_ratio = 1.0f;			// �A�X�y�N�g��	
		float near_clip_plane = 1.0f;			// �j�A�N���b�v�i������J�����O�F����ȉ��̋����ɂ��郁�b�V���͕`�悵�Ȃ��j
		float far_clip_plane = 1000.0f;		// �t�@�[�N���b�v�i������J�����O�F����ȏ�̋����ɂ��郁�b�V���͕`�悵�Ȃ��j


		// �� �֐� �� //
		
		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Projection_System(void);
		
		// �f�X�g���N�^
		~C_Projection_System(void);


		//-��- �Q�b�^ -��-//

		// �v���W�F�N�V�����̃}�g���N�X�ϊ��s���n���ꂽ�Q�Ɛ�ɃZ�b�g����@�����F�v���W�F�N�V�����̃}�g���N�X�ϊ��s��̐ݒ��̎Q��
		void M_Get_Projection(DirectX::XMMATRIX & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE
