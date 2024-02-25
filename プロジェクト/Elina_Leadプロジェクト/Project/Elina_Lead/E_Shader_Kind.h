//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̎�ޒ�`�p�t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE
#define D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�p�̃f�[�^���Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �萔 �� //

	// �V�F�[�_�[�̎�ނ��w�肷�邽�߂̗�
	enum class E_SHADER_KIND : char
	{
		e_VERTEX,			// ���_
		e_HULL_TCS,			// �n���A�e�b�Z���[�V��������
		e_DOMAIN_TES,		// �h���C���A�e�b�Z���[�V�����]��
		e_GEOMETRY,			// �W�I���g��
		e_PIXEL_FRAGMENT,	// �s�N�Z���A�t���O�����g

		e_ALL,	// �S�Ă��w�肷��A�V�F�[�_�[��ސ��Ɠ����l
	};
}


#endif // !D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE

