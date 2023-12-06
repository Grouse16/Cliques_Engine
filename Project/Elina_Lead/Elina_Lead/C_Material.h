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
#include "C_Rendering_Screen_System_Base.h"
#include "C_Shader_Setting_User.h"
#include "C_Rendering_Screen_System.h"
#include "S_Material_Detail.h"
#include "S_World_View_Projection.h"
#include "C_Depth_Stencil_Buffer_System.h"


// �� �l�[���X�y�[�X �� //

// �}�e���A�����Ăяo�����߂̖��O
namespace ASSET::MATERIAL
{
	// �� �\���� �� //

	// �萔�o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Constant_Buffer_Data
	{
		std::unique_ptr<RENDERING::CAPSULE::C_Constant_Buffer_Data_System> data;	// �萔�o�b�t�@���Ǘ�����V�X�e��

		std::string signature_name = "default";	// �萔�o�b�t�@���ʖ�

		int slot_index = 0;	// �萔�o�b�t�@�̃C���f�b�N�X�ԍ�
	};


	// �e�N�X�`���o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Texture_Buffer_Data
	{
		std::unique_ptr<ASSET::TEXTURE::C_Texture_Data_User> data;	// �e�N�X�`�����g�p���邽�߂̃V�X�e��

		std::string signature_name = "default";	// �e�N�X�`���X���b�g���ʖ�

		int slot_index = 0;	// �e�N�X�`���̃C���f�b�N�X�ԍ�
	};


	// �����_�����O��ʂ��g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Rendering_Screen_Data
	{
		RENDERING::CAPSULE::C_Rendering_Screen_System * data = nullptr;	// �����_�����O��ʂ��Ǘ�����V�X�e���̃A�h���X

		std::string signature_name = "default";	// �����_�����O��ʂ̎��ʖ�

		int use_screen_index = 0;	// �e�N�X�`���Ƃ��Ďg�p���郌���_�����O��ʔԍ�

		int slot_index = 0;	// �����_�����O��ʗp�̃e�N�X�`���X���b�g�̔ԍ�
	};


	// �[�x�X�e���V���o�b�t�@���g�p����ۂ̏����܂Ƃ߂��\����
	struct S_Depth_Stencil_Data
	{
		RENDERING::CAPSULE::C_Depth_Stencil_Buffer_System * data = nullptr;	// �[�x�X�e���V���o�b�t�@���Ǘ�����V�X�e���̃A�h���X

		std::string signature_name = "default";	// �[�x�X�e���V���o�b�t�@�̎��ʖ�

		int slot_index = 0;	// �[�x�X�e���V���o�b�t�@�p�̃e�N�X�`���X���b�g�̔ԍ�
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
			std::vector<S_Constant_Buffer_Data> constant_data_list;	// �g�p����萔�o�b�t�@�̃��X�g
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// �g�p����e�N�X�`���̃��X�g

			std::vector<S_Rendering_Screen_Data> rendering_screen_list;	// �g�p���郌���_�����O�X�N���[���̃��X�g

			std::vector<S_Depth_Stencil_Data> depth_stencil_list;	// �g�p����[�x�X�e���V���̃��X�g

			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// �`��p�ݒ�

			ASSET::SHADER::C_Shader_Setting_User shader_setting_data;	// �V�F�[�_�[�ݒ�p���

			ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot * unique_slot_list = nullptr;	// ����X���b�g�̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		
		// �� �֐� �� //

		//-��- �u�����h�ݒ� -��-//

		// �ǂ̃u�����h���[�h��ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�u�����h���[�h������������@�߂�l�F���肵���u�����h���[�h
		RENDERING::INFORM::BLEND::E_BLEND_MODE M_Get_Blend_Mode_By_Text(std::string);

		// �ǂ̐F�̑����ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�F�̑��������������@�߂�l�F���肵���F�̑���
		RENDERING::INFORM::BLEND::E_BLEND_OPTION M_Get_Blend_Option_By_Text(std::string);

		// �ǂ̏������ތ`����ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�������ރf�[�^�`����������������@�߂�l�F�������ރf�[�^�̌`��
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT M_Get_Blend_Write_Format_By_Text(std::string);

		// �ǂ̏������ސF�̎�ނ�ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�������ސF�̎�ނ�����������@�߂�l�F�������ސF�̎��
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR M_Get_Blend_Write_Color_By_Text(std::string);


