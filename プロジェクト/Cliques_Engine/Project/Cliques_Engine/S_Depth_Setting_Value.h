//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：奥行きの値の設定を行うための定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE
#define D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE


// ☆ ネームスペース ☆ //

// ラスタライザ定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::RASTERIZER
{
	// ☆ 構造体 ☆ //

	// 奥行きの値の設定を行うための構造体
	struct S_Depth_Setting_Value
	{
		int depth_bias = 0;		// 奥行き値

		float depth_max = 0.0f;		// 奥行きの最大値　0.0fで奥行き無効
		float depth_slope = 0.0f;	// 奥行き調整値
	};
}


#endif // !D_INCLUDE_GUARD_S_DEPTH_SETTING_VALUE_H_FILE

