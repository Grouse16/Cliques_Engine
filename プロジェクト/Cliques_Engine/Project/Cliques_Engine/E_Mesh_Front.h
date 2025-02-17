//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：表面の基準の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE
#define D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE


// ☆ ネームスペース ☆ //

// ラスタライザ定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::RASTERIZER
{
	// ☆ 列挙 ☆ //

	// 表面の基準の列挙
	enum class E_MESH_FRONT : unsigned char
	{
		e_ANTI_CLOCK_WISE,	// 反時計回りの面が表面
		e_CLOCK_WISE,		// 時計回りの面が表面
	};
}


#endif // !D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE

