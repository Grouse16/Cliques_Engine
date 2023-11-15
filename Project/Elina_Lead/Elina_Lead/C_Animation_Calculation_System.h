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


			// �� �֐� �� //

			//-��- ������ -��-//

			// �ʏ�̃R���X�g���N�^�𖳌���
			SPr_Variable(void) = delete;

			//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
			// �ڍ�   �F�{�[�����������p�̃R���X�g���N�^
			// ����   �Fint �{�[����
			// �߂�l �F�Ȃ�
			//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
			SPr_Variable(int bone_sum) : animation_status(bone_sum)
			{
				return;
			}

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

		// �A�j���[�V�����̃X�e�[�^�X�̏�����
		void M_Animation_Status_Reset(void);


		//-��- �Z�b�^ -��-//

		// ���݂̃A�j���[�V�������Ԃ��Z�b�g����@�����F�Z�b�g����A�j���[�V��������
		void M_Set_Animation_Time(float);

		// ���݂̃A�j���[�V�������Ԃ��Z�b�g����@�����F�Z�b�g����A�j���[�V�����̃X�s�[�h
		void M_Set_Animation_Speed(float);


		//-��- �Q�b�^ -��-//

		// �A�j���[�V�������I�����Ă��邩�ǂ�����Ԃ��@�߂�l�F�A�j���[�V�����I���̃t���O
		bool M_Get_Animation_Is_End(void);

		// ���݂̃A�j���[�V�������Ԃ�Ԃ��@�߂�l�F���݂̃A�j���[�V��������
		float M_Get_Animation_Time(void);

		// ���݂̃A�j���[�V�����̃X�s�[�h��Ԃ��@�߂�l�F���݂̃A�j���[�V�����̃X�s�[�h
		float M_Get_Animation_Speed(void);

		// ���݂̃A�j���[�V�����̃u�����h����Ԃ��@�߂�l�F���݂̃A�j���[�V�����̃u�����h��
		float M_Get_Animation_Blend_Percent(void);


		//-��- �A�j���[�V���� -��-//

		// �n���ꂽ�A�j���[�V�������Đ�����@�����F�Đ�����A�j���[�V�����f�[�^�̃A�h���X
		void M_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// �n���ꂽ�A�j���[�V���������[�v�Đ�����@�����F�Đ�����A�j���[�V�����f�[�^�̃A�h���X
		void M_Loop_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// �n���ꂽ�A�j���[�V�������u�����h���čĐ�����@�����F�Đ�����A�j���[�V�����f�[�^�̃A�h���X�i�u�����h��j
		void M_Blend_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// �w�肳�ꂽ�z��ɃA�j���[�V�������ʂ̃{�[���}�g���N�X�z��̃f�[�^���Z�b�g����@�����F�ݒ��̃{�[���}�g���N�X�z��̃f�[�^�̎Q��
		void M_Create_Animationed_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> &);
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
