//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールログ用のテンプレートとなる文字列用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE
#define D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE


// ☆ ネームスペース ☆ //

// コンソールログ用のシステムを呼び出すための名前
namespace DEBUGGER::LOG::CONSOLE
{
	// ☆ 定数 ☆ //

	// ログに使用する文字列をまとめた構造体
	namespace ALL_LOG_NAME
	{
		// メインシステム用のログ文字列
		namespace MAIN_SYSTEM
		{
			constexpr char con_CONSOLE_CREATED[] = "Console_Created";		// コンソールの生成成功時のログタイトル
			constexpr char con_SET_UP_SUCCEEDED[] = "WIN_DX12_SET_UP_SUCCEEDED";	// ウィンドウズとDX12のシステムのセットアップ成功時のログタイトル
			constexpr char con_ALL_SET_UP_SUCCEEDED[] = "ALL_SET_UP_CLEAR";	// 全てのセットアップに成功したときのログ
			constexpr char con_END[] = "APK_END";	// アプリケーション終了時のログタイトル
		};

		// ゲーム用のログ文字列
		namespace GAME_SYSTEM
		{
			constexpr char con_GAME_INIT[] = "GAME_INIT";					// 立ち上げログ
			constexpr char con_GAME_INIT_ERROR[] = "GAME_INIT_ERROR";		// 立ち上げ失敗時のログ
			constexpr char con_GAME_SHADER_ERROR[] = "SHADER_ERROR";		// シェーダーの生成失敗時
			constexpr char con_GAME_CREATE_FUNCTION[] = "CREATE_FUNCTION";	// 機能の生成
		};

		// ゲームの描画システム用のログ文字列
		namespace GAME_RENDERING
		{
			constexpr char con_INIT[] = "GAME_RENDERING_INIT";		// 立ち上げログ
			constexpr char con_RENDERING_ERROR[] = "GAME_RENDERING";		// レンダリング系統の処理でのエラー
			constexpr char con_ERROR[] = "GAME_RENDERING_ERROR";	// エラーログ
		};

		// アプリケーションのエラーログ
		namespace APK_LOG
		{
			constexpr char con_MANAGERS_ERROR[] = "MANAGER-ERRORS";	// ウィンドウズのセットアップ成功時のログタイトル
		};

		// ウィンドウズ用のログ文字列
		namespace WINDOWS
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "Windows_Set_Up_Succeeded";	// ウィンドウズのセットアップ成功時のログタイトル
		};

		// DX12用のログ文字列
		namespace DX12
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "DX12_Set_Up_Succeeded";	// ウィンドウズのセットアップ成功時のログタイトル
			constexpr char con_SET_UP_FAILED[] = "DX12_Set_Up_Failed";		// ウィンドウズのセットアップ失敗時のログタイトル

			constexpr char con_DEVICE_DELETED[] = "DX12_Device_Deleted";	// デバイスが削除された時のログタイトル

			constexpr char con_ERROR_CHECKING[] = "DX12_ERROR_CHECKING";	// エラー検出時のログタイトル
		};
	};
}


#endif //!D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE

