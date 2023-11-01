//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォーム検出用システム
// 説明   ：プラットフォームが何かを示す、マクロで分岐させるべきではない場所のために使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Platform_Detection_System.h"
#include "Platform_Detector_Macro.h"


// ☆ ネームスペースの省略 ☆ //
using namespace PLATFORM::DETECTION;


// ☆ 変数宣言 ☆ //
C_Platform_Detection_System C_Platform_Detection_System::m_this_instance;	// コンストラクタ起動用用のインスタンス


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、OSの識別を行う
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Platform_Detection_System::C_Platform_Detection_System(void)
{
	// ウィンドウズでの実行時
#ifdef D_OS_IS_WINDOWS
	m_platform_num = E_PLATFORM_NUMBER::e_WINDOWS;

	// マックでの実行時
#elif D_OS_IS_MAC
	m_platform_num = E_PLATFORM_NUMBER::e_MAC;

	// リナックスでの実行時
#elif D_OS_IS_LINUX
	m_platform_num = E_PLATFORM_NUMBER::e_LINUX;

	// ユニックスでの実行時
#elif D_OS_IS_UNIX
	m_platform_num = E_PLATFORM_NUMBER::e_UNIX;
	
	// プラットフォーム識別不可
#elif D_OS_IS_UNKNOWN
	m_platform_num = E_PLATFORM_NUMBER::e_UNKNOWN;
#endif // D_OS_IS_UNKNOWN

	return;
}


//==☆ パブリック ☆==//

//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：プラットフォーム識別用番号を渡す
// 引数   ：void
// 戻り値 ：const E_PLATFORM_NUMBER & プラットフォーム識別用番号の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const E_PLATFORM_NUMBER & C_Platform_Detection_System::M_Get_Platform_Number(void)
{
	return m_this_instance.m_platform_num;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のレンダリングAPI番号を渡す
// 引数   ：void
// 戻り値 ：const E_RENDERING_API_NUMBER & レンダリングAPI番号
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const E_RENDERING_API_NUMBER & C_Platform_Detection_System::M_Get_Rendering_API_Number(void)
{
	return m_this_instance.m_rendering_api_num;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIを指定する番号を設定する
// 引数   ：E_RENDERING_API_NUMBER 設定するレンダリングAPI番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Platform_Detection_System::M_Set_Rendering_API_Number(E_RENDERING_API_NUMBER in_rendering_api_num)
{
	m_this_instance.m_rendering_api_num = in_rendering_api_num;

	return;
}
