//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのレンダリング画面用システムのインターフェース
// 説明   ：レンダリング画面に対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Rendering_Screen.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面システムの解放
// 引数   ：unique_ptr<C_Rendering_Screen_Data_Base> & 設定先のレンダリング画面の参照, const S_Create_Render_Screen_Inform & レンダリング画面を生成するための情報の参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Rendering_Screen::M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & out_result_rendering_screen_system, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & in_create_rendering_screen_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Rendering_Screen(out_result_rendering_screen_system, in_create_rendering_screen_inform);
}


//-☆- 解放 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面の削除を通知する
// 引数   ：const C_Rendering_Screen_Data_Base * 削除されたレンダリング画面のアドレス（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * in_delete_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Notice_Rendering_Screen_Deleted(in_delete_rendering_screen);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面をクリアする
// 引数   ：unique_ptr<C_Rendering_Screen_Data_Base> & クリアするレンダリング画面番号, S_Create_Render_Screen_Inform & クリアするレンダリング画面システムの参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Clear_Rendering_Screen(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Clear_Rendering_Screen(in_rendering_screen_number, in_rendering_screen);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたレンダリング画面を描画先にセット
// 引数   ：unique_ptr<C_Rendering_Screen_Data_Base> & 設定先のレンダリング画面の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_To_Draw_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_set_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Render_Target(in_set_rendering_screen);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メインのレンダリング画面を描画先にする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Rendering_Screen_To_Draw(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Rendering_Screen_To_Rendering();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたレンダリング画面をテクスチャリソーススロットにセット
// 引数   ：int 設定先のスロット番号, int 設定する画面の番号, unique_ptr<C_Rendering_Screen_Data_Base> & 設定先のレンダリング画面の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_To_Texture_Resource_Slot(int in_set_slot_number, int in_set_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_set_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_To_Texture_Slot(in_set_slot_number, in_set_screen_number, in_set_rendering_screen);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メインの表示中のレンダリング画面を指定されたテクスチャスロットにセットする
// 引数   ：int 設定先のテクスチャのスロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(in_texture_slot);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メインの描画書き込み中のレンダリング画面を指定されたテクスチャスロットにセットする
// 引数   ：int 設定先のテクスチャのスロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(in_texture_slot);

	return;
}


//-☆- テクスチャ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたレンダリング画面のデータをテクスチャに移す
// 引数   ：int 設定するレンダリング画面番号, unique_ptr<C_Rendering_Screen_Data_Base> & レンダリング画面システムの参照, C_Texture_Map & 設定先のテクスチャの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Save_Rendering_Screen_To_Texture(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen_data, ASSET::TEXTURE::C_Texture_Map & out_result_texture_map)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Save_Rendering_Screen_To_Texture(in_rendering_screen_number, in_rendering_screen_data, out_result_texture_map);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メインのレンダリング画面のデータをテクスチャに移す
// 引数   ：C_Texture_Map & 設定先のテクスチャの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Save_Main_Rendering_Screen_To_Texture(in_texture_map);
}


//-☆- リソース設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面のデータを読み取り可能にする
// 引数   ：int 設定するレンダリング画面番号, unique_ptr<C_Rendering_Screen_Data_Base> & レンダリング画面システムの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Screen::M_Set_Rendering_Screen_Can_Readable(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Rendering_Screen_Can_Readable(in_rendering_screen_number, in_rendering_screen);

	return;
}
