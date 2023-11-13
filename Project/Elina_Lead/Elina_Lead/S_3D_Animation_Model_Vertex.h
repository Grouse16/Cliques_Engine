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
	// ☆ 定数 ☆ //
	constexpr int con_BONE_WEIGHT_INDEX_SUM = 4;	// 登録できるボーンウェイト情報数（GPUのメモリの扱い的にボーンウェイトは４つで扱うのが最も効率がいい）


	// ☆ 構造体 ☆ //

	// ボーンのウェイト情報の構造体
	struct S_Bone_Weight
	{
		int bone_index = 0;	// ボーンのインデックス番号

		float weight = 0.0f;	// ボーンのウェイト値（影響量）
	};


	// アニメーション用頂点データの構造体
	struct S_3D_Animation_Model_Vertex
	{
		MATH::FORMAT::C_Float_3 vertex;	// 頂点座標

		MATH::FORMAT::C_Float_2 uv;	// UV座標

		DATA::COLOR::C_Color color;	// カラー

		MATH::FORMAT::C_Float_3 normal;	// 法線ベクトル

		MATH::FORMAT::C_Float_3 tangent;	// タンジェントベクトル（接線）

		MATH::FORMAT::C_Float_3 binormal_tangent;	// バイノーマルタンジェントベクトル（従法線）

		S_Bone_Weight bone_weight[con_BONE_WEIGHT_INDEX_SUM];	// ボーンウェイト情報
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE
