//����������������������������������������������//
// �ڍ�   �F�t�H���g�f�[�^�𐧌䂷�邽�߂̖��O
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE
#define D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::INSTANCE
{
	// �� �N���X �� //

	// �t�H���g�̃f�[�^���Ǘ�����V�X�e��
	class C_Rendering_Font_Inform_Base
	{
	//==�� �v���e�N�g ��==//
	protected:


	//==�� �p�u���b�N ��==//
	public:


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Font_Inform_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Font_Inform_Base(void);

		// �t�H���g�̃f�[�^�����Z�b�g����
		virtual void M_Reset(void) = 0;


		//-��- �ύX -��-//

		// �t�H���g�̃s�N�Z���T�C�Y��ύX����@�����F���̃s�N�Z����, �c�̃s�N�Z����
		virtual void M_Resize(int, int) = 0;
	};
}


#endif // !D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE
