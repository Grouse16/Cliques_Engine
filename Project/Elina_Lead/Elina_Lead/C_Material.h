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
#include "C_Shader_Setting.h"


// ☆ ネームスペース ☆ //

// マテリアルを呼び出すための名前
namespace ASSET::MATERIAL
{
	// ☆ 構造体 ☆ //

	// 定数バッファを使用する際の情報をまとめた構造体
	struct S_Constant_Buffer_Data
	{
		std::unique_ptr<RENDERING::CAPSULE::C_Constant_Buffer_Data_System> data;	// 定数バッファを管理するシステム

		std::string signature_name = "default";	// 定数バッファ識別用名

		int index = 0;	// 定数バッファのインデックス番号
	};


	// テクスチャバッファを使用する際の情報をまとめた構造体
	struct S_Texture_Buffer_Data
	{
		ASSET::TEXTURE::C_Texture_Data_User data;	// テクスチャを使用するためのシステム

		std::string signature_name = "default";	// テクスチャスロット識別用名

		int index = 0;	// テクスチャのインデックス番号
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
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// 描画用設定

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// 使用する定数バッファのリスト
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// 使用するテクスチャのリスト

			ASSET::SHADER::C_Shader_Setting shader_setting_data;	// シェーダー設定用情報

		} mpr_variable;	// プライベート変数を呼び出すための名前

		
		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// ブレンドの設定をマテリアル情報からロードする　引数：ブレンドの設定先, 読み込んだファイルの情報
		void M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> &, SYSTEM::TEXT::C_Text_And_File_Manager &);


		//-☆- 生成 -☆-//

		// スロットの情報をセットする　引数：設定するスロット識別用の情報
		void M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & );

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


		//-☆- セッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された定数バッファにデータをセットする
		// 引数   ：int 設定先の定数バッファの番号, int 定数バッファの配列番号, const C_Constant_Data_Class & 定数バッファにセットするデータ
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<class C_Constant_Data_Class>
		void M_Set_Constant_Data_To_Buffer_By_Index(int in_index, int in_buffer_index, const C_Constant_Data_Class & in_set_data)
		{
			// 配列外を指定されたら抜ける
			if (mpr_variable.constant_data_list.size() <= in_index)
			{
				return;
			}


			// ☆ 変数宣言 ☆ //
			int constant_data_size = sizeof(C_Constant_Data_Class);	// 定数データのバイト数


			// データをセットする
			mpr_variable.constant_data_list[in_index].data.M_Set_Constant_Data(constant_data_size, in_buffer_index, reinterpret_cast<void * >(&in_set_data));

			return;
		}

		// 指定されたスロットにテクスチャをロードする　引数：テクスチャスロット番号, ロードするテクスチャ名
		void M_Load_Texture_For_Slot_By_Index(int, std::string);


		//-☆- ゲッタ -☆-//

		// 指定された定数バッファ管理用データを返す　引数：取得する定数バッファ管理用データの番号
		const S_Constant_Buffer_Data & M_Get_Constant_Buffer_Data_By_Index(int);

		// 指定されたテクスチャ管理用データを返す　引数：取得するテクスチャ管理用データの番号
		const S_Texture_Buffer_Data & M_Get_Texture_Data_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

