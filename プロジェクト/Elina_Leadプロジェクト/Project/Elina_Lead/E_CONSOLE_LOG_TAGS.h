//����������������������������������������������//
// �ڍ�   �F�R���\�[�������̃��O�̎��ʗp�ԍ�
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE
#define D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE


// �� �l�[���X�y�[�X �� //

// �f�o�b�O���O�p�̃R���\�[�����Ăяo�����߂̖��O
namespace DEBUGGER::LOG::CONSOLE::TAGS
{
	// �� �萔 �� //

	// �R���\�[�������̃��O�̎��ʗp�ԍ�
	enum class E_CONSOLE_LOG_TAGS
	{
		//-��- �V�X�e�� -��-//
		e_SET_UP = 0,	// ��������
		e_SHUT_DOWN,	// �V���b�g�_�E����


		//-��- �A�v���P�[�V���� -��-//
		e_OBJECT,			// �I�u�W�F�N�g�ɂ�郍�O
		e_GAME_RENDERING,	// �Q�[����̕`��ɂ�郍�O
		e_UI				// UI�ɂ�郍�O
	};
}


#endif // !D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE