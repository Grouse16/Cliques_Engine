////
// Ú×   FAj[VfÌ[hð·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


//  t@CÐç«  //
#include <string>

#include "C_Object_Vertex_System.h"
#include "C_Text_And_File_Manager.h"
#include "S_3D_Animation_Model_Vertex.h"
#include "S_Bone_Inform.h"
#include "C_Mesh_Data.h"


//  l[Xy[X  //

// Aj[Vfð[h·é½ßÌVXeðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION_MODEL::LOADER
{
	//  NX  //

	// Aj[Vfð[h·éNX
	class C_Animation_Model_Loader
	{
	//== vCx[g ==//
	private:

		//  Ö  //

		//-- ú» --//

		// CX^X»Å«È¢æ¤ÉRXgN^ðBÁµ½ãÅí
		C_Animation_Model_Loader(void) = delete;


	//== pubN ==//
	public:

		//  Ö  //

		//-- [h --//

		// wè³ê½pXÌt@Cð[hµAAj[VfÌf[^Å é©Ç¤©ð»è·é@øFt@CÌpX, [hµ½¶f[^Ìæ¾æÌQÆ@ßèlF[hÉ¬÷A©ÂAj[VfÌf[^Å éêÌÝtrue
		static bool M_Load_Animation_Model_File(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// Aj[VfÌ¸_f[^ð[h·é@øFft@CÌf[^, [hæÌ¸_f[^ÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex> & );

		// Aj[VfÌ{[f[^ð[h·é@øFft@CÌf[^, [hæÌ{[f[^ÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// Aj[VfÌbVf[^ð[h·é@øFft@CÌf[^, [hæÌbVf[^ÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

