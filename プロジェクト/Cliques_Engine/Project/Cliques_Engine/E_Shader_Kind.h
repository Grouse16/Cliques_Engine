//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーの種類定義用ファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE
#define D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE


// ☆ ネームスペース ☆ //

// シェーダー用のデータを呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ 定数 ☆ //

	// シェーダーの種類を指定するための列挙
	enum class E_SHADER_KIND : char
	{
		e_VERTEX,			// 頂点
		e_HULL_TCS,			// ハル、テッセレーション制御
		e_DOMAIN_TES,		// ドメイン、テッセレーション評価
		e_GEOMETRY,			// ジオメトリ
		e_PIXEL_FRAGMENT,	// ピクセル、フラグメント

		e_ALL,	// 全てを指定する、シェーダー種類数と同じ値
	};
}


#endif // !D_INCLUDE_GUARD_SHADER_KIND_DATA_H_FILE

