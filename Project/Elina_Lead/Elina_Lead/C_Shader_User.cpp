//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーを使用するためのクラス
// 説明   ：シェーダーマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_User.h"
#include "C_Shader_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_User::C_Shader_User(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_User::~C_Shader_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_User::M_Release(void)
{
	if (mpr_variable.shader_code_address)
	{
		ASSET::SHADER::MANAGER::C_Shader_Manager::M_Released_Shader_Setting_Once(mpr_variable.use_shader_kind, mpr_variable.shader_code_address);
	}

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のシェーダーを読み込む
// 引数   ：E_SHADER_KIND シェーダーの種類, string シェーダー名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_User::M_Load_Shader_Code(ASSET::SHADER::E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// ☆ 変数宣言 ☆ //
	C_Shader_Code * new_shader_code_address = nullptr;	// 新しいシェーダーのアドレス


	// シェーダーの名前から探索して取得
	new_shader_code_address = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Get_Shader_Setting(in_shader_kind, in_shader_name);

	// 指定したシェーダーがまだないなら生成する
	if (new_shader_code_address == nullptr)
	{
		new_shader_code_address = ASSET::SHADER::MANAGER::C_Shader_Manager::M_Load_Shader_By_Name(in_shader_kind, in_shader_name);

		// 生成に失敗したら抜ける
		if (new_shader_code_address == nullptr)
		{
			return;
		}
	}


	// 取得できたシェーダーと入れ替える
	M_Release();
	mpr_variable.use_shader_kind = in_shader_kind;
	mpr_variable.shader_code_address = new_shader_code_address;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今所持しているシェーダーコードを返す
// 引数   ：void
// 戻り値 ：C_Shader_Code * 現在のシェーダーコード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Code * C_Shader_User::M_Get_Shader_Code(void) const
{
	return mpr_variable.shader_code_address;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：所持しているシェーダーコードのシェーダーの種類を返す
// 引数   ：void
// 戻り値 ：E_SHADER_KIND シェーダーの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
E_SHADER_KIND C_Shader_User::M_Get_Shader_Kind(void) const
{
	return mpr_variable.use_shader_kind;
}


