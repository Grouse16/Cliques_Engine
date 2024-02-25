//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�X�N���[���i�����_�����O��摜�j�̃V�X�e��
// ����   �F�����_�[�^�[�Q�b�g�r���[�Ɛ[�x�X�e���V���r���[���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"
#include "C_Color_Converter.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


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
// �߂�l �Fbool �������̂�true
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

		return false;
	}


	// �� �ϐ��錾 �� //
	D3D12_RESOURCE_DESC render_target_view_inform = m_render_target_view.buffer_list[in_screen_number].render_buffer->GetDesc();	// �����_�[�^�[�Q�b�g�r���[�̏��

	int texture_width = (int)render_target_view_inform.Width;	// �摜�̉���
	int texture_height = (int)render_target_view_inform.Height;	// �摜�̏c��

	void * map_data = nullptr;	// �}�b�v�ɂ���Ď擾�����f�[�^


	// �����_�[�^�[�Q�b�g�r���[�̃f�[�^���擾�A�擾�Ɏ��s������G���[�Ŕ�����
	if (FAILED(m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data)))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "�X�N���[���摜�̎擾�Ɏ��s���܂���");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// ��f�̌^�ɂ���ĕ���
	switch (render_target_view_inform.Format)
	{
		// ��f�̐F����RGB���ꂼ��P�o�C�g�̉摜���擾�i�O�`�Q�T�T�j
	case DXGI_FORMAT::DXGI_FORMAT_B8G8R8A8_UNORM:
		{
			// �� �ϐ��錾 �� //
			DATA::COLOR::C_1_Byte_Color * texture_color = nullptr;	// RGBA��S�ĂO�`�Q�T�T�Ŏ󂯎���^

			int pixel_sum = texture_width * texture_height;	// �摜�̉�f��


			// �^�̉��߂�ύX
			texture_color = static_cast<DATA::COLOR::C_1_Byte_Color * >(map_data);

			// �e�N�X�`���p�̃}�b�v�𐶐�����
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// �� �ϐ��錾 �� //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// �e�N�X�`���̃}�b�v���擾����


			// �e�N�X�`���p�̃}�b�v�ɒl���ڂ�
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// �s�N�Z���ɐF��h���Ă���
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_1_Byte_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// �����_�[�^�[�Q�b�g�r���[�̃f�[�^����ďI��
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// ��f�̐F����RGBA���ꂼ��Q�o�C�g�ł���i-1.0�`1.0�j
	case DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT:
		{
			// �� �ϐ��錾 �� //
			DATA::COLOR::C_Half_Color * texture_color = nullptr;	// RGBA��S�ĂO�`�Q�T�T�Ŏ󂯎���^

			int pixel_sum = texture_width * texture_height;	// �摜�̉�f��


			// �^�̉��߂�ύX
			texture_color = static_cast<DATA::COLOR::C_Half_Color * >(map_data);

			// �e�N�X�`���p�̃}�b�v�𐶐�����
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// �� �ϐ��錾 �� //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// �e�N�X�`���̃}�b�v���擾����


			// �e�N�X�`���p�̃}�b�v�ɒl���ڂ�
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// �s�N�Z���ɐF��h���Ă���
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_Half_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// �����_�[�^�[�Q�b�g�r���[�̃f�[�^����ďI��
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// ��f�̐F����RGBA���ꂼ��S�o�C�g�ł���i-1.0�`1.0�j
	case DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT:
		{
			// �� �ϐ��錾 �� //
			DATA::COLOR::C_Color * texture_color = nullptr;	// RGBA��S�ĂO�`�Q�T�T�Ŏ󂯎���^

			int pixel_sum = texture_width * texture_height;	// �摜�̉�f��


			// �^�̉��߂�ύX
			texture_color = static_cast<DATA::COLOR::C_Color * >(map_data);

			// �e�N�X�`���p�̃}�b�v�𐶐�����
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// �� �ϐ��錾 �� //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// �e�N�X�`���̃}�b�v���擾����


			// �e�N�X�`���p�̃}�b�v�ɒl���ڂ�
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// �s�N�Z���ɐF��h���Ă���
				texture_map[l_now_pixel_number] = texture_color[l_now_pixel_number];
			}

			// �����_�[�^�[�Q�b�g�r���[�̃f�[�^����ďI��
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;
	}

	// �e�N�X�`���̎�ނ��s���Ȃ�G���[�Ŕ�����
	return false;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O��ʐ���Ԃ�
// ����   �Fvoid
// �߂�l �Fint �����_�����O��ʐ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_DX12_Rendering_Screen_System::M_Get_Rendering_Screen_Sum(void)
{
	return m_rendering_screen_sum;
}

