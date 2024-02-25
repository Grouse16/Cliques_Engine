//����������������������������������������������//
// �ڍ�   �F�ʒu���W�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_POSITION_H_FILE
#define D_INCLUDE_GUARD_C_POSITION_H_FILE


// �� �ϐ��錾 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// �ʒu���W���Ăяo�����߂̖��O
namespace MATH::POSITION
{
	// �� �N���X �� //

	// �ʒu���W�̃N���X
	class C_Position
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		DirectX::XMFLOAT3 xyz = DirectX::XMFLOAT3();	// ���W�l


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Position(void);

		// �f�X�g���N�^
		~C_Position(void);


		//-��- �Q�b�^ -��-//

		// �ʒu���W�̃}�g���N�X�ϊ��s���Ԃ��@�߂�l�F�ʒu���W�̃}�g���N�X�ϊ����s��
		DirectX::XMMATRIX M_Get_Position_Matrix(void) const;


		//-��- �ړ� -��-//

		// �w�肳�ꂽ�ʒu���W�܂ł��w�肳�ꂽ�������ړ�����@�����F�ړ���̍��W�̎Q��(const), �ړ���
		void M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & , float);

		// �w�肳�ꂽ�ړ�������ړ���܂ł���w�肳�ꂽ�������ړ�����@�����F�ړ����̍��W�̎Q��(const), �ړ���̍��W�̎Q��(const), �ړ���
		void M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & , const DirectX::XMFLOAT3 & , float);

		// �w�肳�ꂽ������O���Ƃ��āA�w�肳�ꂽ�ړ��ʕ��ړ�����@�����F�ړ�����, �ړ���
		void M_Move_By_Direction(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

		// �w�肳�ꂽ������O���Ƃ��āA�w�肳�ꂽ�ړ��ʕ��ړ�����@�����F�����̃}�g���N�X, XMFLOAT3 �ړ���
		void M_Move_By_Direction(DirectX::XMMATRIX, DirectX::XMFLOAT3);

		// �w�肳�ꂽ�ړ������ւ݈̂ړ��ʕ��ړ�����@�����F�ړ�����, �ړ���
		void M_Move_Front_By_Direction(DirectX::XMFLOAT3, float);

		// �w�肳�ꂽ�ړ������ւ݈̂ړ��ʕ��ړ�����@�����FXMMATRIX �����̃}�g���N�X, float �ړ���
		void M_Move_Front_By_Direction(DirectX::XMMATRIX, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_POSITION_H_FILE
