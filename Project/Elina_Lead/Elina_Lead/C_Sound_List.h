//����������������������������������������������//
// �ڍ�   �F�T�E���h�n�����Ǘ����郊�X�g�̓�����J�v�Z��������V�X�e��
// ����   �F�����A�폜�A�擾���s���āA�T�E���h�̔h���ɂ�����N���X�ȊO��S�ă��X�g����e�����Ƃ��ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE
#define D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Sound_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃T�E���h�̃��X�g�̃R���Z�v�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::SOUND::LIST::CONCEPT
{
	// �� �R���Z�v�g�N���X �� //

	// �T�E���h�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Sound_Class = std::is_base_of<GAME::INSTANCE::SOUND::BASE::C_Sound_Base, C_Check_Instance>::value;
}


// �� �}�N�� �� //
#define D_SOUND_TEMPLATE template <GAME::INSTANCE::SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>	// �T�E���h�̃e���v���[�g��`�p�}�N��


// �Q�[���̃T�E���h�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::SOUND::LIST
{
	// �� �N���X �� //

	// �T�E���h�n���̃��X�g�A�T�E���h���N���X���ƂɊǗ����Ă���
	D_SOUND_TEMPLATE class C_Sound_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, std::unique_ptr<C_Sound>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Sound> Type_Sound;	// �T�E���h�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Sound_List<C_Sound> m_sound_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g��������
		C_Sound_List(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Sound_List(void);


		//-��- ���� -��-//

		// �T�E���h�𐶐�����@�����Fstring ��������T�E���h�̖��O�@�߂�l�FC_Sound * ���������T�E���h�̃A�h���X
		static C_Sound * M_Create_Sound(std::string);


		//-��- �폜 -��-//

		// �폜�̃t���O�������Ă���T�E���h������
		static void M_Delete_Sound_Update(void);

		// �C���X�^���X�̍폜���s��
		void M_Delete_Instance_Execute(void) override;

		// �S�ẴC���X�^���X�̍폜���s��
		void M_Delete_All_Instance_Execute(void) override;


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�T�E���h�̃��X�g��Ԃ��@�߂�l�Fvector<Type_Sound> & �w�肳�ꂽ�T�E���h�̃��X�g
		static std::vector<Type_Sound> & M_Get_Sound_List(void);

		// �w�肳�ꂽ���O�̃T�E���h�̃A�h���X��Ԃ��@�߂�l�FC_Sound * ���O����v�����T�E���h�̃A�h���X
		static C_Sound * M_Get_Sound_By_Name(std::string);


		//-��- �X�V -��-//

		// �T�E���h�̍X�V���s��
		void M_Instance_Update(void) override;


		//-��- �`�� -��-//

		// �T�E���h�̕`����s��
		void M_Instance_Draw(void) override;
	};


	// �� �֐� �� //

	//==�� �v���C�x�[�g ��==//

	//-��- ������ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline C_Sound_List<C_Sound>::C_Sound_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//==�� �p�u���b�N ��==//
	
	// �� �֐� �� //

	//-��- �I���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�f�X�g���N�^
	// ����   �Fvoid
	// �߂�l �F�Ȃ�
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline C_Sound_List<C_Sound>::~C_Sound_List(void)
	{
		// �������Ă��郊�X�g��S�ĊJ�����z���_�[���폜����
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_All_Instance();

		return;
	}


	//-��- ���� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�T�E���h�𐶐�����
	// ����   �Fstring ��������T�E���h�̖��O
	// �߂�l �FC_Sound * ���������T�E���h�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline C_Sound * C_Sound_List<C_Sound>::M_Create_Sound(std::string in_sound_name)
	{
		// �� �ϐ��錾 �� //
		Type_Sound & sound_slot_address =		// �V�����T�E���h�p�̃X���b�g�̎Q��

			// �V�����T�E���h�p�̃X���b�g�𐶐�����
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Create_Instance(in_sound_name);


		// �T�E���h�𐶐����A���̃T�E���h�̃N���X�p�̃��X�g�Ɋi�[����
		sound_slot_address.reset(new C_Sound());

		// �V�����������ꂽ�T�E���h�̃A�h���X��Ԃ�
		return sound_slot_address.get();
	}


	//-��- �폜 -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�폜�̃t���O�������Ă���T�E���h������
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_Sound_Update(void)
	{
		// �� �����_�� �� //

		// �x�N�^�[����C���X�^���X�폜�p�̔�����s�������_��
		auto delete_ramada = [](Type_Sound & in_check_sound)
			{
				// �C���X�^���X�폜�̃t���O�������Ă���Ȃ�폜���A�z�񂩂炱�̗v�f���폜����
				if (in_check_sound->M_Get_Destroy_Instance_Flg())
				{
					in_check_sound.reset();
					return true;
				}

				return false;
			};


		// ���X�g����̍폜���s��
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�C���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Sound_Update();

		return;
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_All_Instance();

		return;
	}


	//-��- �Q�b�^ -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ�T�E���h�̃��X�g��Ԃ�
	// ����   �Fvoid
	// �߂�l �Fvector<unique_ptr<C_Sound>> & �w�肳�ꂽ�T�E���h�̃��X�g
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline std::vector<std::unique_ptr<C_Sound>> & C_Sound_List<C_Sound>::M_Get_Sound_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();
	}


	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ���O�̃T�E���h�̃A�h���X��Ԃ�
	// ����   �Fvoid
	// �߂�l �FC_Sound * ���O����v�����T�E���h�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline C_Sound * C_Sound_List<C_Sound>::M_Get_Sound_By_Name(std::string in_search_name)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Sound>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();	// �T�E���h�̃��X�g


		// �S�ẴT�E���h��T�����A���������炻�̃A�h���X��Ԃ�
		for (Type_Sound & now_sound : sound_list)
		{
			if (now_sound.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_sound.get();
			}
		}

		// ������Ȃ������ꍇ�́Anull��Ԃ�
		return nullptr;
	}


	//-��- �X�V -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�T�E���h�̍X�V���s��
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Instance_Update(void)
	{
		// �� �ϐ��錾 �� //
		std::vector<std::unique_ptr<C_Sound>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();	// �T�E���h�̃��X�g


		// �T�E���h���X�V����
		for (Type_Sound & now_sound : sound_list)
		{
			now_sound->M_Sound_Update();
		}

		return;
	}


	//-��- �`�� -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�`��͂Ȃ����G���[�h�~�p�ɒ�`
	// ����   �Fvoid
	// �߂�l �Fvoid
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Instance_Draw(void)
	{
		return;
	}
}


// �� �}�N���폜 �� //
#undef D_SOUND_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE


