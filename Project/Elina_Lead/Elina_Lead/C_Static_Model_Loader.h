//����������������������������������������������//
// �ڍ�   �F�ÓI���f�������[�h����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Text_And_File_Manager.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"
#include "C_Mesh_Data.h"


// �� �l�[���X�y�[�X �� //

// �ÓI���f�������[�h���邽�߂̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MODEL::STATIC_MODEL::LOADER
{
	// �� �N���X �� //

	// �ÓI���f�������[�h����N���X
	class C_Static_Model_Loader
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�C���X�^���X���ł��Ȃ��悤�ɂ��邽�߂ɉB�����č폜
		C_Static_Model_Loader(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���[�h -��-//

		// �w�肳�ꂽ�t�@�C�������[�h���A�ÓI���f���ł��邩�ǂ����𔻒肷��@�����F�t�@�C����, ���[�h�����t�@�C���f�[�^�̋L�^��@�߂�l�F���[�h�ɐ����A���ÓI���f���ł����true
		static bool M_Load_Static_Model_File_Data(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// �ÓI���f���̒��_�f�[�^�����[�h����@�����F���f���t�@�C���̃f�[�^, ���[�h��̒��_�f�[�^�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & );

		// �ÓI���f���̃��b�V���f�[�^�����[�h����@�����F���f���t�@�C���̃f�[�^, ���[�h��̃��b�V���f�[�^�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
