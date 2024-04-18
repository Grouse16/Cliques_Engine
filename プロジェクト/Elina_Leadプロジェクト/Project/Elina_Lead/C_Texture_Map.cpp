//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャのマップを定義する情報
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Texture_Map.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::TEXTURE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Map::C_Texture_Map(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップを生成する
// 引数   ：int 横幅のピクセル数, int 縦幅のピクセル数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Create_Texture_Map(int in_side_pixel, int in_vert_pixel)
{
	// サイズがマイナス値を指定されたら無効
	if (in_side_pixel < 0 || in_vert_pixel < 0)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	DATA::COLOR::C_Color flush_color(1.0f, 1.0f, 1.0f, 1.0f);	// 画像の色を初期化するための色設定


	// 現在のデータは消す
	M_Delete_Map();


	// サイズをセット
	mpr_variable.texture_size_x = in_side_pixel;
	mpr_variable.texture_size_y = in_vert_pixel;


	// サイズ分のメモリの確保（透明な状態で作成）
	mpr_variable.texture_map.resize(mpr_variable.texture_size_x * mpr_variable.texture_size_y);
	M_Flush_All_Color(flush_color);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Map::~C_Texture_Map(void)
{
	M_Delete_Map();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Delete_Map(void)
{
	mpr_variable.texture_map.clear();
	mpr_variable.texture_map.shrink_to_fit();
	mpr_variable.texture_size_x = 0;
	mpr_variable.texture_size_y = 0;

	return;
}


//-☆- マップ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップのサイズを変更する
// 引数   ：int 変更後の横幅のピクセル数, int 変更後の縦幅のピクセル数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Map_Variable_Size_Change(int in_extend_x_size, int in_extend_y_size)
{
	// ☆ 変数宣言 ☆ //
	std::vector<DATA::COLOR::C_Color> then_texture_map;	// 拡張後のデータとなるテクスチャマップ

	int then_size_x = mpr_variable.texture_size_x;	// 拡張前のｘでのサイズ
	int then_size_y = mpr_variable.texture_size_y;	// 拡張前のｙでのサイズ

	int then_map_size = (int)mpr_variable.texture_map.size();	// 拡張前のマップのサイズ

	
	// 拡張前の情報を復元用に移す
	then_texture_map.resize(then_map_size);
	for (int l_pixel_num = 0; l_pixel_num < then_map_size; l_pixel_num++)
	{
		then_texture_map[l_pixel_num] = mpr_variable.texture_map[l_pixel_num];
	}


	// マップを拡張する
	mpr_variable.texture_size_x = 
		(mpr_variable.texture_size_x >= in_extend_x_size) * mpr_variable.texture_size_x 
		+
		(mpr_variable.texture_size_x < in_extend_x_size) * in_extend_x_size;

	mpr_variable.texture_size_y =
		(mpr_variable.texture_size_y >= in_extend_y_size) * mpr_variable.texture_size_y
		+
		(mpr_variable.texture_size_y < in_extend_y_size) * in_extend_y_size;
	mpr_variable.texture_map.resize(mpr_variable.texture_size_x * mpr_variable.texture_size_y);
	

	// 今までの情報を保持したまま新しい部分のみを初期化する
	for (int l_pixel_y = 0; l_pixel_y < mpr_variable.texture_size_y; l_pixel_y++)
	{
		// ｙでいままで保持する情報がある範囲なら、ｘで保持する範囲の判定も行う
		if (l_pixel_y < then_size_y)
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				// ☆ 変数宣言 ☆ //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// 書き込む座標


				// ｘでいままでで保持する情報がある範囲なら、今までの配列から情報を移してくる
				if (l_pixel_x < then_size_x)
				{
					mpr_variable.texture_map[map_write_pos] = then_texture_map[l_pixel_y * then_size_x + l_pixel_x];
				}

				// 保持する範囲外なら初期化色を入れる
				else
				{
					mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
				}
			}
		}

		// ｙで保持する範囲外なら初期化色を書き込む
		else
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				// ☆ 変数宣言 ☆ //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// 書き込む座標


				mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
			}
		}
	}

	return;
}


//-☆- 書き込む -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：全てを一色で初期化
// 引数   ：C_Color & 書き込む色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Flush_All_Color(DATA::COLOR::C_Color & in_flush_color)
{
	for(int row_y = 0; row_y < mpr_variable.texture_size_y; row_y++)
	{
		// ☆ 変数宣言 ☆ //
		int row_plus = row_y * mpr_variable.texture_size_x;	// 設定位置の縦列分でずらす量


		for (int len_x = 0; len_x < mpr_variable.texture_size_x; len_x++)
		{
			mpr_variable.texture_map[row_plus + len_x] = in_flush_color;
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された範囲に色を書き込む
// 引数   ：C_Color & 書き込む色, S_Recto & 書き込む範囲
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Set_Color(DATA::COLOR::C_Color & in_set_color, DATA::RECTSETTING::S_Rect & in_rect_range)
{
	// 指定範囲が無効なら抜ける
	if (in_rect_range.right_x <= 0 || in_rect_range.top_y <= 0)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	int x_start = in_rect_range.left_x - 1;	// 横での書き込み範囲の上限
	int x_limit = in_rect_range.right_x;	// 横での書き込み範囲の上限

	int y_start = in_rect_range.bottom_y - 1;	// 縦での書き込み範囲の上限
	int y_limit = in_rect_range.top_y;	// 縦での書き込み範囲の上限


	// ☆ マップの方が小さいならそれを上限にする ☆ //
	x_limit = (x_limit > mpr_variable.texture_size_x) * mpr_variable.texture_size_x + (x_limit <= mpr_variable.texture_size_x) * x_limit;
	y_limit = (y_limit > mpr_variable.texture_size_y) * mpr_variable.texture_size_y + (y_limit <= mpr_variable.texture_size_y) * y_limit;

	
	// ☆ 書き込み開始位置が範囲内に出ないように調整する ☆ //
	x_start = x_start >= 0 * x_start;
	y_start = y_start >= 0 * y_start;


	// 指定された範囲を書き込む
	for (int row_y = x_start; row_y < y_limit; row_y++)
	{
		// ☆ 変数宣言 ☆ //
		int row_plus = row_y * mpr_variable.texture_size_x;	// 設定位置の縦列分でずらす量


		for (int len_x = y_start; len_x < x_limit; len_x++)
		{
			mpr_variable.texture_map[row_plus + len_x] = in_set_color;
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された場所に色を直接書き込む
// 引数   ：const C_Color & 書き込む色, int 書き込む座標ｘ, int 書き込む座標ｙ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Map::M_Set_Color_At_Point(const DATA::COLOR::C_Color & in_set_color, int in_set_pos_x, int in_set_pos_y)
{
	// 範囲外を指定されたら処理をしない
	if (in_set_pos_x <= 0 || in_set_pos_y <= 0)
	{
		return;
	}


	// 塗る位置を1始まりで指定できるように調整
	in_set_pos_x -= 1;
	in_set_pos_y -= 1;


	// セットする範囲が今のテクスチャサイズを超えるなら配列数を調整する
	if (in_set_pos_x >= mpr_variable.texture_size_x || in_set_pos_y >= mpr_variable.texture_size_y)
	{
		M_Map_Variable_Size_Change(in_set_pos_x, in_set_pos_y);
	}


	// ☆ 変数宣言 ☆ //
	int set_pos = mpr_variable.texture_size_x * in_set_pos_y + in_set_pos_x;	// 色を設定する配列番号


	// 色を設定
	mpr_variable.texture_map[set_pos].m_r = in_set_color.m_r;
	mpr_variable.texture_map[set_pos].m_g = in_set_color.m_g;
	mpr_variable.texture_map[set_pos].m_b = in_set_color.m_b;
	mpr_variable.texture_map[set_pos].m_a = in_set_color.m_a;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今のテクスチャ用のマップを返す
// 引数   ：void
// 戻り値 ：vector<C_Color> テクスチャ用のマップの参照（０列目が左下なので注意）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<DATA::COLOR::C_Color> & C_Texture_Map::M_Get_Texture_Map(void)
{
	return mpr_variable.texture_map;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：横幅のピクセルサイズを返す
// 引数   ：void
// 戻り値 ：戻り値：横幅の値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Texture_Map::M_Get_Width_Size(void)
{
	return mpr_variable.texture_size_x;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：縦幅のピクセルサイズを返す
// 引数   ：void
// 戻り値 ：戻り値：縦幅の値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Texture_Map::M_Get_Height_Size(void)
{
	return mpr_variable.texture_size_y;
}




