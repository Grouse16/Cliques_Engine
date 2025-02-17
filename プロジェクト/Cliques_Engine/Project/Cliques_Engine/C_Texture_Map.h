//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���̃}�b�v���`������
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE
#define D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Color.h"
#include "S_Rect.h"
#include "C_Half_Color.h"


// �� �l�[���X�y�[�X �� //

// �e�N�X�`���p�̒�`���Ăяo�����߂̖��O
namespace ASSET::TEXTURE
{
	// �� �N���X �� //

	// �e�N�X�`���̃}�b�v�p�̃N���X
	class C_Texture_Map
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<DATA::COLOR::C_Color> texture_map;	// �e�N�X�`���p�̃}�b�v�A�O��ڂ͍����Ƃ���i0,0�������ɂ����ق���top>bottom�ɂȂ�̂ŕ�����₷���j
			
			int texture_size_x = 0;	// �����̃e�N�X�`���̃T�C�Y
			int texture_size_y = 0;	// �c���̃e�N�X�`���̃T�C�Y

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Texture_Map(void);

		// �e�N�X�`���}�b�v�𐶐�����@�����F�����̃s�N�Z����, �c���̃s�N�Z����
		void M_Create_Texture_Map(int, int);

		// �f�X�g���N�^
		~C_Texture_Map(void);

		// �e�N�X�`���}�b�v���폜����
		void M_Delete_Map(void);


		//-��- �}�b�v -��-//

		// �e�N�X�`���}�b�v�̃T�C�Y��ύX����@�����F�g����̉����̃s�N�Z����, �g����̏c���̃s�N�Z����
		void M_Map_Variable_Size_Change(int, int);


		//-��- �������� -��-//

		// �S�Ă���F�ŏ������@����:�������ސF
		void M_Flush_All_Color(DATA::COLOR::C_Color &);

		// �w�肳�ꂽ�͈͂ɐF���������ށ@�����F�������ސF, �������ޔ͈�
		void M_Set_Color(DATA::COLOR::C_Color &, DATA::RECTSETTING::S_Rect &);

		// �w�肳�ꂽ�ꏊ�ɐF�𒼐ڏ������ށ@�����F�������ސF, �������ލ��W��, �������ލ��W��
		void M_Set_Color_At_Point(const DATA::COLOR::C_Color &, int, int);


		//-��- �Q�b�^ -��-//

		// ���̃e�N�X�`���p�̃}�b�v��Ԃ��@�߂�l�F�e�N�X�`���p�̃}�b�v�̎Q�Ɓi�O��ڂ������Ȃ̂Œ��Ӂj
		std::vector<DATA::COLOR::C_Color> & M_Get_Texture_Map(void);

		// �����̃s�N�Z���T�C�Y��Ԃ��@�߂�l�F�����̒l
		int M_Get_Width_Size(void);

		// �c���̃s�N�Z���T�C�Y��Ԃ��@�߂�l�F�c���̒l
		int M_Get_Height_Size(void);
	};
}


#endif // !D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE



