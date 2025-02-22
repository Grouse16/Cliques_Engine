////
// Ú×   F¸_CfbNXVXeÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Vertex_Index_System.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "C_Rendering_API_Interface_Vertex_Index_Buffer.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::CAPSULE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Vertex_Index_System::C_Vertex_Index_System(void)
{
	return;
}


//===============//
// Ú×   FRs[RXgN^
// ø   Fconst C_Vertex_Index_System & Rs[·éf[^ÌQÆ(const)
// ßèl FÈµ
//===============//
C_Vertex_Index_System::C_Vertex_Index_System(const C_Vertex_Index_System & in_copy_data)
{
	// ¸_CfbNXobt@ðRs[·é
	mpr_variable.m_index_buffer.reset(in_copy_data.mpr_variable.m_index_buffer.get());

	// ¸_CfbNXf[^ðRs[·é
	mpr_variable.m_index_data = in_copy_data.mpr_variable.m_index_data;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Vertex_Index_System::~C_Vertex_Index_System(void)
{
	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Release(void)
{
	mpr_variable.m_index_buffer.reset();

	mpr_variable.m_index_data.clear();
	mpr_variable.m_index_data.shrink_to_fit();

	return;
}


//-- ¶¬ --//

//===============//
// Ú×   F¸_CfbNXÌf[^Æobt@ð¶¬·é
// ø   Fint ¶¬·éCfbNX
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Create_Index_Data_And_Buffer(int in_index_sum)
{
	//  Ïé¾  //
	RENDERING::API::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// ¸_CfbNXobt@¶¬pÌîñ


	// ¸_CfbNXðÝè·é
	creat_index_inform.index_sum = in_index_sum;

	// ¸_CfbNXobt@ð¶¬·é
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Vertex_Index_Buffer::M_Create_Index_Buffer(mpr_variable.m_index_buffer, creat_index_inform);

	
	// ¸_CfbNXf[^ð¶¬·é
	mpr_variable.m_index_data.resize(in_index_sum);

	return;
}


//===============//
// Ú×   F¸_CfbNXobt@ð»ÝÌCfbNXf[^Éí¹Ä¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Create_Index_Buffer_By_Now_Index_Data(void)
{
	//  Ïé¾  //
	RENDERING::API::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// ¸_CfbNXobt@¶¬pÌîñ


	// ¸_CfbNXðÝè·é
	creat_index_inform.index_sum = (int)mpr_variable.m_index_data.size();

	// ¸_CfbNXobt@ð¶¬·é
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Vertex_Index_Buffer::M_Create_Index_Buffer(mpr_variable.m_index_buffer, creat_index_inform);

	return;
}


//-- í --//

//===============//
// Ú×   F¸_CfbNXf[^ÌÝðí·é@¸_CfbNXobt@ÍíµÈ¢
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Delete_Index_Data(void)
{
	mpr_variable.m_index_data.clear();
	mpr_variable.m_index_data.shrink_to_fit();

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F¸_CfbNXf[^ÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<unsigned int> & ¸_CfbNXf[^ÌQÆ
//===============//
std::vector<unsigned int> & C_Vertex_Index_System::M_Get_Index_Data(void)
{
	return mpr_variable.m_index_data;
}


//-- `æ --//

//===============//
// Ú×   F¸_CfbNXf[^ðgpµÄ`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Set_Index_Data_To_Buffer(void)
{
	mpr_variable.m_index_buffer->M_Set_Index_Setting(mpr_variable.m_index_data);

	return;
}


//===============//
// Ú×   F¸_CfbNXf[^ðgpµÄ`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Draw_Execute_By_Index_Data(void)
{
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer(mpr_variable.m_index_buffer);

	return;
}


//===============//
// Ú×   F¸_CfbNXf[^ðgpµÄ`æ·éCfbNXf[^ÌÍÍðwèµÄ`æ·é
// ø   Fint `æJnCfbNX, int `æI¹CfbNX
// ßèl Fvoid
//===============//
void C_Vertex_Index_System::M_Draw_Index_Data_By_Index_Data_Range(int in_draw_start_index, int in_draw_end_index)
{
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer_By_Range(mpr_variable.m_index_buffer, in_draw_start_index, in_draw_end_index);

	return;
}

