//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���ݒ�p�̃N���X
// ����   �F�[�x�X�e���V���̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>

#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���ݒ�p�V�X�e���̒�`���Ăяo�����߂̖��O
namespace RENDERING::API::DX12::DX12_TOOL
{
	// �� �N���X �� //

	// �[�x�X�e���V���X�e�[�g�ݒ�p�̃N���X
	class C_DX12_Stencil_State_Setting_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �w�肳�ꂽ���ƈ�v�����[�x�l�̏������ݕ��@��Ԃ��@�����F�[�x�l�������݃��[���@�߂�l�F�[�x�l�̏������ݕ��@
		static D3D12_COMPARISON_FUNC M_Get_Depth_Write_Option(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE);

		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �[�x�X�e���V���𐶐��p�������Ƃɐݒ肷��@�����F�p�C�v���C���ݒ�p���, �����_�����O�����p���(const)
		static void M_Depth_Stencil_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform &);


		//-��- �e�X�g�ݒ� -��-//

		// �X�e���V���e�X�g�����s���Ă����s����ݒ�@�����F�p�C�v���C���̉�ʃI�v�V�����ݒ�p���
		static void M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
