//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の機能を使うためのクラス
// 説明   ：DX12設定や描画処理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <string>


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS

#include "C_Windows_System.h"

#include "C_DX12_System.h"
#include "C_DX12_Input_Layout_Setting_System.h"
#include "C_DX12_Streaming_Output_Buffer_Base.h"
#include "C_DX12_Blend_State_Setting_System.h"
#include "C_DX12_Rasterrizer_State_Setting_System.h"
#include "C_DX12_Sampling_Setting_System.h"
#include "C_DX12_Stencil_State_Setting_System.h"
#include "C_DX12_Cached_PSO_Base.h"
#include "C_DX12_Font_Data_Set.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ライブラリひらき ☆ //
#pragma comment (lib, "d3d12.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "D3DCompiler.lib")


// ☆　外部 ☆ //
#ifndef TEXTURE_CHALLEGE
#include <DirectXTex.h>
#pragma comment (lib, "DirectXTex.lib")
#endif


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆-  初期化  -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_System::C_DX12_System(void)
{
    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバイスや描画コマンド、レンダリング先の設定の初期化
// 引数   ：void
// 戻り値 ：bool 立ち上げに成功していたらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_DirectX12_Init(void)
{
    // ☆ デバッグ時のみセットアップ開始を通知 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-DX12のセットアップ開始-☆-☆-☆-☆-☆-☆-☆-");
#endif // _DEBUG


    // DX12用変数群の初期化
    mpr_variable.reset(new C_DX12_System::SPr_Variable());


    // ☆ ファクトリの生成 ☆ //  （全画面表示遷移用システム）  // 失敗で初期化を中断
    if (M_Create_Factory() == false)
    {
        return false;
    }


    // ☆ デバイスの生成 ☆ //  （仮想アダプター）  // 失敗で初期化を中断
    if (M_Create_Device() == false)
    {
        return false;
    }


    // ☆ コマンドアロケーターの生成 ☆ //  （GPUコマンドのストレージ割り当てシステム）  // 失敗で初期化を中断
    if (M_Create_Command_Allocator() == false)
    {
        return false;
    }


    // ☆ コマンドリストの生成 ☆ //  （描画命令のリストのカプセル）  // 失敗で初期化を中断
    if (M_Create_Command_List() == false)
    {
        return false;
    }


    // ☆ コマンドキューの生成 ☆ //  （描画実行システム）  // 失敗で初期化を中断
    if (M_Create_Command_Queue() == false)
    {
        return false;
    }


    // ☆ フェンスの生成 ☆ //  （描画同期用システム）  // 失敗で初期化を中断
    if (M_Create_Fence() == false)
    {
        return false;
    }


    // ☆ スワップチェインの生成 ☆ //  （画面バッファ切り替え用システム）  // 失敗で初期化を中断
    if (M_Create_Swap_Chain() == false)
    {
        return false;
    }


    // ☆ レンダーターゲットビューの生成 ☆ //  （レンダリング先の画面バッファ切り替え用システム）  // 失敗で初期化を中断
    if (M_Create_Render_Target_View_Descriptor_Heap() == false)
    {
        return false;
    }


    // ☆ 深度ステンシルビューの生成 ☆ //  （深度ステンシル適用先の画面バッファの切り替え用システム）  // 失敗で初期化を中断
    if (M_Create_Depth_Stencil_View_Descriptor_Heap() == false)
    {
        return false;
    }


    // 画面を塗りつぶす色を設定
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = 0.0f; // 赤
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = 0.8f; // 緑
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = 0.8f; // 青
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = 1.0f; // α

	// 成功した
	return true;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ファクトリを生成する(全画面表示遷移用システム)
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Factory(void)
{
    // ☆ 変数宣言 ☆  //
    UINT flg_DXGI = 0;  // 機能設定用情報


    // ☆ デバッグ用設定
#if _DEBUG

    // ☆ 変数宣言 ☆ //
    ID3D12Debug* handle_debug_setting = nullptr;   // デバッグ用設定のアドレス


    // デバッグ用情報取得
    D3D12GetDebugInterface(IID_PPV_ARGS(&handle_debug_setting));


    // デバッグレイヤーを有効化
    if (handle_debug_setting != nullptr)
    {
        handle_debug_setting->EnableDebugLayer();
        handle_debug_setting->Release();
    }

    // デバッグ状態を指定
    flg_DXGI |= DXGI_CREATE_FACTORY_DEBUG;

#endif

    // 構成設定用情報の生成
    if (FAILED(CreateDXGIFactory2(flg_DXGI, IID_PPV_ARGS(mpr_variable->s_frame_work.factory.ReleaseAndGetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "ファクトリの生成に失敗");
#endif // _DEBUG

        return false;   // 失敗したらエラーで抜ける
    }

    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "ファクトリの生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバイスを生成する(全画面表示遷移用システム)
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Device(void)
{
    // ☆ 定数宣言 ☆ //
    constexpr int con_DX12_FEATURE_LEVEL_SUM = 5;    // 現在のdx12の機能レベル数


    // ☆ 変数宣言 ☆ //
    Microsoft::WRL::ComPtr<IDXGIAdapter> adapter;   // アダプター（出力先）情報

    std::vector<D3D_FEATURE_LEVEL> can_attach_device_level_list_in_dx12;      // dx12で使用可能な機能レベルリスト


    // ☆ アダプターを取得 ☆ //   // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.factory->EnumAdapters(0, adapter.GetAddressOf())))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "アダプターの取得に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "アダプターの取得に成功");
#endif // _DEBUG


    // ☆ 変数宣言 ☆ //
    HRESULT device_creation_result = E_FAIL; // 機能レベル取得時の処理の結果

    int l_feature_num = 0;  // 生成を試す機能番号


    // ☆ デバイス生成 ☆ //

    // DX12で使用可能な機能レベルを指定する（レベルの高さで降順に並べる）
    can_attach_device_level_list_in_dx12.reserve(con_DX12_FEATURE_LEVEL_SUM);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_2);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_1);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_0);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0);


    // 生成可能なレベルを見つけるまで繰り返す
    for (l_feature_num = 0; l_feature_num < con_DX12_FEATURE_LEVEL_SUM && FAILED(device_creation_result); l_feature_num++)
    {
        device_creation_result = D3D12CreateDevice(adapter.Get(), can_attach_device_level_list_in_dx12[l_feature_num], IID_PPV_ARGS(&mpr_variable->s_frame_work.device));
    }


    // どの機能も作れなかったらエラーで抜ける（windows7や8の場合はこの挙動となる可能性が高い）
    if (FAILED(device_creation_result))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "デバイスの生成に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    l_feature_num -= 1;
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log
    (
        DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
        DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED,
        "デバイスの生成に成功ー種別：" + M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(can_attach_device_level_list_in_dx12[l_feature_num]));
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コマンドアロケーターを生成する（GPUコマンドのストレージ割り当てシステム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Command_Allocator(void)
{
    // ☆ コマンドアロケータを生成 ☆ //  // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(mpr_variable->s_command.allocator.GetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "コマンドアロケータの生成に失敗");
#endif // _DEBUG

        return false;   // 失敗したらエラーで抜ける
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "コマンドアロケータの生成に成功");
#endif // _DEBUG


    // コマンドアロケータのメモリを初期化
    mpr_variable->s_command.allocator->Reset();

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コマンドリストを生成する（描画命令のリストのカプセル）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Command_List(void)
{
    // ☆ コマンドリストの生成 ☆ //    // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, mpr_variable->s_command.allocator.Get(), nullptr, IID_PPV_ARGS(mpr_variable->s_command.list.GetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "コマンドリストの生成に失敗");
#endif // _DEBUG

        return false;   // 失敗したらエラーで抜ける
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "コマンドリストの生成に成功");
#endif // _DEBUG

    // コマンドリストを初期状態にリセット
    mpr_variable->s_command.list->Close();

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コマンドキューを生成する（描画実行システム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Command_Queue(void)
{
    // ☆ 変数宣言 ☆ //
    D3D12_COMMAND_QUEUE_DESC desc_command_queue;    // コマンドキュー生成用情報


    // 初期化
    ZeroMemory(&desc_command_queue, sizeof(desc_command_queue));

    // コマンド書き込み方法を指定
    desc_command_queue.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    // 優先度設定
    desc_command_queue.Priority = 0;

    // GPUタイムアウト設定
    desc_command_queue.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

    // コマンドキューに適応するノード(GPUや物理アダプター)の数
    desc_command_queue.NodeMask = 0;


    // ☆ コマンドキューを生成 ☆ //         // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandQueue(&desc_command_queue, IID_PPV_ARGS(mpr_variable->s_command.queue.GetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "コマンドキューの生成に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "コマンドキューの生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フェンスを生成する（描画同期用システム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Fence(void)
{
    // コマンドキュー用のフェンスを準備
    mpr_variable->s_render.fence_event = CreateEvent(NULL, FALSE, FALSE, NULL);


    // ☆ フェンスを生成 ☆ //   // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(mpr_variable->s_render.queue_fence.GetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "フェンスの生成に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "フェンスの生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：スワップチェインを生成する（画面バッファ切り替え用システム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Swap_Chain(void)
{
    // ☆ 変数宣言 ☆  //
    DXGI_SWAP_CHAIN_DESC desc_swap_chain;   // スワップチェイン設定用情報


    // 初期化
    ZeroMemory(&desc_swap_chain, sizeof(desc_swap_chain));

    // バックバッファのフォーマット
    desc_swap_chain.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    // サンプリング用バッファ数
    desc_swap_chain.SampleDesc.Count = 1;

    // 画面のCPUアクセス方法設定
    desc_swap_chain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

    // 画面数
    desc_swap_chain.BufferCount = (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM;

    // ウィンドウへのハンドル
    desc_swap_chain.OutputWindow = OS::WINDOWS::C_Windows_System::M_Get_Window_Handle();

    // ウィンドウモードであるかどうか
    desc_swap_chain.Windowed = TRUE;

    // 表示切替後オプション
    desc_swap_chain.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

    // スワップチェイン動作オプション
    desc_swap_chain.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;


    // ☆ スワップチェインを生成 ☆ //      // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.factory->CreateSwapChain(mpr_variable->s_command.queue.Get(), &desc_swap_chain, (IDXGISwapChain**)mpr_variable->s_frame_work.swap_chain.GetAddressOf())))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "スワップチェインの生成に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "スワップチェインの生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダーターゲットビューを生成する（レンダリング先の画面バッファ切り替え用システム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Render_Target_View_Descriptor_Heap(void)
{
    // ☆ 変数宣言 ☆ //
    D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // デスクリプタヒープ設定用情報


    // 初期化
    ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

    // ヒープ内のデスクリプタの種類
    desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

    // デスクリプタの数
    desc_descriptor_heap.NumDescriptors = (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM;

    // ヒープオプション
    desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    // デスクリプタに適応するノード(GPUや物理アダプター)の数
    desc_descriptor_heap.NodeMask = 0;


    // ☆ レンダーターゲットヒープの生成 ☆ //     // 失敗ならエラー
    if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(mpr_variable->s_render.rtv.heap.GetAddressOf()))))
    {
        // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "レンダーターゲットヒープ生成に失敗");
#endif // _DEBUG

        return false;   // 失敗したらエラーで抜ける
    }


    // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "レンダーターゲットヒープの生成に成功");
#endif // _DEBUG


    // ☆ 変数宣言 ☆ //
    UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // ハンドル一つ分に対するバイト数(アドレス制御用)


    // 全てのバッファにレンダーターゲットを設定
    for (UINT loop_x = 0; loop_x < (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM; loop_x++)
    {
        // 画面のバッファにレンダーターゲットを指定
        if (FAILED(mpr_variable->s_frame_work.swap_chain->GetBuffer(loop_x, IID_PPV_ARGS(mpr_variable->s_render.rtv.render_buffer[loop_x].GetAddressOf()))))
        {
            // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, ((std::string)"Buffer_Count:" + std::to_string(loop_x) + "-" + "レンダーターゲットの取得に失敗").c_str());
#endif // _DEBUG

            return false;   // 失敗したらエラーで抜ける
        }


        // ☆ デバッグ時なら成功を表示 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, ((std::string)"レンダーターゲットの取得に成功" + "-buffer_count:" + std::to_string(loop_x)).c_str());
#endif // _DEBUG


        // 一番目のデスクリプタのアドレスを指定
        mpr_variable->s_render.rtv.handle[loop_x] = mpr_variable->s_render.rtv.heap->GetCPUDescriptorHandleForHeapStart();

        // 今のデスクリプタまでずらす
        mpr_variable->s_render.rtv.handle[loop_x].ptr += (SIZE_T)loop_x * (SIZE_T)byte_of_handle;

        // レンダーターゲットビュー生成
        mpr_variable->s_frame_work.device->CreateRenderTargetView(mpr_variable->s_render.rtv.render_buffer[loop_x].Get(), nullptr, mpr_variable->s_render.rtv.handle[loop_x]);
    }

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルビューを生成する（深度ステンシル適用先の画面バッファの切り替え用システム）
// 引数   ：void
// 戻り値 ：bool 生成が成功したかどうかを返す 成功でtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Depth_Stencil_View_Descriptor_Heap(void)
{
    // ☆ 深度ステンシルヒープ ☆ //    //（管理用木構造）
    {
        // ☆ 変数宣言 ☆ //
        D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // デスクリプタヒープ設定用情報


        // 初期化
        ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

        // ヒープ内のデスクリプタの種類
        desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;

        // デスクリプタの数
        desc_descriptor_heap.NumDescriptors = 1;

        // ヒープオプション
        desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        // デスクリプタに適応するノード(GPUや物理アダプター)の数
        desc_descriptor_heap.NodeMask = 0;


        // ☆ 深度ステンシルヒープの生成 ☆ //     // 失敗ならエラー
        if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(mpr_variable->s_render.dsv.heap.GetAddressOf()))))
        {
            // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "深度ステンシルヒープの生成に失敗");
#endif // _DEBUG

            return false;
        }
    }


    // ☆ デバッグ時なら初期化の成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "深度ステンシルヒープの生成に成功");
#endif // _DEBUG


    // ☆ 深度ステンシルバッファ用ヒープ ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_HEAP_PROPERTIES heap_propertie;   // ヒープメモリの設定

        D3D12_RESOURCE_DESC desc_resource;    // リソース設定

        D3D12_CLEAR_VALUE clear_setting = {};   // 深度ステンシルバッファクリア時のパラメータ


        // ☆ ヒープメモリの設定 ☆ //

        // 初期化
        ZeroMemory(&heap_propertie, sizeof(heap_propertie));

        // ヒープの動作の種類
        heap_propertie.Type = D3D12_HEAP_TYPE_DEFAULT;

        // CPUのメモリがページングによって複数のメモリとして扱われている時にどのようにそのメモリにアクセスするか
        heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

        // メモリプール(起動時に一気にアプリで使用するデータを確保する場所)の種類を指定する
        heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

        // ヒープメモリを生成するノード(GPUや物理アダプター)の数
        heap_propertie.CreationNodeMask = 1;

        // リソースが存在するノードの数(GPUや物理アダプター)の数
        heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


        // ☆ リソースの設定 ☆ //

        // 初期化
        ZeroMemory(&desc_resource, sizeof(desc_resource));

        // 使用されるリソースの種類
        desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

        // 設定するリソース情報の配置番号
        desc_resource.Alignment = 0;

        // リソースのバイト数
        desc_resource.Width = 1920;

        // リソースの配列数
        desc_resource.Height = 1080;

        // リソースの深さ、または配列数
        desc_resource.DepthOrArraySize = 1;

        // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
        desc_resource.MipLevels = 0;

        // リソースがDX12側が用意した型かどうか
        desc_resource.Format = DXGI_FORMAT_D32_FLOAT;


        // ☆ サンプリング設定 ☆ //

        // サンプリング回数
        desc_resource.SampleDesc.Count = 1;

        // サンプリング時のクオリティ
        desc_resource.SampleDesc.Quality = 0;


        // テクスチャレイアウトのオプション
        desc_resource.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

        // リソースを操作するためのオプション
        desc_resource.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;


        
        // ☆ 深度ステンシルバッファクリア設定 ☆ //

        // クリア用の変数のデータ形式
        clear_setting.Format = DXGI_FORMAT_D32_FLOAT;

        // 初期化用深度値
        clear_setting.DepthStencil.Depth = 1.0f;

        // 初期化用ステンシル値
        clear_setting.DepthStencil.Stencil = 0;


        // ☆ 深度ステンシルバッファ生成 ☆ //
        if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_propertie, D3D12_HEAP_FLAG_NONE, &desc_resource, D3D12_RESOURCE_STATE_DEPTH_WRITE, &clear_setting, IID_PPV_ARGS(&mpr_variable->s_render.dsv.buffer))))
        {
            // ☆ デバッグ時なら初期化の失敗を表示 ☆ //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "深度ステンシルバッファの生成に失敗");
#endif // _DEBUG

            return false;
        }
    }


    // ☆ デバッグ時なら初期化の成功を表示 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "深度ステンシルバッファの生成に成功");
