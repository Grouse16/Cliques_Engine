//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウズの機能を使うためのクラス
// 説明   ：ウィンドウ設定やメッセージ処理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <time.h>

#include "C_Windows_System.h"
#include "C_Wnd_Proc_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace OS::WINDOWS;


// ☆ マクロ ☆ //
#define D_ICON_ADDRESS L"data/asset/image/window/star.ico"	// アイコンハンドル

#define D_WND_WIDTH 1000	// ウィンドウの横のサイズ
#define D_WND_HEIGHT 500	// ウィンドウの縦のサイズ


// ☆ 関数 ☆ //

//==☆  プライベート  ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Windows_System::C_Windows_System(void)
{
	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウを生成する処理
// 引数   ：void
// 戻り値 ：成功したかどうか 成功してたらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Windows_System::M_Creat_Window(void)
{
	// ☆ 変数宣言 ☆ //
	WNDCLASSEX w_wc;	// WNDCLASSEX構造体の中身の準備

	std::wstring device_name_in_wstr;	// ワイド文字列でのウィンドウ名


	// ウィンドウをワイド文字列に変換
	{
		// ☆ 変数宣言 ☆ //
		int text_size = (int)con_DEVICE_NAME.size();	// 文字数


		device_name_in_wstr.resize(text_size + 1);
		device_name_in_wstr[text_size] = '\0';

		for (int l_now_text = 0; l_now_text < text_size; l_now_text++)
		{
			device_name_in_wstr[l_now_text] = con_DEVICE_NAME[l_now_text];
		}
	}


	// この構造体のサイズ
	w_wc.cbSize = sizeof(WNDCLASSEX);

	// ウィンドウのスタイル
	w_wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	// ウィンドウプロシージャのアドレス
	w_wc.lpfnWndProc = OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Get_Game_APK_Wnd_Proc();

	// 構造体の予備のメモリ
	w_wc.cbClsExtra = 0;

	// ウィンドウ側の予備のメモリ
	w_wc.cbWndExtra = 0;

	// インスタンスハンドル
	w_wc.hInstance = GetModuleHandle(0);

	// アプリのショートカットのアイコンの見ため
	w_wc.hIcon = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// ウィンドウ上のマウスカーソルの見ため
	w_wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// ウィンドウ内の背景色（クライアント領域の背景色）
	w_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	// ウィンドウのメニューの名前
	w_wc.lpszMenuName = NULL;

	// ウィンドウのクラスの名前
	w_wc.lpszClassName = device_name_in_wstr.data();

	// タイトルバーのアイコンの見ため
	w_wc.hIconSm = LoadIcon(w_wc.hInstance, D_ICON_ADDRESS);

	// レジスタにセットしてウィンドウ情報を登録
	RegisterClassEx(&w_wc);


	// ウィンドウの大きさを設定
	M_Set_Window_Size_Variable(D_WND_WIDTH, D_WND_HEIGHT);
	

	// ウィンドウの表示設定の初期化
	mpr_variable.s_wnd.h_my_wind = CreateWindowEx(

		// 拡張ウィンドウスタイル
		0,

		// ウィンドウクラスの名前
		w_wc.lpszClassName,

		// ウィンドウの名前
		device_name_in_wstr.data(),

		// ウィンドウスタイル
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_CAPTION,

		// 表示位置
		CW_USEDEFAULT,	// 左上Ｘ座標
		CW_USEDEFAULT,	// 左上Ｙ座標 

		//ウィンドウのサイズ
		(int)D_WND_WIDTH,	// ウィンドウの幅
		(int)D_WND_HEIGHT,	// ウィンドウの高さ

		// 親ウィンドウのハンドル
		NULL,

		// メニューハンドルまたは子ウィンドウID
		NULL,

		// インスタンスハンドル
		GetModuleHandle(0),

		// ウィンドウ作成データ
		NULL);


	// ウィンドウを表示
	ShowWindow(mpr_variable.s_wnd.h_my_wind, mpr_variable.m_cmd_show);

	// ウィンドウの状態を直ちに反映(ウィンドウのクライアント領域を更新)
	UpdateWindow(mpr_variable.s_wnd.h_my_wind);

	// 成功
	return true;
}


//==☆  パブリック  ☆==//

//-☆-  初期化と終了時  -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウズのシステムを初期化する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Creat_Windows_System(void)
{
	m_this_instance.reset(new C_Windows_System());

	// デバッグシステム初期化
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Init_Debug();
#endif // _DEBUG

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウズ機能の初期化用処理
// 引数   ：HINSTANCE& インスタンスハンドル, int& コマンド番号
// 戻り値 ：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Windows_System::M_Set_Up(void)
{
	// ☆ デバッグ時のみセットアップ開始を通知 ☆ //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-ウィンドウズのセットアップ開始-☆-☆-☆-☆-☆-☆-☆-");
#endif // _DEBUG


	// ウィンドウを生成する
	M_Creat_Window();


	// ☆ デバッグ時のみセットアップ完了を通知 ☆ //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::WINDOWS::con_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-ウィンドウズのセットアップに成功、GUIを起動完了-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


	// ウィンドウサイズの更新
	M_Window_Size_Update();

	// 成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Windows_System::~C_Windows_System()
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放など終了時の処理を行う
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Release(void)
{
	mpr_variable.m_cmd_show = 0;
	mpr_variable.s_wnd.h_my_wind = NULL;
	mpr_variable.s_wnd.msg_of_wnd = MSG();

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウの更新をおこなう
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Update(void)
{
	// ☆ ウィンドウの処理 ☆ //

	// ユーザーによる入力の更新
	while (PeekMessage(&mpr_variable.s_wnd.msg_of_wnd, NULL, 0, 0, PM_REMOVE) > 0)
	{
		// 文字メッセージを生成
		TranslateMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// ウィンドウプロシージャを呼び出してメッセージ更新
		DispatchMessage(&mpr_variable.s_wnd.msg_of_wnd);

		// ウィンドウが閉じたらフラグを立てそれを通知する
		if (mpr_variable.s_wnd.msg_of_wnd.message == WM_QUIT)
		{
			m_flg_os_active = false;

			break;
		}
	}

	// ウィンドウサイズの更新
	M_Window_Size_Update();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのサイズの更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Window_Size_Update(void)
{
	// ☆ 変数宣言 ☆ //
	RECT client_rect;	// クライアント領域のピクセル座標

	S_Window_Position set_window_pos;	// 設定するウィンドウ座標


	// ウィンドウのサイズを取得
	GetClientRect(mpr_variable.s_wnd.h_my_wind, &client_rect);
	M_Set_Window_Size_Variable(client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);


	// ウィンドウの位置を取得
	set_window_pos.position_left_x = client_rect.left;
	set_window_pos.position_right_x = client_rect.right;
	set_window_pos.position_top_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.top;
	set_window_pos.position_bottom_y = GetSystemMetrics(SM_CYSCREEN) - client_rect.bottom;
	M_Set_Window_Position_Variable(set_window_pos);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウの初期コマンド番号をセット
// 引数   ：int コマンド番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Set_Cmd_Show(int in_cmdshow)
{
	// ☆ 変数宣言 ☆ //
	C_Windows_System * wind_os_system = static_cast<C_Windows_System*>(m_this_instance.get());	// ウィンドウズOS用のシステム


	wind_os_system->mpr_variable.m_cmd_show = in_cmdshow;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：自ウィンドウのハンドルを返す
// 引数   ：void
// 戻り値 ：HWND 自ウィンドウのハンドル
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
HWND C_Windows_System::M_Get_Window_Handle(void)
{
	return static_cast<C_Windows_System*>(m_this_instance.get())->mpr_variable.s_wnd.h_my_wind;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の時間を引数の参照先に渡す
// 引数   ：S_Time_Inform & 時間の設定先
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Get_Now_Time(OS::S_Time_Inform & in_set_time_inform)
{
	// ☆ 変数宣言 ☆ //
	time_t get_time = time(nullptr);	// 時間情報

	tm time_data;	// 時間情報を解析したデータ


	// 時間情報をデータに変換
	localtime_s(&time_data, &get_time);


	// 日付を設定
	in_set_time_inform.year = time_data.tm_year + 1900;	// 年、入手した情報は1900年分省略されているため訂正
	in_set_time_inform.month = time_data.tm_mon + 1;	// 月、入手した情報が０始まりで月を計算しているので訂正(0～11 + 1 = 1～12)
	in_set_time_inform.day = time_data.tm_mday;			// 日

	// 時刻を設定
	in_set_time_inform.hour = time_data.tm_hour;
	in_set_time_inform.minute = time_data.tm_min;
	in_set_time_inform.second = time_data.tm_sec;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：経過時間をミリ秒単位で取得する
// 引数   ：unsigned __int64 & 取得先の時間変数の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Get_Now_Milli_Second(unsigned __int64 & in_plz_set_this_timer)
{// * GetTickCount64が1.26ナノ秒で最速なので使用している
	in_plz_set_this_timer = GetTickCount64();

	return;
}


//-☆- ウィンドウ機能 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのタイトルを編集する
// 引数   ：const wstring & セットするタイトル名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_System::M_Set_Window_Title(const std::wstring & in_set_title_name)
{
	// ウィンドウタイトルをセット
	SetWindowText(mpr_variable.s_wnd.h_my_wind, in_set_title_name.c_str());

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッセージボックスを表示する(ウィンドウハンドルを必要とするため)
// 引数   ：const wstring & タイトル, const wstring & 表示内容, const unsigned int メッセージボックスの種類
// 戻り値 ：int ウィンドウ入力の結果
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Windows_System::M_Creat_Massage_Box(const std::wstring & in_title, const std::wstring & in_text, const unsigned int in_type)
{
	return MessageBox(mpr_variable.s_wnd.h_my_wind, in_text.c_str(), in_title.c_str(), in_type);
}


#endif // OS_IS_WINDOWS

