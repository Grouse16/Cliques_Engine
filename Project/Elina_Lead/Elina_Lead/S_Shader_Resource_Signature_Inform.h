//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーの識別名を管理するための構造体の宣言
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM
#define D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "E_Shader_Kind.h"


// ☆ ネームスペース ☆ //

// シェーダー用の定義を呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ 構造体 ☆ //

	// リソースの識別用の情報の構造体
	struct S_Resource_Signature
	{
		std::string signature_name = "";	// 識別用の名前
	};


	// シェーダーのリソースの識別名を管理するための構造体
	struct S_Shader_Resource_Signature_Inform
	{
		std::vector<S_Resource_Signature> constant_data;	// 定数バッファデータ識別用の情報

		std::vector<S_Resource_Signature> texture_data;	// テクスチャデータの識別用の情報

		int sampler_sum = 0;	// サンプラー数
	};


	// すべてのシェーダーのリソースの識別名をまとめるための構造体
	struct S_All_Shader_Resource_Signatures
	{
		S_Shader_Resource_Signature_Inform all_shader_signature;	// 全てのシェーダーに共通するリソース識別名

		S_Shader_Resource_Signature_Inform signature_list[(int)E_SHADER_KIND::e_ALL];	// シェーダーのリソース
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

