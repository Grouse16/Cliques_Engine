//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ブレンドステート設定用のクラス
// 説明   ：ブレンドステートの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Blend_State_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆//

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報をもとにブレンドの設定を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & 設定先のパイプラインステート, const C_Creat_Rendering_Graphics_Setting_Inform & レンダリング設定生成用の情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_inform)
{
	// ☆ 定数 ☆ //
	const char con_RENDER_TARGET_SUM = 8;	// 設定可能なレンダーターゲット数

	
	// ☆ 変数宣言 ☆ //
	int use_render_target_sum = in_creat_inform.another_data.blend_mode.size() > con_RENDER_TARGET_SUM * con_RENDER_TARGET_SUM + in_creat_inform.another_data.blend_mode.size() <= con_RENDER_TARGET_SUM * in_creat_inform.another_data.blend_mode.size();	// 使用するレンダーターゲット数


	// レンダーターゲット数分のブレンド設定を行う
	for (int l_now_render_target_setting = 0; l_now_render_target_setting < use_render_target_sum; l_now_render_target_setting++)
	{
		switch (in_creat_inform.another_data.blend_mode[l_now_render_target_setting])
		{
			// 通常通りの描画
		case RENDERING::INFORM::BLEND_MODE::E_BLEND_MODE::e_NORMAL:

			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting];

			break;
		}
	}

	return;
}
