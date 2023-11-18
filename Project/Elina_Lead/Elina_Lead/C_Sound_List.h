//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サウンド系統を管理するリストの動作をカプセル化するシステム
// 説明   ：生成、削除、取得を行って、サウンドの派生にあたるクラス以外を全てリストから弾くことができる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE
#define D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_List_Divided_By_Class_Base.h"
#include "C_Sound_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのサウンドのリストのコンセプトを呼び出すための名前
namespace GAME::INSTANCE::SOUND::LIST::CONCEPT
{
	// ☆ コンセプトクラス ☆ //

	// サウンドの派生クラスのみを登録できるようにする（テンプレート引数を制限する） (C++20なので注意)
	template<typename C_Check_Instance>
	concept C_Checked_Sound_Class = std::is_base_of<GAME::INSTANCE::SOUND::BASE::C_Sound_Base, C_Check_Instance>::value;
}


// ☆ マクロ ☆ //
#define D_SOUND_TEMPLATE template <GAME::INSTANCE::SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>	// サウンドのテンプレート定義用マクロ


// ゲームのサウンドのリストを呼び出すための名前
namespace GAME::INSTANCE::SOUND::LIST
{
	// ☆ クラス ☆ //

	// サウンド系統のリスト、サウンドをクラスごとに管理している
	D_SOUND_TEMPLATE class C_Sound_List : SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, std::unique_ptr<C_Sound>>
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 定義 ☆ //
		typedef std::unique_ptr<C_Sound> Type_Sound;	// サウンドのクラスを使用するときの型


		// ☆ 変数宣言 ☆ //
		static C_Sound_List<C_Sound> m_sound_list_this;	// シングルトン化用のインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ　シングルトン化する
		C_Sound_List(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Sound_List(void);


		//-☆- 生成 -☆-//

		// サウンドを生成する　引数：string 生成するサウンドの名前　戻り値：C_Sound * 生成したサウンドのアドレス
		static C_Sound * M_Create_Sound(std::string);


		//-☆- 削除 -☆-//

		// 削除のフラグが立っているサウンドを消す
		static void M_Delete_Sound_Update(void);

		// インスタンスの削除を行う
		void M_Delete_Instance_Execute(void) override;

		// 全てのインスタンスの削除を行う
		void M_Delete_All_Instance_Execute(void) override;


		//-☆- ゲッタ -☆-//

		// 指定されたサウンドのリストを返す　戻り値：vector<Type_Sound> & 指定されたサウンドのリスト
		static std::vector<Type_Sound> & M_Get_Sound_List(void);

		// 指定された名前のサウンドのアドレスを返す　戻り値：C_Sound * 名前が一致したサウンドのアドレス
		static C_Sound * M_Get_Sound_By_Name(std::string);


		//-☆- 更新 -☆-//

		// サウンドの更新を行う
		void M_Instance_Update(void) override;


		//-☆- 描画 -☆-//

		// サウンドの描画を行う
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
	D_SOUND_TEMPLATE inline C_Sound_List<C_Sound>::C_Sound_List(void)
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
	D_SOUND_TEMPLATE inline C_Sound_List<C_Sound>::~C_Sound_List(void)
	{
		// 所持しているリストを全て開放しホルダーも削除する
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_All_Instance();

		return;
	}


	//-☆- 生成 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：サウンドを生成する
	// 引数   ：string 生成するサウンドの名前
	// 戻り値 ：C_Sound * 生成したサウンドのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline C_Sound * C_Sound_List<C_Sound>::M_Create_Sound(std::string in_sound_name)
	{
		// ☆ 変数宣言 ☆ //
		Type_Sound & sound_slot_address =		// 新しいサウンド用のスロットの参照

			// 新しいサウンド用のスロットを生成する
			SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Create_Instance(in_sound_name);


		// サウンドを生成し、そのサウンドのクラス用のリストに格納する
		sound_slot_address.reset(new C_Sound());

		// 新しく生成されたサウンドのアドレスを返す
		return sound_slot_address.get();
	}


	//-☆- 削除 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：削除のフラグが立っているサウンドを消す
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_Sound_Update(void)
	{
		// ☆ ラムダ式 ☆ //

		// ベクターからインスタンス削除用の判定を行うラムダ式
		auto delete_ramada = [](Type_Sound & in_check_sound)
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
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_Instance_By_Lambda(delete_ramada);

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：インスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_Instance_Execute(void)
	{
		M_Delete_Sound_Update();

		return;
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：全てのインスタンスの削除を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Delete_All_Instance_Execute(void)
	{
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Delete_All_Instance();

		return;
	}


	//-☆- ゲッタ -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定されたサウンドのリストを返す
	// 引数   ：void
	// 戻り値 ：vector<unique_ptr<C_Sound>> & 指定されたサウンドのリスト
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline std::vector<std::unique_ptr<C_Sound>> & C_Sound_List<C_Sound>::M_Get_Sound_List(void)
	{
		return SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();
	}


	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：指定された名前のサウンドのアドレスを返す
	// 引数   ：void
	// 戻り値 ：C_Sound * 名前が一致したサウンドのアドレス
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline C_Sound * C_Sound_List<C_Sound>::M_Get_Sound_By_Name(std::string in_search_name)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Sound>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();	// サウンドのリスト


		// 全てのサウンドを探索し、見つかったらそのアドレスを返す
		for (Type_Sound & now_sound : sound_list)
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
	// 詳細   ：サウンドの更新を行う
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Instance_Update(void)
	{
		// ☆ 変数宣言 ☆ //
		std::vector<std::unique_ptr<C_Sound>> & sound_list = SYSTEM::LIST::BASE::C_List_Divided_By_Class_Base<C_Sound_List, Type_Sound>::M_Get_List();	// サウンドのリスト


		// サウンドを更新する
		for (Type_Sound & now_sound : sound_list)
		{
			now_sound->M_Sound_Update();
		}

		return;
	}


	//-☆- 描画 -☆-//

	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	// 詳細   ：描画はないがエラー防止用に定義
	// 引数   ：void
	// 戻り値 ：void
	//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
	D_SOUND_TEMPLATE inline void C_Sound_List<C_Sound>::M_Instance_Draw(void)
	{
		return;
	}
}


// ☆ マクロ削除 ☆ //
#undef D_SOUND_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_SOUND_LIST_H_FILE


