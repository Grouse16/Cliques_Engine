//����������������������������������������������//
// �ڍ�   �F���_�o�b�t�@�̃Z�b�g�p�̃f�[�^�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::API::INSTANCE
{
	// �� �N���X �� //

	// ���_�o�b�t�@�̃Z�b�g�p�̃f�[�^�̊��N���X
	class C_Rendering_Vertex_Buffer_Setting_Inform_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Vertex_Buffer_Setting_Inform_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Vertex_Buffer_Setting_Inform_Base(void);


		//-��- �Z�b�^ -��-//

		// ���_�f�[�^���Z�b�g����@�����F���_�̃A�h���X
		virtual void M_Set_Vertex_Setting(void * ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
