//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̃o�C�g�R�[�h�p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE
#define D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <memory>


// �� �l�[���X�y�[�X �� //

// �����_�����O�Ɏg�p����V�F�[�_�[���Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �N���X �� //

	// �V�F�[�_�[�̃o�C�g�R�[�h�p�̃N���X
	class C_Shader_Code
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<void* > binary_ptr = nullptr;	// �R���p�C���ς݃R�[�h

			unsigned int size = 0;	// �o�C�g�R�[�h�̃T�C�Y

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Shader_Code(void);

		// �f�X�g���N�^
		~C_Shader_Code(void);

		// �o�C�g�R�[�h�̃����������������������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �V�F�[�_�[�����[�h����@�����F�V�F�[�_�[�܂ł̃p�X
		bool M_Load_Shader_File(std::string);


		//-��- �Q�b�^ -��-//

		// �R���p�C���ς݃R�[�h�̎Q�Ƃ�Ԃ��@�߂�l�F�R���p�C���ς݃R�[�h
		const std::unique_ptr<void * > & M_Get_Compiled_Cord(void) const;

		// �R�[�h�̃o�C�g�T�C�Y��Ԃ��@�߂�l�F�R�[�h�̃o�C�g�T�C�Y
		int M_Get_Cord_Size(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE
