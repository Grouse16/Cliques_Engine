//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンのデータのクラス
// 説明   ：設定された情報をマトリクスに変換することも行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_BONE_DATA_H_FILE
#define D_INCLUDE_GUARD_C_BONE_DATA_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>

// ☆ ネームスペース ☆ //

// ボーンのシステムを呼び出すための名前
namespace ASSET::ANIMATION::BONE
{
	// ☆ クラス ☆ //

	// ボーンのデータのクラス
	class C_Bone_Data
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		DirectX::XMFLOAT3 position;	// 位置座標
		DirectX::XMFLOAT3 scale;	// スケール

		DirectX::XMVECTOR quaternion = DirectX::XMQuaternionIdentity();	// クォータニオン（回転情報）


		// ☆ 関数 ☆ //

		//-☆- マトリクス -☆-//

		// 現在のボーン情報をマトリクスに変換した値を引数にセットする　引数：設定先のマトリクス情報の参照
		void M_Set_Bone_Matrix_Data(DirectX::XMFLOAT4X4 & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_BONE_DATA_H_FILE
