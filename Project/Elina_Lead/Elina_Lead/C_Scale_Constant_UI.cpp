//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UIの図形定義用のデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "UI_Figure_Data.h"
#include "C_OS_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::FIGURE::UI;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Scale_Constant_UI::C_Scale_Constant_UI(void)
{
    m_box_color.m_r = 1.0f;
    m_box_color.m_g = 1.0f;
    m_box_color.m_b = 1.0f;
    m_box_color.m_a = 1.0f;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Scale_Constant_UI::~C_Scale_Constant_UI(void)
{
    return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：基準となる場所を指定する
// 引数   ：E_Scale_Base_Position 基準となる場所を指定する
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Scale_Constant_UI::M_Set_Scale_Base_Position(E_Scale_Base_Position in_base_position)
{
    m_base_position = in_base_position;

    return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI用の四角形をレクトから設定する
// 引数   ：S_Rect & 設置位置
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Scale_Constant_UI::M_Set_Constant_Pixel_By_Rect(DATA::RECTSETTING::S_Rect & in_set_rect)
{
    m_constant_pixel_pos = in_set_rect;

    return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：スケールをピクセル座標に合わせる更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Scale_Constant_UI::M_Scale_Update(void)
{
    // ☆ 変数宣言 ☆ //
    const OS::S_Window_Size_Data & now_window_size = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size();   // 現在のウィンドウサイズ
    

    // 基準となる場所によって左右の位置を設定
    switch (m_base_position)
    {
        // 一番左を基準にする
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
        m_box_pos.left_x = m_constant_pixel_pos.left_x / now_window_size.width;
        m_box_pos.right_x = m_constant_pixel_pos.right_x / now_window_size.width;
        break;

        // 一番右を基準にする
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
        m_box_pos.left_x = (now_window_size.width - m_constant_pixel_pos.left_x) / now_window_size.width;
        m_box_pos.right_x = (now_window_size.width - m_constant_pixel_pos.right_x) / now_window_size.width;
        break;
    }

    // 基準となる場所によって上下の位置を設定
    switch (m_base_position)
    {
        // 一番上を基準にする
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
        m_box_pos.top_y = (now_window_size.height - m_constant_pixel_pos.top_y) / now_window_size.height;
        m_box_pos.bottom_y = (now_window_size.height - m_constant_pixel_pos.bottom_y) / now_window_size.height;
        break;

        // 一番下を基準にする
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
        m_box_pos.top_y = m_constant_pixel_pos.top_y / now_window_size.height;
        m_box_pos.bottom_y = m_constant_pixel_pos.bottom_y / now_window_size.height;
        break;
    }


    // 画面の設定に合わせる
    m_box_pos.left_x = m_box_pos.left_x * 2.0f - 1.0f;
    m_box_pos.right_x = m_box_pos.right_x * 2.0f - 1.0f;
    m_box_pos.top_y = m_box_pos.top_y * 2.0f - 1.0f;
    m_box_pos.bottom_y = m_box_pos.bottom_y * 2.0f - 1.0f;

	return;
}


