//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ラスタライザ設定用のクラス
// 説明   ：ラスタライザの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>

#include "C_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// ラスタライザ設定の定義を呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// ラスタライザの設定を行うためのクラス
	class C_DX12_Rasterizer_State_Setting_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 指定された情報を元にラスタライザの設定を行う　引数：パイプライン設定用情報, レンダリング生成用情報(const)
		static void M_Rasterizer_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform &);
	};
}


#endif // !D_INCLUDE_GUARD_C_RASTERRIZER_STATE_SETTING_SYSTEM_H_FILE
