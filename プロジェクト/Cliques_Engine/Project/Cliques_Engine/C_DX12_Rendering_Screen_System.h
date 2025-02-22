////
// Ú×   FDX12Ì_OXN[i_OææjÌVXe
// à¾   F_[^[Qbgr[ðÇ·é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE


//  t@CÐç«  //
#include <d3d12.h>
#include <wrl.h>
#include <vector>

#include "C_Rendering_Screen_Data_Base.h"
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


//  l[Xy[X  //

// DX12pÌVXeðÄÑo·½ßÌ¼O
namespace RENDERING::API::DX12::DX12_INSTANCE
{
    //  \¢Ì  //

	// _[^[QbgÌobt@ðè`·é\¢Ì
	struct S_DX12_Render_Target_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> render_buffer;	// _[æÌæÊobt@

		D3D12_CPU_DESCRIPTOR_HANDLE handle = D3D12_CPU_DESCRIPTOR_HANDLE();	// eNX`\[X¯Êpîñ(GPUÌ½ßÉ\[XðªðµÄÏ··é)

		D3D12_RESOURCE_STATES now_resource_barrier = D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_PRESENT;	// ±Ì\[XÌoAóÔ
	};


	// _[^[Qbgr[pÌ\¢Ì
	struct S_DX12_Render_Target_View
	{
		std::vector<S_DX12_Render_Target_Buffer> buffer_list;	// _[^[QbgÌobt@Xg

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// fXNv^ð®·é½ßÌØ\¢f[^VXe
	};


    //  NX  //

    // DX12Ì_OXN[ÌNX
	class C_DX12_Rendering_Screen_System : public RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base
    {
        //== pubN ==//
    public:

        //  Ïé¾  //
		S_DX12_Render_Target_View m_render_target_view;	// _[^[Qbgr[pp[^

		int m_rendering_screen_sum = 0;	// _OæÊ


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_DX12_Rendering_Screen_System(void);

		// fXgN^
		~C_DX12_Rendering_Screen_System(void) override;

		// Ìðú
		void M_Release(void) override;


		//-- æ --//

		// wè³ê½ÔÌ_OæÊðeNX`æÆµÄÛ¶·é@øF_OæÊÔ, Û¶æÌeNX`æÊÌQÆ@ßèlF¬÷ÌÝtrue
		bool M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & ) override;


		//-- Qb^ --//

		// _OæÊðÔ·@ßèlF_OæÊ
		int M_Get_Rendering_Screen_Sum(void) override;
    };
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE

