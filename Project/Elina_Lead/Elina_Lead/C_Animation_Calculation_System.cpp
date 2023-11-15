//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̌v�Z�𐧌䂷��N���X
// ����   �F�{�[���}�g���N�X�ɑ΂���A�j���[�V�����̑�����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Calculation_System.h"
#include "C_Bone_Data.h"
#include "C_Animation_Algorithm_No_Animation.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::CALCULATOR;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fconst vector<S_Bone_Inform> & �{�[�����̃��X�g�̎Q��
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list)
{
	// �{�[�������擾
	mpr_variable.bone_sum = in_bone_list.size();

	// ������Ԃ̃{�[����ݒ肷��A���S���Y���𐶐�
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation(in_bone_list));

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Release(void)
{
	mpr_variable.animation_algorithm.reset();
	mpr_variable.bone_sum = 0;

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
	// �{�[���f�[�^�p�̔z����m�ۂ���
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	return;
}
