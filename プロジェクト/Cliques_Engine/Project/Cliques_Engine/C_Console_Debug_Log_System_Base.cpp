//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：デバッグログシステムの基底クラス用の定義を行うファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Console_Debug_Log_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DEBUGGER::LOG::CONSOLE::BASE;


// ☆ 静的変数宣言 ☆ //
std::unique_ptr<C_Console_Debug_Log_System_Base> C_Console_Debug_Log_System_Base::m_this;	// 自クラスへのアクセス用の変数

C_Console_Debug_Log_System_Base::Pr_Variable C_Console_Debug_Log_System_Base::mpr_variable;	// プライベート変数へのアクセス用の変数


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Console_Debug_Log_System_Base::C_Console_Debug_Log_System_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Console_Debug_Log_System_Base::~C_Console_Debug_Log_System_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログシステムを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Debug_Log_System_Base::M_Release(void)
{
	// すでにない場合は削除する必要はない
	if (m_this == nullptr)
	{
		return;
	}

	// 解放する
	m_this.release();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールログシステムのインスタンスのアドレスを返す
// 引数   ：void
// 戻り値 ：C_Console_Debug_Log_System_Base * コンソールログシステムの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Console_Debug_Log_System_Base * C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System(void)
{
	return m_this.get();
}
