//����������������������������������������������//
// �ڍ�   �F�_�C���N�g�G�b�N�X12�̓��̓��C�A�E�g�ݒ�p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Input_Layout_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �N���X �� //

//==�� �v���C�x�[�g ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����ɓ��͗p�̃Z�}���e�B�b�N���𐶐�����@�@�Q�l�����Fhttps://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// ����   �Fconst std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & ���C�A�E�g�ݒ�p�̏��
// �߂�l �FDXGI_FORMAT ���ʂ̃f�[�^�`��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DXGI_FORMAT C_DX12_Input_Layout_Setting_System::M_Get_Format_By_Fit_Setting(const DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING & in_setting_infrom)
{
	// �� �ϐ��̌� �� //
	switch (in_setting_infrom.sum)
	{
	//  �ϐ��P��  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_1:

		// �� �f�[�^�`�� �� //
		switch (in_setting_infrom.format)
		{
		//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:
			
			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
			//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_SINT;

				break;

			//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_SINT;

				break;

			//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_SINT;

				break;
			}

			break;

		//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_UINT;

				break;
			}

			break;

		//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;

				break;
			}

			break;
		}

		break;


	//  �ϐ��Q��  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2:

		// �� �f�[�^�`�� �� //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_SINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;

				break;
			}

			break;
		}

		break;


		//  �ϐ��R��  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_3:

		// �� �f�[�^�`�� �� //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;

				break;
			}

			break;
		}

		break;

	//  �ϐ��S��  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4:

		// �� �f�[�^�`�� �� //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_SINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// �� �f�[�^�T�C�Y �� //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;

				break;
			}

			break;
		}

		break;
	}


	// ���Ă͂܂�Ȃ���Εs����Ԃ�
	return DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
}


//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����ɓ��͗p�̃Z�}���e�B�b�N���𐶐�����@�@�Q�l�����Fhttps://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// ����   �FD3D12_INPUT_LAYOUT_DESC & �ݒ��̓��̓��C�A�E�g���, const vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & ���C�A�E�g�ݒ�p�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Input_Layout_Setting_System::M_Creat_Input_Layout_By_Creat_Inform(D3D12_INPUT_LAYOUT_DESC & in_input_layout, const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & in_input_layout_list)
{
	// �O��̃��������
	m_element_list.clear();
	m_element_list.shrink_to_fit();


	// ���C�A�E�g������������
	in_input_layout.NumElements = in_input_layout_list.size();
	m_element_list.reserve(in_input_layout.NumElements);


	// ���������J��Ԃ��A�S�Đݒ肷��
	for (UINT loop_x = 0; loop_x < in_input_layout.NumElements; loop_x++)
	{
		m_element_list.emplace_back
		(
			// �Z�}���e�B�b�N��
			"CLIQUES",

			// �Z�}���e�B�b�N�̔ԍ�
			loop_x,

			// �f�[�^�`���ݒ�
			M_Get_Format_By_Fit_Setting(in_input_layout_list[loop_x]),

			// ���_�f�[�^���ǂ̓��̓X���b�g�ɐݒ肷�邩
			0,

			// ���̃f�[�^�̎n�܂�̏ꏊ�i�o�C�g���Łj
			D3D12_APPEND_ALIGNED_ELEMENT,

			// ���_�P�̂̃f�[�^���A�������_���܂ރC���X�^���X�̃f�[�^���̎��ʁ@�i���_�����ǃC���X�^���X�Ȃ񂾂���INSTANCE�ȊO�̖��O�ɂ���ׂ��j
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,

			// �C���X�^���X�i�������_���܂ރN���X�j�̏ꍇ�A���̔z��𓯎��ɕ`�悷�邩�A���_�P�̂Ȃ�0
			0
		);
	}


	// �A�h���X���Z�b�g
	in_input_layout.pInputElementDescs = &m_element_list[0];

	return;
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Input_Layout_Setting_System::~C_DX12_Input_Layout_Setting_System(void)
{
	M_Close_Input_Layout_Inform();

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͗p�Z�}���e�B�b�N�ݒ�p�̏����폜����A�p�C�v���C���X�e�[�g�I�u�W�F�N�g�𐶐����I�������폜
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Input_Layout_Setting_System::M_Close_Input_Layout_Inform(void)
{
	m_element_list.clear();
	m_element_list.shrink_to_fit();

	return;
}

