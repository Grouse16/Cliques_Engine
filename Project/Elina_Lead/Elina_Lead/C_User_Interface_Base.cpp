//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UIの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_User_Interface_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INSTANCE::UI::BASE;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- コンポーネント -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のUIのコンポーネントを削除する
// 引数   ：string 削除するコンポーネント名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_User_Interface_Base::M_Delete_Component_By_Name(std::string in_delete_ui_component_name)
{
	// 指定された条件通りのインスタンスを削除する
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// コンポーネントの名前が一致するものを削除
			[in_delete_ui_component_name](S_UI_Component_Inform& in_component_inform)
			{
				return in_component_inform.name == in_delete_ui_component_name;
			}
		),

		m_ui_component_list.end()
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
C_User_Interface_Base::C_User_Interface_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_User_Interface_Base::~C_User_Interface_Base(void)
{
	m_ui_component_list.clear();
	m_ui_component_list.shrink_to_fit();

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンポーネントの更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_User_Interface_Base::M_Update_Component(void)
{
	for (S_UI_Component_Inform & m_component_list : m_ui_component_list)
	{
		m_component_list.ui_component->M_Update();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：削除のフラグが立っているコンポーネントを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_User_Interface_Base::M_Delete_Component_Update(void)
{
	// 指定された条件通りのインスタンスを削除する
	m_ui_component_list.erase
	(
		std::remove_if
		(
			m_ui_component_list.begin(),
			m_ui_component_list.end(),

			// 削除のフラグが立っているコンポーネントを削除
			[](S_UI_Component_Inform& in_component_inform)
			{
				if (in_component_inform.ui_component->M_Get_Component_Destroy_Flg())
				{
					in_component_inform.ui_component.reset();

					return true;
				}

				return false;
			}
		),

		m_ui_component_list.end()
	);

	return;
}

