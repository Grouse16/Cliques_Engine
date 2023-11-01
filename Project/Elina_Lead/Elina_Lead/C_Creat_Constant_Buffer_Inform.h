//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファを生成するための情報のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREAT_CONSTANT_BUFFER_INFORM
#define D_INCLUDE_GUARD_C_CREAT_CONSTANT_BUFFER_INFORM


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::GRAPHICS::CREAT
{
	// ☆ クラス ☆ //

	// 定数バッファを生成するための情報のクラス
	class C_Creat_Constant_Buffer_Inform
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		int m_list_size = 1;	// 定数バッファの配列数
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_CONSTANT_BUFFER_INFORM
