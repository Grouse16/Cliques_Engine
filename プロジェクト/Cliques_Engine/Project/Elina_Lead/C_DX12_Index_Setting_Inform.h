//����������������������������������������������//
// �ڍ�   �FDX12�̒��_�C���f�b�N�X�o�b�t�@�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE
#define D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>
#include <wrl.h>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// �� �N���X �� //

	// DX12�̒��_�C���f�b�N�X�o�b�t�@�̃N���X
	class C_DX12_Index_Setting_Inform : public INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		D3D12_INDEX_BUFFER_VIEW m_index_buffer_view = D3D12_INDEX_BUFFER_VIEW();	// �C���f�b�N�X�o�b�t�@�r���[

		Microsoft::WRL::ComPtr<ID3D12Resource> m_index_buffer_data;	// �C���f�b�N�X�o�b�t�@�̃f�[�^

		int m_index_sum = 0;	// �C���f�b�N�X��


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_DX12_Index_Setting_Inform(void);

		// �f�X�g���N�^
		virtual ~C_DX12_Index_Setting_Inform(void) override;


		//-��- �Z�b�^ -��-//

		// ���_�C���f�b�N�X�f�[�^���Z�b�g����@�����F�ݒ肷��C���f�b�N�X�f�[�^�̎Q��
		void M_Set_Index_Setting(const std::vector<unsigned int> & ) override;
	};
}


#endif // !D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE

