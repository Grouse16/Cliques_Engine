//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：スケールのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SCALE_H_FILE
#define D_INCLUDE_GUARD_C_SCALE_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// スケールのシステムを呼び出すための名前
namespace MATH::SCALE
{
	// ☆ クラス ☆ //

	// スケールのシステムのクラス
	class C_Scale
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		DirectX::XMFLOAT3 xyz = DirectX::XMFLOAT3();	// スケール値


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Scale(void);

		// デストラクタ
		~C_Scale(void);


		//-☆- ゲッタ -☆-//

		// 拡大縮小のマトリクスを生成して返す　戻り値：拡大縮小のマトリクス
		DirectX::XMMATRIX M_Get_Scale_Matrix(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCALE_H_FILE

