//����������������������������������������������//
// �ڍ�   �FDX12�Ńt�H���g���g�����߂̃f�[�^�Ǘ��p�̃N���X�i�|�����[�t�B�Y���p�j
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_FONT_DATA_SET_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <windows.h>

#include "C_Rendering_Font_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// DX12�p�̃V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// �� �N���X �� //

	// DX12�p�̃t�H���g�f�[�^�Z�b�g
	class C_DX12_Font_Data_Set : public INSTANCE::C_Rendering_Font_Inform_Base
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		LOGFONTW m_log_font;	// �t�H���g�̐ݒ�


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_DX12_Font_Data_Set(void);

		// �f�X�g���N�^
		~C_DX12_Font_Data_Set(void) override;

		// �t�H���g�f�[�^�̏�����
		void M_Reset(void) override;


		//-��- �ύX -��-//

		// �t�H���g�̃s�N�Z���T�C�Y��ύX����@�����F���̃s�N�Z����, �c�̃s�N�Z����
		void M_Resize(int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_FONT_DATA_SET_H_FILE

