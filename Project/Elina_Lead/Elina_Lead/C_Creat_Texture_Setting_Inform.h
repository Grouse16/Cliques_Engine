//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャ用情報を生成するための情報のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::GRAPHICS::CREAT
{
	// ☆ 定数 ☆ //

	// テクスチャのデータ形式指定用の列挙
	enum class E_TEXTURE_DATA_FORMAT
	{
		e_8BIT_MULTI_4,	// ８ビット４つ
		e_8BIT_MULTI_2,	// ８ビット２つ
		e_8BIT_MULTI_1,	// ８ビット１つ
	};


	// ☆ クラス ☆ //

	// テクスチャ用情報を生成するための情報のクラス
	class C_Creat_Texture_Setting_Inform
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		int pixel_width = 0;		// 横幅のピクセル数
		int pixel_height = 0;		// 縦幅のピクセル数
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_TEXTURE_SETTING_INFORM_H_FILE
