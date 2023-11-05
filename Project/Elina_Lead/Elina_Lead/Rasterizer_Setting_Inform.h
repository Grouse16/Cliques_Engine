//����������������������������������������������//
// �ڍ�   �F���X�^���C�U�ݒ�̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::RASTERIZER
{
	// �� �� �� //

	// �\�����[�h�̗�
	enum class E_DRAW_MODE : unsigned char
	{
		e_NORMAL,		// �ʏ�\��
		e_WIRE_FRAME,	// �ӂ̂ݕ\��
	};

	// �ʂ̃J�����O�̕`���̗�
	enum class E_MESH_CULLING : unsigned char
	{
		e_ALWAYS,	// ��ɕ`��
		e_FRONT,	// �\�ʂ̂ݕ`��
		e_BACK,		// ���ʂ̂ݕ`��
	};

	// �\�ʂ̊�̗�
	enum class E_MESH_FRONT : unsigned char
	{
		e_ANTI_CLOCK_WISE,	// �����v���̖ʂ��\��
		e_CLOCK_WISE,		// ���v���̖ʂ��\��
	};

	// �A���`�G�C���A�V���O�̕��@�̗�
	enum class E_ANTIALIASING : unsigned char
	{
		e_DONT,		// ����
		e_ALPHA,	// �A���t�@�l�ōs��
		e_PIXEL,	// �l�ӌ`�ŐF�𕪎U���čs��
		e_LINE,		// �ӂɃA���`�G�C���A�V���O��������
	};


	// �� �\���� �� //

	// ���s���̒l�̐ݒ���s�����߂̍\����
	struct S_Depth_Setting_Value
	{
		int depth_value = 0;		// ���s���l
		float depth_max = 0.0f;		// ���s���̍ő�l�@0.0f�ŉ��s������
		float depth_slope = 0.0f;	// ���s�������l
	};
}


#endif // !D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE

