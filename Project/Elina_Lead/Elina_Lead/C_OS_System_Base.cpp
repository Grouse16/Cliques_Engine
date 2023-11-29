//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：OSのシステムを制御するための基底クラス
// 説明   ：OSの挙動などを指定する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_OS_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace OS;


// ☆ 変数宣言 ☆ //
std::unique_ptr<C_OS_System_Base> C_OS_System_Base::m_this_instance;	// インスタンス化するための実体

bool C_OS_System_Base::m_flg_os_active = false;	// OSが終了したかどうかのフラグ


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_OS_System_Base::C_OS_System_Base(void)
{
	m_flg_os_active = true;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OSシステムを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Delete_OS_System(void)
{
	m_this_instance.reset();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_OS_System_Base::~C_OS_System_Base(void)
{
	m_this_instance.reset();

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マウス座標をセットする
// 引数   ：int ｘ座標, int ｙ座標
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void OS::C_OS_System_Base::M_Set_Mouse_Position_Variable(int in_set_x, int in_set_y)
{
	m_mouse_state.x = in_set_x;
	m_mouse_state.y = in_set_y;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：画面サイズをセットする
// 引数   ：int 横幅, int 縦幅
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Set_Window_Size_Variable(int in_width, int in_height)
{
	m_size_of_window.width = (in_width != 0) * in_width + (in_width == 0) * 1;
	m_size_of_window.height = (in_height != 0) * in_height + (in_height == 0) * 1;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウの座標をセットする
// 引数   ：S_Window_Position & ウィンドウ座標
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Set_Window_Position_Variable(S_Window_Position & in_window_pos)
{
	m_position_window = in_window_pos;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：左クリックのフラグをセットする
// 引数   ：E_MOUSE_CLICK_STATE クリックの状態
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Set_Left_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.left_click = in_set_state;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：右クリックのフラグをセットする
// 引数   ：E_MOUSE_CLICK_STATE クリックの状態
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Set_Right_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.right_click = in_set_state;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：中クリックのフラグをセットする
// 引数   ：E_MOUSE_CLICK_STATE クリックの状態
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_OS_System_Base::M_Set_Center_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.center_click = in_set_state;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OS用システムのインスタンスのアドレスを返す
// 引数   ：void
// 戻り値 ：C_OS_System_Base * OSシステムのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_OS_System_Base * C_OS_System_Base::M_Get_Instance(void)
{
	return m_this_instance.get();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OSのシステムが停止したかどうかを返す
// 引数   ：void
// 戻り値 ：終了時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_OS_System_Base::M_Get_OS_Active(void)
{
	return m_flg_os_active;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのサイズを返す
// 引数   ：void
// 戻り値 ：const S_Window_Size_Data & ウィンドウのサイズ
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Window_Size_Data & OS::C_OS_System_Base::M_Get_Window_Size(void) const
{
	return m_size_of_window;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウのアスペクト比を返す
// 引数   ：void
// 戻り値 ：float アスペクト比
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_OS_System_Base::M_Get_Aspect_Size(void) const
{
	return static_cast<float>(m_size_of_window.width) / static_cast<float>(m_size_of_window.height);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウの位置を返す
// 引数   ：void
// 戻り値 ：const S_Window_Position & ウィンドウの座標
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Window_Position & OS::C_OS_System_Base::M_Get_Window_Position(void)
{
	return m_position_window;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マウスの状態を返す
// 引数   ：void
// 戻り値 ：const S_Window_Position & マウスの状態
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Mouse_State & OS::C_OS_System_Base::M_Get_Mouse_State(void)
{
	return m_mouse_state;
}




