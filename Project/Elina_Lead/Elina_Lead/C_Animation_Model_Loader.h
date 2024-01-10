//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃��[�h������V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Object_Vertex_System.h"
#include "C_Text_And_File_Manager.h"
#include "S_3D_Animation_Model_Vertex.h"
#include "S_Bone_Inform.h"
#include "C_Mesh_Data.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������f�������[�h���邽�߂̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL::LOADER
{
	// �� �N���X �� //

	// �A�j���[�V�������f�������[�h����N���X
	class C_Animation_Model_Loader
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���ł��Ȃ��悤�ɃR���X�g���N�^���B��������ō폜
		C_Animation_Model_Loader(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X�̃t�@�C�������[�h���A�A�j���[�V�������f���̃f�[�^�ł��邩�ǂ����𔻒肷��@�����F�t�@�C���̃p�X, ���[�h���������f�[�^�̎擾��̎Q�Ɓ@�߂�l�F���[�h�ɐ����A���A�j���[�V�������f���̃f�[�^�ł���ꍇ�̂�true
		static bool M_Load_Animation_Model_File(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// �A�j���[�V�������f���̒��_�f�[�^�����[�h����@�����F���f���t�@�C���̃f�[�^, ���[�h��̒��_�f�[�^�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex> & );

		// �A�j���[�V�������f���̃{�[���f�[�^�����[�h����@�����F���f���t�@�C���̃f�[�^, ���[�h��̃{�[���f�[�^�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// �A�j���[�V�������f���̃��b�V���f�[�^�����[�h����@�����F���f���t�@�C���̃f�[�^, ���[�h��̃��b�V���f�[�^�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

