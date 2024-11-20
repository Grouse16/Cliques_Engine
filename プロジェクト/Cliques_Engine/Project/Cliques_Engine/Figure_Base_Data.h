//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：図形の基底となるクラス用のデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_FIGURE_BASE_DATA_H_FILE
#define D_INCLUDE_GUARD_FIGURE_BASE_DATA_H_FILE


// ☆ ネームスペース ☆ //

// 図形の基底クラスを呼び出すための名前
namespace DATA::FIGURE::BASE
{
	// ☆ クラス ☆ //

	// 図形の基底となるクラス
	class C_Figure_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Figure_Base(void) { return; }

		// デストラクタ
		virtual ~C_Figure_Base(void) { return; }
	};
}


#endif // !D_INCLUDE_GUARD_FIGURE_BASE_DATA_H_FILE
