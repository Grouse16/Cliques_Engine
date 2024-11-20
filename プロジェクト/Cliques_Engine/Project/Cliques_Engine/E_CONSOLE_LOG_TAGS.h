//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソール向けのログの識別用番号
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE
#define D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE


// ☆ ネームスペース ☆ //

// デバッグログ用のコンソールを呼び出すための名前
namespace DEBUGGER::LOG::CONSOLE::TAGS
{
	// ☆ 定数 ☆ //

	// コンソール向けのログの識別用番号
	enum class E_CONSOLE_LOG_TAGS
	{
		//-☆- システム -☆-//
		e_SET_UP = 0,	// 初期化時
		e_SHUT_DOWN,	// シャットダウン時


		//-☆- アプリケーション -☆-//
		e_OBJECT,			// オブジェクトによるログ
		e_GAME_RENDERING,	// ゲーム上の描画によるログ
		e_UI				// UIによるログ
	};
}


#endif // !D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE