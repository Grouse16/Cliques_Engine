//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダー制御用のクラス
// 説明   ：シェーダーの読み取りと書き出し、管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_Manager.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER::MANAGER;


// ☆ スタティック変数 ☆ //
C_Shader_Manager C_Shader_Manager::m_this;


// ☆ 変数宣言 ☆ //
C_Shader_Manager C_Shader_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Manager::C_Shader_Manager(void)
{
	// シェーダーの種類数分リストを作る
	mpr_variable.shader_inform_list.resize((int)E_SHADER_KIND::e_ALL);

	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Manager::~C_Shader_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Manager::M_Release(void)
{
	for (std::vector<S_Shader_Manage_Inform> & now_inform_list : m_this.mpr_variable.shader_inform_list)
	{
		for (S_Shader_Manage_Inform & now_inform : now_inform_list)
		{
			now_inform.shader->M_Release();
			now_inform.shader.reset();
		}

		now_inform_list.clear();
		now_inform_list.shrink_to_fit();
	}

	m_this.mpr_variable.shader_inform_list.clear();
	m_this.mpr_variable.shader_inform_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたシェーダーデータを返す
// 引数   ：E_SHADER_KIND シェーダーの種類, string シェーダーの設定の名前
// 戻り値 ：C_Shader_Set * 指定されたシェーダーデータへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Get_Shader_Setting(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// すでにロード済みのシェーダー設定内から見つかるまで探索し、見つかったらそのデータのアドレスを返す
	for (S_Shader_Manage_Inform & now_shader_inform : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_inform.name == in_shader_name)
		{
			now_shader_inform.user_sum += 1;
			return now_shader_inform.shader.get();
		}
	}

	// ロードできなかったらnullptrを返す
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダー名からシェーダーをロードする
// 引数   ：E_SHADER_KIND シェーダーの種類, string シェーダー名の参照
// 戻り値 ：C_Shader_Code * 生成したシェーダーデータへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Load_Shader_By_Name(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// ☆ 変数宣言 ☆ //
	std::string shader_inform_path = RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Get_Shader_Folder_Path() + in_shader_name;	// シェーダー情報へのパス

	int shader_slot_num = m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].size();	// 操作するシェーダーの番号


	// 新しいシェーダー設定用のスロットを生成
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].resize(shader_slot_num + 1);
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.reset(new ASSET::SHADER::C_Shader_Code);

	// シェーダー情報からシェーダーをロードする、できなければfalseを返す
	if (m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader->M_Load_Shader_File(shader_inform_path) == false)
	{
		return nullptr;
	}

	// 新しいシェーダーの名前を登録し、使用されている数を加算
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].name = in_shader_name;
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].user_sum = 1;

	// 生成したシェーダーを返す
	return m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.get();
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたシェーダー設定の所有権を放棄することを通知する
// 引数   ：E_SHADER_KIND シェーダーの種類, C_Shader_Setting * & 所有権を放棄するシェーダー設定のアドレスの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Manager::M_Released_Shader_Setting_Once(ASSET::SHADER::E_SHADER_KIND in_shader_kind, C_Shader_Code * & in_released_shader)
{
	// 指定されたシェーダー設定を探索し、見つかったら所持しているインスタンス数を減らし、そのシェーダーへの接続を切る
	for (S_Shader_Manage_Inform & now_shader_set : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_set.shader.get() == in_released_shader)
		{
			in_released_shader = nullptr;
			now_shader_set.user_sum -= 1;


			// このシェーダーが使われなくなったら削除する
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].erase
			(
				std::remove_if
				(
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].begin(),
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end(),

					// 削除条件のラムダ式
					[](S_Shader_Manage_Inform & in_shader_inform)
					{
						if (in_shader_inform.user_sum < 1)
						{
							in_shader_inform.shader.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end()
			);
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].shrink_to_fit();

			return;
		}
	}

	return;
}

