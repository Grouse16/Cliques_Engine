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
#include "C_Create_Constant_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �萔 �� //
	constexpr int con_CONSTANT_DATA_SIZE = 256;	// �萔�f�[�^�̃o�C�g�T�C�Y


	// �� �N���X �� //

	// �萔�o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
	class C_Constant_Buffer_Data_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// 256�o�C�g�̒�`�p�̌^
		struct S_256_Byte_Type
		{
			std::byte data[con_CONSTANT_DATA_SIZE]{};	// �f�[�^�A256�o�C�g������
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

		// �f�X�g���N�^
		~C_Constant_Buffer_Data_System(void);

		// ���������������
		void M_Release(void);


		//-��- ���� -��-//

		// �萔�o�b�t�@�ƃf�[�^�𐶐�����@�����F�o�b�t�@��
		void M_Create_Constant_Buffer_And_Data(int);

		// �萔�o�b�t�@�݂̂𐶐�����@�����F�o�b�t�@��
		void M_Create_Only_Constant_Buffer(int);


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

		// �萔�o�b�t�@�̃f�[�^�̃A�h���X���擾���ĕԂ��@���K��Close�Ŏg�p���I�����邱�Ɓ@�߂�l�F�萔�o�b�t�@�̃f�[�^�̃A�h���X
		unsigned char * M_Get_Constant_Buffer_Data(void);


		//-��- �`�� -��-//

		// �萔�o�b�t�@�����݂̃f�[�^�ōX�V����
		void M_Set_Constant_Data_To_Buffer(void);

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�萔�f�[�^���㏑������A�������ɒ萔�f�[�^�𐶐����Ă��邱��
		// ����   �Fint �z��, int �ݒ��̔z��ԍ�, const C_Set_Class * �㏑������f�[�^
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template <class C_Set_Class>
		void M_Set_Constant_Data(int in_list_num, int in_index, const C_Set_Class * in_data)
		{
			// �� �ϐ��錾 �� //
			int set_data_size = sizeof(C_Set_Class);	// �Z�b�g����f�[�^�̃T�C�Y


			// �T�C�Y���傫�����邩�A�z��̊O���w�肵�Ă���Ȃ甲����
			if (set_data_size > con_CONSTANT_DATA_SIZE || in_index >= mpr_variable.list_sum)
			{
				return;
			}


			// �萔�f�[�^������������
			for (int l_now_slot = 0; l_now_slot < in_list_num && l_now_slot < mpr_variable.list_sum; l_now_slot++)
			{
				memcpy_s(mpr_variable.constant_data[in_index + l_now_slot].data, con_CONSTANT_DATA_SIZE, in_data[l_now_slot], set_data_size);
			}


			return;
		}

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�萔�o�b�t�@���㏑������
		// ����   �Fint �z��, int �ݒ��̔z��ԍ�, const C_Set_Class * �㏑������f�[�^
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template <class C_Set_Class>
		void M_Set_Constant_Buffer_Data(int in_list_num, int in_index, const C_Set_Class * in_data)
		{
			// �� �ϐ��錾 �� //
			int set_data_size = sizeof(C_Set_Class);	// �Z�b�g����f�[�^�̃T�C�Y


			// �T�C�Y���傫�����邩�A�z��̊O���w�肵�Ă���Ȃ甲����
			if (set_data_size > con_CONSTANT_DATA_SIZE  || in_index >= mpr_variable.list_sum)
			{
				return;
			}


			// �萔�o�b�t�@�̃f�[�^���擾����
			S_256_Byte_Type * buffer_data = mpr_variable.constant_buffer_inform->M_Get_Constant_Buffer_Data_Address();


			// �萔�o�b�t�@�̃f�[�^�����Ă��Ȃ��Ȃ甲����
			if (buffer_data == nullptr)
			{
				// �萔�o�b�t�@�̃f�[�^�̎g�p���I������
				mpr_variable.constant_buffer_inform->M_Close_Constant_Buffer_Data_Address();

				return;
			}

			// �萔�f�[�^������������
			for (int l_now_slot = 0; l_now_slot < in_list_num && l_now_slot < mpr_variable.list_sum; l_now_slot++)
			{
				memcpy_s(buffer_data[in_index + l_now_slot].data, con_CONSTANT_DATA_SIZE, in_data[l_now_slot], set_data_size);
			}

			// �萔�o�b�t�@�̃f�[�^�̎g�p���I������
			mpr_variable.constant_buffer_inform->M_Close_Constant_Buffer_Data_Address();

			return;
		}
		
		// �萔�o�b�t�@��GPU�ɓn��
		void M_Set_Constant_Buffer_To_GPU(void);

		// �萔�o�b�t�@���w�肳�ꂽ�C���f�b�N�X�ɃZ�b�g���AGPU�ɓn���@�����F�ݒ肷��C���f�b�N�X�ԍ��i�萔�o�b�t�@�̃X���b�g�ԍ��j
		void M_Set_Constant_Buffer_To_GPU_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE

