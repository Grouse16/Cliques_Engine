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
#include "C_Post_Effect_Draw_Manager.h"


// ☆ ネームスペース ☆ //

// ゲームのポストエフェクトのリスト用コンセプトを呼び出すための名前
namespace GAME::INSTANCE::POST_EFFECT::LIST::CONCEPT
{
	// ☆ コンセプトクラス ☆ //

	// ポストエフェクトの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Post_Effect_Class = std::is_base_of<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base, C_Check_Instance>::value;
}


// ☆ マクロ ☆ //
#define D_POST_EFFECT_TEMPLATE template <GAME::INSTANCE::POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>	// ポストエフェクトのテンプレート定義用マクロ


// ゲームのポストエフェクトのリストを呼び出すための名前
namespace GAME::INSTANCE::POST_EFFECT::LIST
{
	// ☆ クラス ☆ //

	// ポストエフェクト系統のリスト、ポストエフェクトをクラスごとに管理している
	D_POST_EFFECT_TEMPLATE class C_Post_Effect_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base < C_Post_Effect_List, std::unique_ptr<C_Post_Effect>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_Post_Effect> Type_Post_Effect;	// ポストエフェクトのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Post_Effect_List<C_Post_Effect> m_post_effect_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ　シングルトン化する
		C_Post_Effect_List(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//
		
		// デストラクタ
		~C_Post_Effect_List(void);


		//-☆- 生成 -☆-//

		// ポストエフェクトを生成する　引数：string 生成したポストエフェクトの名前　戻り値：C_Post_Effect * 生成したポストエフェクトのアドレス
		static C_Post_Effect * M_Create_Post_Effect(std::string);


		//-☆- 削除 -☆-//

		// 削除のフラグが立っているポストエフェクトを消す
		static void M_Delete_Post_Effect_Update(void);

		// シーン遷移で削除しないフラグが立っていないポストエフェクトを全て削除する
		static void M_Delete_Post_Effect_Is_Not_Scene_Over(void);

		// 削除のフラグが立っているインスタンスの削除の実行
		void M_Delete_Instance_Execute(void) override;

		// 大部分のインスタンスの削除を行う
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// 全てのインスタンスの削除を行う
		void M_Delete_All_Instance_Execute(void) override;


		//-☆- ゲッタ -☆-//

		// 指定されたポストエフェクトのリストを返す　戻り値：vector<Type_Post_Effect> & 指定されたポストエフェクトのリスト
		static std::vector<Type_Post_Effect> & M_Get_Post_Effect_List(void);

		// 指定された名前のポストエフェクトのアドレスを返す　戻り値：C_Post_Effect * 名前が一致したポストエフェクトのアドレス
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string);


		//-☆- 更新 -☆-//

		// ポストエフェクトの更新を行う
		void M_Instance_Update(void) override;


		//-☆- 描画 -☆-//

		// ポストエフェクトの描画処理を行う、ここでは、UIの前にかけるポストエフェクトとUIのあとに掛けるポストエフェクトで分かれる
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
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect_List<C_Post_Effect>::C_Post_Effect_List(void)
	{
		M_Set_My_Instance_Address(this);

		return;
	}


	//==☆ パブリック ☆==//

	// ☆ 関数 ☆ //

	//-☆- 終了時 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：デストラクタ
	// 引数   ：void
	// 戻り値 ：なし
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect_List<C_Post_Effect>::~C_Post_Effect_List(void)
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
	D_POST_EFFECT_TEMPLATE inline static C_Post_Effect * C_Post_Effect_List<C_Post_Effect>::M_Create_Post_Effect(std::string in_post_effect_name)
	{
		// ☆ 変数宣言 ☆ //
		Type_Post_Effect& post_effect_slot_address =		// 新しいポストエフェクト用のスロットの参照

			// 新しいポストエフェクト用のスロットを生成する
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Create_Instance(in_post_effect_name);


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
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Post_Effect_Update(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_lambda = [](Type_Post_Effect& in_check_post_effect)
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


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：シーン遷移で削除しないフラグが立っていないポストエフェクトを全て削除する
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Post_Effect_Is_Not_Scene_Over(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_lambda = [](Type_Post_Effect & in_check_post_effect)
			{
				// シーン遷移時に残るフラグが立っていないなら削除する
				if (in_check_post_effect->M_Get_Scene_Over_Flg() == false)
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


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：インスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Post_Effect_Update();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：大部分のインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_Post_Effect_Is_Not_Scene_Over();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：全てのインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline void C_Post_Effect_List<C_Post_Effect>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Delete_All_Instance();

		return;
	}


	//-☆- ゲッタ -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたポストエフェクトのリストを返す
	// 引数   ：void
	// 戻り値 ：vector<unique_ptr<C_Post_Effect>> & 指定されたポストエフェクトのリスト
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline std::vector<std::unique_ptr<C_Post_Effect>> & C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定された名前のポストエフェクトのアドレスを返す
	// 引数   ：void
	// 戻り値 ：C_Post_Effect * 名前が一致したポストエフェクトのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE inline C_Post_Effect * C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_By_Name(std::string in_search_name)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// ポストエフェクトのリスト


		// 全てのポストエフェクトを探索し、見つかったらそのアドレスを返す
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			if (now_post_effect.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_post_effect.get();
			}
		}


		// 見つからなかった場合は、nullを返す
		return nullptr;
	}


	//-☆- 更新 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：ポストエフェクトの更新を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE void C_Post_Effect_List<C_Post_Effect>::M_Instance_Update(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// ポストエフェクトのリスト


		// ポストエフェクトの更新を行う
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			now_post_effect->M_Post_Effect_Update();
		}

		return;
	}


	//-☆- 描画 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：ポストエフェクトの描画処理を行う、ここでは、UIの前にかけるポストエフェクトとUIのあとに掛けるポストエフェクトで描画のリストを分ける
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_POST_EFFECT_TEMPLATE void C_Post_Effect_List<C_Post_Effect>::M_Instance_Draw(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Post_Effect>> & post_effect_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Post_Effect_List, Type_Post_Effect>::M_Get_List();	// ポストエフェクトのリスト


		// ポストエフェクトを描画用リストに追加する
		for (Type_Post_Effect & now_post_effect : post_effect_list)
		{
			GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Set_Post_Effect_Before_UI(now_post_effect);
			GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER::C_Post_Effect_Draw_Manager::M_Set_Post_Effect_After_UI(now_post_effect);
		}

		return;
	}
}


// ☆ マクロ削除 ☆ //
#undef D_POST_EFFECT_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_LIST_H_FILE


