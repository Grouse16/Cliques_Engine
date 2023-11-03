//����������������������������������������������//
// �ڍ�   �F�T�[�h�p�[�e�B�̓��̃O���t�B�b�N�𐧌䂷��V�X�e���̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE
#define D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"

#include "C_Creat_Vertex_Buffer_Inform.h"
#include "C_Creat_Constant_Buffer_Inform.h"
#include "C_Creat_Rendering_Graphics_Setting_Inform.h"
#include "C_Creat_Texture_Setting_Inform.h"
#include "C_Creat_Font_Data_Inform.h"

#include "Color_Data.h"
#include "S_Tex_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̊����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS
{
	// �� �N���X �� //
	
	// �T�[�h�p�[�e�B�̓��̃O���t�B�b�N�𐧌䂷��V�X�e���̊��N���X
	class C_Rendering_Graphics_API_Base
	{
	//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		static std::unique_ptr<C_Rendering_Graphics_API_Base> m_this;	// �N���X�̃C���X�^���X�p�A�h���X�A��Ƀ|�����[�t�B�Y�����Ɏg�p


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// ���������Ďg�p�\�ɂ���
		virtual bool M_Set_Up(void) = 0;

		// ���������
		virtual void M_Release(void) = 0;

		// �����_�����O�p��API���I������
		static void M_Delete_API(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Graphics_API_Base(void);


		//-��- �����_�����O -��-//

		// �����_�����O���J�n����
		virtual void M_Rendering_Start(void) = 0;

		// ���̕`����s���J�n����@�����F�����_�����O�p�C�v���C���p���(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & ) = 0;

		// �萔�f�[�^���Z�b�g����@�����F�萔�f�[�^�ݒ�p���(const)
		virtual void M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// �w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�ɒ萔�f�[�^���Z�b�g����@�����F�萔�f�[�^�ݒ�p���, �Z�b�g��̃C���f�b�N�X�ԍ�
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & , int) = 0;

		// �e�N�X�`���̃f�[�^���Z�b�g����@�����F�Z�b�g����e�N�X�`���f�[�^���(const)
		virtual void M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// �w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�Ƀe�N�X�`���̃f�[�^���Z�b�g����@�����F�Z�b�g����e�N�X�`���f�[�^���(const), �Z�b�g��̃C���f�b�N�X�ԍ�
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;

		// ���̕`������s����@�����F���_�f�[�^�ݒ�p���(const)
		virtual void M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// �`�悷��C���f�b�N�X�ԍ����w�肵�������ō��̕`������s����@�����F���_�f�[�^�ݒ�p���(const), �`�悷��C���f�b�N�X�̕`��̊J�n�ԍ�,�`�悷��C���f�b�N�X�̏I���ԍ�
		virtual void M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & , int, int) = 0;

		// �����_�����O���I�����āA��ʂ�\��
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-��- ���� -��-//

		// ���_�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒��_���, �����p�̏��(const)
		virtual void M_Creat_Vertex_Inform(std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> &, const CREAT::C_Creat_Vertex_Buffer_Inform & ) = 0;

		// �萔�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒萔���, �����p�̏��(const)
		virtual void M_Creat_Constant_Inform(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> &, const CREAT::C_Creat_Constant_Buffer_Inform &) = 0;

		// �e�N�X�`���p�̏��𐶐�����@�����F�e�N�X�`���p���, �����p�̏��(const)�@�߂�l�F�������̂�true
		virtual bool M_Creat_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const CREAT::C_Creat_Texture_Setting_Inform&) = 0;

		// �`��p�C�v���C���p�̏��𐶐�����@�����F�ݒ��̃p�C�v���C�����, �����p�̏��(const)
		virtual bool M_Creat_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> &, const CREAT::C_Creat_Rendering_Graphics_Setting_Inform &) = 0;

		// �t�H���g���w�肳�ꂽ�t�H���g�������Ƀ��[�h����@�����F�ݒ��̃t�H���g���p�����[�^, �����p�̏��(const)�@�߂�l�F�������̂�true
		virtual bool M_Creat_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> &, const CREAT::C_Creat_Font_Data_Inform &) = 0;

		// �n���ꂽ�������ɕ�������}�b�v�ɃZ�b�g����@�����F�t�H���g����摜����邽�߂̃p�b�P�[�W���@�߂�l�F�������̂�true
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) = 0;


		//-��- �Q�b�^ -��-//

		// ���̃N���X�̎��̂̃A�h���X��Ԃ�
		static C_Rendering_Graphics_API_Base * M_Get_Instance(void);


		//-��- �Z�b�^ -��-//

		// ��ʂ��N���A����F��ݒ肷��@�����F�ݒ肷��F(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-��- ���[�h -��-//

		// �e�N�X�`�������[�h����@�����F�e�N�X�`���t�@�C���̃p�X, �e�N�X�`���}�b�v�̎Q��
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
