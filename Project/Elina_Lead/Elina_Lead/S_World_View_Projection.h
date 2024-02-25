//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ワールド、ビュー、プロジェクション変換行列の定義
// 説明   ：３Dモデルを2Dスクリーン内で描画するためのデータ
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
#define D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// ワールド、ビュー、プロジェクション変換行列を呼び出すための名前
namespace MATH::WVP
{
	// ☆ 構造体 ☆ //

	// world view projection行列を整列して定義するための構造体
	struct S_World_View_Projection_Data
	{
		DirectX::XMMATRIX world = DirectX::XMMATRIX();		// ワールド変換行列
		DirectX::XMMATRIX view = DirectX::XMMATRIX();		// ビュー変換行列
		DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// プロジェクション変換行列
	};
}


#endif // !D_INCLUDE_GUARD_C_WORLD_VIEW_PROJECTION_H_FILE
