//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：メッシュのデータ管理用のシステムのクラス
// 説明   ：頂点や頂点インデックス情報の管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MESH_DATA_H_FILE
#define D_INCLUDE_GUARD_C_MESH_DATA_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Object_Vertex_System.h"


// ☆ ネームスペース ☆ //

// メッシュのシステムを呼び出すための名前
namespace ASSET::MESH
{
	// ☆ クラス ☆ //

	// メッシュのデータ管理用のシステムのクラス
	class C_Mesh_Data
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System 

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:
	};
}


#endif // !D_INCLUDE_GUARD_C_MESH_DATA_H_FILE

