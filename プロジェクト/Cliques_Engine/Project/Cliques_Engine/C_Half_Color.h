//����������������������������������������������//
// �ڍ�   �F�Q�o�C�g�̐F���`����\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE
#define D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <directxpackedvector.h>

#include "C_Color.h"


// �� �l�[���X�y�[�X �� //

// �F�̒�`���Ăяo�����߂̖��O
namespace DATA::COLOR
{
	// �� �N���X �� //

	// �Q�o�C�g�̐F���`����\����
	class C_Half_Color
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		DirectX::PackedVector::HALF m_r = 0;		// �Q�o�C�g�̐�
		DirectX::PackedVector::HALF m_g = 0;		// �Q�o�C�g�̗�
		DirectX::PackedVector::HALF m_b = 0;		// �Q�o�C�g�̐�
		DirectX::PackedVector::HALF m_a = 0;		// �Q�o�C�g�̃�


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Half_Color(void);

		// �O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_Half_Color(float, float, float, float);

		// �O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^�@�����F��, ��, ��, �����x
		C_Half_Color(int, int, int, int);

		// �f�X�g���N�^
		~C_Half_Color(void);


		//-��- �Z�b�^ -��-//

		// �O�`�P�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_1(float, float, float, float);

		// �O�`�Q�T�T�ŐF�̐ݒ���s���@�����F��, ��, ��, �����x
		void M_Set_Color_By_0_255(int, int, int, int);


		//-��- �I�y���[�^�[ -��-//

		// �F���m�̊|���Z�@�����F�F���@�߂�l�F�F���̊|���Z����
		C_Half_Color operator*(C_Half_Color);

		// �F��ݒ肷��@�����F�F���
		void operator=(C_Half_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE

