//����������������������������������������������//
// �ڍ�   �F�F��`�p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_COLOR_DATA_H_FILE
#define D_INCLUDE_GUARD_COLOR_DATA_H_FILE


// �� �l�[���X�y�[�X �� //

// �F�̒�`���Ăяo�����߂̖��O
namespace DATA::COLOR
{
	// �� �N���X �� //

	// �F�̃N���X
	class C_Color
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float r = 0.0f;	// ��
		float g = 0.0f;	// ��
		float b = 0.0f;	// ��
		float a = 0.0f;	// �����x


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Color(void) { return; }

		// �O�`�P�F��ݒ肷�鎞�̃R���X�g���N�^
		C_Color(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}

		// �O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^
		C_Color(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		// �f�X�g���N�^
		~C_Color(void) { return; }


		//-��- �ݒ� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�O�`�P�ŐF�̐ݒ���s��
		// ����   �Ffloat ��, float ��, float ��, float �����x
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F// �O�`�Q�T�T�ŐF�̐ݒ���s��
		// ����   �Fint ��, int ��, int ��, int �����x
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		//-��- �I�y���[�^�[ -��-//

		// �F���m�̊|���Z
		C_Color operator*(C_Color& in_color)
		{
			// �� �ϐ��錾 �� //
			C_Color result;	// �v�Z����


			// �F����������
			result.r = in_color.r * r;
			result.g = in_color.g * g;
			result.b = in_color.b * b;
			result.a = in_color.a * a;

			return result;
		}

		// �F��ݒ肷��
		void operator=(C_Color& in_color)
		{
			// �F����������
			r = in_color.r;
			g = in_color.g;
			b = in_color.b;
			a = in_color.a;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_COLOR_DATA_H_FILE

