//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ブレンドステート設定用のクラス
// 説明   ：ブレンドステートの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>

#include "C_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// ブレンドステート設定用システムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //
	class C_DX12_Blend_State_Setting_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 指定された情報をもとにブレンドの設定を行う　引数：設定先のパイプラインステート, レンダリング設定生成用の情報(const)
		static void M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & , const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & );
	};
}


#endif // !D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
