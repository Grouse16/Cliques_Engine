//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̌v�Z�𐧌䂷��N���X
// ����   �F�{�[���}�g���N�X�ɑ΂���A�j���[�V�����̑�����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Animation_Calculator_Algorithm_Base.h"
#include "C_Animation_Data_System.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����̌v�Z�V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::CALCULATOR
{
	// �� �N���X �� //
	
	// �A�j���[�V�����̌v�Z�𐧌䂷��N���X
	class C_Animation_Calculation_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::ALGORITHM::C_Animation_Calculate_Algorithm_Base> animation_algorithm = nullptr;	// �A�j���[�V�����̃A���S���Y��


		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Calculation_System(void);

		// �f�X�g���N�^
		~C_Animation_Calculation_System(void);


		//-��- �X�V -��-//


		//-��- �A�j���[�V���� -��-//

		// �w�肳�ꂽ�z��Ƀ{�[���}�g���N�X�z��̃f�[�^���Z�b�g����
		void M_Get_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> &);
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
