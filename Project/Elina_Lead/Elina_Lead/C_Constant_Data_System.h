//����������������������������������������������//
// �ڍ�   �F�萔�o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�萔�f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>
#include <memory>
#include <string>

#include "E_Shader_Kind.h"
#include "C_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Creat_Constant_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �萔�o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
	class C_Constant_Buffer_Data_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// 256�o�C�g�̒�`�p�̌^
		struct S_256_Byte_Type
		{
			std::byte data[256]{};	// �f�[�^�A256�o�C�g������
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr <RENDERING::GRAPHICS::INSTANCE::C_Constant_Buffer_Setting_Inform_Base> constant_buffer_inform;	// �萔�f�[�^�p�̃o�b�t�@

			std::vector<S_256_Byte_Type> constant_data;	// �萔�f�[�^

			std::string data_signature_name = "";	// �f�[�^���ʖ��A�p�C�v���C�����V�X�e���Ɠ������ʖ���t�����邱�Ƃ�GPU�ɏ���n����

			ASSET::SHADER::E_SHADER_KIND attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// �e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎��

			int list_sum = 0;	// �z��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Constant_Buffer_Data_System(void);

		// �萔�o�b�t�@�𐶐�����@�����F�o�b�t�@��
		void M_Constant_Buffer_Init(int);

		// �f�X�g���N�^
		~C_Constant_Buffer_Data_System(void);

		// ���������������
		void M_Release(void);


		//-��- �Z�b�^ -��-//

		// �f�[�^�̎��ʖ����Z�b�g����@�����F�Z�b�g���镶����
		void M_Set_Data_Signature_Name(std::string);

		// �e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�ύX����@�����F�ݒ��̃V�F�[�_�[�̎��
		void M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);


		//-��- �Q�b�^ -��-//

		// �f�[�^�̎��ʖ���Ԃ��@�߂�l�F���݂̃f�[�^���ʖ��̎Q��
		const std::string & M_Get_Data_Signature_Name(void);

		// �萔�o�b�t�@�p�̃f�[�^��Ԃ��@�߂�l�F�萔�f�[�^
		std::vector<S_256_Byte_Type> & M_Get_Constant_Data(void);

		// �e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�Ԃ��@�߂�l�F�ݒ��̃V�F�[�_�[�̎��
		ASSET::SHADER::E_SHADER_KIND M_Get_Attach_Shader_Kind(void);


		//-��- �`�� -��-//

		// �萔�o�b�t�@�����݂̃f�[�^�ōX�V����
		void M_Set_Constant_Data_To_Buffer(void);

		// �萔�o�b�t�@��GPU�ɓn��
		void M_Set_Constant_Buffer_To_GPU(void);

		// �萔�o�b�t�@���w�肳�ꂽ�C���f�b�N�X�ɃZ�b�g���AGPU�ɓn���@�����F�ݒ肷��C���f�b�N�X�ԍ��i�萔�o�b�t�@�̃X���b�g�ԍ��j
		void M_Set_Constant_Buffer_To_GPU_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE

