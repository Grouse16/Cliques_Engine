//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウの挙動を定義するインターフェース
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "S_Window_Position.h"
#include "S_Window_Size.h"
#include "E_OS_KIND.h"


// ☆ ネームスペース ☆ //

// ウィンドウ用のインターフェースを呼び出すための名前
namespace PLATFORM::WINDOW::INTERFACE
{
	// ☆ クラス ☆ //

	// ウィンドウの挙動を定義するインターフェース
	class I_Window_System
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- コンストラクタとデストラクタ -☆-//

		// コンストラクタ
		I_Window_System(void) = default;

		// デストラクタ
		virtual ~I_Window_System(void) = default;


		//-☆- 生成 -☆-//

		// ウィンドウの生成　戻り値：生成に成功したか
		virtual bool M_Create_Window(void) = 0;

		
		//-☆- 初期化 -☆-//

		// ウィンドウの初期化　戻り値：初期化に成功したか
		virtual bool M_Init_Window(void) = 0;

		
		//-☆- 削除 -☆-//

		// ウィンドウの削除　戻り値：削除に成功したか
		virtual bool M_Delete_Window(void) = 0;


		//-☆- 更新 -☆-//

		// ウィンドウの更新　戻り値：更新に成功したか
		virtual bool M_Update_Window(void) = 0;


		//-☆- 有効と無効 -☆-//

		// ウィンドウを有効にする　戻り値：有効に成功したか
		virtual bool M_Enable_Window(void) = 0;

		// ウィンドウを無効にする　戻り値：無効に成功したか
		virtual bool M_Disable_Window(void) = 0;


		//-☆- 表示 -☆-//

		// ウィンドウを表に出す　戻り値：表に出すのに成功したか
		virtual bool M_Bring_To_Front_Window(void) = 0;

		// ウィンドウを表示する　戻り値：表示に成功したか
		virtual bool M_Show_Window(void) = 0;

		// ウィンドウを非表示にする　戻り値：非表示に成功したか
		virtual bool M_Hide_Window(void) = 0;


		//-☆- 拡張縮小 -☆-//

		// ウィンドウを拡張する　戻り値：拡張に成功したか
		virtual bool M_Expand_Window(void) = 0;

		// ウィンドウを縮小する　戻り値：縮小に成功したか
		virtual bool M_Shrink_Window(void) = 0;


		//-☆- セッタ -☆-//

		// ウィンドウの座標を設定する　引数：ウィンドウの座標
		virtual void M_Set_Window_Position(const PLATFORM::WINDOW::DATA::S_Window_Position & ) = 0;

		// ウィンドウのサイズを設定する　引数：ウィンドウのサイズ
		virtual void M_Set_Window_Size(const PLATFORM::WINDOW::DATA::S_Window_Size & ) = 0;

		// ウィンドウ名を設定する　引数：ウィンドウ名
		virtual void M_Set_Window_Name(const std::wstring & ) = 0;


		//-☆- ゲッタ -☆-//

		// ウィンドウのプラットフォームを示すデータを返す　戻り値：プラットフォームを示すデータ
		virtual PLATFORM::E_OS_KIND M_Get_Platform(void) = 0;

		// ウィンドウ識別用のデータを返す　戻り値：ウィンドウ識別用のデータ
		virtual void * M_Get_Window_Handle(void) = 0;

		// ウィンドウの座標を返す　戻り値：ウィンドウの座標
		virtual const PLATFORM::WINDOW::DATA::S_Window_Position & M_Get_Window_Position(void) = 0;

		// ウィンドウのサイズを返す　戻り値：ウィンドウのサイズ
		virtual const PLATFORM::WINDOW::DATA::S_Window_Size & M_Get_Window_Size(void) = 0;

		// ウィンドウ名を返す　戻り値：ウィンドウ名
		virtual const std::wstring & M_Get_Window_Name(void) = 0;

		// ウィンドウが有効かを返す　戻り値：ウィンドウが有効かどうか
		virtual bool M_Is_Window_Enable(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE
