//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの定数リソース用システムのインターフェース
// 説明   ：定数バッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Constant_Resource.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ クラス ☆ //

//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数リソース用の情報を生成する
// 引数   ：unique_ptr<C_Rendering_Constant_Buffer_Setting_Inform_Base> & 設定先の定数リソースの参照, const S_Create_Constant_Buffer_Inform & 定数リソースを生成するための情報の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & out_result_constant_buffer, const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & in_create_constant_resource_inform)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Constant_Inform(out_result_constant_buffer, in_create_constant_resource_inform);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数リソースを描画用にセットする
// 引数   ：S_Constant_Buffer_Drawing_Setting & 定数リソース用描画設定の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & in_draw_constant_buffer)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Constant_Buffer(in_draw_constant_buffer);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された番号のリソーススロットに定数データをセットする
// 引数   ：unique_ptr<C_Rendering_Constant_Buffer_Setting_Inform_Base> & セットする定数リソースの参照, int セット先のリソーススロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & in_draw_constant_resource, int in_set_slot_number)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Constant_Buffer_By_Index(in_draw_constant_resource, in_set_slot_number);

	return;
}
