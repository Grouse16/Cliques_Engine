//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̃X�e�[�^�X��`�p�̍\����
// ����   �F���݂̎��ԁA�u�����h���ȂǁA�A�j���[�V�����v�Z�ɋ��ʂ��ĕK�v�ȏ���ݒ�
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE
#define D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION
{
	// �� �\���� �� //

	// �A�j���[�V�����̃X�e�[�^�X��`�p�̍\����
	struct S_Animation_Status
	{
		float animation_time = 0.0f;	// �A�j���[�V��������
		float animation_blend = 0.0f;	// �A�j���[�V�����u�����h��
	};
}


#endif // !D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE

