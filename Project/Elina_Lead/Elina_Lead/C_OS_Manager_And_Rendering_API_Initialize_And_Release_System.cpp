//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：グラフィックスAPIを初期化するためのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"
#include "Platform_Detector_Macro.h"
#include "C_Platform_Detection_System.h"


// ☆ ウィンドウズOSの時のみDirextXを有効化 ☆ //
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_OS_Management_System.h"
#include "C_DX12_System.h"
#endif // D_OS_IS_WINDOWS


// ☆ マクロ ☆ //
#if _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace PLATFORM;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System(void)
{
	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OS制御システムの初期化を行う
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Set_Up();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIの初期化を行う
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_Rendering_API(void)
{
	// ☆ 初期化するAPIによって分岐 ☆ //
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
		// ☆ ウィンドウズOSの時のみDirectXを有効化 ☆ //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX11:

		break;

		//  DX12  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX12:

		// DX12の初期化
		RENDERING::GRAPHICS::DX12::C_DX12_System::M_Create_DirectX12();
		return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Up();

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case PLATFORM::E_RENDERING_API_KIND::e_OPENGL:


		// レンダリングAPIがOpenGLであることを示す
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;


		//  Vulkan  //
	case PLATFORM::E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  なにも生成できなかったのでエラーを出して終了  //
	default:
		return false;
		break;
	}

	// 初期化に成功
	return true;
}


//==☆ パブリック ☆==//

//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウズOS制御システムのときのみ必要なコマンド番号を指定する、これがないとウィンドウを生成できない
// 引数   ：int コマンド番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Set_CMD_Number(int in_set_cmd)
{
	// ウィンドウズ時はコマンド番号をセット
#ifdef D_OS_IS_WINDOWS

	// DirectX使用時のみでよい
	if (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::E_RENDERING_API_KIND::e_DX11 ||
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::E_RENDERING_API_KIND::e_DX12)
	{
		OS::WINDOWS::C_Windows_OS_Management_System::M_Set_Cmd_Show(in_set_cmd);
	}

#endif

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OS制御システムの生成を行う
// 引数   ：E_RENDERING_API_KIND 使用するAPIの種類への参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(E_RENDERING_API_KIND in_use_api_kind)
{
	// ☆ ウィンドウズ非対応時はOpenGLに切り替える ☆ //
	if ((in_use_api_kind == E_RENDERING_API_KIND::e_DX12 || in_use_api_kind == E_RENDERING_API_KIND::e_DX11) && PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Platform_Number() != PLATFORM::E_OS_KIND::e_WINDOWS)
	{
		in_use_api_kind = E_RENDERING_API_KIND::e_OPENGL;
	}


	// ☆ 初期化するAPIによって分岐 ☆ //
	switch (in_use_api_kind)
	{
		// ☆ ウィンドウズOSの時のみDirextXを有効化 ☆ //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case E_RENDERING_API_KIND::e_DX11:

		// ウィンドウズの生成
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();


		// レンダリングAPIがDX11であることを示す
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX11);

		break;

		//  DX12  //
	case E_RENDERING_API_KIND::e_DX12:

		// ウィンドウズの生成
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();


		// レンダリングAPIがDX12であることを示す
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX12);

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case E_RENDERING_API_KIND::e_OPENGL:


		// レンダリングAPIがOpenGLであることを示す
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;


		//  Vulkan  //
	case E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  なにも生成できなかったのでエラーを出して終了  //
	default:
		return false;
		break;
	}

	// 初期化に成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OS制御システムとレンダリングAPIを生成する
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API(void)
{
	// OS制御システムの初期化　失敗でエラーを出して抜ける
	if (M_Init_OS() == false)
	{
		return false;
	}


	// レンダリングAPIの初期化を行う　失敗でエラーを出して抜ける
	if (M_Init_Rendering_API() == false)
	{
		return false;
	}

	return true;
}


//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OS制御システムとレンダリングAPIを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API(void)
{
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance() != nullptr)
	{
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Release();
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Delete_API();
	}

	if (OS::BASE::C_OS_Management_System_Base::M_Get_Instance() != nullptr)
	{
		OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Release();
		OS::BASE::C_OS_Management_System_Base::M_Delete_OS_System();
	}

	return;
}
