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
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "S_Bone_Inform.h"
#include "S_Animation_Status.h"
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
			std::unique_ptr<ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base> animation_algorithm = nullptr;	// �A�j���[�V�����̃A���S���Y��

			ASSET::ANIMATION::S_Animation_Status animation_status;	// �A�j���[�V�����̃X�e�[�^�X

			int bone_sum = 0;	// �{�[����

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^�ɂ�鏉�����𖳌����A�{�[�����̃��X�g���Z�b�g���Ȃ���Ώ������ł��Ȃ�����
		C_Animation_Calculation_System(void) = delete;

		// �R���X�g���N�^�@�����F�{�[�����̃��X�g�̎Q��(const)
		C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// �f�X�g���N�^
		~C_Animation_Calculation_System(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- �A�j���[�V���� -��-//

		// �n���ꂽ�A�j���[�V�������Đ�����@�����F�ݒ肷��A�j���[�V�����f�[�^�̃A�h���X
		void M_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// �w�肳�ꂽ�z��ɃA�j���[�V�������ʂ̃{�[���}�g���N�X�z��̃f�[�^���Z�b�g����@�����F�ݒ��̃{�[���}�g���N�X�z��̃f�[�^�̎Q��
		void M_Create_Animationed_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> &);
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
