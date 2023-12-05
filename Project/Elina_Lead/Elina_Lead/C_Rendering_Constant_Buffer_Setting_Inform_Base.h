//����������������������������������������������//
// �ڍ�   �F�萔�o�b�t�@�̃Z�b�g�p�̃f�[�^�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>

#include "E_Shader_Kind.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::INSTANCE
{
	// �� �N���X �� //

	// �萔�o�b�t�@����p�f�[�^�̊��N���X
	class C_Rendering_Constant_Buffer_Setting_Inform_Base
	{
	//==�� �p�u���b�N ��==//
	public:

		//-��- �֐� -��-//

		//-��- �I���� -��-//

		// �R���X�g���N�^
		C_Rendering_Constant_Buffer_Setting_Inform_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Constant_Buffer_Setting_Inform_Base(void);


		//-��- �Z�b�^ -��-//

		// �萔�o�b�t�@�Ɏw�肳�ꂽ�����Z�b�g����@�����F�Z�b�g����f�[�^, �z��, �Z�b�g����f�[�^�T�C�Y
		virtual void M_Set_Data_To_Buffer(void*, int, int) = 0;


		//-��- �Q�b�^ -��-//

		// �萔�o�b�t�@�̃f�[�^�̃A�h���X��Ԃ��@���g�p���I�������K��Close���邱�Ɓ@�߂�l�F�萔�o�b�t�@�̃f�[�^�̃A�h���X
		virtual unsigned char * M_Get_Constant_Buffer_Data_Address(void) = 0;

		// �萔�o�b�t�@�̃f�[�^���g�p�I������
		virtual void M_Close_Constant_Buffer_Data_Address(void) = 0;
	};


	// �萔�o�b�t�@��`�悷��Ƃ��̏��Z�b�g
	struct S_Constant_Buffer_Drawing_Setting
	{
		C_Rendering_Constant_Buffer_Setting_Inform_Base * add_constant_buffer = nullptr;	// �萔�o�b�t�@�p���̃A�h���X

		std::string * add_signature_name = nullptr;	// ���ʖ��̃A�h���X

		ASSET::SHADER::E_SHADER_KIND * add_attach_shader_kind = nullptr;	// �ݒ��̃V�F�[�_�[�̎�ނ̃A�h���X
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
