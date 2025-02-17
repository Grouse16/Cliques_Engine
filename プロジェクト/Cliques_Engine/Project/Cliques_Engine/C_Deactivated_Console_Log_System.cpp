//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールログ用のシステムを無効化するクラス
// 説明   ：リリース時などコンソールログが不要な場合に使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Deactivated_Console_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DEBUGGER::LOG::CONSOLE::DEACTIVATED;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Deactivated_Console_Log_System::C_Deactivated_Console_Log_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグシステムの初期化と生成
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Init_Debug(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログシステム無効化用クラスを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System(void)
{
	// ☆ 変数宣言 ☆ //
	C_Deactivated_Console_Log_System * deactivated_console_log_system = new C_Deactivated_Console_Log_System();	// 無効化されたコンソールログシステム


	// デバッグシステムの初期化
	deactivated_console_log_system->M_Init_Debug();

	// シングルトンのインスタンスを生成
	m_this.reset(deactivated_console_log_system);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Deactivated_Console_Log_System::~C_Deactivated_Console_Log_System(void)
{
	return;
}



//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログシステムを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
{
	return;
}


//-☆- ログ出力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字列を設定されたファイル名で出力する
// 引数   ：E_CONSOLE_LOG_TAGS ログの種類, string 記録するファイル名, string 記録内容
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_log_tags, std::string in_log_file_name, std::string in_print_text)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：処理を止めてログを出す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールのログを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Console_Log_Flush(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_console_log_color)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 文字の色, E_CONSOLE_LOG_COLOR 背景の色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Deactivated_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_text_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	return;
}



