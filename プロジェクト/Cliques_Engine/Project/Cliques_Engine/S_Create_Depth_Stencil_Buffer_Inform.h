//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�𐶐����邽�߂̏��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�Ɏg�p����V�X�e���𐶐����邽�߂̏��
namespace RENDERING::API::CREATE
{
	// �� �\���� �� //

	// �[�x�X�e���V���o�b�t�@�𐶐����邽�߂̏��
	struct S_Create_Depth_Stencil_Buffer_Inform
	{
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT m_byte_format = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT::e_4_BYTE;	// �s�N�Z���̃o�C�g�^
	};
}


#endif // !D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE

