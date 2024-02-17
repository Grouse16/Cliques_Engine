//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の機能を使うためのクラス
// 説明   ：DX12設定や描画処理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_SYSTEM_H
#define D_INCLUDE_GUARD_C_DX12_SYSTEM_H


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <Windows.h>
#include <d3d12.h>
#include <d3d12shader.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <wrl/client.h>

#include "C_DX12_Vertex_Setting_Inform.h"
#include "C_DX12_Index_Setting_Inform.h"
#include "C_DX12_Constant_Setting_Inform.h"
#include "C_DX12_Rendering_Texture_Setting_Inform.h"
#include "C_DX12_Rendering_Graphics_Setting_Inform.h"
#include "C_Rendering_API_Base.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "E_DX12_PARAMATOR.h"
#include "C_DX12_Rendering_Screen_System.h"
#include "C_DX12_Depth_Stencil_Buffer_System.h"


// ☆ ネームスペース ☆ //

// DX12システムを呼び出すための名前
namespace RENDERING::API::DX12
{
	// ☆ クラス ☆ //

	// DX12の機能用のクラス
	class C_DX12_System : private RENDERING::API::BASE::C_Rendering_API_Base
	{
		//==☆  プライベート  ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// 変数をしまうための構造体
		struct SPr_Variable
		{
			// フレームワーク用の構造体
			struct S_Frame_Work
			{
				Microsoft::WRL::ComPtr<ID3D12Device> device;	// デバイス（仮想アダプター）

				Microsoft::WRL::ComPtr<IDXGISwapChain3> swap_chain;	// 画面スワップ（画面バッファ切り替え用システム）

				Microsoft::WRL::ComPtr<IDXGIFactory3> factory;	// ファクトリ（全画面表示の切り替え用システム）

				D3D12_VIEWPORT view_port = D3D12_VIEWPORT();	// ビューポートパラメータ

				D3D12_RECT scissor_rect = D3D12_RECT();	// シザーレクト

				float clear_color[(int)E_DX12_PARAMATOR::e_COLOR_SUM] = { 0.0f,0.0f,0.0f,0.0f };  // 画面塗りつぶし色

			} s_frame_work;	// フレームワーク用パラメータ(デバイスや画面切り替え、構成の設定など)


			// 描画コマンド用の構造体
			struct S_Command
			{
				Microsoft::WRL::ComPtr<ID3D12CommandQueue> queue;	// 描画実行システム

				Microsoft::WRL::ComPtr<ID3D12CommandAllocator> allocator;	// 描画命令制御用システム（GPU処理命令のストレージ割り当てシステム）

				Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> list;	// 描画命令のリスト

				int fence_value[(int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM];  // フェンスのフレームインクリメントを判定するための値

				int num_front_screen = 0;	// 前側（表示中）の画面の番号
				int num_back_screen = 0;	// 後側（描画書き込み中）の画面の番号

			} s_command;	// 描画コマンド用パラメータ


			// レンダー用の構造体
			struct S_Render
			{
				HANDLE fence_event = nullptr;	// フェンスイベント（描画同期時のイベント）

				Microsoft::WRL::ComPtr<ID3D12Fence>  queue_fence;	// フェンス（描画同期用システム）

				std::unique_ptr<RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System> main_rendering_screen = nullptr;	// レンダリング画面の情報

				RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_Buffer * now_screen_address_handle = nullptr;	// 今のスクリーンシステムへのアドレス
				RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Depth_Stencil_Buffer * now_depth_stencil_address_handle = nullptr;	// 今の深度ステンシルバッファへのアドレス

				int now_rendering_screen_sum = 1;	// 今のレンダリング画面の総数

			} s_render;	// レンダー用パラメータ

			std::unique_ptr<const ASSET::SHADER::S_Resource_Inform_List> shader_resource_list = nullptr;	// 現在適用されているシェーダーのリソース識別名のリスト

			bool flg_rendering_api_end = true;	// レンダリングAPIが終了しているときのみtrueとなるフラグ
		};

		std::unique_ptr<SPr_Variable> mpr_variable;	// このクラスの変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化するためにここで定義、静的変数でこのクラスにアクセスできる
		C_DX12_System(void);

		// デバイスや描画コマンド、レンダリング先の設定　戻り値：成功時のみtrue
		bool M_DirectX12_Init(void);


		//-☆- ファクトリ＆デバイス -☆-//

		// ファクトリを生成する(全画面表示遷移用システム)　戻り値：成功時のみtrue
		bool M_Create_Factory(void);

		// デバイスを生成する(仮想アダプター)　戻り値：成功時のみtrue
		bool M_Create_Device(void);

		
		//-☆- コマンド -☆-//
		
