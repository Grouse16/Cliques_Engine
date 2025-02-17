//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンのウェイト情報の構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_BONE_WEIGHT_H_FILE
#define D_INCLUDE_GUARD_S_BONE_WEIGHT_H_FILE


// ☆ ネームスペース ☆ //

// ボーン系の情報を呼び出すための名前
namespace ASSET::ANIMATION::BONE
{
	// ☆ 構造体 ☆ //

	// ボーンのウェイト情報の構造体
	struct S_Bone_Weight
	{
		int bone_index = 0;	// ボーンのインデックス番号

		float weight = 0.0f;	// ボーンのウェイト値（影響量）
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
