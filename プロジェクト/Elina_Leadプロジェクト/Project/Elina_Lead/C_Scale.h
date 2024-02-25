//����������������������������������������������//
// �ڍ�   �F�X�P�[���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SCALE_H_FILE
#define D_INCLUDE_GUARD_C_SCALE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// �X�P�[���̃V�X�e�����Ăяo�����߂̖��O
namespace MATH::SCALE
{
	// �� �N���X �� //

	// �X�P�[���̃V�X�e���̃N���X
	class C_Scale
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		DirectX::XMFLOAT3 xyz = DirectX::XMFLOAT3();	// �X�P�[���l


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Scale(void);

		// �f�X�g���N�^
		~C_Scale(void);


		//-��- �Q�b�^ -��-//

		// �g��k���̃}�g���N�X�𐶐����ĕԂ��@�߂�l�F�g��k���̃}�g���N�X
		DirectX::XMMATRIX M_Get_Scale_Matrix(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCALE_H_FILE