		// コマンドアロケーターを生成する（GPUコマンドのストレージ割り当てシステム）　戻り値：成功時のみtrue
		bool M_Create_Command_Allocator(void);

		// コマンドリストを生成する（描画命令のリストのカプセル）　戻り値：成功時のみtrue
		bool M_Create_Command_List(void);

		// コマンドキューを生成する（描画実行システム）　戻り値：成功時のみtrue
		bool M_Create_Command_Queue(void);


		//-☆- フェンス＆スワップチェイン -☆-//

		// フェンスを生成する（描画同期用システム）　戻り値：成功時のみtrue
		bool M_Create_Fence(void);

		// スワップチェインを生成する（画面バッファ切り替え用システム）　戻り値：成功時のみtrue
		bool M_Create_Swap_Chain(void);


		//-☆- レンダリング -☆-//

		// レンダーターゲットビューを生成する（レンダリング先の画面バッファ切り替え用システム）　引数：DX12用の設定先のレンダリング画面の参照, レンダリング画面を生成するための情報の参照（const）　戻り値：成功時のみtrue
		bool M_Create_Render_Target_View_Descriptor_Heap(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System * & , const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & ) const;

		// 画面の番号によってレンダリング画面をセットする　引数：レンダリング画像の番号, レンダーターゲットビュー情報の参照
		void M_Set_Render_Target_View_By_Screen_Number(int, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View & );

		// レンダリング画面をセットする　引数：レンダーターゲットビュー情報の参照
		void M_Set_Render_Target_View(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System * & );

		// レンダリング画面をクリアする　引数：レンダリング画像の番号, レンダーターゲットビュー情報の参照
		void M_Clear_Render_Target_View(int, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View & ) const;


		//-☆- 深度ステンシルビュー -☆-//

		// 深度ステンシルビューを生成する（深度ステンシル適用先の画面バッファの切り替え用システム）　引数：DX12用の深度ステンシルバッファのアドレスの参照,深度ステンシルバッファを生成するための情報の参照（const）　戻り値：成功時のみtrue
		bool M_Create_Depth_Stencil_View_Descriptor_Heap(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * &, const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) const;

		// 深度ステンシルバッファをセットする　引数：DX12用深度ステンシルバッファ情報の参照
		void M_Set_Depth_Stencil_View(RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Depth_Stencil_Buffer & );

		// 深度ステンシルバッファをクリアする　引数：DX12用深度ステンシルバッファ情報の参照
		void M_Clear_Depth_Stencil_View_Buffer(RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Depth_Stencil_Buffer & ) const;


		//-☆- 頂点バッファ -☆-//

		// 頂点バッファを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Vertex_Buffer(DX12_INSTANCE::C_DX12_Vertex_Setting_Inform * &, const CREATE::S_Create_Vertex_Buffer_Inform & ) const;


		//-☆- 頂点インデックス -☆-//

		// インデックスバッファを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Index_Buffer(DX12_INSTANCE::C_DX12_Index_Setting_Inform * &, const CREATE::S_Create_Index_Buffer_Inform & ) const;


		//-☆- 定数バッファ -☆-//

		// 定数バッファのヒープを生成する　引数：設定先の定数の情報, 生成用の情報(const)
		void M_Create_Constant_Heap(DX12_INSTANCE::C_DX12_Constant_Setting_Inform * &, const CREATE::S_Create_Constant_Buffer_Inform & ) const;

		// 定数バッファのデータを生成する　引数：設定先の定数の情報, 生成用の情報(const)
		void M_Create_Constant_Resource(DX12_INSTANCE::C_DX12_Constant_Setting_Inform * &, const CREATE::S_Create_Constant_Buffer_Inform & ) const;


		//-☆- テクスチャ -☆-//

		// テクスチャ用のビューとヒープを生成する　引数：設定先のテクスチャの情報,  生成用の情報(const)
		void M_Create_Texture_Resource_View_And_Heap(DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * &, const CREATE::S_Create_Texture_Setting_Inform & ) const;

		// テクスチャ用のデータを生成する　引数：設定先のテクスチャの情報,  生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Texture_Resource(DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * &, const CREATE::S_Create_Texture_Setting_Inform & ) const;


		//-☆- ルートシグネチャ -☆-//

		// ルートシグネチャデスクからルートシグネチャをシリアライズし生成する,　引数：ルートシグネチャを設定するための情報の参照(const), ルートシグネチャの設定先　戻り値：成功時のみtrue
		bool M_Serialize_And_Create_RootSignature_By_Desc(const D3D12_ROOT_SIGNATURE_DESC &, Microsoft::WRL::ComPtr<ID3D12RootSignature> & ) const;

