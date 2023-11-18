//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UI系統を管理するリストの動作をカプセル化するシステム
// 説明   ：生成、削除、取得を行って、UIの派生にあたるクラス以外を全てリストから弾くことができる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_UI_LIST_H_FILE
#define D_INCLUDE_GUARD_C_UI_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_User_Interface_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのUIのリスト用のコンセプトを呼び出すための名前
namespace GAME::INSTANCE::UI::LIST::CONCEPT
{
	// ☆ コンセプトクラス ☆ //

	// UIの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_UI_Class = std::is_base_of<GAME::INSTANCE::UI::BASE::C_User_Interface_Base, C_Check_Instance>::value;
}


// ☆ マクロ ☆ //
#define D_UI_TEMPLATE template <GAME::INSTANCE::UI::LIST::CONCEPT::C_Checked_UI_Class C_User_Interface>	// UIのテンプレート定義用マクロ


// ゲームのUIのリストを呼び出すための名前
namespace GAME::INSTANCE::UI::LIST
{
	// ☆ クラス ☆ //

	// UI系統のリスト、UIをクラスごとに管理している
	D_UI_TEMPLATE class C_User_Interface_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, std::unique_ptr<C_User_Interface>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_User_Interface> Type_UI;	// UIのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_User_Interface_List<C_User_Interface> m_UI_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ　シングルトン化する
		C_User_Interface_List(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_User_Interface_List(void);


		//-☆- 生成 -☆-//

		// UIを生成する　引数：生成したUIの名前　戻り値：C_Instance_List_Base<C_User_Interface_List, Type_UI>::S_Instance_Inform & 生成したUIのアドレス
		static C_User_Interface * M_Create_UI(std::string);


		//-☆- 削除 -☆-//

		// 削除のフラグが立っているアクターを消す
		static void M_Delete_UI_Update(void);

		// インスタンスの削除を行う
		void M_Delete_Instance_Execute(void) override;

		// 全てのインスタンスの削除を行う
		void M_Delete_All_Instance_Execute(void) override;


		//-☆- ゲッタ -☆-//

		// 指定されたUIのリストを返す　戻り値：vector<Type_UI> & 指定されたUIのリスト
		static std::vector<Type_UI> & M_Get_UI_List(void);

		// 指定された名前のUIのアドレスを返す　戻り値：C_Type_User_Interface * 名前が一致したUIのアドレス
		static C_User_Interface * M_Get_UI_By_Name(std::string);


		//-☆- 更新 -☆-//

		// UIの更新を行う
		void M_Instance_Update(void) override;


		//-☆- 描画 -☆-//

		// UIを描画リストに追加する
		void M_Instance_Draw(void) override;
	};


	// ☆ 関数 ☆ //

	//==☆ プライベート ☆==//

	//-☆- 初期化 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：コンストラクタ　シングルトン化する
	// 引数   ：void
	// 戻り値 ：なし
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline C_User_Interface_List<C_User_Interface>::C_User_Interface_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//==☆ パブリック ☆==//

	//-☆- 終了時 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：デストラクタ
	// 引数   ：void
	// 戻り値 ：なし
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline C_User_Interface_List<C_User_Interface>::~C_User_Interface_List(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_All_Instance();

		return;
	}


	//-☆- 生成 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：UIを生成する
	// 引数   ：string 生成したUIの名前
	// 戻り値 ：C_Instance_List_Base<C_User_Interface_List, Type_UI>::S_Instance_Inform & 生成したUIのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline C_User_Interface * C_User_Interface_List<C_User_Interface>::M_Create_UI(std::string in_ui_name)
	{
		// ☆ 変数宣言 ☆ //
		Type_UI& ui_slot_address =		// 新しいUI用のスロットの参照

			// 新しいUI用のスロットを生成する
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Create_Instance(in_ui_name);


		// UIを生成し、そのUIのクラス用のリストに格納する
		ui_slot_address.reset(new C_User_Interface());

		// 新しく生成されたUIのアドレスを返す
		return ui_slot_address.get();
	}


	//-☆- 削除 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：削除のフラグが立っているアクターを消す
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_UI_Update(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_lambda = [](Type_UI& in_check_ui)
			{
				// インスタンス削除のフラグが立っているなら削除し、配列からこの要素を削除する
				if (in_check_ui->M_Get_Destroy_Instance_Flg())
				{
					in_check_ui.reset();
					return true;
				}

				return false;
			};


		// リストからの削除を行う
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_Instance_By_Lambda(delete_lambda);

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：インスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_Instance_Execute(void)
	{
		M_Delete_UI_Update();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：全てのインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Delete_All_Instance();

		return;
	}


	//-☆- ゲッタ -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたUIのリストを返す
	// 引数   ：void
	// 戻り値 ：vector<unique_ptr<C_User_Interface>> & 指定されたUIのリスト
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline std::vector<std::unique_ptr<C_User_Interface>> & C_User_Interface_List<C_User_Interface>::M_Get_UI_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定された名前のUIのアドレスを返す
	// 引数   ：void
	// 戻り値 ：C_Type_User_Interface * 名前が一致したUIのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline C_User_Interface * C_User_Interface_List<C_User_Interface>::M_Get_UI_By_Name(std::string in_search_name)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UIのリスト


		// 全てのUIを探索し、見つかったらそのアドレスを返す
		for (Type_UI & now_ui : ui_list)
		{
			if (now_ui.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_ui.get();
			}
		}

		// 見つからなかった場合は、nullを返す
		return nullptr;
	}


	//-☆- 更新 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：UIの更新を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Instance_Update(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UIのリスト


		// 全てのUIを更新する
		for (Type_UI & now_ui : ui_list)
		{
			now_ui->M_UI_Update();
		}

		return;
	}


	//-☆- 描画 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：UIを描画リストに追加する
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_UI_TEMPLATE inline void C_User_Interface_List<C_User_Interface>::M_Instance_Draw(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_User_Interface>> & ui_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Get_List();	// UIのリスト


		// 全てのUIを描画する
		for (Type_UI & now_ui : ui_list)
		{
			now_ui->M_UI_Draw();
		}

		return;
	}
}


// ☆ マクロ削除 ☆ //
#undef D_UI_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_UI_LIST_H_FILE


