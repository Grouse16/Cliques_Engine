//����������������������������������������������//
// �ڍ�   �F�`��p�C�v���C���p���𐶐����邽�߂̏��̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::CREAT
{
	// �� �萔 �� //

	// �u�����h���[�h���w�肷�邽�߂̗�
	enum class E_BLEND_MODE
	{
		e_ALPHA_SRC,
	};


	// �� �N���X �� //

	// �`��p�C�v���C���p���𐶐����邽�߂̏��̃N���X
	class C_Creat_Rendering_Graphics_Setting_Inform
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		ASSET::SHADER::C_Shader_Setting * shader_setting;	// �V�F�[�_�[�ݒ���
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM
