//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：２バイトの色を定義する構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE
#define D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE


// ☆ ファイルひらき ☆ //
#include <directxpackedvector.h>

#include "C_Color.h"


// ☆ ネームスペース ☆ //

// 色の定義を呼び出すための名前
namespace DATA::COLOR
{
	// ☆ クラス ☆ //

	// ２バイトの色を定義する構造体
	class C_Half_Color
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		DirectX::PackedVector::HALF m_r = 0;		// ２バイトの赤
		DirectX::PackedVector::HALF m_g = 0;		// ２バイトの緑
		DirectX::PackedVector::HALF m_b = 0;		// ２バイトの青
		DirectX::PackedVector::HALF m_a = 0;		// ２バイトのα


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Half_Color(void);

		// ０～１で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_Half_Color(float, float, float, float);

		// ０～２５５で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_Half_Color(int, int, int, int);

		// デストラクタ
		~C_Half_Color(void);


		//-☆- セッタ -☆-//

		// ０～１で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_1(float, float, float, float);

		// ０～２５５で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_255(int, int, int, int);


		//-☆- オペレーター -☆-//

		// 色同士の掛け算　引数：色情報　戻り値：色情報の掛け算結果
		C_Half_Color operator*(C_Half_Color);

		// 色を設定する　引数：色情報
		void operator=(C_Half_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_HALF_FLOAT_TEXTURE_H_FILE

