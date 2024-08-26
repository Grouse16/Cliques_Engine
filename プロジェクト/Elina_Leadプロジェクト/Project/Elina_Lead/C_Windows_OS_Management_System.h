//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウズの機能を使うためのクラス
// 説明   ：ウィンドウ設定やメッセージ処理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H
#define D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <Windows.h>
#include <memory>
#include <string>

#include "C_OS_Management_System_Base.h"


// ☆ ネームスペース ☆ //

// ウィンドウズ用のシステムを呼び出すための名前
namespace OS::WINDOWS
{
	// ☆ クラス ☆ //

	// ウィンドウズOS制御システムのクラス
	class C_Windows_OS_Management_System : public OS::BASE::C_OS_Management_System_Base
	{
		//==☆  プライベート  ☆==//
	private:

		// ☆ 構造体 ☆ //

		// 変数をしまうための構造体
		struct SPr_Variable
		{
			// ウィンドウ用情報の構造体
			struct S_WND
			{
				HWND h_my_wind = nullptr;	// 自ウィンドウのハンドル

				MSG msg_of_wnd = MSG();	// ウィンドウの処理用の変数

			} s_wnd;	// ウィンドウ

			int m_cmd_show = 0;	// 画面にウィンドウを表示するための値

		} mpr_variable;	// このクラスの変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、通常の方法でインスタンス化出来なくする
		C_Windows_OS_Management_System(void);

		// ウィンドウを生成する処理
		bool M_Create_Window(void);

		
		//-☆- 入力 -☆-//

		// マウス入力の更新
		void M_Mouse_Input_Update(void);


		//==☆  パブリック  ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆-  初期化と終了時  -☆-//

		// ウィンドウズ用のシステムを生成する
		static void M_Create_Windows_System(void);

		// ウィンドウズ機能の初期化用処理、引数：HINSTANCE& インスタンスハンドル, int& コマンド番号
		bool M_Set_Up(void) override;

		// デストラクタ
		~C_Windows_OS_Management_System(void);

		// メモリ解放
		void M_Release(void) override;


		//-☆- 更新 -☆-//

		// ウィンドウの更新をおこなう
		void M_Update(void) override;

		// ウィンドウのサイズの更新を行う
		void M_Window_Size_Update(void) override;

		// 時間を更新する
		void M_Update_Time(void) override;


		//-☆- セッタ -☆-//

		// ウィンドウの初期コマンド番号をセット　引数：コマンド番号
		static void M_Set_Cmd_Show(int);


		//-☆- ゲッタ -☆-//

		// 自ウィンドウのハンドルを返す
		static HWND M_Get_Window_Handle(void);


		//-☆- ウィンドウ機能 -☆-//

		// ウィンドウのタイトルを編集する　引数：セットするタイトル名(const)
		void M_Change_Window_Title(const std::wstring &) override;

		// メッセージボックスを表示する　引数：タイトル(const), 表示内容(const), メッセージボックスの種類
		int M_Create_Massage_Box(const std::wstring &, const std::wstring &, unsigned int) override;
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

