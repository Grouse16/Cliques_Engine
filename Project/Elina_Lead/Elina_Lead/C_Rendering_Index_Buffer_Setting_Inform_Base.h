//����������������������������������������������//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@�ݒ�p�̃f�[�^�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::INSTANCE
{
	// �� �N���X �� //

	// ���_�C���f�b�N�X�o�b�t�@�ݒ�p�̃f�[�^�̊��N���X
	class C_Rendering_Index_Buffer_Setting_Inform_Base
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Index_Buffer_Setting_Inform_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Index_Buffer_Setting_Inform_Base(void);


		//-��- �Z�b�^ -��-//

		// ���_�C���f�b�N�X�f�[�^���Z�b�g����@�����F�ݒ肷��C���f�b�N�X�f�[�^�̎Q��
		virtual void M_Set_Index_Setting(const std::vector<unsigned int> & ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE


