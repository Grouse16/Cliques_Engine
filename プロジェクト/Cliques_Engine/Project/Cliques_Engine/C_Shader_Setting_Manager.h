//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーの設定をまとめた情報を管理するクラス
// 説明   ：多重に同じものがロードされないように制御し、必要がなくなったシェーダーの設定を削除する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER
#define D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>
#include <string>

#include "C_Shader_Setting.h"


// ☆ ネームスペース ☆ //

// シェーダーの設定を制御するためのシステムを呼び出すための名前
namespace ASSET::SHADER::MANAGER
{
	// ☆ クラス ☆ //

	// シェーダーの設定をまとめた情報を管理するクラス
	class C_Shader_Setting_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// シェーダーの設定を管理するためのデータの構造体
		struct S_Shader_Setting_Inform
		{
			std::unique_ptr<C_Shader_Setting> shader_setting_data = nullptr;	// シェーダー設定

			std::string name = "default";	// シェーダー設定名
			
			int user_sum = 0;	// このデータを使用しているインスタンス数
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Shader_Setting_Inform> shader_setting_list;	// シェーダー設定のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Shader_Setting_Manager m_this;	// 自クラスをシングルトン化するためのインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化する
		C_Shader_Setting_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Shader_Setting_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定されたシェーダー設定を返す　引数：シェーダー設定の名前　戻り値：指定されたシェーダー設定へのアドレス、なければnullptrを返す
		static ASSET::SHADER::C_Shader_Setting * M_Get_Shader_Setting_By_Name(std::string);


		//-☆- ロード -☆-//

		// シェーダー設定名からシェーダー設定をロードする　引数：シェーダー設定名　戻り値：生成したシェーダー設定へのアドレス
		static ASSET::SHADER::C_Shader_Setting * M_Load_Shader_Setting_By_Name(std::string);


		//-☆- 削除 -☆-//

		// 指定されたシェーダー設定の所有権を放棄することを通知する　引数：所有権を放棄するシェーダー設定のアドレスの参照
		static void M_Release_Shader(ASSET::SHADER::C_Shader_Setting * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SETTING_MANAGER
