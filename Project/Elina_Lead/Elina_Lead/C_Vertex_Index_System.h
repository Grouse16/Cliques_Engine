//����������������������������������������������//
// �ڍ�   �F���_�C���f�b�N�X�V�X�e���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// ���_�C���f�b�N�X�V�X�e���̃N���X
	class C_Vertex_Index_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> m_index_buffer = nullptr;	// ���_�C���f�b�N�X�o�b�t�@�ݒ�p���

			std::vector<unsigned int> m_index_data;	// ���_�C���f�b�N�X�f�[�^

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Vertex_Index_System(void);

		// �R�s�[�R���X�g���N�^�@�����F�R�s�[����f�[�^�̎Q��(const)
		C_Vertex_Index_System(const C_Vertex_Index_System & );

		// �f�X�g���N�^
		~C_Vertex_Index_System(void);

		// ���������������
		void M_Release(void);


		//-��- ���� -��-//

		// ���_�C���f�b�N�X�̃f�[�^�ƃo�b�t�@�𐶐�����@�����F��������C���f�b�N�X��
		void M_Create_Index_Data_And_Buffer(int);

		// ���_�C���f�b�N�X�o�b�t�@�����݂̃C���f�b�N�X�f�[�^�ɍ��킹�Đ�������
		void M_Create_Index_Buffer_By_Now_Index_Data(void);


		//-��- �폜 -��-//

		// ���_�C���f�b�N�X�f�[�^�݂̂��폜����@�����_�C���f�b�N�X�o�b�t�@�͍폜���Ȃ�
		void M_Delete_Index_Data(void);


		//-��- �Q�b�^ -��-//

		// ���_�C���f�b�N�X�f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F���_�C���f�b�N�X�f�[�^�̎Q��
		std::vector<unsigned int> & M_Get_Index_Data(void);


		//-��- �`�� -��-//

		// ���_�C���f�b�N�X�f�[�^���o�b�t�@�ɃZ�b�g����
		void M_Set_Index_Data_To_Buffer(void);

		// ���_�C���f�b�N�X�f�[�^���g�p���ĕ`�悷��
		void M_Draw_Execute_By_Index_Data(void);

		// ���_�C���f�b�N�X�f�[�^���g�p���ĕ`�悷��C���f�b�N�X�f�[�^�͈̔͂��w�肵�ĕ`�悷��@�����F�`�悷��C���f�b�N�X�f�[�^�̊J�n�ʒu�A�`�悷��C���f�b�N�X�f�[�^�̏I���ʒu
		void M_Draw_Index_Data_By_Index_Data_Range(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE

