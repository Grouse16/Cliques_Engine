//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルのクラス、描画時の描画方法の設定を行う
// 説明   ：バッファの管理やレンダリング設定の管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <vector>
#include <memory>

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_User.h"
#include "C_Constant_Data_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Rendering_Screen_System_Base.h"
#include "C_Shader_Setting_User.h"
#include "C_Rendering_Screen_System.h"
#include "S_Material_Detail.h"
#include "S_World_View_Projection.h"
#include "C_Depth_Stencil_Buffer_System.h"


// ☆ ネームスペース ☆ //

// マテリアルを呼び出すための名前
namespace ASSET::MATERIAL
{
	// ☆ 構造体 ☆ //

	// 定数バッファを使用する際の情報をまとめた構造体
	struct S_Constant_Buffer_Data
	{
		std::unique_ptr<RENDERING::CAPSULE::C_Constant_Buffer_Data_System> data;	// 定数バッファを管理するシステム

		std::string signature_name = "default";	// 定数バッファ識別名

		int slot_index = 0;	// 定数バッファのインデックス番号
	};


	// テクスチャバッファを使用する際の情報をまとめた構造体
	struct S_Texture_Buffer_Data
	{
		std::unique_ptr<ASSET::TEXTURE::C_Texture_Data_User> data;	// テクスチャを使用するためのシステム

		std::string signature_name = "default";	// テクスチャスロット識別名

		int slot_index = 0;	// テクスチャのインデックス番号
	};


	// レンダリング画面を使用する際の情報をまとめた構造体
	struct S_Rendering_Screen_Data
	{
		RENDERING::CAPSULE::C_Rendering_Screen_System * data = nullptr;	// レンダリング画面を管理するシステムのアドレス

		std::string signature_name = "default";	// レンダリング画面の識別名

		int use_screen_index = 0;	// テクスチャとして使用するレンダリング画面番号

		int slot_index = 0;	// レンダリング画面用のテクスチャスロットの番号
	};


	// 深度ステンシルバッファを使用する際の情報をまとめた構造体
	struct S_Depth_Stencil_Data
	{
		RENDERING::CAPSULE::C_Depth_Stencil_Buffer_System * data = nullptr;	// 深度ステンシルバッファを管理するシステムのアドレス

		std::string signature_name = "default";	// 深度ステンシルバッファの識別名

		int slot_index = 0;	// 深度ステンシルバッファ用のテクスチャスロットの番号
	};


	// ☆ クラス ☆ //
	
	// マテリアルのクラス、描画時の描画方法の設定を行う
	class C_Material
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Constant_Buffer_Data> constant_data_list;	// 使用する定数バッファのリスト
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// 使用するテクスチャのリスト

			std::vector<S_Rendering_Screen_Data> rendering_screen_list;	// 使用するレンダリングスクリーンのリスト

			std::vector<S_Depth_Stencil_Data> depth_stencil_list;	// 使用する深度ステンシルのリスト

			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// 描画用設定

			ASSET::SHADER::C_Shader_Setting_User shader_setting_data;	// シェーダー設定用情報

			ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot * unique_slot_list = nullptr;	// 特殊スロットのリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		
		// ☆ 関数 ☆ //

		//-☆- ブレンド設定 -☆-//

		// どのブレンドモードを設定するかを指定された文字列から特定して返す　引数：ブレンドモードを示す文字列　戻り値：特定したブレンドモード
		RENDERING::INFORM::BLEND::E_BLEND_MODE M_Get_Blend_Mode_By_Text(std::string);

		// どの色の操作を設定するかを指定された文字列から特定して返す　引数：色の操作を示す文字列　戻り値：特定した色の操作
		RENDERING::INFORM::BLEND::E_BLEND_OPTION M_Get_Blend_Option_By_Text(std::string);

