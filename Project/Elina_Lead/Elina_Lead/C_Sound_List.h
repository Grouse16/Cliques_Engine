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

// �Q�[���̃T�E���h�̃��X�g���Ăяo�����߂̖��O
namespace GAME::INSTANCE::SOUND::LIST
{
	// �� �R���Z�v�g�N���X �� //

	// �T�E���h�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Sound_Class = std::is_base_of<GAME::INSTANCE::SOUND::BASE::C_Sound_Base, C_Check_Instance>::value;


	// �� �N���X �� //

	// �T�E���h�n���̃��X�g�A�T�E���h���N���X���ƂɊǗ����Ă���
	template <C_Checked_Sound_Class C_Sound>
	class C_Sound_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, std::unique_ptr<C_Sound>>
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� ��` �� //
		typedef std::unique_ptr<C_Sound> Type_Sound;	// �T�E���h�̃N���X���g�p����Ƃ��̌^


		// �� �ϐ��錾 �� //
		static C_Sound_List<C_Sound> m_sound_list_this;	// �V���O���g�����p�̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^�@�V���O���g��������
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_Sound_List(void)
		{
			M_Set_My_Instance_Address(this);

			return;
		}


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�f�X�g���N�^
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		~C_Sound_List(void)
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
		static C_Sound * M_Create_Sound(std::string in_sound_name)
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
		static void M_Delete_Sound_Update(void)
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
		void M_Delete_Instance_Execute(void) override
		{
			M_Delete_Sound_Update();

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�S�ẴC���X�^���X�̍폜���s��
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Delete_All_Instance_Execute(void) override
		{
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_All_Instance();

			return;
		}


		//-��- �Q�b�^ -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�T�E���h�̃��X�g��Ԃ�
		// ����   �Fvoid
		// �߂�l �Fvector<Type_Sound> & �w�肳�ꂽ�T�E���h�̃��X�g
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static std::vector<Type_Sound> & M_Get_Sound_List(void)
		{
			return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ���O�̃T�E���h�̃A�h���X��Ԃ�
		// ����   �Fvoid
		// �߂�l �FC_Sound * ���O����v�����T�E���h�̃A�h���X
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		static C_Sound * M_Get_Sound_By_Name(std::string in_search_name)
		{
			// �S�ẴT�E���h��T�����A���������炻�̃A�h���X��Ԃ�
			for (Type_Sound & now_sound : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List())
			{
				if (now_sound.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_sound.get();
				}
			}

			// ������Ȃ������ꍇ�́Anull��Ԃ�
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE


