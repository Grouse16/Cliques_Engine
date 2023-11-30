//����������������������������������������������//
// �ڍ�   �F�J�����̃N���X
// ����   �F�J�����r���[�ƃv���W�F�N�V������S������V�X�e��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>

#include "C_Position.h"
#include "C_Quaternion.h"
#include "C_Projection_System.h"


// �� �l�[���X�y�[�X �� //

// �J�������Ăяo�����߂̖��O
namespace GAME::CAMERA
{
	// �� �N���X �� //

	// �J�����̃V�X�e��
	class C_Camera_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			MATH::POSITION::C_Position position;	// �J�����̃|�W�V����

			MATH::QUATERNION::C_Quaternion quaternion;	// �J�����̉�]�i�N�H�[�^�j�I���j

			GAME::CAMERA::PROJECTION::C_Projection_System projection_system;	// �v���W�F�N�V����

			DirectX::XMMATRIX view_matrix = DirectX::XMMATRIX();		// �r���[�̃}�g���N�X�ϊ��s��
			DirectX::XMMATRIX projection_matrix = DirectX::XMMATRIX();	// �v���W�F�N�V�����̃}�g���N�X�ϊ��s��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Camera_System(void);

		// �f�X�g���N�^
		~C_Camera_System(void);


		//-��- �X�V -��-//

		// �}�g���N�X�ϊ��s����X�V����
		void M_Update_Matrix(void);


		//-��- �Z�b�^ -��-//

		// �J�����̎���p�����W�A����̊p�x�ŃZ�b�g����@�����F���W�A���ł̊p�x
		void M_Set_Camera_Field_Of_View_Angle_By_Radian(float);

		// �J�����̎���p��x����̊p�x�ŃZ�b�g����@�����F�x���ł̊p�x
		void M_Set_Camera_Field_Of_View_Angle_By_Degree(float);

		// �J�����̃j�A�N���b�v�������Z�b�g����@�����F�j�A�N���b�v�����i������J�����O�̕`��͈͂̍ł��߂������j
		void M_Set_Near_Clip(float);

		// �J�����̃t�@�[�N���b�v�������Z�b�g����@�����F�t�@�[�N���b�v�����i������J�����O�̕`��͈͂̍ł����������j
		void M_Set_Far_Clip(float);


		//-��- �Q�b�^ -��-//

		// �r���[�̃}�g���N�X�ϊ��s���Ԃ��@�߂�l�F�r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		const DirectX::XMMATRIX & M_Get_View_Matrix(void) const;

		// �v���W�F�N�V�����̃}�g���N�X�ϊ��s���Ԃ��@�߂�l�F�v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		const DirectX::XMMATRIX & M_Get_Projection_Matrix(void) const;

		// �J�����̍��W�ւ̎Q�Ƃ�Ԃ��@�߂�l�F�J�����̍��W�ւ̎Q��
		MATH::POSITION::C_Position & M_Get_Position(void);

		// �J�����̉�]�i�N�H�[�^�j�I���j�ւ̎Q�Ƃ�Ԃ��@�߂�l�F��]�i�N�H�[�^�j�I���j�ւ̎Q��
		MATH::QUATERNION::C_Quaternion & M_Get_Quaternion(void);

		// �J�����̎���p�����W�A����̊p�x�ŕԂ��@�����F���W�A���ł̊p�x
		float M_Get_Camera_Field_Of_View_Angle(void);

		// �J�����̃j�A�N���b�v������Ԃ��@�����F�j�A�N���b�v�����i������J�����O�̕`��͈͂̍ł��߂������j
		float M_Get_Near_Clip(float);

		// �J�����̃t�@�[�N���b�v������Ԃ��@�����F�t�@�[�N���b�v�����i������J�����O�̕`��͈͂̍ł����������j
		float M_Get_Far_Clip(float);
	};
}


#endif // !D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE

