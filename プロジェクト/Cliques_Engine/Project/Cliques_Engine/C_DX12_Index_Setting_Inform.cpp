////
// Ú×   FDX12Ì¸_CfbNXobt@ÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_DX12_Index_Setting_Inform.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Index_Setting_Inform::C_DX12_Index_Setting_Inform(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Index_Setting_Inform::~C_DX12_Index_Setting_Inform(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   F¸_CfbNXf[^ðZbg·é
// ø   Fconst vector<unsigned int> & Ýè·éCfbNXf[^ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_Index_Setting_Inform::M_Set_Index_Setting(const std::vector<unsigned int> & in_set_index_data)
{
    //  Ïé¾  //
    void * get_map_address = nullptr; // ¸_f[^«ÝæÌ}bvAhX


    //  CfbNXobt@f[^ðÝè  //

    //  f[^ÌAhXðüè  //    // üèÉ¸sµ½çðâ~
    if (FAILED(m_index_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&get_map_address))))
    {
        return;
    }


    //  Ïé¾  //
    unsigned int * buffer_data = static_cast<unsigned int * >(get_map_address);    // «Ýæobt@iPoCgItZbgj

    int write_index_sum = 0;    // «ÞCfbNX


    // «à¤ÆµÄ¢éCfbNXªCfbNXobt@ÌTCYð´¦Ä¢½çCfbNXobt@ÌTCYªÜÅ«Þ
    if (m_index_sum < in_set_index_data.size())
    {
		write_index_sum = m_index_sum;
	}

    // «à¤ÆµÄ¢éCfbNXªCfbNXobt@ÌTCYð´¦Ä¢È©Á½ç«à¤ÆµÄ¢éCfbNXªÜÅ«Þ
    else
    {
		write_index_sum = (int)in_set_index_data.size();
	}

    // CfbNXobt@Éf[^ð«Þ
    for (int index = 0; index < write_index_sum; index++)
    {
        buffer_data[index] = in_set_index_data[index];
    }

    // }bsOð
    m_index_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

	return;
}