		//-��- �[�x�X�e���V�� -��-//

		// �ǂ̐[�x���[�h��ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�[�x���[�h�̎�ނ�����������@�߂�l�F�[�x���[�h�̎��
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE M_Get_Depth_Mode_By_Text(std::string);

		// �ǂ̐[�x�I�v�V������ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�[�x�I�v�V�����̎�ނ�����������@�߂�l�F�[�x�I�v�V�����̎��
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE M_Get_Depth_Option_By_Text(std::string);

		// �ǂ̃X�e���V����L���ɂ��邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�X�e���V���̗L������������������@�߂�l�F�X�e���V���̗L������
		RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS M_Get_Stencil_Is_Active_By_Text(std::string);


		//-��- ���X�^���C�U -��-//

		// �ǂ̕`�惂�[�h��ݒ肷�邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�`�惂�[�h�̎�ނ�����������@�߂�l�F�`�惂�[�h�̎��
		RENDERING::INFORM::RASTERIZER::E_DRAW_MODE M_Get_Draw_Mode_By_Text(std::string);

		// �ǂ̖ʂ�\�����邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�ʕ\���̎�ނ�����������@�߂�l�F�ʂ̕\�����[�h��Ԃ�
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING M_Get_Mesh_Culling_By_Text(std::string);

		// �ǂ̖ʂ̕\�ʂ̐ݒ���g�p���邩���w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�\�ʐݒ�̎�ނ�����������@�߂�l�F�\�ʐݒ��Ԃ�
		RENDERING::INFORM::RASTERIZER::E_MESH_FRONT M_Get_Mesh_Front_By_Text(std::string);

		// �ǂ̃A���`�G�C���A�V���O�̎�ނ��w�肳�ꂽ�����񂩂���肵�ĕԂ��@�����F�A���`�G�C���A�V���O�̎�ނ�����������@�߂�l�F�A���`�G�C���A�V���O�̎�ނ�Ԃ�
		RENDERING::INFORM::RASTERIZER::E_ANTIALIASING M_Get_Antialiasing_By_Text(std::string);


		//-��- ���[�h -��-//

		// �u�����h�̐ݒ���}�e���A����񂩂烍�[�h����@�����F�u�����h�̐ݒ��, �ǂݍ��񂾃t�@�C���̏��
		void M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::S_Blend_Setting_Create_Data> &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// �[�x�X�e���V�����}�e���A����񂩂烍�[�h����@�����F�[�x�X�e���V���̐ݒ��, �ǂݍ��񂾃t�@�C���̏��
		void M_Load_Depth_Stencil_Setting(RENDERING::GRAPHICS::CREATE::S_Depth_Stencil_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// ���X�^���C�U���}�e���A����񂩂烍�[�h����@�����F���X�^���C�U�̐ݒ��, �ǂݍ��񂾃t�@�C���̏��
		void M_Load_Rasterizer_Setting(RENDERING::GRAPHICS::CREATE::S_Rasterizer_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// ���̑��ݒ�����[�h����@�����F�ݒ��̃����_�����O�ݒ萶���p���, �ǂݍ��񂾃t�@�C���̏��
		void M_Load_Another_Setting(RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform &, SYSTEM::TEXT::C_Text_And_File_Manager &);


		//-��- ���� -��-//

		// �X���b�g�̏����Z�b�g����@�����F�ݒ肷��X���b�g���ʗp�̏��
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_Resource_Inform_List & );

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


		//-��- �萔�o�b�t�@ -��-//

		//--�� �Z�b�^ ��--//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�萔�o�b�t�@�Ƀf�[�^���Z�b�g����
		// ����   �Fint �ݒ��̒萔�o�b�t�@�̔ԍ�, int �萔�o�b�t�@�̔z��ԍ�, const C_Constant_Data_Class & �萔�o�b�t�@�ɃZ�b�g����f�[�^
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		template<class C_Constant_Data_Class>
		void M_Set_Constant_Data_To_Slot_By_Index(int in_index, int in_buffer_index, const C_Constant_Data_Class& in_set_data)
		{
			// �z��O���w�肳�ꂽ�甲����
			if (in_index < 0 || mpr_variable.constant_data_list.size() <= in_index)
			{
				return;
			}


			// �� �ϐ��錾 �� //
			int constant_data_size = sizeof(C_Constant_Data_Class);	// �萔�f�[�^�̃o�C�g��


			// �f�[�^���Z�b�g����
			mpr_variable.constant_data_list[in_index].data->M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void*>(&in_set_data));

			return;
		}

