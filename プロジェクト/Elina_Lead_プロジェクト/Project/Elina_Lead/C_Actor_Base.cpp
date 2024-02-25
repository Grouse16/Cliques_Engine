//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクターの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Actor_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE::ACTOR::BASE;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- コンポーネント -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のコンポーネントを削除する
// 引数   ：string 削除するコンポーネント名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// 指定された条件通りのインスタンスを削除する
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// コンポーネントの名前が一致するものを削除
			[in_delete_ui_component_name](S_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_component_list.end()
	);

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Actor_Base::C_Actor_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Actor_Base::~C_Actor_Base(void)
{
	m_component_list.clear();
	m_component_list.shrink_to_fit();

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンポーネントの更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Base::M_Component_Update(void)
{
	for (S_Component_Inform & now_component : m_component_list)
	{
		now_component.component->M_Update();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：削除のフラグが立っているコンポーネントを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Base::M_Delete_Component_Update(void)
{
	// 指定された条件通りのインスタンスを削除する
	m_component_list.erase
	(
		std::remove_if
		(
			m_component_list.begin(),
			m_component_list.end(),

			// 削除のフラグが立っているコンポーネントを削除
			[](S_Component_Inform& in_component_inform)
			{
				if (in_component_inform.component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.component.reset();

					return true;
				}

				return false;
			}
		),

		m_component_list.end()
	);

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アクターを描画するかどうかのフラグをセットする
// 引数   ：bool アクターをセットするかどうかのフラグ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Base::M_Set_Draw_Flg(bool in_set_draw_flg)
{
	m_draw_flg = in_set_draw_flg;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常描画後にアクターを描画するかどうかのフラグをセットする
// 引数   ：bool 通常描画後にアクターを描画するかどうかのフラグ、trueの時のみ描画する
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Actor_Base::M_Set_After_Draw_Flg(bool in_after_draw_flg)
{
	m_after_draw_flg = in_after_draw_flg;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アクターを描画するかどうかのフラグを返す
// 引数   ：void
// 戻り値 ：bool アクターを描画するかどうかのフラグ、trueは描画する
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Actor_Base::M_Get_Draw_Flg(void)
{
	return m_draw_flg;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常描画後にアクターを描画するかどうかのフラグを返す
// 引数   ：void
// 戻り値 ：bool 通常描画後にアクターを描画するかどうかのフラグ、trueは描画する
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Actor_Base::M_Get_After_Draw_Flg(void)
{
	return m_after_draw_flg;
}

