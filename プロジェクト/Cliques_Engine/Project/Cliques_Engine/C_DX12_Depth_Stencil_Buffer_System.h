////
// Ú×   FDX12Ì[xXeVobt@VXe
// à¾   F[xXeVobt@pÌf[^ðÇ·é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE


//  t@CÐç«  //
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include <d3d12.h>
#include <wrl.h>


//  l[Xy[X  //

// DX12pÌVXeðÄÑo·½ßÌ¼O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	//  \¢Ì  //

	// [xXeVÌobt@ðè`·é\¢Ì
	struct S_DX12_Depth_Stencil_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> depth_stencil_buffer;	// [xXeVpÌobt@

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// fXNv^ð®·é½ßÌØ\¢f[^VXe

		D3D12_CPU_DESCRIPTOR_HANDLE handle = D3D12_CPU_DESCRIPTOR_HANDLE();	// eNX`\[X¯Êpîñ(GPUÌ½ßÉ\[XðªðµÄÏ··é
	};


	//  NX  //

	// DX12Ì[xXeVobt@ÌNX
	class C_DX12_Depth_Stencil_Buffer_System : public RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		S_DX12_Depth_Stencil_Buffer m_data;	// [xXeVobt@pp[^
		

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_DX12_Depth_Stencil_Buffer_System(void);

		// fXgN^
		~C_DX12_Depth_Stencil_Buffer_System(void) override;

		// Ìðú
		void M_Release(void) override;


		//-- æ --//

		// [xXeVobt@æÊðeNX`æÆµÄÛ¶·é@øFÛ¶æÌeNX`æÊÌQÆ@ßèlF¬÷ÌÝtrue
		bool M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & ) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
