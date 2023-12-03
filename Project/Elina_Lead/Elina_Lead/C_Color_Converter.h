//����������������������������������������������//
// �ڍ�   �F�O��ނ̐F���Ԃ̕ϊ����s���N���X
// ����   �F�O��ނ̐F�Ƃ́AC_Color C_Half_Color C_1_Byte_Color�̂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
#define D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Color.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"


// �� �l�[���X�y�[�X �� //

// �F�̒�`���Ăяo�����߂̖��O
namespace DATA::COLOR
{
	// �� �N���X �� //

	// �O��ނ̐F���Ԃ̕ϊ����s���N���X
	class C_Color_Converter
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^�A���̉��h�~�̂��߂ɍ폜����
		C_Color_Converter(void) = delete;


		//-��- 4�o�C�g�F�ւ̕ϊ� -��-//

		// 1�o�C�g�F����4�o�C�g�F�ւ̕ϊ��@�����F1�o�C�g�F�̎Q�Ɓ@�߂�l�F4�o�C�g�F
		static C_Color M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color &);

		// �Q�o�C�g�F����4�o�C�g�F�ւ̕ϊ��@�����F�Q�o�C�g�F�̎Q�Ɓ@�߂�l�F4�o�C�g�F
		static C_Color M_Convert_Half_Color_To_Color(const C_Half_Color &);


		//-��- 2�o�C�g�F�ւ̕ϊ� -��-//

		// 1�o�C�g�F����2�o�C�g�F�ւ̕ϊ��@�����F1�o�C�g�F�̎Q�Ɓ@�߂�l�F2�o�C�g�F
		static C_Half_Color M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color &);

		// 4�o�C�g�F����2�o�C�g�F�ւ̕ϊ��@�����F4�o�C�g�F�̎Q�Ɓ@�߂�l�F2�o�C�g�F
		static C_Half_Color M_Convert_Color_To_Half_Color(const C_Color &);


		//-��- 1�o�C�g�F�ւ̕ϊ� -��-//

		// 2�o�C�g�F����1�o�C�g�F�ւ̕ϊ��@�����F2�o�C�g�F�̎Q�Ɓ@�߂�l�F1�o�C�g�F
		static C_1_Byte_Color M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color &);

		// 4�o�C�g�F����1�o�C�g�F�ւ̕ϊ��@�����F4�o�C�g�F�̎Q�Ɓ@�߂�l�F1�o�C�g�F
		static C_1_Byte_Color M_Convert_Color_To_1_Byte_Color(const C_Color &);
	};
}


#endif // !D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
