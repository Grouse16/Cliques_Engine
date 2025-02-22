////
// Ú×   Fèobt@pf[^ÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM


//  t@CÐç«  //
#include <vector>
#include <d3d12.h>
#include <wrl.h>

#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"


//  l[Xy[X  //

// DX12pÌVXeðÄÑo·½ßÌ¼O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	//  NX  //

	// èobt@pf[^ÌNX
	class C_DX12_Constant_Setting_Inform : public INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_constant_buffer_heap = nullptr;	// èobt@r[Ìq[vVXeiØ\¢ÇVXej

		Microsoft::WRL::ComPtr<ID3D12Resource> m_constant_buffer_data = nullptr;	// èf[^


		//-- I¹ --//

		// RXgN^
		C_DX12_Constant_Setting_Inform(void);

		// fXgN^
		virtual ~C_DX12_Constant_Setting_Inform(void);


		//-- Zb^ --//

		// èobt@Éwè³ê½îñðZbg·é@øFZbg·éf[^, zñ, Zbg·éf[^TCY
		void M_Set_Data_To_Buffer(void*, int, int) override;


		//-- Qb^ --//

		// èobt@Ìf[^ÌAhXðÔ·@gpªIíÁ½çK¸Close·é±Æ@ßèlFèobt@Ìf[^ÌAhX
		unsigned char * M_Get_Constant_Buffer_Data_Address(void) override;

		// èobt@Ìf[^ðgpI¹·é
		void M_Close_Constant_Buffer_Data_Address(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
