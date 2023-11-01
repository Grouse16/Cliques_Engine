//����������������������������������������������//
// �ڍ�   �F�e�N�X�`��UV�p�̃f�[�^��`�p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE
#define D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE


// �� �l�[���X�y�[�X �� //

// �e�N�X�`��UV�p�̃f�[�^�̒�`���Ăяo�����߂̖��O
namespace DATA::TEXTURE_UV
{
	// �� �N���X �� //

	// ���_���W�̃N���X
	class C_Textuer_UV
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float u = 0.0f;	// U���W
		float v = 0.0f;	// V���W


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Textuer_UV(void) { return; }
		
		// �t�u���W���Z�b�g����R���X�g���N�^
		C_Textuer_UV(float in_u, float in_v) 
		{
			u = in_u;
			v = in_v;

			return;
		}

		// �f�X�g���N�^
		~C_Textuer_UV(void) { return; }


		//-��- �ݒ� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �FUV���W���Z�b�g����
		// ����   �Ffloat �Z�b�g����U, float �Z�b�g����V
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Set_UV(float in_u, float in_v)
		{
			u = in_u;
			v = in_v;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE

