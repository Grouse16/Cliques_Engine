//����������������������������������������������//
// �ڍ�   �F�萔�o�b�t�@�p�f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <d3d12.h>
#include <wrl.h>

#include "C_Constant_Buffer_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// �萔�o�b�t�@�p�f�[�^�̃N���X
	class C_DX12_Constant_Setting_Inform : public INSTANCE::C_Constant_Buffer_Setting_Inform_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_constant_buffer_heap = nullptr;	// �萔�o�b�t�@�r���[�̃q�[�v�V�X�e���i�؍\���Ǘ��V�X�e���j

		Microsoft::WRL::ComPtr<ID3D12Resource> m_constant_buffer_data = nullptr;	// �萔�f�[�^


		//-��- �I���� -��-//

		// �R���X�g���N�^
		C_DX12_Constant_Setting_Inform(void);

		// �f�X�g���N�^
		virtual ~C_DX12_Constant_Setting_Inform(void);


		//-��- �Z�b�^ -��-//

		// �萔�o�b�t�@�Ɏw�肳�ꂽ�����Z�b�g����@�����F�Z�b�g����f�[�^, �z��, �Z�b�g����f�[�^�T�C�Y
		void M_Set_Data_To_Buffer(void*, int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
