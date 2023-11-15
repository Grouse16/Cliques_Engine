//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̃A���S���Y���̊��N���X
// ����   �F�ǂ�ȃA�j���[�V���������邩�𕪊�ł͂Ȃ��A��������N���X�ɂ���ĕ���ł���悤�ɂ��邽�߂̒��ۉ����C���[�@�A�j���[�V�����̌v�Z�������Ȃ��Ȃ��Ƃ��͂�������̉�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_CALCULATE_ALGORITHM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_CALCULATE_ALGORITHM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����̌v�Z�A���S���Y�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::CALCULATOR::ALGORITHM
{
	// �� �N���X �� //

	// �A�j���[�V�����̌v�Z�𐧌䂷��N���X�̊��N���X
	class C_Animation_Calculate_Algorithm_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Calculate_Algorithm_Base(void);

		// �f�X�g���N�^
		virtual ~C_Animation_Calculate_Algorithm_Base(void);

		
		//-��- �X�V -��-//

		// �A�j���[�V�������Ԃ̍X�V
		virtual void M_Animation_Time_Update(void);

		// �A�j���[�V�����̍X�V
		virtual void M_Animation_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATE_ALGORITHM_BASE_H_FILE
