//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：メッシュのデータ管理用のシステムのクラス
// 説明   ：頂点や頂点インデックス情報の管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Mesh_Data.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MESH;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Mesh_Data::C_Mesh_Data(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Mesh_Data::~C_Mesh_Data(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Release(void)
{
	mpr_variable.vertex_setting.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点を指定された数分生成
// 引数   ：int 生成する頂点数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Create_Vertex_List(int in_creat_vertex_sum)
{
	mpr_variable.vertex_setting.M_Create_Vertex_Data_By_Number(in_creat_vertex_sum);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスを指定された数分生成
// 引数   ：int 生成する頂点インデックス数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Create_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_setting.M_Create_Index_Data_By_Number(in_creat_index_sum);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点バッファと頂点インデックスバッファを生成し　＊頂点データと頂点インデックスを必要な数だけ生成してから実行すること
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Create_Vertex_Buffer_And_Index_Buffer(void)
{
	mpr_variable.vertex_setting.M_Create_Vertex_Buffer_By_Now_Parameter();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスのデータをインデックスバッファに設定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Index_Data_To_Buffer();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データを頂点バッファに設定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Attach_Vertex_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Set_Vertex_Data_To_Buffer();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データのみを削除する（頂点バッファに設定後、編集しないなら持っておく必要がない）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Delete_Vertex_Data(void)
{
	mpr_variable.vertex_setting.M_Delete_Vertex_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータのみを削除する（バッファに設定後、編集しないなら必要がない）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_setting.M_Delete_Index_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のマテリアルをロードする
// 引数   ：マテリアル名
// 戻り値 ：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Mesh_Data::M_Load_Material_By_Name(std::string in_load_material_name)
{
	return mpr_variable.material.M_Load_Material(in_load_material_name);
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データのリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<S_3D_Model_Vertex> & 頂点データのリストを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<DATA::VERTEX::S_3D_Model_Vertex> & C_Mesh_Data::M_Get_Vertex_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Vertex_Data();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータのリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<unsigned __int32> & 頂点インデックスデータのリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<unsigned __int32> & C_Mesh_Data::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Index_Data();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のマテリアルユーザーの参照を返す
// 引数   ：void
// 戻り値 ：C_Material_User & マテリアルユーザーの参照を返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MATERIAL::C_Material_User & C_Mesh_Data::M_Get_Material_User(void)
{
	return mpr_variable.material;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッシュの描画を実行する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Draw_Mesh(void)
{
	// マテリアルをセットする（レンダリング設定を登録し、定数バッファ、テクスチャをGPUのデータスロットにセット）
	mpr_variable.material.M_Material_Attach_To_Draw();

	// 頂点を描画する（頂点インデックスバッファのリスト全てを描画する）
	mpr_variable.vertex_setting.M_Set_Vertex_Buffer_To_Redering();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルの設定をせずに面の描画のみ行う（外部でマテリアルを設定してから描画するとき用）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::m_Draw_Mesh_Do_Not_Set_Material(void)
{
	mpr_variable.vertex_setting.M_Set_Vertex_Buffer_To_Redering();

	return;
}


