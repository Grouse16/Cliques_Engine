////
// Ú×   FAj[VfÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_SYSTEM_H_FILE


//  t@CÐç«  //
#include "C_Mesh_Data.h"
#include "S_Bone_Inform.h"
#include "C_Animation_Data_System.h"
#include "C_Transform.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Animation_Model_Vertex.h"


//  l[Xy[X  //

// Aj[VÅ«é3DfðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION_MODEL
{
	//  NX  //

	// Aj[VfÌVXe
	class C_Animation_Model_System
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex> vertex_system;	// ¸_f[^ðÇ·éNX

			std::vector<ASSET::MESH::C_Mesh_Data> mesh_list;	// bVf[^

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// {[îñÌXg

			std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> animation_data_list;	// Aj[Vf[^ÌXg

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Animation_Model_System(void);

		//fXgN^
		~C_Animation_Model_System(void);

		// Ìðúðs¤
		void M_Release(void);


		//-- [h --//

		// wè³ê½pXÌ3DAj[Vfð[h·é@øF3DAj[VfÜÅÌpX@ßèlF¬÷ÌÝtrue
		bool M_Load_3D_Animation_Model_By_Path(std::string);

		// wè³ê½¼OÌAj[Vf[^ð[h·é@øF[h·éAj[Vf[^¼@ßèlF¬÷ÌÝtrue
		bool M_Load_Animation_Data_By_Name(std::string);


		//-- Qb^ --//

		// wè³ê½¼OÌbVf[^îñÌAhXðÔ·@øFT·bVÌ¼O@ßèlF¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
		ASSET::MESH::C_Mesh_Data * M_Get_Mesh_Data_By_Name(std::string);

		// bVîñÌXgÌQÆðÔ·@ßèlFbVîñÌXgÌQÆ
		std::vector<ASSET::MESH::C_Mesh_Data> & M_Get_Mesh_Inform_List(void);

		// wè³ê½¼OÌAj[Vf[^îñÌAhXðÔ·@øFT·Aj[Vf[^Ì¼O@ßèlF¼Oªêvµ½Aj[VÌAhXAêvµÈ©Á½çnullptrðÔ·
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation_Data_By_Name(std::string);

		// Aj[VVXeÌXgÌQÆðÔ·@ßèlFAj[VVXeÌXgÌQÆ
		const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & M_Get_Animation_Inform_List(void);

		// wè³ê½¼OÌ{[îñÌAhXðÔ·@øFT·{[Ì¼O@ßèlF¼Oªêvµ½{[ÌAhXAêvµÈ©Á½çnullptrðÔ·
		const ASSET::ANIMATION::BONE::S_Bone_Inform* M_Get_Bone_Inform_By_Name(std::string);

		// {[îñÌXgðÔ·@ßèlF{[îñÌXgÌQÆ(const)
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & M_Get_Bone_Inform_List(void);


		//-- `æ --//

		// 3Dfð`æ·é
		void M_Draw_3D_Model(void);

		// 3Df©çwè³ê½Aj[V¼ÌÝ`æ·é@øF`æ·éAj[V¼i¡»è·éj
		void M_Draw_Meshes_By_Name(std::string);

		// }eAðÝè¹¸ÉA3Dfð`æ·éi`æOÉ}eAðZbg·éÆ«pj
		void M_Draw_3D_Model_Do_Not_Use_Material(void);

		// }eAðÝè¹¸ÉA3Df©çwè³ê½bV¼ÌÝ`æ·éi`æOÉ}eAðZbg·éÆ«pj@øF`æ·ébV¼i¡»è·éj
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-- èobt@ --//

		// {[Ì}gNXð}eAÉZbg·é@øFZbg·é{[}gNXzñÌQÆ(const)
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & );

		// [h r[ vWFNVðCJð³Éèobt@ÉZbg·é@øFgXtH[ÌQÆiconstj
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// [h r[ vWFNVðCJð³Éèobt@ÉZbg·éA[h}gNXðó¯æé@øF[h}gNXÌQÆiconstj
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & );
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_SYSTEM_H_FILE



































//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================
