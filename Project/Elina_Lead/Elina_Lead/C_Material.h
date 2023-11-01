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

#include "C_Rendering_Setting_System.h"
#include "C_Texture_Data_System.h"
#include "C_Constant_Data_System.h"


// ☆ ネームスペース ☆ //

// マテリアルを呼び出すための名前
namespace ASSET::MATERIAL
{
	// ☆ クラス ☆ //
	
	// マテリアルのクラス、描画時の描画方法の設定を行う
	class C_Material
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// 定数バッファを使用する際の情報をまとめた構造体
		struct S_Constant_Buffer_Data
		{
			RENDERING::CAPSULE::C_Constant_Buffer_Data_System data;	// 定数バッファを管理するシステム

			int index = 0;	// 定数バッファのインデックス番号
		};


		// テクスチャバッファを使用する際の情報をまとめた構造体
		struct S_Texture_Buffer_Data
		{
			RENDERING::CAPSULE::C_Texture_Data_System * data = nullptr;	// テクスチャバッファを管理するシステム

			int index = 0;	// 定数バッファのインデックス番号
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System rendering_setting;	// 描画用設定

			SHADER::C_Shader_Setting shader_setting_data;	// シェーダー設定用情報

			std::vector<S_Constant_Buffer_Data> constant_data_list;	// 使用する定数バッファのリスト
		
			std::vector<S_Texture_Buffer_Data> texture_data_list;	// 使用するテクスチャのリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前


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
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_H_FILE

