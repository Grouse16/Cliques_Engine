//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���f�[�^�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�e�N�X�`���f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM
#define D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>

#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "E_Shader_Kind.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// �e�N�X�`���f�[�^���~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
	class C_Texture_Data_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base > texture_setting_inform;	// �e�N�X�`���ݒ�p�̏��

			ASSET::TEXTURE::C_Texture_Map texture_map;	// �e�N�X�`���p�̃}�b�v

			std::string data_signature_name = "";	// �f�[�^���ʖ��A�p�C�v���C�����V�X�e���Ɠ������ʖ���t�����邱�Ƃ�GPU�ɏ���n����

			bool flg_loaded = false;	// �e�N�X�`�������[�h�ς݂��ǂ���������, true�Ń��[�h�ς�

			ASSET::SHADER::E_SHADER_KIND attach_shader = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// �K�p��V�F�[�_�[

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Texture_Data_System(void);

		// �f�X�g���N�^
		~C_Texture_Data_System(void);

		// �������̉�����s��
		void M_Delete(void);

		// �e�N�X�`���}�b�v�̂݉������i�o�b�t�@�͎c��j
		void M_Delete_Map(void);


		//-��- ���Z�b�g -��-//

		// �e�N�X�`���������̏�Ԃɂ���(�s���N�F�̉摜)
		void M_Reset_Texture(void);


		//-��- ���� -��-//

		// �e�N�X�`���f�[�^�𐶐�����@�����F�e�N�X�`���̉��T�C�Y, �e�N�X�`���̏c�T�C�Y
		void M_Create_Texture_Data(int, int);

		// �e�N�X�`���}�b�v�ɍ��킹�āA�e�N�X�`���̃��\�[�X�𐶐�����
		void M_Create_Texture_Resource_By_Texture_Map(void);

		// �e�N�X�`�������[�h�����f�[�^�����ɐ�������@�����F�e�N�X�`���̃p�X�@�߂�l�F�������̂�true
		bool M_Create_Texture_By_Load_Texture_File(std::string);


		//-��- �Z�b�^ -��-//

		// �f�[�^�̎��ʖ����Z�b�g����@�����F�Z�b�g���镶����
		void M_Set_Data_Signature_Name(std::string);

		// �e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�ύX����
		void M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);


		//-��- �Q�b�^ -��-//

		// �f�[�^�̎��ʖ���Ԃ��@�߂�l�F���ʗp�̕�����
		const std::string & M_Get_Data_Signature_Name(void);

		// �e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�Ԃ�
		ASSET::SHADER::E_SHADER_KIND M_Get_Attach_Shader_Kind(void);

		// �e�N�X�`���}�b�v�̎Q�Ƃ�Ԃ��@�߂�l�F�e�N�X�`���}�b�v�̎Q��
		ASSET::TEXTURE::C_Texture_Map & M_Get_Texture_Map(void);

		
		//-��- �`�� -��-//

		// �e�N�X�`���}�b�v�̃f�[�^���e�N�X�`���Ƃ��ăZ�b�g����
		void M_Texture_Map_To_Texture_Resource_Data(void);

		// �e�N�X�`������GPU�ɓn��
		void M_Attach_To_Shader(void);

		// �e�N�X�`�������w�肳�ꂽ�C���f�b�N�X�ɐݒ肵�AGPU�ɓn���@�����F�C���f�b�N�X�ԍ�
		void M_Attach_To_Shader_By_Index(int);
	};
}


#endif // !D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM
