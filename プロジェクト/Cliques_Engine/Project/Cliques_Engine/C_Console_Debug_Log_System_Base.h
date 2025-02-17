//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ログをコンソールとファイルに出力するクラス
// 説明   ：デバッグ用にログを記録する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM
#define D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>

#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"


// ☆ ネームスペース ☆ //

// デバッグログのコンソールの基底クラスを呼び出すための名前
namespace DEBUGGER::LOG::CONSOLE::BASE
{
	// ☆ クラス ☆ //

	// デバッグログ出力用システムの基底クラス
	class C_Console_Debug_Log_System_Base
	{
		//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct Pr_Variable
		{
			FILE * console_file = nullptr;	// コンソールの出力先

			int text_color = 0;	// コンソールのテキストの色
			int color_back = 0;	// コンソールの背景色

			bool initialized = false;	// 初期化されたかどうかのフラグ

		} static mpr_variable;	// プライベート変数を呼び出すための名前

		static std::unique_ptr<C_Console_Debug_Log_System_Base> m_this;	// ログシステム用クラスの実体（シングルトン）


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ、インスタンス化防止のために隠蔽
		C_Console_Debug_Log_System_Base(void);

		// デストラクタ
		virtual ~C_Console_Debug_Log_System_Base(void);

		// デバッグシステムの初期化と生成
		virtual void M_Init_Debug(void) = 0;

		// デバッグログシステムを削除する
		virtual void M_Delete_Console_Debug_Log_System(void) = 0;

		// デバッグログシステムを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// コンソールログシステムのインスタンスのアドレスを返す　戻り値：コンソールログシステムの参照
		static C_Console_Debug_Log_System_Base * M_Get_Console_Debug_Log_System(void);


		//-☆- ログ出力 -☆-//

		// 指定された文字列を設定されたファイル名で出力する　引数：ログの種類, 記録するファイル名, 記録内容
		virtual void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) = 0;

		// 処理を止めてログを出す
		virtual void M_Stop_Update_And_Log_Present(void) = 0;

		// コンソールのログを初期化する
		virtual void M_Console_Log_Flush(void) = 0;

		// コンソールの文字カラーを変更する　引数：設定する色番号
		virtual void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// コンソールの背景カラーを変更する　引数：設定する色番号
		virtual void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// コンソールの文字と背景カラーを変更する　引数：文字の色, 背景の色
		virtual void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

