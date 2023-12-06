//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：深度ステンシルバッファのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Depth_Stencil_Buffer_System.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Depth_Stencil_Buffer_System::C_Depth_Stencil_Buffer_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Depth_Stencil_Buffer_System::~C_Depth_Stencil_Buffer_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Release(void)
{
	if (mpr_variable.depth_stencil_buffer == nullptr)
	{
		return;
	}


	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Notice_Depth_Stencil_Buffer_Deleted(mpr_variable.depth_stencil_buffer.get());
	mpr_variable.depth_stencil_buffer.reset();
	
	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをロードする
// 引数   ：E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT 深度ステンシルバッファのバイトフォーマット
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Depth_Stencil_Buffer_System::M_Load_Depth_Stencil_Buffer(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT in_byte_format)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Depth_Stencil_Buffer_Inform create_depth_stencil_inform;	// 深度ステンシルバッファの生成用情報



	// ☆ 深度ステンシルバッファの生成用情報を設定 ☆ //
	create_depth_stencil_inform.m_byte_format = in_byte_format;

	// 生成して結果を返す
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Depth_Stencil_Buffer(mpr_variable.depth_stencil_buffer, create_depth_stencil_inform);
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをクリアする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Clear_Depth_Stencil_Buffer(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(mpr_variable.depth_stencil_buffer);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファを指定されたテクスチャスロットにセットする
// 引数   ：int テクスチャスロット番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int in_texture_slot)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Texture_Slot(in_texture_slot, mpr_variable.depth_stencil_buffer);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをレンダリング先として設定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Set_Depth_Stencil_Buffer_To_Render_Target(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Depth_Stencil_Buffer_To_Rendering(mpr_variable.depth_stencil_buffer);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをテクスチャに変換する
// 引数   ：C_Texture_Map & 設定先のテクスチャの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Save_Depth_Stencil_Buffer_To_Texture(ASSET::TEXTURE::C_Texture_Map & out_texture)
{
	mpr_variable.depth_stencil_buffer->M_Save_Screen_For_Texture(out_texture);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファをメインの深度ステンシルバッファに戻す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Depth_Stencil_Buffer_System::M_Set_Main_Depth_Stencil_Buffer(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Main_Depth_Stencil_Buffer_To_Rendering();

	return;
}
