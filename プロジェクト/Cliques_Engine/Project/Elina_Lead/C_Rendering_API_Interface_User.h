//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�ɑ΂����{������s�����߂̃C���^�[�t�F�[�X
// ����   �F��{����݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Color.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̊�{������s���N���X
	class C_Rendering_API_Interface_User
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_User(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �����_�����O -��-//

		// �����_�����O�̊J�n�̎��s
		static void M_Rendering_Start(void);

		// �����_�����O�̏I���ƕ`��o�b�t�@�؂�ւ��̎��s
		static void M_Rendering_End_And_Swap_Screen(void);


		//-��- ���� -��-//

		// �����_�����OAPI������ł��邩�ǂ������`�F�b�N����@�߂�l�F���펞�̂�true
		static bool M_Rendering_API_Safe_Check(void);


		//-��- �Q�b�^ -��-//

		// ���݂̃����_�����O�V�X�e���̃V�F�[�_�[�̃t�H���_�܂ł̃p�X��Ԃ��@�߂�l�F�V�F�[�_�[�܂ł̃p�X
		static std::string M_Get_Shader_Folder_Path(void);

		// ���݂̃����_�����O�V�X�e���̃V�F�[�_�[�̊g���q��Ԃ��@�߂�l�F�V�F�[�_�[�̊g���q
		static std::string M_Get_Shader_Extension(void);


		//-��- �Z�b�^ -��-//

		// ��ʂ��N���A����F��ݒ肷��@�����F�Z�b�g����F
		static void M_Set_Screen_Clear_Color(DATA::COLOR::C_Color);
	};
}



#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE
