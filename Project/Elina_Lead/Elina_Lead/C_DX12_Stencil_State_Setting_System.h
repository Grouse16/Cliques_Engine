//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシル設定用のクラス
// 説明   ：深度ステンシルの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>


// ☆ ネームスペース ☆ //

// 深度ステンシル設定用システムの定義を呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// 深度ステンシルステート設定用のクラス
	class C_DX12_Stencil_State_Setting_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 深度ステンシルを無効にする時の設定　引数：パイプライン設定用情報
		static void M_Disabled_Depth_Stencil(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);


		//-☆- テスト設定 -☆-//

		// ステンシルテストを失敗しても続行する設定　引数：パイプラインの画面オプション設定用情報
		static void M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
