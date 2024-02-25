//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テスクチャのセット用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE
#define D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE


// ☆ ファイルひらき ☆ //
#include <string>
#include <memory>
#include <vector>

#include "E_Shader_Kind.h"
#include "C_Texture_Map.h"
#include "C_Half_Color.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::API::INSTANCE
{
	// ☆ クラス ☆ //

	// テスクチャのセット用のデータの基底クラス
	class C_Rendering_Texture_Setting_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Texture_Setting_Inform_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Texture_Setting_Inform_Base(void);


		//-☆- 更新 -☆-//

		// テクスチャのデータをセットする　引数：設定する色配列への参照, テクスチャの横幅, テクスチャの縦幅
		virtual void M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> & , int, int) = 0;
	};


	// 定数バッファを描画するときの情報セット
	struct S_Texture_Buffer_Drawing_Setting
	{
		C_Rendering_Texture_Setting_Inform_Base * add_texture_data = nullptr;	// テクスチャデータ用情報のアドレス

		std::string * add_signature_name = nullptr;	// 識別名のアドレス

		ASSET::SHADER::E_SHADER_KIND attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// 設定先のシェーダーの種類のアドレス
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_TEXTURE_SETTING_INFORM_BASE
