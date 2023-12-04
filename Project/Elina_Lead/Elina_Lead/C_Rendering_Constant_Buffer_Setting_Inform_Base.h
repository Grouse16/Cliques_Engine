//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファのセット用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>

#include "E_Shader_Kind.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// 定数バッファ制御用データの基底クラス
	class C_Rendering_Constant_Buffer_Setting_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		//-☆- 関数 -☆-//

		//-☆- 終了時 -☆-//

		// コンストラクタ
		C_Rendering_Constant_Buffer_Setting_Inform_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Constant_Buffer_Setting_Inform_Base(void);


		//-☆- セッタ -☆-//

		// 定数バッファに指定された情報をセットする　引数：セットするデータ, 配列数, セットするデータサイズ
		virtual void M_Set_Data_To_Buffer(void*, int, int) = 0;


		//-☆- ゲッタ -☆-//

		// 定数バッファのデータのアドレスを返す　＊使用が終わったら必ずCloseすること　戻り値：定数バッファのデータのアドレス
		virtual unsigned char * M_Get_Constant_Buffer_Data_Address(void) = 0;

		// 定数バッファのデータを使用終了する
		virtual void M_Close_Constant_Buffer_Data_Address(void) = 0;
	};


	// 定数バッファを描画するときの情報セット
	struct S_Constant_Buffer_Drawing_Setting
	{
		C_Rendering_Constant_Buffer_Setting_Inform_Base * add_constant_buffer = nullptr;	// 定数バッファ用情報のアドレス

		std::string * add_signature_name = nullptr;	// 識別名のアドレス

		ASSET::SHADER::E_SHADER_KIND * add_attach_shader_kind = nullptr;	// 設定先のシェーダーの種類のアドレス
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
