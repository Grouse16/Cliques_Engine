//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクターの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>

#include "C_Game_Instance_Base.h"
#include "C_Component_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのアクターの基底クラスを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::BASE
{
	// ☆ コンセプトクラス ☆ //

	// コンポーネントの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Component_Class = std::is_base_of<GAME::COMPONENT::BASE::C_Component_Base, C_Check_Instance>::value;


	// ☆ クラス ☆ //

	// アクターの基底となるクラス
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==// 
	private:

		// ☆ 構造体 ☆ //

		// コンポーネント制御用の情報の構造体
		struct S_Component_Inform
		{
			std::unique_ptr<GAME::COMPONENT::BASE::C_Component_Base> component;	// コンポーネント

			std::string name = "default";	// コンポーネント名
		};


		// ☆ 変数宣言 ☆ //
		std::vector<S_Component_Inform> m_component_list;	// コンポーネントのリスト

		bool m_draw_flg = true;			// 描画するかどうかのフラグ
		bool m_after_draw_flg = false;	// 通常描画後に描画するかどうかのフラグ


		// ☆ 関数 ☆ //

		//-☆- コンポーネント -☆-//

		// 指定されたコンポーネントを生成し、そのアドレスを返す　引数：string 生成するコンポーネント名　戻り値：C_UI_Component_Base * 生成したコンポーネントのアドレス
		template <C_Checked_Component_Class C_Component_Class>
		C_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// 指定された名前のコンポーネントを削除する　引数：string 削除するコンポーネント名
		void M_Delete_Component_By_Name(std::string);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Actor_Base(void);

		// デストラクタ
		virtual ~C_Actor_Base(void);


		//-☆- 優先度 -☆-//

		// アクターの優先度を返す　戻り値：アクターの優先度
		virtual int M_Get_Priority(void) = 0;


		//-☆- 更新 -☆-//

		// コンポーネントの更新を行う
		void M_Component_Update(void);

		// アクターの更新を行う
		virtual void M_Actor_Update(void) = 0;

		// 削除のフラグが立っているコンポーネントを削除する
		void M_Delete_Component_Update(void);


		//-☆- 描画 -☆-//

		// アクター描画する
		virtual void M_Actor_Draw(void) = 0;

		// 通常描画後にアクターを描画する
		virtual void M_Actor_After_Draw(void) = 0;


		//-☆- セッタ -☆-//

		// アクターを通常描画で描画するかどうかのフラグをセットする　引数：trueの時は描画する、falseの時は描画しない
		void M_Set_Draw_Flg(bool);

		// 通常描画後にアクターを描画するかどうかのフラグをセットする　引数：trueの時は描画する、falseの時は描画しない
		void M_Set_After_Draw_Flg(bool);

		
		//-☆- ゲッタ -☆-//

		// アクターを描画するかどうかのフラグを返す　戻り値：trueは描画する、falseは描画しない
		bool M_Get_Draw_Flg(void);

		// 通常描画後にアクターを描画するかどうかのフラグを返す　戻り値：trueは描画する、falseは描画しない
		bool M_Get_After_Draw_Flg(void);
	};


	// ☆ 関数 ☆ //

	//==☆ プライベート ☆==//

	//-☆- コンポーネント -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたコンポーネントを生成し、そのアドレスを返す
	// 引数   ：string 生成するコンポーネント名
	// 戻り値 ：C_UI_Component_Base * 生成したコンポーネントのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	template<C_Checked_Component_Class C_Component_Class>
	inline C_Component_Class * C_Actor_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		// ☆ 変数宣言 ☆ //
		C_Component_Class * new_component = new C_Component_Class();	// 新しいコンポーネントのアドレス

		int new_component_slot = m_component_list.size();	// 新しいコンポーネント用のスロット番号


		// 新しいコンポーネントをリストに追加
		m_component_list.resize(new_component_slot + 1);
		m_component_list[new_component_slot].component.reset(new_component);
		m_component_list[new_component_slot].name = in_set_ui_component_name;

		// 生成されたコンポーネントのアドレスを返す
		return new_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


