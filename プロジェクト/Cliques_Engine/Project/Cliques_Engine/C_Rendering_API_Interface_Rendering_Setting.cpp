//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのレンダリング設定のインターフェース
// 説明   ：レンダリング設定に対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Rendering_Setting.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング設定の生成
// 引数   ：unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & 設定先のレンダリング設定の参照, const S_Create_Rendering_Graphics_Setting_Inform & 生成用の情報の参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Rendering_Setting::M_Create_Rendering_Setting(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & out_result_rendering_setting, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Rendering_Graphics_Inform(out_result_rendering_setting, in_create_inform);
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング設定を描画用にセットする
// 引数   ：unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & セットするレンダリング設定の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Rendering_Setting::M_Set_Rendering_Setting_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_set_rendering_setting)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(in_set_rendering_setting);
}

