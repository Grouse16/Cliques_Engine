//����������������������������������������������//
// �ڍ�   �FDX12�̐[�x�X�e���V���o�b�t�@�V�X�e��
// ����   �F�[�x�X�e���V���o�b�t�@�p�̃f�[�^���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include <d3d12.h>
#include <wrl.h>


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// �� �\���� �� //

	// �[�x�X�e���V���̃o�b�t�@���`����\����
	struct S_DX12_Depth_Stencil_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> depth_stencil_buffer;	// �[�x�X�e���V���p�̃o�b�t�@

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// �f�X�N���v�^�𐮗����邽�߂̖؍\���f�[�^�V�X�e��

		D3D12_CPU_DESCRIPTOR_HANDLE handle = D3D12_CPU_DESCRIPTOR_HANDLE();	// �e�N�X�`�����\�[�X���ʗp���(GPU�̂��߂Ƀ��\�[�X�𕪉����ĕϊ�����
	};


	// �� �N���X �� //

	// DX12�̐[�x�X�e���V���o�b�t�@�̃N���X
	class C_DX12_Depth_Stencil_Buffer_System : public RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		S_DX12_Depth_Stencil_Buffer m_data;	// �[�x�X�e���V���o�b�t�@�p�p�����[�^
		

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_DX12_Depth_Stencil_Buffer_System(void);

		// �f�X�g���N�^
		~C_DX12_Depth_Stencil_Buffer_System(void) override;

		// �������̉��
		void M_Release(void) override;


		//-��- �摜 -��-//

		// �[�x�X�e���V���o�b�t�@��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����@�����F�ۑ���̃e�N�X�`����ʂ̎Q�Ɓ@�߂�l�F�������̂�true
		bool M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & ) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
