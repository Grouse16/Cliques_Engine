//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�X�N���[���i�����_�����O��摜�j�̃V�X�e��
// ����   �F�����_�[�^�[�Q�b�g�r���[�Ɛ[�x�X�e���V���r���[���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE
#define D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�p�̃��\�[�X�̒�`���Ăяo�����߂̖��O
namespace ASSET::SHADER::RESOURCE
{
	// �� �\���� �� //

	// ����o�b�t�@�̃X���b�g�̔ԍ����܂Ƃ߂����X�g�̍\����
	struct S_Unique_Buffer_Slot
	{
		int wvp = -1;	// ���[���h �r���[ �v���W�F�N�V����
		int bone = -1;	// �{�[���}�g���N�X

		int material = -1;	// �����f�[�^

		int ambient_light = -1;		// �A���r�G���g���C�g
		int directional_light = -1;	// �f�B���N�V���i�����C�g
		int point_light = -1;		// �|�C���g���C�g
		int spot_light = -1;		// �X�|�b�g���C�g
		int area_light = -1;		// �G���A���C�g
	};
}


#endif // !D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE

