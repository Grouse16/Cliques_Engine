//����������������������������������������������//
// �ڍ�   �F�}�e���A���̃N���X�A�`�掞�̕`����@�̐ݒ���s��
// ����   �F�o�b�t�@�̊Ǘ��⃌���_�����O�ݒ�̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <vector>
#include <memory>

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_User.h"
#include "C_Constant_Data_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Shader_Setting.h"


// �� �l�[���X�y�[�X �� //

// �}�e���A�����Ăяo�����߂̖��O
namespace ASSET::MATERIAL
{
	// �� �\���� �� //

	// �萔�o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Constant_Buffer_Data
	{
		std::unique_ptr<RENDERING::CAPSULE::C_Constant_Buffer_Data_System> data;	// �萔�o�b�t�@���Ǘ�����V�X�e��

		std::string signature_name = "default";	// �萔�o�b�t�@���ʗp��

		int index = 0;	// �萔�o�b�t�@�̃C���f�b�N�X�ԍ�
	};


	// �e�N�X�`���o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Texture_Buffer_Data
	{
		ASSET::TEXTURE::C_Texture_Data_User data;	// �e�N�X�`�����g�p���邽�߂̃V�X�e��

		std::string signature_name = "default";	// �e�N�X�`���X���b�g���ʗp��

		int index = 0;	// �e�N�X�`���̃C���f�b�N�X�ԍ�
	};


	// �� �N���X �� //
	
	// �}�e���A���̃N���X�A�`�掞�̕`����@�̐ݒ���s��
	class C_Material
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// �`��p�ݒ�

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// �g�p����萔�o�b�t�@�̃��X�g
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// �g�p����e�N�X�`���̃��X�g

			ASSET::SHADER::C_Shader_Setting shader_setting_data;	// �V�F�[�_�[�ݒ�p���

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		
		// �� �֐� �� //

		//-��- ���[�h -��-//

		// �u�����h�̐ݒ���}�e���A����񂩂烍�[�h����@�����F�u�����h�̐ݒ��, �ǂݍ��񂾃t�@�C���̏��
		void M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> &, SYSTEM::TEXT::C_Text_And_File_Manager &);


		//-��- ���� -��-//

		// �X���b�g�̏����Z�b�g����@�����F�ݒ肷��X���b�g���ʗp�̏��
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & );

		// �����_�����O���𐶐�����@�����F���݂̃t�@�C��������@�߂�l�F�������̂�true
		bool M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager &);

		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Material(void);

		// �f�X�g���N�^
		~C_Material(void);

		// ��������������ď���������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �}�e���A���f�[�^�ւ̃p�X����}�e���A���������[�h�@�����F�}�e���A���f�[�^�ւ̃p�X�@�߂�l�F�������̂�true
		bool M_Load_Material_By_Path(std::string);


		//-��- �`�� -��-//

		// �����_�����O�p�̏���GPU�ɐݒ肷��
		void M_Attach_To_GPU(void);


		//-��- �Z�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�萔�o�b�t�@�Ƀf�[�^���Z�b�g����
		// ����   �Fint �ݒ��̒萔�o�b�t�@�̔ԍ�, int �萔�o�b�t�@�̔z��ԍ�, const C_Constant_Data_Class & �萔�o�b�t�@�ɃZ�b�g����f�[�^
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<class C_Constant_Data_Class>
		void M_Set_Constant_Data_To_Buffer_By_Index(int in_index, int in_buffer_index, const C_Constant_Data_Class & in_set_data)
		{
			// �z��O���w�肳�ꂽ�甲����
			if (mpr_variable.constant_data_list.size() <= in_index)
			{
				return;
			}


			// �� �ϐ��錾 �� //
			int constant_data_size = sizeof(C_Constant_Data_Class);	// �萔�f�[�^�̃o�C�g��


			// �f�[�^���Z�b�g����
			mpr_variable.constant_data_list[in_index].data.M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void * >(&in_set_data));

			return;
		}

		// �w�肳�ꂽ�X���b�g�Ƀe�N�X�`�������[�h����@�����F�e�N�X�`���X���b�g�ԍ�, ���[�h����e�N�X�`����
		void M_Load_Texture_For_Slot_By_Index(int, std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�萔�o�b�t�@�Ǘ��p�f�[�^��Ԃ��@�����F�擾����萔�o�b�t�@�Ǘ��p�f�[�^�̔ԍ�
		const S_Constant_Buffer_Data & M_Get_Constant_Buffer_Data_By_Index(int);

		// �w�肳�ꂽ�e�N�X�`���Ǘ��p�f�[�^��Ԃ��@�����F�擾����e�N�X�`���Ǘ��p�f�[�^�̔ԍ�
		const S_Texture_Buffer_Data & M_Get_Texture_Data_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

