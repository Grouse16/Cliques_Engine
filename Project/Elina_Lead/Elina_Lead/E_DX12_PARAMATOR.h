//����������������������������������������������//
// �ڍ�   �FDX12�Ɏg�p����萔���܂Ƃ߂���
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE
#define D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE


// �� �l�[���X�y�[�X �� //

// DX12�V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12
{
	// �� �萔 �� //

	// DX12�p�̒萔�̗�
	enum class E_DX12_PARAMATOR : int
	{
		e_RENDER_TARGET_BUFFER_SUM = 2,	// �����_�[�p��ʐ�

		e_RED = 0,		// �Ԃ̔z��ԍ�
		e_GREEN = 1,	// �΂̔z��ԍ�
		e_BLUE = 2,		// �̔z��ԍ�
		e_ALPHA = 3,	// ���̔z��ԍ�
		e_COLOR_SUM,	// �F�̔z��
	};
}


#endif // !D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE

