//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ポストエフェクトの描画制御システム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Post_Effect_Draw_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER;


// ☆ スタティック変数 ☆ //
C_Post_Effect_Draw_Manager C_Post_Effect_Draw_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Post_Effect_Draw_Manager::C_Post_Effect_Draw_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Post_Effect_Draw_Manager::~C_Post_Effect_Draw_Manager(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UIの前に描画するポストエフェクトを描画リストに追加する
// 引数   ：C_Post_Effect_Base * 追加するポストエフェクト
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * in_add_post_effect)
{
	// UI描画前に描画しないポストエフェクトは描画リストに追加しない
	if (in_add_post_effect->M_Get_Flg_Post_Effect_Before_UI_Draw() == false)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	int set_post_effect_slot = (int)m_this.mpr_variable.post_effect_before_ui_list.size();	// ポストエフェクトの追加先スロット


	// ポストエフェクトを描画リストに追加
	m_this.mpr_variable.post_effect_before_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_before_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UIの前に描画するポストエフェクトを描画リストに追加する
// 引数   ：C_Post_Effect_Base * 追加するポストエフェクト
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Draw_Manager::M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base* in_add_post_effect)
{
	// UI描画後に描画しないポストエフェクトは描画リストに追加しない
	if (in_add_post_effect->M_Get_Flg_Post_Effect_After_UI_Draw() == false)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	int set_post_effect_slot = (int)m_this.mpr_variable.post_effect_after_ui_list.size();	// ポストエフェクトの追加先スロット


	// ポストエフェクトを描画リストに追加
	m_this.mpr_variable.post_effect_after_ui_list.resize(set_post_effect_slot + 1);
	m_this.mpr_variable.post_effect_after_ui_list[set_post_effect_slot] = in_add_post_effect;

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UIの前のポストエフェクトを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_Before_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_before_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}

	
	// UI描画前に描画するポストエフェクトのリスト
	m_this.mpr_variable.post_effect_before_ui_list.clear();
	m_this.mpr_variable.post_effect_before_ui_list.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UIの後のポストエフェクトを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Post_Effect_Draw_Manager::M_Draw_Post_Effect_After_UI(void)
{
	for (GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * draw_post_effect : m_this.mpr_variable.post_effect_after_ui_list)
	{
		draw_post_effect->M_Post_Effect_Draw_Before_UI();
	}


	// UI描画後に描画するポストエフェクトのリスト
	m_this.mpr_variable.post_effect_after_ui_list.clear();
	m_this.mpr_variable.post_effect_after_ui_list.shrink_to_fit();

	return;
}


