//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションのステータス定義用の構造体
// 説明   ：現在の時間、ブレンド率など、アニメーション計算に共通して必要な情報を設定
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE
#define D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE


// ☆ ネームスペース ☆ //

// アニメーション用のシステムを呼び出すための名前
namespace ASSET::ANIMATION
{
	// ☆ 構造体 ☆ //

	// アニメーションのステータス定義用の構造体
	struct S_Animation_Status
	{
		float animation_time = 0.0f;	// アニメーション時間
		float animation_blend = 0.0f;	// アニメーションブレンド率
	};
}


#endif // !D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE

