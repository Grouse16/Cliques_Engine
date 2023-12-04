//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング画像を円滑に設定し、使用するためのシステム
// 説明   ：レンダリングAPIとの連携や、複雑な抽象化レイヤーのシステムのカプセル化を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Screen_System.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Screen_System::C_Rendering_Screen_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Screen_System::~C_Rendering_Screen_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面を削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Release(void)
{
	mpr_variable.rendering_screen.reset();

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面を生成する
// 引数   ：int 画面数, E_RENDERING_SCREEN_FORMAT 画面のバイト数, E_SCREEN_TEXTURE_SETTING 画面のテクスチャ設定
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_Screen_System::M_Create_Rendering_Screen(int in_screen_sum, RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT in_screen_format, RENDERING::GRAPHICS::CREATE::E_SCREEN_TEXTURE_SETTING in_texture_setting)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Render_Screen_Inform create_screen_inform;	// レンダリング画面生成情報
	

	// 画面数
	create_screen_inform.m_screen_buffer_sum = in_screen_sum;

	// 画面のバイト数
	create_screen_inform.m_rendering_screen_format = in_screen_format;

	// 画面のテクスチャ設定
	create_screen_inform.m_screen_texture_setting = in_texture_setting;

	// 生成して結果を返す
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Rendering_Screen(mpr_variable.rendering_screen, create_screen_inform);
}


//-☆- テクスチャ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面をテクスチャ画像として保存する
// 引数   ：int レンダリング画面番号, C_Texture_Map & 保存先のテクスチャ画面の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_rendering_screen_num, ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Save_Rendering_Screen_To_Texture(in_rendering_screen_num, mpr_variable.rendering_screen, in_texture_map);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画像を描画先として設定する
// 引数   ：int 設定するレンダリング画像番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Set_Render_Target(int in_screen_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Render_Target(in_screen_number, mpr_variable.rendering_screen);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面をクリアする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Clear_Screen(void)
{
	// ☆ 変数宣言 ☆ //
	int rendering_screen_sum = mpr_variable.rendering_screen->M_Get_Rendering_Screen_Sum();	// レンダリング画像数


	for (int l_screen_number = 0; l_screen_number < rendering_screen_sum; l_screen_number++)
	{
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(l_screen_number, mpr_variable.rendering_screen);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面をクリアする
// 引数   ：int クリアする画面番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Clear_Screen_By_Number(int in_screen_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(in_screen_number, mpr_variable.rendering_screen);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたテクスチャのスロット番号にレンダリング画面の画像をセットする
// 引数   ：int セットする画面番号, int セットするスロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Screen_System::M_Set_Rendering_Screen_To_Texture_Slot(int in_screen_number, int in_slot_number)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Texture_Slot(in_screen_number, in_slot_number, mpr_variable.rendering_screen);

	return;
}

