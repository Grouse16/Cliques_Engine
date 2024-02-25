//����������������������������������������������//
// �ڍ�   �FUI�̐}�`��`�p�̃f�[�^
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
#define D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <d3d12.h>

#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"
#include "Figure_Base_Data.h"
#include "S_Rect.h"


// �� �l�[���X�y�[�X �� //

// UI�n�����Ăяo�����߂̖��O
namespace DATA::FIGURE::UI
{
	// �� �萔 �� //

	// UI�̐}�`�̂��߂̐��l�Q
	enum class E_UI_FIGURE_PARAMATOR
	{
		e_PICXCEL_BASE_SIZE = 1000,	// �s�N�Z���̊�Ƃ���傫��
	};


	// �� �ϐ��錾 �� //

	// UI�ݒ�p�̕ϐ��Q
	class C_UI_SETTING_DATA
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		static C_UI_SETTING_DATA m_this;	// �I�u�W�F�N�g��`�p�̕ϐ��i�V���O���g�����j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_UI_SETTING_DATA(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		static float ui_width;	// UI�̊�{�s�N�Z���̉���
		static float ui_height;	// UI�̊�{�s�N�Z���̏c��

		static float aspect_x;	// �A�X�y�N�g��ł̂�
		static float aspect_y;		// �A�X�y�N�g��ł̂�

		static float percent_of_aspect_x;	// �A�X�y�N�g��̂��̔䗦
		static float percent_of_aspect_y;	// �A�X�y�N�g��̂��̔䗦

	};	// UI�ݒ�p�̕ϐ��Q���Ăяo�����߂̖��O


	// �� �N���X �� //

	// �l�p�`��UI�p�̃N���X
	class C_UI_Box : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		RECTSETTING::S_Rect m_box_pos;	// �l�p�`�̍��W

		DATA::COLOR::C_Color m_box_color;	// �l�p�`�̐F


		// �� �֐� �� //

		//-��- �X�V -��-//

		// UI�p�̎l�p�`�����N�g����ݒ肷��@�����FRECT & �ݒu�ʒu
		virtual void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & );

		// �F��S�Ă̒��_�ɐݒ肷��@�����FCOLOR & �F
		void M_Set_UI_Box_Color(DATA::COLOR::C_Color & );


		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_UI_Box(void) { return; }

		// �f�X�g���N�^
		virtual ~C_UI_Box(void) { return; }
	};


	// �`�悷��s�N�Z�����W�����S�ɌŒ肵���l�p�`��UI
	class C_Scale_Constant_UI : public C_UI_Box
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �萔 �� //

		// �s�N�Z���̃T�C�Y��ݒ肷��Ƃ��Ɋ�Ƃ���ꏊ��ݒ肷��
		enum class E_Scale_Base_Position
		{
			e_LEFT_TOP,		// ����
			e_LEFT_BOTTOM,	// ����

			e_RIGHT_TOP,	// �E��
			e_RIGHT_BOTTOM,	// �E��
		};


		// �� �ϐ��錾 �� //
		DATA::RECTSETTING::S_Rect m_constant_pixel_pos;	// �s�N�Z���̍��W

		E_Scale_Base_Position m_base_position = E_Scale_Base_Position::e_LEFT_BOTTOM;	// �Œ莞�̊�ƂȂ�ꏊ�̎w��


		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Scale_Constant_UI(void);

		// �f�X�g���N�^
		~C_Scale_Constant_UI(void);


		//-��- �Z�b�^ -��-//

		// ��ƂȂ�ꏊ���w�肷��@�����F�w�肷��ꏊ
		void M_Set_Scale_Base_Position(E_Scale_Base_Position);


		//-��- �X�V -��-//

		// UI�p�̎l�p�`�����N�g����ݒ肷��@�����FRECT & �ݒu�ʒu
		void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & ) override;
		
		// �X�P�[�����s�N�Z�����W�ɍ��킹��X�V���s��
		void M_Scale_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
