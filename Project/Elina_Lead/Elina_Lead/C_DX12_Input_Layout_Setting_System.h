//����������������������������������������������//
// �ڍ�   �F�_�C���N�g�G�b�N�X12�̓��̓��C�A�E�g�ݒ�p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory.h>
#include <d3d12.h>

#include "Input_Layout_Data.h"


// �� �l�[���X�y�[�X �� //

// DX12�V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// �� �N���X �� //

	// �_�C���N�g�G�b�N�X12�̓��̓��C�A�E�g�ݒ�p�̃N���X
	class C_DX12_Input_Layout_Setting_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		std::vector<D3D12_INPUT_ELEMENT_DESC> m_element_list;	// ���̓G�������g�Ǘ��p�z��


		// �� �֐� �� //

		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���ɍ������`���̎��ʗp�̏���Ԃ��@�����F�C���v�b�g���C�A�E�g�ݒ�p���@�߂�l�F�t�H�[�}�b�g���
		DXGI_FORMAT M_Get_Format_By_Fit_Setting(const DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING &);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//
		
		// �w�肳�ꂽ�f�[�^�����ɓ��͗p�̃Z�}���e�B�b�N���𐶐�����@�����F�ݒ��̓��̓��C�A�E�g���, ���C�A�E�g�ݒ�p�̏��
		void M_Create_Input_Layout_By_Create_Inform(D3D12_INPUT_LAYOUT_DESC &, const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> &);


		//-��- �폜 -��-//
		
		// �f�X�g���N�^
		~C_DX12_Input_Layout_Setting_System(void);

		// ���͗p�Z�}���e�B�b�N�ݒ�p�̏����폜����A�p�C�v���C���X�e�[�g�I�u�W�F�N�g�𐶐����I�������폜
		void M_Close_Input_Layout_Inform(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE

