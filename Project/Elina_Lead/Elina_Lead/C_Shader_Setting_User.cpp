//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダー設定を使用するためのクラス
// 説明   ：シェーダー設定マネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_Setting_User.h"
#include "C_Shader_Setting_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- メモリを解放する -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting_User::C_Shader_Setting_User(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting_User::~C_Shader_Setting_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting_User::M_Release(void)
{
	if (mpr_variable.shader_settting_address)
	{
		ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Release_Shader(mpr_variable.shader_settting_address);
	}

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のシェーダー設定を読み込む
// 引数   ：string シェーダー設定名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting_User::M_Load_Shader_Setting(std::string in_shader_setting_name)
{
	// ☆ 変数宣言 ☆ //
	C_Shader_Setting * new_shader_setting_address = nullptr;	// 新しいシェーダー設定のアドレス


	// シェーダー設定の名前から探索して取得
	new_shader_setting_address = ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Get_Shader_Setting_By_Name(in_shader_setting_name);

	// 指定したシェーダー設定がまだないなら生成する
	if (new_shader_setting_address == nullptr)
	{
		new_shader_setting_address = ASSET::SHADER::MANAGER::C_Shader_Setting_Manager::M_Load_Shader_Setting_By_Name(in_shader_setting_name);

		// 生成に失敗したら抜ける
		if (new_shader_setting_address == nullptr)
		{
			return;
		}
	}


	// 取得できたシェーダー設定と入れ替える
	M_Release();
	mpr_variable.shader_settting_address = new_shader_setting_address;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今所持しているシェーダー設定を返す
// 引数   ：void
// 戻り値 ：C_Shader_Setting * 現在のシェーダー設定
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting * ASSET::SHADER::C_Shader_Setting_User::M_Get_Shader_Setting(void)
{
	return mpr_variable.shader_settting_address;
}


