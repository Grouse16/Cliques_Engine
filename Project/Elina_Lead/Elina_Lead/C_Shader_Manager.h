//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シェーダー制御用のクラス
// 説明   ：シェーダーの読み取りと書き出し、管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Shader_Code.h"
#include "E_Shader_Kind.h"


// ☆ ネームスペース ☆ //

// レンダリングに使用するシェーダーを呼び出すための名前
namespace ASSET::SHADER::MANAGER
{
	// ☆ クラス ☆ //

	// シェーダーの制御用システム
	class C_Shader_Manager
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //
		
		// シェーダー情報の構造体
		struct S_Shader_Manage_Inform
		{
			std::unique_ptr<C_Shader_Code> shader = nullptr;	// シェーダー設定

			std::string name = "DEFAULT";	// シェーダー設定名

			int user_sum = 0;	// このシェーダー情報を持っているシステムの数
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<std::vector<S_Shader_Manage_Inform>> shader_inform_list;	// シェーダー情報のリスト
		};

		SPr_Variable mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Shader_Manager m_this;	// シェーダー制御用システムのシングルトン化用インスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化する
		C_Shader_Manager(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Shader_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定されたシェーダーデータを返す　引数：シェーダーの種類, シェーダー設定の名前　戻り値：指定されたシェーダーデータへのアドレス、なければnullptrを返す
		static C_Shader_Code * M_Get_Shader_Setting(E_SHADER_KIND, std::string);


		//-☆- ロード -☆-//

		// シェーダー名からマテリアルをロードする　引数：シェーダーの種類　戻り値：生成したシェーダーデータへのアドレス
		static C_Shader_Code * M_Load_Shader_Setting_By_Name(E_SHADER_KIND, std::string);


		//-☆- 削除 -☆-//

		// 指定されたシェーダー設定の所有権を放棄することを通知する　引数：シェーダーの種類, 所有権を放棄するシェーダー設定のアドレスの参照
		static void M_Released_Shader_Setting_Once(E_SHADER_KIND, C_Shader_Code * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

