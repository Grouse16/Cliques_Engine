//����������������������������������������������//
// �ڍ�   �F�u�����h�ݒ�̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE


// �� �l�[���X�y�[�X �� //

// �u�����h��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::BLEND
{
	// �u�����h���[�h���`�����
	enum class E_BLEND_MODE
	{
		e_NORMAL,			// �ʏ�`��
		e_NORMAL_NOT_ALPHA,	// ���l���g�p�����ɕ`��
		
		e_INVERT,			// ���Z�����ŕ`��
		e_INVERT_NOT_ALPHA,	// ���l���g�p�����Ɍ��Z�����ŕ`��
	};

	// �s�N�Z���V�F�[�_�[�ƃ����_�����O�摜�̐F�̍��������w�肷���
	enum class E_BLEND_OPTION
	{
		e_ADD,		// �s�N�Z���V�F�[�_�[�̐F�����Z
		e_SUB,		// �s�N�Z���V�F�[�_�[�̐F�����Z
		e_SUB_PIX,	// �s�N�Z���V�F�[�_�[�̐F�����݂̐F�Ō��Z
		e_MAX,		// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ő�l
		e_MIN,		// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ŏ��l
	};

	// �����_�����O�摜�ɏ������ރs�N�Z���̃f�[�^�`���̗�
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// �P�o�C�g��UINT
		e_BYTE_2_UINT,	// �Q�o�C�g��UINT
		e_BYTE_4_UINT,	// �S�o�C�g��UINT

		e_BYTE_2_FLOAT,	// �Q�o�C�g��FLOAT
		e_BYTE_4_FLOAT,	// �S�o�C�g��FLOAT
	};

	// �����_�����O�摜�ɏ������ސF�̎�ސ��̗�
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// �Ԃ̂�
		e_RG,	// �ԂƗ�
		e_RGBA,	// �ԂƗ΂Ɛƃ��l
	};

}


#endif // !D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE

