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

#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// 深度ステンシル設定用システムの定義を呼び出すための名前
namespace RENDERING::API::DX12::DX12_TOOL
{
	// ☆ クラス ☆ //

	// 深度ステンシルステート設定用のクラス
	class C_DX12_Stencil_State_Setting_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 指定された情報と一致した深度値の書き込み方法を返す　引数：深度値書き込みルール　戻り値：深度値の書き込み方法
		static D3D12_COMPARISON_FUNC M_Get_Depth_Write_Option(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE);

		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 設定 -☆-//

		// 深度ステンシルを生成用情報をもとに設定する　引数：パイプライン設定用情報, レンダリング生成用情報(const)
		static void M_Depth_Stencil_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform &);


		//-☆- テスト設定 -☆-//

		// ステンシルテストを失敗しても続行する設定　引数：パイプラインの画面オプション設定用情報
		static void M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC&);
	};
}


#endif // !D_INCLUDE_GUARD_C_STENCIL_STATE_SETTING_SYSTEM_H_FILE
