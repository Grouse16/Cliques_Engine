//����������������������������������������������//
// �ڍ�   �F�T�[�h�p�[�e�B�̃����_�����O�ɂ��O���t�B�b�N�𐧌䂷��V�X�e���̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"
#include "C_Rendering_Screen_Data_Base.h"
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include "S_Create_Vertex_Buffer_Inform.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "S_Create_Constant_Buffer_Inform.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Create_Render_Screen_Inform.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"

#include "C_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�̊��N���X���Ăяo�����߂̖��O
namespace RENDERING::API::BASE
{
	// �� �N���X �� //
	
	// �����_�����OAPI�̊��N���X
	class C_Rendering_API_Base
	{
	//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		static std::unique_ptr<C_Rendering_API_Base> m_this;	// �N���X�̃C���X�^���X�p�A�h���X�A��Ƀ|�����[�t�B�Y�����Ɏg�p


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �����_�����OAPI�̏�����
		virtual bool M_Set_Up(void) = 0;

		// �����_�����OAPI�̃��������
		virtual void M_Release(void) = 0;

		// �����_�����OAPI�̍폜
		static void M_Delete_API(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_API_Base(void);


		//-��- �����_�����O -��-//

		// �����_�����O�J�n���̏���
		virtual void M_Rendering_Start(void) = 0;

		// �����_�����O�I���ƕ`��o�b�t�@�̐؂�ւ�����
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-��- �����_�����O�ݒ� -��-//

		// �����_�����O�ݒ�̐�������@�����F�ݒ��̃����_�����O�ݒ�, �����_�����O�ݒ�̐����p�̏��(const)
		virtual bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform&) const = 0;

		// �����_�����O�ݒ�̃Z�b�g����@�����F�Z�b�g���郌���_�����O�ݒ�(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&) = 0;


		//-��- �����_�����O��� -��-//

		// �����_�����O��ʂ̐�������@�����F�ݒ��̃����_�����O��ʂ̎Q��, �����_�����O��ʂ𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		virtual bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> &, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & ) const = 0;

		// �����_�����O��ʂ̃N���A����@�����F�N���A���郌���_�����O��ʔԍ�, �N���A���郌���_�����O��ʃV�X�e���̎Q��
		virtual void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) const = 0;

		// �����_�����O��ʂ�`���Ƃ��ăZ�b�g����@�����F�ݒ��̃����_�����O��ʂ̎Q��
		virtual void M_Set_Rendering_Screen_To_Render_Target(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// �����_�����O��ʂ��w�肳�ꂽ�e�N�X�`�����\�[�X�X���b�g�ɃZ�b�g����@�����F�����_�����O��ʔԍ�, �ݒ��̃e�N�X�`���̃X���b�g�ԍ�, �����_�����O��ʃV�X�e���̎Q��
		virtual void M_Set_Rendering_Screen_To_Texture_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// �����_�����O��ʂ̃f�[�^��ǂݎ��\�ɂ���@�����F�ݒ肷�郌���_�����O��ʔԍ�, �����_�����O��ʃV�X�e���̎Q��
		virtual void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// ���C���̃����_�����O��ʂ�`���ɂ���
		virtual void M_Set_Main_Rendering_Screen_To_Rendering(void) = 0;

		// ���C���̕\�����̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����@�����F�ݒ��̃e�N�X�`���̃X���b�g�ԍ�
		virtual void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int) = 0;

