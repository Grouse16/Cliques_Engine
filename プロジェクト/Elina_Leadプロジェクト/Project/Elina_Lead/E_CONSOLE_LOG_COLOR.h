//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールの出力時の文字の色
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_COONSOLE_LOG_COLOR_H_FILE
#define D_INCLUDE_GUARD_E_COONSOLE_LOG_COLOR_H_FILE


// ☆ ネームスペース ☆ //

// デバッグログ用のコンソールを呼び出すための名前
namespace DEBUGGER::LOG::CONSOLE::COLOR
{
	// ☆ 定数 ☆ //

	// コンソールの出力時の文字の色
	enum class E_CONSOLE_LOG_COLOR
	{
		e_BLACK,		// 黒
		e_GRAY,			// 灰色
		e_WHITE,		// 白
		e_LIGHT_WHITE,	// 明るい白
		e_RED,			// 赤
		e_PINK,			// ピンク
		e_GREEN,		// 緑
		e_LIGHT_GREEN,	// 黄緑
		e_BLUE,			// 青
		e_LIGHT_BLUE,	// 水色
		e_PURPLE,		// 紫
		e_LIGHT_PURPLE,	// 明るい紫
		e_YELLOW,		// 黄
		e_LIGHT_YELLOW,	// 明るい黄
		e_CYAN,			// シアン（青紫）
		e_LIGHT_CYAN,	// 明るいシアン（青紫）
	};
}


#endif // !D_INCLUDE_GUARD_E_COONSOLE_LOG_TAGS_H_FILE