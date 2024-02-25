//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：通常のシステムがOSを使用するためのレイヤー
// 説明   ：OSの初期化や内部データの変更を行わないクラスはこのシステムを介してOSを使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "S_Window_Size_Data.h"
#include "S_Window_Position.h"
#include "S_Mouse_State.h"
#include "S_Day_And_Time_Inform.h"


// ☆ ネームスペース ☆ //

// OSのシステムを呼び出すための名前
namespace OS
{
	// ☆ クラス ☆ //

	// 通常のシステムがOSを使用するためのレイヤーのクラス
	class C_OS_User_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ゲッタ -☆-//

		// ウィンドウサイズのデータの参照を返す　戻り値：ウィンドウサイズのデータの参照(const)
		static const S_Window_Size_Data & M_Get_Window_Size(void);

		// ウィンドウのアスペクト比を返す　戻り値：アスペクト比
		static float M_Get_Window_Aspect_Ratio(void);

		// ウィンドウ座標のデータの参照を返す　戻り値：ウィンドウ座標のデータの参照(const)
		static const S_Window_Position & M_Get_Window_Position(void);

		// マウスの情報のデータの参照を返す　戻り値：マウスの情報のデータの参照(const)
		static const S_Mouse_State & M_Get_Mouse_State(void);

		// ウィンドウタイトルを返す　戻り値：ウィンドウタイトル
		static std::wstring M_Get_Window_Title(void);

		// 現在の日時のデータの参照を返す　戻り値：現在の日時のデータの参照(const)
		static const S_Day_And_Time_Inform & M_Get_Now_Day_And_Time(void);

		// 現在の起動時からのミリ秒単位での経過時間を返す　戻り値：経過時間
		static unsigned __int64 M_Get_Now_Time_Millisecond_By_Start_Application(void);

		// ウィンドウタイトルの変更　引数：変更先のウィンドウタイトル
		static void M_Change_Window_Title(std::wstring);

		// メッセージボックスの表示　引数：表示するタイトル, 表示するメッセージ, メッセージボックスの種類
		static int M_Create_Massage_Box(std::wstring, std::wstring, unsigned int);
	};
}


#endif // !D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE

