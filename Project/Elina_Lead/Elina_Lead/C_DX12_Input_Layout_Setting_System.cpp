//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ダイレクトエックス12の入力レイアウト設定用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Input_Layout_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ クラス ☆ //

//==☆ プライベート ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを元に入力用のセマンティック情報を生成する　　参考資料：https://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// 引数   ：const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & レイアウト設定用の情報
// 戻り値 ：DXGI_FORMAT 結果のデータ形式
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DXGI_FORMAT C_DX12_Input_Layout_Setting_System::M_Get_Format_By_Fit_Setting(const DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING & in_setting_infrom)
{
	// ☆ 変数の個数 ☆ //
	switch (in_setting_infrom.sum)
	{
	//  変数１つ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_1:

		// ☆ データ形式 ☆ //
		switch (in_setting_infrom.format)
		{
		//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:
			
			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
			//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_SINT;

				break;

			//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_SINT;

				break;

			//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_SINT;

				break;
			}

			break;

		//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_UINT;

				break;
			}

			break;

		//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;

				break;
			}

			break;
		}

		break;


	//  変数２つ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2:

		// ☆ データ形式 ☆ //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_SINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;

				break;
			}

			break;
		}

		break;


		//  変数３つ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_3:

		// ☆ データ形式 ☆ //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R24_UNORM_X8_TYPELESS;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R10G10B10A2_TYPELESS;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;

				break;
			}

			break;
		}

		break;

	//  変数４つ  //
	case DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4:

		// ☆ データ形式 ☆ //
		switch (in_setting_infrom.format)
		{
			//  INT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_SINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_SINT;

				break;
			}

			break;

			//  UINT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_UINT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_UINT;

				break;
			}

			break;

			//  FLOAT  //
		case DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT:

			// ☆ データサイズ ☆ //
			switch (in_setting_infrom.size)
			{
				//  8bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_1BYTE_8BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_SINT;

				break;

				//  16bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;

				break;

				//  32bit  //
			case DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT:

				return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;

				break;
			}

			break;
		}

		break;
	}


	// 当てはまらなければ不明を返す
	return DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
}


//==☆ パブリック ☆==//

//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを元に入力用のセマンティック情報を生成する　　参考資料：https://learn.microsoft.com/ja-jp/windows/win32/api/d3d12/ns-d3d12-d3d12_input_element_desc
// 引数   ：D3D12_INPUT_LAYOUT_DESC & 設定先の入力レイアウト情報, const vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & レイアウト設定用の情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Input_Layout_Setting_System::M_Creat_Input_Layout_By_Creat_Inform(D3D12_INPUT_LAYOUT_DESC & in_input_layout, const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & in_input_layout_list)
{
	// 前回のメモリ解放
	m_element_list.clear();
	m_element_list.shrink_to_fit();


	// レイアウト数分生成する
	in_input_layout.NumElements = in_input_layout_list.size();
	m_element_list.reserve(in_input_layout.NumElements);


	// 生成数分繰り返し、全て設定する
	for (UINT loop_x = 0; loop_x < in_input_layout.NumElements; loop_x++)
	{
		m_element_list.emplace_back
		(
			// セマンティック名
			"CLIQUES",

			// セマンティックの番号
			loop_x,

			// データ形式設定
			M_Get_Format_By_Fit_Setting(in_input_layout_list[loop_x]),

			// 頂点データをどの入力スロットに設定するか
			0,

			// このデータの始まりの場所（バイト数で）
			D3D12_APPEND_ALIGNED_ELEMENT,

			// 頂点単体のデータか、複数頂点を含むインスタンスのデータかの識別　（頂点も結局インスタンスなんだからINSTANCE以外の名前にするべき）
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,

			// インスタンス（複数頂点を含むクラス）の場合、何個の配列を同時に描画するか、頂点単体なら0
			0
		);
	}


	// アドレスをセット
	in_input_layout.pInputElementDescs = &m_element_list[0];

	return;
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Input_Layout_Setting_System::~C_DX12_Input_Layout_Setting_System(void)
{
	M_Close_Input_Layout_Inform();

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力用セマンティック設定用の情報を削除する、パイプラインステートオブジェクトを生成し終わったら削除
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Input_Layout_Setting_System::M_Close_Input_Layout_Inform(void)
{
	m_element_list.clear();
	m_element_list.shrink_to_fit();

	return;
}

