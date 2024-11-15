//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの生成と解放のインターフェース
// 説明   ：生成と解放の動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Initialize_And_Release.h"
#include "C_Rendering_API_Base.h"
#include "Platform_Detector_Macro.h"

#include "C_Console_Log_Interface.h"


// ☆ ウィンドウズOSの時のみDirectXを有効化 ☆ //
#ifdef D_OS_IS_WINDOWS
#include "C_DX12_System.h"
#endif // D_OS_IS_WINDOWS



// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIの初期化
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Initialize_And_Release::M_Initialize_Rendering_API(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::BASE::C_Rendering_API_Base * rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // レンダリングAPIへのアドレス


	// インスタンスが生成されていないならエラーを返す
	if (rendering_api_address == nullptr)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"レンダリングAPIのインスタンスが生成されていない状態で初期化を実行されました"
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// レンダリングAPIの初期化
	return rendering_api_address->M_Set_Up();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIのDX12を生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Initialize_And_Release::M_Create_DX12(void)
{
	// ☆ ウィンドウズOSの時のみDirectXを有効化 ☆ //
#ifdef D_OS_IS_WINDOWS
	RENDERING::API::DX12::C_DX12_System::M_Create_DirectX12();

#else

	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
	(
		DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED,
		"Windows OSを実行できる環境ではないのにDX12の生成が実行されました"
	);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

#endif // D_OS_IS_WINDOWS

	return;
}


//-☆- 解放 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIの解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Initialize_And_Release::M_Release_Rendering_API(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::BASE::C_Rendering_API_Base * rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // レンダリングAPIへのアドレス


	// レンダリングAPIが存在しているなら削除
	if (rendering_api_address != nullptr)
	{
		rendering_api_address->M_Release();
		RENDERING::API::BASE::C_Rendering_API_Base::M_Delete_API();
	}

	return;
}
