////
// Ú×   FÃIfð[h·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE


//  t@CÐç«  //
#include <string>

#include "C_Text_And_File_Manager.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"
#include "C_Mesh_Data.h"


//  l[Xy[X  //

// ÃIfð[h·é½ßÌVXeðÄÑo·½ßÌ¼O
namespace ASSET::MODEL::STATIC_MODEL::LOADER
{
	//  NX  //

	// ÃIfð[h·éNX
	class C_Static_Model_Loader
	{
	//== vCx[g ==//
	private:

		//  Ö  //

		//-- ú» --//

		// RXgN^ACX^X»Å«È¢æ¤É·é½ßÉBÁµÄí
		C_Static_Model_Loader(void) = delete;


	//== pubN ==//
	public:

		//  Ö  //

		//-- [h --//

		// wè³ê½t@Cð[hµAÃIfÅ é©Ç¤©ð»è·é@øFt@C¼, [hµ½t@Cf[^ÌL^æ@ßèlF[hÉ¬÷A©ÂÃIfÅ êÎtrue
		static bool M_Load_Static_Model_File_Data(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// ÃIfÌ¸_f[^ð[h·é@øFft@CÌf[^, [hæÌ¸_f[^ÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & );

		// ÃIfÌbVf[^ð[h·é@øFft@CÌf[^, [hæÌbVf[^ÌQÆ@ßèlF¬÷ÌÝtrue
		static bool M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
