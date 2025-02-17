//����������������������������������������������//
// �ڍ�   �F�F��`�p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_COLOR_H_FILE
#define D_INCLUDE_GUARD_C_COLOR_H_FILE


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
		float m_r = 0.0f;	// ��
		float m_g = 0.0f;	// ��
		float m_b = 0.0f;	// ��
		float m_a = 0.0f;	// �����x


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Color(void);

		// �O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_Color(float, float, float, float);

		// �O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_Color(int, int, int, int);

		// �f�X�g���N�^
		~C_Color(void);


		//-��- �Z�b�^ -��-//
		
		// �O�`�P�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_1(float, float, float, float);

		// �O�`�Q�T�T�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_255(int, int, int, int);


		//-��- �I�y���[�^�[ -��-//

		// �F���m�̊|���Z�@�����F�F��� �߂�l�F�F���̊|���Z����
		C_Color operator*(C_Color);

		// �F��ݒ肷��@�����F�F���
		void operator=(C_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_COLOR_H_FILE

