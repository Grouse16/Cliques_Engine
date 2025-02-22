////
// Ú×   F3DfÌNX
// à¾   F3DfÌæ¾©ç`æAAj[VÌÀsÜÅðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_STATIC_MODEL_SYSTEM_H_FILE


//  t@CÐç«  //
#include <vector>
#include <memory>
#include <string>
#include <DirectXMath.h>

#include "C_Mesh_Data.h"
#include "C_Transform.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"


//  l[Xy[X  //

// 3DfðÄÑo·½ßÌ¼O
namespace ASSET::MODEL
{
	//  NX  //

	// 3DfÌNX
	class C_Static_Model_System
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		
		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> vertex_system;	// ¸_f[^ðÇ·éNX

			std::vector<ASSET::MESH::C_Mesh_Data> mesh_list;	// bVÌÇpîñXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Static_Model_System(void);

		//fXgN^
		~C_Static_Model_System(void);

		// Ìðúðs¤
		void M_Release(void);


		//-- [h --//

		// wè³ê½pXÌ3Dfð[h·é@øF3DfÜÅÌpX@ßèlF¬÷ÌÝtrue
		bool M_Load_3D_Model_By_Path(std::string);


		//-- Qb^ --//

		// wè³ê½¼OÌbVîñÌAhXðÔ·@øFT·bVÌ¼O@ßèlF¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
		ASSET::MESH::C_Mesh_Data * M_Get_Mesh_Data_By_Name(std::string);

		// bVîñÌXgÌQÆðÔ·@ßèlFbVîñÌXgÌQÆ
		std::vector<ASSET::MESH::C_Mesh_Data> & M_Get_Mesh_Inform_List(void);


		//-- `æ --//

		// 3Dfð`æ·é
		void M_Draw_Model(void);

		// 3Df©çwè³ê½bV¼ÌÝ`æ·é@øF`æ·ébV¼i¡»è·éj
		void M_Draw_Meshes_By_Name(std::string);

		// }eAðÝè¹¸ÉA3Dfð`æ·éi`æOÉ}eAðZbg·éÆ«pj
		void M_Draw_Model_Do_Not_Use_Material(void);

		// }eAðÝè¹¸ÉA3Df©çwè³ê½bV¼ÌÝ`æ·éi`æOÉ}eAðZbg·éÆ«pj@øF`æ·ébV¼i¡»è·éj
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-- èobt@ --//

		// [h r[ vWFNVðCJð³Éèobt@ÉZbg·éAgXtH[ðó¯æé@øFgXtH[ÌQÆiconstj
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// [h r[ vWFNVðCJð³Éèobt@ÉZbg·éA[h}gNXðó¯æé@øF[h}gNXÌQÆiconstj
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX &);
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_SYSTEM_H_FILE





































//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================
