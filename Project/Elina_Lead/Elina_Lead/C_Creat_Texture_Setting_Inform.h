//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���p���𐶐����邽�߂̏��̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::CREAT
{
	// �� �萔 �� //

	// �e�N�X�`���̃f�[�^�`���w��p�̗�
	enum class E_TEXTURE_DATA_FORMAT
	{
		e_8BIT_MULTI_4,	// �W�r�b�g�S��
		e_8BIT_MULTI_2,	// �W�r�b�g�Q��
		e_8BIT_MULTI_1,	// �W�r�b�g�P��
	};


	// �� �N���X �� //

	// �e�N�X�`���p���𐶐����邽�߂̏��̃N���X
	class C_Creat_Texture_Setting_Inform
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		int pixel_width = 0;		// �����̃s�N�Z����
		int pixel_height = 0;		// �c���̃s�N�Z����
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE
