//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：パイプラインステートの状態を受け取るためのキャッシュ用のシステムの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Cached_PSO_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::DX12::DX12_TOOL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ストリーミング出力用バッファを使用しない時の初期化を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Cached_PSO_Base::M_Cashe_Nothing(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // パイプラインの状態を受け取るキャッシュのアドレス
    in_pso_desc.CachedPSO.pCachedBlob = nullptr;

    // パイプラインの状態を受け取るキャッシュのサイズ
    in_pso_desc.CachedPSO.CachedBlobSizeInBytes = 0;

    // デバッグモードにするかどうかのフラグ
    in_pso_desc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

	return;
}
