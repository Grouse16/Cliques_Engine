//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：モデルの描画設定用のシステム
// 説明   ：描画に使用するマテリアルとそのマテリアルで描画するメッシュ一覧を持つ
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE
#define D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Material_User.h"


// ☆ ネームスペース ☆ //

// モデル用のシステムを呼び出すための名前
namespace ASSET::MODEL_SYSTEM
{
	// ☆ 列挙 ☆ //

	// モデルの描画オプションを指定する列挙
	enum class E_MODEL_DRAW_OPTION : char
	{
		e_NATURAL_DRAW,			// 通常描画
		e_MATERIAL_ORIGINAL,	// マテリアルをセットして描画
		e_SELECT_MESH,			// メッシュを指定して描画
		e_SELECT_MESH_AND_MATERIAL_ORIGINAL,	// メッシュを指定したうえでマテリアルをセットして描画
	};


	// ☆ 構造体 ☆ //

	// モデルの描画設定
	struct S_Model_Draw_Command
	{
		ASSET::MATERIAL::C_Material_User material_data;	// 描画に使うマテリアルのデータ

		std::vector<std::string> mesh_name_list;	// このマテリアルで描画するメッシュ名のリスト

		E_MODEL_DRAW_OPTION model_draw_option = E_MODEL_DRAW_OPTION::e_NATURAL_DRAW;	// モデルの描画方法を指定するフラグ
	};
}


#endif // !D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE

