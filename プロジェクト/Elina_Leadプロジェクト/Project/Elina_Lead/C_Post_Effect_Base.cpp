//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ポストエフェクトの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆　ファイルひらき ☆ //
#include "C_Post_Effect_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE::POST_EFFECT::BASE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Post_Effect_Base::C_Post_Effect_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Post_Effect_Base::~C_Post_Effect_Base(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI描画前にポストエフェクトを描画するかどうかのフラグをセットする
// 引数   ：bool trueで描画する、falseは描画しない
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_Before_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_before_ui = in_set_draw_flg;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI描画後にポストエフェクトを描画するかどうかのフラグをセットする
// 引数   ：bool trueで描画する、falseは描画しない
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Base::M_Set_Flg_Post_Effect_After_UI_Draw(bool in_set_draw_flg)
{
	m_flg_draw_after_ui = in_set_draw_flg;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI描画前にポストエフェクトを描画するかどうかのフラグを返す
// 引数   ：void
// 戻り値 ：bool trueで描画する、falseは描画しない
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_Before_UI_Draw(void)
{
	return m_flg_draw_before_ui;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI描画後にポストエフェクトを描画するかどうかのフラグを返す
// 引数   ：void
// 戻り値 ：bool trueで描画する、falseは描画しない
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Post_Effect_Base::M_Get_Flg_Post_Effect_After_UI_Draw(void)
{
	return m_flg_draw_after_ui;
}
