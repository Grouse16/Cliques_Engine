//����������������������������������������������//
// �ڍ�   �F�u�����h�X�e�[�g�ݒ�p�̃N���X
// ����   �F�u�����h�X�e�[�g�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Blend_State_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� ��//

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ƂɃu�����h�̐ݒ���s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �ݒ��̃p�C�v���C���X�e�[�g, const C_Creat_Rendering_Graphics_Setting_Inform & �����_�����O�ݒ萶���p�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_inform)
{
	// �� �萔 �� //
	const char con_RENDER_TARGET_SUM = 8;	// �ݒ�\�ȃ����_�[�^�[�Q�b�g��

	
	// �� �ϐ��錾 �� //
	int use_render_target_sum = in_creat_inform.another_data.blend_mode.size() > con_RENDER_TARGET_SUM * con_RENDER_TARGET_SUM + in_creat_inform.another_data.blend_mode.size() <= con_RENDER_TARGET_SUM * in_creat_inform.another_data.blend_mode.size();	// �g�p���郌���_�[�^�[�Q�b�g��


	// �����_�[�^�[�Q�b�g�����̃u�����h�ݒ���s��
	for (int l_now_render_target_setting = 0; l_now_render_target_setting < use_render_target_sum; l_now_render_target_setting++)
	{
		switch (in_creat_inform.another_data.blend_mode[l_now_render_target_setting])
		{
			// �ʏ�ʂ�̕`��
		case RENDERING::INFORM::BLEND_MODE::E_BLEND_MODE::e_NORMAL:

			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting];

			break;
		}
	}

	return;
}
