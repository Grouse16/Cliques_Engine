//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�ݒ�p�f�[�^�̃Z�b�g�p�̃f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <wrl.h>
#include <d3d12.h>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "C_Shader_Setting.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// DX12�̃����_�����O�ݒ�p�f�[�^�̃Z�b�g�p�̃f�[�^�̃N���X
	class C_DX12_Rendering_Graphics_Setting_Inform : public INSTANCE::C_Rendering_Graphics_Setting_Inform_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		Microsoft::WRL::ComPtr<ID3D12RootSignature> m_root_signature;	// ���[�g�����̃A�h���X

		Microsoft::WRL::ComPtr<ID3D12PipelineState> m_pipeline_state_setting;	// �`��p�C�v���C���ݒ�

		D3D12_PRIMITIVE_TOPOLOGY m_topology_type = D3D12_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;	// �`�悷��}�`�̎��

		ASSET::SHADER::C_Shader_Setting m_shader_setting;	// �V�F�[�_�[�̏��


		//-��- �I���� -��-//

		// �R���X�g���N�^
		C_DX12_Rendering_Graphics_Setting_Inform(void);

		// �f�X�g���N�^
		virtual ~C_DX12_Rendering_Graphics_Setting_Inform(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM
