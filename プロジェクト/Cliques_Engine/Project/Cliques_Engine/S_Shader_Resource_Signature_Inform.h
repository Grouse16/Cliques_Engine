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
	// ☆ 列挙 ☆ //

	// リソースの種類
	enum class E_RESOURCE_KIND : char
	{
		e_CONSTANT_BUFFER,	// 定数バッファ
		e_TEXTURE,			// テクスチャ
	};


	// ☆ 構造体 ☆ //

	// 定数バッファのリソース情報の構造体
	struct S_Constant_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類

		std::string resource_name = "default";	// 定数バッファの名前

		int array_sum = 0;	// 定数バッファの配列数

		bool flg_data_creation = false;	// データを生成するかどうかのフラグ

		int slot_number = 0;	// スロット番号
	};


	// テクスチャバッファのリソース情報の構造体
	struct S_Texture_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類

		std::string resource_name = "default";	// テクスチャの名前
		std::string initialize_texture_name = "default";	// 初期ロードするテクスチャ名

		int slot_number = 0;	// スロット番号
	};


	// レンダリング画面のリソース情報の構造体
	struct S_Screen_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類

		std::string resource_name = "default";	// テクスチャの名前

		int slot_number = 0;	// スロット番号
	};


	// 深度ステンシルのリソース情報の構造体
	struct S_Depth_Stencil_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類

		std::string resource_name = "default";	// テクスチャの名前

		int slot_number = 0;	// スロット番号
	};


	// サンプラーのリソース情報の構造体
	struct S_Sampler_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類

		std::string uv_setting = "";	// UVの使用方法
	};


	// スロットの情報の構造体
	struct S_Resource_Slot_Inform
	{
		E_RESOURCE_KIND resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;	// リソースの種類

		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類
	};


	// リソースの情報をまとめた構造体
	struct S_Resource_Inform_List
	{
		std::vector<S_Constant_Resource_Inform> constant_list;	// 定数バッファの情報リスト

		std::vector<S_Texture_Resource_Inform> texture_list;	// テクスチャの情報リスト

		std::vector<S_Screen_Resource_Inform> screen_list;	// レンダリング画面の情報リスト

		std::vector<S_Depth_Stencil_Resource_Inform> depth_stencil_list;	// 深度ステンシルの情報リスト

		std::vector<S_Sampler_Resource_Inform> sampler_list;	// サンプラーの情報リスト

		std::vector<S_Resource_Slot_Inform> slot_list;	// スロットの情報リスト
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

