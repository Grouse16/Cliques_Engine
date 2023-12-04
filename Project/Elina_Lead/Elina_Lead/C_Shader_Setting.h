//����������������������������������������������//
// �ڍ�   �F��g�̃V�F�[�_�[�̐ݒ���܂Ƃ߂邽�߂̃N���X
// ����   �F�V�F�[�_�[���o���o���ɐݒ肷��K�v���Ȃ����A�J�v�Z����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_SET_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <vector>

#include "C_Shader_User.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "E_Shader_Kind.h"
#include "Input_Layout_Data.h"
#include "C_Text_And_File_Manager.h"
#include "S_Unique_Buffer_Slot.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �\���� �� //

	// �V�F�[�_�[���\�[�X���Ƃ̑��������\����
	struct S_Shader_Resource_Sum
	{
		int constant_buffer_sum = 0;	// �萔�o�b�t�@��
		int texture_buffer_sum = 0;		// �e�N�X�`���o�b�t�@��
		int screen_resource_sum = 0;	// �X�N���[����ʃX���b�g��
	};


	// �� �N���X �� //

	// ��g�̃V�F�[�_�[�̐ݒ���܂Ƃ߂邽�߂̃N���X
	class C_Shader_Setting
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> vertex_layout_setting;	// ���_���C�A�E�g�ݒ�

			std::vector<C_Shader_User> shader_list;	// �V�F�[�_�[�R�[�h�̃��X�g

			S_All_Shader_Resource_Signatures resource_signature;	// ���\�[�X���ʗp���̃��X�g

			ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot unique_buffer_slot_list;	// ����ȃo�b�t�@�X���b�g�̃��X�g

			S_Shader_Resource_Sum shader_resource_sum;	// �V�F�[�_�[���\�[�X�̑���

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- ���[�h -��-//

		// ���_���C�A�E�g�����[�h����@�����F�V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// �S�ẴV�F�[�_�[�ɋ��ʂ��郊�\�[�X�̒�`���s���@�����F�V�F�[�_�[�̎�ޖ�, �V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_Shader_Resource_Signature(std::string, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// �e��V�F�[�_�[�̃��[�h�ƃ��\�[�X�̒�`���s���@�����F�V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// ���ޕ��̃V�F�[�_�[���[�h���s�������@�����F�V�F�[�_�[���t�@�C���̃f�[�^, �V�F�[�_�[������t�H���_, �V�F�[�_�[�̎�ށ@�߂�l�F�������̂�true
		bool M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & , int );

		// �V�F�[�_�[�̃X���b�g���𐮗񂷂�
		void M_Slot_Inform_Alignment(void);

		// ����ȃo�b�t�@�X���b�g��T�����Ĕԍ����L�^����
		void M_Search_And_Save_Index_Of_Unique_Buffer_Slot_Number(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Shader_Setting(void);

		// �f�X�g���N�^
		~C_Shader_Setting(void);

		// ���������������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �V�F�[�_�[���t�@�C���̓��e��ǂݎ���Ċe��V�F�[�_�[�����[�h���A���_���C�A�E�g�ƃ��\�[�X�̒�`��ݒ肷��@�����F�ǂݍ��ރV�F�[�_�[�ݒ�t�@�C���܂ł̑��΃p�X�@�߂�l�F�������̂�true
		bool M_Load_Shaders_Inform_By_Shader_Setting_File_Path(std::string);


		//-��- �Q�b�^ -��-//

		// �V�F�[�_�[�̎g�p�V�X�e���̃Z�b�g��Ԃ��@�߂�l�F�V�F�[�_�[�̎g�p�V�X�e���̎�ޕʃ��X�g�̎Q��(const)
		const std::vector<C_Shader_User> & M_Get_Shader_Code_List(void) const;

		// ���\�[�X���ʗp����Ԃ��@�߂�l�F���\�[�X���ʗp���̎Q��(const)
		const S_All_Shader_Resource_Signatures & M_Get_Resource_Signature(void) const;

		// ���_���̓��C�A�E�g�̃��X�g��Ԃ��@�߂�l�F���̓��C�A�E�g�ւ̎Q��(const)
		const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & M_Get_Input_Layout(void) const;

		// ����ȃV�F�[�_�[�̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F����ȃV�F�[�_�[�̃��X�g�̎Q�Ɓiconst�j
		const ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot & M_Get_Unique_Buffer_Slot(void) const;

		// ���\�[�X���̑����̏��̎Q�Ƃ�Ԃ��@�߂�l�F���\�[�X���̑����̏��̎Q�Ɓiconst�j
		const S_Shader_Resource_Sum & M_Get_Resource_Sum(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