		// ルートシグネチャを生成する　引数：設定先の描画パイプライン用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Root_Signature(DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &, const CREATE::S_Create_Rendering_Graphics_Setting_Inform & ) const;


		//-☆- パイプラインステート -☆-//

		// パイプラインステートを生成する　引数：設定先の描画パイプライン用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Pipeline_State(DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &, const CREATE::S_Create_Rendering_Graphics_Setting_Inform & ) const;

		// シェーダー毎にリソースを定義する（ディスクリプタとレンジ、サンプラーを生成する）　引数：シェーダーのリソース識別情報の参照, ディスクリプタ設定用情報の参照, レンジの設定用情報の参照, サンプラー設定用情報の参照
		void M_Create_Descriptor_And_Sampler_By_Shaders_Inform(const ASSET::SHADER::S_Resource_Inform_List &, std::vector<D3D12_ROOT_PARAMETER> &, std::vector<D3D12_DESCRIPTOR_RANGE> &, std::vector<D3D12_STATIC_SAMPLER_DESC> &) const;


		//-☆- 描画 -☆-//

		// リソース同期用バリアのセット　引数：設定先のレンダリング画面の番号, レンダーターゲットビュー情報, 設定するリソース使用方法
		void M_Set_Resource_Barrier(int, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View &, D3D12_RESOURCE_STATES) const;

		// コマンド実行待ち
		void M_Wait_For_Command_Queue(void);

		// ビューポートとシザーの設定を行う
		void M_Set_Scissor_And_View_Port(void);

		// 描画コマンド情報をリセットする
		void M_Reset_Command(void);


		//-☆- 識別用情報 -☆-//

		// 指定されたパイプライン情報を元にシェーダーのリソース識別名をセットする　引数：設定する識別用情報の参照(const)
		void M_Set_Shader_Resource_Signature_By_Rendering_Setting(const DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * &);


		//-☆- 種別 -☆-//

		// 指定された機能レベルを文字列に変換する　引数：機能レベル指定用列挙　戻り値：変換後の文字列
		std::string M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(D3D_FEATURE_LEVEL);


		//-☆- デバッグ -☆-//
#if _DEBUG
		// デバッグ時の更新
		void M_Debug_Update(void) const;
#endif // _DEBUG


		//==☆  パブリック  ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆-  初期化と終了時  -☆-//

		// レンダリングAPIの初期化
		bool M_Set_Up(void) override;

		// DX12を生成する処理
		static void M_Create_DirectX12(void);

		// メモリ解放
		void M_Release(void) override;

		// デストラクタ
		~C_DX12_System(void) override;


		//-☆- レンダリング -☆-//

		// レンダリングの開始の処理
		void M_Rendering_Start(void) override;

		// レンダリングの終了と描画バッファ切り替えの処理
		void M_Rendering_End_And_Swap_Screen(void) override;


		//-☆- レンダリング設定 -☆-//

		// レンダリング設定の生成　引数：設定先のパイプライン情報, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & , const CREATE::S_Create_Rendering_Graphics_Setting_Inform & ) const override;

		// レンダリング設定のセット　引数：レンダリングパイプライン用情報(const)
		void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & ) override;


		//-☆- レンダリング画面 -☆-//

		// レンダリング画面の生成　引数：設定先のレンダリング画面の参照, レンダリング画面を生成するための情報の参照（const）　戻り値：成功時のみtrue
		bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> &, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & ) const override;

