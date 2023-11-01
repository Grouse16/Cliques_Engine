//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの機能を制御するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER
#define D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER


// ☆ ファイルひらき ☆ //
#include <string>
#include <vector>

#include "C_Engine_Function_Base.h"


// ☆ ネームスペース ☆ //

// エンジンの機能を制御するシステムを呼び出すための名前
namespace GAME::FUNCTION
{
	// ☆ クラス ☆ //

	// エンジンの機能を制御するクラス
	class C_Engine_Function_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPR_Variable
		{
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > function_list;	// 機能を管理する配列

			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > before_func_update_list;	// シーン処理前に更新する機能のリスト
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > after_func_update_list;	// シーン処理後に更新する機能のリスト
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > before_func_draw_list;		// 描画する機能のリスト
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > after_func_draw_list;			// 描画する機能のリスト

			std::vector<std::string> function_create_kind_list;	// 機能の生成要求をまとめたリスト

			bool flg_reset_list = false;	// リストをリセットするかどうかのフラグ、一部の機能の優先度が変更されたときにもう一度設定しなおすタイミングを指定するために設定する

		} static mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Engine_Function_Manager m_this;	// エンジン制御用のシステムの実体(シングルトン)


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化に使用
		C_Engine_Function_Manager(void);


		//-☆- 生成 -☆-//

		// 指定された機能の型の生成を実行する
		template <class TYPE_CREATE_FUNCTION>
		static C_Engine_Function_Base * M_Creat_Function_Excute(void)
		{
			// ☆ 変数宣言 ☆ //
			C_Engine_Function_Base * new_function_address = nullptr;	// 新しい


			// 生成してリストに加える
			new_function_address = new TYPE_CREATE_FUNCTION;
			mpr_variable.function_list.reserve(mpr_variable.function_list.size() + 1);
			mpr_variable.function_list.emplace_back(new_function_address);

			return new_function_address;
		}


		//-☆- 機能 -☆-//

		// 機能の生成を行う　引数：生成する機能の名前
		static void M_Create_Function_By_Kind(std::string);

		// シーン処理前に更新する機能を追加
		static void M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// シーン処理後に更新する機能を追加
		static void M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// シーン前の描画する機能を追加する
		static void M_Set_Before_Draw_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// シーン後の描画する機能を追加する
		static void M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// 指定されたアドレスの機能をすべての登録から削除する　引数：削除する機能のアドレス
		static void M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Engine_Function_Base *);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Engine_Function_Manager(void);

		// メモリ解放
		static void M_Release_Memory(void);


		//-☆- 更新 -☆-//

		// シーン処理前の機能の更新を行う
		static void M_Before_Scene_Update(void);

		// シーン処理後の機能の更新を行う
		static void M_After_Scene_Update(void);

		// シーン処理前の機能の描画を行う
		static void M_Before_Scene_Draw(void);

		// シーン処理後の機能の描画を行う
		static void M_After_Scene_Draw(void);


		//-☆- 機能 -☆-//

		// 削除のフラグがたった機能を消す
		static void M_Delete_Function(void);

		// 生成する要求のあった機能を全て生成する
		static bool M_Execute_Create_Function_By_List(void);

		// 機能の生成を要求する、引数：string 生成する機能の名前
		static void M_Command_Create_Function(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