		// どの書き込む形式を設定するかを指定された文字列から特定して返す　引数：書き込むデータ形式をを示す文字列　戻り値：書き込むデータの形式
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT M_Get_Blend_Write_Format_By_Text(std::string);

		// どの書き込む色の種類を設定するかを指定された文字列から特定して返す　引数：書き込む色の種類を示す文字列　戻り値：書き込む色の種類
		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR M_Get_Blend_Write_Color_By_Text(std::string);


		//-☆- 深度ステンシル -☆-//

		// どの深度モードを設定するかを指定された文字列から特定して返す　引数：深度モードの種類を示す文字列　戻り値：深度モードの種類
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE M_Get_Depth_Mode_By_Text(std::string);

		// どの深度オプションを設定するかを指定された文字列から特定して返す　引数：深度オプションの種類を示す文字列　戻り値：深度オプションの種類
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE M_Get_Depth_Option_By_Text(std::string);

		// どのステンシルを有効にするかを指定された文字列から特定して返す　引数：ステンシルの有効無効を示す文字列　戻り値：ステンシルの有効無効
		RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS M_Get_Stencil_Is_Active_By_Text(std::string);


		//-☆- ラスタライザ -☆-//

		// どの描画モードを設定するかを指定された文字列から特定して返す　引数：描画モードの種類を示す文字列　戻り値：描画モードの種類
		RENDERING::INFORM::RASTERIZER::E_DRAW_MODE M_Get_Draw_Mode_By_Text(std::string);

		// どの面を表示するかを指定された文字列から特定して返す　引数：面表示の種類を示す文字列　戻り値：面の表示モードを返す
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING M_Get_Mesh_Culling_By_Text(std::string);

		// どの面の表面の設定を使用するかを指定された文字列から特定して返す　引数：表面設定の種類を示す文字列　戻り値：表面設定を返す
		RENDERING::INFORM::RASTERIZER::E_MESH_FRONT M_Get_Mesh_Front_By_Text(std::string);

		// どのアンチエイリアシングの種類を指定された文字列から特定して返す　引数：アンチエイリアシングの種類を示す文字列　戻り値：アンチエイリアシングの種類を返す
		RENDERING::INFORM::RASTERIZER::E_ANTIALIASING M_Get_Antialiasing_By_Text(std::string);


		//-☆- ロード -☆-//

		// ブレンドの設定をマテリアル情報からロードする　引数：ブレンドの設定先, 読み込んだファイルの情報
		void M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::S_Blend_Setting_Create_Data> &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 深度ステンシルをマテリアル情報からロードする　引数：深度ステンシルの設定先, 読み込んだファイルの情報
		void M_Load_Depth_Stencil_Setting(RENDERING::GRAPHICS::CREATE::S_Depth_Stencil_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// ラスタライザをマテリアル情報からロードする　引数：ラスタライザの設定先, 読み込んだファイルの情報
		void M_Load_Rasterizer_Setting(RENDERING::GRAPHICS::CREATE::S_Rasterizer_Create_Data &, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// その他設定をロードする　引数：設定先のレンダリング設定生成用情報, 読み込んだファイルの情報
		void M_Load_Another_Setting(RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform &, SYSTEM::TEXT::C_Text_And_File_Manager &);


		//-☆- 生成 -☆-//

		// スロットの情報をセットする　引数：設定するスロット識別用の情報
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_Resource_Inform_List & );

		// レンダリング情報を生成する　引数：現在のファイル文字列　戻り値：成功時のみtrue
		bool M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager &);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Material(void);

		// デストラクタ
		~C_Material(void);

		// メモリを解放して初期化する
		void M_Release(void);


		//-☆- ロード -☆-//

		// マテリアルデータへのパスからマテリアル情報をロード　引数：マテリアルデータへのパス　戻り値：成功時のみtrue
		bool M_Load_Material_By_Path(std::string);


		//-☆- 描画 -☆-//

		// レンダリング用の情報をGPUに設定する
		void M_Attach_To_GPU(void);


