//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：質感情報用のデータ
// 説明   ：シェーダー定義などマテリアル設定をMaterial　質感情報をMaterial_Detailとする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
#define D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Float_4.h"


// ☆ ネームスペース ☆ //

// 質感情報の定義を呼び出すための名前
namespace DATA::MATERIAL_DETAIL
{
	// ☆ 構造体 ☆ //

	// 質感情報の構造体
	struct S_Material_Detail
	{
		MATH::FORMAT::C_Float_4 ambient;		// アンビエント
		MATH::FORMAT::C_Float_4 diffuse;		// ディフューズ
		MATH::FORMAT::C_Float_4 emission;		// エミッション
		MATH::FORMAT::C_Float_4 reflection;		// リフレクション
		MATH::FORMAT::C_Float_4 specular;		// スペキュラー
		MATH::FORMAT::C_Float_4 transparent;	// トランスペアレント
	};
}


#endif // !D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
