//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：キーフレーム情報の構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE
#define D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// アニメーションデータを呼び出すための名前
namespace ASSET::ANIMATION::DATA
{
	// ☆ 構造体 ☆ //

	// キーフレーム情報
	struct S_Key_Frame
	{
		DirectX::XMFLOAT3 key_value = DirectX::XMFLOAT3();	// キー値

		float time_of_frame = 0.0f;	// フレームの時間
	};


	// 回転用のキーフレーム情報
	struct S_Rotation_Key_Frame
	{
		DirectX::XMFLOAT4 quaternion;	// クォータニオン値

		float time_of_frame = 0.0f;	// フレームの時間

	};	// 回転のみクオータニオンで四つ要素があるため分けている
}


#endif // !D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE
