//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームのシステム制御用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_State_Manager.h"

#include <vector>


// ☆ ネームスペース ☆ //

// ゲームの制御用のシステム
namespace GAME
{
	// ☆ クラス ☆ //

	// ゲーム制御用システム
	class C_Game_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// 変数をまとめた構造体
		struct SPr_Variable
		{
			bool flg_Game_exist = true;		// ゲームが存在しているかどうかのフラグ
			bool flg_Game_activate = false;	// ゲームが稼働中かどうかのフラグ
			bool flg_OS_active_now = false;		// OSシステムが稼働中かどうかのフラグ

		} static mpr_variable;	// 変数を呼び出すための名前

		static C_Game_Manager m_this;	// ゲーム制御用のシステムの実体(シングルトン)


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Game_Manager(void);

		
		//-☆- 更新 -☆-//

		// データの更新を行う
		static void M_Data_Update(void);

		// ウィンドウタイトルの更新
		static void M_Window_Title_Update(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// ゲームの初期化
		static void M_Init(void);

		// デストラクタ
		~C_Game_Manager(void);

		// メモリ解放
		static void M_Release(void);


		//-☆- セッタ -☆-//

		// ゲームを存在している状態かどうかを設定する　引数：trueは正常に存在している
		static void M_Set_Game_Exist_Flg(bool);

		// ゲームが稼働中かどうかを設定する　引数：trueは稼働中
		static void M_Set_Game_Activate_Flg(bool);


		//-☆- ゲッタ -☆-//

		// ゲームを存在している状態かどうかを取得する　引数：trueは正常に存在している
		static bool M_Get_Game_Exist_Flg(void);

		// ゲームがアクティブ状態かどうかを返す　戻り値：アクティブ時のみture
		static bool M_Get_Game_Active_Flg(void);


		//-☆- 実行 -☆-//

		// ゲームの処理を実行する
		static void M_Executes_Process(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_MANAGER_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
