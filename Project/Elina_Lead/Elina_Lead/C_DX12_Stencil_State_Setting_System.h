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


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���ݒ�p�V�X�e���̒�`���Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// �[�x�X�e���V���X�e�[�g�ݒ�p�̃N���X
	class C_DX12_Stencil_State_Setting_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �[�x�X�e���V���𖳌��ɂ��鎞�̐ݒ�@�����F�p�C�v���C���ݒ�p���
		static void M_Disabled_Depth_Stencil(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);


		//-��- �e�X�g�ݒ� -��-//

		// �X�e���V���e�X�g�����s���Ă����s����ݒ�@�����F�p�C�v���C���̉�ʃI�v�V�����ݒ�p���
		static void M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
