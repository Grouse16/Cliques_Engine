//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点情報を生成するための情報のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::GRAPHICS::CREATE
{
	// ☆ クラス ☆ //
	
	// 頂点情報を生成するための情報のクラス
	class C_Create_Vertex_Buffer_Inform
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		int size_of_vertex = 0;	// 頂点一つ分のサイズ
		int vertex_sum = 0;		// 頂点数
		int index_sum = 0;		// インデックス数
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE
