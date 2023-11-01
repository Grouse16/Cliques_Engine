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


#include "C_Shader_Manager.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "E_Shader_Kind.h"
#include "Input_Layout_Data.h"
#include "C_Text_And_File_Manager.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �\���� �� //

	// �V�F�[�_�[�R�[�h�̎�ޕʃ��X�g�̍\����
	struct S_Shader_Byte_Code_List
	{
		C_Shader_Code * list[(int)E_SHADER_KIND::e_ALL];	// �V�F�[�_�[�R�[�h�̃��X�g�@VS,HS,DS,GS,PS������
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

			S_Shader_Byte_Code_List shader_code;	// �V�F�[�_�[�̃R�[�h���܂Ƃ߂��\����

			S_All_Shader_Resource_Signatures resource_signature;	// ���\�[�X���ʗp���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- ���[�h -��-//

		// ���_���C�A�E�g�����[�h����@�����F�V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// �S�ẴV�F�[�_�[�ɋ��ʂ��郊�\�[�X�̒�`���s���@�����F�V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_All_Shader_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// �e��V�F�[�_�[�̃��[�h�ƃ��\�[�X�̒�`���s���@�����F�V�F�[�_�[���t�@�C���̃f�[�^�@�߂�l�F�������̂�true
		bool M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// ���ޕ��̃V�F�[�_�[���[�h���s�������@�����F�V�F�[�_�[���t�@�C���̃f�[�^, �V�F�[�_�[������t�H���_, �V�F�[�_�[�̎�ށ@�߂�l�F�������̂�true
		bool M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & , int );


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

		// �V�F�[�_�[���t�@�C���̓��e��ǂݎ���Ċe��V�F�[�_�[�����[�h���A���_���C�A�E�g�ƃ��\�[�X�̒�`��ݒ肷��@�����F�V�F�[�_�[���t�@�C���̃p�X�@�߂�l�F�������̂�true
		bool M_Load_Shaders_Inform_By_Shader_Setting_Name(std::string);


		//-��- �Q�b�^ -��-//

		// �V�F�[�_�[�̃R�[�h�̃Z�b�g��Ԃ��@�߂�l�F�V�F�[�_�[�̃R�[�h�̎�ޕʃ��X�g�̎Q��(const)
		const S_Shader_Byte_Code_List & M_Get_Shader_Code_List(void) const;

		// ���\�[�X���ʗp����Ԃ��@�߂�l�F���\�[�X���ʗp���̎Q��(const)
		const S_All_Shader_Resource_Signatures & M_Get_Resource_Signature(void) const;

		// ���_���̓��C�A�E�g�̃��X�g��Ԃ��@�߂�l�F���̓��C�A�E�g�ւ̎Q��(const)
		const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & M_Get_Input_Layout(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