		//--�� �Q�b�^ ��--//

		// �w�肳�ꂽ�萔�o�b�t�@�Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����萔�o�b�t�@�Ǘ��p�f�[�^�̔ԍ��@�߂�l�F�w�肳�ꂽ�萔�o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Index(int);

		// �w�肳�ꂽ���O�̒萔�o�b�t�@�Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����萔�o�b�t�@�Ǘ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�萔�o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Name(std::string);

		// �w�肳�ꂽ���O�̒萔�o�b�t�@�Ǘ��p�f�[�^�̃X���b�g�ԍ���Ԃ��@�����F�擾����萔�o�b�t�@�Ǘ��p�f�[�^�̖��O�@�߂�l�Fint �w�肳�ꂽ�萔�o�b�t�@�̔ԍ��A�Ȃ����-1
		int M_Get_Constant_Buffer_Slot_Number_By_Name(std::string);

		//--�� WVP ���[���h �r���[ �v���W�F�N�V���� ��--//

		// �n���ꂽ���[���h�ϊ��s��i�g�����X�t�H�[���j��WVP�p�̒萔�o�b�t�@�ɃZ�b�g����@�����F�Z�b�g���郏�[���h�ϊ��s��̎Q��(const)
		void M_Set_World_Matrix(const DirectX::XMMATRIX & );

		// ���C���J�����̃r���[�ϊ��s��A�v���W�F�N�V�����ϊ��s���WVP�p�̒萔�o�b�t�@�ɃZ�b�g����
		void M_Set_View_Projection_By_Main_Camera(void);

		// �n���ꂽ�r���[�ϊ��s��i�J�����j��WVP�p�̒萔�o�b�t�@�ɃZ�b�g����@�����F�Z�b�g����r���[�ϊ��s��̎Q��(const)
		void M_Set_View_Matrix(const DirectX::XMMATRIX & );

		// �n���ꂽ�v���W�F�N�V�����ϊ��s��i�`��X�N���[���ݒ�j��WVP�p�̒萔�o�b�t�@�ɃZ�b�g����@�����F�Z�b�g����v���W�F�N�V�����ϊ��s��̎Q��(const)
		void M_Set_Projection_Matrix(const DirectX::XMMATRIX & );

		// �n���ꂽWVP�ϊ��s���WVP�p�̒萔�o�b�t�@�ɃZ�b�g����@�����F�Z�b�g����WVP�ϊ��s��̎Q��(const)
		void M_Set_WVP_Matrix(const MATH::WVP::S_World_View_Projection_Data & );

		//--�� �{�[�� ��--//

		// �n���ꂽ�{�[���}�g���N�X�s����{�[���p�̒萔�o�b�t�@�ɃZ�b�g����
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & );

		//--�� ������� ��--//

		// �}�e���A���̎��������Z�b�g����@�����F�Z�b�g����}�e���A���������̎Q�Ɓiconst�j
		void M_Set_Material_Detail(const DATA::MATERIAL_DETAIL::S_Material_Detail & );


		//-��- �e�N�X�`�� -��-//

		//--�� ���[�h ��--//

		// �w�肳�ꂽ�X���b�g�Ƀe�N�X�`�������[�h����@�����F�e�N�X�`���X���b�g�ԍ�, ���[�h����e�N�X�`�����@�߂�l�F�������̂�true
		bool M_Load_Texture_To_Slot_By_Index(int, std::string);

		//--�� �Q�b�^ ��--//

		// �w�肳�ꂽ�e�N�X�`���Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����e�N�X�`���Ǘ��p�f�[�^�̔ԍ��@�߂�l�F�w�肳�ꂽ�e�N�X�`���o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Texture_Buffer_Data * M_Get_Texture_Data_By_Index(int);

		// �w�肳�ꂽ���O�̃e�N�X�`���Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����e�N�X�`���Ǘ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�e�N�X�`���o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Texture_Buffer_Data * M_Get_Texture_Data_By_Name(std::string);

