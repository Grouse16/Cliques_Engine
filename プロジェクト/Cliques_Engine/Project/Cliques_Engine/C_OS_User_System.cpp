//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：通常のシステムがOSを使用するためのレイヤー
// 説明   ：OSの初期化や内部データの変更を行わないクラスはこのシステムを介してOSを使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_OS_User_System.h"
#include "C_OS_Management_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace OS;


// ☆ クラス ☆ //

//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の時間を更新する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_User_System::M_Update_Time(void)
{
	OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Update_Time();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウサイズのデータの参照を返す
// 引数   ：void
// 戻り値 ：S_Window_Size_Data & ウィンドウサイズのデータの参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Window_Size_Data & C_OS_User_System::M_Get_Window_Size(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Size();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのアスペクト比を返す
// 引数   ：void
// 戻り値 ：float アスペクト比
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_OS_User_System::M_Get_Window_Aspect_Ratio(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Aspect_Ratio();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウ座標のデータの参照を返す
// 引数   ：void
// 戻り値 ：const S_Window_Position & ウィンドウ座標のデータの参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Window_Position & C_OS_User_System::M_Get_Window_Position(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Position();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マウスの情報のデータの参照を返す
// 引数   ：void
// 戻り値 ：const S_Mouse_State & マウスの情報のデータの参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Mouse_State & C_OS_User_System::M_Get_Mouse_State(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Mouse_State();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウタイトルを返す
// 引数   ：void
// 戻り値 ：wstring ウィンドウタイトル
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::wstring C_OS_User_System::M_Get_Window_Title(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Title_Name();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の日時のデータの参照を返す
// 引数   ：void
// 戻り値 ：const S_Day_And_Time_Inform & 現在の日時のデータの参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Day_And_Time_Inform & C_OS_User_System::M_Get_Now_Day_And_Time(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Now_Day_And_Time();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の起動時からのミリ秒単位での経過時間を返す
// 引数   ：void
// 戻り値 ：unsigned __int64 経過時間
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
unsigned __int64 C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second_By_Start_Application();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのハンドル番号や、識別番号を返す
// 引数   ：void
// 戻り値 ：void * ウィンドウのハンドル番号や、識別番号
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void * C_OS_User_System::M_Get_Window_Handle_Or_Identify(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Handle_Or_Identify();
}


// ☆ 変更 ☆ //

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウタイトルの変更
// 引数   ：wstring 変更先のウィンドウタイトル
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_User_System::M_Change_Window_Title(std::wstring in_change_title_name)
{
	OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Change_Window_Title(in_change_title_name);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッセージボックスの表示
// 引数   ：wstring 表示するタイトル, wstring 表示するメッセージ, unsigned int メッセージボックスの種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_OS_User_System::M_Create_Massage_Box(std::wstring in_massage_title, std::wstring in_massage_text, unsigned int in_massage_kind)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Create_Massage_Box(in_massage_title, in_massage_text, in_massage_kind);
}
