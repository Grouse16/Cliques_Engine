//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力の当たり判定を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <algorithm>

#include "C_Game_Input_Collision_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INPUT::COLLISION;


// ☆ スタティック変数 ☆ //
std::unique_ptr<C_Game_Input_Collision_Manager> C_Game_Input_Collision_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Input_Collision_Manager::C_Game_Input_Collision_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームの入力ボックス制御用システムの生成
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Input_Collision_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Input_Collision_Manager);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Input_Collision_Manager::~C_Game_Input_Collision_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリ解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Input_Collision_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力判定のリストの参照を返す
// 引数   ：void
// 戻り値 ：vector<C_Game_Input_Collision * > & 入力判定のリストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::vector<C_Game_Input_Collision * > & C_Game_Input_Collision_Manager::M_Get_Input_Collision_List(void)
{
	return m_this->mpr_variable.collision_list;
}


//-☆- リスト -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された入力判定のアドレスを管理用リストに追加する
// 引数   ：C_Game_Input_Collision * リストに追加する入力判定のアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * in_add_input_box)
{
	m_this->mpr_variable.collision_list.reserve(m_this->mpr_variable.collision_list.size() + 1);
	m_this->mpr_variable.collision_list.emplace_back(in_add_input_box);

	// 優先度を元に降順にソートする
	std::sort
	(
		m_this->mpr_variable.collision_list.begin(),	// ソートの開始
		m_this->mpr_variable.collision_list.end(),		// ソートのおわり

		// ラムダ式、右の要素が左の要素よりも値が大きければ、順番を入れ替える
		[](C_Game_Input_Collision * & left_function, C_Game_Input_Collision * & right_function)
		{
			return left_function->M_Get_Priority() >= right_function->M_Get_Priority();
		}
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された入力判定のアドレスを管理用リストから削除する
// 引数   ：C_Game_Input_Collision * リストから削除する入力判定のアドレス
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * in_delete_input_box)
{
	m_this->mpr_variable.collision_list.erase(std::remove(m_this->mpr_variable.collision_list.begin(), m_this->mpr_variable.collision_list.end(), in_delete_input_box), m_this->mpr_variable.collision_list.end());
	m_this->mpr_variable.collision_list.shrink_to_fit();

	return;
}
