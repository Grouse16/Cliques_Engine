//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーのバイトコード用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Shader_Code.h"
#include "C_Platform_Detection_System.h"

// デバッグ時のみ
#ifdef _DEBUG

#include "C_Log_System.h"

#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER;


// ☆ 定数 ☆ //

// レンダリングAPIごとのファイル名を設定
namespace RENDER_API_FILENAME
{
	const char * C_DX12 = "_DX12.cso";	// dx12時のファイル名
	const char * C_DX11 = "_DX11.cso";	// dx11時のファイル名
	const char * C_OPENGL = "_GLSL.cso";	// openGL時のファイル名
}


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Code::C_Shader_Code(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Code::~C_Shader_Code(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：バイトコードのメモリを解放し初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Code::M_Release(void)
{
	// コードの情報用メモリを解放
	mpr_variable.binary_ptr.reset();

	// サイズを初期化
	mpr_variable.size = 0;

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーの初期化
// 引数   ：string シェーダーの設定
// 戻り値 ：bool シェーダーが無かったらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Code::M_Load_Shader_File(std::string in_shader_file_name)
{
	// ☆ 変数宣言 ☆ //
	FILE * file_address = nullptr;	// コンパイル済みシェーダーのファイルを入手

	std::string file_name = in_shader_file_name;	// ファイル名


	// プラットフォーム毎に分岐する
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
	//  DX12  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX12:

		file_name += RENDER_API_FILENAME::C_DX12;

		break;

		//  DX11  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX11:

		file_name += RENDER_API_FILENAME::C_DX11;

		break;

		//  OpenGL  Vulkan  不明時  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_OPENGL:
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_VULKAN:
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_UNKNOWN:

		file_name += RENDER_API_FILENAME::C_OPENGL;

		break;
	}


	// コンパイル済みシェーダーのファイルを開く
	fopen_s(&file_address, file_name.c_str(), "rb");


	// ファイルがなかったらfalseで抜ける
	if (file_address == nullptr)
	{
		// デバッグ時のみエラーを警告
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_SHADER_ERROR, (file_name + "シェーダーの読み取りに失敗しました").c_str());
#endif // _DEBUG

		return false;
	}


	// デバッグ時のみ成功を告知
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, (file_name + "シェーダーの読み取りに成功しました").c_str());
#endif // _DEBUG


	// バイトコードのビット数の入手
	fseek(file_address, 0, SEEK_END);
	mpr_variable.size = ftell(file_address);
	rewind(file_address);


	// バイトコードをロードする
	mpr_variable.binary_ptr.reset(new(void * [mpr_variable.size]));
	fread(mpr_variable.binary_ptr.get(), 1, mpr_variable.size, file_address);


	// ファイルを閉じる
	fclose(file_address);
	file_address = nullptr;

	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンパイル済みコードの参照を返す
// 引数   ：void
// 戻り値 ：const unique_ptr<void * > & コンパイル済みコード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::unique_ptr<void * > & C_Shader_Code::M_Get_Compiled_Cord(void) const
{
	return mpr_variable.binary_ptr;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コードのバイトサイズを返す
// 引数   ：void
// 戻り値 ：int コードのバイトサイズ
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Shader_Code::M_Get_Cord_Size(void) const
{
	return mpr_variable.size;
}



