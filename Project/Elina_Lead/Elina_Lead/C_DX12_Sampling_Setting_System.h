//����������������������������������������������//
// �ڍ�   �F�T���v�����O�ݒ�p�̃N���X
// ����   �F�T���v�����O�ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM
#define D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>


// �� �l�[���X�y�[�X �� //

// �T���v�����O�ݒ�p�̒�`���Ăяo�����߂̖��O
namespace RENDERING::API::DX12::DX12_TOOL
{
	// �� �N���X �� //

	// �T���v�����O�ݒ�p�̃N���X
	class C_DX12_Sampling_Setting_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �T���v�����O�ݒ���܂Ƃ߂čs���@�����F�p�C�v���C�������p���,�@�T���v�����O��,�@�N�I���e�B,�@�m�[�h��
		static void M_Sampling_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC&, UINT, UINT, UINT);
	};
}


#endif // !D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM
