//����������������������������������������������//
// �ڍ�   �F�����_�����O�ݒ�̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE


// �� �l�[���X�y�[�X �� //

// �����_�����O�ݒ��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::SETTING
{
	// �� �� �� //

	// �����_�����O�摜�ɏ������ރs�N�Z���̃f�[�^�`���̗�
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// �P�o�C�g��UINT
		e_BYTE_2_UINT,	// �Q�o�C�g��UINT
		e_BYTE_3_UINT,	// �R�o�C�g��UINT
		e_BYTE_4_UINT,	// �S�o�C�g��UINT

		e_BYTE_2_FLOAT,	// �Q�o�C�g��FLOAT
		e_BYTE_4_FLOAT,	// �S�o�C�g��FLOAT
	};

	// �����_�����O�摜�ɏ������ސF�̎�ސ��̗�
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// �Ԃ̂�
		e_RG,	// �ԂƗ�
		e_RGB,	// �ԂƗ΂Ɛ�
		e_RGBA,	// �ԂƗ΂Ɛƃ��l
	};


	// �� �\���� �� //

	// �T���v�����O�̐ݒ���s�����߂̏��̍\����
	struct S_Sampling_Setting_Inform
	{
		int sampling_count = 1;		// �T���v�����O�̉�
		int sampling_quality = 1;	// �T���v�����O�̕i��

		bool flg_conservative = true;	// �ێ�I�ȃT���v�����O�̃t���O�Atrue�ŗL���Afalse�Ŗ���
	};
}


#endif // !D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE



