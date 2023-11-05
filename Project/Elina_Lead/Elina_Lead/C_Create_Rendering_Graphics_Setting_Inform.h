//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：描画パイプライン用情報を生成するための情報のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"
#include "E_BLEND_MODE.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rasterizer_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rendering_Another_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::GRAPHICS::CREATE
{
	// ☆ クラス ☆ //

	// 描画パイプライン用情報を生成するための情報のクラス
	class C_Create_Rendering_Graphics_Setting_Inform
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 構造体 ☆ //
		
		// 深度ステンシル設定を生成するためのデータの構造体
		struct S_Depth_Stencil_Create_Data
		{
			RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE mode = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;	// 深度のモード

			RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE write_rule = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT;	// 深度値書き込みルール

			RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS stencil_activate = RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE;	// ステンシルを有効にするかどうか
		};

		// ラスタライザ設定を生成するためのデータの構造体
		struct S_Rasterizer_Create_Data
		{
			RENDERING::INFORM::RASTERIZER::E_DRAW_MODE draw_mode = RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL;	// オブジェクト描画モード

			RENDERING::INFORM::RASTERIZER::E_MESH_CULLING mesh_culling = RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT;	// カリング時に残る面を表裏で決める

			RENDERING::INFORM::RASTERIZER::E_MESH_FRONT mesh_front = RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE;	// 面の表向きを決める時の頂点の描画順

			RENDERING::INFORM::RASTERIZER::E_ANTIALIASING antialiasing = RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT;	// アンチエイリアシングのモード

			RENDERING::INFORM::RASTERIZER::S_Depth_Setting_Value depth_value;	// 深度情報設定用の値
		};

		// その他設定を生成するためのデータの構造体
		struct S_Another_Setting_Create_Data
		{
			std::vector<RENDERING::INFORM::BLEND_MODE::E_BLEND_MODE> blend_mode;	// ブレンドモード

			RENDERING::INFORM::SETTING::E_RENDERING_DRAW_FORMAT draw_format = RENDERING::INFORM::SETTING::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;	// 描画時の書き込み形式

			RENDERING::INFORM::SETTING::E_RENDERING_DRAW_COLOR draw_color = RENDERING::INFORM::SETTING::E_RENDERING_DRAW_COLOR::e_RGBA;	// 書き込むときの色数
			
			RENDERING::INFORM::SETTING::S_Sampling_Setting_Inform sampling_setting;	// サンプリングの設定
		};


		// ☆ 変数宣言 ☆ //
		ASSET::SHADER::C_Shader_Setting * shader_setting;	// シェーダー設定情報

		S_Depth_Stencil_Create_Data depth_stencil_data;	// 深度ステンシルの生成用データ

		S_Rasterizer_Create_Data rasterizer_data;	// ラスタライザ設定の生成用データ

		S_Another_Setting_Create_Data another_data;	// その他で設定するデータ
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM
