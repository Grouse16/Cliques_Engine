//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャのマップを定義する情報
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE
#define D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Color.h"
#include "S_Rect.h"
#include "C_Half_Color.h"


// ☆ ネームスペース ☆ //

// テクスチャ用の定義を呼び出すための名前
namespace ASSET::TEXTURE
{
	// ☆ クラス ☆ //

	// テクスチャのマップ用のクラス
	class C_Texture_Map
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<DATA::COLOR::C_Color> texture_map;	// テクスチャ用のマップ、０列目は左下とする（0,0を左下にしたほうがtop>bottomになるので分かりやすい）
			
			int texture_size_x = 0;	// 横幅のテクスチャのサイズ
			int texture_size_y = 0;	// 縦幅のテクスチャのサイズ

		} mpr_variable;	// プライベート変数を呼び出すための名前


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Texture_Map(void);

		// テクスチャマップを生成する　引数：横幅のピクセル数, 縦幅のピクセル数
		void M_Create_Texture_Map(int, int);

		// デストラクタ
		~C_Texture_Map(void);

		// テクスチャマップを削除する
		void M_Delete_Map(void);


		//-☆- マップ -☆-//

		// テクスチャマップのサイズを変更する　引数：拡張後の横幅のピクセル数, 拡張後の縦幅のピクセル数
		void M_Map_Variable_Size_Change(int, int);


		//-☆- 書き込み -☆-//

		// 全てを一色で初期化　引数:書き込む色
		void M_Flush_All_Color(DATA::COLOR::C_Color &);

		// 指定された範囲に色を書き込む　引数：書き込む色, 書き込む範囲
		void M_Set_Color(DATA::COLOR::C_Color &, DATA::RECTSETTING::S_Rect &);

		// 指定された場所に色を直接書き込む　引数：書き込む色, 書き込む座標ｘ, 書き込む座標ｙ
		void M_Set_Color_At_Point(const DATA::COLOR::C_Color &, int, int);


		//-☆- ゲッタ -☆-//

		// 今のテクスチャ用のマップを返す　戻り値：テクスチャ用のマップの参照（０列目が左下なので注意）
		std::vector<DATA::COLOR::C_Color> & M_Get_Texture_Map(void);

		// 横幅のピクセルサイズを返す　戻り値：横幅の値
		int M_Get_Width_Size(void);

		// 縦幅のピクセルサイズを返す　戻り値：縦幅の値
		int M_Get_Height_Size(void);
	};
}


#endif // !D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE



