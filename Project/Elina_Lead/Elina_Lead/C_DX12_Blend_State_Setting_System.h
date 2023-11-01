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

		// 全ての色を加算として扱い、論理操作をしない、マスクを掛けない
		static void M_Set_All_Color_Add_Blend_To_PSO(D3D12_GRAPHICS_PIPELINE_STATE_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
