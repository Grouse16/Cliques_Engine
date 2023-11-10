//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ポストエフェクト系統を管理するリストの動作をカプセル化するシステム
// 説明   ：生成、削除、取得を行って、ポストエフェクトの派生にあたるクラス以外を全てリストから弾くことができる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Post_Effect_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのポストエフェクトのリストを呼び出すための名前
namespace GAME::INSTANCE::POST_EFFECT::LIST
{
	// ☆ コンセプトクラス ☆ //

	// ポストエフェクトの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Instance_Class = std::is_base_of<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base, C_Check_Instance>::value;


	// ☆ クラス ☆ //

	// ポストエフェクト系統のリスト、ポストエフェクトをクラスごとに管理している
	template <C_Checked_Instance_Class C_Post_Effect>
	class C_Post_Effect_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base < C_Post_Effect_List, std::unique_ptr<C_Post_Effect>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_Post_Effect> Type_Post_Effect;	// ポストエフェクトのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Post_Effect_List<C_Post_Effect> m_post_effect_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ　シングルトン化する
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_Post_Effect_List(void)
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
		~C_Post_Effect_List(void)
		{
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_All_Instance();

			return;
		}


		//-☆- 生成 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：ポストエフェクトを生成する
		// 引数   ：string 生成したポストエフェクトの名前
		// 戻り値 ：C_Post_Effect * 生成したポストエフェクトのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Post_Effect * M_Creat_Post_Effect(std::string in_post_effect_name)
		{
			// ☆ 変数宣言 ☆ //
			Type_Post_Effect & post_effect_slot_address =		// 新しいポストエフェクト用のスロットの参照

				// 新しいポストエフェクト用のスロットを生成する
				SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Creat_Instance(in_post_effect_name);


			// ポストエフェクトを生成し、そのポストエフェクトのクラス用のリストに格納する
			post_effect_slot_address.reset(new C_Post_Effect());

			// 新しく生成されたポストエフェクトのアドレスを返す
			return post_effect_slot_address.get();
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：削除のフラグが立っているポストエフェクトを消す
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Delete_Post_Effect_Update(void)
		{
			// ☆ ラムダ式 ☆ //

			// ベクターからインスタンス削除用の判定を行うラムダ式
			auto delete_lambda = [](Type_Post_Effect & in_check_post_effect)
				{
					// インスタンス削除のフラグが立っているなら削除し、配列からこの要素を削除する
					if (in_check_post_effect->M_Get_Destroy_Instance_Flg())
					{
						in_check_post_effect.reset();
						return true;
					}

					return false;
				};


			// リストからの削除を行う
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_Instance_By_Lambda(delete_lambda);

			return;
		}


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたポストエフェクトのリストを返す
		// 引数   ：void
		// 戻り値 ：vector<Type_Post_Effect> & 指定されたポストエフェクトのリスト
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<Type_Post_Effect> & M_Get_Post_Effect_List(void)
		{
			return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された名前のポストエフェクトのアドレスを返す
		// 引数   ：void
		// 戻り値 ：C_Post_Effect * 名前が一致したポストエフェクトのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string in_search_name)
		{
			// 全てのポストエフェクトを探索し、見つかったらそのアドレスを返す
			for (Type_Post_Effect & now_post_effect : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List())
			{
				if (now_post_effect.get()->M_Get_Instance_Name() == in_search_name)
				{
					return now_post_effect.get();
				}
			}


			// 見つからなかった場合は、nullを返す
			return nullptr;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


