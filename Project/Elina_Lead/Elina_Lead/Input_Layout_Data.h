//����������������������������������������������//
// �ڍ�   �F���_�o�b�t�@�̓��̓��C�A�E�g���`���邽�߂̃f�[�^
// ����   �FGLSL�Q�l���� https://www.khronos.org/opengl/wiki/OpenGL_Type
// ����   �FHLSL�Q�l���� https://learn.microsoft.com/en-us/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
#define D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE


// �� �l�[���X�y�[�X �� //

// ���̓��C�A�E�g�ݒ�p�̃f�[�^���Ăяo�����߂̖��O
namespace DATA::INPUTLAYOUT
{
	// �� �萔 �� //

	// �T�|�[�g����f�[�^�̃r�b�g�T�C�Y
	enum class E_INPUT_DATA_BITSIZE
	{
		e_1BYTE_8BIT,		// 8�r�b�g�A1�o�C�g���@�����I��Int�`���ɂȂ�̂�FLOAT�̃Z�b�g�͂��Ȃ��悤�ɂ��邱��
		e_2BYTE_16BIT,	// 16�r�b�g�A2�o�C�g��
		e_4BYTE_32BIT,	// 32�r�b�g�A4�o�C�g��

		// 64��GLSL�݂̂ɂȂ�̂ŃT�|�[�g���Ȃ�
	};

	// �f�[�^�^
	enum class E_INPUT_DATA_FORMAT
	{
		e_INT,		// INT�^
		e_UINT,		// UINT�^
		e_FLOAT,	// FLOAT�^ ���� half
	};

	// �ϐ��̐��@�ifloat4 �� int3�ȂǁAxyzw�̎w��j
	enum class E_INPUT_DATA_PARAMATOR_SUM
	{
		e_1 = 1,	// �P��
		e_2 = 2,	// �Q��
		e_3 = 3,	// �R��
		e_4 = 4,	// �S��
	};


	// �� �\���� �� //

	// �����p�̏��
	struct S_INPUT_LAYOUT_SETTING
	{
		E_INPUT_DATA_BITSIZE size;	// �ϐ�����̃r�b�g�T�C�Y�ivec.x�Ȃǂ̃T�C�Y�j

		E_INPUT_DATA_FORMAT format;	// �`���i�f�[�^�^�j
		
		E_INPUT_DATA_PARAMATOR_SUM sum;	// �ϐ��̐��@�ifloat4 �� int3�ȂǁAxyzw�̎w��j
	};
}


#endif // !D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