#endif // _DEBUG


    // ☆ 深度ステンシルビュー ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_DEPTH_STENCIL_VIEW_DESC dsv_desc = {};    //深度ステンシルビュー設定用情報


        // 深度ステンシルバッファのデータ形式
        dsv_desc.Format = DXGI_FORMAT_D32_FLOAT;

        // 深度ステンシルバッファの寸法（テクスチャ形式）
        dsv_desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;

        // テクスチャの使用方法
        dsv_desc.Flags = D3D12_DSV_FLAG_NONE;


        // アドレスの取得
        mpr_variable->s_render.dsv.handle = mpr_variable->s_render.dsv.heap->GetCPUDescriptorHandleForHeapStart();

        //深度ステンシルビュー生成
        mpr_variable->s_frame_work.device->CreateDepthStencilView(mpr_variable->s_render.dsv.buffer.Get(), &dsv_desc, mpr_variable->s_render.dsv.handle);
    }

    return true;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点バッファを生成する
// 引数   ：C_DX12_Vertex_Setting_Inform * & セット先の頂点データ, const C_Create_Vertex_Buffer_Inform & 頂点データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Vertex_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * & in_dx12_vertex_inform, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    D3D12_HEAP_PROPERTIES heap_properties;   // ヒープメモリの設定

    D3D12_RESOURCE_DESC desc_resource;    // リソース設定


    // ☆ ヒープメモリの設定 ☆ //

    // 初期化
    ZeroMemory(&heap_properties, sizeof(heap_properties));

    // ヒープの動作の種類
    heap_properties.Type = D3D12_HEAP_TYPE_UPLOAD;

    // CPUのメモリがページングによって複数のメモリとして扱われている時にどのようにそのメモリにアクセスするか
    heap_properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

    // メモリプール(起動時に一気にアプリで使用するデータを確保する場所)の種類を指定する
    heap_properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    // ヒープメモリを生成するノード(GPUや物理アダプター)の数
    heap_properties.CreationNodeMask = 0;

    // リソースが存在するノードの数(GPUや物理アダプター)の数
    heap_properties.VisibleNodeMask = heap_properties.CreationNodeMask;


    // ☆ リソースの設定 ☆ //

    // 初期化
    ZeroMemory(&desc_resource, sizeof(desc_resource));

    // 使用されるリソースの種類
    desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

    // 設定するリソース情報の配置番号
    desc_resource.Alignment = 0;

    // リソースのバイト数
    desc_resource.Width = in_create_inform.size_of_vertex * in_create_inform.vertex_sum;

    // リソースの配列番号
    desc_resource.Height = 1;

    // リソースの深さ、または配列数
    desc_resource.DepthOrArraySize = 1;

    // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
    desc_resource.MipLevels = 1;

    // リソースがDX12側が用意した型かどうか
    desc_resource.Format = DXGI_FORMAT_UNKNOWN;


    // ☆ サンプリング設定 ☆ //

    // サンプリング回数
    desc_resource.SampleDesc.Count = 1;

    // サンプリング時のクオリティ
    desc_resource.SampleDesc.Quality = 0;


    // テクスチャレイアウトのオプション
    desc_resource.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    // リソースを操作するためのオプション
    desc_resource.Flags = D3D12_RESOURCE_FLAG_NONE;


    // 頂点バッファのアドレス設定を生成(失敗でエラーを出して抜ける)
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
    (
        &heap_properties,
        D3D12_HEAP_FLAG_NONE,
        &desc_resource,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(in_dx12_vertex_inform->m_vertex_buffer_data.GetAddressOf())))
        || in_dx12_vertex_inform->m_vertex_buffer_data == nullptr
    )
    {
        return;
    }


    // ☆ 頂点バッファ設定 ☆ //

    // バッファの座標
    in_dx12_vertex_inform->m_vertex_buffer_view.BufferLocation = in_dx12_vertex_inform->m_vertex_buffer_data->GetGPUVirtualAddress();

    // 頂点バッファのバイト数
    in_dx12_vertex_inform->m_vertex_buffer_view.SizeInBytes = in_create_inform.size_of_vertex * in_create_inform.vertex_sum;

    // 要素のバイト数
    in_dx12_vertex_inform->m_vertex_buffer_view.StrideInBytes = in_create_inform.size_of_vertex;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：インデックスバッファを生成する
