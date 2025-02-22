////
// Ú×   FDX12Ì¸_obt@ÌZbgpf[^ÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_DX12_Vertex_Setting_Inform.h"


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
C_DX12_Vertex_Setting_Inform::C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Vertex_Setting_Inform::~C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//-- Zb^ --//

//===============//
// Ú×   F¸_f[^ðZbg·é
// ø   Fvoid * ¸_f[^ÌAhX
// ßèl Fvoid
//===============//
void C_DX12_Vertex_Setting_Inform::M_Set_Vertex_Setting(void * in_vertex_add)
{
    //  Ïé¾  //
    UINT8 * add_map = nullptr; // ¸_f[^«ÝæÌ}bvAhX


    // }bvðüèoÈ©Á½çG[ðoµÄ²¯é
    if (FAILED(m_vertex_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&add_map))))
    {
        return;
    }


    // }bvÉ¸_îñð«Þ
    memcpy(add_map, in_vertex_add, m_vertex_buffer_view.SizeInBytes);


    // }bvððú
    m_vertex_buffer_data->Unmap(0, nullptr);

	return;
}

