//����������������������������������������������//
// �ڍ�   �F�t�H���g�f�[�^�𐳊m�Ɏg�����߂̃V�X�e��
// ����   �F�t�H���g�̓ǂݍ��݂���`��܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_FONT_DATA_H_FILE
#define D_INCLUDE_GUARD_C_FONT_DATA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <memory>

#include "C_Rendering_Font_Inform_Base.h"
#include "C_Texture_Data_System.h"
#include "S_Rect.h"


// �� �l�[���X�y�[�X �� //

// �t�H���g���Ăяo�����߂̖��O
namespace DATA::FONT
{
	// �� �N���X �� //

	// �t�H���g�𐧌䂷��V�X�e��
	class C_Font_Draw_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Texture_Data_System texture_data;	// �摜�f�[�^�Ǘ��p�V�X�e��

			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Font_Inform_Base> font_data;	// �t�H���g�̃f�[�^�Ǘ��p�V�X�e��

			std::wstring now_draw_text = L"\0";	// �`�悷��e�L�X�g

			int font_size = 60;	// �t�H���g�̑傫��

			int span_size = 0;	// �����Ԋu

			bool flg_save_map = true;	// ���I�ɑ���ł���e�N�X�`���}�b�v�������ǂ���

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- �`�� -��-//

		// ���݂̃e�L�X�g�ɉ����ĉ摜�𐶐�����
		void M_Creat_Texture_On_Now_Text(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Font_Draw_System(void);

		// �f�X�g���N�^
		~C_Font_Draw_System(void);
		
		// �t�H���g�f�[�^������������
		void M_Reset(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X�ɂ���t�H���g���擾����


		// �w�肳�ꂽ���O�̃t�H���g���擾����(PC�ɑ��݂��Ă��鎞�̂ݓ���)�@�����F�t�H���g��, �t�H���g�̃s�N�Z���T�C�Y�@�߂�l�F�������̂�true
		bool M_Load_Font_By_Font_Name(std::wstring, int);


		//-��- �Z�b�^ -��-//

		// �t�H���g�T�C�Y��ݒ肷��@�����F�t�H���g�T�C�Y
		void M_Set_Font_Size(int);

		// �����Ԋu��ݒ肷��@�����F�ݒ肷�镶���Ԋu
		void M_Set_Span(int);


		//-��- �Q�b�^ -��-//

		// �e�N�X�`���f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F�e�N�X�`���[�f�[�^�̎Q��
		RENDERING::CAPSULE::C_Texture_Data_System & M_Get_Texture_Data(void);


		//-��- �`�� -��-//

		// �e�L�X�g����摜�𐶐�����@�����F�ݒ肷��e�L�X�g
		void M_Creat_Graph_By_Text(const std::wstring);

		// �ݒ肳�ꂽ�e�L�X�g�ɂ��摜��������x��������
		void M_Recreate_Graph(void);

		// �C���f�b�N�X�w��p�̎��ʖ����Z�b�g����@�����F�ݒ肷�鎯�ʖ�
		void M_Set_Signature_Name(const std::string);

		// �K������V�F�[�_�[�̎�ނ�ݒ肷��@�����F�ݒ肷����
		void M_Set_Attach_Shader_Kind(const ASSET::SHADER::E_SHADER_KIND);

		// ���̃e�N�X�`���̃f�[�^��GPU�֑���
		void M_Attach_To_Shader(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_FONT_DATA_H_FILE



