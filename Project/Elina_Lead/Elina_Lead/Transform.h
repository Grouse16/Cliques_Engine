//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：オブジェクトの座標、回転、大きさの設定
// 説明   ：名前をトランスフォームとする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_TRANSFORM_H_FILE
#define D_INCLUDE_GUARD_TRANSFORM_H_FILE


// ☆ ネームスペース ☆ //

// 数学系統のシステムを呼び出すための名前
namespace MATH
{
	// ☆ クラス ☆ //

	// トランスフォーム
	class Transform
	{
	public:

		float position;

	};
}


#endif // !D_INCLUDE_GUARD_TRANSFORM_H_FILE
