//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーの設定をまとめた情報を管理するクラス
// 説明   ：多重に同じものがロードされないように制御し、必要がなくなったシェーダーの設定を削除する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_Setting_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER::MANAGER;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、シングルトン化する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting_Manager::C_Shader_Setting_Manager(void)
{

	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting_Manager::~C_Shader_Setting_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting_Manager::M_Release(void)
{
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		now_shader_setting_inform.shader_setting_data->M_Release();
		now_shader_setting_inform.shader_setting_data.reset();
	}

	m_this.mpr_variable.shader_setting_list.clear();
	m_this.mpr_variable.shader_setting_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたシェーダー設定を返す
// 引数   ：string シェーダー設定の名前
// 戻り値 ：C_Shader_Setting * 指定されたシェーダー設定へのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::C_Shader_Setting * C_Shader_Setting_Manager::M_Get_Shader_Setting_By_Name(std::string in_shader_setting_name)
{
	// シェーダー設定名から指定されたシェーダー設定を探して、見つかったらそれを返す
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		if (now_shader_setting_inform.name == in_shader_setting_name)
		{
			now_shader_setting_inform.user_sum += 1;
			return now_shader_setting_inform.shader_setting_data.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダー設定名からシェーダー設定をロードする
// 引数   ：string シェーダー設定名
// 戻り値 ：C_Shader_Setting * 生成したシェーダー設定へのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::C_Shader_Setting * C_Shader_Setting_Manager::M_Load_Shader_Setting_By_Name(std::string in_shader_setting_name)
{
	// ☆ 定数 ☆ //
	std::string shader_setting_inform_path = "project/asset/shader/inform/setting/" + in_shader_setting_name + ".elsst";	// シェーダー設定へのパス

	int shader_setting_slot_num = m_this.mpr_variable.shader_setting_list.size();	// 操作するシェーダー設定の番号


	// 新しいシェーダー設定用のスロットを生成
	m_this.mpr_variable.shader_setting_list.resize(shader_setting_slot_num + 1);
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data.reset(new ASSET::SHADER::C_Shader_Setting());

	// シェーダー設定名からシェーダー設定をロードする、できなければfalseを返す
	if (m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data->M_Load_Shaders_Inform_By_Shader_Setting_File_Path(shader_setting_inform_path) == false)
	{
		return nullptr;
	}

	// 新しいシェーダー設定の名前を登録し、使用されている数を加算
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].name = in_shader_setting_name;
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].user_sum = 1;

	// 生成したシェーダー設定を返す
	return m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data.get();
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたシェーダー設定の所有権を放棄することを通知する
// 引数   ：C_Shader_Setting * & 所有権を放棄するシェーダー設定のアドレスの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting_Manager::M_Release_Shader(ASSET::SHADER::C_Shader_Setting * & in_release_shader_setting_address)
{
	// シェーダー設定名から指定されたシェーダー設定を探して、見つかったら所有されている数のカウントを減らして参照できなくする
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		if (now_shader_setting_inform.shader_setting_data.get() == in_release_shader_setting_address)
		{
			in_release_shader_setting_address = nullptr;
			now_shader_setting_inform.user_sum -= 1;


			// このシェーダー設定が使われなくなったら削除する
			m_this.mpr_variable.shader_setting_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.shader_setting_list.begin(),
					m_this.mpr_variable.shader_setting_list.end(),

					// 残りの数が0になると削除するラムダ式
					[](S_Shader_Setting_Inform & in_shader_setting)->bool
					{
						if (in_shader_setting.user_sum < 1)
						{
							in_shader_setting.shader_setting_data.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.shader_setting_list.end()
			);

			return;
		}
	}

	return;
}
