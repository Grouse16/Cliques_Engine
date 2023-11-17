//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：機能の優先度設定を行うための空間
// 説明   ：更新の優先度や描画の優先度を設定する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_FUNCTION_PRIORITY_SETTING_H_FILE
#define D_INCLUDE_GUARD_FUNCTION_PRIORITY_SETTING_H_FILE


// ☆ ネームスペース ☆ //

// 機能の優先度の定義を呼び出すための名前
namespace GAME::FUNCTION::PRIOTRITY
{
	// ☆ 定数 ☆ //

	// シーン前の更新の優先度
	enum class E_Game_BEFORE_UPDATE_PRIORITY
	{
		// ☆ 特殊値 ☆ //
		e_INVALID = -1,	// 無効


		// ☆ 通常時更新 ☆ //
		e_ALL_TIME_1 = 0,	// 常時更新

		// ☆ 基本更新 ☆ //
		e_Game_FRAME_WORK,	// タブの更新


		// ☆ 下が一番優先度が高い ☆ //
	};


	// シーン後の更新の優先度
	enum class E_Game_AFTER_UPDATE_PRIORITY
	{
		// ☆ 特殊値 ☆ //
		e_INVALID = -1,	// 無効

		// ☆ 通常時更新 ☆ //
		e_ALL_TIME_1 = 0,	// 常時更新
	};


	// シーン処理後の描画の優先度
	enum class E_BEFORE_Game_DRAW_PRIORITY
	{
		// ☆ 特殊値 ☆ //
		e_INVALID = -1,	// 無効

		// ☆ 自由画面優先度 ☆ //	// ここから先は自由に番号を振れる
		e_SCREEN_1 = 0,	// 自由な描画の優先度1
		
		// ☆ 下が一番上に表示される ☆ //
	};


	// シーン処理後の描画の優先度
	enum class E_AFTER_Game_DRAW_PRIORITY
	{
		// ☆ 特殊値 ☆ //
		e_INVALID = -1,	// 無効

		// ☆ 自由画面優先度 ☆ //	// ここから先は自由に番号を振れる
		e_SCREEN_1 = 0,	// 自由な描画の優先度1
		e_SCREEN_2,		// 自由な描画の優先度2
		e_SCREEN_3,		// 自由な描画の優先度3
		e_SCREEN_4,		// 自由な描画の優先度4
		e_SCREEN_5,		// 自由な描画の優先度5
		e_SCREEN_6,		// 自由な描画の優先度6
		e_SCREEN_7,		// 自由な描画の優先度7
		e_SCREEN_8,		// 自由な描画の優先度8
		e_SCREEN_9,		// 自由な描画の優先度9
		e_SCREEN_10,	// 自由な描画の優先度10
		e_SCREEN_11,	// 自由な描画の優先度11
		e_SCREEN_12,	// 自由な描画の優先度12
		e_SCREEN_13,	// 自由な描画の優先度13
		e_SCREEN_14,	// 自由な描画の優先度14
		e_SCREEN_15,	// 自由な描画の優先度15
		e_SCREEN_16,	// 自由な描画の優先度16
		e_SCREEN_17,	// 自由な描画の優先度17
		e_SCREEN_18,	// 自由な描画の優先度18
		e_SCREEN_19,	// 自由な描画の優先度19
		e_SCREEN_20,	// 自由な描画の優先度20

		e_Game_FRAME_WORK,	// 基本フレーム枠部分

		// ☆ 下が一番上に表示される ☆ //
	};
}


#endif // !D_INCLUDE_GUARD_FUNCTION_LAYERS_H_FILE
