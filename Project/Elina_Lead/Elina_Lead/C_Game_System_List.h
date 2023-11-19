//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：システム系統を管理するリストの動作をカプセル化するシステム
// 説明   ：生成、削除、取得を行って、システムの派生にあたるクラス以外を全てリストから弾くことができる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE
#define D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Game_System_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのシステムのリストのコンセプトを呼び出すための名前
namespace GAME::INSTANCE::GAME_SYSTEM::LIST::CONCEPT
{
	// ☆ コンセプトクラス ☆ //

	// システムの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_System_Class = std::is_base_of<GAME::INSTANCE::GAME_SYSTEM::BASE::C_Game_System_Base, C_Check_Instance > ::value;
}


// ☆ マクロ ☆ //
#define D_SYSTEM_TEMPLATE template <GAME::INSTANCE::GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_System>	// システムのテンプレート定義用マクロ


// ゲームのシステムのリストを呼び出すための名前
namespace GAME::INSTANCE::GAME_SYSTEM::LIST
{
	// ☆ クラス ☆ //

	// システム系統のリスト、システムをクラスごとに管理している
	D_SYSTEM_TEMPLATE class C_Game_System_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, std::unique_ptr<C_System>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_System> Type_System;	// システムのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Game_System_List<C_System> m_sound_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ　シングルトン化する
		C_Game_System_List(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Game_System_List(void);


		//-☆- 生成 -☆-//

		// システムを生成する　引数：string 生成するシステムの名前　戻り値：C_System * 生成したシステムのアドレス
		static C_System * M_Create_System(std::string);


		//-☆- 削除 -☆-//

		// 削除のフラグが立っているシステムを消す
		static void M_Delete_System_Update(void);

		// シーン遷移で削除しないフラグが立っていないシステムを全て削除する
		static void M_Delete_System_Is_Not_Scene_Over(void);

		// 削除のフラグが立っているインスタンスの削除の実行
		void M_Delete_Instance_Execute(void) override;

		// 大部分のインスタンスの削除を行う
		void M_Delete_Most_OF_Instance_Execute(void) override;

		// 全てのインスタンスの削除を行う
		void M_Delete_All_Instance_Execute(void) override;


		//-☆- ゲッタ -☆-//

		// 指定されたシステムのリストを返す　戻り値：vector<Type_System> & 指定されたシステムのリスト
		static std::vector<Type_System> & M_Get_System_List(void);

		// 指定された名前のシステムのアドレスを返す　戻り値：C_System * 名前が一致したシステムのアドレス
		static C_System* M_Get_System_By_Name(std::string);


		//-☆- 更新 -☆-//

		// システムの更新を行う
		void M_Instance_Update(void) override;


		//-☆- 描画 -☆-//

		// 描画はないがエラー防止用に定義
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
	D_SYSTEM_TEMPLATE inline C_Game_System_List<C_System>::C_Game_System_List()
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
	D_SYSTEM_TEMPLATE inline C_Game_System_List<C_System>::~C_Game_System_List(void)
	{
		// 所持しているリストを全て開放しホルダーも削除する
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_All_Instance();

		return;
	}


	//-☆- 生成 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：システムを生成する
	// 引数   ：string 生成するシステムの名前
	// 戻り値 ：C_System * 生成したシステムのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline C_System* C_Game_System_List<C_System>::M_Create_System(std::string in_sound_name)
	{
		// ☆ 変数宣言 ☆ //
		Type_System& sound_slot_address =		// 新しいシステム用のスロットの参照

			// 新しいシステム用のスロットを生成する
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Create_Instance(in_sound_name);


		// システムを生成し、そのシステムのクラス用のリストに格納する
		sound_slot_address.reset(new C_System());

		// 新しく生成されたシステムのアドレスを返す
		return sound_slot_address.get();
	}


	//-☆- 削除 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：削除のフラグが立っているシステムを消す
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_System_Update(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_ramada = [](Type_System& in_check_sound)
			{
				// インスタンス削除のフラグが立っているなら削除し、配列からこの要素を削除する
				if (in_check_sound->M_Get_Destroy_Instance_Flg())
				{
					in_check_sound.reset();
					return true;
				}

				return false;
			};


		// リストからの削除を行う
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：シーン遷移で削除しないフラグが立っていないシステムを全て削除する
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_System_Is_Not_Scene_Over(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_ramada = [](Type_System& in_check_sound)
			{
				// シーン遷移時に残るフラグが立っていないなら削除する
				if (in_check_sound->M_Get_Scene_Over_Flg() == false)
				{
					in_check_sound.reset();
					return true;
				}

				return false;
			};


		// リストからの削除を行う
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：インスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_Instance_Execute(void)
	{
		M_Delete_System_Update();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：大部分のインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_Most_OF_Instance_Execute(void)
	{
		M_Delete_System_Is_Not_Scene_Over();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：全てのインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Delete_All_Instance();

		return;
	}


	//-☆- ゲッタ -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたシステムのリストを返す
	// 引数   ：void
	// 戻り値 ：vector<unique_ptr<C_System>> & 指定されたシステムのリスト
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline std::vector<std::unique_ptr<C_System>> & C_Game_System_List<C_System>::M_Get_System_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定された名前のシステムのアドレスを返す
	// 引数   ：void
	// 戻り値 ：C_System * 名前が一致したシステムのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline C_System * C_Game_System_List<C_System>::M_Get_System_By_Name(std::string in_search_name)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_System>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();	// システムのリスト


		// 全てのシステムを探索し、見つかったらそのアドレスを返す
		for (Type_System & now_sound : sound_list)
		{
			if (now_sound.get()->M_Get_Instance_Name() == in_search_name)
			{
				return now_sound.get();
			}
		}

		// 見つからなかった場合は、nullを返す
		return nullptr;
	}


	//-☆- 更新 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：システムの更新を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Instance_Update(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_System>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Game_System_List, Type_System>::M_Get_List();	// システムのリスト


		// システムを更新する
		for (Type_System & now_sound : sound_list)
		{
			now_sound->M_System_Update();
		}

		return;
	}


	//-☆- 描画 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：描画はないがエラー防止用に定義
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SYSTEM_TEMPLATE inline void C_Game_System_List<C_System>::M_Instance_Draw(void)
	{
		return;
	}
}


// ☆ マクロ削除 ☆ //
#undef D_SYSTEM_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_SYSTEM_LIST_H_FILE


