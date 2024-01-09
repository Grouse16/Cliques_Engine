//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンの情報の構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>
#include <string>


// ☆ ネームスペース ☆ //
namespace ASSET::ANIMATION::BONE
{
	// ☆ クラス ☆ //

	// ボーンの情報の構造体
	struct S_Bone_Inform
	{
		// ☆ 変数宣言 ☆ //
		DirectX::XMFLOAT4X4 offset_matrix = DirectX::XMFLOAT4X4();	// オフセットマトリクス行列

		std::string bone_name = "default";	// ボーン名

		std::vector<int> children_bone_index_list;	// 子ボーンのインデックスのリスト

		int parent_bone_index = -1;	// 親ボーンのインデックス
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
