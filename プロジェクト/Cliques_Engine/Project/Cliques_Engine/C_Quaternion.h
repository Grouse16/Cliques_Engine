////
// Ú×   FNH[^jIVXeÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_QUATERNION_H_FILE
#define D_INCLUDE_GUARD_C_QUATERNION_H_FILE


//  t@CÐç«  //
#include <DirectXMath.h>


//  l[Xy[X  //

// NH[^jIðÄÑo·½ßÌ¼O
namespace MATH::QUATERNION
{
	//  NX  //

	// NH[^jIÌNX
	class C_Quaternion
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			DirectX::XMVECTOR m_rotation_vector = DirectX::XMVECTOR();	// ñ]iNH[^jIj

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Quaternion(void);

		// fXgN^
		~C_Quaternion(void);


		//-- Zb^ --//

		// NH[^jIðZbg·é@øFZbg·éNH[^jIÌQÆiconstj
		void M_Set_Quaternion(const DirectX::XMVECTOR & );

		// xÌñ]Ìîñ©çNH[^jIðZbg·é@øFñ]îñ
		void M_Set_Quaternion_By_Angle(DirectX::XMFLOAT3);

		// xÌñ]Ìîñ©çNH[^jIðZbg·é@øF[, sb`, E
		void M_Set_Quaternion_By_Angle(float, float, float);

		// WAÌñ]Ìîñ©çNH[^jIðZbg·é@øFñ]îñ
		void M_Set_Quaternion_By_Radian(DirectX::XMFLOAT3);

		// WAÌñ]Ìîñ©çNH[^jIðZbg·é@øF[, sb`, E
		void M_Set_Quaternion_By_Radian(float, float, float);


		//-- Qb^ --//

		// NH[^jIÌñ]xNgðÔ·@ßèlFNH[^jIÌñ]xNg
		DirectX::XMVECTOR M_Get_Quaternion_Rotation_Vector(void) const;

		// ñ]Ì}gNXÏ·sñðÔ·@ßèlFñ]}gNXsñ
		DirectX::XMMATRIX M_Get_Rotation_Matrix(void) const;

		// »ÝÌNH[^jI©çwè³ê½ûüðü¢½xNgðÔ·@øFü­ûü(constQÆ:¬»p)@ßèlFûüðÏ¦½ãÌxNg
		DirectX::XMFLOAT3 M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & ) const;


		//-- NH[^jI --//

		// xÅwèlª¾¯ñ]³¹é@øF[, sb`, E
		void M_Add_Rotation_By_Angle(float, float, float);

		// xÅwèlª¾¯ñ]³¹é@øFñ]îñ
		void M_Add_Rotation_By_Angle(DirectX::XMFLOAT3);

		// WAÅwèlª¾¯ñ]³¹é@øF[, sb`, E
		void M_Add_Rotation_By_Radian(float, float, float);

		// WAÅwèlª¾¯ñ]³¹é@øFñ]îñ
		void M_Add_Rotation_By_Radian(DirectX::XMFLOAT3);

		// »ÝÌñ]xNg©çwè³ê½NH[^jIÜÅâÔ¦ÉæéÊü`âÔðs¤@øFâÔæÌNH[^jIÖÌQÆ(const), âÔ¦i0%Å³lA100%ÅÚ®æÆ¯¶lj
		void M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);
		
		// êÂÚÌNH[^jI©çñÂÚÌNH[^jIÖwè³ê½âÔ¦ÌÊü`âÔðs¤@øFâÔ³NH[^jIÌQÆ(const), âÔæNH[^jIÌQÆ(const), âÔ¦i0%ÅêÂÚA100%ÅñÂÆ¯¶Êuj
		void M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR & , float );

		// »ÝÌñ]xNg©çwè³ê½NH[^jIÜÅâÔ¦Éæéü`âÔðs¤@øFâÔæÌNH[^jIÖÌQÆ(const), âÔ¦i0%Å³lA100%ÅÚ®æÆ¯¶lj
		void M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);

		// êÂÚÌNH[^jI©çñÂÚÌNH[^jIÖwè³ê½âÔ¦Ìü`âÔðs¤@øFâÔ³NH[^jIÌQÆ(const), âÔæNH[^jIÌQÆ(const), âÔ¦i0%ÅêÂÚA100%ÅñÂÆ¯¶Êuj
		void M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR &, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_QUATERNION_H_FILE


