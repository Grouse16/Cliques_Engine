//����������������������������������������������//
// �ڍ�   �F�u�����h�X�e�[�g�ݒ�p�̃N���X
// ����   �F�u�����h�X�e�[�g�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>

#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// �u�����h�X�e�[�g�ݒ�p�V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //
	class C_DX12_Blend_State_Setting_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �ʏ�`�掞�̃u�����h��o�^�@�����F�o�^��̃u�����h�ݒ�
		static void M_Attach_Normal_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// �ʏ�`��Ń��l�݂̂P�Œ�̎��̃u�����h��o�^�@�����F�o�^��̃u�����h�ݒ�
		static void M_Attach_Normal_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// ���Z�����ł̕`�掞�̃u�����h��o�^�@�����F�o�^��̃u�����h�ݒ�
		static void M_Attach_Invert_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// ���Z�����ł̕`��Ń��l�݂̂P�Œ�̎��̃u�����h��o�^�@�����F�o�^��̃u�����h�ݒ�
		static void M_Attach_Invert_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);


		//-��- �Q�b�^ -��-//

		// �����_�[�^�[�Q�b�g�ɏ������ގ��̃t�H�[�}�b�g�𐶐��p�̏�񂩂犄��o���ĕԂ��@�����F�u�����h�ݒ�̐����p�f�[�^(const)
		static DXGI_FORMAT M_Get_Write_Rendering_Graph_Format_By_Create_Inform(const RENDERING::GRAPHICS::CREATE::S_Blend_Setting_Create_Data & );


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �w�肳�ꂽ�������ƂɃu�����h�̐ݒ���s���@�����F�ݒ��̃p�C�v���C���X�e�[�g���, �����_�����O�ݒ萶���p�̏��(const)
		static void M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & , const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform & );
	};
}


#endif // !D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
