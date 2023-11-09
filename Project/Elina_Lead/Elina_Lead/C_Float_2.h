//����������������������������������������������//
// �ڍ�   �F�t���[�g�Q�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_FLOAT_2_H_FILE
#define D_INCLUDE_GUARD_C_FLOAT_2_H_FILE


// �� �l�[���X�y�[�X �� //

// ���w�n���̌^���Ăяo�����߂̖��O
namespace MATH::FORMAT
{
	// �� �N���X �� //

	// �t���[�g�Q�����Ǘ�����N���X
	class C_Float_2
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float x = 0.0f;
		float y = 0.0f;


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Float_2(void);

		// xy�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l, y�ɃZ�b�g����l
		C_Float_2(float, float);

		// �f�X�g���N�^
		~C_Float_2(void);


		//-��- �I�y���[�^ -��-//

		// C_Float_2�Ƃ�=���Z�@�����F�������t���[�g2�l�@�߂�l�F������ʂ̃t���[�g2�l
		C_Float_2 operator= (C_Float_2);

		// C_Float_2�Ƃ́{���Z�@�����F���Z����t���[�g2�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator+ (C_Float_2);

		// C_Float_2�Ƃ�-���Z�@�����F���Z����t���[�g2�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator- (C_Float_2);

		// C_Float_2�Ƃ́~���Z�@�����F��Z����t���[�g2�l�@�߂�l�F��Z���ʂ̃t���[�g2�l
		C_Float_2 operator* (C_Float_2);

		// C_Float_2�Ƃ�/���Z�@�����F���Z����t���[�g2�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator/ (C_Float_2);

		// C_Float_2�Ƃ�%���Z�@�����F��]�Z����t���[�g2�l�@�߂�l�F��]�Z���ʂ̃t���[�g2�l
		C_Float_2 operator% (C_Float_2);

		// C_Float_2�Ƃ́{=���Z�@�����F���Z�������t���[�g2�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator+= (C_Float_2);

		// C_Float_2�Ƃ�-=���Z�@�����F���Z�������t���[�g2�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator-= (C_Float_2);

		// C_Float_2�Ƃ́~=���Z�@�����F��Z�������t���[�g2�l�@�߂�l�F��Z������ʂ̃t���[�g2�l
		C_Float_2 operator*= (C_Float_2);

		// C_Float_2�Ƃ�/=���Z�@�����F���Z�������t���[�g2�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator/= (C_Float_2);

		// C_Float_2�Ƃ�%=���Z�@�����F��]�Z�������t���[�g2�l�@�߂�l�F��]�Z������ʂ̃t���[�g2�l
		C_Float_2 operator%= (C_Float_2);

		// float�Ƃ�=���Z�@�����F�������t���[�g�l�@�߂�l�F������ʂ̃t���[�g2�l
		C_Float_2 operator= (float);

		// float�Ƃ́{���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator+ (float);

		// float�Ƃ�-���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator- (float);

		// float�Ƃ́~���Z�@�����F��Z����t���[�g�l�@�߂�l�F��Z���ʂ̃t���[�g2�l
		C_Float_2 operator* (float);

		// float�Ƃ�/���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g2�l
		C_Float_2 operator/ (float);

		// float�Ƃ�%���Z�@�����F��]�Z����t���[�g�l�@�߂�l�F��]�Z���ʂ̃t���[�g2�l
		C_Float_2 operator% (float);

		// float�Ƃ́{=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator+= (float);

		// float�Ƃ�-=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator-= (float);

		// float�Ƃ́~=���Z�@�����F��Z�������t���[�g�l�@�߂�l�F��Z������ʂ̃t���[�g2�l
		C_Float_2 operator*= (float);

		// float�Ƃ�/=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g2�l
		C_Float_2 operator/= (float);

		// float�Ƃ�%=���Z�@�����F��]�Z�������t���[�g�l�@�߂�l�F��]�Z������ʂ̃t���[�g2�l
		C_Float_2 operator%= (float);
	};
}


#endif // !D_INCLUDE_GUARD_C_FLOAT_2_H_FILE

