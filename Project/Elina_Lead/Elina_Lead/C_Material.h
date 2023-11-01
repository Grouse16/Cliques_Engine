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

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_System.h"
#include "C_Constant_Data_System.h"


// �� �l�[���X�y�[�X �� //

// �}�e���A�����Ăяo�����߂̖��O
namespace ASSET::MATERIAL
{
	// �� �N���X �� //
	
	// �}�e���A���̃N���X�A�`�掞�̕`����@�̐ݒ���s��
	class C_Material
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// �萔�o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
		struct S_Constant_Buffer_Data
		{
			RENDERING::CAPSULE::C_Constant_Buffer_Data_System data;	// �萔�o�b�t�@���Ǘ�����V�X�e��

			int index = 0;	// �萔�o�b�t�@�̃C���f�b�N�X�ԍ�
		};


		// �e�N�X�`���o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
		struct S_Texture_Buffer_Data
		{
			RENDERING::CAPSULE::C_Texture_Data_System * data = nullptr;	// �e�N�X�`���o�b�t�@���Ǘ�����V�X�e��

			int index = 0;	// �萔�o�b�t�@�̃C���f�b�N�X�ԍ�
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// �`��p�ݒ�

			SHADER::C_Shader_Setting shader_setting_data;	// �V�F�[�_�[�ݒ�p���

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// �g�p����萔�o�b�t�@�̃��X�g
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// �g�p����e�N�X�`���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


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
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