		// レンダリング画面のクリア　引数：クリアするレンダリング画面番号, クリアするレンダリング画面システムの参照
		void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) const override;

		// レンダリング画面を描画先としてセット　引数：設定先のレンダリング画面の参照
		void M_Set_Rendering_Screen_To_Render_Target(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) override;
		
		// レンダリング画面を指定されたテクスチャのスロットにセット　引数：レンダリング画面番号, 設定先のテクスチャのスロット番号, レンダリング画面システムの参照
		void M_Set_Rendering_Screen_To_Texture_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) override;

		// レンダリング画面のデータ（画素配列）を取得可能な状態にする　引数：設定するレンダリング画面番号, レンダリング画面システムの参照
		void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) override;

		// メインのレンダリング画面に戻す
		void M_Set_Main_Rendering_Screen_To_Rendering(void) override;
		
		// メインの表示中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int) override;

		// メインの描画書き込み中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int) override;

		// メインのレンダリング画面のデータをテクスチャに移す　引数：設定先のテクスチャの参照
		void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & ) const override;

		// 指定されたレンダリング画面のデータをテクスチャに移す　引数：設定するレンダリング画面番号, レンダリング画面システムの参照, 設定先のテクスチャの参照
		void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base>&, ASSET::TEXTURE::C_Texture_Map&) const override;

		// レンダリング画面の削除を通知する　引数：削除されたレンダリング画面のアドレス（const）
		void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base*) override;


		//-☆- 深度ステンシルバッファ -☆-//

		// 深度ステンシルバッファを生成する　引数：生成先の深度ステンシルバッファの参照, 深度ステンシルバッファを生成するための情報の参照（const）　戻り値：成功時のみtrue
		bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) const override;

		// 深度ステンシルバッファをクリアする　引数：クリアする深度ステンシルバッファの参照
		void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base>&) const override;

		// 深度ステンシルバッファを描画先にセット　引数：設定する深度ステンシルバッファの参照
		void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) override;

		// 深度ステンシルバッファをGPU用リソースのテクスチャスロットにセット　引数：設定先のスロット番号, 設定する深度ステンシルバッファの参照
		void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) override;

		// 深度ステンシルバッファの削除を通知する　引数：削除された深度ステンシルバッファのアドレス（const）
		void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * ) override;

		// 深度ステンシルバッファをリセットする
		void M_Reset_Depth_Stencil_Buffer(void) override;


		//-☆- 頂点バッファ -☆-//

		// 指定された情報を元に頂点データを生成する　引数：設定先の頂点情報, 生成用の情報(const)
		void M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> &, const CREATE::S_Create_Vertex_Buffer_Inform & ) const override;

		// 頂点バッファをセットする　引数：セットする頂点データ(const)
		void M_Set_Vertex_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) override;

		// 頂点バッファを元に描画を実行する　引数：描画する頂点データ(const)
		void M_Draw_Command_By_Vertex_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) override;


		//-☆- 頂点インデックス -☆-//

		// 指定された情報を元にインデックスデータを生成する　引数：設定先のインデックス情報, 生成用の情報(const)
		void M_Create_Index_Inform(std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> &, const CREATE::S_Create_Index_Buffer_Inform & ) const override;

		// インデックスバッファを元に描画を行う　引数：インデックスデータ設定用情報(const)
		void M_Draw_Command_By_Index_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & ) override;

		// インデックスバッファを元に指定されたインデックス間の描画を行う　引数：インデックスデータ設定用情報(const), 描画を開始するインデックス番号, 描画終了のインデックス番号
		void M_Draw_Command_By_Index_Buffer_By_Range(const std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int) override;


		//-☆- 定数バッファ -☆-//

		// 定数データ用の情報を生成する　引数：設定先の定数情報, 生成用の情報(const)
		void M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> &, const CREATE::S_Create_Constant_Buffer_Inform & ) const override;

		// 定数データをセットする　引数：定数データ設定用情報
		void M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & ) override;

		// 指定されたインデックス番号のスロットに定数データをセットする　引数：定数バッファデータ, セット先のインデックス番号
		void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int) override;


		//-☆- テクスチャ -☆-//

		// テクスチャ用の情報を生成する　引数：設定先のテクスチャ情報, 生成用の情報(const)
		bool M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const CREATE::S_Create_Texture_Setting_Inform & ) const override;

		// テクスチャのデータをセットする　引数：セットするテクスチャデータ情報
		void M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & ) override;

		// 指定されたインデックス番号のスロットにテクスチャのデータをセットする　引数：テクスチャデータ, セット先のインデックス番号
		void M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) override;


		//-☆- フォント -☆-//

		// フォントを指定されたフォント名を元にロードする　引数：設定先のフォント情報パラメータ, 生成用の情報(const)　戻り値：成功時のみtrue
		bool M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> &, const CREATE::S_Create_Font_Data_Inform & ) const override;

		// 渡された情報を元に文字列をマップにセットする　引数：フォントから画像を作るためのパッケージ情報　戻り値：成功時のみtrue
		bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) const override;


		//-☆- ゲッタ -☆-//

		// DX12のレンダリングシステムのシェーダーのフォルダまでのパスを返す　戻り値：シェーダーのフォルダまでのパス
		std::string M_Get_Shader_Folder_Path(void) const override;

		// DX12のレンダリングシステムのシェーダーの拡張子を返す　戻り値：DX12でのシェーダーの拡張子
		std::string M_Get_Shader_Extension(void) const override;

		// レンダリングシステムが終了しているかどうかのフラグを返す　戻り値：レンダリングシステムが終了しているかどうかのフラグ
		bool M_Get_End_Rendering_System(void) const override;


		//-☆- セッタ -☆-//

		// 画面をクリアする色を設定する　引数：設定する色(const)
		void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) override;


		//-☆- ロード -☆-//

		// テクスチャをロードする　引数：テクスチャファイルのパス, テクスチャマップの参照
		bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) const override;
	};
}


#endif // OS_IS_WINDOWS
#endif // !DX12_SYSTEM


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

