////
// Ú×   F_CNgGbNX12ÌüÍCAEgÝèpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_DX12_Input_Layout_Setting_System.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


//  NX  //

//== vCx[g ==//

//-- ¶¬ --//

//===============//
// Ú×   Fwè³ê½f[^ð³ÉüÍpÌZ}eBbNîñð¶¬·é@@Ql¿Fhttps://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// ø   Fconst std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & CAEgÝèpÌîñ
// ßèl FDXGI_FORMAT ÊÌf[^`®
//===============//
DXGI_FORMAT C_DX12_Input_Layout_Setting_System::M_Get_Format_By_Fit_Setting(const DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING & in_setting_infrom)
{
	//  ÏÌÂ  //
	switch (in_setting_infrom.sum)
	{
	//  ÏPÂ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_1:

		//  f[^`®  //
		switch (in_setting_infrom.format)
		{
		//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:
			
			//  f[^TCY  //
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

			//  f[^TCY  //
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

			//  f[^TCY  //
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


	//  ÏQÂ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2:

		//  f[^`®  //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			//  f[^TCY  //
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

			//  f[^TCY  //
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

			//  f[^TCY  //
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


		//  ÏRÂ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_3:

		//  f[^`®  //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			//  f[^TCY  //
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

			//  f[^TCY  //
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

			//  f[^TCY  //
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

	//  ÏSÂ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4:

		//  f[^`®  //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			//  f[^TCY  //
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

			//  f[^TCY  //
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

			//  f[^TCY  //
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


	// ÄÍÜçÈ¯êÎs¾ðÔ·
	return DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
}


//== pubN ==//

//-- ¶¬ --//

//===============//
// Ú×   Fwè³ê½f[^ð³ÉüÍpÌZ}eBbNîñð¶¬·é@@Ql¿Fhttps://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// ø   FD3D12_INPUT_LAYOUT_DESC & ÝèæÌüÍCAEgîñ, const vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & CAEgÝèpÌîñ
// ßèl Fvoid
//===============//
void C_DX12_Input_Layout_Setting_System::M_Create_Input_Layout_By_Create_Inform(D3D12_INPUT_LAYOUT_DESC & in_input_layout, const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & in_input_layout_list)
{
	// OñÌðú
	m_element_list.clear();
	m_element_list.shrink_to_fit();


	// CAEgª¶¬·é
	in_input_layout.NumElements = (UINT)in_input_layout_list.size();
	m_element_list.reserve(in_input_layout.NumElements);


	// ¶¬ªJèÔµASÄÝè·é
	for (UINT loop_x = 0; loop_x < in_input_layout.NumElements; loop_x++)
	{
		m_element_list.emplace_back
		(
			// Z}eBbN¼
			"CLIQUES",

			// Z}eBbNÌÔ
			loop_x,

			// f[^`®Ýè
			M_Get_Format_By_Fit_Setting(in_input_layout_list[loop_x]),

			// ¸_f[^ðÇÌüÍXbgÉÝè·é©
			0,

			// ±Ìf[^ÌnÜèÌêioCgÅj
			D3D12_APPEND_ALIGNED_ELEMENT,

			// ¸_PÌÌf[^©A¡¸_ðÜÞCX^XÌf[^©Ì¯Ê@i¸_àÇCX^XÈñ¾©çINSTANCEÈOÌ¼OÉ·é×«j
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,

			// CX^Xi¡¸_ðÜÞNXjÌêA½ÂÌzñð¯É`æ·é©A¸_PÌÈç0
			0
		);
	}


	// AhXðZbg
	in_input_layout.pInputElementDescs = &m_element_list[0];

	return;
}


//-- í --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Input_Layout_Setting_System::~C_DX12_Input_Layout_Setting_System(void)
{
	M_Close_Input_Layout_Inform();

	return;
}

//===============//
// Ú×   FüÍpZ}eBbNÝèpÌîñðí·éApCvCXe[gIuWFNgð¶¬µIíÁ½çí
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_Input_Layout_Setting_System::M_Close_Input_Layout_Inform(void)
{
	m_element_list.clear();
	m_element_list.shrink_to_fit();

	return;
}

