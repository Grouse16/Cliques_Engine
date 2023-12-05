//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12に使用する定数をまとめた列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE
#define D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE


// ☆ ネームスペース ☆ //

// DX12システムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12
{
	// ☆ 定数 ☆ //

	// DX12用の定数の列挙
	enum class E_DX12_PARAMATOR : int
	{
		e_RENDER_TARGET_BUFFER_SUM = 2,	// レンダー用画面数

		e_RED = 0,		// 赤の配列番号
		e_GREEN = 1,	// 緑の配列番号
		e_BLUE = 2,		// 青の配列番号
		e_ALPHA = 3,	// αの配列番号
		e_COLOR_SUM,	// 色の配列数
	};
}


#endif // !D_INCLUDE_GUARD_E_DX12_PARAMATOR_H_FILE

