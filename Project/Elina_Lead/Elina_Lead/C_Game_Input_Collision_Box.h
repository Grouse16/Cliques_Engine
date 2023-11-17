//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力判定をとるボックス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Input_Collision_Manager.h"

#include "S_Rect.h"


// ☆ ネームスペース ☆ //

// ゲームの当たり判定の入力のシステムを呼び出すための名前
namespace GAME::INPUT::COLLISION
{
	// ☆ クラス ☆ //

	// ゲームの入力判定をとるボックス
	class C_Game_Input_Collision_Box : public GAME::INPUT::COLLISION::C_Game_Input_Collision
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			DATA::RECTSETTING::S_Rect collision_rect;	// 入力を受け付けるボックスの範囲
			
		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Game_Input_Collision_Box(void);

		// デストラクタ
		~C_Game_Input_Collision_Box(void) override;


		//-☆- セッタ -☆-//

		// 四角形の当たり判定を設定する　引数：設定する当たり判定の参照
		void M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect &);


		//-☆- ゲッタ -☆-//

		// 四角形の当たり判定の参照を取得する　戻り値：現在の当たり判定の参照(const)
		const DATA::RECTSETTING::S_Rect & M_Get_Collision_Box(void);


		//-☆- 当たり判定 -☆-//

		// 指定された座標と重なっているかどうか　引数：当たり判定の座標ｘ, 当たり判定の座標ｙ　戻り値：当たっていたらtrue
		bool M_Collision_To_Pixel(int, int) const override;
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_BOX_H_FILE


