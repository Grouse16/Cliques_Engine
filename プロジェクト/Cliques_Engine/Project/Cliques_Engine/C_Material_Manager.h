//����������������������������������������������//
// �ڍ�   �F�}�e���A���𐧌䂷�邽�߂̃V�X�e��
// ����   �F�}�e���A���̃��[�h�������s������A�d�����ē����}�e���A�������[�h���Ȃ��悤�ɊǗ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <vector>

#include "C_Material.h"


// �� �l�[���X�y�[�X �� //

// �}�e���A������p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MATERIAL::MANAGER
{
	// �� �N���X �� //

	// �}�e���A���𐧌�p���邽�߂̃V�X�e��
	class C_Material_Manager
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// �}�e���A���Ǘ��p�̏��̍\����
		struct S_Material_Manage_Inform
		{
			std::unique_ptr<C_Material> material = nullptr;	// �}�e���A��

			std::string name = "DEFAULT";	// �}�e���A����

			int user_sum = 0;	// ���̃}�e���A�����g�p���Ă���C���X�^���X��
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Material_Manage_Inform> material_inform_list;	// �}�e���A�����̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Material_Manager m_this;	// �}�e���A������p�V�X�e���̃V���O���g�����p�C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g��������
		C_Material_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Material_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�}�e���A����Ԃ��@�����F�}�e���A���̖��O�@�߂�l�F�w�肳�ꂽ�}�e���A���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static ASSET::MATERIAL::C_Material * M_Get_Material_By_Name(std::string);


		//-��- ���[�h -��-//

		// �}�e���A��������}�e���A�������[�h����@�����F�}�e���A�����@�߂�l�F���������}�e���A���f�[�^�ւ̃A�h���X
		static ASSET::MATERIAL::C_Material * M_Load_Material_By_Name(std::string);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�}�e���A���̏��L����������邱�Ƃ�ʒm����@�����F���L�����������}�e���A���̃A�h���X�̎Q��
		static void M_Release_Material(ASSET::MATERIAL::C_Material * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
