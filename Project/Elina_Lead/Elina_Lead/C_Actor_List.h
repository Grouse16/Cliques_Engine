//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクター系統を管理するリストの動作をカプセル化するシステム
// 説明   ：生成、削除、取得を行って、アクターの派生にあたるクラス以外を全てリストから弾くことができる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Actor_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのアクターのリストを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::LIST
{
	// ☆ コンセプトクラス ☆ //

	// アクターの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Actor_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;


	// ☆ クラス ☆ //

	// アクター系統のリスト、アクターをクラスごとに管理している
	template <C_Checked_Actor_Class C_Actor>
	class C_Actor_List : protected SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_Actor> Type_Actor;	// アクターのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Actor_List<C_Actor> m_this;	// シングルトン化用のインスタンス

		bool m_actor_is_nothing = true;	// アクターを持っていない状態の時のみたつフラグ


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ　シングルトン化する
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_Actor_List(void)
		{
			return;
		}


		//-☆- ソート -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：アクターをクラスごとに優先度順にソートする
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Sort_Actor_By_Class(void)
		{
			// ソート用のラムダ式、降順にソートする
			bool sort_lambda = [](SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * & in_left_actor, SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * & in_right_actor)
				{
					return in_left_actor->M_Get_Priority_List()[0] >= in_right_actor->M_Get_Priority_List()[0];
				};


			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda(sort_lambda);

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
		~C_Actor_List(void)
		{
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_All_Instance();
			
			return;
		}

		
		//-☆- 生成 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：アクターを生成する
		// 引数   ：string 生成したアクターの名前
		// 戻り値 ：C_Actor * 生成したアクターのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Actor * M_Creat_Actor(std::string in_actor_name)
		{
			// ☆ 変数宣言 ☆ //
			Type_Actor & actor_slot_address =		// 新しいアクター用のスロットの参照

				// 新しいアクター用のスロットを生成する
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Creat_Instance(in_actor_name);


			// アクターを生成し、そのアクターのクラス用のリストに格納する
			actor_slot_address.reset(new C_Actor());


			// 一体目が新しく追加されたらクラスの優先度を追加して全体をソートする
			if (m_actor_is_nothing)
			{
				// ☆ 変数宣言 ☆ //
				std::vector<int> & priority_list = SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base::M_Get_Priority_List();	// 優先度のリスト

				int priority_list_slot = priority_list.size();	// 優先度設定先のスロット


				// 優先度を登録する
				priority_list.resize(priority_list_slot + 1);
				priority_list[priority_list_slot] = actor_slot_address->M_Get_Priority();

				// ソートを実行
				M_Sort_Actor_By_Class();

				// アクターを持ったのでアクターがない状態のフラグを下げる
				m_actor_is_nothing = false;
			}


			// 新しく生成されたアクターのアドレスを返す
			return actor_slot_address.get();
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：削除のフラグが立っているアクターを消す
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Delete_Actor_Update(void)
		{
			// ☆ ラムダ式 ☆ //

			// ベクターからインスタンス削除用の判定を行うラムダ式
			auto delete_lambda = [](Type_Actor & in_check_actor)
				{
					// インスタンス削除のフラグが立っているなら削除し、配列からこの要素を削除する
					if (in_check_actor->M_Get_Destroy_Instance_Flg())
					{
						in_check_actor.reset();
						return true;
					}

					return false;
				};


			// リストからの削除を行う
			m_actor_is_nothing = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_Instance_By_Lambda(delete_lambda);

			return;
		}


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたアクターのリストを返す
		// 引数   ：void
		// 戻り値 ：vector<Type_Actor> & 指定されたアクターのリスト
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<Type_Actor> & M_Get_Actor_List(void)
		{
			return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された名前のアクターのアドレスを返す
		// 引数   ：void
		// 戻り値 ：C_Actor * 名前が一致したアクターのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Actor * M_Get_Actor_By_Name(std::string in_search_name)
		{
			// 全てのアクターを探索し、見つかったらそのアドレスを返す
			for (Type_Actor & now_actor : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List())
			{
				if (now_actor.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_actor.get();
				}
			}

			// 見つからなかった場合は、nullを返す
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


