////
// Ú×   FCX^Xª£XgÌSÄÌ³ÆÈéîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_LIST_ALL_BASE
#define D_INCLUDE_GUARD_C_LIST_ALL_BASE


//  t@CÐç«  //
#include <vector>


//  l[Xy[X  //

// CX^Xª£XgÌSÄÌ³ÆÈéîêNXðÄÑo·½ßÌ¼O
namespace SYSTEM::LIST::BASE::ALL_LIST_BASE
{
	//  NX  //

	// CX^Xª£XgÌSÄÌ³ÆÈéîêNX
	class C_List_All_Base
	{
		//== veNg ==//
	protected:

		//  Ïé¾  //
		std::vector<int> m_priority_list;	// DæxÌXg


		//  Ö  //

		//-- Qb^ --//

		// DæxÌXgðÔ·@ßèlFvector<int> & DæxÌXg
		std::vector<int> & M_Get_Priority_List(void);


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_List_All_Base(void);

		// fXgN^
		virtual ~C_List_All_Base(void);


		//-- XV --//

		// XgàÌCX^XÌXVðs¤
		virtual void M_Instance_Update(void) = 0;


		//-- `æ --//

		// XgàÌCX^XÌ`æðs¤
		virtual void M_Instance_Draw(void) = 0;


		//-- í --//

		// êÌCX^XÌíðs¤
		virtual void M_Delete_Instance_Execute(void) = 0;

		// åªÌCX^XÌíðs¤
		virtual void M_Delete_Most_OF_Instance_Execute(void) = 0;

		// SÄÌCX^XÌíðs¤
		virtual void M_Delete_All_Instance_Execute(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_LIST_ALL_BASE

