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
		float animation_blend_percent = 0.0f;	// アニメーションブレンド率
		float need_blend_time = 0.1f;	// アニメーションブレンド完了までの時間
		float animation_speed = 1.0f;	// アニメーション速度
		float passed_time = 0.0f;		// 経過時間

		const int bone_sum = 0;	// ボーン数

		bool flg_animation_end = false;		// アニメーションの終了
		bool flg_animation_reverse = false;	// アニメーションを逆再生するかどうか


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// 通常のコンストラクタを無効化
		S_Animation_Status(void) = delete;

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：ボーン数初期化用のコンストラクタ
		// 引数   ：int ボーン数
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		S_Animation_Status(int in_bone_sum) : bone_sum(in_bone_sum)
		{
			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE

