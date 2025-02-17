//����������������������������������������������//
// �ڍ�   �F���s���̒l�̐ݒ���s�����߂̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE
#define D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::RASTERIZER
{
	// �� �\���� �� //

	// ���s���̒l�̐ݒ���s�����߂̍\����
	struct S_Depth_Setting_Value
	{
		int depth_bias = 0;		// ���s���l

		float depth_max = 0.0f;		// ���s���̍ő�l�@0.0f�ŉ��s������
		float depth_slope = 0.0f;	// ���s�������l
	};
}


#endif // !D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE

