//����������������������������������������������//
// �ڍ�   �FDX12�̒��_�o�b�t�@�̃Z�b�g�p�f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>
#include <wrl.h>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// DX12�̒��_�o�b�t�@�̃Z�b�g�p�f�[�^�̃N���X
	class C_DX12_Vertex_Setting_Inform : public INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		D3D12_VERTEX_BUFFER_VIEW m_vertex_buffer_view;	// ���_�o�b�t�@�r���[�̃A�h���X

		D3D12_INDEX_BUFFER_VIEW m_index_buffer_view;	// �C���f�b�N�X�o�b�t�@�r���[�̃A�h���X

		Microsoft::WRL::ComPtr<ID3D12Resource> m_vertex_buffer_data;	// ���_�o�b�t�@�̃f�[�^
		Microsoft::WRL::ComPtr<ID3D12Resource> m_index_buffer_data;	// �C���f�b�N�X�o�b�t�@�̃f�[�^

		int m_draw_index_sum = 0;	// �`�悷��񐔁i�C���f�b�N�X���j


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_DX12_Vertex_Setting_Inform(void);

		// �f�X�g���N�^
		virtual ~C_DX12_Vertex_Setting_Inform(void) override;


		//-��- �Z�b�^ -��-//

		// ���_�f�[�^���Z�b�g����@�����F���_�f�[�^�̃A�h���X
		void M_Set_Vertex_Setting(void*) override;

		// �C���f�b�N�X�f�[�^���Z�b�g����@�����F�C���f�b�N�X�f�[�^
		void M_Set_Index_Setting(void*) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE

