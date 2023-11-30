//����������������������������������������������//
// �ڍ�   �F�I�u�W�F�N�g�̍��W�A��]�A�傫���̐ݒ���s���V�X�e��
// ����   �F���O���g�����X�t�H�[���Ƃ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_TRANSFORM_H_FILE
#define D_INCLUDE_GUARD_TRANSFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Position.h"
#include "C_Quaternion.h"
#include "C_Scale.h"


// �� �l�[���X�y�[�X �� //

// ���w�n���̃V�X�e�����Ăяo�����߂̖��O
namespace MATH
{
	// �� �N���X �� //

	// �g�����X�t�H�[���̃N���X
	class C_Transform
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		MATH::POSITION::C_Position position;	// ���W

		MATH::SCALE::C_Scale scale;	// �X�P�[��

		MATH::QUATERNION::C_Quaternion quaternion;	// �N�H�[�^�j�I��


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Transform(void);

		// �f�X�g���N�^
		~C_Transform(void);


		//-��- �ړ� -��-//

		// �������Ă��������O���Ƃ��Ĉړ����s���@�����F�ړ���
		void M_Move(DirectX::XMFLOAT3);


		//-��- �s��ϊ� -��-//

		// ���[���h�ϊ��s��ɕϊ����ĕԂ��@�����F�ϊ��f�[�^�̐ݒ��̎Q��
		void M_Generate_World_Matrix(DirectX::XMMATRIX & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_TRANSFORM_H_FILE
