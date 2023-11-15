


// ☆ ファイルひらき ☆ //
#include "C_DX12_Constant_Setting_Inform.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ クラス ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報を元に定数データを生成する
// 引数   ：C_Constant_Buffer_Setting_Inform_Base & セット先の定数データ, C_Creat_Constant_Buffer_Inform & 定数データ生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Constant_Setting_Inform::C_DX12_Constant_Setting_Inform(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報を元に定数データを生成する
// 引数   ：C_Constant_Buffer_Setting_Inform_Base & セット先の定数データ, C_Creat_Constant_Buffer_Inform & 定数データ生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Constant_Setting_Inform::~C_DX12_Constant_Setting_Inform(void)
{
	m_constant_buffer_data.Reset();

	m_constant_buffer_heap.Reset();

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファに指定された情報をセットする
// 引数   ：void * セットするデータ, int 配列数, int セットするデータサイズ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Constant_Setting_Inform::M_Set_Data_To_Buffer(void * in_set_data, int in_list_size, int in_data_size)
{
    // ☆ 変数宣言 ☆ //
    void * get_map_address = nullptr; // 定数バッファ書き込み先のマップアドレス
    
    
    // マップを入手出来なかったらエラーを出して抜ける
    if (FAILED(m_constant_buffer_data->Map(0, nullptr, &get_map_address)))
    {
        return;
    }


    // ☆ 変数宣言 ☆ //
    unsigned char * buffer_data = static_cast<unsigned char *>(get_map_address);    // 書き込み先バッファ（１バイトオフセット）


    // マップに定数情報を書き込む
    for (int loop_x = 0; loop_x < in_list_size; loop_x++)
    {
        memcpy((buffer_data + 256 * loop_x), (static_cast<unsigned char * >(in_set_data) + in_list_size * in_data_size), in_data_size);
    }


    // マップを解放
    m_constant_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

    return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファのデータのアドレスを返す　＊使用が終わったら必ずCloseすること
// 引数   ：void
// 戻り値 ：定数バッファのデータのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
unsigned char * C_DX12_Constant_Setting_Inform::M_Get_Constant_Buffer_Data_Address(void)
{
    // ☆ 変数宣言 ☆ //
    void * get_map_address = nullptr; // 定数バッファ書き込み先のマップアドレス

    // 定数バッファのデータを取得して返す
    m_constant_buffer_data->Map(0, nullptr, &get_map_address);
    return (unsigned char*)get_map_address;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数バッファのデータを使用終了する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Constant_Setting_Inform::M_Close_Constant_Buffer_Data_Address(void)
{
    // 定数バッファのデータの使用を終了する
    m_constant_buffer_data->Unmap(0, nullptr);

    return;
}



