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


// �� �l�[���X�y�[�X �� //

// �u�����h�X�e�[�g�ݒ�p�V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //
	class C_DX12_Blend_State_Setting_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �S�Ă̐F�����Z�Ƃ��Ĉ����A�_����������Ȃ��A�}�X�N���|���Ȃ�
		static void M_Set_All_Color_Add_Blend_To_PSO(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
