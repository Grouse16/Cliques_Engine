////
// Ú×   FÏ`µÈ¢fÌR|[lgÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


//  t@CÐç«  //
#include <vector>
#include <string>

#include "C_Component_Base.h"
#include "C_Static_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"
#include "S_Model_Draw_Command.h"


//  l[Xy[X  //

// fpR|[lgðÄÑo·½ßÌ¼O
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	//  NX  //

	// Ï`µÈ¢fÌR|[lgNX
	class C_Static_Model_Component : public GAME::COMPONENT::BASE::C_Component_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			ASSET::MODEL::C_Static_Model_User model_system;	// 3DfVXe
			
			MATH::C_Transform transform;	// fÌÝuÊui[JÀWj

			std::vector<ASSET::MODEL_SYSTEM::S_Model_Draw_Command> draw_command_list;	// `æÝèXg

			DirectX::XMMATRIX world_matrix = DirectX::XMMATRIX();	// [h}gNXÏ·sñ

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Static_Model_Component(void);

		// fXgN^
		~C_Static_Model_Component(void);


		//-- [h --//

		// wè³ê½¼OÌfð[h·é@øF[h·éf¼@ßèlF¬÷ÌÝtrue
		bool M_Load_Model_By_Name(std::string);


		//-- Zb^ --//

		// `æÝèXgðÔðwèµÄÝè·éAOÉ Á½`æÝèÌf[^ÍÁ¦é@øFÝèæÌ`æÝèÔ, gp·é}eA¼, `æ·ébV¼ÌXgigÈµÅSbV`æj@ßèlFÇÁµ½}eAgpVXeÌAhX
		ASSET::MATERIAL::C_Material_User * M_Set_Model_Draw_List(int, std::string, std::vector<std::string>);


		//-- Qb^ --//

		// [JÀWÌQÆðÔ·@ßèlF[JÀWÌQÆ
		MATH::C_Transform & M_Get_Transform(void);

		// fVXeÌQÆðÔ·@ßèlFfVXeÌQÆ
		ASSET::MODEL::C_Static_Model_User & M_Get_Model_Address(void);


		//-- XV --//

		// XV
		void M_Update(void) override;


		//-- `æ --//

		// `æÊuÆÈé[h}gNXðÝè·éA`æÌJnÉÀs·é@øFÝè·é[h}gNXÏ·sñÌQÆiconstj
		void M_Draw_Start_World_Matrix_Set(const DirectX::XMMATRIX & );

		// fÌ`æðs¤@øF`æ·éÌ`æÝèÌÔ
		void M_Model_Draw(int);

		// R|[lgpÌ`æ¾ªgpµÈ¢if`æOÉ}eAÌÝèÈÇðs¤½ßj
		void M_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
