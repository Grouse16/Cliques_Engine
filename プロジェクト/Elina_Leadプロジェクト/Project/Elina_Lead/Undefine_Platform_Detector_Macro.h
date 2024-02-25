//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォーム検出用マクロを無効化するファイル、スコープ管理用
// 説明   ：https://www.yokoweb.net/dokuwiki/programing/c-language/compiler-os-macro-define
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_UNDEFINE_PLATFORM_DETECTOR_MACRO_H_FILE
#define D_INCLUDE_GUARD_UNDEFINE_PLATFORM_DETECTOR_MACRO_H_FILE


// ☆ マクロ ☆ //
#undef D_OS_IS_WINDOWS
#undef D_OS_IS_MAC
#undef D_OS_IS_LINUX
#undef D_OS_IS_UNIX
#undef D_OS_IS_UNKNOWN



#endif // !D_INCLUDE_GUARD_UNDEFINE_PLATFORM_DETECTOR_MACRO_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

