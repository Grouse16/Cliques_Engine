//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：一組のシェーダーの設定をまとめるためのクラス
// 説明   ：シェーダーをバラバラに設定する必要をなくす、カプセル化
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
#define D_INCLUDE_GUARD_C_SHADER_SET_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <vector>
#include <memory>

#include "C_Shader_User.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "E_Shader_Kind.h"
#include "Input_Layout_Data.h"
#include "C_Text_And_File_Manager.h"
#include "S_Unique_Buffer_Slot.h"


// ☆ ネームスペース ☆ //

// シェーダー用のシステムを呼び出すための名前
namespace ASSET::SHADER
{
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

			std::vector<C_Shader_User> shader_list;	// シェーダーコードのリスト

			S_Resource_Inform_List resource_inform;	// リソースのリスト

			ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot unique_buffer_slot_list;	// 特殊なバッファスロットのリスト

			int slot_number = 0;	// スロット番号

		} mpr_variable;	// プライベート変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// 頂点レイアウトをロードする　引数：シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 全てのシェーダーに共通するリソースの定義を行う　引数：シェーダーの種類名, シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_Resource_Signature(E_SHADER_KIND, SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 各種シェーダーのロードとリソースの定義を行う　引数：シェーダー情報ファイルのデータ　戻り値：成功時のみtrue
		bool M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager &);

		// 一種類分のシェーダーロードを行う処理　引数：シェーダー情報ファイルのデータ, シェーダーがあるフォルダ, シェーダーの種類　戻り値：成功時のみtrue
		bool M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & , int );

		// シェーダーのスロット情報を整列する
		void M_Slot_Inform_Alignment(void);


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

		// シェーダー情報ファイルの内容を読み取って各種シェーダーをロードし、頂点レイアウトとリソースの定義を設定する　引数：読み込むシェーダー設定ファイルまでの相対パス　戻り値：成功時のみtrue
		bool M_Load_Shaders_Inform_By_Shader_Setting_File_Path(std::string);


		//-☆- ゲッタ -☆-//

		// シェーダーの使用システムのセットを返す　戻り値：シェーダーの使用システムの種類別リストの参照(const)
		const std::vector<C_Shader_User> & M_Get_Shader_Code_List(void) const;

		// 頂点入力レイアウトのリストを返す　戻り値：入力レイアウトへの参照(const)
		const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & M_Get_Input_Layout(void) const;

		// 特殊なシェーダーのリストの参照を返す　戻り値：特殊なシェーダーのリストの参照（const）
		const ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot & M_Get_Unique_Buffer_Slot(void) const;

		// リソースのリストを返す　戻り値：リソースのリストの参照(const)
		const S_Resource_Inform_List & M_Get_Resource_Inform(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_SHADER_SET_H_FILE
