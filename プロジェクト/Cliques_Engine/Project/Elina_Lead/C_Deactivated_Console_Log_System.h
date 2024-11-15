//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールログ用のシステムを無効化するクラス
// 説明   ：リリース時などコンソールログが不要な場合に使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DEACTIVATED_CONSOLE_LOG_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DEACTIVATED_CONSOLE_LOG_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Console_Debug_Log_System_Base.h"


// ☆ ネームスペース ☆ //

// コンソールログ用のシステムを無効化するクラス
namespace DEBUGGER::LOG::CONSOLE::DEACTIVATED
{
	// ☆ クラス ☆ //

	// コンソールログ用のシステムを無効化するクラス
	class C_Deactivated_Console_Log_System : public DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Deactivated_Console_Log_System(void);

		// デバッグシステムの初期化と生成
		void M_Init_Debug(void) override;

		// デバッグログシステム無効化用クラスを生成する
		static void M_Create_Deactivated_Console_Debug_Log_System(void);

		// デストラクタ
		~C_Deactivated_Console_Log_System(void) override;

		// デバッグログシステムを削除する
		void M_Delete_Console_Debug_Log_System(void) override;


		//-☆- ログ出力 -☆-//

		// 指定された文字列を設定されたファイル名で出力する　引数：ログの種類, 記録するファイル名, 記録内容
		void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) override;

		// 処理を止めてログを出す
		void M_Stop_Update_And_Log_Present(void) override;

		// コンソールのログを初期化する
		void M_Console_Log_Flush(void) override;

		// コンソールの文字カラーを変更する　引数：設定する色番号
		void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// コンソールの背景カラーを変更する　引数：設定する色番号
		void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// コンソールの文字と背景カラーを変更する　引数：文字の色, 背景の色
		void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DEACTIVATED_CONSOLE_LOG_SYSTEM_H_FILE

