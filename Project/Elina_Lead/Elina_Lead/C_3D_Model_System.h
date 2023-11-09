//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルのクラス
// 説明   ：3Dモデルの取得から描画、アニメーションの実行までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>
#include <string>

#include "C_Mesh_Data.h"


// ☆ ネームスペース ☆ //

// 3Dモデルを呼び出すための名前
namespace ASSET::MODEL
{
	// ☆ クラス ☆ //

	// 3Dモデルのクラス
	class C_3D_Model_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// メッシュを管理するためのデータの構造体
		struct S_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::MESH::C_Mesh_Data> mesh_list = nullptr;	// メッシュデータ

			std::string mesh_name = "default";	// メッシュ名
		};


		// ☆ 変数宣言 ☆ //
		
		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Mesh_Data_Inform> mesh_inform_list;	// メッシュの管理用情報リスト
		};
	};
}

#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
