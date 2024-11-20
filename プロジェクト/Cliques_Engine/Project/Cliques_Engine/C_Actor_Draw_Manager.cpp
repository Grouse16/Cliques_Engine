//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクターの描画制御をするクラス
// 説明   ：アクターを描画するかどうかのフラグや、距離やカメラとの位置関係からのカリングなどを行って描画するオブジェクトをまとめて持つ
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Actor_Draw_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE::ACTOR::DRAW_MANAGER;


// ☆ スタティック変数 ☆ //
C_Actor_Draw_Manager C_Actor_Draw_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Actor_Draw_Manager::C_Actor_Draw_Manager(void)
{
	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カリングの処理を実行する
// 引数   ：C_Actor_Base * カリングの判定を行うアクターのアドレス
// 戻り値 ：bool 描画する時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Actor_Draw_Manager::M_Culling_Calculation(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_draw_actor)
{
	// 描画する
	return true;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Actor_Draw_Manager::~C_Actor_Draw_Manager(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画リストにアクターを追加する
// 引数   ：C_Actor_Base * 追加するアクターのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Draw_Manager::M_Set_Actor_To_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_set_actor)
{
	// アクターが描画しない状態になっていたら描画しない
	if (in_set_actor->M_Get_Draw_Flg() == false)
	{
		return;
	}


	// アクターがカリングによって描画されない場合は描画リストに追加しない
	if (M_Culling_Calculation(in_set_actor) == false)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	int actor_slot = (int)m_this.mpr_variable.draw_actor_list.size();	// アクターの追加先スロット番号


	// アクターを描画システム内に追加する
	m_this.mpr_variable.draw_actor_list.resize(actor_slot + 1);
	m_this.mpr_variable.draw_actor_list[actor_slot] = in_set_actor;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画リストにアクターを追加する
// 引数   ：C_Actor_Base * 追加するアクターのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Draw_Manager::M_Set_Actor_To_After_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * in_set_actor)
{
	// アクターが描画しない状態になっていたら描画しない
	if (in_set_actor->M_Get_After_Draw_Flg() == false)
	{
		return;
	}


	// アクターがカリングによって描画されない場合は描画リストに追加しない
	if (M_Culling_Calculation(in_set_actor) == false)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	int actor_slot = (int)m_this.mpr_variable.after_draw_actor_list.size();	// アクターの追加先スロット番号


	// アクターを描画システム内に追加する
	m_this.mpr_variable.after_draw_actor_list.resize(actor_slot + 1);
	m_this.mpr_variable.after_draw_actor_list[actor_slot] = in_set_actor;

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画リスト内のアクターを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Draw_Manager::M_Draw_Actor_In_Draw_List(void)
{
	for (GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * draw_actor : m_this.mpr_variable.draw_actor_list)
	{
		draw_actor->M_Actor_Draw();
	}


	// 描画するアクターのリストを初期化する
	m_this.mpr_variable.draw_actor_list.clear();
	m_this.mpr_variable.draw_actor_list.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常描画後の描画リスト内のアクターを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Draw_Manager::M_Draw_Actor_In_After_Draw_List(void)
{
	for (GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * after_draw_actor : m_this.mpr_variable.after_draw_actor_list)
	{
		after_draw_actor->M_Actor_After_Draw();
	}


	// 通常描画後に描画するアクターのリストを初期化する
	m_this.mpr_variable.after_draw_actor_list.clear();
	m_this.mpr_variable.after_draw_actor_list.shrink_to_fit();

	return;
}

