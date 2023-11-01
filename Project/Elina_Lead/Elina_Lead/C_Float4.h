//����������������������������������������������//
// �ڍ�   �F�t���[�g�l�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
#define D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE


// �� �l�[���X�y�[�X �� //

// ���w�n�����Ăяo�����߂̖��O
namespace MATH
{
	// �� �N���X �� //

	// �t���[�g�l�����Ǘ�����N���X
	class C_Float4
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		float x = 0.0f;	// �v�f�P
		float y = 0.0f;	// �v�f�Q
		float z = 0.0f;	// �v�f�R
		float w = 0.0f;	// �v�f�S


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Float4(void);

		// xyzw�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l, y�ɃZ�b�g����l, z�ɃZ�b�g����l, w�ɃZ�b�g����l
		C_Float4(float, float, float, float);

		// xyz�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l, y�ɃZ�b�g����l, z�ɃZ�b�g����l
		C_Float4(float, float, float);

		// xy�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l, y�ɃZ�b�g����l
		C_Float4(float, float);

		// x�����ɃZ�b�g����R���X�g���N�^�@�����Fx�ɃZ�b�g����l
		C_Float4(float);

		// �f�X�g���N�^
		~C_Float4(void);


		//-��- �I�y���[�^ -��-//

		// Float4�Ƃ̃C�R�[�����Z(�Q�ƌ^)�@�����G�������t���[�g4�l
		void operator= (C_Float4 & );

		// Float4�Ƃ̃C�R�[�����Z�@�����F�������t���[�g4�l
		void operator= (C_Float4);

		// Float4�Ƃ́{���Z(�Q�ƌ^)�@�����F���Z����t���[�g4�l
		C_Float4 operator+ (C_Float4 & );

		// Float4�Ƃ́{���Z�@�����F���Z����t���[�g4�l
		C_Float4 operator+ (C_Float4);

		// float�Ƃ́{���Z�i�S�Ă̕ϐ������Z�j�@�����F���Z����t���[�g�l
		C_Float4 operator+ (float &);
	};
}


#endif // !D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
