//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：画像を表示するUIのクラス（UIのコンポーネント）
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_UIC_Graph_Box.h"
#include "E_BOX_VERTEX_SETTING.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::UI_COMPONENT;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_UIC_Text_Box::C_UIC_Text_Box(void)
{
	// ☆ 変数宣言　☆ //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// 頂点データのリスト

	std::vector<unsigned int> & index_list = mpr_variable.vertex_system.M_Get_Index_Data();	// インデックスデータのリスト


	// マテリアルのロード
	mpr_variable.material.M_Load_Material("UI_Material");

	// 頂点データの生成
	mpr_variable.vertex_system.M_Create_Vertex_And_Index_Data_And_Buffer((int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_SUM, (int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_SUM);


	// インデックスデータをセットする
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_1;
	index_list[1] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_2;
	index_list[2] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_3;
	index_list[3] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_4;
	index_list[4] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_5;
	index_list[5] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_6;


	// UV座標をそれぞれ設定
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].uv.M_Set_UV(0.0f, 0.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].uv.M_Set_UV(0.0f, 1.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].uv.M_Set_UV(1.0f, 0.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].uv.M_Set_UV(1.0f, 1.0f);


	// 頂点バッファにセット
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_UIC_Text_Box::~C_UIC_Text_Box(void)
{
	mpr_variable.vertex_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のテクスチャをロードする
// 引数   ：string ロードするテクスチャ名
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UIC_Text_Box::M_Load_Texture(std::string in_load_texture_name)
{
	mpr_variable.material.M_Get_Material_Address()->M_Load_Texture_To_Slot_By_Index(0, in_load_texture_name);

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UIC_Text_Box::M_Update(void)
{
	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UIC_Text_Box::M_Draw(void)
{
	// マテリアルを描画に適用
	mpr_variable.material.M_Material_Attach_To_Draw();

	// 頂点を描画する
	mpr_variable.vertex_system.M_Draw_All_Vertex();

	return;
}


//-☆- 座標 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UIの座標をセットする
// 引数   ：S_Rect セット位置の四角形（左下が０，右上が１）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UIC_Text_Box::M_Set_UI_Position(DATA::RECTSETTING::S_Rect in_set_rect)
{
	// ☆ 変数宣言 ☆ //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// 頂点データのリスト


	// 左上頂点の座標をセット
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.x = in_set_rect.left_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.y = in_set_rect.top_y / 2.0f;

	// 右上頂点の座標をセット
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.x = in_set_rect.right_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.y = in_set_rect.top_y / 2.0f;

	// 左下頂点の座標をセット
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.x = in_set_rect.left_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.y = in_set_rect.bottom_y / 2.0f;

	// 右下頂点の座標をセット
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.x = in_set_rect.right_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.y = in_set_rect.bottom_y / 2.0f;

	// 頂点バッファにセット
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}


//-☆- カラー -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色を設定する
// 引数   ：C_Color 色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UIC_Text_Box::M_Set_Color(DATA::COLOR::C_Color in_set_color)
{
	// ☆ 変数宣言 ☆ //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// 頂点データのリスト


	// 頂点の色を設定して頂点バッファにセット
	for (DATA::VERTEX::S_UI_Vertex & now_vertex : vertex_list)
	{
		now_vertex.color = in_set_color;
	}
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}
