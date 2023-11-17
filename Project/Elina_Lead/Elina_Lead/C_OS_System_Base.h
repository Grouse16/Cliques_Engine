//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：OSのシステムを制御するための基底クラス
// 説明   ：OSの挙動などを指定する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>
#include <memory>


// ☆ ネームスペース ☆ //

// OSの基底クラスを呼び出すための名前
namespace OS
{
	// ☆ 列挙型 ☆ //

	// マウスのクリック状態を指定する列挙
	enum class E_MOUSE_CLICK_STATE
	{
		e_NON,			// 何もしていない
		e_CLICK,		// クリック中
		e_DOUBLE_CLICK,	// ダブルクリック中
	};


	// ☆ 構造体 ☆//

	// ウィンドウのサイズ指定用の構造体
	struct S_Window_Size_Data
	{
		int width = 0;	// 画面横のサイズ
		int height = 0;	// 画面縦のサイズ
	};

	// マウス座標用の構造体
	struct S_Mouse_State
	{
		E_MOUSE_CLICK_STATE left_click = E_MOUSE_CLICK_STATE::e_NON;	// 左クリックの状態
		E_MOUSE_CLICK_STATE center_click = E_MOUSE_CLICK_STATE::e_NON;	// 中クリックの状態
		E_MOUSE_CLICK_STATE right_click = E_MOUSE_CLICK_STATE::e_NON;	// 右クリックの状態

		int x = 0;	// マウス座標ｘ
		int y = 0;	// マウス座標ｙ
	};

	// ウィンドウの位置を指定する構造体
	struct S_Window_Position
	{
		int position_left_x = 0;	// ウィンドウの左端
		int position_right_x = 0;	// ウィンドウの右端
		int position_top_y = 0;		// ウィンドウの上端
		int position_bottom_y = 0;	// ウィンドウの下橋
	};

	// 日付と時間情報の構造体
	struct S_Time_Inform
	{
		int year = 0;	// 年
		int month = 0;	// 月
		int day = 0;	// 日

		int hour = 0;	// 時
		int minute = 0;	// 分
		int second = 0;	// 秒
	};


	// ☆ 定数 ☆ //
	const std::wstring con_DEVICE_NAME = L"Elina Lead";	// デバイス名


	// ☆ クラス ☆ //

	// OSシステムの基底クラス
	class C_OS_System_Base
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		OS::S_Window_Size_Data m_size_of_window;	// ウィンドウのサイズ

		OS::S_Window_Position m_position_window;	// ウィンドウの位置座標

		OS::S_Mouse_State m_mouse_state;	// マウス座標


	//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		static std::unique_ptr<C_OS_System_Base> m_this_instance;	// インスタンス化用プライベート変数

		static bool m_flg_os_active;	// OSを終了させるフラグ


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_OS_System_Base(void);

		// OSの初期化を行う
		virtual bool M_Set_Up(void) = 0;

		// メモリ解放
		virtual void M_Release(void) = 0;

		// OSシステムを削除する
		static void M_Delete_OS_System(void);

		// デストラクタ
		virtual ~C_OS_System_Base(void);


		//-☆- 更新 -☆-//

		// 更新を行う
		virtual void M_Update(void) = 0;

		// ウィンドウのサイズの更新
		virtual void M_Window_Size_Update(void) = 0;


		//-☆- セッタ -☆-//

		// マウス座標をセットする　引数：ｘ座標, ｙ座標
		void M_Set_Mouse_Position_Variable(int, int);

		// 画面サイズをセットする　引数：横幅,　縦幅
		void M_Set_Window_Size_Variable(int, int);

		// ウィンドウの座標をセットする　引数：
		void M_Set_Window_Position_Variable(S_Window_Position&);

		// 左クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Left_Click_State(E_MOUSE_CLICK_STATE);

		// 右クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Right_Click_State(E_MOUSE_CLICK_STATE);

		// 中クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Center_Click_State(E_MOUSE_CLICK_STATE);


		//-☆- ゲッタ -☆-//

		// OS用システムのインスタンスのアドレスを返す
		static C_OS_System_Base * M_Get_Instance(void);

		// OSのシステムが停止したかどうかを返す
		static bool M_Get_OS_Active(void);

		// ウィンドウのサイズを返す　戻り値：ウィンドウサイズ
		const S_Window_Size_Data & M_Get_Window_Size(void);

		// ウィンドウの座標を返す　戻り値：ウィンドウ座標
		const S_Window_Position & M_Get_Window_Position(void);

		// マウスの状態を返す　戻り値：マウスの状態
		const S_Mouse_State & M_Get_Mouse_State(void);

		// 現在の時間を引数の参照先に渡す
		virtual void M_Get_Now_Time(S_Time_Inform & ) = 0;

		// 経過時間をミリ秒単位で取得する　引数：取得先の時間変数の参照
		virtual void M_Get_Now_Milli_Second(unsigned __int64 & ) = 0;


		//-☆- ウィンドウ機能 -☆-//

		// ウィンドウのタイトルを編集する　引数：const std::wstring & セットするタイトル名
		virtual void M_Set_Window_Title(const std::wstring & ) = 0;

		// メッセージボックスを表示する(ウィンドウハンドルを必要とするため)　引数：const std::wstring タイトル, const std::wstring 表示内容, const unsigned int メッセージボックスの種類
		virtual int M_Create_Massage_Box(const std::wstring &, const std::wstring &, const unsigned int ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
