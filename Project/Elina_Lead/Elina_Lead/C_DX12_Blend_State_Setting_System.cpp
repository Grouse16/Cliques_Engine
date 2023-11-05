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

//==☆ プライベート ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常描画時のブレンドを登録
// 引数   ：D3D12_RENDER_TARGET_BLEND_DESC & 登録先のブレンド設定
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Attach_Normal_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// ブレンドが有効か
	in_blend_setting.BlendEnable = true;

	// 論理操作が有効か無効か
	in_blend_setting.LogicOpEnable = false;

	
	//-☆- RGB色 -☆-//

	// ピクセルシェーダーの出力色の設定
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_SRC_COLOR;

	// レンダーターゲットの色の使用方法
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-☆- α値 -☆-//

	// ピクセルシェーダーの出力α値の設定
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_SRC_ALPHA;

	// レンダーターゲットのα値の使用方法
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;


	//-☆- 論理演算オプション -☆-//
	in_blend_setting.LogicOp = D3D12_LOGIC_OP_CLEAR;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常描画でα値のみ１固定のブレンドを登録
// 引数   ：D3D12_RENDER_TARGET_BLEND_DESC & 登録先のブレンド設定
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Attach_Normal_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// ブレンドが有効か
	in_blend_setting.BlendEnable = true;

	// 論理操作が有効か無効か
	in_blend_setting.LogicOpEnable = false;


	//-☆- RGB色 -☆-//

	// ピクセルシェーダーの出力色の設定
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_SRC_COLOR;

	// レンダーターゲットの色の使用方法
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-☆- α値 -☆-//

	// ピクセルシェーダーの出力α値の設定
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_ONE;

	// レンダーターゲットのα値の使用方法
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：減算方式の描画でブレンドを登録
// 引数   ：D3D12_RENDER_TARGET_BLEND_DESC & 登録先のブレンド設定
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Attach_Invert_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// ブレンドが有効か
	in_blend_setting.BlendEnable = true;

	// 論理操作が有効か無効か
	in_blend_setting.LogicOpEnable = false;


	//-☆- RGB色 -☆-//

	// ピクセルシェーダーの出力色の設定
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_INV_SRC_COLOR;

	// レンダーターゲットの色の使用方法
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-☆- α値 -☆-//

	// ピクセルシェーダーの出力α値の設定
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_INV_DEST_ALPHA;

	// レンダーターゲットのα値の使用方法
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：減算方式の描画でα値のみ１固定のブレンドを登録
// 引数   ：D3D12_RENDER_TARGET_BLEND_DESC & 登録先のブレンド設定
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Attach_Invert_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// ブレンドが有効か
	in_blend_setting.BlendEnable = true;

	// 論理操作が有効か無効か
	in_blend_setting.LogicOpEnable = false;


	//-☆- RGB色 -☆-//

	// ピクセルシェーダーの出力色の設定
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_INV_SRC_COLOR;

	// レンダーターゲットの色の使用方法
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-☆- α値 -☆-//

	// ピクセルシェーダーの出力α値の設定
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_ONE;

	// レンダーターゲットのα値の使用方法
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダーターゲットに書き込む時のフォーマットを生成用の情報から割り出して返す
// 引数   ：C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data & ブレンド設定の生成用データ(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DXGI_FORMAT RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Blend_State_Setting_System::M_Get_Write_Rendering_Graph_Format_By_Create_Inform(const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data & in_blend_setting)
{
	//-☆- 書き込む時の色数によって分岐 -☆-//
	switch (in_blend_setting.draw_color)
	{
		// Rのみ
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_R:

		// 書き込むデータの形式で分岐
		switch (in_blend_setting.draw_format)
		{
			// １バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8_UINT;

			// ２バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16_UINT;

			// ４バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32_UINT;

			// ２バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16_FLOAT;

			// ４バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
		}
		

		// RGのみ
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RG:

		// 書き込むデータの形式で分岐
		switch (in_blend_setting.draw_format)
		{
			// １バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8G8_UINT;

			// ２バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16_UINT;

			// ４バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32_UINT;

			// ２バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16_FLOAT;

			// ４バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
		}

		break;


		// RGBA全て
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA:
	default:

		// 書き込むデータの形式で分岐
		switch (in_blend_setting.draw_format)
		{
			// １バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UINT;

			// ２バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_UINT;

			// ４バイトのUINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_UINT;

			// ２バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;

			// ４バイトのFLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
		}

		break;
	}

	return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;
}


//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報をもとにブレンドの設定を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & 設定先のパイプラインステート情報, const C_Creat_Rendering_Graphics_Setting_Inform & レンダリング設定生成用の情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_inform)
{
	// ☆ 定数 ☆ //
	const char con_RENDER_TARGET_SUM = 8;	// 設定可能なレンダーターゲット数

	
	// ☆ 変数宣言 ☆ //
	int use_render_target_sum = in_creat_inform.blend_setting.size();	// 使用するレンダーターゲット数


	// レンダーターゲットの最大数を超えないようにする
	use_render_target_sum =
		use_render_target_sum > con_RENDER_TARGET_SUM * con_RENDER_TARGET_SUM
		+
		use_render_target_sum <= con_RENDER_TARGET_SUM * use_render_target_sum;


	// レンダーターゲット数分のブレンド設定を行う
	for (int l_now_render_target_setting = 0; l_now_render_target_setting < con_RENDER_TARGET_SUM; l_now_render_target_setting++)
	{
		//-☆- 指定されたブレンドのモードで設定内容を分岐 -☆-//
		switch (in_creat_inform.blend_setting[l_now_render_target_setting].blend_mode)
		{
			// 通常通りの描画
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL:
		default:
			M_Attach_Normal_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// 通常通りの描画でα値のみ１で固定
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL_NOT_ALPHA:
			M_Attach_Normal_And_One_Alpha_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// 減算方式の描画
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT:
			M_Attach_Invert_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// 減算方式の描画でα値のみ１で固定
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT_NOT_ALPHA:
			M_Attach_Invert_And_One_Alpha_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;
		}


		//-☆- 指定された混ぜ方でブレンドオプションの設定を分岐 -☆-//
		switch (in_creat_inform.blend_setting[l_now_render_target_setting].blend_option)
		{
			// ピクセルシェーダーの色を加算
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD:
		default:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_ADD;
			break;

			// ピクセルシェーダーの色を減算
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_SUBTRACT;
			break;

			// ピクセルシェーダーの色を現在の色で減算
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB_PIX:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_REV_SUBTRACT;
			break;

			// 現在の色とピクセルシェーダーの色を比較したときの最大値
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MAX:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_MAX;
			break;

			// 現在の色とピクセルシェーダーの色を比較したときの最大値
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MIN:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_MIN;
			break;
		}


		// レンダーターゲット画像に書き込むときのフォーマットを設定
		in_pipeline_state_desc.RTVFormats[l_now_render_target_setting] = M_Get_Write_Rendering_Graph_Format_By_Create_Inform(in_creat_inform.blend_setting[l_now_render_target_setting]);
	}


	// レンダーターゲットに送らないリソースはすべて初期値にする(しなければエラー)
	for (int l_now_format_setting = use_render_target_sum; l_now_format_setting < 8; l_now_format_setting++)
	{
		in_pipeline_state_desc.RTVFormats[l_now_format_setting] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	}

	return;
}