// 引数   ：C_DX12_Vertex_Setting_Inform * & セット先の頂点データ, const C_Create_Vertex_Buffer_Inform & 頂点データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Index_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * & in_dx12_vertex_inform, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    D3D12_HEAP_PROPERTIES heap_propertie;   // ヒープメモリの設定

    D3D12_RESOURCE_DESC desc_resource;    // リソース設定

    int byte_size = in_create_inform.index_sum * sizeof(uint32_t);  // バイト数


    // ☆ ヒープメモリの設定 ☆ //

    // 初期化
    ZeroMemory(&heap_propertie, sizeof(heap_propertie));

    // ヒープの動作の種類
    heap_propertie.Type = D3D12_HEAP_TYPE_UPLOAD;

    // CPUのメモリがページングによって複数のメモリとして扱われている時にどのようにそのメモリにアクセスするか
    heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

    // メモリプール(起動時に一気にアプリで使用するデータを確保する場所)の種類を指定する
    heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    // ヒープメモリを生成するノード(GPUや物理アダプター)の数
    heap_propertie.CreationNodeMask = 0;

    // リソースが存在するノードの数(GPUや物理アダプター)の数
    heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


    // ☆ リソースの設定 ☆ //

    // 初期化
    ZeroMemory(&desc_resource, sizeof(desc_resource));

    // 使用されるリソースの種類
    desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

    // 設定するリソース情報の配列数
    desc_resource.Alignment = 0;

    // リソースのバイト数
    desc_resource.Width = byte_size;

    // リソースの配列番号
    desc_resource.Height = 1;

    // リソースの深さ、または配列数
    desc_resource.DepthOrArraySize = 1;

    // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
    desc_resource.MipLevels = 1;

    // リソースがDX12側が用意した型かどうか
    desc_resource.Format = DXGI_FORMAT_UNKNOWN;


    // ☆ サンプリング設定 ☆ //

    // サンプリング回数
    desc_resource.SampleDesc.Count = 1;

    // サンプリング時のクオリティ
    desc_resource.SampleDesc.Quality = 0;


    // テクスチャレイアウトのオプション
    desc_resource.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    // リソースを操作するためのオプション
    desc_resource.Flags = D3D12_RESOURCE_FLAG_NONE;


    // 頂点バッファのアドレス設定を生成(失敗でエラーを出して抜ける)
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
    (
        &heap_propertie,
        D3D12_HEAP_FLAG_NONE,
        &desc_resource,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(in_dx12_vertex_inform->m_index_buffer_data.GetAddressOf())))
        || in_dx12_vertex_inform->m_index_buffer_data == nullptr
    )
    {
        return;
    }


    // GPUでのアドレスを入手
    in_dx12_vertex_inform->m_index_buffer_view.BufferLocation = in_dx12_vertex_inform->m_index_buffer_data->GetGPUVirtualAddress();

    // インデックスバッファのバイト数
    in_dx12_vertex_inform->m_index_buffer_view.SizeInBytes = byte_size;

    // インデックスバッファのデータ形式
    in_dx12_vertex_inform->m_index_buffer_view.Format = DXGI_FORMAT_R32_UINT;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数データ用のヒープを生成する
