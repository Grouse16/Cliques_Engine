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

// ゲームのUIのリストを呼び出すための名前
namespace GAME::INSTANCE::UI::LIST
{
	// ☆ クラス ☆ //

	// UIの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::UI::BASE::C_User_Interface_Base, C_Check_Instance>::value;

	// UI系統のリスト、UIをクラスごとに管理している
	template <C_Checked_Instance_Class C_User_Interface>
	class C_User_Interface_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, std::unique_ptr<C_User_Interface>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_User_Interface> Type_UI;	// UIのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_User_Interface_List<C_User_Interface> m_UI_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ　シングルトン化する
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_User_Interface_List(void)
		{
			return;
		}


		//-☆- ソート -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：ホルダーにソートをかける
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void C_User_Interface_List(void)
		{
			return;
		}


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：デストラクタ
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		~C_User_Interface_List(void)
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
		static C_User_Interface * C_Creat_UI(std::string in_ui_name)
		{
			// ☆ 変数宣言 ☆ //
			Type_UI & ui_slot_address =		// 新しいUI用のスロットの参照

				// 新しいUI用のスロットを生成する
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_User_Interface_List, Type_UI>::M_Creat_Instance(in_ui_name);


			// UIを生成し、そのUIのクラス用のリストに格納する
			ui_slot_address.reset(new Type_UI());

			// 新しく生成されたUIのアドレスを返す
			return ui_slot_address.get();
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：削除のフラグが立っているアクターを消す
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void C_Delete_UI_Update(void)
		{
			// ☆ ラムダ式 ☆ //

			// ベクターからインスタンス削除用の判定を行うラムダ式
			auto delete_lambda = [](Type_UI & in_check_ui)
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


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたUIのリストを返す
		// 引数   ：void
		// 戻り値 ：vector<Type_UI> & 指定されたUIのリスト
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<Type_UI> & C_Get_UI_List(void)
		{
			return m_this.m_instance_list;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された名前のUIのアドレスを返す
		// 引数   ：void
		// 戻り値 ：C_Type_User_Interface * 名前が一致したUIのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_User_Interface * C_Get_UI_By_Name(std::string in_search_name)
		{
			// 全てのUIを探索し、見つかったらそのアドレスを返す
			for (Type_UI & now_ui : m_this.m_instance_list)
			{
				if (now_ui.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_ui.get();
				}
			}

			// 見つからなかった場合は、nullを返す
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_UI_LIST_H_FILE


