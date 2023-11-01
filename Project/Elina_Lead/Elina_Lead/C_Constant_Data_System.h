//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：定数データのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>
#include <memory>
#include <string>

#include "E_Shader_Kind.h"
#include "C_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Creat_Constant_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// 定数バッファの情報を円滑に設定し、レンダリングするためのシステム
	class C_Constant_Buffer_Data_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 構造体 ☆ //

		// 256バイトの定義用の型
		struct S_256_Byte_Type
		{
			std::byte data[256]{};	// データ、256バイト分ある
		};


		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr <RENDERING::GRAPHICS::INSTANCE::C_Constant_Buffer_Setting_Inform_Base> constant_buffer_inform;	// 定数データ用のバッファ

			std::vector<S_256_Byte_Type> constant_data;	// 定数データ

			std::string data_signature_name = "";	// データ識別名、パイプライン情報システムと同じ識別名を付加することでGPUに情報を渡せる

			ASSET::SHADER::E_SHADER_KIND attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// テクスチャデータ設定先のシェーダーの種類

			int list_sum = 0;	// 配列数

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Constant_Buffer_Data_System(void);

		// 定数バッファを生成する　引数：バッファ数
		void M_Constant_Buffer_Init(int);

		// デストラクタ
		~C_Constant_Buffer_Data_System(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- セッタ -☆-//

		// データの識別名をセットする　引数：セットする文字列
		void M_Set_Data_Signature_Name(std::string);

		// テクスチャデータ設定先のシェーダーの種類を変更する　引数：設定先のシェーダーの種類
		void M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);


		//-☆- ゲッタ -☆-//

		// データの識別名を返す　戻り値：現在のデータ識別名の参照
		const std::string & M_Get_Data_Signature_Name(void);

		// 定数バッファ用のデータを返す　戻り値：定数データ
		std::vector<S_256_Byte_Type> & M_Get_Constant_Data(void);

		// テクスチャデータ設定先のシェーダーの種類を返す　戻り値：設定先のシェーダーの種類
		ASSET::SHADER::E_SHADER_KIND M_Get_Attach_Shader_Kind(void);


		//-☆- 描画 -☆-//

		// 定数バッファを現在のデータで更新する
		void M_Set_Constant_Data_To_Buffer(void);

		// 定数バッファをGPUに渡す
		void M_Set_Constant_Buffer_To_GPU(void);

		// 定数バッファを指定されたインデックスにセットし、GPUに渡す　引数：設定するインデックス番号（定数バッファのスロット番号）
		void M_Set_Constant_Buffer_To_GPU_By_Index(int);
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_DATA_SETTING_H_FILE

