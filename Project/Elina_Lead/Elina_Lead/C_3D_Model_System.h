//����������������������������������������������//
// �ڍ�   �F3D���f���̃N���X
// ����   �F3D���f���̎擾����`��A�A�j���[�V�����̎��s�܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>
#include <string>

#include "C_Mesh_Data.h"


// �� �l�[���X�y�[�X �� //

// 3D���f�����Ăяo�����߂̖��O
namespace ASSET::MODEL
{
	// �� �N���X �� //

	// 3D���f���̃N���X
	class C_3D_Model_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// �A�j���[�V�������f���̓���o�b�t�@�̃X���b�g�̔ԍ����܂Ƃ߂��\����
		struct S_Unique_Buffer_Slot
		{
			int transform = 0;			// �g�����X�t�H�[��

			int ambient_light = 0;		// �A���r�G���g���C�g
			int directional_light = 0;	// �f�B���N�V���i�����C�g
			int point_light = 0;		// �|�C���g���C�g
			int spot_light = 0;			// �X�|�b�g���C�g
			int area_light = 0;			// �G���A���C�g

			int main_texture = 0;	// ���C���ƂȂ�e�N�X�`��
		};

		// ���b�V�����Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::MESH::C_Mesh_Data> mesh_data = nullptr;	// ���b�V���f�[�^

			std::string name = "default";	// ���b�V����

			S_Unique_Buffer_Slot unique_buffer_number;	// ����ȃo�b�t�@�ԍ�
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		
		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Mesh_Data_Inform> mesh_inform_list;	// ���b�V���̊Ǘ��p��񃊃X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_3D_Model_System(void);

		//�f�X�g���N�^
		~C_3D_Model_System(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X��3D���f�������[�h����@�����F3D���f���܂ł̃p�X�@�߂�l�F�������̂�true
		bool M_Load_3D_Model_By_Path(std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���O�̃��b�V�����̃A�h���X��Ԃ��@�����F�T�����b�V���̖��O�@�߂�l�F���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		S_Mesh_Data_Inform * M_Get_Mesh_Data_By_Name(std::string);

		// ���b�V�����̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���b�V�����̃��X�g�̎Q��
		std::vector<S_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);


		//-��- �`�� -��-//

		// 3D���f����`�悷��
		void M_Draw_3D_Model(void);

		// 3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name(std::string);

		// �}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
		void M_Draw_3D_Model_Do_Not_Use_Material(void);

		// �}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j�@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
