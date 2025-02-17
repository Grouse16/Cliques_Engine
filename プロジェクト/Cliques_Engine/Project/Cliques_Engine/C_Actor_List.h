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
#include "C_Actor_Draw_Manager.h"


// ☆ ネームスペース ☆ //

// ゲームのアクターのリスト用のコンセプトを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::LIST::CONCEPT
{
	// ☆ コンセプトクラス ☆ //

	// アクターの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Actor_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;
}


// ☆ マクロ ☆ //
#define D_ACTOR_TEMPLATE template <GAME::INSTANCE::ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>	// テンプレート型定義用マクロ


// ☆ ネームスペース ☆ //

// ゲームのアクターのリストを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::LIST
{
	// ☆ クラス ☆ //
	
	// アクター系統のリスト、アクターをクラスごとに管理している
	D_ACTOR_TEMPLATE class C_Actor_List : protected SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
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

		// コンストラクタ　シングルトン化する
		C_Actor_List(void);


		//-☆- ソート -☆-//

		// アクターをクラスごとに優先度順にソートする
		static void M_Sort_Actor_By_Class(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Actor_List(void);

		
		//-☆- 生成 -☆-//

		// アクターを生成する　引数：string 生成したアクターの名前　戻り値：C_Actor * 生成したアクターのアドレス
		static C_Actor * M_Create_Actor(std::string);


		//-☆- 削除 -☆-//

		// 削除のフラグが立っているアクターを消す
		static void M_Delete_Actor_Update(void);

		// シーン遷移で削除しないフラグが立っていないアクターを全て削除する
		static void M_Delete_Actor_Is_Not_Scene_Over(void);

		// 削除のフラグが立っているインスタンスの削除の実行
		void M_Delete_Instance_Execute(void) override;

		// 大部分のインスタンスの削除を行う
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// 全てのインスタンスの削除を行う
		void M_Delete_All_Instance_Execute(void) override;


		//-☆- ゲッタ -☆-//

		// 指定されたアクターのリストを返す　戻り値：vector<Type_Actor> & 指定されたアクターのリスト
		static std::vector<Type_Actor> & M_Get_Actor_List(void);

		// 指定された名前のアクターのアドレスを返す　戻り値：C_Actor * 名前が一致したアクターのアドレス
		static C_Actor * M_Get_Actor_By_Name(std::string);


		//-☆- 更新 -☆-//

		// アクターの更新を行う
		void M_Instance_Update(void) override;


		//-☆- 描画 -☆-//

		// アクターの描画処理を行う、ここでは近いアクターから順に並べた描画用の配列を作る
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
	D_ACTOR_TEMPLATE inline C_Actor_List<C_Actor>::C_Actor_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：アクターをクラスごとに優先度順にソートする
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Sort_Actor_By_Class(void)
	{
		// ソート用のラムダ式、降順にソートする
		bool sort_lambda = [](SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base*& in_left_actor, SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base*& in_right_actor)
			{
				return in_left_actor->M_Get_Priority_List()[0] >= in_right_actor->M_Get_Priority_List()[0];
			};


		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda(sort_lambda);

		return;
	}


	//==☆ パブリック ☆==//

	//-☆- 終了時 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：デストラクタ
	// 引数   ：void
	// 戻り値 ：なし
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline C_Actor_List<C_Actor>::~C_Actor_List(void)
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
	D_ACTOR_TEMPLATE inline C_Actor * C_Actor_List<C_Actor>::M_Create_Actor(std::string in_actor_name)
	{
		// ☆ 変数宣言 ☆ //
		Type_Actor & actor_slot_address =		// 新しいアクター用のスロットの参照

			// 新しいアクター用のスロットを生成する
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Create_Instance(in_actor_name);


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
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Actor_Update(void)
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


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：シーン遷移で削除しないフラグが立っていないアクターを全て削除する
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Actor_Is_Not_Scene_Over(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_lambda = [](Type_Actor & in_check_actor)
			{
				// シーン遷移時に残るフラグが立っていないなら削除する
				if (in_check_actor->M_Get_Scene_Over_Flg() == false)
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


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：削除のフラグが立っているインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Actor_Update();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：大部分のインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_Actor_Is_Not_Scene_Over();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：全てのインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_All_Instance();
		C_Actor_List<C_Actor>::Type_Actor;
		return;
	}


	//-☆- ゲッタ -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたアクターのリストを返す
	// 引数   ：void
	// 戻り値 ：vector<unique_ptr<C_Actor>> & 指定されたアクターのリスト
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline std::vector<std::unique_ptr<C_Actor>> & C_Actor_List<C_Actor>::M_Get_Actor_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定された名前のアクターのアドレスを返す
	// 引数   ：void
	// 戻り値 ：C_Actor * 名前が一致したアクターのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline C_Actor * C_Actor_List<C_Actor>::M_Get_Actor_By_Name(std::string in_search_name)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// アクターのリスト


		// 全てのアクターを探索し、見つかったらそのアドレスを返す
		for (Type_Actor & now_actor : actor_list)
		{
			if (now_actor.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_actor.get();
			}
		}

		// 見つからなかった場合は、nullを返す
		return nullptr;
	}


	//-☆- 更新 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：アクターの更新を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Instance_Update(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// アクターのリスト


		// 全てのアクターを更新する
		for (Type_Actor & now_actor : actor_list)
		{
			now_actor->M_Component_Update();
			now_actor->M_Actor_Update();
			now_actor->M_Delete_Component_Update();
		}

		return;
	}


	//-☆- 描画 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：アクターの描画処理を行う、ここでは近いアクターから順に並べた描画用の配列を作る
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_ACTOR_TEMPLATE inline void C_Actor_List<C_Actor>::M_Instance_Draw(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Actor>> & actor_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Get_List();	// アクターのリスト


		// アクターを描画リストに追加
		for (std::unique_ptr<C_Actor> & actor_address : actor_list)
		{
			GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Set_Actor_To_Draw_List(actor_address.get());
			GAME::INSTANCE::ACTOR::DRAW_MANAGER::C_Actor_Draw_Manager::M_Set_Actor_To_After_Draw_List(actor_address.get());
		}

		return;
	}
}


// ☆ マクロ削除 ☆ //
#undef D_ACTOR_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_ACTOR_LIST_H_FILE


