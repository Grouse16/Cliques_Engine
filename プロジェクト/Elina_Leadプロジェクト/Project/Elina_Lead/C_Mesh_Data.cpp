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
	mpr_variable.vertex_index_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスを指定された数分生成
// 引数   ：int 生成する頂点インデックス数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Create_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_index_system.M_Create_Index_Data_And_Buffer(in_creat_index_sum);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスのデータをインデックスバッファに設定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_index_system.M_Set_Index_Data_To_Buffer();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータのみを削除する（バッファに設定後、編集しないなら必要がない）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_index_system.M_Delete_Index_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のマテリアルをロードする
// 引数   ：string マテリアル名
// 戻り値 ：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Mesh_Data::M_Load_Material_By_Name(std::string in_load_material_name)
{
	return mpr_variable.material.M_Load_Material(in_load_material_name);
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッシュ名を設定する
// 引数   ：string 設定するメッシュ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Set_Mesh_Name(std::string in_set_mesh)
{
	mpr_variable.name = in_set_mesh;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータのリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<unsigned int> & 頂点インデックスデータのリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<unsigned int> & C_Mesh_Data::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_index_system.M_Get_Index_Data();
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


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メッシュ名を返す
// 引数   ：void
// 戻り値 ：string メッシュ名
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Mesh_Data::M_Get_Mesh_Name(void)
{
	return mpr_variable.name;
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
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルの設定をせずに面の描画のみ行う（外部でマテリアルを設定してから描画するとき用）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Mesh_Data::M_Draw_Mesh_Do_Not_Set_Material(void)
{
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


