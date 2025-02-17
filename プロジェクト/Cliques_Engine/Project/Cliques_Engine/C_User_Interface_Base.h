//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UIの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "C_Game_Instance_Base.h"
#include "C_UI_Component_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのUIの基底クラスを呼び出すための名前
namespace GAME::INSTANCE::UI::BASE
{
	// ☆ コンセプトクラス ☆ //

	// UIコンポーネントの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_UI_Component_Class = std::is_base_of<GAME::UI_COMPONENT::BASE::C_UI_Component_Base, C_Check_Instance>::value;


	// ☆ クラス ☆ //

	// UIの基底となるクラス
	class C_User_Interface_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// ＵＩ用のコンポーネントを管理するための構造体
		struct S_UI_Component_Inform
		{
			std::unique_ptr<GAME::UI_COMPONENT::BASE::C_UI_Component_Base> ui_component;	// ＵＩのコンポーネント

			std::string name = "default";	// ＵＩコンポーネント名
		};


		// ☆ 変数宣言 ☆ //
		std::vector<S_UI_Component_Inform> m_ui_component_list;	// UIのコンポーネントのリスト


		// ☆ 関数 ☆ //

		//-☆- コンポーネント -☆-//

		// 指定されたUI用のコンポーネントを生成し、そのアドレスを返す　引数：string 生成するコンポーネント名　戻り値：C_UI_Component_Base * 生成したコンポーネントのアドレス
		template <C_Checked_UI_Component_Class C_UI_Component_Class>
		C_UI_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// 指定された名前のUIのコンポーネントを削除する　引数：string 削除するコンポーネント名
		void M_Delete_Component_By_Name(std::string);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_User_Interface_Base(void);

		// デストラクタ
		virtual ~C_User_Interface_Base(void);


		//-☆- 更新 -☆-//

		// コンポーネントの更新を行う
		void M_Update_Component(void);

		// UIの更新を行う
		virtual void M_UI_Update(void) = 0;

		// 削除のフラグが立っているコンポーネントを削除する
		void M_Delete_Component_Update(void);


		//-☆- 描画 -☆-//

		// UIの描画を行う
		virtual void M_UI_Draw(void) = 0;
	};


	// ☆ 関数 ☆ //

	//==☆ プライベート ☆==//

	//-☆- コンポーネント -☆-//
	
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたUI用のコンポーネントを生成し、そのアドレスを返す
	// 引数   ：string 生成するコンポーネント名
	// 戻り値 ：C_UI_Component_Base * 生成したコンポーネントのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	template<C_Checked_UI_Component_Class C_UI_Component_Class>
	inline C_UI_Component_Class * C_User_Interface_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		// ☆ 変数宣言 ☆ //
		C_UI_Component_Class * new_ui_component = new C_UI_Component_Class();	// 新しいUIのコンポーネントのアドレス

		int new_ui_component_slot = m_ui_component_list.size();	// 新しいUIのコンポーネント用のスロット番号


		// 新しいUIのコンポーネントをリストに追加
		m_ui_component_list.resize(new_ui_component_slot + 1);
		m_ui_component_list[new_ui_component_slot].ui_component.reset(new_ui_component);
		m_ui_component_list[new_ui_component_slot].name = in_set_ui_component_name;

		// 生成されたコンポーネントのアドレスを返す
		return new_ui_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
