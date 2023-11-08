//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデル用の頂点フォーマットの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Float_3.h"
#include "C_Float_2.h"


// ☆ ネームスペース ☆ //

// 頂点データ用システムを呼び出すための名前
namespace DATA::VERTEX
{
	// ☆ 構造体 ☆ //

	// 3Dモデル用の頂点情報のフォーマット
	struct S_3D_Model_Vertex
	{
		// ☆ 変数宣言 ☆ //
		MATH::FORMAT::C_Float_3 vertex;	// 頂点座標

		MATH::FORMAT::C_Float_2 uv;	// UV座標

		MATH::FORMAT::C_Float_3 normal;	// 法線ベクトル

		MATH::FORMAT::C_Float_3 tangent;	// タンジェントベクトル（接線）

		MATH::FORMAT::C_Float_3 binormal_tangent;	// バイノーマルタンジェントベクトル（従法線）
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
