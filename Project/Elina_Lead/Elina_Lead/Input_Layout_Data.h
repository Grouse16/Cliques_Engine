//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点バッファの入力レイアウトを定義するためのデータ
// 説明   ：GLSL参考資料 https://www.khronos.org/opengl/wiki/OpenGL_Type
// 説明   ：HLSL参考資料 https://learn.microsoft.com/en-us/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
#define D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE


// ☆ ネームスペース ☆ //

// 入力レイアウト設定用のデータを呼び出すための名前
namespace DATA::INPUTLAYOUT
{
	// ☆ 定数 ☆ //

	// サポートするデータのビットサイズ
	enum class E_INPUT_DATA_BITSIZE
	{
		e_1BYTE_8BIT,		// 8ビット、1バイト分　強制的にInt形式になるのでFLOATのセットはしないようにすること
		e_2BYTE_16BIT,	// 16ビット、2バイト分
		e_4BYTE_32BIT,	// 32ビット、4バイト分

		// 64はGLSLのみになるのでサポートしない
	};

	// データ型
	enum class E_INPUT_DATA_FORMAT
	{
		e_INT,		// INT型
		e_UINT,		// UINT型
		e_FLOAT,	// FLOAT型 又は half
	};

	// 変数の数　（float4 や int3など、xyzwの指定）
	enum class E_INPUT_DATA_PARAMATOR_SUM
	{
		e_1 = 1,	// １つ
		e_2 = 2,	// ２つ
		e_3 = 3,	// ３つ
		e_4 = 4,	// ４つ
	};


	// ☆ 構造体 ☆ //

	// 生成用の情報
	struct S_INPUT_LAYOUT_SETTING
	{
		E_INPUT_DATA_BITSIZE size;	// 変数一つ分のビットサイズ（vec.xなどのサイズ）

		E_INPUT_DATA_FORMAT format;	// 形式（データ型）
		
		E_INPUT_DATA_PARAMATOR_SUM sum;	// 変数の数　（float4 や int3など、xyzwの指定）
	};
}


#endif // !D_INCLUDE_GUARD_INPUT_LAYOUT_DATA_H_FILE