		// �w�肳�ꂽ���O�̃e�N�X�`���Ǘ��p�f�[�^�̃X���b�g�ԍ���Ԃ��@�����F�擾����e�N�X�`���Ǘ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�e�N�X�`���̔ԍ��A�Ȃ����-1
		int M_Get_Texture_Slot_Number_By_Name(std::string);


		//-��- �����_�����O��� -��-//

		//--�� �Z�b�^ ��--//

		// �����_�����O��ʂ��X���b�g�ɃZ�b�g���遖���ӁF�V�F�[�_�[�ł̃X���b�g�ԍ��ł͂Ȃ��@�����F�����_�����O�摜�̐ݒ��X���b�g�ԍ�, �����_�����O�摜�̎Q��
		void M_Set_Rendering_Screen_To_Slot_By_Index(int, RENDERING::CAPSULE::C_Rendering_Screen_System & );

		// ���C���̃����_�����O��ʂ��X���b�g�ɃZ�b�g���遖���ӁF�V�F�[�_�[�ł̃X���b�g�ԍ��ł͂Ȃ��@�����F�����_�����O�摜�̐ݒ��X���b�g�ԍ�
		void M_Set_Main_Rendering_Screen_To_Slot_By_Index(int);

		//--�� �Q�b�^ ��--//

		// �w�肳�ꂽ�����_�����O��ʊǗ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾���郌���_�����O��ʊǗ��p�f�[�^�̔ԍ��@�߂�l�F�w�肳�ꂽ�����_�����O��ʃo�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Rendering_Screen_Data * M_Get_Rendering_Screen_Data_By_Index(int);

		// �w�肳�ꂽ���O�̃����_�����O��ʊǗ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾���郌���_�����O��ʊǗ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�����_�����O��ʃo�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Rendering_Screen_Data * M_Get_Rendering_Screen_By_Name(std::string);

		// �w�肳�ꂽ���O�̃����_�����O��ʊǗ��p�f�[�^�̃X���b�g�ԍ���Ԃ��@�����F�擾���郌���_�����O��ʊǗ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�����_�����O��ʂ̔ԍ��A�Ȃ����-1
		int M_Get_Rendering_Screen_Slot_Number_By_Name(std::string);


		//-��- �[�x�X�e���V���o�b�t�@ -��-//

		//--�� �Z�b�^ ��--//

		// �[�x�X�e���V���o�b�t�@���X���b�g�ɃZ�b�g���遖���ӁF�V�F�[�_�[�ł̃X���b�g�ԍ��ł͂Ȃ��@�����F�[�x�X�e���V���o�b�t�@�̐ݒ��X���b�g�ԍ�, �[�x�X�e���V���o�b�t�@�̎Q��
		void M_Set_Depth_Stencil_Buffer_To_Slot_By_Index(int, RENDERING::CAPSULE::C_Depth_Stencil_Buffer_System & );

		// ���C���̐[�x�X�e���V���o�b�t�@���X���b�g�ɃZ�b�g���遖���ӁF�V�F�[�_�[�ł̃X���b�g�ԍ��ł͂Ȃ��@�����F�[�x�X�e���V���o�b�t�@�̐ݒ��X���b�g�ԍ�
		void M_Set_Main_Depth_Stencil_Buffer_To_Slot_To_Index(int);

		//--�� �Q�b�^ ��--//

		// �w�肳�ꂽ�[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̔ԍ��@�߂�l�F�w�肳�ꂽ�[�x�X�e���V���o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Depth_Stencil_Data * M_Get_Depth_Stencil_Data_By_Index(int);

		// �w�肳�ꂽ���O�̐[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̃A�h���X��Ԃ��@�����F�擾����[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�[�x�X�e���V���o�b�t�@���̃A�h���X�A�Ȃ����nullptr
		S_Depth_Stencil_Data * M_Get_Depth_Stencil_Buffer_By_Name(std::string);

		// �w�肳�ꂽ���O�̐[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̃X���b�g�ԍ���Ԃ��@�����F�擾����[�x�X�e���V���o�b�t�@�Ǘ��p�f�[�^�̖��O�@�߂�l�F�w�肳�ꂽ�[�x�X�e���V���o�b�t�@�̔ԍ��A�Ȃ����-1
		int M_Get_Depth_Stencil_Buffer_Slot_Number_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

