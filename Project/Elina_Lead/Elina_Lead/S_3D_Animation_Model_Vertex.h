//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーション用の頂点データの構造体
// 説明   ：アニメーションする3Dモデルに必要な頂点データのみをまとめた構造体
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE


// ☆ ファイルひらき ☆ //
#include "Color_Data.h"
#include "C_Float_4.h"
#include "C_Float_3.h"
#include "C_Float_2.h"


// ☆ ネームスペース ☆ //

// 頂点データを呼び出すための名前
namespace DATA::VERTEX
{
	// ☆ 構造体 ☆ //	

	// アニメーション用頂点データの構造体
	struct S_3D_Animation_Model_Vertex
	{
		MATH::FORMAT::C_Float_3 vertex;	// 頂点座標

		MATH::FORMAT::C_Float_2 uv;	// UV座標

		DATA::COLOR::C_Color color;	// カラー

		MATH::FORMAT::C_Float_3 normal;	// 法線ベクトル

		MATH::FORMAT::C_Float_3 tangent;	// タンジェントベクトル（接線）

		MATH::FORMAT::C_Float_3 binormal_tangent;	// バイノーマルタンジェントベクトル（従法線）

		int bone_index[4] = { 0, 0, 0, 0 };	// ボーンのインデックスのリスト

		MATH::FORMAT::C_Float_4 bone_weight;	// ウェイト値（ボーンからの影響量）
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE
