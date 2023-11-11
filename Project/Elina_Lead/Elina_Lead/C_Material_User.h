//����������������������������������������������//
// �ڍ�   �F�}�e���A�����g�p���邽�߂̃N���X
// ����   �F�}�e���A���̎擾�A���[�h�A������~���ɍs���Astatic�ł���}�l�[�W���𑼂̎���������؂藣�����߂ɂ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_USER_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Material.h"

#include <string>


// �� �l�[���X�y�[�X �� //

// �}�e���A�����Ăяo�����߂̖��O
namespace ASSET::MATERIAL
{
	// �� �N���X �� //

	// �}�e���A�����g�p���邽�߂̃N���X
	class C_Material_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::MATERIAL::C_Material * material_address = nullptr;	// �}�e���A��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Material_User(void);

		// �f�X�g���N�^
		~C_Material_User(void);

		// �}�e���A�����������
		void M_Release(void);

		
		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃}�e���A����ǂݍ��ށ@�����F���[�h����}�e���A����
		void M_Load_Material(std::string);


		//-��- �`�� -��-//

		// ���̃}�e���A����`��p�ɃZ�b�g����
		void M_Material_Attach_To_Draw(void);


		//-��- �Q�b�^ -��-//

		// ���݂̃}�e���A����Ԃ��@�߂�l�F���݂̃}�e���A���ւ̃A�h���X
		C_Material * M_Get_Material_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
