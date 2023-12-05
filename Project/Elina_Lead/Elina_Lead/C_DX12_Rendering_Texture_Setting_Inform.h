//����������������������������������������������//
// �ڍ�   �FDX12�̃e�X�N�`���̃Z�b�g�p�̃f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <wrl.h>
#include <d3d12.h>
#include <vector>

#include "E_Shader_Kind.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// DX12�̃e�X�N�`���̃Z�b�g�p�̃f�[�^�̃N���X
	class C_DX12_Rendering_Texture_Setting_Inform : public INSTANCE::C_Rendering_Texture_Setting_Inform_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_texture_heap;	// �e�N�X�`���p�q�[�v

		Microsoft::WRL::ComPtr<ID3D12Resource> m_texture_data;	// �e�N�X�`���p�f�[�^

		int m_pix_size_x = 0;	// �e�N�X�`���̃s�N�Z���T�C�Yx
		int m_pix_size_y = 0;	// �e�N�X�`���̃s�N�Z���T�C�Yy


		//-��- �I���� -��-//

		// �R���X�g���N�^
		C_DX12_Rendering_Texture_Setting_Inform(void);

		// �f�X�g���N�^
		virtual ~C_DX12_Rendering_Texture_Setting_Inform(void);

		// ���������������
		void M_Delete(void);


		//-��- �X�V -��-//

		// �e�N�X�`���̃f�[�^���Z�b�g����@�����F�ݒ肷��F�z��ւ̎Q��, �e�N�X�`���̉���, �e�N�X�`���̏c��
		void M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> &, int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
