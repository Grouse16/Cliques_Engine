//����������������������������������������������//
// �ڍ�   �F�X�N���[����ʂ̃e�N�X�`���̐ݒ�
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE
#define D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::API::CREATE
{
	// �� �� �� //

	// �X�N���[����ʂ̃e�N�X�`���̐ݒ���s�����߂̗�
	enum class E_SCREEN_TEXTURE_SETTING : char
	{
		e_BUFFER,		// �o�b�t�@�̐ݒ�
		e_TEXTURE_1D,	// 1�����e�N�X�`���̐ݒ�
		e_TEXTURE_2D,	// 2�����e�N�X�`���̐ݒ�
		e_TEXTURE_3D,	// 3�����e�N�X�`���̐ݒ�
	};
}


#endif // !D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE


