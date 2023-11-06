//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダー設定を使用するためのクラス
// 説明   ：シェーダー設定マネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Shader_Setting.h"


// ☆ ネームスペース ☆ //

// シェーダー系のシステムを呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ クラス ☆ //

	// シェーダー設定を使用するためのクラス
	class C_Shader_Setting_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			C_Shader_Setting * shader_settting_address = nullptr;	// 使用するシェーダー設定のアドレス

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Shader_Setting_User(void);

		// デストラクタ
		~C_Shader_Setting_User(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定された名前のシェーダー設定を読み込む　引数：シェーダー設定名
		void M_Load_Shader_Setting(std::string);


		//-☆- ゲッタ -☆-//

		// 今所持しているシェーダー設定を返す　戻り値：現在のシェーダー設定
		C_Shader_Setting * M_Get_Shader_Setting(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SETTING_USER_H_FILE

