//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーション用のメッシュのクラス
// 説明   ：アニメーションブレンド用の定数バッファを持つシステムを追加したメッシュシステムクラス
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
		std::string bone_name = "default";	// ボーン名

		DirectX::XMFLOAT4X4 offset_matrix = DirectX::XMFLOAT4X4();	// オフセットマトリクス行列
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
