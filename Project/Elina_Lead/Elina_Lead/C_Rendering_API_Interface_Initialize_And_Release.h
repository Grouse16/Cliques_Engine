//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̐����Ɖ���̃C���^�[�t�F�[�X
// ����   �F�����Ɖ���̓���݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̐����Ɖ�����s���N���X
	class C_Rendering_API_Interface_Initialize_And_Release
	{
	//==�� �v���C�x�[�g ��==//
private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Initialize_And_Release(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �����_�����OAPI�̏������@�߂�l�F�������̂�true
		static bool M_Initialize_Rendering_API(void);

		// �����_�����OAPI��DX12�𐶐�����
		static void M_Create_DX12(void);


		//-��- ��� -��-//

		// �����_�����OAPI�̉��
		static void M_Release_Rendering_API(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE


