//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̃A���S���Y���̊��N���X
// ����   �F�ǂ�ȃA�j���[�V���������邩�𕪊�ł͂Ȃ��A��������N���X�ɂ���ĕ���ł���悤�ɂ��邽�߂̒��ۉ����C���[
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <DirectXMath.h>

#include "C_Animation_Data_System.h"
#include "S_Animation_Status.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����̌v�Z�A���S���Y�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::ALGORITHM
{
	// �� �N���X �� //

	// �A�j���[�V�����̌v�Z�𐧌䂷��N���X�̊��N���X
	class C_Animation_Algorithm_Base
	{
		//==�� �v���e�N�g ��==//
	protected:

		// �� �֐� �� //

		//-��- �_�����Z -��-//

		// �l�P���l�Q���傫���Ȃ�l�P�ɒl�Q���Z�b�g����A�����łȂ��Ȃ牽�����Ȃ��@�����F�l�P, �l�Q
		void M_Guard_1_Over_2(float &, float);

		// �A�j���[�V�����̎��Ԃ̍Đ��Ƌt�Đ������s���A�A�j���[�V�����̏I�������肷��@�����F�A�j���[�V�����̏��̎Q��, �A�j���[�V�����J�n����I���܂ł̎���
		void M_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status &, float);

		// �u�����h���̎��Ԃ̍Đ��Ƌt�Đ����s���@�����F�A�j���[�V�����̏��(const), �u�����h���̎��Ԃ̎Q��, �A�j���[�V�����J�n����I���܂ł̎���
		void M_Animation_Blend_Time_Update(const ASSET::ANIMATION::S_Animation_Status &, float & , float);

		// ���[�v����A�j���[�V�����̎��Ԃ̍Đ��Ƌt�Đ������s���@�����F�A�j���[�V�����̏��̎Q��, �A�j���[�V�����J�n����I���܂ł̎���
		void M_Loop_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status &, float);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Algorithm_Base(void);

		// �f�X�g���N�^
		virtual ~C_Animation_Algorithm_Base(void);

		
		//-��- �X�V -��-//

		// �A�j���[�V�������Ԃ̍X�V
		virtual void M_Animation_Time_Update(void) = 0;

		// �A�j���[�V�����̍X�V�@�����F�X�V��������{�[���̃}�g���N�X�̔z��̎Q��, �{�[���̃I�t�Z�b�g�}�g���N�X�̃��X�g�̎Q��(const)
		virtual void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &) = 0;


		//-��- �Q�b�^ -��-//

		// ���݂̃A�j���[�V������Ԃ��@�߂�l�F���݂̃A�j���[�V�����̃A�h���X
		virtual const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATE_ALGORITHM_BASE_H_FILE
