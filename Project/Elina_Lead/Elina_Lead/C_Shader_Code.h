//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダーのバイトコード用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE
#define D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <memory>


// ☆ ネームスペース ☆ //

// レンダリングに使用するシェーダーを呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ クラス ☆ //

	// シェーダーのバイトコード用のクラス
	class C_Shader_Code
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<void* > binary_ptr = nullptr;	// コンパイル済みコード

			unsigned int size = 0;	// バイトコードのサイズ

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Shader_Code(void);

		// デストラクタ
		~C_Shader_Code(void);

		// バイトコードのメモリを解放し初期化する
		void M_Release(void);


		//-☆- ロード -☆-//

		// シェーダーをロードする　引数：シェーダーまでのパス
		bool M_Load_Shader_File(std::string);


		//-☆- ゲッタ -☆-//

		// コンパイル済みコードの参照を返す　戻り値：コンパイル済みコード
		const std::unique_ptr<void * > & M_Get_Compiled_Cord(void) const;

		// コードのバイトサイズを返す　戻り値：コードのバイトサイズ
		int M_Get_Cord_Size(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHDER_BYTE_CODE_H_FILE