		//-☆- 定数バッファ -☆-//

		//--☆ セッタ ☆--//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された定数バッファにデータをセットする
		// 引数   ：int 設定先の定数バッファの番号, int 定数バッファの配列番号, const C_Constant_Data_Class & 定数バッファにセットするデータ
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<class C_Constant_Data_Class>
		void M_Set_Constant_Data_To_Slot_By_Index(int in_index, int in_buffer_index, const C_Constant_Data_Class& in_set_data)
		{
			// 配列外を指定されたら抜ける
			if (in_index < 0 || mpr_variable.constant_data_list.size() <= in_index)
			{
				return;
			}


			// ☆ 変数宣言 ☆ //
			int constant_data_size = sizeof(C_Constant_Data_Class);	// 定数データのバイト数


			// データをセットする
			mpr_variable.constant_data_list[in_index].data->M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void*>(&in_set_data));

			return;
		}

		//--☆ ゲッタ ☆--//

		// 指定された定数バッファ管理用データのアドレスを返す　引数：取得する定数バッファ管理用データの番号　戻り値：指定された定数バッファ情報のアドレス、なければnullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Index(int);

		// 指定された名前の定数バッファ管理用データのアドレスを返す　引数：取得する定数バッファ管理用データの名前　戻り値：指定された定数バッファ情報のアドレス、なければnullptr
		S_Constant_Buffer_Data * M_Get_Constant_Buffer_Data_By_Name(std::string);

		// 指定された名前の定数バッファ管理用データのスロット番号を返す　引数：取得する定数バッファ管理用データの名前　戻り値：int 指定された定数バッファの番号、なければ-1
		int M_Get_Constant_Buffer_Slot_Number_By_Name(std::string);

		//--☆ WVP ワールド ビュー プロジェクション ☆--//

		// 渡されたワールド変換行列（トランスフォーム）をWVP用の定数バッファにセットする　引数：セットするワールド変換行列の参照(const)
		void M_Set_World_Matrix(const DirectX::XMMATRIX & );

		// メインカメラのビュー変換行列、プロジェクション変換行列をWVP用の定数バッファにセットする
		void M_Set_View_Projection_By_Main_Camera(void);

		// 渡されたビュー変換行列（カメラ）をWVP用の定数バッファにセットする　引数：セットするビュー変換行列の参照(const)
		void M_Set_View_Matrix(const DirectX::XMMATRIX & );

		// 渡されたプロジェクション変換行列（描画スクリーン設定）をWVP用の定数バッファにセットする　引数：セットするプロジェクション変換行列の参照(const)
		void M_Set_Projection_Matrix(const DirectX::XMMATRIX & );

		// 渡されたWVP変換行列をWVP用の定数バッファにセットする　引数：セットするWVP変換行列の参照(const)
		void M_Set_WVP_Matrix(const MATH::WVP::S_World_View_Projection_Data & );

		//--☆ ボーン ☆--//

		// 渡されたボーンマトリクス行列をボーン用の定数バッファにセットする
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & );

		//--☆ 質感情報 ☆--//

		// マテリアルの質感情報をセットする　引数：セットするマテリアル質感情報の参照（const）
		void M_Set_Material_Detail(const DATA::MATERIAL_DETAIL::S_Material_Detail & );


		//-☆- テクスチャ -☆-//

		//--☆ ロード ☆--//

		// 指定されたスロットにテクスチャをロードする　引数：テクスチャスロット番号, ロードするテクスチャ名　戻り値：成功時のみtrue
		bool M_Load_Texture_To_Slot_By_Index(int, std::string);

		//--☆ ゲッタ ☆--//

		// 指定されたテクスチャ管理用データのアドレスを返す　引数：取得するテクスチャ管理用データの番号　戻り値：指定されたテクスチャバッファ情報のアドレス、なければnullptr
		S_Texture_Buffer_Data * M_Get_Texture_Data_By_Index(int);

		// 指定された名前のテクスチャ管理用データのアドレスを返す　引数：取得するテクスチャ管理用データの名前　戻り値：指定されたテクスチャバッファ情報のアドレス、なければnullptr
		S_Texture_Buffer_Data * M_Get_Texture_Data_By_Name(std::string);

		// 指定された名前のテクスチャ管理用データのスロット番号を返す　引数：取得するテクスチャ管理用データの名前　戻り値：指定されたテクスチャの番号、なければ-1
		int M_Get_Texture_Slot_Number_By_Name(std::string);


		//-☆- レンダリング画面 -☆-//

		//--☆ セッタ ☆--//

		// レンダリング画面をスロットにセットする＊注意：シェーダーでのスロット番号ではない　引数：レンダリング画像の設定先スロット番号, レンダリング画像の参照
		void M_Set_Rendering_Screen_To_Slot_By_Index(int, RENDERING::CAPSULE::C_Rendering_Screen_System & );

		// メインのレンダリング画面をスロットにセットする＊注意：シェーダーでのスロット番号ではない　引数：レンダリング画像の設定先スロット番号
		void M_Set_Main_Rendering_Screen_To_Slot_By_Index(int);

		//--☆ ゲッタ ☆--//

		// 指定されたレンダリング画面管理用データのアドレスを返す　引数：取得するレンダリング画面管理用データの番号　戻り値：指定されたレンダリング画面バッファ情報のアドレス、なければnullptr
		S_Rendering_Screen_Data * M_Get_Rendering_Screen_Data_By_Index(int);

		// 指定された名前のレンダリング画面管理用データのアドレスを返す　引数：取得するレンダリング画面管理用データの名前　戻り値：指定されたレンダリング画面バッファ情報のアドレス、なければnullptr
		S_Rendering_Screen_Data * M_Get_Rendering_Screen_By_Name(std::string);

		// 指定された名前のレンダリング画面管理用データのスロット番号を返す　引数：取得するレンダリング画面管理用データの名前　戻り値：指定されたレンダリング画面の番号、なければ-1
		int M_Get_Rendering_Screen_Slot_Number_By_Name(std::string);


		//-☆- 深度ステンシルバッファ -☆-//

		//--☆ セッタ ☆--//

		// 深度ステンシルバッファをスロットにセットする＊注意：シェーダーでのスロット番号ではない　引数：深度ステンシルバッファの設定先スロット番号, 深度ステンシルバッファの参照
		void M_Set_Depth_Stencil_Buffer_To_Slot_By_Index(int, RENDERING::CAPSULE::C_Depth_Stencil_Buffer_System & );

		// メインの深度ステンシルバッファをスロットにセットする＊注意：シェーダーでのスロット番号ではない　引数：深度ステンシルバッファの設定先スロット番号
		void M_Set_Main_Depth_Stencil_Buffer_To_Slot_To_Index(int);

		//--☆ ゲッタ ☆--//

		// 指定された深度ステンシルバッファ管理用データのアドレスを返す　引数：取得する深度ステンシルバッファ管理用データの番号　戻り値：指定された深度ステンシルバッファ情報のアドレス、なければnullptr
		S_Depth_Stencil_Data * M_Get_Depth_Stencil_Data_By_Index(int);

		// 指定された名前の深度ステンシルバッファ管理用データのアドレスを返す　引数：取得する深度ステンシルバッファ管理用データの名前　戻り値：指定された深度ステンシルバッファ情報のアドレス、なければnullptr
		S_Depth_Stencil_Data * M_Get_Depth_Stencil_Buffer_By_Name(std::string);

		// 指定された名前の深度ステンシルバッファ管理用データのスロット番号を返す　引数：取得する深度ステンシルバッファ管理用データの名前　戻り値：指定された深度ステンシルバッファの番号、なければ-1
		int M_Get_Depth_Stencil_Buffer_Slot_Number_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

