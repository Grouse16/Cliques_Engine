//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの頂点インデックスバッファ用システムのインターフェース
// 説明   ：頂点インデックスバッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Vertex_Index_Buffer.h"
#include "C_Rendering_API_Base.h"


// ☆　ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータ用の情報を生成する
// 引数   ：unique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & 設定先の頂点インデックスバッファの参照, const S_Create_Index_Buffer_Inform & 頂点インデックスバッファ生成用の情報の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Create_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & out_result_vertex_buffer, const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & in_create_vertex_index_buffer_inform)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Index_Inform(out_result_vertex_buffer, in_create_vertex_index_buffer_inform);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスバッファを元に指定された頂点インデックス間の描画を行う
// 引数   ：unique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & 設定先の頂点インデックスバッファの参照, int 描画開始位置の頂点インデックス番号, int 描画終了位置の頂点インデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer_By_Range(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_draw_index_buffer, int in_start_index_slot, int in_end_index_slot)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer_By_Range(in_draw_index_buffer, in_start_index_slot, in_end_index_slot);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスバッファを元に描画を行う
// 引数   ：unique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & 設定先の頂点インデックスバッファの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Index_Buffer::M_Draw_By_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_draw_index_buffer)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer(in_draw_index_buffer);

	return;
}
