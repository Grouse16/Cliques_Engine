//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：定数データのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Constant_Data_System.h"
#include "C_Rendering_API_Interface_Constant_Resource.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Constant_Buffer_Data_System::C_Constant_Buffer_Data_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Constant_Buffer_Data_System::~C_Constant_Buffer_Data_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Release(void)
{
	mpr_variable.constant_data.clear();
	mpr_variable.constant_data.shrink_to_fit();

	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name.shrink_to_fit();
	
	mpr_variable.constant_buffer_inform.reset();

	mpr_variable.attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;

	mpr_variable.list_sum = 0;

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファとデータを生成する
// 引数   ：int バッファ数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Create_Constant_Buffer_And_Data(int in_buffer_sum)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform creat_constant_inform;	// 定数バッファ生成用情報


	// 現在持っているデータを解放する
	M_Release();

	// 生成用のデータを設定して生成を行う
	creat_constant_inform.m_list_size = in_buffer_sum + ((in_buffer_sum <= 0) * 1);	// 定数バッファの配列数、０にならないようにしている
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(mpr_variable.constant_buffer_inform, creat_constant_inform);


	// ☆ 定数データの生成 ☆ //

	// 定数データを確保し。定数バッファ配列数を設定する
	mpr_variable.constant_data.resize(in_buffer_sum);
	mpr_variable.list_sum = creat_constant_inform.m_list_size;
	
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファのみを生成する
// 引数   ：int バッファ数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Create_Only_Constant_Buffer(int in_buffer_sum)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform creat_constant_inform;	// 定数バッファ生成用情報


	// 現在持っているデータを解放する
	M_Release();

	// 生成用のデータを設定して生成を行う
	creat_constant_inform.m_list_size = in_buffer_sum + ((in_buffer_sum <= 0) * 1);	// 定数バッファの配列数、０にならないようにしている
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(mpr_variable.constant_buffer_inform, creat_constant_inform);


	// ☆ 定数データの生成 ☆ //

	// 定数データを確保し。定数バッファ配列数を設定する
	mpr_variable.list_sum = creat_constant_inform.m_list_size;

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データの識別名をセットする
// 引数   ：string セットする文字列
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Set_Data_Signature_Name(std::string in_set_name)
{
	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name = in_set_name;
	mpr_variable.data_signature_name.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータ設定先のシェーダーの種類を変更する
// 引数   ：E_SHADER_KIND 設定先のシェーダーの種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.attach_shader_kind = in_set_shader_kind;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データの識別名を返す
// 引数   ：void
// 戻り値 ：const string & 現在のデータ識別名の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::string & C_Constant_Buffer_Data_System::M_Get_Data_Signature_Name(void)
{
	return mpr_variable.data_signature_name;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファ用のデータを返す　
// 引数   ：void
// 戻り値 ：vector<S_256_Byte_Type> & 定数データ
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<C_Constant_Buffer_Data_System::S_256_Byte_Type> & C_Constant_Buffer_Data_System::M_Get_Constant_Data(void)
{
	return mpr_variable.constant_data;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータ設定先のシェーダーの種類を返す
// 引数   ：void
// 戻り値 ：E_SHADER_KIND 設定先のシェーダーの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::E_SHADER_KIND C_Constant_Buffer_Data_System::M_Get_Attach_Shader_Kind(void)
{
	return mpr_variable.attach_shader_kind;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファのデータのアドレスを取得して返す
// 引数   ：void
// 戻り値 ：unsigned char * 定数バッファのデータのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
unsigned char * RENDERING::CAPSULE::C_Constant_Buffer_Data_System::M_Get_Constant_Buffer_Data(void)
{
	return nullptr;
}



//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファを現在のデータで更新する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Set_Constant_Data_To_Buffer(void)
{
	mpr_variable.constant_buffer_inform->M_Set_Data_To_Buffer(&mpr_variable.constant_data[0], mpr_variable.list_sum, 256);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファをGPUに渡す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Set_Constant_Buffer_To_GPU(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting drawing_setting;	// 描画用に渡す情報


	// 描画情報を設定してGPUに渡す
	drawing_setting.add_constant_buffer = mpr_variable.constant_buffer_inform.get();
	drawing_setting.add_attach_shader_kind = mpr_variable.attach_shader_kind;
	drawing_setting.add_signature_name = &mpr_variable.data_signature_name;
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw(drawing_setting);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ： 定数バッファを指定されたインデックスにセットし、GPUに渡す
// 引数   ：int 設定するインデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Constant_Buffer_Data_System::M_Set_Constant_Buffer_To_GPU_By_Index(int in_slot_num)
{
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw_By_Slot_Index(mpr_variable.constant_buffer_inform, in_slot_num);

	return;
}