		// ���C���̕`�揑�����ݒ��̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����@�����F�ݒ��̃e�N�X�`���̃X���b�g�ԍ�
		virtual void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int) = 0;

		// ���C���̃����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ��@�����F�ݒ��̃e�N�X�`���̎Q��
		virtual void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// �w�肳�ꂽ�����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ��@�����F�ݒ肷�郌���_�����O��ʔԍ�, �����_�����O��ʃV�X�e���̎Q��, �ݒ��̃e�N�X�`���̎Q��
		virtual void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// �����_�����O��ʂ̍폜��ʒm����@�����F�폜���ꂽ�����_�����O��ʂ̃A�h���X�iconst�j
		virtual void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * ) = 0;


		//-��- �[�x�X�e���V���o�b�t�@ -��-//

		// �[�x�X�e���V���o�b�t�@�𐶐�����@�����F������̐[�x�X�e���V���o�b�t�@�̎Q��, �[�x�X�e���V���o�b�t�@�𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		virtual bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) const = 0;

		// �[�x�X�e���V���o�b�t�@���N���A����@�����F�N���A����[�x�X�e���V���o�b�t�@�̎Q��
		virtual void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) const = 0;

		// �[�x�X�e���V���o�b�t�@��`��p�ɃZ�b�g����@�����F�ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
		virtual void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// �[�x�X�e���V���o�b�t�@��GPU�p���\�[�X�̃e�N�X�`���X���b�g�ɃZ�b�g�@�����F�ݒ��̃X���b�g�ԍ�, �ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
		virtual void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// �[�x�X�e���V���o�b�t�@�̍폜��ʒm����@�����F�폜���ꂽ�[�x�X�e���V���o�b�t�@�̃A�h���X�iconst�j
		virtual void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * ) = 0;

		// �[�x�X�e���V���o�b�t�@�����Z�b�g����
		virtual void M_Reset_Depth_Stencil_Buffer(void) = 0;


		//-��- ���_�o�b�t�@ -��-//

		// ���_�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒��_���, �����p�̏��(const)
		virtual void M_Create_Vertex_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & ) const = 0;

		// ���_�o�b�t�@���Z�b�g����@�����F���_�f�[�^�ݒ�p���(const)
		virtual void M_Set_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// ���_�o�b�t�@�����ɕ`������s����@�����F�`�悷�钸�_�f�[�^(const)
		virtual void M_Draw_Command_By_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;


		//-��- �C���f�b�N�X�o�b�t�@ -��-//

		// �C���f�b�N�X�f�[�^�p�̏��𐶐�����@�����F�ݒ��̃C���f�b�N�X���, �����p�̏��(const)
		virtual void M_Create_Index_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & ) const = 0;

		// �C���f�b�N�X�o�b�t�@�����ɕ`����s���@�����F�C���f�b�N�X�f�[�^�ݒ�p���(const)
		virtual void M_Draw_Command_By_Index_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & ) = 0;

		// �C���f�b�N�X�o�b�t�@�����Ɏw�肳�ꂽ�C���f�b�N�X�Ԃ̕`����s���@�����F�C���f�b�N�X�f�[�^�ݒ�p���(const), �`����J�n����C���f�b�N�X�ԍ�, �`��I���̃C���f�b�N�X�ԍ�
		virtual void M_Draw_Command_By_Index_Buffer_By_Range(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int) = 0;


		//-��- �萔�o�b�t�@ -��-//

		// �萔�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒萔���, �����p�̏��(const)
		virtual void M_Create_Constant_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & ) const = 0;

		// �萔�f�[�^���Z�b�g����@�����F�萔�f�[�^�ݒ�p���(const)
		virtual void M_Rendering_Set_Constant_Buffer(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// �w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�ɒ萔�f�[�^���Z�b�g����@�����F�萔�f�[�^�ݒ�p���, �Z�b�g��̃C���f�b�N�X�ԍ�
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int) = 0;


		//-��- �e�N�X�`�� -��-//

		// �e�N�X�`���p�̏��𐶐�����@�����F�e�N�X�`���p���, �����p�̏��(const)�@�߂�l�F�������̂�true
		virtual bool M_Create_Texture_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & ) const = 0;

		// �e�N�X�`���̃f�[�^���Z�b�g����@�����F�Z�b�g����e�N�X�`���f�[�^���(const)
		virtual void M_Rendering_Set_Texture(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// �w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�Ƀe�N�X�`���̃f�[�^���Z�b�g����@�����F�Z�b�g����e�N�X�`���f�[�^���(const), �Z�b�g��̃C���f�b�N�X�ԍ�
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;


		//-��- �t�H���g -��-//

		// �t�H���g���w�肳�ꂽ�t�H���g�������Ƀ��[�h����@�����F�ݒ��̃t�H���g���p�����[�^, �����p�̏��(const)�@�߂�l�F�������̂�true
		virtual bool M_Create_Font_Data(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> &, const RENDERING::API::CREATE::S_Create_Font_Data_Inform & ) const = 0;

		// �n���ꂽ�������ɕ�������}�b�v�ɃZ�b�g����@�����F�t�H���g����摜����邽�߂̃p�b�P�[�W���@�߂�l�F�������̂�true
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) const = 0;


		//-��- �Q�b�^ -��-//

		// ���̃N���X�̎��̂̃A�h���X��Ԃ��@�߂�l�F���N���X�̃C���X�^���X�ւ̃A�h���X
		static C_Rendering_API_Base * M_Get_Instance(void);

		// ���̃����_�����O�V�X�e���̃V�F�[�_�[�̃t�H���_�܂ł̃p�X��Ԃ��@�߂�l�F�V�F�[�_�[�̃t�H���_�܂ł̃p�X
		virtual std::string M_Get_Shader_Folder_Path(void) const = 0;

		// ���̃����_�����O�V�X�e���̃V�F�[�_�[�̊g���q��Ԃ��@�߂�l�F�V�F�[�_�[�̊g���q
		virtual std::string M_Get_Shader_Extension(void) const = 0;

		// �����_�����O�V�X�e�����I�����Ă��邩�ǂ����̃t���O��Ԃ��@�߂�l�F�����_�����O�V�X�e�����I�����Ă��邩�ǂ����̃t���O
		virtual bool M_Get_End_Rendering_System(void) const = 0;


		//-��- �Z�b�^ -��-//

		// ��ʂ��N���A����F��ݒ肷��@�����F�ݒ肷��F(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-��- ���[�h -��-//

		// �e�N�X�`�������[�h����@�����F�e�N�X�`���t�@�C���̃p�X, �e�N�X�`���}�b�v�̎Q��
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) const = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

