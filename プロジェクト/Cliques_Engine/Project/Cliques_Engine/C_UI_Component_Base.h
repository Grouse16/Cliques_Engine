////
// Ú×   FUIÌR|[lgÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_UI_COMPONENT_BASE_H_FILE
#define D_INCLUDE_GUARD_C_UI_COMPONENT_BASE_H_FILE


//  l[Xy[X  //

// UIÌR|[lgÌîêNXðÄÑo·½ßÌ¼O
namespace GAME::UI_COMPONENT::BASE
{
	//  NX  //

	// UIÌR|[lgÌîêNX
	class C_UI_Component_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		bool m_flg_destroy_component = false;	// R|[lgðí·é


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_UI_Component_Base(void);

		// fXgN^
		virtual ~C_UI_Component_Base(void);


		//-- XV --//

		// R|[lgÌXV
		virtual void M_Update(void) = 0;


		//-- `æ --//

		// R|[lgÌ`æ
		virtual void M_Draw(void) = 0;


		//-- Qb^ --//

		// R|[lgðí·é©Ç¤©ÌtOðÔ·@ßèlFtrueÅí·éAfalseÅíµÈ¢
		bool M_Get_Component_Destroy_Flg(void);


		//-- í --//

		// R|[lgðí·étOð§Äé
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_UI_COMPONENT_BASE_H_FILE

