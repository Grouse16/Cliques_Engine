//����������������������������������������������//
// �ڍ�   �F�t���[�g�R�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_FLOAT_3_H_FILE
#define D_INCLUDE_GUARD_C_FLOAT_3_H_FILE


// �� �l�[���X�y�[�X �� //

// ���w�n���̌^���Ăяo�����߂̖��O
namespace MATH::FORMAT
{
	// �� �N���X �� //

	// �t���[�g�R�����Ǘ�����N���X
	class C_Float_3
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Float_3(void);

		// xyz�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l, y�ɃZ�b�g����l, z�ɃZ�b�g����l
		C_Float_3(float, float, float);

		// �f�X�g���N�^
		~C_Float_3(void);


		//-��- �I�y���[�^ -��-//

		// C_Float_3�Ƃ�=���Z�@�����F�������t���[�g3�l�@�߂�l�F������ʂ̃t���[�g3�l
		C_Float_3 operator= (C_Float_3);

		// C_Float_3�Ƃ́{���Z�@�����F���Z����t���[�g3�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator+ (C_Float_3);

		// C_Float_3�Ƃ�-���Z�@�����F���Z����t���[�g3�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator- (C_Float_3);

		// C_Float_3�Ƃ́~���Z�@�����F��Z����t���[�g3�l�@�߂�l�F��Z���ʂ̃t���[�g3�l
		C_Float_3 operator* (C_Float_3);

		// C_Float_3�Ƃ�/���Z�@�����F���Z����t���[�g3�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator/ (C_Float_3);

		// C_Float_3�Ƃ�%���Z�@�����F��]�Z����t���[�g3�l�@�߂�l�F��]�Z���ʂ̃t���[�g3�l
		C_Float_3 operator% (C_Float_3);

		// C_Float_3�Ƃ́{=���Z�@�����F���Z�������t���[�g3�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator+= (C_Float_3);

		// C_Float_3�Ƃ�-=���Z�@�����F���Z�������t���[�g3�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator-= (C_Float_3);

		// C_Float_3�Ƃ́~=���Z�@�����F��Z�������t���[�g3�l�@�߂�l�F��Z������ʂ̃t���[�g3�l
		C_Float_3 operator*= (C_Float_3);

		// C_Float_3�Ƃ�/=���Z�@�����F���Z�������t���[�g3�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator/= (C_Float_3);

		// C_Float_3�Ƃ�%=���Z�@�����F��]�Z�������t���[�g3�l�@�߂�l�F��]�Z������ʂ̃t���[�g3�l
		C_Float_3 operator%= (C_Float_3);

		// float�Ƃ�=���Z�@�����F�������t���[�g�l�@�߂�l�F������ʂ̃t���[�g3�l
		C_Float_3 operator= (float);

		// float�Ƃ́{���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator+ (float);

		// float�Ƃ�-���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator- (float);

		// float�Ƃ́~���Z�@�����F��Z����t���[�g�l�@�߂�l�F��Z���ʂ̃t���[�g3�l
		C_Float_3 operator* (float);

		// float�Ƃ�/���Z�@�����F���Z����t���[�g�l�@�߂�l�F���Z���ʂ̃t���[�g3�l
		C_Float_3 operator/ (float);

		// float�Ƃ�%���Z�@�����F��]�Z����t���[�g�l�@�߂�l�F��]�Z���ʂ̃t���[�g3�l
		C_Float_3 operator% (float);

		// float�Ƃ́{=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator+= (float);

		// float�Ƃ�-=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator-= (float);

		// float�Ƃ́~=���Z�@�����F��Z�������t���[�g�l�@�߂�l�F��Z������ʂ̃t���[�g3�l
		C_Float_3 operator*= (float);

		// float�Ƃ�/=���Z�@�����F���Z�������t���[�g�l�@�߂�l�F���Z������ʂ̃t���[�g3�l
		C_Float_3 operator/= (float);

		// float�Ƃ�%=���Z�@�����F��]�Z�������t���[�g�l�@�߂�l�F��]�Z������ʂ̃t���[�g3�l
		C_Float_3 operator%= (float);
	};
}


#endif // !D_INCLUDE_GUARD_C_FLOAT_3_H_FILE

