//����������������������������������������������//
// �ڍ�   �F�X�g���[�~���O�o�͗p�o�b�t�@�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE
#define D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>


// �� �l�[���X�y�[�X �� //

// �X�g���[�~���O�o�͗p�o�b�t�@���Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// �X�g���[�~���O�o�͗p�o�b�t�@�̊��N���X
	class C_DX12_Streaming_Output_Buffer_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �X�g���[�~���O�o�͗p�o�b�t�@���g�p���Ȃ����̏��������s���@�����F�p�C�v���C���ݒ�p���
		static void M_Do_Not_Use_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &);
	};
}


#endif // !D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE
