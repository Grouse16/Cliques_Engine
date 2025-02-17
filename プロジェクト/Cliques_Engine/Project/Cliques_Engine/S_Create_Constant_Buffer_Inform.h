//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファを生成するための情報の構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREATE_CONSTANT_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_CONSTANT_BUFFER_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::API::CREATE
{
	// ☆ 構造体 ☆ //

	// 定数バッファを生成するための情報の構造体
	struct S_Create_Constant_Buffer_Inform
	{
		int m_list_size = 1;	// 定数バッファの配列数
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_CONSTANT_BUFFER_INFORM_H_FILE
