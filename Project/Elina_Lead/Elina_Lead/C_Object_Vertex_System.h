//����������������������������������������������//
// �ڍ�   �F�I�u�W�F�N�g�̒��_�����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F���_�f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>

#include "C_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// �I�u�W�F�N�g�̒��_�����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
	template <class _My_Vertex_Type> class C_Object_Vertex_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> m_setting_inform;	// ���_�o�b�t�@�ݒ�p���

			std::vector <_My_Vertex_Type> m_vertex_data;	// ���_�f�[�^

			std::vector <unsigned __int32> m_index_data;	// �C���f�b�N�X�f�[�^

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�R���X�g���N�^
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		C_Object_Vertex_System(void)
		{
			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�f�X�g���N�^�A������������s��
		// ����   �Fvoid
		// �߂�l �F�Ȃ�
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		~C_Object_Vertex_System(void)
		{
			mpr_variable.m_setting_inform.reset();

			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F������������s��
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Release(void)
		{
			mpr_variable.m_setting_inform.reset();

			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//-��- ���� -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_���𐶐�����
		// ����   �Fint �������钸�_��, int ��������C���f�b�N�X���
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Create_Vertex_And_Index_Data_And_Buffer(int in_creat_vertex_sum, int in_creat_index_sum)
		{
			// �� �ϐ��錾 �� //
			RENDERING::GRAPHICS::CREATE::C_Create_Vertex_Buffer_Inform creat_vertex_inform;	// ���_��񐶐��p���


			// ���������āA�K�v�ȕ������z��𐶐����Ȃ���
			M_Release();
			mpr_variable.m_vertex_data.resize(in_creat_vertex_sum);
			mpr_variable.m_index_data.resize(in_creat_index_sum);


			// �� ���_�����p���̐ݒ� �� //
			creat_vertex_inform.size_of_vertex = sizeof(_My_Vertex_Type);	// ���_����̃o�C�g��
			creat_vertex_inform.vertex_sum = (int)mpr_variable.m_vertex_data.size();	// ���_��
			creat_vertex_inform.index_sum = (int)mpr_variable.m_index_data.size();		// �C���f�b�N�X���


			// �� �����_�����O�p���_���̐��� �� //
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(mpr_variable.m_setting_inform, creat_vertex_inform);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���݂̒��_�ƃC���f�b�N�X�̐��ɍ��킹�ăo�b�t�@�𐶐�����
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Create_Vertex_And_Index_Buffer_By_Now_Parameter(void)
		{
			// �� �ϐ��錾 �� //
			RENDERING::GRAPHICS::CREATE::C_Create_Vertex_Buffer_Inform creat_vertex_inform;	// ���_��񐶐��p���


			// �� ���_�����p���̐ݒ� �� //
			creat_vertex_inform.size_of_vertex = sizeof(_My_Vertex_Type);	// ���_����̃o�C�g��
			creat_vertex_inform.vertex_sum = (int)mpr_variable.m_vertex_data.size();	// ���_��
			creat_vertex_inform.index_sum = (int)mpr_variable.m_index_data.size();		// �C���f�b�N�X���


			// �� �����_�����O�p���_���̐��� �� //
			mpr_variable.m_setting_inform.reset();
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(mpr_variable.m_setting_inform, creat_vertex_inform);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�������_�f�[�^�𐶐�����
		// ����   �Fint ���_�f�[�^�̐�����
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Creat_Vertex_Data_By_Number(int in_vertex_sum)
		{
			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_vertex_data.resize(in_vertex_sum);
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�w�肳�ꂽ�������_�C���f�b�N�X�f�[�^�𐶐�����
		// ����   �Fint ���_�C���f�b�N�X�f�[�^�̐�����
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Creat_Index_Data_By_Number(int in_index_sum)
		{
			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			mpr_variable.m_index_data.resize(in_vertex_sum);
		}


		//-��- �폜 -��-//

		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�f�[�^���폜����@�����_�o�b�t�@�͍폜����Ȃ�
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Delete_Vertex_Data(void)
		{
			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�C���f�b�N�X�f�[�^���폜����@�����_�C���f�b�N�X�o�b�t�@�͍폜����Ȃ�
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Delete_Index_Data(void)
		{
			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//-��- �Q�b�^ -��-//
		
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�f�[�^�ւ̎Q�Ƃ�Ԃ�
		// ����   �Fvoid
		// �߂�l �Fstd::vector<_My_Vertex_Type> & ���_�f�[�^�ւ̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		std::vector<_My_Vertex_Type> & M_Get_Vertex_Data(void)
		{
			return mpr_variable.m_vertex_data;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�o�b�t�@�̏���`�悷��C���f�b�N�X���w�肵�ĕ`�悷��
		// ����   �Fvoid
		// �߂�l �Fstd::vector<uint32_t> & �C���f�b�N�X�f�[�^�ւ̎Q��
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		std::vector<uint32_t> & M_Get_Index_Data(void)
		{
			return mpr_variable.m_index_data;
		}

		
		//-��- �`�� -��-//
		
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�o�b�t�@�ɒ��_�f�[�^���Z�b�g����
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Vertex_Data_To_Buffer(void)
		{
			mpr_variable.m_setting_inform->M_Set_Vertex_Setting(&mpr_variable.m_vertex_data[0]);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F�C���f�b�N�X�o�b�t�@�ɃC���f�b�N�X�f�[�^���Z�b�g����
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Index_Data_To_Buffer(void)
		{
			mpr_variable.m_setting_inform->M_Set_Index_Setting(&mpr_variable.m_index_data[0]);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�o�b�t�@�̏���S�ĕ`�悷��
		// ����   �Fvoid
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Draw_All_Vertex(void)
		{
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_All_Vertex_By_Index(mpr_variable.m_setting_inform);

			return;
		}


		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		// �ڍ�   �F���_�o�b�t�@�̏���`�悷��C���f�b�N�X���w�肵�ĕ`�悷��
		// ����   �Fint �`�悷��C���f�b�N�X���̎n�܂�̔Ԓn, int �`�悷��C���f�b�N�X���̏I���̔Ԓn
		// �߂�l �Fvoid
		//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
		void M_Draw_Select_Vertex(int in_start_point, int in_end_point)
		{
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Select_Vertex_By_Index(mpr_variable.m_setting_inform, in_start_point, in_end_point);

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE
