//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点インデックスバッファを生成するための情報のデータの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_CREATE_INDEX_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_INDEX_BUFFER_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::API::CREATE
{
	// ☆ 構造体 ☆ //

	// 頂点インデックスバッファを生成するための情報の構造体
	struct S_Create_Index_Buffer_Inform
	{
		int index_sum = 0;		// インデックス数
	};
}


#endif // !D_INCLUDE_GUARD_S_CREATE_INDEX_BUFFER_INFORM_H_FILE

