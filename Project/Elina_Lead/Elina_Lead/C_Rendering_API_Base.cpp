//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サードパーティの内のグラフィックを制御するシステムの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Base.h"


// ☆ ネームスペース ☆ //
using namespace RENDERING::API::BASE;


// ☆ 変数宣言 ☆ //
std::unique_ptr <C_Rendering_API_Base> C_Rendering_API_Base::m_this;	// クラスのインスタンス用アドレス、主にポリモーフィズム化に使用


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング用のAPIを終了する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Base::M_Delete_API(void)
{
	if (m_this != nullptr)
	{
		m_this.reset();
		m_this = nullptr;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_API_Base::~C_Rendering_API_Base(void)
{
	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このクラスの実体のアドレスを返す
// 引数   ：void
// 戻り値 ：C_Rendering_API_Base * レンダリングAPI基底クラスのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_API_Base * C_Rendering_API_Base::M_Get_Instance(void)
{
	return m_this.get();
}
