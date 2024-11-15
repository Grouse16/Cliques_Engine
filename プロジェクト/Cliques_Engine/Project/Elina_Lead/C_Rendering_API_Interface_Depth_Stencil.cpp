//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの深度ステンシル用システムのインターフェース
// 説明   ：深度ステンシルに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Depth_Stencil.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファを生成する
// 引数   ：unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & 設定先の深度ステンシルバッファの参照, const S_Create_Depth_Stencil_Buffer_Inform & 深度ステンシルバッファを生成するための情報の参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Depth_Stencil::M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & out_result_stencil_buffer, const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & in_create_stencil_buffer)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Depth_Stencil_Buffer(out_result_stencil_buffer, in_create_stencil_buffer);
}


//-☆- 解放 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファの削除を通知する
// 引数   ：const C_Rendering_Depth_Stencil_Buffer_Base * 削除された深度ステンシルバッファのアドレス（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Depth_Stencil::M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * in_delete_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Notice_Depth_Stencil_Buffer_Deleted(in_delete_depth_stencil_view);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをリセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Depth_Stencil::M_Reset_Draw_Depth_Stencil_Buffer(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Reset_Depth_Stencil_Buffer();

	return;
}


//-☆- クリア -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをクリアする
// 引数   ：unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & クリアする深度ステンシルバッファの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Depth_Stencil::M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_clear_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Clear_Depth_Stencil_Buffer(in_clear_depth_stencil_view);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファを描画用にセットする
// 引数   ：unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & 設定する深度ステンシルバッファの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Depth_Stencil::M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_set_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(in_set_depth_stencil_view);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをGPU用リソースのテクスチャスロットにセット
// 引数   ：int 設定先のスロット番号, unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & 設定する深度ステンシルバッファの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Depth_Stencil::M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int in_slot, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_set_depth_stencil_view)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Texture_Slot(in_slot, in_set_depth_stencil_view);

	return;
}

