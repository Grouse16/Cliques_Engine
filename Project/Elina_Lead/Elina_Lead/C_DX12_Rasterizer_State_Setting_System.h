//����������������������������������������������//
// �ڍ�   �F���X�^���C�U�ݒ�p�̃N���X
// ����   �F���X�^���C�U�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>

#include "C_Create_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U�ݒ�̒�`���Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// ���X�^���C�U�̐ݒ���s�����߂̃N���X
	class C_DX12_Rasterizer_State_Setting_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �w�肳�ꂽ�������Ƀ��X�^���C�U�̐ݒ���s���@�����F�p�C�v���C���ݒ�p���, �����_�����O�����p���(const)
		static void M_Rasterizer_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform &);
	};
}


#endif // !D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE
