//����������������������������������������������//
// �ڍ�   �F�s�N�Z���V�F�[�_�[�̏o�͒l�̓��͏������`����f�[�^
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE


// �� �l�[���X�y�[�X �� //

// �u�����h��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::BLEND
{
	// �� �� �� //

	// �s�N�Z���V�F�[�_�[�ƃ����_�����O�摜�̐F�̍��������w�肷���
	enum class E_BLEND_OPTION
	{
		e_ADD,		// �s�N�Z���V�F�[�_�[�̐F�����Z
		e_SUB,		// �s�N�Z���V�F�[�_�[�̐F�����Z
		e_SUB_PIX,	// �s�N�Z���V�F�[�_�[�̐F�����݂̐F�Ō��Z
		e_MAX,		// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ő�l
		e_MIN,		// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ŏ��l
	};
}


#endif // !D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE

