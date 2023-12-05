//����������������������������������������������//
// �ڍ�   �FDX12�̐[�x�X�e���V���o�b�t�@�V�X�e��
// ����   �F�[�x�X�e���V���o�b�t�@�p�̃f�[�^���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Depth_Stencil_Buffer_System.h"
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE.h"
#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Depth_Stencil_Buffer_System::C_DX12_Depth_Stencil_Buffer_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Depth_Stencil_Buffer_System::~C_DX12_Depth_Stencil_Buffer_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Depth_Stencil_Buffer_System::M_Release(void)
{
	m_data.depth_stencil_buffer.Reset();
	m_data.heap.Reset();
}


//-��- �摜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����
// ����   �FC_Texture_Map & �ۑ���̃e�N�X�`����ʂ̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_Depth_Stencil_Buffer_System::M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	// �� �ϐ��錾 �� //
	void * get_mapped_data = nullptr;	// �擾�����e�N�X�`���f�[�^

	float * get_depth_data = nullptr;	// �[�x�f�[�^�i�}�b�v�̃f�[�^��float�^�œǂݑւ��j


	// �[�x�X�e���V���o�b�t�@�̃f�[�^���擾�A���s������G���[�Ŕ�����
	if (FAILED(m_data.depth_stencil_buffer->Map(0, nullptr, &get_mapped_data)))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "�[�x�X�e���V���摜�̎擾�Ɏ��s���܂���");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// float�ɓǂݑւ���
	get_depth_data = reinterpret_cast<float *>(get_mapped_data);

	// �K�v�ȃe�N�X�`���T�C�Y�𐶐�
	in_texture_map.M_Create_Texture_Map((int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_WIDTH_SIZE, (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_HEIGHT_SIZE);


	// �� �ϐ��錾 �� //
	std::vector<DATA::COLOR::C_Color> & texture_map = in_texture_map.M_Get_Texture_Map();	// �e�N�X�`���}�b�v�ւ̎Q��


	// �� �ϐ��錾 �� //

	// �e�N�X�`���̃f�[�^���ڂ�
	for (int now_depth_pixel = 0; now_depth_pixel < (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_ALL_SIZE; now_depth_pixel++)
	{
		// �e�N�X�`���̃f�[�^���ڂ�
		texture_map[now_depth_pixel].m_r = get_depth_data[now_depth_pixel];
		texture_map[now_depth_pixel].m_g = get_depth_data[now_depth_pixel];
		texture_map[now_depth_pixel].m_b = get_depth_data[now_depth_pixel];
		texture_map[now_depth_pixel].m_a = 1.0f;
	}

	// ����
	return true;
}
