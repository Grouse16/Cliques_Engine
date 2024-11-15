//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンパイルがGCCかMSVCのどちらであるかを判定するマクロ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE
#define D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE


// ☆ マクロ ☆ //

// GCCによるコンパイル時
#ifdef __GNUC__
#define D_GCC_COMPILE true	// GCCによるコンパイルであることを示すマクロ

// MSVCによるコンパイル時
#elif defined(_MSC_VER)
#define D_MSVC_COMPILE true	// MSVCによるコンパイルであることを示すマクロ

// どちらでもない時
#else
#define D_COMPILER_LOST true	// 不明なコンパイラによるコンパイルであることを示すマクロ
#endif

#endif // !D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE

