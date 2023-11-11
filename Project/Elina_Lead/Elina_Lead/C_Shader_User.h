//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーを使用するためのクラス
// 説明   ：シェーダーマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHADER_USER_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include "E_Shader_Kind.h"
#include "C_Shader_Code.h"


// ☆ ネームスペース ☆ //

// シェーダー系統のシステムを呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ クラス ☆ //
	
	// シェーダーを使用するためのクラス
	class C_Shader_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::SHADER::C_Shader_Code * shader_code_address = nullptr;	// 使用するシェーダーコードへのアドレス

			ASSET::SHADER::E_SHADER_KIND use_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_VERTEX;	// 取得したシェーダーの種類

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //
		
		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Shader_User(void);

		// デストラクタ
		~C_Shader_User(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定された名前のシェーダーを読み込む　引数：ロードするシェーダーの種類, ロードするシェーダー名
		void M_Load_Shader_Code(ASSET::SHADER::E_SHADER_KIND, std::string);


		//-☆- ゲッタ -☆-//

		// 今所持しているシェーダーコードを返す　戻り値：現在のシェーダーコード
		C_Shader_Code * M_Get_Shader_Code(void) const;

		// 所持しているシェーダーコードのシェーダーの種類を返す　戻り値：シェーダーの種類
		E_SHADER_KIND M_Get_Shader_Kind(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_USER_H_FILE
