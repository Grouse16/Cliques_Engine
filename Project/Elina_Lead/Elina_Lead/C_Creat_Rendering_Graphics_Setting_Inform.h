//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：描画パイプライン用情報を生成するための情報のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::GRAPHICS::CREAT
{
	// ☆ クラス ☆ //

	// 描画パイプライン用情報を生成するための情報のクラス
	class C_Creat_Rendering_Graphics_Setting_Inform
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		ASSET::SHADER::C_Shader_Setting shader_setting;	// シェーダー設定情報
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_RENDERING_GRAPHICS_SETTING_INFORM
