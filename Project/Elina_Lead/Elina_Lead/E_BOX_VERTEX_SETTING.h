//����������������������������������������������//
// �ڍ�   �F�l�p�`�̒��_�ݒ�p�̔z��ԍ�
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE
#define D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE


// �� �l�[���X�y�[�X �� //

// ���_�ݒ�p�̃f�[�^���Ăяo�����߂̖��O
namespace DATA::VERTEX::SETTING
{
	// �� �萔 �� //

	// �l�p�`�̒��_�ݒ�p�̔z��ԍ�
	enum class E_BOX_VERTEX_SETTING
	{
		e_LEFT_TOP,		// ���㒸�_
		e_RIGHT_TOP,	// �E�㒸�_
		e_RIGHT_BOTTOM,	// �E�����_
		e_LEFT_BOTTOM,	// �������_

		e_SUM	// ���_�̑���
	};


	// �C���f�b�N�X�o�b�t�@�̐ݒ�p�ԍ��̗�
	enum class E_BOX_INDEX_SETTING
	{
		e_INDEX_1 = (int)E_BOX_VERTEX_SETTING::e_LEFT_TOP,		// �O�p�`�P�̍��㒸�_
		e_INDEX_2 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_TOP,	// �O�p�`�P�̉E�㒸�_
		e_INDEX_3 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM,	// �O�p�`�P�̉E�����_

		e_INDEX_4 = (int)E_BOX_VERTEX_SETTING::e_LEFT_TOP,		// �O�p�`�Q�̍��㒸�_
		e_INDEX_5 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM,	// �O�p�`�Q�̉E�����_
		e_INDEX_6 = (int)E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM,	// �O�p�`�Q�̍������_

		e_SUM,	// �C���f�b�N�X�̑���
	};
}

#endif // !D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE
