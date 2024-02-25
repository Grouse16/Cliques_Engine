//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォーム検出用マクロ
// 説明   ：https://www.yokoweb.net/dokuwiki/programing/c-language/compiler-os-macro-define
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE
#define D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


// ☆ マクロ ☆ //

//-☆- ウィンドウズ -☆-//
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__MINGW32__) || defined(__MINGW64__) || defined(_WINDOWS) || defined(_CONSOLE)) && !defined(__CYGWIN__)

// ウィンドウズOSであることを示すマクロ
#define D_OS_IS_WINDOWS


//-☆- マック -☆-//
#elif defined(__MACH__)

// マックOSであることを示すマクロ
#define D_OS_IS_MAC


//-☆- リナックス -☆-//
#elif defined(__linux__) || defined(__linux)

// リナックスOSであることを示すマクロ
#define D_OS_IS_LINUX


//-☆- ユニックス -☆-//
#elif defined(__unix__) || defined(__unix) || defined(__CYGWIN__)

// ユニックスOSであることを示すマクロ
#define D_OS_IS_UNIX


//-☆- 検知不可 -☆-//
#else

// OSを検知できなかったことを示すマクロ
#define D_OS_IS_UNKNOWN

#endif


#endif // !D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

