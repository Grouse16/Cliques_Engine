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

#include "E_MOUSE_CLICK_STATE.h"
#include "S_Window_Size_Data.h"
#include "S_Mouse_State.h"
#include "S_Window_Position.h"
#include "S_Day_And_Time_Inform.h"


// ☆ ネームスペース ☆ //

// OSの基底クラスを呼び出すための名前
namespace OS::BASE
{
	// ☆ クラス ☆ //

	// OS制御システムの基底クラス
	class C_OS_Management_System_Base
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		OS::S_Window_Size_Data m_size_of_window;	// ウィンドウのサイズ

		OS::S_Window_Position m_position_window;	// ウィンドウの位置座標

		OS::S_Mouse_State m_mouse_state;	// マウス座標

		std::wstring m_title_name = L"Elina Lead";	// ウィンドウタイトル名

		S_Day_And_Time_Inform m_now_day_and_time;	// 現在の時間

		unsigned __int64 m_now_time_by_start_in_milli_second;	// 実行されてからのミリ秒単位での経過時間


	//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		static std::unique_ptr<C_OS_Management_System_Base> m_this_instance;	// インスタンス化用プライベート変数

		static bool m_flg_os_active;	// OSを終了させるフラグ


		// ☆ 関数 ☆ //

		//-☆- セッタ -☆-//

		// ウィンドウのタイトル名をセットする　引数：セットするウィンドウタイトル
		void M_Set_Window_Title_Name(std::wstring);

		// 現在の時間をセットする　引数：セットする現在の時間
		void M_Set_Now_Day_And_Time(const S_Day_And_Time_Inform & );

		// 実行されてからのミリ秒単位での経過時間のセッタ　引数：セットする経過時間
		void M_Set_Now_Time_By_Start_In_Milli_Second(unsigned __int64);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_OS_Management_System_Base(void);

		// OSの初期化を行う
		virtual bool M_Set_Up(void) = 0;

		// メモリ解放
		virtual void M_Release(void) = 0;

		// OSシステムを削除する
		static void M_Delete_OS_System(void);

		// デストラクタ
		virtual ~C_OS_Management_System_Base(void);


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
		void M_Set_Window_Position_Variable(S_Window_Position & );

		// 左クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Left_Click_State(E_MOUSE_CLICK_STATE);

		// 右クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Right_Click_State(E_MOUSE_CLICK_STATE);

		// 中クリックのフラグをセットする　引数：クリックの状態
		void M_Set_Center_Click_State(E_MOUSE_CLICK_STATE);


		//-☆- ゲッタ -☆-//

		// OS用システムのインスタンスのアドレスを返す
		static C_OS_Management_System_Base * M_Get_Instance(void);

		// OSのシステムが停止したかどうかを返す
		static bool M_Get_OS_Active(void);

		// ウィンドウのサイズを返す　戻り値：ウィンドウサイズ
		const S_Window_Size_Data & M_Get_Window_Size(void) const;

		// ウィンドウのアスペクト比を返す　戻り値：アスペクト比
		float M_Get_Aspect_Ratio(void) const;

		// ウィンドウの座標を返す　戻り値：ウィンドウ座標
		const S_Window_Position & M_Get_Window_Position(void) const;

		// マウスの状態を返す　戻り値：マウスの状態
		const S_Mouse_State & M_Get_Mouse_State(void) const;

		// 現在の時間の参照を返す　戻り値：現在の時間の参照(const)
		const S_Day_And_Time_Inform & M_Get_Now_Day_And_Time(void) const;

		// 経過時間をミリ秒単位で取得する　戻り値：取得先の時間変数の参照
		unsigned __int64 M_Get_Now_Milli_Second_By_Start_Application(void) const;

		// ウィンドウのタイトル名を返す　戻り値：ウィンドウタイトル名
		std::wstring M_Get_Window_Title_Name(void) const;


		//-☆- ウィンドウ機能 -☆-//

		// ウィンドウのタイトルを編集する　引数：セットするタイトル名(const)
		virtual void M_Change_Window_Title(const std::wstring & ) = 0;

		// メッセージボックスを表示する　引数：タイトル(const), 表示内容(const), メッセージボックスの種類
		virtual int M_Create_Massage_Box(const std::wstring &, const std::wstring &, unsigned int ) = 0;
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
