////
// Ú×   FbVÌf[^ÇpÌVXeÌNX
// à¾   F¸_â¸_CfbNXîñÌÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Mesh_Data.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MESH;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Mesh_Data::C_Mesh_Data(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Mesh_Data::~C_Mesh_Data(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Release(void)
{
	mpr_variable.vertex_index_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-- Ýè --//

//===============//
// Ú×   F¸_CfbNXðwè³ê½ª¶¬
// ø   Fint ¶¬·é¸_CfbNX
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Create_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_index_system.M_Create_Index_Data_And_Buffer(in_creat_index_sum);

	return;
}


//===============//
// Ú×   F¸_CfbNXÌf[^ðCfbNXobt@ÉÝè·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_index_system.M_Set_Index_Data_To_Buffer();

	return;
}


//===============//
// Ú×   F¸_CfbNXf[^ÌÝðí·éiobt@ÉÝèãAÒWµÈ¢ÈçKvªÈ¢j
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_index_system.M_Delete_Index_Data();

	return;
}


//===============//
// Ú×   Fwè³ê½¼OÌ}eAð[h·é
// ø   Fstring }eA¼
// ßèl F¬÷ÌÝtrue
//===============//
bool C_Mesh_Data::M_Load_Material_By_Name(std::string in_load_material_name)
{
	return mpr_variable.material.M_Load_Material(in_load_material_name);
}


//-- Zb^ --//

//===============//
// Ú×   FbV¼ðÝè·é
// ø   Fstring Ýè·ébV¼
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Set_Mesh_Name(std::string in_set_mesh)
{
	mpr_variable.name = in_set_mesh;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F¸_CfbNXf[^ÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<unsigned int> & ¸_CfbNXf[^ÌXgÌQÆ
//===============//
std::vector<unsigned int> & C_Mesh_Data::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_index_system.M_Get_Index_Data();
}


//===============//
// Ú×   F»ÝÌ}eA[U[ÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Material_User & }eA[U[ÌQÆðÔ·
//===============//
ASSET::MATERIAL::C_Material_User & C_Mesh_Data::M_Get_Material_User(void)
{
	return mpr_variable.material;
}


//===============//
// Ú×   FbV¼ðÔ·
// ø   Fvoid
// ßèl Fstring bV¼
//===============//
std::string C_Mesh_Data::M_Get_Mesh_Name(void)
{
	return mpr_variable.name;
}


//-- `æ --//

//===============//
// Ú×   FbVÌ`æðÀs·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Draw_Mesh(void)
{
	// }eAðZbg·éi_OÝèðo^µAèobt@AeNX`ðGPUÌf[^XbgÉZbgj
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ¸_ð`æ·éi¸_CfbNXobt@ÌXgSÄð`æ·éj
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


//===============//
// Ú×   F}eAÌÝèð¹¸ÉÊÌ`æÌÝs¤iOÅ}eAðÝèµÄ©ç`æ·éÆ«pj
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Mesh_Data::M_Draw_Mesh_Do_Not_Set_Material(void)
{
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


