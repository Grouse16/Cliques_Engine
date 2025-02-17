//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サンプリング設定用のクラス
// 説明   ：サンプリング設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM
#define D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM


// ☆ ファイルひらき ☆ //
#include <d3d12.h>


// ☆ ネームスペース ☆ //

// サンプリング設定用の定義を呼び出すための名前
namespace RENDERING::API::DX12::DX12_TOOL
{
	// ☆ クラス ☆ //

	// サンプリング設定用のクラス
	class C_DX12_Sampling_Setting_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// サンプリング設定をまとめて行う　引数：パイプライン生成用情報,　サンプリング回数,　クオリティ,　ノード数
		static void M_Sampling_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC&, UINT, UINT, UINT);
	};
}


#endif // !D_INCLUDE_GUARD_C_SAMPLING_SETTING_SYSTEM
