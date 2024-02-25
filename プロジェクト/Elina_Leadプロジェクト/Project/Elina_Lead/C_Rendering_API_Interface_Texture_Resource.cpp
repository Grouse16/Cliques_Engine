//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのテスクチャリソース用システムのインターフェース
// 説明   ：テスクチャバッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Texture_Resource.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace  RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テスクチャリソース用の情報を生成する
// 引数   ：unique_ptr<C_Rendering_Texture_Setting_Inform_Base> & 設定先のテスクチャリソースの参照, const S_Create_Texture_Setting_Inform & テスクチャリソースを生成するための情報の参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Texture_Resource::M_Create_Texture_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & out_result_texture_resource, const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & in_create_texture_resource_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Texture_Inform(out_result_texture_resource, in_create_texture_resource_inform);
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テスクチャリソースを描画用にセットする
// 引数   ：S_Texture_Buffer_Drawing_Setting & テスクチャリソース用描画設定の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Texture_Resource::M_Set_Texture_Resource_To_Draw(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & in_draw_texture_resource)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Texture(in_draw_texture_resource);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された番号のリソーススロットにテスクチャデータをセットする
// 引数   ：unique_ptr<C_Rendering_Texture_Setting_Inform_Base> & セットするテスクチャリソースの参照, int セット先のリソーススロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Texture_Resource::M_Set_Texture_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_draw_texture_resource, int in_slot_number)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Texture_By_Index(in_draw_texture_resource, in_slot_number);

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テスクチャをロードする
// 引数   ：string ロードするテクスチャまでのパス, C_Texture_Map & ロード先のテクスチャマップの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Texture_Resource::M_Load_Texture(std::string in_load_texture_path, ASSET::TEXTURE::C_Texture_Map & out_result_texture)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Load_Texture(in_load_texture_path, out_result_texture);
}
