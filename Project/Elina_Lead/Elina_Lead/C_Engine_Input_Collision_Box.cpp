//����������������������������������������������//
// �ڍ�   �F�G���W���̓��͔�����Ƃ�{�b�N�X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Engine_Input_Collision_Box.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INPUT::COLLISION;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Collision_Box::C_Engine_Input_Collision_Box(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Input_Collision_Box::~C_Engine_Input_Collision_Box(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�l�p�`�̓����蔻���ݒ肷��
// ����   �Fconst S_Rect & �ݒ肷�铖���蔻��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Input_Collision_Box::M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect & in_set_rect)
{
	mpr_variable.collision_rect = in_set_rect;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�l�p�`�̓����蔻��̎Q�Ƃ��擾����
// ����   �Fvoid
// �߂�l �Fconst S_Rect & ���݂̓����蔻��̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const DATA::RECTSETTING::S_Rect & C_Engine_Input_Collision_Box::M_Get_Collision_Box(void)
{
	return mpr_variable.collision_rect;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�l�p�`�̓����蔻��̎Q�Ƃ��擾����
// ����   �Fvoid
// �߂�l �Fconst S_Rect & ���݂̓����蔻��̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Engine_Input_Collision_Box::M_Collision_To_Pixel(int in_x, int in_y) const
{
	return(mpr_variable.collision_rect.left_x <= in_x) * (in_x <= mpr_variable.collision_rect.right_x)
		* (mpr_variable.collision_rect.bottom_y <= in_y) * (in_y <= mpr_variable.collision_rect.top_y);
}


