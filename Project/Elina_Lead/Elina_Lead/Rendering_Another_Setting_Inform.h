//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング設定の定義を行うファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// レンダリング設定定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::SETTING
{
	// ☆ 列挙 ☆ //

	// レンダリング画像に書き込むピクセルのデータ形式の列挙
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// １バイトのUINT
		e_BYTE_2_UINT,	// ２バイトのUINT
		e_BYTE_3_UINT,	// ３バイトのUINT
		e_BYTE_4_UINT,	// ４バイトのUINT

		e_BYTE_2_FLOAT,	// ２バイトのFLOAT
		e_BYTE_4_FLOAT,	// ４バイトのFLOAT
	};

	// レンダリング画像に書き込む色の種類数の列挙
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// 赤のみ
		e_RG,	// 赤と緑
		e_RGB,	// 赤と緑と青
		e_RGBA,	// 赤と緑と青とα値
	};


	// ☆ 構造体 ☆ //

	// サンプリングの設定を行うための情報の構造体
	struct S_Sampling_Setting_Inform
	{
		int sampling_count = 1;		// サンプリングの回数
		int sampling_quality = 1;	// サンプリングの品質

		bool flg_conservative = true;	// 保守的なサンプリングのフラグ、trueで有効、falseで無効
	};
}


#endif // !D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE



