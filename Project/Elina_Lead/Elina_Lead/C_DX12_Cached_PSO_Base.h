//����������������������������������������������//
// �ڍ�   �F�p�C�v���C���X�e�[�g�̏�Ԃ��󂯎�邽�߂̃L���b�V���p�̃V�X�e���̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CACHED_PSO_BASE
#define D_INCLUDE_GUARD_C_CACHED_PSO_BASE


// �� �t�@�C���Ђ炫 ��//
#include <d3d12.h>


// �� �l�[���X�y�[�X �� //

// �p�C�v���C���X�e�[�g�̏�Ԃ��󂯎�邽�߂̃L���b�V���p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// �p�C�v���C���X�e�[�g�̏�Ԃ��󂯎�邽�߂̃L���b�V���p�̃V�X�e���̊��N���X
	class C_DX12_Cached_PSO_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �ݒ� -��-//

		// �L���b�V�����󂯎��Ȃ����̐ݒ���s���@�����F�p�C�v���C���ݒ�p���
		static void M_Cashe_Nothing(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_CACHED_PSO_BASE
