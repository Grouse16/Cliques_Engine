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
	// ☆ クラス ☆ //

	// アクターの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base, C_Check_Instance>::value;

	// アクター系統のリスト、アクターをクラスごとに管理している
	template <C_Checked_Instance_Class C_Actor>
	class C_Actor_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, std::unique_ptr<C_Actor>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_Actor> Type_Actor;	// アクターのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Actor_List<C_Actor> m_actor_list_this;	// シングルトン化用のインスタンス


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
		static void C_Sort_Actor_By_Class(void)
		{
			// ソート用のラムダ式、降順にソートする
			bool sort_lambda = [](C_Actor_List * & in_left_actor, C_Actor_List * & in_right_actor)
				{
					return in_left_actor->C_Get_Object_List()->M_Get_Priority() >= in_right_actor->C_Get_Object_List()->M_Get_Priority();
				};


			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<C_Actor_List>::M_Sort_Instance_By_Lambda<>(sort_lambda);

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
		static C_Actor * C_Creat_Actor(std::string in_actor_name)
		{
			// ☆ 変数宣言 ☆ //
			Type_Actor & actor_slot_address =		// 新しいアクター用のスロットの参照

				// 新しいアクター用のスロットを生成する
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Creat_Instance(in_actor_name);


			// アクターを生成し、そのアクターのクラス用のリストに格納する
			actor_slot_address.reset(new Type_Actor());

			// 新しく生成されたアクターのアドレスを返す
			return actor_slot_address.get();
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：削除のフラグが立っているアクターを消す
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void C_Delete_Actor_Update(void)
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
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Actor_List, Type_Actor>::M_Delete_Instance_By_Lambda(delete_lambda);

			return;
		}


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたアクターのリストを返す
		// 引数   ：void
		// 戻り値 ：vector<Type_Actor> & 指定されたアクターのリスト
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<Type_Actor> & C_Get_Actor_List(void)
		{
			return m_this.m_instance_list;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された名前のアクターのアドレスを返す
		// 引数   ：void
		// 戻り値 ：C_Actor * 名前が一致したアクターのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Actor * C_Get_Actor_By_Name(std::string in_search_name)
		{
			// 全てのアクターを探索し、見つかったらそのアドレスを返す
			for (Type_Actor & now_actor : m_this.m_instance_list)
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


