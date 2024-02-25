//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIに対する基本動作を行うためのインターフェース
// 説明   ：基本動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_User.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆　//

//==☆ パブリック ☆==//

//-☆- レンダリング -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングの開始の実行
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_User::M_Rendering_Start(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Start();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングの終了と描画バッファ切り替えの実行
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_User::M_Rendering_End_And_Swap_Screen(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_End_And_Swap_Screen();

	return;
}


//-☆- 判定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIが正常であるかどうかをチェックする
// 引数   ：void
// 戻り値 ：bool 正常時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_User::M_Rendering_API_Safe_Check(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::BASE::C_Rendering_API_Base* rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // レンダリングAPIへのアドレス


	// レンダリングAPIのアドレスが削除されているなら異常を返す
	if (rendering_api_address == nullptr)
	{
		return false;
	}

	// レンダリングAPIシステムが終了しているなら異常を返す
	if (rendering_api_address->M_Get_End_Rendering_System())
	{
		return false;
	}

	// 異常が見つからないので正常である
	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このレンダリングシステムのシェーダーのフォルダまでのパスを返す
// 引数   ：void
// 戻り値 ：string シェーダーまでのパス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Rendering_API_Interface_User::M_Get_Shader_Folder_Path(void)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Get_Shader_Folder_Path();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のレンダリングシステムのシェーダーの拡張子を返す
// 引数   ：void
// 戻り値 ：string シェーダーの拡張子
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Rendering_API_Interface_User::M_Get_Shader_Extension(void)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Get_Shader_Extension();
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面をクリアする色を設定する
// 引数   ：C_Color セットする色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_User::M_Set_Screen_Clear_Color(DATA::COLOR::C_Color in_set_color)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Clear_Color(in_set_color);

	return;
}
