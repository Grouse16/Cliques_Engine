//����������������������������������������������//
// �ڍ�   �F���[���h�A�r���[�A�v���W�F�N�V�����ϊ��s��̒�`
// ����   �F�RD���f����2D�X�N���[�����ŕ`�悷�邽�߂̃f�[�^
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
#define D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// ���[���h�A�r���[�A�v���W�F�N�V�����ϊ��s����Ăяo�����߂̖��O
namespace MATH::WVP
{
	// �� �\���� �� //

	// world view projection�s��𐮗񂵂Ē�`���邽�߂̍\����
	struct S_World_View_Projection_Data
	{
		DirectX::XMMATRIX world = DirectX::XMMATRIX();		// ���[���h�ϊ��s��
		DirectX::XMMATRIX view = DirectX::XMMATRIX();		// �r���[�ϊ��s��
		DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// �v���W�F�N�V�����ϊ��s��
	};
}


#endif // !D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
