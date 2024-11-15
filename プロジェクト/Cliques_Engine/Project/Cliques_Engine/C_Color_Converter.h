//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：三種類の色情報間の変換を行うクラス
// 説明   ：三種類の色とは、C_Color C_Half_Color C_1_Byte_Colorのこと
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
#define D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Color.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"


// ☆ ネームスペース ☆ //

// 色の定義を呼び出すための名前
namespace DATA::COLOR
{
	// ☆ クラス ☆ //

	// 三種類の色情報間の変換を行うクラス
	class C_Color_Converter
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ、実体化防止のために削除する
		C_Color_Converter(void) = delete;


		//-☆- 4バイト色への変換 -☆-//

		// 1バイト色から4バイト色への変換　引数：1バイト色の参照　戻り値：4バイト色
		static C_Color M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color &);

		// ２バイト色から4バイト色への変換　引数：２バイト色の参照　戻り値：4バイト色
		static C_Color M_Convert_Half_Color_To_Color(const C_Half_Color &);


		//-☆- 2バイト色への変換 -☆-//

		// 1バイト色から2バイト色への変換　引数：1バイト色の参照　戻り値：2バイト色
		static C_Half_Color M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color &);

		// 4バイト色から2バイト色への変換　引数：4バイト色の参照　戻り値：2バイト色
		static C_Half_Color M_Convert_Color_To_Half_Color(const C_Color &);


		//-☆- 1バイト色への変換 -☆-//

		// 2バイト色から1バイト色への変換　引数：2バイト色の参照　戻り値：1バイト色
		static C_1_Byte_Color M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color &);

		// 4バイト色から1バイト色への変換　引数：4バイト色の参照　戻り値：1バイト色
		static C_1_Byte_Color M_Convert_Color_To_1_Byte_Color(const C_Color &);
	};
}


#endif // !D_INCLUDE_GUARD_C_COLOR_CONVERTER_H_FILE