// 引数   ：C_DX12_Constant_Setting_Inform * & 設定先の定数用のデータ, const C_Create_Constant_Buffer_Inform & 定数用データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Constant_Heap(DX12INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // テクスチャ用のヒープの生成用情報


    // ヒープで管理するデータの管理
    descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

    // データ数
    descriptor_heap_desc.NumDescriptors = in_create_inform.m_list_size;

    // シェーダーから編集できるかどうか
    descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    // アダプターのノード数
    descriptor_heap_desc.NodeMask = 0;


    // テクスチャヒープの生成
    if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_heap))))
    {
        return;
    }

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数データ用の情報を生成する
// 引数   ：C_DX12_Constant_Setting_Inform * & 設定先の定数用のデータ, const C_Create_Constant_Buffer_Inform & 定数用データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Constant_Resource(DX12INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // ☆ 定数 ☆ //
    const int con_CONSTANT_BUFFER_ONE_BYTE = 256;	// 定数バッファ一つ分のバイト数


    // ☆ 定数バッファデータを生成 ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_HEAP_PROPERTIES constant_data_prop;   // 定数データ生成用のプロパティ設定
        
        D3D12_RESOURCE_DESC constant_data_desc;     // 定数バッファのデータの設定


        // ☆ プロパティ設定 ☆ //

        // ヒープの動作の種類
        constant_data_prop.Type = D3D12_HEAP_TYPE_UPLOAD;

        // CPUのメモリがページングによって複数のメモリとして扱われている時にどのようにそのメモリにアクセスするか
        constant_data_prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    
        // メモリプール(起動時に一気にアプリで使用するデータを確保する場所)の種類を指定する
        constant_data_prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    
        // ヒープメモリを生成するノード(GPUや物理アダプター)の数
        constant_data_prop.CreationNodeMask = 1;
    
        // リソースが存在するノードの数(GPUや物理アダプター)の数
        constant_data_prop.VisibleNodeMask = 1;


        // ☆ データ設定 ☆ //

        // 使用されるリソースの種類
        constant_data_desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

        // 設定するリソース情報の配置位置を指定
        constant_data_desc.Alignment = 0;

        // リソースのバイト数
        constant_data_desc.Width = con_CONSTANT_BUFFER_ONE_BYTE; // 定数バッファサイズは256バイトでなければならない

        // リソースの配列番号
        constant_data_desc.Height = in_create_inform.m_list_size;

        // リソースの深さ、または配列数
        constant_data_desc.DepthOrArraySize = 1;

        // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
        constant_data_desc.MipLevels = 1;

        // リソースがDX12側が用意した型かどうか
        constant_data_desc.Format = DXGI_FORMAT_UNKNOWN;
        

        // ☆ サンプリング設定 ☆ //

        // サンプリング回数
        constant_data_desc.SampleDesc.Count = 1;

        // サンプリング時のクオリティ
        constant_data_desc.SampleDesc.Quality = 0;

        // テクスチャレイアウトのオプション
        constant_data_desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

        // リソースを操作するためのオプション
        constant_data_desc.Flags = D3D12_RESOURCE_FLAG_NONE;


        // 定数バッファのデータを生成
        if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&constant_data_prop, D3D12_HEAP_FLAG_NONE, &constant_data_desc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_data))))
        {
            return;
        }
    }
    

    // ☆ 定数バッファビューの設定 ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_CONSTANT_BUFFER_VIEW_DESC constant_buffer_view_desc = {};  // 定数バッファビュー生成用情報
        

        // 定数バッファのGPUでのアドレス
        constant_buffer_view_desc.BufferLocation = in_dx12_constant_setting->m_constant_buffer_data->GetGPUVirtualAddress();
        
        // バイト数
        constant_buffer_view_desc.SizeInBytes = con_CONSTANT_BUFFER_ONE_BYTE * in_create_inform.m_list_size;


        // 定数バッファビューの生成
        mpr_variable->s_frame_work.device->CreateConstantBufferView(&constant_buffer_view_desc, in_dx12_constant_setting->m_constant_buffer_heap->GetCPUDescriptorHandleForHeapStart());
    }

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ用のビューとヒープを生成する
// 引数   ：C_DX12_Rendering_Texture_Setting_Inform * & 設定先のテクスチャ用のデータ, const C_Create_Texture_Setting_Inform & テクスチャ用データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Texture_Resource_View_And_Heap(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // ☆ ディスクリプタヒープの生成 ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // テクスチャ用のヒープの生成用情報


        // ヒープで管理するデータの管理
        descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

        // データ数
        descriptor_heap_desc.NumDescriptors = 1;

        // シェーダーから編集できるかどうか
        descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

        // アダプターのノード数
        descriptor_heap_desc.NodeMask = 0;


        // テクスチャヒープの生成
        if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_texture_setting->mpr_variable.texture_heap))))
        {
            return;
        }
    }


    // ☆　ディスクリプタビューの生成 ☆ //
    {
        // ☆ 変数宣言 ☆ //
        D3D12_SHADER_RESOURCE_VIEW_DESC resource_view_desc = {};  // テクスチャ用リソースビュー設定用構造体の設定


        // データ形式
        resource_view_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

        // リソースの種類
        resource_view_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;

        // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
        resource_view_desc.Texture2D.MipLevels = 1;

        // ミップマップが最も細かい時の細かさ
        resource_view_desc.Texture2D.MostDetailedMip = 0;

        // シェーダーへのマッピング方法
        resource_view_desc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;


        // ビューを生成する
        mpr_variable->s_frame_work.device->CreateShaderResourceView(in_dx12_texture_setting->mpr_variable.texture_data.Get(), &resource_view_desc, in_dx12_texture_setting->mpr_variable.texture_heap->GetCPUDescriptorHandleForHeapStart());
    }

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ用のデータを生成する
// 引数   ：C_DX12_Rendering_Texture_Setting_Inform * & 設定先のテクスチャ用のデータ, const C_Create_Texture_Setting_Inform & テクスチャ用データ生成用情報(const)
// 戻り値 ：戻り値：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Texture_Resource(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    D3D12_RESOURCE_DESC resource_desc_for_tex;  // テクスチャ生成用の設定
    
    D3D12_HEAP_PROPERTIES heap_properties_setting;    // ヒープ設定用の情報


    // メモリの初期化
    ZeroMemory(&heap_properties_setting, sizeof(heap_properties_setting));
    ZeroMemory(&resource_desc_for_tex, sizeof(resource_desc_for_tex));
    
    
    // ☆ ヒープの設定 ☆ //

    // ヒープの動作の種類
    heap_properties_setting.Type = D3D12_HEAP_TYPE_CUSTOM;

    // CPUのメモリがページングによって複数のメモリとして扱われている時にどのようにそのメモリにアクセスするか
    heap_properties_setting.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;

    // メモリプール(起動時に一気にアプリで使用するデータを確保する場所)の種類を指定する
    heap_properties_setting.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;

    // ヒープメモリを生成するノード(GPUや物理アダプター)の数
    heap_properties_setting.CreationNodeMask = 1;

    // リソースが存在するノードの数(GPUや物理アダプター)の数
    heap_properties_setting.VisibleNodeMask = 1;


    // ☆ リソースの設定 ☆ //

    // 使用されるリソースの種類
    resource_desc_for_tex.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    // 設定するリソース情報の配置番号
    resource_desc_for_tex.Alignment = 0;

    // リソースのバイト数
    resource_desc_for_tex.Width = in_create_inform.pixel_width;
    in_dx12_texture_setting->mpr_variable.pix_size_x = in_create_inform.pixel_width;

    // リソースの配列番号
    resource_desc_for_tex.Height = in_create_inform.pixel_height;
    in_dx12_texture_setting->mpr_variable.pix_size_y = in_create_inform.pixel_height;

    // リソースの深さ、または配列数
    resource_desc_for_tex.DepthOrArraySize = 1;

    // MIPMAPレベル(この数値に応じてピクセル数が倍になる)
    resource_desc_for_tex.MipLevels = 1;

    // リソースがDX12側が用意した型かどうか
    resource_desc_for_tex.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    // ☆ サンプリング設定 ☆ //

    // サンプリング回数
    resource_desc_for_tex.SampleDesc.Count = 1;

    // サンプリング時のクオリティ
    resource_desc_for_tex.SampleDesc.Quality = 0;

    // テクスチャレイアウトのオプション
    resource_desc_for_tex.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

    // リソースを操作するためのオプション
    resource_desc_for_tex.Flags = D3D12_RESOURCE_FLAG_NONE;


    // リソースを生成する    // 失敗したらエラーで抜ける
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_properties_setting, D3D12_HEAP_FLAG_NONE, &resource_desc_for_tex, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(in_dx12_texture_setting->mpr_variable.texture_data.GetAddressOf()))))
    {
        return false;
    }

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ルートシグネチャのパラメータの設定を行う
// 引数   ：vector<D3D12_ROOT_PARAMETER> & 設定先ルートパラメーターの参照, vector<D3D12_DESCRIPTOR_RANGE> & 設定先のレンジの参照, D3D12_DESCRIPTOR_RANGE_TYPE 設定する種類, int レジスタ番号, int シェーダー番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void Inline_Set_Root_Parameter(std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, D3D12_DESCRIPTOR_RANGE_TYPE in_set_type, int register_num, int shader_num)
{
    // ☆ 変数宣言 ☆ //
    int set_param_number = (int)in_root_param.size();    // 設定先のパラメータの配列番号
    int set_range_pos = (int)in_range.size();    // 設定先のレンジ番号


    // 配列を必要なだけ増やす
    in_root_param.resize(set_param_number + 1);
    in_range.resize(set_range_pos + 1);

    // パラメータの種類
    in_range[set_range_pos].RangeType = in_set_type;

    // いくつの定数バッファやテクスチャをこのレジスタで管理するか（配列数）
    in_range[set_range_pos].NumDescriptors = 1;

    // シェーダーでのレジスタ番号
    in_range[set_range_pos].BaseShaderRegister = register_num;

    // レジスタのスペース番号
    in_range[set_range_pos].RegisterSpace = 0;

    // レンジ内で何バイト目にデータが来るか
    in_range[set_range_pos].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;


    // ☆ パラメータ設定 ☆ //

    // スロットの種類
    in_root_param[set_param_number].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;

    // レンジの配列数
    in_root_param[set_param_number].DescriptorTable.NumDescriptorRanges = 1;

    // レンジのアドレス
    in_root_param[set_param_number].DescriptorTable.pDescriptorRanges = &in_range[set_range_pos];

    // どのシェーダーでこのスロットを使うか
    in_root_param[set_param_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)shader_num;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ルートシグネチャのパラメータの設定を行う
// 引数   ：vector<D3D12_STATIC_SAMPLER_DESC> & サンプラー設定用情報, int レジスタ番号, int シェーダー番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void Inline_Set_Sampler_State(std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler_desc, int in_register_num, int in_shader_num)
{
    // ☆ 変数宣言 ☆ //
    int set_static_number = (int)in_sampler_desc.size();    // 設定先のパラメータの配列番号


    // 配列を必要なだけ増やす
    in_sampler_desc.resize(set_static_number + 1);


    // フィルタ処理のオプション
    in_sampler_desc[set_static_number].Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;

    // U座標の処理の仕方
    in_sampler_desc[set_static_number].AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // V座標の処理の仕方
    in_sampler_desc[set_static_number].AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // W座標の処理の仕方
    in_sampler_desc[set_static_number].AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // ミップマップレベルのオフセット
    in_sampler_desc[set_static_number].MipLODBias = 0.0f;

    // フィルタがD3D12_FILTER_ANISOTROPICまたはD3D12_FILTER_COMPARISON_ANISOTROPICのときに使用されるクランプ値
    in_sampler_desc[set_static_number].MaxAnisotropy = 16;

    // サンプリングされたデータを既存のサンプリング データと比較する関数を選ぶ
    in_sampler_desc[set_static_number].ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;

    // D3D12_TEXTURE_ADDRESS_MODE_BORDERがAddressUVWに設定されている時の境界線の色
    in_sampler_desc[set_static_number].BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;

    // ミップマップレベルの詳細度の最低値
    in_sampler_desc[set_static_number].MinLOD = 0.0f;

    // ミップマップレベルの詳細度の最高値
    in_sampler_desc[set_static_number].MaxLOD = D3D12_FLOAT32_MAX;

    // シェーダーでのレジスタ番号
    in_sampler_desc[set_static_number].ShaderRegister = in_register_num;

    // レジスタのスペース番号
    in_sampler_desc[set_static_number].RegisterSpace = 0;

    // どのシェーダーからアクセスできるか
    in_sampler_desc[set_static_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)in_shader_num;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ルートシグネチャデスクにディスクリプタスロットとサンプラーを設定する
// 引数   ：D3D12_ROOT_SIGNATURE_DESC & ルートシグネチャの設定用情報の参照, vector<D3D12_ROOT_PARAMETER> & ディスクリプタ設定用情報の参照, vector<D3D12_STATIC_SAMPLER_DESC> & サンプラー設定用情報の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(D3D12_ROOT_SIGNATURE_DESC & in_root_signature, std::vector<D3D12_ROOT_PARAMETER> & in_parameter, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler)
{
    // ディスクリプタ情報があればディスクリプタスロット数と最初のアドレスをセット
    if (in_parameter.size() > 0)
    {
        in_root_signature.NumParameters = (UINT)in_parameter.size();
        in_root_signature.pParameters = &in_parameter[0];
    }

    // なければゼロクリアする
    else
    {
        in_root_signature.NumParameters = 0;
        in_root_signature.pParameters = nullptr;
    }


    // サンプラーがあればサンプラー数と最初のアドレスをセット
    if (in_parameter.size() > 0)
    {
        in_root_signature.NumStaticSamplers = (UINT)in_parameter.size();
        in_root_signature.pStaticSamplers = &in_sampler[0];
    }

    // なければゼロクリアする
    else
    {
        in_root_signature.NumStaticSamplers = 0;
        in_root_signature.pStaticSamplers = nullptr;
    }

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーのデータをDX12用のバイトコードにセットする
// 引数   ：D3D12_SHADER_BYTECODE & セット先のバイトコードの参照, const C_Shader_Code * セットするシェーダーコード
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void Inline_Set_Shader_Data(D3D12_SHADER_BYTECODE & in_set_code, const ASSET::SHADER::C_Shader_Code * in_shader_code)
{
    // シェーダーのコードがないなら抜ける
    if (in_shader_code == nullptr)
    {
        return;
    }

    // バイトコードのアドレスとサイズをセット
    in_set_code.pShaderBytecode = in_shader_code->M_Get_Compiled_Cord().get();
    in_set_code.BytecodeLength = in_shader_code->M_Get_Cord_Size();

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ルートシグネチャデスクからルートシグネチャをシリアライズし生成する
// 引数   ：const D3D12_ROOT_SIGNATURE_DESC & ルートシグネチャを設定するための情報の参照(const), ComPtr<ID3D12RootSignature> & ルートシグネチャの設定先
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Serialize_And_Creat_RootSignature_By_Desc(const D3D12_ROOT_SIGNATURE_DESC & in_root_signature_desc, Microsoft::WRL::ComPtr<ID3D12RootSignature> & in_root_signature)
{
    // ☆ 変数宣言 ☆ //
    ID3DBlob * root_signature_serialized_data = nullptr;    // ルート署名生成時のシリアライズデータを得る


    // ☆ ルートシグネチャ生成用情報をリソースとしてシリアライズする ☆ //		// 失敗でエラーを出す
    if (FAILED(D3D12SerializeRootSignature(&in_root_signature_desc, D3D_ROOT_SIGNATURE_VERSION_1, &root_signature_serialized_data, nullptr)))
    {
        // デバッグ時は失敗ログを出力
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "ルートシグネチャのシリアライズ化に失敗しました");
#endif // _DEBUG

        return false;
    }


    // ☆ ルートシグネチャの生成 ☆ //	// 失敗でエラーを出す
    if (FAILED(mpr_variable->s_frame_work.device->CreateRootSignature(0, root_signature_serialized_data->GetBufferPointer(), root_signature_serialized_data->GetBufferSize(), IID_PPV_ARGS((ID3D12RootSignature**)&in_root_signature))))
    {
        // デバッグ時は失敗ログを出力
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "ルートシグネチャの生成に失敗しました");
#endif // _DEBUG

        return false;
    }


    // デバッグ時は成功ログを出力
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "ルートシグネチャの生成に成功しました");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ルートシグネチャを生成する
// 引数   ：C_DX12_Rendering_Graphics_Setting_Inform * & セット先の描画パイプライン用データ, const C_Create_Vertex_Buffer_Inform & 描画パイプライン用データ生成用情報(const)
// 戻り値 ：bool 成功時はtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Root_Signature(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    D3D12_ROOT_SIGNATURE_DESC root_signature_desc;	// ルート署名（シグネチャ）生成用情報

    std::vector<D3D12_STATIC_SAMPLER_DESC> static_sampler_desc; // 静的サンプラー生成用情報

    std::vector<D3D12_DESCRIPTOR_RANGE> range_setting_list;    // 記述子の範囲を設定する情報

    std::vector<D3D12_ROOT_PARAMETER> paramater_setting_list;  // テクスチャや定数バッファを設定する場所の生成用情報


    // シェーダー毎にリソースを定義する（ディスクリプタとレンジ、サンプラーを生成する）
    M_Create_Descriptor_And_Sampler_By_Shaders_Inform(in_create_inform.shader_setting->M_Get_Resource_Signature(), paramater_setting_list, range_setting_list, static_sampler_desc);


    // ☆ ルートシグネチャデスクの設定 ☆ //

    // 初期化
    ZeroMemory(&root_signature_desc, sizeof(root_signature_desc));

    // ルートシグネチャデスクにディスクリプタスロットとサンプラーを設定する
    Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(root_signature_desc, paramater_setting_list, static_sampler_desc);

    // ルート署名のレイアウトオプション
    root_signature_desc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;


    // ☆ ルートシグネチャの生成 ☆ //

    // ルートシグネチャを生成して結果を返す
    return M_Serialize_And_Creat_RootSignature_By_Desc(root_signature_desc, in_dx12_pipeline_inform->m_root_signature);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：パイプラインステートを生成する
// 引数   ：C_DX12_Rendering_Graphics_Setting_Inform * & セット先の描画パイプライン用データ, const C_Create_Vertex_Buffer_Inform & 描画パイプライン用データ生成用情報(const)
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Pipeline_State(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Input_Layout_Setting_System input_setting_system;    // 入力レイアウト設定用システム

    D3D12_GRAPHICS_PIPELINE_STATE_DESC desc_pipeline_state; // パイプライン設定用情報

    D3D12_SHADER_BYTECODE * add_shader_list[] =    // 設定するシェーダーのアドレスのリスト
    {
        &desc_pipeline_state.VS,
        &desc_pipeline_state.HS,
        &desc_pipeline_state.DS,
        &desc_pipeline_state.GS,
        &desc_pipeline_state.PS,
    };


    // 初期化
    ZeroMemory(&desc_pipeline_state, sizeof(desc_pipeline_state));


    // ☆ ルートシグネチャのセット ☆ //
    desc_pipeline_state.pRootSignature = in_dx12_pipeline_inform->m_root_signature.Get();


    // シェーダーの種類ごとに指定された番号をセット
    {
        // ☆ 変数宣言 ☆ //
        const ASSET::SHADER::S_Shader_Byte_Code_List & shader_code_list = in_create_inform.shader_setting->M_Get_Shader_Code_List(); // 指定されたシェーダーセットのコードのリスト


        for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
        {
            Inline_Set_Shader_Data(*add_shader_list[now_shader_kind], shader_code_list.list[now_shader_kind]);
        }
    }

    // シェーダーの情報を設定
    in_dx12_pipeline_inform->m_shader_setting = *in_create_inform.shader_setting;


    // ☆ 入力レイアウトの設定 ☆ //
    input_setting_system.M_Create_Input_Layout_By_Create_Inform(desc_pipeline_state.InputLayout, in_create_inform.shader_setting->M_Get_Input_Layout());


    // ☆ ストリーミング出力バッファ ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(desc_pipeline_state);


    // ☆ ブレンド状態設定 ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(desc_pipeline_state, in_create_inform);


    // ☆ レンダーターゲットで更新されるサンプル数 ☆ //
    desc_pipeline_state.SampleMask = UINT_MAX;


    // ☆ ラスタライザー設定（画像変換時の設定） ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Rasterrizer_State_Setting_System::M_Law_Cost_Setting(desc_pipeline_state);


    // ☆ 深度ステンシル設定 ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Disabled_Depth_Stencil(desc_pipeline_state);


    // ☆ 表向きの面の深度ステンシルテスト設定 ☆ //    // 法線がカメラの方を向いているかどうかで判定する
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.FrontFace);


    // ☆ 裏向きの面の深度ステンシルテスト設定 ☆ //    // 法線がカメラの方を向いているかどうかで判定する
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.BackFace);


    // ☆ マルチサンプリング設定 ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Sampling_Setting_System::M_Sampling_Setting(desc_pipeline_state, in_create_inform.sampling_setting.sampling_count, in_create_inform.sampling_setting.sampling_quality, 0);


    // ☆ パイプラインステートの取得用の設定 ☆ //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Cached_PSO_Base::M_Cashe_Nothing(desc_pipeline_state);


    // ☆ パイプライン生成 ☆ //  // エラーなら抜ける
    if (FAILED(mpr_variable->s_frame_work.device->CreateGraphicsPipelineState(&desc_pipeline_state, IID_PPV_ARGS(&in_dx12_pipeline_inform->m_pipeline_state_setting))))
    {
        // デバッグ時は失敗を告知
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "パイプラインステートの生成に失敗しました");
#endif // _DEBUG

        return false;
    }


    // デバッグ時は成功ログを出力
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "パイプラインステートの生成に成功しました");
#endif // _DEBUG


    // 設定用の情報をクローズ
    input_setting_system.M_Close_Input_Layout_Inform();

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダー毎にリソースを定義する（ディスクリプタとレンジ、サンプラーを生成する）
// 引数   ：const S_All_Shader_Resource_Signatures & シェーダーのリソース識別情報の参照, vector<D3D12_ROOT_PARAMETER> & ディスクリプタ設定用情報の参照, vector<D3D12_DESCRIPTOR_RANGE> & レンジの設定用情報の参照, vector<D3D12_STATIC_SAMPLER_DESC> & サンプラー設定用情報の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Descriptor_And_Sampler_By_Shaders_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & in_shader_inform, std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler)
{
    // ☆ 変数宣言 ☆ //
    int shader_paramater_register_start = 0;    // シェーダーのディスクリプタの開始レジスタ番号
    int shader_sampler_register_start = 0;      // シェーダーのサンプラーの開始レジスタ番号


    // ☆ 全てのシェーダーに共通する情報の設定 ☆ //
    {
        // ☆ 変数宣言 ☆ //
        int constant_buffer_sum = (int)in_shader_inform.all_shader_signature.constant_data.size();   // 定数バッファ数
        int texture_sum = (int)in_shader_inform.all_shader_signature.texture_data.size();   // テクスチャリソース数
        int sampler_sum = in_shader_inform.all_shader_signature.sampler_sum;   // サンプラー数
        

        // シェーダーの定数バッファ分繰り返す
        for (int now_csv_num = 0; now_csv_num < constant_buffer_sum; now_csv_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_CBV, shader_paramater_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_paramater_register_start += 1;
        }

        // シェーダーのテクスチャデータ分繰り返す
        for (int now_texture_num = 0; now_texture_num < texture_sum; now_texture_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, shader_paramater_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_paramater_register_start += 1;
        }


        // サンプラー分繰り返す
        for (int now_sampler_num = 0; now_sampler_num < sampler_sum; now_sampler_num++)
        {
            Inline_Set_Sampler_State(in_sampler, shader_sampler_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_sampler_register_start += 1;
        }
    }


    // ☆ シェーダー毎にディスクリプタの設定 ☆ //
    for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
    {
        // ☆ 変数宣言 ☆ //
        int constant_buffer_sum = (int)in_shader_inform.signature_list[now_shader_kind].constant_data.size();   // 定数バッファ数
        int texture_sum = (int)in_shader_inform.signature_list[now_shader_kind].texture_data.size();   // テクスチャリソース数
        int sampler_sum = (int)in_shader_inform.signature_list[now_shader_kind].sampler_sum;   // サンプラー数
        int set_param_register_num = shader_paramater_register_start; // 設定するレジスタ番号
        int set_sampler_register_num = shader_sampler_register_start; // 設定するレジスタ番号


        // シェーダーの定数バッファ分繰り返す
        for (int now_csv_num = 0; now_csv_num < constant_buffer_sum; now_csv_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_CBV, set_param_register_num, now_shader_kind + 1);  // D3D12_SHADER_VISIBILITYではVERTEX_BUFFERが1からなので合わせるために1加算

            set_param_register_num += 1;
        }

        // シェーダーのテクスチャデータ分繰り返す
        for (int now_texture_num = 0; now_texture_num < texture_sum; now_texture_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, set_param_register_num, now_shader_kind + 1);

            set_param_register_num += 1;
        }

        // サンプラー分繰り返す
        for (int now_sampler_num = 0; now_sampler_num < sampler_sum; now_sampler_num++)
        {
            Inline_Set_Sampler_State(in_sampler, set_sampler_register_num, now_shader_kind + 1);

            set_sampler_register_num += 1;
        }
    }

    return;
}


//-☆- 更新 -☆-//

//-☆- デバッグ -☆-//
#if _DEBUG
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグ時のみ行う更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Debug_Update(void)
{
    // ☆ ウィンドウタイトルをテスト用に更新 ☆ //
    //OS::BASE::C_OS_System_Base::m_this_instance->M_Set_Window_Title();

    return;
}
#endif // _DEBUG


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：リソース同期用バリアのセット
// 引数   ：D3D12_RESOURCE_STATES 切り替え前の使用法, D3D12_RESOURCE_STATES 切り替えの後の使用法
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Set_Resource_Barrier(D3D12_RESOURCE_STATES in_before, D3D12_RESOURCE_STATES in_after)
{
    // ☆ 変数宣言 ☆ //
    D3D12_RESOURCE_BARRIER desc_resource_barrier;   // リソースバリア設定用情報


    // 初期化
    ZeroMemory(&desc_resource_barrier, sizeof(desc_resource_barrier));

    // リソースバリアの種類
    desc_resource_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;

    // リソースへのアドレス
    desc_resource_barrier.Transition.pResource = mpr_variable->s_render.rtv.render_buffer[mpr_variable->s_command.num_back_screen].Get();

    // サブリソースのインデックス
    desc_resource_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

    // 切り替え前の使用法セット
    desc_resource_barrier.Transition.StateBefore = in_before;

    // 切り替え後の使用法セット
    desc_resource_barrier.Transition.StateAfter = in_after;


    // バリアのセット
    mpr_variable->s_command.list->ResourceBarrier(1, &desc_resource_barrier);
    
    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面をクリアする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Clear_Screen(void)
{
    // レンダーターゲットの画面情報クリア
    mpr_variable->s_command.list->ClearRenderTargetView(mpr_variable->s_render.rtv.handle[mpr_variable->s_command.num_back_screen], mpr_variable->s_frame_work.clear_color, 0, nullptr);

    // 深度ステンシルの初期化
    mpr_variable->s_command.list->ClearDepthStencilView(mpr_variable->s_render.dsv.handle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    //  ビューのバインド
    mpr_variable->s_command.list->OMSetRenderTargets(1, &mpr_variable->s_render.rtv.handle[mpr_variable->s_command.num_back_screen], TRUE, &mpr_variable->s_render.dsv.handle);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コマンド実行待ち
// 引数   ：ID3D12Resource * リソースへのアドレス, D3D12_RESOURCE_STATES サブリソース発生の前の使用法, D3D12_RESOURCE_STATES サブリソース発生の後の使用法
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Wait_For_Command_Queue(void)
{
    // ☆ 変数宣言 ☆ //
    static int fence_value = 1;  // フェンスのインクリメントを判定するための値
    
    UINT64 result_fence = fence_value; // 結果のフェンス値を受け取る


    // 今のフェンス値を受け取る
    mpr_variable->s_command.queue->Signal(mpr_variable->s_render.queue_fence.Get(), result_fence);


    // 判定用のフェンス値をインクリメント
    fence_value += 1;


    // ☆ まだコマンドキューが終了していないことを確認する ☆ //
    if (mpr_variable->s_render.queue_fence->GetCompletedValue() < result_fence)
    {
        // このFenceにおいて、fvalue の値になったらフェンスイベントを実行
        mpr_variable->s_render.queue_fence->SetEventOnCompletion(result_fence, mpr_variable->s_render.fence_event);


        // イベントが発火するまで待つ
        WaitForSingleObject(mpr_variable->s_render.fence_event, INFINITE);
    }

    return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ビューポートとシザーの設定を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Set_Scissor_And_View_Port(void)
{
    // ☆ 変数宣言 ☆ //
    D3D12_VIEWPORT view_port = {};	// ビューポートパラメータ

    D3D12_RECT scissor_rect = {};	// シザーレクト


    // ☆ ビューポート設定 ☆ //

    // 画面サイズ
    view_port.Width = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size().width;
    view_port.Height = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size().height;

    // 画面の左上座標
    view_port.TopLeftX = 0.0f;
    view_port.TopLeftY = 0.0f;

    // 深度設定
    view_port.MinDepth = 0.0f;
    view_port.MaxDepth = 1.0f;


    // ☆ シザーレクト設定 ☆ //

    // 座標設定
    scissor_rect.left = 0;
    scissor_rect.right = (LONG)view_port.Width;
    scissor_rect.top = 0;
    scissor_rect.bottom = (LONG)view_port.Height;


    // 画面サイズ更新
    mpr_variable->s_command.list->RSSetViewports(1, &view_port);
    mpr_variable->s_command.list->RSSetScissorRects(1, &scissor_rect);

    return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画コマンド情報をリセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Reset_Command(void)
{
    // コマンドアロケータのメモリを初期化して再利用可能にする
    mpr_variable->s_command.allocator->Reset();

    // コマンドリストを初期状態にリセット（これをしないと書き込み可能にならない）
    mpr_variable->s_command.list->Reset(mpr_variable->s_command.allocator.Get(), nullptr);

    return;
}


//-☆- 識別用情報 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパイプライン情報を元にシェーダーのリソース識別名をセットする
// 引数   ：const C_DX12_Rendering_Graphics_Setting_Inform * & パイプライン情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Set_Shader_Resource_Signature_By_Rendering_Setting(const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_rendering_setting)
{
    mpr_variable->shader_resource_list.release();
    mpr_variable->shader_resource_list.reset(&in_rendering_setting->m_shader_setting.M_Get_Resource_Signature());

    return;
}


//-☆- 種別 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された機能レベルを文字列に変換する
// 引数   ：D3D_FEATURE_LEVEL 機能レベル指定用列挙
// 戻り値 ：std::string 変換後の文字列
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_DX12_System::M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(D3D_FEATURE_LEVEL in_feature_level)
{
    // ☆ 機能レベルで分岐 ☆ //
    switch (in_feature_level)
    {
        // コンピューティング専用モデル
    case D3D_FEATURE_LEVEL_1_0_CORE:
        return "D3D_FEATURE_LEVEL_1_0_CORE";

        // DirectX9
    case D3D_FEATURE_LEVEL_9_1:
        return "D3D_FEATURE_LEVEL_9_1";
    case D3D_FEATURE_LEVEL_9_2:
        return "D3D_FEATURE_LEVEL_9_2";
    case D3D_FEATURE_LEVEL_9_3:
        return "D3D_FEATURE_LEVEL_9_3";

        // DirectX10
    case D3D_FEATURE_LEVEL_10_0:
        return "D3D_FEATURE_LEVEL_10_0";
    case D3D_FEATURE_LEVEL_10_1:
        return "D3D_FEATURE_LEVEL_10_1";

        // DirectX11
    case D3D_FEATURE_LEVEL_11_0:
        return "D3D_FEATURE_LEVEL_11_0";
    case D3D_FEATURE_LEVEL_11_1:
        return "D3D_FEATURE_LEVEL_11_1";

        // DirectX12
    case D3D_FEATURE_LEVEL_12_0:
        return "D3D_FEATURE_LEVEL_12_0";
    case D3D_FEATURE_LEVEL_12_1:
        return "D3D_FEATURE_LEVEL_12_1";
    case D3D_FEATURE_LEVEL_12_2:
        return "D3D_FEATURE_LEVEL_12_2";
    }

    // 未定義の番号
    return "Undefined";
}


//==☆  パブリック  ☆==//

//-☆-  初期化と終了時  -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：DX12システムの初期化
// 引数   ：void
// 戻り値 ：bool 立ち上げに成功していたらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Set_Up(void)
{
	// DX12システムの初期化
	if (M_DirectX12_Init() == false)
	{
        // ☆ デバッグ時のみセットアップ失敗を通知 ☆ //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "Error-☆-☆-☆-☆-☆-☆-☆-DX12のセットアップ失敗-☆-☆-☆-☆-☆-☆-☆-Error");
#endif // _DEBUG

		return false;	// 失敗ならエラーを返して抜ける
	}


    // ☆ デバッグ時のみセットアップ完了を通知 ☆ //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-DX12のセットアップ完了-☆-☆-☆-☆-☆-☆-☆-");
    DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
    DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG

	// 成功した
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：DX12を生成する処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_DirectX12(void)
{
    // ☆ 生成してセット ☆ //   // 既に生成していたデータは消される
    m_this.reset(new C_DX12_System);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Release(void)
{
    // 未解放ならば解放
    if (mpr_variable)
    {
        CloseHandle(mpr_variable->s_render.fence_event);
        mpr_variable.reset();
    }
    
    mpr_variable->shader_resource_list.release();

    return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_System::~C_DX12_System()
{
    M_Release();

	return;
}


//-☆- レンダリング -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画開始用の処理、コマンドを初期化し裏画面のリソースを同期させレンダーターゲット先に指定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Start(void)
{
    // ☆ コマンド初期化 ☆ //
    M_Reset_Command();


    // 描画先の画面を入手する(裏画面を指定)
    mpr_variable->s_command.num_back_screen = mpr_variable->s_frame_work.swap_chain->GetCurrentBackBufferIndex();


    // リソース同期用のバリアを描画書き込み用に変更 (変更が完了するまで待つ)
    M_Set_Resource_Barrier(D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);


    // ビューポートとシザーの更新
    M_Set_Scissor_And_View_Port();


    // 画面クリア
    M_Clear_Screen();

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：次の描画実行を開始する
// 引数   ：const unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & セットするレンダリングの設定の情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_pipeline_inform)
{
    // ☆ 変数宣言 ☆ //
    const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * > (in_pipeline_inform.get());   // 描画パイプライン用情報をDX12用へキャストした結果のアドレス


    // 描画する図形を設定
    mpr_variable->s_command.list->IASetPrimitiveTopology(dx12_pipeline_inform->m_topology_type);

    // ルートシグネチャのセット
    mpr_variable->s_command.list->SetGraphicsRootSignature(dx12_pipeline_inform->m_root_signature.Get());

    // パイプラインステートを設定する
    mpr_variable->s_command.list->SetPipelineState(dx12_pipeline_inform->m_pipeline_state_setting.Get());


    // 識別用情報を設定する
    M_Set_Shader_Resource_Signature_By_Rendering_Setting(dx12_pipeline_inform);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：定数データをセットする
// 引数   ：S_Constant_Buffer_Drawing_Setting & セットする定数データ情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & in_constant_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_inform = reinterpret_cast<DX12INSTANCE::C_DX12_Constant_Setting_Inform*>(in_constant_inform.add_constant_buffer);   // 描画用情報をDX12用へキャストした結果のアドレス

    int slot_number = 0;    // 定数バッファ設定先のスロット番号

    bool flg_slot_exist = false;    // スロットを発見できたかどうかのフラグ


    // 全シェーダー共通の定数バッファに書き込む
    if (*in_constant_inform.add_attach_shader_kind == ASSET::SHADER::E_SHADER_KIND::e_ALL)
    {
        // ☆ 変数宣言 ☆ //
        int constant_slot_sum = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();   // 定数バッファ数


        // 定数バッファのスロット数分繰り返す、文字列が一致したら発見できたので番号を指定してループを抜ける
        for (int l_now_slot_number = 0; l_now_slot_number < constant_slot_sum && flg_slot_exist == false; l_now_slot_number++)
        {
            if (mpr_variable->shader_resource_list->all_shader_signature.constant_data[l_now_slot_number].signature_name == *in_constant_inform.add_signature_name)
            {
                slot_number = l_now_slot_number;

                flg_slot_exist = true;
            }
        }
    }

    // 各シェーダーに用意されている定数バッファに書き込む
    else
    {
        // ☆ 変数宣言 ☆ //
        int constant_slot_sum = (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data.size();   // 定数バッファのスロット数
        int slot_skipped = 0;   // 通過したスロット数


        // 全てのシェーダーに共通するスロットは飛ばす
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();
        slot_skipped += (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();


        // 他のシェーダー用のスロットは飛ばす
        for (int now_shader_kind = 0; now_shader_kind < (int)*in_constant_inform.add_attach_shader_kind; now_shader_kind++)
        {
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data.size();
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].texture_data.size();
        }


        // 定数バッファのスロット数分繰り返す、文字列が一致したら発見できたので番号を指定してループを抜ける
        for (int l_slot_number = 0; l_slot_number < constant_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data[l_slot_number].signature_name == *in_constant_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }


    // スロットがみつからなかったら抜ける
    if (flg_slot_exist == false)
    {
        return;
    }


    // 定数バッファ用ヒープのセット
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_inform->m_constant_buffer_heap);

    // ルートシグネチャに定数バッファを紐付ける
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_constant_inform->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたインデックス番号のスロットに定数データをセットする
// 引数   ：unique_ptr<C_Constant_Buffer_Setting_Inform_Base> & 定数バッファデータ, int セット先のインデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & in_constant_buffer, int in_set_index_slot_num)
{
    // ☆ 変数宣言 ☆ //
    DX12::DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_buffer = reinterpret_cast<DX12::DX12INSTANCE::C_DX12_Constant_Setting_Inform * >(in_constant_buffer.get());    // 定数バッファ情報をDX12用へキャストした結果のアドレス


    // 定数バッファ用ヒープのセット
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_buffer->m_constant_buffer_heap);

    // ルートシグネチャに定数バッファを紐付ける
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_constant_buffer->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータをセットする
// 引数   ：S_Texture_Buffer_Drawing_Setting & セットするテクスチャデータ情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & in_texture_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture_inform = reinterpret_cast<DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform*>(in_texture_inform.add_texture_data); // 描画用情報をDX12用へキャストした結果のアドレス

    int slot_number = 0;    // テクスチャデータ設定先のスロット番号

    bool flg_slot_exist = false;    // スロットを発見できたかどうかのフラグ


    // 全シェーダー共通のテクスチャに書き込む
    if (*in_texture_inform.add_attach_shader_kind == ASSET::SHADER::E_SHADER_KIND::e_ALL)
    {
        // ☆ 変数宣言 ☆ //
        int texture_slot_sum = (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();   // テクスチャ数
        int slot_skipped = 0;   // 通過したスロット数


        // 定数バッファ用のスロットは飛ばす
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();


        // テクスチャのスロット数分繰り返す、文字列が一致したら発見できたので番号を指定してループを抜ける
        for (int l_slot_number = 0; l_slot_number < texture_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->all_shader_signature.texture_data[l_slot_number].signature_name == *in_texture_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }

    // 各シェーダーに用意されているテクスチャに書き込む
    else
    {
        // ☆ 変数宣言 ☆ //
        int texture_slot_sum = (int)mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].texture_data.size();   // テクスチャのスロット数
        int slot_skipped = 0;   // 通過したスロット数


        // 全てのシェーダーに共通するスロットは飛ばす
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();
        slot_skipped += (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();


        // 他のシェーダー用のスロットは飛ばす
        for (int now_shader_kind = 0; now_shader_kind < (int)*in_texture_inform.add_attach_shader_kind; now_shader_kind++)
        {
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[now_shader_kind].constant_data.size();
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[now_shader_kind].texture_data.size();
        }


        // 定数バッファ用のスロットは飛ばす
        slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].constant_data.size();


        // テクスチャのスロット数分繰り返す、文字列が一致したら発見できたので番号を指定してループを抜ける
        for (int l_slot_number = 0; l_slot_number < texture_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].texture_data[l_slot_number].signature_name == *in_texture_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }


    // スロットがみつからなかったら抜ける
    if (flg_slot_exist == false)
    {
        return;
    }


    // テクスチャの管理用の木構造をセットする
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture_inform->mpr_variable.texture_heap);

    // ルートシグネチャとテクスチャ用のデータを紐づける
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_texture_inform->mpr_variable.texture_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたインデックス番号のスロットにテクスチャのデータをセットする
// 引数   ：unique_ptr<C_Rendering_Texture_Setting_Inform_Base> & テクスチャデータ, int セット先のインデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture, int in_set_index_slot_num)
{
    // ☆ 変数宣言 ☆ //
    DX12::DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture = reinterpret_cast<DX12::DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * >(in_texture.get());    // テクスチャ情報をDX12用へキャストした結果のアドレス


    // テクスチャ用ヒープのセット
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture->mpr_variable.texture_heap);

    // ルートシグネチャにテクスチャを紐付ける
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_texture->mpr_variable.texture_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の描画を実行する
// 引数   ：const unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & セットする頂点データ情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_vertex_inform)
{
    // ☆ 変数宣言 ☆ //
    const DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_vertex_inform.get());   // 頂点用情報をDX12用へキャストした結果のアドレス


    // 頂点バッファをセットする
    mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);

    // インデックスバッファをセットする    
    mpr_variable->s_command.list->IASetIndexBuffer(&dx12_vertex_inform->m_index_buffer_view);

    // 描画を実行する（インデックスバッファ分）
    mpr_variable->s_command.list->DrawIndexedInstanced(dx12_vertex_inform->m_draw_index_sum, 1, 0, 0, 0);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の描画を実行する
// 引数   ：const unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & セットする頂点データ情報(const), int 描画するインデックスの描画の開始番号, int 描画するインデックスの終了番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_vertex_inform, int start_point, int end_point)
{
    // ☆ 変数宣言 ☆ //
    const DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_vertex_inform.get());   // 頂点用情報をDX12用へキャストした結果のアドレス


    // 頂点バッファをセットする
    mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);

    // インデックスバッファをセットする    
    mpr_variable->s_command.list->IASetIndexBuffer(&dx12_vertex_inform->m_index_buffer_view);

    // 描画を実行する（インデックスバッファ分）
    mpr_variable->s_command.list->DrawIndexedInstanced(end_point - start_point, 1, start_point, 0, 0);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面をフリップして描画する処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Rendering_End_And_Swap_Screen(void)
{
    // ☆ 変数宣言 ☆ //
    ID3D12CommandList * p_command_list = mpr_variable->s_command.list.Get();   // コマンドリストのアドレスを渡すために変数にする


    // ☆ 描画命令の記録終了 ☆ //

    // リソース同期用のバリアを出力用に変更 (変更が完了するまで待つ)
    M_Set_Resource_Barrier(D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);


    // コマンドリストへの記録終了(これを先に行わないと実行させることが出来ない)
    mpr_variable->s_command.list->Close();


    // コマンド実行
    mpr_variable->s_command.queue->ExecuteCommandLists(1, &p_command_list);

    // ☆ 画面出力 ☆ //
    mpr_variable->s_frame_work.swap_chain->Present(1, 0);


#if 1   // デバイスが削除されたらこれをオンにして理由を取得すること
    HRESULT bugresult = mpr_variable->s_frame_work.device->GetDeviceRemovedReason();
#endif


    // 描画完了待ち
    M_Wait_For_Command_Queue();


    // デバッグ時のみ行う更新
#if _DEBUG
    M_Debug_Update();
#endif // _DEBUG

    return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報を元に頂点データを生成する
// 引数   ：unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & セット先の頂点データ, const C_Create_Vertex_Buffer_Inform & 頂点データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_set_to, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = new DX12INSTANCE::C_DX12_Vertex_Setting_Inform();   // DX12用の頂点用情報


    // データをセット
    in_set_to.reset(dx12_vertex_inform);


    // 頂点バッファを生成
    M_Create_Vertex_Buffer(dx12_vertex_inform, in_create_inform);

    // インデックスバッファの生成
    M_Create_Index_Buffer(dx12_vertex_inform, in_create_inform);

    // 描画回数をインデックスバッファ分セット
    dx12_vertex_inform->m_draw_index_sum = in_create_inform.index_sum;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報を元に定数データを生成する
// 引数   ：unique_ptr<C_Constant_Buffer_Setting_Inform_Base> & セット先の定数データ, const C_Create_Constant_Buffer_Inform & 定数データ生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & in_constant_inform, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_inform = new DX12INSTANCE::C_DX12_Constant_Setting_Inform();   // DX12用の定数用情報


    // ☆ 定数データ用のヒープを生成 ☆ //
    M_Create_Constant_Heap(dx12_constant_inform, in_create_inform);

    // ☆ 定数データを生成 ☆ //
    M_Create_Constant_Resource(dx12_constant_inform, in_create_inform);


    // データをセット
    in_constant_inform.reset(dx12_constant_inform);

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ用の情報を生成する
// 引数   ：unique_ptr<C_Rendering_Texture_Setting_Inform_Base> & 設定先のパイプライン情報, const C_Create_Texture_Setting_Inform & 生成用の情報(const)
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture_inform, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture_inform = new DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform(); // DX12用の描画用情報


    // ☆ テクスチャ用データの生成 ☆ //　// 失敗したらエラーで抜ける
    if (M_Create_Texture_Resource(dx12_texture_inform, in_create_inform) == false)
    {
        // デバッグ時は失敗ログを出力
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "テクスチャヒープの生成に失敗");
#endif // _DEBUG

        return false;
    }


    // ☆ ヒープを生成 ☆ //
    M_Create_Texture_Resource_View_And_Heap(dx12_texture_inform, in_create_inform);


    // データをセット
    in_texture_inform.reset(dx12_texture_inform);


    // デバッグ時は成功ログを出力
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "テクスチャ用データの生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画パイプライン用の情報を生成する
// 引数   ：std::unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & 設定先のパイプライン情報, const C_Create_Rendering_Graphics_Setting_Inform & 生成用の情報(const)
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>& in_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform& in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = new DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform(); // DX12用の描画用情報


    // ☆ ルートシグネチャ設定 ☆ //　失敗したらエラーで抜ける
    if (M_Create_Root_Signature(dx12_pipeline_inform, in_create_inform) == false)
    {
        return false;
    }


    // ☆ パイプラインステート ☆ //　失敗したらエラーで抜ける
    if (M_Create_Pipeline_State(dx12_pipeline_inform, in_create_inform) == false)
    {
        return false;
    }

    // データをセット
    in_pipeline_inform.reset(dx12_pipeline_inform);


    // デバッグ時は成功ログを出力
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "レンダリング設定の生成に成功");
#endif // _DEBUG

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フォントをフォント名を元にロードする
// 引数   ：unique_ptr<C_Rendering_Font_Inform_Base> & 設定先のフォント情報パラメータ, const C_Create_Font_Data_Inform & 生成用の情報(const)
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> & in_font_data, const CREATE::C_Create_Font_Data_Inform & in_create_inform)
{
    // ☆ 変数宣言 ☆ //
    HFONT handle_font = NULL;   // フォントのハンドル

    LOGFONT log_font_data =  // フォント設定用のデータ
    {
        //-☆- サイズや形状の設定 -☆-// 
        in_create_inform.m_height,   // フォントのセルや文字の高さ
        0,                          // フォントの文字の幅
        0,                          // 文字を傾ける方向
        0,                          // 基本線と比べたときのｘ軸での角度
        0,                          // フォントの太さの設定（０でデフォルト）

        //-☆- 書体の設定 -☆-//
        FALSE,              // 斜体フォントかどうかのフラグ
        FALSE,              // 下線付きフォントかどうかのフラグ
        FALSE,              // 取り消し線付きフォントかどうかのフラグ
        SHIFTJIS_CHARSET,   // 文字セットの種類

        //-☆- 精度の設定 -☆-//
        OUT_TT_ONLY_PRECIS,         // フォントの精度（今までの設定にどれだけ忠実な結果になるか）
        CLIP_DEFAULT_PRECIS,        // クリッピングの精度
        PROOF_QUALITY,              // 出力時の品質
        DEFAULT_PITCH | FF_MODERN,  // フォントのピッチとファミリ(フォントのデザイン方法の定義)

        // フォント名
        (WCHAR)in_create_inform.m_font_name.data()
    };

    // フォントのハンドルを読み込む
    handle_font = CreateFontIndirectW(&log_font_data);
    

    // フォントハンドルの取得に失敗したらエラーを示して抜ける
    if (handle_font == NULL)
    {
#ifdef _DEBUG

        DEBUGGER::LOG::C_Log_System::M_Set_Console_Text_Color(DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, "フォントハンドルの生成に失敗", "DX12_FONT_SYSTEM");

#endif // _DEBUG

        return false;
    }


    // テストは完了したので現状で必要のないデータは削除
    DeleteObject(handle_font);
    handle_font = NULL;


    //-☆- 成功していたら登録 -☆-//

    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Font_Data_Set * new_font_data_handler = new DX12INSTANCE::C_DX12_Font_Data_Set();   // 新しいフォントデータ用の設定


    // フォント名
    new_font_data_handler->m_log_font = log_font_data;


    //--☆ 登録 ☆--//
    in_font_data.reset(new_font_data_handler);

    return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡された情報を元に文字をマップにセットする
// 引数   ：S_Make_Font_To_Graph_Package & フォントから画像を作るためのパッケージ情報
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & in_set_inform)
{
    // ☆ 定数 ☆ //
    const MAT2 texture_uv_setting_mat = { {0,1},{0,0},{0,0},{0,1} };   // テクスチャ座標指定用の二次元配列コード


    // ☆ 変数宣言 ☆ //
    DX12INSTANCE::C_DX12_Font_Data_Set * dx12_font_data = reinterpret_cast<DX12INSTANCE::C_DX12_Font_Data_Set * >(in_set_inform.attach_font_data->get());   // ＤＸ１２用フォントデータへの変換

    HFONT handle_font = NULL;   // フォントのハンドル


    // フォントのハンドルを読み込む
    handle_font = CreateFontIndirectW(&dx12_font_data->m_log_font);


    // フォントハンドルの取得に失敗したらエラーを示して抜ける
    if (handle_font == NULL)
    {
#ifdef _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Text_Color(DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, "DX12_FONT_SYSTEM", "フォントの生成に失敗、もしくはフォント情報が設定されていないため、このフォント情報を使用する事はできませんでした");

#endif // _DEBUG

        return false;
    }


    // ☆ 変数宣言 ☆ //
    HDC handle_device_context = GetDC(NULL);   // ウィンドウのデバイスコンテキスト

    TEXTMETRIC txt_met;  // テキストの設定

    HFONT old_font_handle = NULL;  // このフォントデータを適用する前に設定されていたハンドル

    int FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;  // ビットマップの諧調指定用のフラグ

    int num_grad = 0;   // 階調の最大値


    // フォントの取得
    old_font_handle = (HFONT)SelectObject(handle_device_context, handle_font);


    // ☆ ビットマップの諧調のレベルを指定 ☆ //
    switch (in_set_inform.bit_map_level)
    {
        // 0~4
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_4:
        FLG_GRAY_SETTING = GGO_GRAY2_BITMAP;
        num_grad = 4;
        break;

        // 0~16
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_16:
        FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;
        num_grad = 16;
        break;

        // 0~64
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_64:
        FLG_GRAY_SETTING = GGO_GRAY8_BITMAP;
        num_grad = 64;
        break;
    }   // * 0～num_gradに指定した値の間で色の情報を取得できる
    
    // テキスト設定をウィンドウのコンテキストから取得
    GetTextMetrics(handle_device_context, &txt_met);

    
    // ☆ 変数宣言 ☆ //
    GLYPHMETRICS glyph_met;    // フォント用の設定
    
    DWORD font_map_size = 0; // ビットマップのサイズ
    
    // ビットマップサイズを取得
    font_map_size = GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, 0, NULL, &texture_uv_setting_mat);

    std::vector<DWORD> font_texture_data;    // フォントから取得した画像情報


    // マップの取得
    font_texture_data.resize(font_map_size);
    GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, font_map_size, &font_texture_data[0], &texture_uv_setting_mat);
    

    // ☆ 変数宣言 ☆ //
    DATA::COLOR::C_Color set_color(1.0f, 1.0f, 1.0f, 0.0f); // 設定する色
    
    int font_map_start_x = glyph_met.gmptGlyphOrigin.x; // ｘ方向でのフォントの開始ビット番号
    int font_map_start_y = txt_met.tmAscent - glyph_met.gmptGlyphOrigin.y;  // ｙ方向でのフォントの開始ビット番号

    int font_size_x = (glyph_met.gmBlackBoxX + (4 - (glyph_met.gmBlackBoxX % 4)) % 4);    // ｘ方向でのフォントのビット数（４で割ってるのは四つ横に並べて渡されるため）
    int font_size_y = glyph_met.gmBlackBoxY;    // ｙ方向でのフォントのビット数

    int map_x_size = in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x + 1; // 横方向でのマップに書き込む大きさ
    int map_y_size = in_set_inform.draw_rect.top_y - in_set_inform.draw_rect.bottom_y + 1; // 縦方向でのマップに書き込む大きさ


    int map_write_start_x = (int)(((float)font_map_start_x / ((float)font_size_x + (float)font_map_start_x)) * (float)map_x_size); // マップに書き込むときのｘでの開始座標
    int map_write_start_y = (int)(((float)font_map_start_y / ((float)font_size_y + (float)font_map_start_y)) * (float)map_y_size); // マップに書き込むときのｙでの開始座標


    // 送られてくる画像をマップに合わせるための調整
    font_size_x /= 4;
    map_x_size -= map_write_start_x;
    map_y_size -= map_write_start_y;


    float font_size_x_by_map_x_size = (float)font_size_x / (float)map_x_size;   // ｘでのフォントマップに適用するための倍率
    float font_size_y_by_map_y_size = (float)font_size_y / (float)map_y_size;   // ｙでのフォントマップに適用するための倍率


    // テクスチャ用のマップを確保する
    in_set_inform.tex_map_data->M_Map_Variable_Size_Change(in_set_inform.draw_rect.right_x, in_set_inform.draw_rect.top_y);


    // 修正が必要な文字は修正を加える（記号など）
    switch (in_set_inform.text_code)
    {
        // ハイフンは下に並べられるので上にあげる、サイズも訂正する
    case L'-':
        map_write_start_y /= 2;
        map_x_size /= 2;
        map_write_start_x = (in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x) / 3;
        break;

        // 伸ばし棒は下に並べられるので上にあげる
    case L'ー':
        map_write_start_y /= 2;
        break;
    }


    // 縦のピクセル分のループ
    for (int l_y_now_pix = 0; l_y_now_pix < map_y_size; l_y_now_pix++)
    {
        // ☆ 変数宣言 ☆ //
        int now_data_y_element = (int)(l_y_now_pix * font_size_y_by_map_y_size);  // 現在取り出すデータのｙ座標分の要素数
        
        now_data_y_element =
            (now_data_y_element >= (font_size_y - 1)) * (font_size_y - 1)
            +
            (now_data_y_element < (font_size_y - 1)) * now_data_y_element;

        now_data_y_element *= font_size_x;

        
        // 横のピクセル分のループ
        for (int l_x_now_pix = 0; l_x_now_pix < map_x_size; l_x_now_pix++)
        {
            // ☆ 変数宣言 ☆ //
            int now_data_element = (int)(l_x_now_pix * font_size_x_by_map_x_size);  // 現在取り出すデータの要素番号

            now_data_element =
                (now_data_element >= (font_size_x - 1)) * (font_size_x - 1)
                +
                (now_data_element < (font_size_x - 1)) * now_data_element;

            now_data_element += now_data_y_element;

            WORD now_color_data = (WORD)((font_texture_data[now_data_element] * 255) / num_grad);    // 取り出したカラーデータ


            // 色の濃さが渡されるだけなので透明度のみ設定する
            set_color.a = (float)(now_color_data & 0x000000ff) / 255;
            in_set_inform.tex_map_data->M_Set_Color_At_Point(set_color, l_x_now_pix + in_set_inform.draw_rect.left_x + map_write_start_x, l_y_now_pix + in_set_inform.draw_rect.bottom_y + map_write_start_y);
        }
    }


    // 使用済みのマップデータを解放
    font_texture_data.clear();
    font_texture_data.shrink_to_fit();


    // 元々設定されていたフォントに戻す
    SelectObject(handle_device_context, old_font_handle);

    // 権限の解放
    DeleteObject(handle_font);
    ReleaseDC(NULL, handle_device_context);

    return true;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色データをセットする
// 引数   ：const C_Color & セットする色データ(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_System::M_Set_Clear_Color(const DATA::COLOR::C_Color & in_set_color)
{
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = in_set_color.r;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = in_set_color.g;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = in_set_color.b;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = in_set_color.a;

    return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャをロードする
// 引数   ：string ファイルのパス, C_Texture_Map & テクスチャマップの参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_System::M_Load_Texture(std::string in_file_path, ASSET::TEXTURE::C_Texture_Map & in_tex_map)
{
    // ☆ 変数宣言 ☆ //
    DirectX::TexMetadata file_metadata = {};     // テクスチャのメタデータを取得する

    DirectX::ScratchImage scratch_img = {};  // 画像ファイルの読み取り結果

    std::vector<wchar_t> w_file_path;  // ファイルパスをwcharに変換した結果

    int file_path_size = (int)in_file_path.size();   // ファイルパス文字数


    // ワイドキャラに変換する
    w_file_path.resize(file_path_size + 1);
    for (int loop_x = 0; loop_x < file_path_size; loop_x++)
    {
        w_file_path[loop_x] = (wchar_t)in_file_path[loop_x];
    }
    w_file_path[file_path_size] = '\0';


    // ファイルの読み込み    // 失敗したらエラーで抜ける
    if (FAILED(DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img)))
    {
        HRESULT result_error = DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img);

        w_file_path.clear();
        w_file_path.shrink_to_fit();
        return false;
    }
    w_file_path.clear();
    w_file_path.shrink_to_fit();


    // ☆ 変数宣言 ☆ //
    const DirectX::Image * add_image = scratch_img.GetImage(0, 0, 0);   // 画像データのアドレス
    

    // メモリの確保
    in_tex_map.M_Delete_Map();
    in_tex_map.M_Map_Variable_Size_Change((int)add_image->width, (int)add_image->height);


    // ピクセルデータのセット
    for (int l_tex_y = 0; l_tex_y < (int)add_image->height; l_tex_y++)
    {
        // ☆ 変数宣言 ☆ //
        int row_plus = l_tex_y * (int)add_image->width;	// 設定位置の縦列分でずらす量
        int image_plus = row_plus * 4;	// イメージ座標の設定位置の縦列分でずらす量


        for (int l_tex_x = 0; l_tex_x < (int)add_image->width; l_tex_x++)
        {
            // ☆ 変数宣言 ☆ //
            DATA::COLOR::C_Color set_color; // 設定する色


            set_color.r = add_image->pixels[image_plus + l_tex_x * 4 + 0];
            set_color.g = add_image->pixels[image_plus + l_tex_x * 4 + 1];
            set_color.b = add_image->pixels[image_plus + l_tex_x * 4 + 2];
            set_color.a = add_image->pixels[image_plus + l_tex_x * 4 + 3];
            in_tex_map.M_Set_Color_At_Point(set_color, l_tex_x, l_tex_y);
        }
    }

    // 成功
    return true;
}


#endif // OS_IS_WINDOWS


