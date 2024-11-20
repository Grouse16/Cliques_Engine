//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールログを出力するためのインターフェース
// 説明   ：コンソールログの生成や初期化、出力、解放を簡略化し、依存関係を切り離すためのインターフェース
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE
#define D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>	// 文字列

#include "E_CONSOLE_LOG_TAGS.h"			// コンソールログのタグ
#include "E_CONSOLE_LOG_COLOR.h"		// コンソールログの色
#include "Console_Debug_Log_Names.h"	// ログ名


// ☆ ネームスペース ☆ //

// コンソールログ用のシステムを呼び出すための名前
namespace DEBUGGER::LOG::CONSOLE
{
	// ☆ クラス ☆ //

	// コンソールログを出力するためのインターフェース
	class C_Console_Log_Interface
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、インスタンス化防止のために隠蔽
		C_Console_Log_Interface(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// デバッグログクラスを生成する、ＯＳやビルド時の設定で分岐する
		static void M_Create_And_Initialize_Console_Log_System(void);

		// デバッグログシステムを削除する
		static void M_Delete_Console_Log_System(void);


		//-☆- 出力 -☆-//

		// 指定された文字列を設定されたファイル名で出力する　引数：ログの種類, 記録するファイル名, 記録内容
		static void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string);

		// 処理を止めてログを出す
		static void M_Stop_Update_And_Log_Present(void);

		// コンソール画面に出力中のログをフラッシュ（初期化）する
		static void M_Console_LOG_Flush(void);


		//-☆- 色 -☆-//

		// コンソールの文字カラーを変更する　引数：設定する色番号
		static void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR);

		// コンソールの背景カラーを変更する　引数：設定する色番号
		static void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR);

		// コンソールの文字と背景カラーを変更する　引数：文字の色, 背景の色
		static void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR);
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE
