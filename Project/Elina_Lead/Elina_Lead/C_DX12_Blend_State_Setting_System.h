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

#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// ブレンドステート設定用システムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //
	class C_DX12_Blend_State_Setting_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 通常描画時のブレンドを登録　引数：登録先のブレンド設定
		static void M_Attach_Normal_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// 通常描画でα値のみ１固定の時のブレンドを登録　引数：登録先のブレンド設定
		static void M_Attach_Normal_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// 減算方式での描画時のブレンドを登録　引数：登録先のブレンド設定
		static void M_Attach_Invert_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);

		// 減算方式での描画でα値のみ１固定の時のブレンドを登録　引数：登録先のブレンド設定
		static void M_Attach_Invert_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC &);


		//-☆- ゲッタ -☆-//

		// レンダーターゲットに書き込む時のフォーマットを生成用の情報から割り出して返す　引数：ブレンド設定の生成用データ(const)
		static DXGI_FORMAT M_Get_Write_Rendering_Graph_Format_By_Create_Inform(const RENDERING::GRAPHICS::CREATE::S_Blend_Setting_Create_Data & );


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 指定された情報をもとにブレンドの設定を行う　引数：設定先のパイプラインステート情報, レンダリング設定生成用の情報(const)
		static void M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & , const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform & );
	};
}


#endif // !D_INCLUDE_GUARD_C_BLEND_STATE_SETTING_SYSTEM_H_FILE
