//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの頂点バッファ用システムのインターフェース
// 説明   ：頂点バッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Vertex_Buffer.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データ用の情報を生成する
// 引数   ：unique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & 設定先の頂点バッファの参照,　const S_Create_Vertex_Buffer_Inform & 生成するための情報の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Buffer::M_Create_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & out_result_vertex_buffer, const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & in_create_vertex_buffer_inform)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(out_result_vertex_buffer, in_create_vertex_buffer_inform);

    return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データを描画用にセットする
// 引数   ：unique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & セットする頂点バッファ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Buffer::M_Set_Vertex_Buffer_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & in_set_vertex_buffer)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Vertex_Buffer(in_set_vertex_buffer);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点バッファを元に描画を実行する
// 引数   ：unique_ptr<C_Rendering_Vertex_Buffer_Setting_Inform_Base> & 描画する頂点バッファ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Vertex_Buffer::M_Draw_By_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & in_draw_vertex_buffer)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Draw_Command_By_Vertex_Buffer(in_draw_vertex_buffer);

    return;
}
