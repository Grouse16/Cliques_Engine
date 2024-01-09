//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点インデックスシステムのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Vertex_Index_System.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Vertex_Index_System::C_Vertex_Index_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コピーコンストラクタ
// 引数   ：const C_Vertex_Index_System & コピーするデータの参照(const)
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Vertex_Index_System::C_Vertex_Index_System(const C_Vertex_Index_System & in_copy_data)
{
	// 頂点インデックスバッファをコピーする
	mpr_variable.m_index_buffer.reset(in_copy_data.mpr_variable.m_index_buffer.get());

	// 頂点インデックスデータをコピーする
	mpr_variable.m_index_data = in_copy_data.mpr_variable.m_index_data;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Vertex_Index_System::~C_Vertex_Index_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Release(void)
{
	mpr_variable.m_index_buffer.reset();

	mpr_variable.m_index_data.clear();
	mpr_variable.m_index_data.shrink_to_fit();

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスバッファを生成する
// 引数   ：int 生成するインデックス数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Create_Index_Buffer(int in_index_sum)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// 頂点インデックスバッファ生成用の情報


	// 頂点インデックス数を設定する
	creat_index_inform.index_sum = in_index_sum;

	// 頂点インデックスバッファを生成する
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Index_Inform(mpr_variable.m_index_buffer, creat_index_inform);

	
	// 頂点インデックスデータを生成する
	mpr_variable.m_index_data.resize(in_index_sum);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスバッファを現在のインデックスデータに合わせて生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Create_Index_Buffer_By_Now_Index_Data(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// 頂点インデックスバッファ生成用の情報


	// 頂点インデックス数を設定する
	creat_index_inform.index_sum = (int)mpr_variable.m_index_data.size();

	// 頂点インデックスバッファを生成する
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Index_Inform(mpr_variable.m_index_buffer, creat_index_inform);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータの参照を返す
// 引数   ：void
// 戻り値 ：vector<unsigned int> & 頂点インデックスデータの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<unsigned int> & C_Vertex_Index_System::M_Get_Index_Data(void)
{
	return mpr_variable.m_index_data;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータを使用して描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Set_Index_Data_To_Buffer(void)
{
	mpr_variable.m_index_buffer->M_Set_Index_Setting(mpr_variable.m_index_data);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータを使用して描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Draw_Execute_By_Index_Data(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer(mpr_variable.m_index_buffer);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータを使用して描画するインデックスデータの範囲を指定して描画する
// 引数   ：int 描画開始インデックス, int 描画終了インデックス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Vertex_Index_System::M_Draw_Index_Data_By_Index_Data_Range(int in_draw_start_index, int in_draw_end_index)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer_By_Range(mpr_variable.m_index_buffer, in_draw_start_index, in_draw_end_index);

	return;
}

