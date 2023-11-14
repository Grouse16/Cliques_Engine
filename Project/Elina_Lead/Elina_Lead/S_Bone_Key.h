//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンのキーの情報の構造体
// 説明   ：キーフレームの最終的なアニメーションブレンド結果を受け取るための構造体
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_BONE_KEY_H_FILE
#define D_INCLUDE_GUARD_S_BONE_KEY_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "S_Key_Frame.h"


// ☆ ネームスペース ☆ //

// ボーンの情報を呼び出すための名前
namespace ASSET::ANIMATION::BONE
{
	// ☆ 構造体 ☆ //

	// ボーンのキーの情報の構造体
	struct S_Bone_Key
	{
		DirectX::XMFLOAT3 position_key;	// 位置座標のキー
		DirectX::XMFLOAT3 scale_key;	// スケールのキー

		DirectX::XMVECTOR quaternion_key = DirectX::XMQuaternionIdentity();	// クォータニオン（回転情報）のキー
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_KEY_H_FILE

