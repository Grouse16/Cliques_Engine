//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：パイプラインステートの状態を受け取るためのキャッシュ用のシステムの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CACHED_PSO_BASE
#define D_INCLUDE_GUARD_C_CACHED_PSO_BASE


// ☆ ファイルひらき ☆//
#include <d3d12.h>


// ☆ ネームスペース ☆ //

// パイプラインステートの状態を受け取るためのキャッシュ用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// パイプラインステートの状態を受け取るためのキャッシュ用のシステムの基底クラス
	class C_DX12_Cached_PSO_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// キャッシュを受け取らない時の設定を行う　引数：パイプライン設定用情報
		static void M_Cashe_Nothing(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_CACHED_PSO_BASE
