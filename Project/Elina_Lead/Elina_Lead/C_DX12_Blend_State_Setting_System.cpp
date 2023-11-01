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
// 詳細   ：ウィンドウのサイズの更新を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプラインステートの生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Set_All_Color_Add_Blend_To_PSO(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // ☆ 変数宣言 ☆ //
    int sum_rendertarget = _countof(in_pso_desc.BlendState.RenderTarget);   // レンダーターゲット数


    // ブレンドステートを全て初期化
    for (int loop_x = 0; loop_x < sum_rendertarget; loop_x++)
    {
        // ☆ 状態設定 ☆ //

        // ブレンドの有効無効
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendEnable = TRUE;

        // 論理演算の有効無効（ブレンドとロジック両方を同時にTRUEにしてはならない）
        in_pso_desc.BlendState.RenderTarget[loop_x].LogicOpEnable = FALSE;


        // ☆ RGB値 ☆ //

        // ピクセルシェーダーが出力したRGB値の操作（上書きする色の操作の定義）
        in_pso_desc.BlendState.RenderTarget[loop_x].SrcBlend = D3D12_BLEND_SRC_ALPHA;

        // レンダーターゲットの今のRGB値の操作（上書きされる側の色の操作の定義）
        in_pso_desc.BlendState.RenderTarget[loop_x].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;

        // SRC(上書きする側)とDEST(上書きされる側)のRGB値を混ぜる方法
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendOp = D3D12_BLEND_OP_ADD;


        // ☆ α値 ☆ //

        // ピクセルシェーダーが出力したα値の操作（上書きする色の操作の定義）
        in_pso_desc.BlendState.RenderTarget[loop_x].SrcBlendAlpha = D3D12_BLEND_ONE;

        // レンダーターゲットの今のα値の操作（上書きされる側の色の操作の定義）
        in_pso_desc.BlendState.RenderTarget[loop_x].DestBlendAlpha = D3D12_BLEND_ZERO;

        // SRC(上書きする側)とDEST(上書きされる側)のα値を混ぜる方法
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendOpAlpha = D3D12_BLEND_OP_ADD;


        // ☆ 論理操作 ☆ //

        // レンダーターゲットに対する論理操作の指定
        in_pso_desc.BlendState.RenderTarget[loop_x].LogicOp = D3D12_LOGIC_OP_NOOP;


        // ☆ マスク ☆ //

        // ブレンド中に書き込み可能な色を指定する
        in_pso_desc.BlendState.RenderTarget[loop_x].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }


	return;
}
