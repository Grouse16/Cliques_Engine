//����������������������������������������������//
// �ڍ�   �F�e�X�N�`���̃Z�b�g�p�̃f�[�^�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE
#define D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <memory>
#include <vector>

#include "E_Shader_Kind.h"
#include "C_Texture_Map.h"
#include "C_Half_Color.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::API::INSTANCE
{
	// �� �N���X �� //

	// �e�X�N�`���̃Z�b�g�p�̃f�[�^�̊��N���X
	class C_Rendering_Texture_Setting_Inform_Base
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Texture_Setting_Inform_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Texture_Setting_Inform_Base(void);


		//-��- �X�V -��-//

		// �e�N�X�`���̃f�[�^���Z�b�g����@�����F�ݒ肷��F�z��ւ̎Q��, �e�N�X�`���̉���, �e�N�X�`���̏c��
		virtual void M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> & , int, int) = 0;
	};


	// �萔�o�b�t�@��`�悷��Ƃ��̏��Z�b�g
	struct S_Texture_Buffer_Drawing_Setting
	{
		C_Rendering_Texture_Setting_Inform_Base * add_texture_data = nullptr;	// �e�N�X�`���f�[�^�p���̃A�h���X

		std::string * add_signature_name = nullptr;	// ���ʖ��̃A�h���X

		ASSET::SHADER::E_SHADER_KIND attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎�ނ̃A�h���X
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE
