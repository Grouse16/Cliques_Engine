//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力判定をとるボックス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Engine_Input_Collision_Box.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INPUT::COLLISION;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Collision_Box::C_Engine_Input_Collision_Box(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Collision_Box::~C_Engine_Input_Collision_Box(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：四角形の当たり判定を設定する
// 引数   ：const S_Rect & 設定する当たり判定の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision_Box::M_Set_Collision_Box(const DATA::RECTSETTING::S_Rect & in_set_rect)
{
	mpr_variable.collision_rect = in_set_rect;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：四角形の当たり判定の参照を取得する
// 引数   ：void
// 戻り値 ：const S_Rect & 現在の当たり判定の参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const DATA::RECTSETTING::S_Rect & C_Engine_Input_Collision_Box::M_Get_Collision_Box(void)
{
	return mpr_variable.collision_rect;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：四角形の当たり判定の参照を取得する
// 引数   ：void
// 戻り値 ：const S_Rect & 現在の当たり判定の参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Engine_Input_Collision_Box::M_Collision_To_Pixel(int in_x, int in_y) const
{
	return(mpr_variable.collision_rect.left_x <= in_x) * (in_x <= mpr_variable.collision_rect.right_x)
		* (mpr_variable.collision_rect.bottom_y <= in_y) * (in_y <= mpr_variable.collision_rect.top_y);
}


