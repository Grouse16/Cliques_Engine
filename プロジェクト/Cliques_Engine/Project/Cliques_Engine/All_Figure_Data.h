//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：図形定義用のファイル
// 説明   ：あらゆる図形を定義する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE
#define D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE


// ☆ ファイルひらき ☆ //
#include "2D_Position_Data.h"
#include "Figure_Base_Data.h"


// ☆ ネームスペース ☆ //

// 2D用の図形の定義を呼び出すための名前
namespace DATA::FIGURE::_2D
{
	// 2Dの円の基底となるクラス
	class C_2D_Circle : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //

		// 変数をまとめた構造体
		struct S_Variable
		{
			DATA::POSITION_2D::C_2D_Position vertex_center;	// 中心点

			float radius = 0.0f;	// 半径

		} m_variable;	// 変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_2D_Circle(void) { return; }

		// デストラクタ
		~C_2D_Circle(void) { return; }
	};


	// 2Dの長方形の基底となるクラス
	class C_2D_Long_Box : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //

		// 変数をまとめた構造体
		struct S_Variable
		{
			DATA::POSITION_2D::C_2D_Position vertex_left_top;	// 左上頂点
			DATA::POSITION_2D::C_2D_Position vertex_right_bottom;	// 右下頂点

		} m_variable;	// 変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_2D_Long_Box(void) { return; }

		// デストラクタ
		~C_2D_Long_Box(void) { return; }
	};
}

#endif // !D_INCLUDE_GUARD_ALL_FIGURE_DATA_H_FILE

