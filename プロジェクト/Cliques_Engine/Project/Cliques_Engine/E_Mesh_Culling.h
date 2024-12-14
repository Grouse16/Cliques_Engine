//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：面のカリングの描画基準の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE
#define D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE


// ☆ ネームスペース ☆ //

// ラスタライザ定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::RASTERIZER
{
	// ☆ 列挙 ☆ //

	// 面のカリングの描画基準の列挙
	enum class E_MESH_CULLING : unsigned char
	{
		e_ALWAYS,	// 常に描画
		e_FRONT,	// 表面のみ描画
		e_BACK,		// 裏面のみ描画
	};
}


#endif // !D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE

