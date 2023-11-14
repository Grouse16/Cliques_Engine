//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンのキーの情報の配列の構造体
// 説明   ：キーのリストはそれぞれ総数が異なることがあるので、分けた配列で管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE
#define D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "S_Key_Frame.h"


// ☆ ネームスペース ☆ //

// ボーンの情報を呼び出すための名前
namespace ASSET::ANIMATION::BONE
{
	// ☆ 構造体 ☆ //

	// ボーンのキーの情報の配列の構造体
	struct S_Bone_Key_Frame_List
	{
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> position_key_list;	// 位置座標のキーのリスト
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> scale_key_list;	// スケールのキーのリスト

		std::vector<ASSET::ANIMATION::DATA::S_Quaternion_Key_Frame> quaternion_key_list;	// クォータニオン（回転情報）のキーのリスト
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE

