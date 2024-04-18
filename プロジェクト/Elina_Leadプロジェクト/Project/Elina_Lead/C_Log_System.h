//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エラーログをファイルとして出力するクラス
// 説明   ：デバッグ用に存在するエラー時にログをフォルダとして記録する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM
#define D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM


// ☆ ファイルひらき ☆ //
#include <string>


// ☆ ネームスペース ☆ //

// デバッグ用のシステムのログシステムを呼び出すための名前
namespace DEBUGGER::LOG
{
	// ☆ 定数 ☆ //

	// ログの識別用番号
	enum class E_LOG_TAGS
	{
		//-☆- システム -☆-//
		e_SET_UP = 0,	// 初期化時
		e_SHUT_DOWN,	// シャットダウン時


		//-☆- アプリケーション -☆-//
		e_OBJECT,			// オブジェクトによるログ
		e_GAME_RENDERING,	// ゲーム上の描画によるログ
		e_UI				// UIによるログ
	};

	// ログの表示カラー設定用の番号
	enum class E_LOG_COLOR
	{
		e_WHITE,	// 白
		e_BLACK,	// 黒
		e_BLUE,		// 青
		e_GREEN,	// 緑
		e_RED,		// 赤
		e_PURPLE,	// 紫
	};


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
		};
	};


	// ☆ クラス ☆ //

	// エラーログをファイルとして出力するクラス
	class C_Log_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct Pr_Variable
		{
			FILE* console_file = nullptr;	// コンソールの出力先

			int color_text = 0;	// コンソールのテキストの色
			int color_back = 0;	// コンソールの背景色

			bool initialized = false;	// 初期化されたかどうかのフラグ

		} static mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Log_System m_this;	// ログシステム用クラスの実体（シングルトン）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、インスタンス化防止のために隠蔽
		C_Log_System(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// デバッグシステムの初期化
		static void M_Init_Debug(void);

		// デストラクタ、インスタンス化防止のために隠蔽
		~C_Log_System(void);


		//-☆- ログ出力 -☆-//

		// 指定された文字列を設定されたファイル名で出力する、引数 E_LOG_TAGS ログの種類, string 記録するファイル名, string 記録内容
		static void M_Print_Log(E_LOG_TAGS, std::string, std::string);

		// 処理を止めてログを出す
		static void M_Stop_Update_And_Log_Present(void);

		// コンソールのログを初期化する
		static void M_Console_LOG_Flush(void);

		// コンソールの文字カラーを変更する、引数 E_LOG_COLOR 設定する色番号
		static void M_Set_Console_Text_Color(E_LOG_COLOR);

		// コンソールの背景カラーを変更する、引数 E_LOG_COLOR 設定する色番号
		static void M_Set_Console_Back_Ground_Color(E_LOG_COLOR);

		// コンソールの文字と背景カラーを変更する、引数 E_LOG_COLOR 文字の色, 背景の色
		static void M_Set_Console_Color_Text_And_Back(E_LOG_COLOR, E_LOG_COLOR);
	};
}


#endif // !D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

