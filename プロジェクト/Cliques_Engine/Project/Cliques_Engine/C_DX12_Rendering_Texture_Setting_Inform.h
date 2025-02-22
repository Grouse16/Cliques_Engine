////
// Ú×   FDX12ÌeXN`ÌZbgpÌf[^ÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM


//  t@CĞç«  //
#include <wrl.h>
#include <d3d12.h>
#include <vector>

#include "E_Shader_Kind.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"


//  l[Xy[X  //

// DX12pÌVXeğÄÑo·½ßÌ¼O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	//  NX  //

	// DX12ÌeXN`ÌZbgpÌf[^ÌNX
	class C_DX12_Rendering_Texture_Setting_Inform : public INSTANCE::C_Rendering_Texture_Setting_Inform_Base
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_texture_heap;	// eNX`pq[v

		Microsoft::WRL::ComPtr<ID3D12Resource> m_texture_data;	// eNX`pf[^

		int m_pix_size_x = 0;	// eNX`ÌsNZTCYx
		int m_pix_size_y = 0;	// eNX`ÌsNZTCYy


		//-- I¹ --//

		// RXgN^
		C_DX12_Rendering_Texture_Setting_Inform(void);

		// fXgN^
		virtual ~C_DX12_Rendering_Texture_Setting_Inform(void);

		// ğğú·é
		void M_Delete(void);


		//-- XV --//

		// eNX`Ìf[^ğZbg·é@øFİè·éFzñÖÌQÆ, eNX`Ì¡, eNX`Ìc
		void M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> &, int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
