//����������������������������������������������//
// �ڍ�   �F�t�H���g�f�[�^�𐶐����邽�߂̏��
// ����   �F�����`����݂̂Ȃ̂Ŏ��ۂ̐����͂��̏��������_�����OAPI�ɓn�����Ƃōs��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREATE_FONT_DATA_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_FONT_DATA_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�Ɏg�p����V�X�e���𐶐����邽�߂̏��
namespace RENDERING::GRAPHICS::CREATE
{
	// �� �\���� �� //

	// �t�H���g�f�[�^�𐶐����邽�߂̏��̍\����
	struct S_Create_Font_Data_Inform
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		std::wstring m_font_name = L"\0";	// �t�H���g��

		int m_height = 0;	// �g�p�\�ȃt�H���g�̏c�T�C�Y
		int m_width = 0;	// �t�H���g�̑���
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_FONT_DATA_INFORM_H_FILE
