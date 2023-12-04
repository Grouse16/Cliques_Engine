//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�X�N���[���i�����_�����O��摜�j�̃V�X�e��
// ����   �F�����_�[�^�[�Q�b�g�r���[���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>
#include <wrl.h>
#include <vector>

#include "C_Rendering_Screen_System_Base.h"
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
    // �� �\���� �� //

	// �����_�[�^�[�Q�b�g�̃o�b�t�@���`����\����
	struct S_DX12_Render_Target_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> render_buffer;	// �����_�[��̉�ʃo�b�t�@

		D3D12_CPU_DESCRIPTOR_HANDLE handle;	// �e�N�X�`�����\�[�X���ʗp���(GPU�̂��߂Ƀ��\�[�X�𕪉����ĕϊ�����)
	};


	// �����_�[�^�[�Q�b�g�r���[�p�̍\����
	struct S_DX12_Render_Target_View
	{
		std::vector<S_DX12_Render_Target_Buffer> buffer_list;	// �����_�[�^�[�Q�b�g�̃o�b�t�@���X�g

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// �f�X�N���v�^�𐮗����邽�߂̖؍\���f�[�^�V�X�e��

		D3D12_RESOURCE_STATES now_resource_barrier = D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_PRESENT;	// ���̃��\�[�X�̃o���A���
	};


    // �� �N���X �� //

    // DX12�̃����_�����O�X�N���[���̃N���X
	class C_DX12_Rendering_Screen_System : public RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base
    {
        //==�� �p�u���b�N ��==//
    public:

        // �� �ϐ��錾 �� //
		S_DX12_Render_Target_View m_render_target_view;	// �����_�[�^�[�Q�b�g�r���[�p�p�����[�^

		int m_rendering_screen_sum = 0;	// �����_�����O��ʐ�


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_DX12_Rendering_Screen_System(void);

		// �f�X�g���N�^
		~C_DX12_Rendering_Screen_System(void) override;

		// �������̉��
		void M_Release(void) override;


		//-��- �摜 -��-//

		// �w�肳�ꂽ�ԍ��̃����_�����O��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����@�����F�����_�����O��ʔԍ�, �ۑ���̃e�N�X�`����ʂ̎Q�Ɓ@�߂�l�F�������̂�true
		bool M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & ) override;


		//-��- �Q�b�^ -��-//

		// �����_�����O��ʐ���Ԃ��@�߂�l�F�����_�����O��ʐ�
		int M_Get_Rendering_Screen_Sum(void) override;
    };
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE

