//����������������������������������������������//
// �ڍ�   �F�t�H���g�f�[�^���摜�ɕϊ����鎞�ɕK�v�ȃf�[�^���܂Ƃ߂��p�b�P�[�W�\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE
#define D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>

#include "C_Rendering_Font_Inform_Base.h"
#include "S_Rect.h"
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X �� //

// �p�b�P�[�W���̂����t�H���g�n�����Ăяo�����߂̖��O
namespace PAKAGE::FONT
{
	// �� �萔 �� //

	// �t�H���g�̃r�b�g�}�b�v���~�����x��
	enum class E_FONTBIT_MAP_LEVEL
	{
		e_4,	// 0~4
		e_16,	// 0~16
		e_64,	// 0~64
	};


	// �� �N���X �� //

	// �t�H���g�f�[�^���摜�ɕϊ����鎞�ɕK�v�ȃf�[�^���܂Ƃ߂��p�b�P�[�W�\����
	struct S_Make_Font_To_Graph_Package
	{
		std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Font_Inform_Base> * attach_font_data = nullptr;	// �ݒ肷��t�H���g�̃f�[�^

		ASSET::TEXTURE::C_Texture_Map * tex_map_data = nullptr;	// �e�N�X�`���̃f�[�^

		DATA::RECTSETTING::S_Rect draw_rect;	// �e�N�X�`���f�[�^�̕`��͈�

		E_FONTBIT_MAP_LEVEL bit_map_level = E_FONTBIT_MAP_LEVEL::e_16;	// �ݒ肷��r�b�g�}�b�v���x��

		wchar_t text_code = L'\0';	// �`�悷�镶��
	};
}


#endif // !D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE
