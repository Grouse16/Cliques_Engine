//����������������������������������������������//
// �ڍ�   �F�N�H�[�^�j�I���V�X�e���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_QUATERNION_H_FILE
#define D_INCLUDE_GUARD_C_QUATERNION_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// �N�H�[�^�j�I�����Ăяo�����߂̖��O
namespace MATH::QUATERNION
{
	// �� �N���X �� //

	// �N�H�[�^�j�I���̃N���X
	class C_Quaternion
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			DirectX::XMVECTOR m_rotation_vector = DirectX::XMVECTOR();	// ��]�i�N�H�[�^�j�I���j

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Quaternion(void);

		// �f�X�g���N�^
		~C_Quaternion(void);


		//-��- �Z�b�^ -��-//

		// �N�H�[�^�j�I�����Z�b�g����@�����F�Z�b�g����N�H�[�^�j�I���̎Q�Ɓiconst�j
		void M_Set_Quaternion(const DirectX::XMVECTOR & );

		// �x���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����@�����F��]���
		void M_Set_Quaternion_By_Angle(DirectX::XMFLOAT3);

		// �x���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����@�����F���[��, �s�b�`, ���E
		void M_Set_Quaternion_By_Angle(float, float, float);

		// ���W�A���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����@�����F��]���
		void M_Set_Quaternion_By_Radian(DirectX::XMFLOAT3);

		// ���W�A���̉�]�̏�񂩂�N�H�[�^�j�I�����Z�b�g����@�����F���[��, �s�b�`, ���E
		void M_Set_Quaternion_By_Radian(float, float, float);


		//-��- �Q�b�^ -��-//

		// �N�H�[�^�j�I���̉�]�x�N�g����Ԃ��@�߂�l�F�N�H�[�^�j�I���̉�]�x�N�g��
		DirectX::XMVECTOR M_Get_Quaternion_Rotation_Vector(void) const;

		// ��]�̃}�g���N�X�ϊ��s���Ԃ��@�߂�l�F��]�}�g���N�X�s��
		DirectX::XMMATRIX M_Get_Rotation_Matrix(void) const;

		// ���݂̃N�H�[�^�j�I������w�肳�ꂽ�������������x�N�g����Ԃ��@�����F��������(const�Q��:�������p)�@�߂�l�F������ς�����̃x�N�g��
		DirectX::XMFLOAT3 M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & ) const;


		//-��- �N�H�[�^�j�I�� -��-//

		// �x���Ŏw��l��������]������@�����F���[��, �s�b�`, ���E
		void M_Add_Rotation_By_Angle(float, float, float);

		// �x���Ŏw��l��������]������@�����F��]���
		void M_Add_Rotation_By_Angle(DirectX::XMFLOAT3);

		// ���W�A���Ŏw��l��������]������@�����F���[��, �s�b�`, ���E
		void M_Add_Rotation_By_Radian(float, float, float);

		// ���W�A���Ŏw��l��������]������@�����F��]���
		void M_Add_Rotation_By_Radian(DirectX::XMFLOAT3);

		// ���݂̉�]�x�N�g������w�肳�ꂽ�N�H�[�^�j�I���܂ŕ�ԗ��ɂ�鋅�ʐ��`��Ԃ��s���@�����F��Ԑ�̃N�H�[�^�j�I���ւ̎Q��(const), ��ԗ��i0%�Ō��l�A100%�ňړ���Ɠ����l�j
		void M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);
		
		// ��ڂ̃N�H�[�^�j�I�������ڂ̃N�H�[�^�j�I���֎w�肳�ꂽ��ԗ��̋��ʐ��`��Ԃ��s���@�����F��Ԍ��N�H�[�^�j�I���̎Q��(const), ��Ԑ�N�H�[�^�j�I���̎Q��(const), ��ԗ��i0%�ň�ځA100%�œ�Ɠ����ʒu�j
		void M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR & , float );

		// ���݂̉�]�x�N�g������w�肳�ꂽ�N�H�[�^�j�I���܂ŕ�ԗ��ɂ����`��Ԃ��s���@�����F��Ԑ�̃N�H�[�^�j�I���ւ̎Q��(const), ��ԗ��i0%�Ō��l�A100%�ňړ���Ɠ����l�j
		void M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);

		// ��ڂ̃N�H�[�^�j�I�������ڂ̃N�H�[�^�j�I���֎w�肳�ꂽ��ԗ��̐��`��Ԃ��s���@�����F��Ԍ��N�H�[�^�j�I���̎Q��(const), ��Ԑ�N�H�[�^�j�I���̎Q��(const), ��ԗ��i0%�ň�ځA100%�œ�Ɠ����ʒu�j
		void M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR &, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_QUATERNION_H_FILE


