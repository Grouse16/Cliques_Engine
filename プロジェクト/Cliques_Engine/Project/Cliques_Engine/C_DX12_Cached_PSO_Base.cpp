////
// Ú×   FpCvCXe[gÌóÔðó¯æé½ßÌLbVpÌVXeÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_DX12_Cached_PSO_Base.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_TOOL;


//  Ö  //

//== pubN ==//

//-- Ýè --//

//===============//
// Ú×   FXg[~OoÍpobt@ðgpµÈ¢Ìú»ðs¤
// ø   FD3D12_GRAPHICS_PIPELINE_STATE_DESC & pCvC¶¬pîñ
// ßèl Fvoid
//===============//
void C_DX12_Cached_PSO_Base::M_Cache_Nothing(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // pCvCÌóÔðó¯æéLbVÌAhX
    in_pso_desc.CachedPSO.pCachedBlob = nullptr;

    // pCvCÌóÔðó¯æéLbVÌTCY
    in_pso_desc.CachedPSO.CachedBlobSizeInBytes = 0;

    // fobO[hÉ·é©Ç¤©ÌtO
    in_pso_desc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

	return;
}
