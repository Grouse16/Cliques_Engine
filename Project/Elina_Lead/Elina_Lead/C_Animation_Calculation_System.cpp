//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̌v�Z�𐧌䂷��N���X
// ����   �F�{�[���}�g���N�X�ɑ΂���A�j���[�V�����̑�����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Calculation_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::CALCULATOR;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::CALCULATOR::ALGORITHM::C_Animation_Calculate_Algorithm_Base);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	return;
}


//-��- �A�j���[�V���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�z��Ƀ{�[���}�g���N�X�z��̃f�[�^���Z�b�g����
// ����   �Fvector<XMFLOAT4X4> & �ݒ��̃{�[���}�g���N�X�z��̃f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Get_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{


	return;
}
