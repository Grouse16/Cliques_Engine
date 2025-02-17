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
		float animation_blend_percent = 0.0f;	// �A�j���[�V�����u�����h��
		float need_blend_time = 0.1f;	// �A�j���[�V�����u�����h�����܂ł̎���
		float animation_speed = 1.0f;	// �A�j���[�V�������x
		float passed_time = 0.0f;		// �o�ߎ���

		const int bone_sum = 0;	// �{�[����

		bool flg_animation_end = false;		// �A�j���[�V�����̏I��
		bool flg_animation_reverse = false;	// �A�j���[�V�������t�Đ����邩�ǂ���


		// �� �֐� �� //

		//-��- ������ -��-//

		// �ʏ�̃R���X�g���N�^�𖳌���
		S_Animation_Status(void) = delete;

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�{�[�����������p�̃R���X�g���N�^
		// ����   �Fint �{�[����
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		S_Animation_Status(int in_bone_sum) : bone_sum(in_bone_sum)
		{
			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE

