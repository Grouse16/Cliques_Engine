//����������������������������������������������//
// �ڍ�   �F2D���_���W�p�̃f�[�^��`�p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE
#define D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE


// �� �l�[���X�y�[�X �� //

// 2D�̒��_���W�p�̃f�[�^�̒�`���Ăяo�����߂̖��O
namespace DATA::POSITION_2D
{
	// �� �N���X �� //

	// 2D�̒��_���W�̃N���X
	class C_2D_Position
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float x = 0.0f;	// �����W
		float y = 0.0f;	// �����W


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_2D_Position(void) { return; }

		// �f�X�g���N�^
		~C_2D_Position(void) { return; }


		//-��- �ݒ� -��-//

		// ���_���Z�b�g����
		void M_Set_Position(float in_x, float in_y)
		{
			x = in_x;
			y = in_y;

			return;
		}
	};


	// 2D�̃s�N�Z�����W�̃N���X
	class C_2D_Pixel_Position
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		int x = 0;	// �����W
		int y = 0;	// �����W


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_2D_Pixel_Position(void) { return; }

		// �f�X�g���N�^
		~C_2D_Pixel_Position(void) { return; }


		//-��- �ݒ� -��-//

		// ���_���Z�b�g����
		void M_Set_Vertex(int in_x, int in_y)
		{
			x = in_x;
			y = in_y;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE

