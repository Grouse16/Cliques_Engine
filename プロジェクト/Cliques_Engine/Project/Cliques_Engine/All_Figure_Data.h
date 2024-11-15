//����������������������������������������������//
// �ڍ�   �F�}�`��`�p�̃t�@�C��
// ����   �F������}�`���`����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE
#define D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "2D_Position_Data.h"
#include "Figure_Base_Data.h"


// �� �l�[���X�y�[�X �� //

// 2D�p�̐}�`�̒�`���Ăяo�����߂̖��O
namespace DATA::FIGURE::_2D
{
	// 2D�̉~�̊��ƂȂ�N���X
	class C_2D_Circle : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct S_Variable
		{
			DATA::POSITION_2D::C_2D_Position vertex_center;	// ���S�_

			float radius = 0.0f;	// ���a

		} m_variable;	// �ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_2D_Circle(void) { return; }

		// �f�X�g���N�^
		~C_2D_Circle(void) { return; }
	};


	// 2D�̒����`�̊��ƂȂ�N���X
	class C_2D_Long_Box : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct S_Variable
		{
			DATA::POSITION_2D::C_2D_Position vertex_left_top;	// ���㒸�_
			DATA::POSITION_2D::C_2D_Position vertex_right_bottom;	// �E�����_

		} m_variable;	// �ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_2D_Long_Box(void) { return; }

		// �f�X�g���N�^
		~C_2D_Long_Box(void) { return; }
	};
}

#endif // !D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE

