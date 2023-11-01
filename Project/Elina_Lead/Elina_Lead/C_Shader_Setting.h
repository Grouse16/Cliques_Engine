//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：一組のシェーダーの設定をまとめるためのクラス
// 説明   ：シェーダーをバラバラに設定する必要をなくす、カプセル化
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_SET_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <vector>


#include "C_Shader_Manager.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "E_Shader_Kind.h"
#include "Input_Layout_Data.h"
#include "C_Text_And_File_Manager.h"


// ☆ ネームスペース ☆ //

// シェーダー用のシステムを呼び出すための名前
namespace ASSET::SHADER
{
	// ☆ 構造体 ☆ //

	// シェーダーコードの種類別リストの構造体
	struct S_Shader_Byte_Code_List
	{
		C_Shader_Code * list[(int)E_SHADER_KIND::e_ALL];	// シェーダーコードのリスト　VS,HS,DS,GS,PSを持つ
	};


	// ☆ クラス ☆ //

	// 一組のシェーダーの設定をまとめるためのクラス
	class C_Shader_Setting
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> vertex_layout_setting;	// 頂点レイアウト設定

			S_Shader_Byte_Code_List shader_code;	// シェーダーのコードをまとめた構造体

			S_All_Shader_Resource_Signatures resource_signature;	// リソース識別用情報のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// 頂点レイアウトをロードする　引数：シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 全てのシェーダーに共通するリソースの定義を行う　引数：シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_All_Shader_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 各種シェーダーのロードとリソースの定義を行う　引数：シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 一種類分のシェーダーロードを行う処理　引数：シェーダー情報ファイルのデータ, シェーダーがあるフォルダ, シェーダーの種類　戻り値：成功時のみtrue
		bool M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & , int );


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Shader_Setting(void);

		// デストラクタ
		~C_Shader_Setting(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// シェーダー情報ファイルの内容を読み取って各種シェーダーをロードし、頂点レイアウトとリソースの定義を設定する　引数：シェーダー情報ファイルのパス　戻り値：成功時のみtrue
		bool M_Load_Shaders_Inform_By_Shader_Setting_Name(std::string);


		//-☆- ゲッタ -☆-//

		// シェーダーのコードのセットを返す　戻り値：シェーダーのコードの種類別リストの参照(const)
		const S_Shader_Byte_Code_List & M_Get_Shader_Code_List(void) const;

		// リソース識別用情報を返す　戻り値：リソース識別用情報の参照(const)
		const S_All_Shader_Resource_Signatures & M_Get_Resource_Signature(void) const;

		// 頂点入力レイアウトのリストを返す　戻り値：入力レイアウトへの参照(const)
		const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & M_Get_Input_Layout(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
