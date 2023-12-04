//����������������������������������������������//
// �ڍ�   �F�P�o�C�g�̃J���[�̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE
#define D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE


// �� �l�[���X�y�[�X �� //

// �e�N�X�`���p�̒�`���Ăяo�����߂̖��O
namespace DATA::COLOR
{
	// �� �\���� �� //

	// �P�o�C�g�̃J���[�̍\����
	class C_1_Byte_Color
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		unsigned char m_r = 0;	// ��
		unsigned char m_g = 0;	// ��
		unsigned char m_b = 0;	// ��
		unsigned char m_a = 0;	// �����x


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_1_Byte_Color(void);

		// �O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_1_Byte_Color(float, float, float, float);

		// �O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_1_Byte_Color(int, int, int, int);

		// �f�X�g���N�^
		~C_1_Byte_Color(void);


		//-��- �Z�b�^ -��-//

		// �O�`�P�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_1(float, float, float, float);

		// �O�`�Q�T�T�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_255(int, int, int, int);


		//-��- �I�y���[�^�[ -��-//

		// �F���m�̊|���Z�@�����F�F��� �߂�l�F�F���̊|���Z����
		C_1_Byte_Color operator*(C_1_Byte_Color);

		// �F��ݒ肷��@�����F�F���
		void operator=(C_1_Byte_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE
