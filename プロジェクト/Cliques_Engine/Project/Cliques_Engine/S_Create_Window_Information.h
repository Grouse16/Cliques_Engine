//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウの生成用の情報を格納する構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "S_Window_Position.h"
#include "S_Window_Size.h"


// ☆ ネームスペース ☆ //

// ウィンドウ用のデータを呼び出すための名前
namespace PLATFORM::WINDOW::CREATE
{
	// ☆ 構造体 ☆ //

	// ウィンドウの生成用の情報を格納する構造体
	struct S_Create_Window_Information
	{
		PLATFORM::WINDOW::DATA::S_Window_Position m_position;	// 初期座標
		
		PLATFORM::WINDOW::DATA::S_Window_Size m_size;	// 初期サイズ

		std::wstring m_class_name = L"Default";	// ウィンドウクラス名

		std::wstring m_name = L"Default";	// ウィンドウ名

		std::wstring m_parent_name = L"Default";	// 親ウィンドウ名

		std::wstring m_child_name = L"Default";	// 子ウィンドウ名
	};
}



#endif // !D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE

