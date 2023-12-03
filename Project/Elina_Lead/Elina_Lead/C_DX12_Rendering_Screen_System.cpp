//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�X�N���[���i�����_�����O��摜�j�̃V�X�e��
// ����   �F�����_�[�^�[�Q�b�g�r���[�Ɛ[�x�X�e���V���r���[���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Rendering_Screen_System::C_DX12_Rendering_Screen_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Rendering_Screen_System::~C_DX12_Rendering_Screen_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������J������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Rendering_Screen_System::M_Release(void)
{
	m_render_target_view.buffer_list.clear();
	m_render_target_view.buffer_list.shrink_to_fit();
	
	return;
}


//-��- �摜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ԍ��̃����_�����O��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����
// ����   �Fint �����_�����O��ʔԍ�, C_Texture_Map & �ۑ���̃e�N�X�`����ʂ̎Q��
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_screen_number, ASSET::TEXTURE::C_Texture_Map & in_to_texture)
{
	// �͈͊O���w�肳�ꂽ��G���[���o���Ĕ�����
	if (0 < in_screen_number || in_screen_number <= m_rendering_screen_sum)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "�X�N���[���摜�ԍ��ɔ͈͊O���w�肳��܂���");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}


	// �� �ϐ��錾 �� //
	int texture_width = m_render_target_view.buffer_list[in_screen_number].screen_width;	// �摜�̉���
	int texture_height = m_render_target_view.buffer_list[in_screen_number].screen_height;	// �摜�̏c��

	void * map_data = nullptr;	// �}�b�v�ɂ���Ď擾�����f�[�^


	// �����_�[�^�[�Q�b�g�r���[�̃f�[�^���擾
	m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data);

	// �擾�Ɏ��s������G���[�Ŕ�����
	if (map_data == nullptr)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "�X�N���[���摜�̎擾�Ɏ��s���܂���");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}

	// ��f�̌^�ɂ���ĕ���
	switch (m_screen_format)
	{
		// ��f�̐F����RGB���ꂼ��P�o�C�g�ł���i�O�`�Q�T�T�j
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_1_BYTE:
		{
			// �� �ϐ��錾 �� //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBA��S�ĂO�`�Q�T�T�Ŏ󂯎���^


			// �^�̉��߂�ύX
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// �e�N�X�`���p�̃}�b�v�𐶐�����
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			// �� �ϐ��錾 �� //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// �e�N�X�`���̃}�b�v���擾����


			// �e�N�X�`���p�̃}�b�v�ɒl���ڂ�
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					// �� �ϐ��錾 �� //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// ���݂̃s�N�Z���ԍ�


					// �s�N�Z���ɐF��h���Ă���
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// �����_�[�^�[�Q�b�g�r���[�̃f�[�^����ďI��
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// ��f�̐F����RGBA���ꂼ��Q�o�C�g�ł���i-1.0~1.0�j
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE:
		{
			// �� �ϐ��錾 �� //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBA��S�ĂO�`�Q�T�T�Ŏ󂯎���^


			// �^�̉��߂�ύX
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// �e�N�X�`���p�̃}�b�v�𐶐�����
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			// �� �ϐ��錾 �� //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// �e�N�X�`���̃}�b�v���擾����


			// �e�N�X�`���p�̃}�b�v�ɒl���ڂ�
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					// �� �ϐ��錾 �� //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// ���݂̃s�N�Z���ԍ�


					// �s�N�Z���ɐF��h���Ă���
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// �����_�[�^�[�Q�b�g�r���[�̃f�[�^����ďI��
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// ��f�̐F����RGBA���ꂼ��S�o�C�g�ł���i-1.0~1.0�j
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_4_BYTE:
		{
		}
		return;
	}

	return;
}

