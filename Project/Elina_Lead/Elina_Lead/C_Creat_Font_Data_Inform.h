//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フォントデータを生成するための情報
// 説明   ：情報を定義するのみなので実際の生成はこの情報をレンダリングAPIに渡すことで行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CREAT_FONT_DATA_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREAT_FONT_DATA_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>


// ☆ ネームスペース ☆ //

// レンダリングAPIに使用するシステムを生成するための情報
namespace RENDERING::GRAPHICS::CREAT
{
	// ☆ クラス ☆ //

	// フォントデータを生成するための情報
	class C_Creat_Font_Data_Inform
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		std::wstring m_font_name = L"\0";	// フォント名

		int m_height = 0;	// 使用可能なフォントの縦サイズ

		int m_width = 0;	// フォントの太さ
	};
}


#endif // !D_INCLUDE_GUARD_C_CREAT_FONT_DATA_INFORM_H_FILE
