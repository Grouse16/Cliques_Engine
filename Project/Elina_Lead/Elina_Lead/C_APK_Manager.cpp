//����������������������������������������������//
// �ڍ�   �F�A�v���P�[�V��������p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_APK_Manager.h"
#include "C_Scene_Manager.h"
#include "C_Game_Instance_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::APPLICATION;


// �� �ϐ��錾 �� //
std::unique_ptr<C_APK_Manager> C_APK_Manager::m_this;	// ���N���X�ւ̃A�N�Z�X�p�̕ϐ�


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_APK_Manager::C_APK_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F ���������Ďg�p�\�ɂ���
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_APK_Manager::M_Init(void)
{
	m_this.reset(new C_APK_Manager);

	// �����V�[�������[�h�@���s��false���Ԃ�
	return GAME::SCENE::MANAGER::C_Scene_Manager::M_Scene_Load(con_INITIALIZED_SCENE_NAME);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_APK_Manager::~C_APK_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_APK_Manager::M_Release(void)
{
	m_this.reset();
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Release();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�v���P�[�V�����̓��͂��s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_APK_Manager::M_APK_Input(void)
{
	// �A�v���P�[�V�������A�N�e�B�u�łȂ���΃X���[
	if (m_this == nullptr)
	{
		return;
	}


	//--�� ���� ��--//



	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�v���P�[�V�����̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_APK_Manager::M_APK_Update(void)
{
	// �A�v���P�[�V�������A�N�e�B�u�łȂ���΃X���[
	if (m_this == nullptr)
	{
		return;
	}


	//--�� �X�V ��--//

	// �V�[���ɂ��Q�[���X�V�O�̍X�V���s��
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Before_Update();

	// �A�N�^�[�̍X�V���s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Actor();

	// UI�̍X�V���s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_UI();

	// �|�X�g�G�t�F�N�g�̍X�V���s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Post_Effect();

	// �T�E���h�̍X�V���s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Sound();

	// �V�[���ɂ��Q�[���X�V��̍X�V���s��
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_After_Update();

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�v���P�[�V�����̕`����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_APK_Manager::M_APK_Draw(void)
{
	// �A�v���P�[�V�������A�N�e�B�u�łȂ���΃X���[
	if (m_this == nullptr)
	{
		return;
	}


	//--�� �`�� ��--//

	// �A�N�^�[�̕`����s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Actor();

	// �|�X�g�G�t�F�N�g�`�惊�X�g���X�V
	GAME::INSTANCE::C_Game_Instance_Manager::M_Set_Post_Effect_To_Draw_List();

	// �|�X�g�G�t�F�N�g��UI�`��O�̕`����s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_Before_UI();

	// UI�̕`����s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_UI();

	// �|�X�g�G�t�F�N�g��UI�`���̕`����s��
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_After_UI();

	// �V�[���ɂ��`���̍X�V���s��
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Update_After_Draw();

	return;
}
