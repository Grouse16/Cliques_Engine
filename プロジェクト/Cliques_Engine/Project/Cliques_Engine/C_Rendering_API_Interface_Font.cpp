//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのフォントデータ用システムのインターフェース
// 説明   ：フォントに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_API_Interface_Font.h"
#include "C_Rendering_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::RENDER_INTERFACE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フォントを指定されたフォント名を元にロードする
// 引数   ：unique_ptr<C_Rendering_Font_Inform_Base> & 設定先のフォントシステムの参照, const S_Create_Font_Data_Inform & フォントを生成するための情報の参照（const）
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_API_Interface_Font::M_Load_Font(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> & out_result_font_system, const RENDERING::API::CREATE::S_Create_Font_Data_Inform & in_font_create_inform)
{
    return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Font_Data(out_result_font_system, in_font_create_inform);
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡された情報を元に文字列をマップにセットする
// 引数   ：S_Make_Font_To_Graph_Package & フォントデータをテクスチャマップに移すための情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_API_Interface_Font::M_Set_Font_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & in_make_font_graph_package)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Font_To_Texture_Map(in_make_font_graph_package);

    return;
}
