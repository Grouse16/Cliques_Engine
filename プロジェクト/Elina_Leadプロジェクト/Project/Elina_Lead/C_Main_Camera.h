//����������������������������������������������//
// �ڍ�   �F���C���J�����̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
#define D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>


// �� �l�[���X�y�[�X �� //

// ���C���ƂȂ�J�������Ăяo�����߂̖��O
namespace GAME::CAMERA::MAIN_CAMERA
{
	// �� �N���X �� //
	
	// ���C���J�����̃N���X
	class C_Main_Camera
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			DirectX::XMMATRIX view = DirectX::XMMATRIX();	// �r���[�̃}�g���N�X�ϊ��s��
			DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// �v���W�F�N�V�����̃}�g���N�X�ϊ��s��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Main_Camera m_this;	// �V���O���g�������邽�߂̃C���X�^���X


		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Main_Camera(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// ���C���J����������������
		static void M_Reset(void);

		// �f�X�g���N�^
		~C_Main_Camera(void);


		//-��- �Z�b�^ -��-//

		// �r���[�̃}�g���N�X�ϊ��s����Z�b�g����@�����F�Z�b�g����r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		static void M_Set_View_Matrix(const DirectX::XMMATRIX & );

		// �v���W�F�N�V�����̃}�g���N�X�ϊ��s����Z�b�g����@�����F�Z�b�g����v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		static void M_Set_Projection_Matrix(const DirectX::XMMATRIX & );

		
		//-��- �Q�b�^ -��-//

		// �r���[�̃}�g���N�X�ϊ��s��̎Q�Ƃ�Ԃ��@�߂�l�F�r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		static const DirectX::XMMATRIX & M_Get_View_Matrix(void);

		// �v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ƃ�Ԃ��@�߂�l�F�v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		static const DirectX::XMMATRIX & M_Get_Projection_Matrix(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
