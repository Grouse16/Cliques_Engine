//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャデータの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：テクスチャデータのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM
#define D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>

#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "E_Shader_Kind.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// テクスチャデータを円滑に設定し、レンダリングするためのシステム
	class C_Texture_Data_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base > texture_setting_inform;	// テクスチャ設定用の情報

			ASSET::TEXTURE::C_Texture_Map texture_map;	// テクスチャ用のマップ

			std::string data_signature_name = "";	// データ識別名、パイプライン情報システムと同じ識別名を付加することでGPUに情報を渡せる

			bool flg_loaded = false;	// テクスチャがロード済みかどうかを示す, trueでロード済み

			ASSET::SHADER::E_SHADER_KIND attach_shader = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// 適用先シェーダー

		} mpr_variable;	// プライベート変数を呼び出すための名前


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Texture_Data_System(void);

		// デストラクタ
		~C_Texture_Data_System(void);

		// メモリの解放を行う
		void M_Delete(void);

		// テクスチャマップのみ解放する（バッファは残る）
		void M_Delete_Map(void);


		//-☆- リセット -☆-//

		// テクスチャを初期の状態にする(ピンク色の画像)
		void M_Reset_Texture(void);


		//-☆- 生成 -☆-//

		// テクスチャデータを生成する　引数：テクスチャの横サイズ, テクスチャの縦サイズ
		void M_Create_Texture_Data(int, int);

		// テクスチャマップに合わせて、テクスチャのリソースを生成する
		void M_Create_Texture_Resource_By_Texture_Map(void);

		// テクスチャをロードしたデータを元に生成する　引数：テクスチャのパス　戻り値：成功時のみtrue
		bool M_Create_Texture_By_Load_Texture_File(std::string);


		//-☆- セッタ -☆-//

		// データの識別名をセットする　引数：セットする文字列
		void M_Set_Data_Signature_Name(std::string);

		// テクスチャデータ設定先のシェーダーの種類を変更する
		void M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);


		//-☆- ゲッタ -☆-//

		// データの識別名を返す　戻り値：識別用の文字列
		const std::string & M_Get_Data_Signature_Name(void);

		// テクスチャデータ設定先のシェーダーの種類を返す
		ASSET::SHADER::E_SHADER_KIND M_Get_Attach_Shader_Kind(void);

		// テクスチャマップの参照を返す　戻り値：テクスチャマップの参照
		ASSET::TEXTURE::C_Texture_Map & M_Get_Texture_Map(void);

		
		//-☆- 描画 -☆-//

		// テクスチャマップのデータをテクスチャとしてセットする
		void M_Texture_Map_To_Texture_Resource_Data(void);

		// テクスチャ情報をGPUに渡す
		void M_Attach_To_Shader(void);

		// テクスチャ情報を指定されたインデックスに設定し、GPUに渡す　引数：インデックス番号
		void M_Attach_To_Shader_By_Index(int);
	};
}


#endif // !D_INCLDUE_GUARD_C_TEXTURE_DATA_SYSTEM
